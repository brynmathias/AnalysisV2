#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
import os
from montecarlo.Summer11.ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.QCD_Summer11_Pythia_All import *
from montecarlo.Summer11.TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1 import *
from montecarlo.Summer11.WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1 import *
samples = []
samples += [TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1,WJetsToLNu_250_HT_300_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_50_HT_100_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1, WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_19_jetCorrections_L1FastJet_L2Relative_L3Absolute_jetCollections_ak5calo_ak5pf_hbheNoiseFilterDefaultIsoReq_1,ZJetsToNuNu_100_HT_200_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1,ZJetsToNuNu_200_HT_inf_7TeV_madgraph_Summer11_PU_S4_START42_V11_v1]
#Want to measre the size of the samples on dcach.
#first get lits of dirs:
from montecarlo.Summer11.QCD_Pt_15to30_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_30to50_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_50to80_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_80to120_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_120to170_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_170to300_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_300to470_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_470to600_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_600to800_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_800to1000_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_1000to1400_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_1400to1800_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *
from montecarlo.Summer11.QCD_Pt_1800_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2 import *

QCD_Summer11_Pythia_All = [
QCD_Pt_15to30_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_30to50_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_50to80_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2, 
QCD_Pt_80to120_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2, 
QCD_Pt_120to170_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_170to300_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_300to470_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_470to600_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_600to800_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2, 
QCD_Pt_800to1000_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2, 
QCD_Pt_1000to1400_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_1400to1800_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
QCD_Pt_1800_TuneZ2_7TeV_pythia6_Summer11_PU_S3_START42_V11_v2,
]
from data.Run2011.HTRun2011AB import *
#samples = QCD_Summer11_Pythia_All 
lines = []
for sample in samples:
  for line in sample.File:
    newline = ""
    for sec in line.split("/")[3:-1]:
      newline += ("/"+sec)
    lines.append(newline)
text = ""
sumList = []
lines = list(set(lines))
print lines
sum = 0
print lines
print "%d lines to read"%(len(lines))
storage_element='srm://gfe02.grid.hep.ph.ic.ac.uk:8443/srm/managerv2?SFN=/pnfs/hep.ph.ic.ac.uk/data/cms'
for i,line in enumerate(lines):
  print "reading %d of %d"%(i,len(lines))
  path = storage_element+line
  for offset in range(3):
    p = os.popen("srmls --count=1000 --offset=%d %s/" % (offset*1000,path),'r')
    for line in (p.read().split("\n"))[3:]:
      if len(line.split(" ")) > 5:
        text += (line+"\n") 
        sum +=int(line.split(" ")[6].replace(" ",""))
        print "size so far is %d b, %d Mb, %f Tb"%(sum,float(sum)/(1024**2),float(sum)/(1024**4))


outF = open("./sizefile.txt",'w')
outF.write(text)
print "Total Size of %s = %f Mb, = %f Tb"%("ewk samples",float(sum)/(1024**2),float(sum)/(1024**4))
