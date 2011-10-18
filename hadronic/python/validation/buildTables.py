#!/usr/bin/env python

import sys
import re
import commands

from toolkit import newBuildTable, smVsDataTable

from newresults_cff import *
from newcuts_cff import *

lumi = float(sys.argv[1])

def makeTable(smresultsset,dataresults,cuts,lumi,ncomjets,tablename):
    print "Making table with lumi = " + str(lumi)
    table = smVsDataTable(smresultsset,dataresults,cuts,lumi,ncomjets)
    
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
    caption_text += "\n column $c)$ is the percentage lost from the previous cut.\n"
    caption_text += r"Pythia samples made with \\code{"+tablename+"}."
    newtable_tex = q.sub(caption_text, newtable_tex)
    #
    temp = open("mytable.tex", 'w')
    temp.write(newtable_tex)
    temp.close()
    
    output = commands.getstatusoutput("pdflatex mytable.tex")
    output = commands.getstatusoutput("pdflatex mytable.tex")
    filename = tablename+"_"+ncomjets
    output = commands.getstatusoutput("mv mytable.tex "+filename+".tex")
    output = commands.getstatusoutput("mv mytable.pdf "+filename+".pdf")


makeTable(SM_36,dataresults,cuts,lumi,"2om","cmssw361patch4-V00-12-15")
makeTable(SM_36,dataresults,cuts,lumi,"2eq","cmssw361patch4-V00-12-15")
makeTable(SM_36,dataresults,cuts,lumi,"3om","cmssw361patch4-V00-12-15")
makeTable(SM_38,dataresults,cuts,lumi,"2om","cmssw384patch3-V12-00-02")
makeTable(SM_38,dataresults,cuts,lumi,"2eq","cmssw384patch3-V12-00-02")
makeTable(SM_38,dataresults,cuts,lumi,"3om","cmssw384patch3-V12-00-02")
