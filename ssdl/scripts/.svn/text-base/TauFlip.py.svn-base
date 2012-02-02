#!/usr/bin/env python


import setupSUSY
from libFrameworkSUSY import *
from libSSDL import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.utils import *
from montecarlo.Spring11.TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import TTJets_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 as tt
from montecarlo.Spring11.QCD_TuneD6T_HT_100To250_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_100To250_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD1
from montecarlo.Spring11.QCD_TuneD6T_HT_250To500_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_250To500_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD2
from montecarlo.Spring11.QCD_TuneD6T_HT_500To1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_500To1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD3
from montecarlo.Spring11.QCD_TuneD6T_HT_1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 import QCD_TuneD6T_HT_1000_7TeV_madgraph_Spring11_PU_S1_START311_V1G1_v1 as QCD4
from montecarlo.Spring11.WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 as Wjets
from montecarlo.Spring11.LMx_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 import LM0_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1 as lm0
from montecarlo.Spring11.QCD_Pt_170to300_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_170to300_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd1
from montecarlo.Spring11.QCD_Pt_300to470_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_300to470_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd2
from montecarlo.Spring11.QCD_Pt_470to600_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_470to600_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd3
from montecarlo.Spring11.QCD_Pt_600to800_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  import QCD_Pt_600to800_TuneZ2_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1  as qcd4
from montecarlo.Spring11.DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 import DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1 as Zjets
import lep_conf as lepconf
import icf.utils as utils
import icf.types as types



# Standard classes for running and Analysis
# PSet is similar to the CMSSW PSet
# Analysis wraps the manager class for our convenience
from icf.core import PSet,Analysis

# This is the default configuration
from icf.config import defaultConfig 

# import default configuration

conf=defaultConfig

conf.Ntuple.Jets.Suffix="Pat"
conf.Ntuple.Jets.Uncorrected=False
conf.Ntuple.Jets.UseGenJets=False
conf.Ntuple.Jets.Prefix="ak5JetPF2PAT"
conf.Ntuple.SecJets.Prefix="ak5Jet"
conf.Common.Jets.PtCut = 40.0
conf.Common.Jets.EtaCut = 5.0
conf.Common.Jets.TightID=False
conf.Common.Jets.ApplyID=True

#############################
conf.Common.Muons.PtCut = 5.0
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.TightID = False
conf.Common.Muons.ApplyID = False

conf.Common.Electrons.PtCut = 10.0
conf.Common.Electrons.EtaCut = 2.4
conf.Common.Electrons.TrkIsoCut = 99.
conf.Common.Electrons.CombIsoCut = 99.
conf.Common.Electrons.TightID = False
conf.Common.Electrons.ApplyID = False

#############################
#conf.Ntuple.Taus.Prefix="tauHPS"
#conf.Ntuple.Taus.Suffix="PF"
conf.Ntuple.Taus.Suffix="PF"
conf.Common.Taus.TightID = False
conf.Common.Taus.ApplyID = False
conf.Common.Taus.PtCut =  15.0
conf.Common.Taus.EtaCut = 2.3


IsoTightTau=1
IsoLooseTau=0

tau_id = PSet(
    TauSource=conf.Ntuple.Taus.Prefix,
    tauIDbyIso = IsoTightTau,
#     tauIDbyDecay = True,
     AgainstElectron = True,
     AgainstMuon = True
)


ele_id = PSet(
    Cuts = lepconf.ele_ptThres_vbtf80,
)

muon_id = PSet(#we're missing the ecalvetoDep and hcalvetoDep in the ntuples (for MIP requirement) - AGB 22/10/10
   Cuts = lepconf.muonCuts,
)
elecSelFilter=CustomEleId(ele_id.ps())
muonSelFilter=CustomMuonId(muon_id.ps())
tauSelFilter=CustomTauId(tau_id.ps())

muelfilter=MuonElectronDrFilter(0.1)
eletaufilter=ElectronTauDrFilter(0.1)
mutaufilter=MuonTauDrFilter(0.1)

elejetfilter=ElectronJetDrFilter(0.4)
muonjetfilter=MuonJetDrFilter(0.4)
taujetfilter=TauJetDrFilter(0.1)



# Create the analysis
a=Analysis("TauFR")
tree = Tree("Main")


# Create a Tree called Main
tree = Tree("Main")
#from icf.config import Trigger

##############
## TRIGGERS ##
##############



a.AddMuonFilter("PreCC",muonSelFilter)
a.AddElectronFilter("PreCC",elecSelFilter)
a.AddTauFilter("PreCC",tauSelFilter)


a.AddElectronFilter("PreCC",muelfilter)
a.AddTauFilter("PreCC",mutaufilter)
a.AddTauFilter("PreCC",eletaufilter)

a.AddJetFilter("PreCC",taujetfilter) 
a.AddJetFilter("PreCC",elejetfilter)
a.AddJetFilter("PreCC",muonjetfilter)



TauFlip=TauBkgEval("TauFlip")
mcnoele = NOMC(11)
mcnomu = NOMC(13)
################################################
a += tree
##TRIGGERS
tree.Attach(mcnoele)
tree.TAttach(mcnoele,mcnomu)
tree.TAttach(mcnomu,TauFlip)

latestdata=[tt,QCD1,QCD2,QCD3,QCD4,Wjets,lm0,qcd1,qcd2,qcd3,qcd4,Zjets]
#latestdata=[lm0]
test=PSet(
        Name="test",
        Format=("ICF",3),
        File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_19_30_01//TTJets_TuneZ2_7TeV-madgraph-tauola.Spring11-PU_S1_START311_V1G1-v1.AODSIM//SusyCAF_Tree_10_1_1zt.root" ,
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_19_30_01//TTJets_TuneZ2_7TeV-madgraph-tauola.Spring11-PU_S1_START311_V1G1-v1.AODSIM//SusyCAF_Tree_11_1_Cqz.root" ,
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/bbetchar//ICF/automated/2011_04_07_19_30_01//TTJets_TuneZ2_7TeV-madgraph-tauola.Spring11-PU_S1_START311_V1G1-v1.AODSIM//SusyCAF_Tree_12_1_mN2.root" ,
        ],
        Weight=1.,
#        FirstEntry=2148,
#       LastEntry=200
)

#latestdata=[test]

a.Run(".", conf, latestdata)
