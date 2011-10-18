#!/usr/bin/env python

from ROOT import *

def procnum(number, error):
    numberstring = r"\\ensuremath{"
    #temp
    if (number>=1000000):
        if (error/1000000. >= 0.05):
            numberstring += "("
            numberstring += "%.1f" % (number/1000000.)
            numberstring += r" \\pm "
            numberstring += "%.1f" % (error/1000000.)
            numberstring += ")"
        #if (number>=10000000):
        #    numberstring += "%.1f" % (number/1000000.)
        else:
            numberstring += "%.2f" % (number/1000000.)
        #else:
        #    numberstring += "%.2f" % (number/1000000.)
        numberstring += r" \\, \\textrm{M} "
    elif (number>=1000):
        if (error/1000. >= 0.5):
            numberstring += "("
            numberstring += "%.0f" % (number/1000.)
            numberstring += r" \\pm "
            numberstring += "%.0f" % (error/1000.)
            numberstring += r")"
        else:
            numberstring += "("
            numberstring += "%.1f" % (number/1000.)
            numberstring += r" \\pm "
            numberstring += "%.1f" % (error/1000.)
            numberstring += r")"
        numberstring += r"\\, \\textrm{k} "
    elif (number < 10.0):
        numberstring += "%.2f " % (number)
        numberstring += r" \\pm "
        numberstring += "%.2f " % (error)
    else:
        numberstring += "%.1f " % (number)
        numberstring += r" \\pm "
        numberstring += "%.1f " % (error)
    numberstring += r"}"
    return numberstring

def isItOneHundred(number):
    numberstring = ""
    if (number == 100.0):
        numberstring += "100.0"
    elif ((number >= 99.9) and (number < 100.0)):
        numberstring += r"\\geq "
        numberstring += "99.9"
    else:
        numberstring += "%.1f" % (number)
    return numberstring

def buildTable(resultsfiles,cuts,data=True,lumi=100.0):
    lumiscale = lumi/100.0
    table = ""
    #start of tabular environment
    table += "\t\t"+r"\\begin{tabular}{l"
    for sample in resultsfiles:
        table+="."
    if (data):
        table += r".."
    table += r"}"+"\n"
    table += "\t\t\t"+r"\\hline"+"\n"
    #
    #header row
    headerrow = "\t\t\t"+r"\\multicolumn{1}{c}{Cut} & "
    for sample in resultsfiles:
        if (sample[0]!="Data"):
            headerrow += r"\\multicolumn{1}{c}{" + sample[0] + r"} & "
        else:
            headerrow += r"\\multicolumn{1}{c}{SM Total} & \\multicolumn{1}{c}{Data} \\\\"+"\n"
    if (not(data)):
        headerrow = headerrow[:-2]
        headerrow += r"\\\\"+"\n"
    table += headerrow
    table += "\t\t\t"+r"\\hline"+"\n"
    #
    # cuts
    for cut in cuts:
        #row = "\t\t\t" + r"\\multicolumn{1}{l}{" + cut[1] + r"} & " #cut name
        row = "\t\t\t" + cut[1] + " & " #cut name
        SMtotal = 0.
        SMerrorSquare = 0.
        #get the numbers from the file
        for sample in resultsfiles:
            #get the number from the histogram
            name = cut[0]+r"/count"
            file = TFile(sample[1], "READ")
            hist = file.Get(name)
            if (sample[0]!="Data"):
                if (hist):
                    num = (hist.GetBinContent(1))*lumiscale #scale by supplied luminosity
                    row += " %.2f & " % (num)
                    if ((sample[0]!="LM0") and (sample[0]!="LM1")):
                        SMtotal += num
                else:
                    row += r"- & "
            else:
                #print name
                row += " %.2f & " % (SMtotal)
                if (hist):
                    num = hist.GetBinContent(1)
                    row += "%.2f " % (num)
                else:
                    row += "- "
                row += r"\\\\"+"\n"
        if (not(data)):
            row = row[:-2]
            row += r"\\\\"+"\n"
        table += row
    table += "\t\t\t"+r"\\hline"+"\n"
    #end of tabular environment
    table += "\t\t"+r"\\end{tabular}"
    return table

