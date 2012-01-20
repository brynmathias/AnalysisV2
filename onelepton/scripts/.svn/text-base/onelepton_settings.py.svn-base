# this files overloads most of ../../framework/python/icf/config.py, if interested in a specific setting not found below please look the included file
## Calo and PF jet exchange is NOT just a matter of changing the Jet collection. CALO and PF treat muons in jets differntly, you have to look at the x-cleaning parameters. Also the residual corrections (if applied) do have to be changed !!!

import setupSUSY
from libFrameworkSUSY import *
from copy import deepcopy
from icf.core import PSet,Analysis
from icf.config import defaultConfig
import icf.utils as utils

#q2_scales = ["2.0","0.5","1.0"]
q2_scales = ["1.0"]

conf=defaultConfig.copy()
conf.Common.Jets.PtCut = 40.0
conf.Common.Jets.EtaCut = 2.4
conf.Common.Jets.TightID=False
conf.Common.Jets.ApplyID=False
# muons
conf.Common.Muons.EtaCut = 2.1
conf.Common.Muons.PtCut = 20.0
conf.Common.Muons.TrkIsoCut=999999.
conf.Common.Muons.CombIsoCut=0.1
conf.Common.Muons.TightID=False
conf.Common.Muons.ApplyID=False
# electrons
conf.Common.Electrons.PtCut = 15.0 #it was 15 put it so again
conf.Common.Electrons.EtaCut = 2.5
conf.Common.Electrons.TrkIsoCut=5.
conf.Common.Electrons.CombIsoCut=0.15
conf.Common.Electrons.TightID=False
conf.Common.Electrons.ApplyID=False
# photons
conf.Common.Photons.EtCut = 25.0
conf.Common.Photons.EtaCut = 2.5
conf.Common.Photons.TrkIsoRel=0.
conf.Common.Photons.TrkIsoCut=99999.
conf.Common.Photons.EcalIsoRel=0.
conf.Common.Photons.EcalIsoCut=99999.
conf.Common.Photons.HcalIsoRel=0.
conf.Common.Photons.HcalIsoCut=99999.
conf.Common.Photons.HadOverEmCut=0.5
conf.Common.Photons.SigmaIetaIetaCut=0.5
#conf.Common.Photons.CaloIsoCut=0.2
conf.Common.Photons.IDReq=2
conf.Common.ApplyXCleaning=False
# If you use calo jets be aware that muons in jets ARE not added to the jet. For PFjets they are already in the jets, to steer the xcleaning, do default_cc = deepcopy(defaultConfig.XCleaning) and overload stuff

conf.Ntuple.Weight="User"
conf.Ntuple.Electrons.Prefix="electron"
conf.Ntuple.Electrons.Suffix="Pat"
conf.Ntuple.Electrons.LooseID="EIDLoose"
conf.Ntuple.Electrons.TightID="EIDTight"
conf.Ntuple.Muons.Prefix="muon"
conf.Ntuple.Muons.Suffix="Pat"
conf.Ntuple.Muons.LooseID="IsGlobalMuon"
conf.Ntuple.Muons.TightID="IDGlobalMuonPromptTight"
conf.Ntuple.Jets.Prefix="ak5JetPF"
# if you switch to CaloJets, check that care about how muons are added to jets. Read also comment at top of page
conf.Ntuple.Jets.Suffix="Pat"
conf.Ntuple.Jets.Uncorrected=False
conf.Ntuple.Jets.UseGenJets=False
conf.Ntuple.SecMuons.Prefix="muon"
conf.Ntuple.SecMuons.Suffix="PF"
conf.Ntuple.TerJets.Prefix="ak5JetPF2PAT"
conf.Ntuple.TerJets.Suffix="Pat"

# note that these corrections are presumably outdated once you read this!!!
from icf.JetCorrections import *
#corPset =  CorrectionPset("ResidualJetEnergyCorrections.txt") # Calo Jets (pre CMSSW_4_1_X)
corPset = CorrectionPset("Spring10DataV2_L2L3Residual_AK5PF.txt") # PF Jets (pre CMSSW_4_1_X)

## lepton definitions ######
## Muon definition
Mus = PSet(
    MuID = "Tight",
    MinPt = 20.,
    MaxEta = 2.1,
    MaxIsolation = 0.1,
    DRMuJet = 0.3,
    MaxGlbTrkDxy = 0.02,
    MinGlbTrkNumOfValidHits = 11,
    SegMatch2GlbMu = 1,
    PixelHitsOnInrTrk = 1,
    MaxInrTrkDz = 1.
    )


## Electron definition
import wpol.electron_id as eid
id_sig = eid.eff_80

Els_Sig = PSet(
    Cuts = id_sig,
    PtMin = 20.,
    Isolation = 1,
    HoverE = 1,
    DeltaEtaAtVtx = 1,
    DeltaPhiAtVtx = 1,
    SigmaIEtaIEta = 1,
    Conversions = 1,
    ConversionsExtra = 1,
    SupressErrors = True,
    D0BS = 0.02
    )

# Anti-selection electron ID
# The convention below is
# 1 -> apply criterion
# 0 -> invert criterion
# -1 -> ignore criterion

id_qcd = eid.eff_custom

Els_QCD = PSet(
    Cuts = id_qcd,
    PtMin = 20.,
    # Apply Isolation and HoE cuts
    Isolation = 1,
    HoverE = 1,
    # Invert DeltaEta/DeltaPhi
    DeltaEtaAtVtx = 0,
    DeltaPhiAtVtx = 0,
    # Ignore the rest
    SigmaIEtaIEta = -1,
    Conversions = -1,
    ConversionsExtra = -1,
    SupressErrors = True,
    d0dzCutApplied = False,
    DetaOrDphi = True
    )


id_veto = eid.eff_95

Els_Veto = PSet(
    Cuts = id_veto,
    PtMin = 15.,
    Isolation = 1,
    HoverE = 1,
    DeltaEtaAtVtx = 1,
    DeltaPhiAtVtx = 1,
    SigmaIEtaIEta = 1,
    Conversions = 1,
    ConversionsExtra = 1,
    SupressErrors = 1,
    D0BS = 0.1
    )

