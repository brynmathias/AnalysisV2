#!/usr/bin/env python

import sys
import re
import commands

from toolkit import buildTable

from myresults_cff import *
from mycuts_cff import *

lumi = float(sys.argv[1])

#
#buildTable is a function defined in toolkit.py
#resultsfiles and cuts are set in the myresults_cff and mycuts_cff respectively.
#The 3rd argument is: Is there data in there?
#The 4th argument is the integrated luminosity of the data.
#table = buildTable(resultsfiles,cuts,True,10.9357)
#table = buildTable(resultsfiles,cuts,True,lumi)
#table = buildTable(resultsfilesoddatend,cutsoddatend,True,6.679)
table = buildTable(resultsfilesnewid,cuts,True,lumi)
#table = buildTable(resultsfilesnewidoddatend,cutsoddatend,True,6.679)
#
#print table
#
#get the table .tex file
file = open("templates/table_temp.tex","r")
table_tex = file.read()

p = re.compile('TABLECONTENTS')
newtable_tex = p.sub(table, table_tex)
q = re.compile('SUMMARY')
summary_text = r"Cut flow for $"
summary_text += "%s " % (lumi)
summary_text += r"\\, \\textrm{pb}^{-1}$"
newtable_tex = q.sub(summary_text, newtable_tex)
#
temp = open("mytable.tex", 'w')
temp.write(newtable_tex)
temp.close()

#output = commands.getstatusoutput("pdflatex mytable.tex")
