#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from libHadronic import *
from icf.core import PSet,Analysis
from time import strftime
from time import strftime
from batchGolden import *

from ra1objectid.vbtfElectronId_cff import *
from ra1objectid.vbtfMuonId_cff import *
from ra1objectid.ra3PhotonId_cff import *
vbtfMuonId_cff = Muon_IDFilter( vbtfmuonidps.ps()  )
vbtfElectronIdFilter = Electron_IDFilter( vbtfelectronidWP95ps.ps() )
ra3PhotonIdFilter    = Photon_IDFilter( ra3photonidps.ps() )
PreScaleWeights      = PreScaleReweighting(datatriggerps.ps())

cutTree,blah,l = MakeDataTree(100.)


def addCutFlowData(a) :
  # a.AddJetFilter("PreCC",JetCorrections)
  a.AddPhotonFilter("PreCC",ra3PhotonIdFilter)
  a.AddElectronFilter("PreCC",vbtfElectronIdFilter)
  a.AddMuonFilter("PreCC",vbtfMuonId_cff)
  a+=cutTree

# AK5 Calo

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

# AK5 PF

conf_ak5_pfData = deepcopy(defaultConfig)
conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfData.XCleaning = deepcopy(default_cc)
conf_ak5_pfData.Common = deepcopy(default_common)
anal_ak5_pfData=Analysis("AK5PF")
addCutFlowData(anal_ak5_pfData)


from data.Run2011.HT_Run2011_promptReco_DCS import *
from data.Run2011.RA1ToBurn import *
from data.Run2011.HT42_incomplete import *
from data.Run2011.HT_Run2011A import *
from data.Run2011.HTRun2011AB import *
test = PSet(
Name = "test",
Format = ("ICF",3),
Weight = 1.0,
File = "../../Ntuples/375_newFormat.root")
outdir = "../results_"+strftime("%d_%b_%H")+"/Data/"
ensure_dir(outdir)
anal_ak5_caloData.Run(outdir,conf_ak5_caloData,[HTRun2011AB])#HT_Run2011A])
