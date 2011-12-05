#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
import os

#Want to measre the size of the samples on dcach.
#first get lits of dirs:

from data.Run2011.HTRun2011AB import *
lines = []
for line in HTRun2011AB.File:
  newline = ""
  for sec in line.split("/")[3:]:
    newline += ("/"+sec)
  lines.append(newline)
print "%d lines to read"%(len(lines))

sumList = []
lines = list(set(lines))
sum = 0
storage_element='srm://gfe02.grid.hep.ph.ic.ac.uk:8443/srm/managerv2?SFN=/pnfs/hep.ph.ic.ac.uk/data/cms'
for i,line in enumerate(lines):
  print "reading %d of %d"%(i,len(lines))
  path = storage_element+line
  #print path
  p=os.popen("srmls --count=10 %s" % path,'r')
  
  #print p.read()
  i = 0
  sumList.append(p.read().split("\n")[2].split("/")[0].replace(" ",""))
#    val = field.split(" ")[0]
#    sum += int(val)


outF = open("./sizefile.txt",'w')
outF.write(sumList)
print "Total Size = %f Mb"%(float(sum)/(1024**2))
