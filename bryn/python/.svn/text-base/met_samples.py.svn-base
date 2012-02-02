#!/usr/bin/env python
"""
met_samples.py

Created by Bryn Mathias on 2010-05-07.
"""
import array
from icf.core import PSet

SusyCafDataSkim=PSet(
Name="SusyCafDataSkim",
File="/castor/cern.ch/user/b/bbetchar//SusyCAF/automated/2010_04_24_23_38_50/Skims/TwoCaloJets_pt10.root",
Weight=1.0,
Format=("ICF",2)
)

MCPath="/castor/cern.ch/user/b/bbetchar//SusyCAF/automated/2010_04_26_02_57_56/"
fileMC=[MCPath + "SusyCAF_Tree_" + str(i) + "_1.root" for i in range (1 ,114)] #Pulls all the files from castor in the MC path


SusyCafMC=PSet(
Name="SusyCafMC",
File=fileMC,
Format=("ICF",2),
Weight=1.0
)

ICDataSkim=PSet(
Name="ICDataSkim",
File=["/vols/cms02/elaird1/03_skims/cleaned/JetMETTau.Run2010A-May27thReReco_v1.RECO/*.root","/vols/cms02/elaird1/03_skims/cleaned/MinimumBias.Commissioning10-SD_JetMETTau-v9.RECO/*.root","/vols/cms02/elaird1/03_skims/cleaned/MinimumBias.Commissioning10-May6thPDSkim2_SD_JetMETTau-v1.RECO/*.root"],
Format=("ICF",2),
Weight=1.0
)

ICMCSkim=PSet(
Name="ICMCSkim",
File="/vols/cms02/elaird1/03_skims/QCD_Pt-15_7TeV-pythia8.Spring10-START3X_V26B-v1.GEN-SIM-RECO/*.root",
Format=("ICF",2),
Weight=1.0
)