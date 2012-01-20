from icf.core import PSet

# Define the muonID parameters to filter on
muon_id = PSet(
    NumValidTrackerHits = 10,
    #NumPixelHits = 1,
    #NumMatches = 2,
    dxychoice = "beamspot",
    dxyclosestzvertex = 0.20,#0.2cm (200 microns)
    dxybeamspot = 0.20 #0.2 (200 microns)
)

# Define the muonID parameters to filter on (latest ID)
muon_id_latest = PSet(
    NumValidTrackerHits = 10,
    NumPixelHits = 1,
    NumMatches = 2,
    dxychoice = "beamspot",
    dxyclosestzvertex = 0.20,#0.2cm (200 microns)
    dxybeamspot = 0.20 #0.2 (200 microns)
)

# Define some parameters for the muon scale shift
muon_scale_shift = PSet(
    scalechoice = 100.0,
    scaleshift = 0.01,
    plusplus = True
)

# This is the default configuration
from icf.config import defaultConfig

# We can override the configuration we imported
conf=defaultConfig
conf.Ntuple.Jets.Prefix="ak5JetPF2PAT"
conf.Ntuple.Jets.Suffix="Pat"
conf.Ntuple.Jets.Uncorrected=False
conf.Common.Jets.PtCut=20.0
conf.Common.Jets.EtaCut=5.0
#conf.Common.Jets.EMFracCut=0.95

conf.Common.Muons.EtaCut=2.1
conf.Common.Muons.PtCut=20.0 
conf.Common.Muons.TrkIsoCut=-1.0 #i.e. we are ignoring it
conf.Common.Muons.CombIsoCut=0.15
conf.Common.Muons.ApplyID = True
conf.Common.Muons.TightID = True

conf.Common.Electrons.PtCut=15.0
conf.Common.Electrons.EtaCut=3.0
conf.Common.Electrons.TrkIsoCut=1.0

conf.Common.Photons.EtCut=25.0
conf.Common.Photons.IDReq=3

conf.Common.ApplyXCleaning=True

# -----------------------------------------------------------------------------
# Secondary Jet Collection settings (PF2PAT has exclusive muon/jet collections etc)
conf.Ntuple.SecJets.Prefix="ak5JetPF"
conf.Ntuple.SecJets.Suffix="Pat"
conf.Ntuple.SecJets.Uncorrected=False
# Tertiary Jet Collection settings (the three collections MUST be independent)
conf.Ntuple.TerJets.Prefix="ak5Jet"
conf.Ntuple.TerJets.Suffix="Pat"
conf.Ntuple.TerJets.Uncorrected=False

# -----------------------------------------------------------------------------
# Cross-cleaning settings

conf.XCleaning.Verbose=False
conf.XCleaning.MuonJet=True
conf.XCleaning.ElectronJet=True
conf.XCleaning.PhotonJet=False
conf.XCleaning.ResolveConflicts=False
#conf.XCleaning.Jets.EtCut=0.
#conf.XCleaning.Jets.EtaCut=1000.0
#conf.XCleaning.Muons.PtCut=0.
#conf.XCleaning.Muons.EtaCut=1000.
#conf.XCleaning.Muons.TrkIsoCut=-1.
#conf.XCleaning.Muons.CombIsoCut=6.
#conf.XCleaning.Electrons.PtCut=0.0
#conf.XCleaning.Electrons.EtaCut=1000.0
#conf.XCleaning.Electrons.TrkIsoCut=6.0
#conf.XCleaning.Electrons.CombIsoCut=0.2
#conf.XCleaning.Photons.EtCut=0.0
#conf.XCleaning.Photons.EtaCut=1000.0
#conf.XCleaning.Photons.TrkIsoCut=9.
#conf.XCleaning.Photons.AllIsoCut=0.2
#conf.XCleaning.Photons.IDReq=2