def newBuildTable(resultsfiles,cuts,lumi=100.0,ncomjets="2eq"):
    lumiscale = lumi/100.0
    table = ""
    #start of tabular environment
    table += "\t\t"+r"\\begin{tabular}{l"
    for sample in resultsfiles:
        table+="c.."
    #if (data):
    #    table += r".."
    table += r"}"+"\n"
    table += "\t\t\t"+r"\\hline"+"\n"
    #
    #header row
    headerrow = "\t\t\t"+r"\\multicolumn{1}{c}{Cut} & "
    #count the number of samples
    numsamples = len(resultsfiles)
    samplecount = 0
    for sample in resultsfiles:
        samplecount += 1
        headerrow += r"\\multicolumn{3}{c}{" + sample[0] + r"} & "
    if (samplecount==numsamples):
        headerrow = headerrow[:-2]
        headerrow += r"\\\\"+"\n"
    table += headerrow
    #
    #sub-header row
    subheaderrow = ""
    subheaderrow = "\t\t\t"+r" & "
    #count the number of samples
    numsamples = len(resultsfiles)
    samplecount = 0
    for sample in resultsfiles:
        samplecount += 1
        subheaderrow += r"\\multicolumn{1}{c}{ a) } & \\multicolumn{1}{c}{ b) } & \\multicolumn{1}{c}{ c) } & "
    if (samplecount==numsamples):
        subheaderrow = subheaderrow[:-2]
        subheaderrow += r"\\\\"+"\n"
    table += subheaderrow
    table += "\t\t\t"+r"\\hline"+"\n"
    #
    # cuts
    cutcount = 0
    firstcut = "count_selection"+ncomjets #remove ncomjets if count_total used
    for cut in cuts:
        cutcount += 1
        #row = "\t\t\t" + r"\\multicolumn{1}{l}{" + cut[1] + r"} & " #cut name
        row = "\t\t\t" + cut[1] + " & " #cut name
#        SMtotal = 0.
#        SMerrorSquare = 0.
        #get the numbers from the file
        numsamples = len(resultsfiles)
        samplecount = 0
        for sample in resultsfiles:
            #lastCutCount = -1.0
            samplecount += 1
            #get the number from the histogram
            baseHistName = "count_htCutBase250_"+ncomjets+r"/count"
            name = cut[0]+ncomjets
            #print "Current cut "+name
            lastcutname = ""
            if (name!=firstcut):
                #name += ncomjets
                lastcut = cuts[cutcount-2]
                lastcutname = lastcut[0]
            #
            name += r"/count"
            file = TFile(sample[1], "READ")
            hist = file.Get(name)
            baseHist = file.Get(baseHistName)
#            if (sample[0]!="Data"):
            if (hist and baseHist):
                num = (hist.GetBinContent(1))
                error = hist.GetBinError(1)
                baseValue = (baseHist.GetBinContent(1))
                if (sample[0]!="Data"):
                    num *= lumiscale #scale by supplied luminosity
                    error *= lumiscale
                    baseValue *= lumiscale #scale by supplied luminosity
                fracLostToBase = ((baseValue - num)/baseValue)*100.
                if (fracLostToBase < 0.):
                    row += procnum(num,error) + " & - & "
                else:
                    #row += " %.2f & %.1f & " % (num,fracLostToBase) #old
                    row += procnum(num,error)
                    #
                    #row += " & %.1f & " % (fracLostToBase)
                    row += " & "+isItOneHundred(fracLostToBase)+" & "
                if (lastcutname!=""):
                    if (lastcutname!=firstcut):
                        lastcutname+=ncomjets+r"/count"
                        #lastcutname+=r"/count"
                    else:
                        lastcutname+=r"/count"
                    lastHist = file.Get(lastcutname)
                    if (lastHist):
                        lastCutValue = (lastHist.GetBinContent(1))
                        if (sample[0]!="Data"):
                            lastCutValue *= lumiscale
                        if (lastCutValue>0.):
                            fracLostToLast = ((lastCutValue - num)/lastCutValue)*100.
                            if (fracLostToLast>0.0):
                                row += " %.1f " % (fracLostToLast)
                            else:
                                row += " 0.0 "
                        else:
                            row += " - "
                    else:
                        row += " 0.0 "
                else:
                    row += " - "
                #
            if (samplecount<numsamples):
                row += "& "
        #
        row += r" \\\\"+"\n"
        table += row
    #
    table += "\t\t\t"+r"\\hline"+"\n"
    #end of tabular environment
    table += "\t\t"+r"\\end{tabular}"
    return table

def smVsDataTable(smresultsfiles,datafile,cuts,lumi=100.,ncomjets="2eq"):
    lumiscale = lumi/100.0
    table = ""
    #start of tabular environment
    table += "\t\t"+r"\\begin{tabular}{l"
    for smresults in smresultsfiles:
        table+="c.."
    #for the data
    table += "c..}"+"\n"
    table += "\t\t\t"+r"\\hline"+"\n"
    #
    #header row
    headerrow = "\t\t\t"+r"\\multicolumn{1}{c}{Cut} & "
    #count the number of samples
    numsmresults = len(smresultsfiles)
    smresultscount = 0
    for smresult in smresultsfiles:
        smresultscount += 1
        headerrow += r"\\multicolumn{3}{c}{" + smresult[0] + r"} & "
    #if (smresultscount==numsmresults):
    #    headerrow = headerrow[:-2]
    #    headerrow += r"\\\\"+"\n"
    headerrow += r"\\multicolumn{3}{c}{Data} \\\\"+"\n"
    table += headerrow
    #
    #sub-header row
    subheaderrow = ""
    subheaderrow = "\t\t\t"+r" & "
    #count the number of samples
    for sample in smresultsfiles:
        subheaderrow += r"\\multicolumn{1}{c}{ a) } & \\multicolumn{1}{c}{ b) } & \\multicolumn{1}{c}{ c) } & "
    subheaderrow += r"\\multicolumn{1}{c}{ a) } & \\multicolumn{1}{c}{ b) } & \\multicolumn{1}{c}{ c) } \\\\"
    table += subheaderrow
    table += "\t\t\t"+r"\\hline"+"\n"
    #
    #
    # cuts
    cutcount = 0
    firstcut = "count_selection"+ncomjets #remove ncomjets if count_total used
    for cut in cuts:
        cutcount += 1
        row = "\t\t\t" + cut[1] + " & " #cut name
        #loop over the 
        for smresult in smresultsfiles:
            SMtotal = 0.
            SMerrorSquare = 0.
            SMbaseTotal = 0.
            SMlastCutTotal = 0.
            resultsfiles = smresult[1]
            #get the numbers from the file
            numsamples = len(resultsfiles)
            #print str(numsamples) + " found in sm result"
            samplecount = 0
            for sample in resultsfiles:
