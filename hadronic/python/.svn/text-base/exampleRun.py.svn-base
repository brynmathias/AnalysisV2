#!/usr/bin/env python
"""
Created by Bryn Mathias on 04/03/2011.
"""


# -----------------------------------------------------------------------------
# Necessary includes
import errno
import os
import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.config import defaultConfig
from copy import deepcopy
from icf.JetCorrections import *
from hadronic.samples_cff import * #import samples
# -----------------------------------------------------------------------------
#  A little bit of python for making sure a directory exists, useful for scripts where you want to have lots of different output files in different places
def ensure_dir(path):
    try:
      os.makedirs(path)
    except OSError as exc: # Python >2.5
      if exc.errno == errno.EEXIST:
        pass
      else: raise

examplePlotSet = OP_examplePlots(
                                 PSet(
                                      DirName       = "ExamplePlots",
                                      MinObjects    = 2,
                                      MaxObjects    = 15,
                                      ExamplePlots = True,
                                      ).ps()
                                 )

# -----------------------------------------------------------------------------
# Reading the collections from the ntuple

from hadronic.golden_cff import * #This is done for you here, this gives you a "common" setup
from hadronic.commonIncludes import *
# -----------------------------------------------------------------------------
# Now build the analysis

cutTreeData = Tree("Data")
cutTreeData.Attach(DataTrigger)
cutTreeData.TAttach(DataTrigger,NoiseFilt)
cutTreeData.TAttach(NoiseFilt,selection)
cutTreeData.TAttach(selection,oddMuon)
cutTreeData.TAttach(oddMuon,oddElectron)
cutTreeData.TAttach(oddElectron,oddPhoton)
cutTreeData.TAttach(oddPhoton,numComLeptons)
cutTreeData.TAttach(numComLeptons,numComPhotons)
cutTreeData.TAttach(numComPhotons,LeadingJetEta)
cutTreeData.TAttach(LeadingJetEta,badMuonInJet)
cutTreeData.TAttach(badMuonInJet,oddJet)
cutTreeData.TAttach(oddJet,LeadingJetCut)
cutTreeData.TAttach(LeadingJetCut,secondJetET)
cutTreeData.TAttach(secondJetET,VertexPtOverHT)
cutTreeData.TAttach(VertexPtOverHT,htCut250)
#FOR HT > 250Gev Plot
cutTreeData.TAttach(htCut250,examplePlotSet)


#Second MC!


cutTreeMC = Tree("MC")
cutTreeMC.Attach(selection)
cutTreeMC.TAttach(selection,oddMuon)
cutTreeMC.TAttach(oddMuon,oddElectron)
cutTreeMC.TAttach(oddElectron,oddPhoton)
cutTreeMC.TAttach(oddPhoton,numComLeptons)
cutTreeMC.TAttach(numComLeptons,numComPhotons)
cutTreeMC.TAttach(numComPhotons,LeadingJetEta)
cutTreeMC.TAttach(LeadingJetEta,badMuonInJet)
cutTreeMC.TAttach(badMuonInJet,oddJet)
cutTreeMC.TAttach(oddJet,LeadingJetCut)
cutTreeMC.TAttach(LeadingJetCut,secondJetET)
cutTreeMC.TAttach(secondJetET,VertexPtOverHT)
cutTreeMC.TAttach(VertexPtOverHT,htCut250)
#FOR HT > 250Gev Plot
cutTreeMC.TAttach(htCut250,examplePlotSet)

def addCutFlowData(a) :
  a.AddJetFilter("PreCC",JetCorrections)
  a+=cutTreeData

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)


anal_ak5_caloData.Run("../results/",conf_ak5_caloData,[Jet_MultiJet_JetMet_38_JSonUpTo151010])




