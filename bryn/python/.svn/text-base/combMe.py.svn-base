#!/usr/bin/env python
import ROOT as r
import glob
import sys
from combiner import *
# class Combiner(object):
#   """Adds histograms in subdirectories of a root file outputting them to a new root file"""
#   def __init__(self, RootFile):
#     super(Combiner, self).__init__()
#     self.arg = arg
#     self.RootFile = RF
#

fileList = [
"AK5Calo_Jets.root",
"AK5Calo_QCD_All.root",
"AK5Calo_Zinv.root",
"AK5Calo_WJets.root",
"AK5Calo_TTbar.root",
"AK5Calo_LM0.root",
"AK5Calo_LM1.root",
"AK5Calo_LM2.root",
"AK5Calo_LM3.root",
"AK5Calo_LM4.root",
"AK5Calo_LM5.root",
"AK5Calo_LM6.root",
"AK5Calo_LM7.root",
"AK5Calo_SingleTop.root",
"AK5PF_Jets.root",
"AK5PF_QCD_All.root",
"AK5PF_Zinv.root",
"AK5PF_WJets.root",
"AK5PF_TTbar.root",
"AK5PF_LM0.root",
"AK5PF_LM1.root",
"AK5PF_LM2.root",
"AK5PF_LM3.root",
"AK5PF_LM4.root",
"AK5PF_LM5.root",
"AK5PF_LM6.root",
"AK5PF_LM7.root",
"AK5PF_SingleTop.root",
]

resultsDir = sys.argv[1]
aa = glob.glob(resultsDir)
#print aa
for a in aa:
  for b in fileList:
    # print a.rpartition("/")[2],b
    if a.rpartition("/")[2] == b:
      Combiner(a)





