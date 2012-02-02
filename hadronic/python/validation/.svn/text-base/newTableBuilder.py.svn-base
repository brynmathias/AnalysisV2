#!/usr/bin/env python

import sys
import re
import commands

from toolkit import newBuildTable, smVsDataTable

from newresults_cff import *
from newcuts_cff import *

lumi = float(sys.argv[1])

def makeTable(resultsfiles,cuts,lumi,ncomjets,filename):
    table = newBuildTable(resultsfiles,cuts,lumi,ncomjets)

    #get the table .tex file
    file = open("templates/a4_table_temp.tex","r")
    table_tex = file.read()
    
    p = re.compile('TABLECONTENTS')
    newtable_tex = p.sub(table, table_tex)
    #q = re.compile('SUMMARY')
    q = re.compile('CAPTION')
    caption_text = r"Cut flow for $"
    caption_text += "%s " % (lumi)
    caption_text += r"\\, \\textrm{pb}^{-1}$ "
    if (ncomjets=="2eq"):
        caption_text += r" for $N^{j} = 2$"
    elif (ncomjets=="3om"):
        caption_text += r" for $N^{j} \\geq 3$"
    elif (ncomjets=="2om"):
        caption_text += r" for $N^{j} \\geq 2$"
    caption_text += ". \n"
    caption_text += " Column $a)$ is the number of events passing the cut,\n"
    caption_text += "column $b)$ is the percentage of events lost of those passing the intial\n"
    caption_text += r"$H_T > 250 \\, \\gev$ cut (cumulative), and"
    caption_text += "\n column $c)$ is the percentage lost from the previous cut."
    newtable_tex = q.sub(caption_text, newtable_tex)
    #
    temp = open("mytable.tex", 'w')
    temp.write(newtable_tex)
    temp.close()
    
    output = commands.getstatusoutput("pdflatex mytable.tex")
    output = commands.getstatusoutput("pdflatex mytable.tex")
    myfilename = filename+"_"+ncomjets
    output = commands.getstatusoutput("mv mytable.tex "+myfilename+".tex")
    output = commands.getstatusoutput("mv mytable.pdf "+myfilename+".pdf")

makeTable(EWKresults,cuts,lumi,"2om","EWKresults")
makeTable(EWKresults,cuts,lumi,"2eq","EWKresults")
makeTable(EWKresults,cuts,lumi,"3om","EWKresults")
makeTable(QCD36results,cuts,lumi,"2om","QCD36results")
makeTable(QCD36results,cuts,lumi,"2eq","QCD36results")
makeTable(QCD36results,cuts,lumi,"3om","QCD36results")
makeTable(QCD38results,cuts,lumi,"2om","QCD38results")
makeTable(QCD38results,cuts,lumi,"2eq","QCD38results")
makeTable(QCD38results,cuts,lumi,"3om","QCD38results")
makeTable(PhoJetresults,cuts,lumi,"2om","PhoJetresults")
makeTable(PhoJetresults,cuts,lumi,"2eq","PhoJetresults")
makeTable(PhoJetresults,cuts,lumi,"3om","PhoJetresults")
makeTable(signalresults,cuts,lumi,"2om","signalresults")
makeTable(signalresults,cuts,lumi,"2eq","signalresults")
makeTable(signalresults,cuts,lumi,"3om","signalresults")

#gs -dBATCH -dNOPAUSE -q -sDEVICE=pdfwrite -sOutputFile=finished.pdf file1.pdf file2.pdf