#            #lastCutCount = -1.0
                samplecount += 1
                #get the number from the histogram
                baseHistName = "count_htCutBase250_"+ncomjets+r"/count"
                name = cut[0]+ncomjets
                #print "Current cut "+name
                lastcutname = ""
                if (name!=firstcut):
                    lastcut = cuts[cutcount-2]
                    lastcutname = lastcut[0]
                #
                name += r"/count"
                file = TFile(sample[1], "READ")
                hist = file.Get(name)
                baseHist = file.Get(baseHistName)
                if (hist and baseHist):
                    num = (hist.GetBinContent(1))
                    error = hist.GetBinError(1)
                    baseValue = (baseHist.GetBinContent(1))
                    num *= lumiscale #scale by supplied luminosity
                    error *= lumiscale
                    baseValue *= lumiscale #scale by supplied luminosity
                    #add to totals
                    SMtotal += num
                    SMerrorSquare += error*error
                    SMbaseTotal += baseValue
                    if (lastcutname!=""):
                        if (lastcutname!=firstcut):
                            lastcutname+=ncomjets+r"/count"
                            #lastcutname+=r"/count"
                        else:
                            lastcutname+=r"/count"
                        lastHist = file.Get(lastcutname)
                        if (lastHist):
                            lastCutValue = (lastHist.GetBinContent(1))
                            SMlastCutTotal += lastCutValue*lumiscale
            #end of loop over samples - now do something with the totals
            row += procnum(SMtotal,sqrt(SMerrorSquare)) + " & "
            #
            #add baseline cut
            fracLostToBase = ((SMbaseTotal - SMtotal)/SMbaseTotal)*100.
            if (fracLostToBase < 0.):
                row += " - & "
            else:
                #row += " %.1f & " % (fracLostToBase)
                row += isItOneHundred(fracLostToBase) + " & "
            #add last cut loss
            if (SMlastCutTotal>0.):
                fracLostToLast = ((SMlastCutTotal - SMtotal)/SMlastCutTotal)*100.
#            if (fracLostToLast>0.0):
                #row += " %.1f & " % (fracLostToLast)
                row += isItOneHundred(fracLostToLast) + " & "
            else:
                row += " - & "
        #
        #end of loop over SM results batch
        #
        #get the data
        data = datafile[0]
        #get the number from the histogram
        baseHistName = "count_htCutBase250_"+ncomjets+r"/count"
        name = cut[0]+ncomjets
        #print "Current cut "+name
        lastcutname = ""
        if (name!=firstcut):
            lastcut = cuts[cutcount-2]
            lastcutname = lastcut[0]
        #
        name += r"/count"
        file = TFile(data[1], "READ")
        hist = file.Get(name)
        baseHist = file.Get(baseHistName)
        if (hist and baseHist):
            num = (hist.GetBinContent(1))
            error = hist.GetBinError(1)
            baseValue = (baseHist.GetBinContent(1))
            row += procnum(num,error) + " & "
            #add baseline cut
            fracLostToBase = ((baseValue - num)/baseValue)*100.
            if (fracLostToBase < 0.):
                row += " - & "
            else:
                row += isItOneHundred(fracLostToBase) + " & "
            #now, finally, the previous cut loss...
            if (lastcutname!=""):
                if (lastcutname!=firstcut):
                    lastcutname+=ncomjets+r"/count"
                    #lastcutname+=r"/count"
                else:
                    lastcutname+=r"/count"
                lastHist = file.Get(lastcutname)
                if (lastHist):
                    lastCutValue = (lastHist.GetBinContent(1))
                    if (lastCutValue>0.):
                        fracLostToLast = ((lastCutValue - num)/lastCutValue)*100.
                        row += isItOneHundred(fracLostToLast)
                    else:
                        row += " - "
                else:
                    row += " - "
            else:
                row += " - "
        row += r" \\\\"+"\n"
        #
        table += row
    #end of loop over cuts
    #
    #end of table
    table += "\t\t\t"+r"\\hline"+"\n"
    #end of tabular environment
    table += "\t\t"+r"\\end{tabular}"
    #
    return table
