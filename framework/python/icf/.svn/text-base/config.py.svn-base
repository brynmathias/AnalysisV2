from core import PSet
defaultConfig= PSet(
    # Controls configuration of common object collections
    LogFileFormat="JSON",# JSON or text (default is JSON)
    Common=PSet(
        ApplyXCleaning=False,
        Electrons=PSet(
            PtCut=20.,
            EtaCut=2.5,
            TrkIsoCut=5.,
            CombIsoCut=0.1,
            TightID=False,
            ApplyID=True,
            RequireLooseForOdd=False,
  ),
        Muons=PSet(
            PtCut=20.,
            EtaCut=2.5,
            TrkIsoCut=3.,
            CombIsoCut=0.1,
            TightID=False,
            ApplyID=True,
            RequireLooseForOdd=True,
  ),
        Taus=PSet(
            PtCut=20.,
            EtaCut=2.5,
            ElecClean=False,
            MuonClean=False,
            JetClean=False,
            TightID=False,
            ApplyID=True
            ),
        Jets=PSet(
            PtCut=30.,
            EtaCut=2.5,
            TightID=False,
            ApplyID=True,
            ),
        Photons=PSet(
            EtCut=40.,
            EtaEBMaxCut=1.479,
            EtaEEMinCut=1.525,
            EtaEEMaxCut=2.5,
            EcalIsoCut=4.,
            EcalIsoRel=0.,
            HcalIsoCut=2.,
            HcalIsoRel=0.,
            TrackIsoCut=2.,
            TrackIsoRel=0.,
            HadOverEmCut=0.05,
            R9Cut=0.,
            SigIhIhEBCut=0.015,
            SigIhIhEECut=0.035,
            UseID=True,
            IDReq=3,
            RequireLooseForOdd=False,
            ),
        AlphaT=PSet(
        CalcWithEt=True,
        ),
        ),

    Gen=PSet(
        Electrons=PSet(
            PtCut=-1.,
            EtaCut=999.,
        ),
        Muons=PSet(
            PtCut=-1.,
            EtaCut=999.,
        ),
    ),

    XCleaning=PSet(
        Verbose=False,
        MuonJet=False,
        ElectronJet=False,
        PhotonJet=False,
        TauJet=False,
        ResolveConflicts=False,
        Jets=PSet(
            PtCut=40.,
            EtaCut=2.5,
        ),
        Muons=PSet(
            PtCut=5.,
            EtaCut=2.5,
            TrkIsoCut=10.,
            CombIsoCut=10.,
            ModifyJetEnergy=True,
            MuonJetDeltaR=0.5,       # TW added 13/10/2010
            MuonIsoTypePtCutoff=30., # TW added 13/10/2010
            RequireLooseIdForInitialFilter=True, # TW added 14/10/2010
        ),
        Electrons=PSet(
            PtCut=5.,
            EtaCut=2.5,
            TrkIsoCut=10.,
            CombIsoCut=10.,
            ElectronJetDeltaR=0.5,        # TW added 13/10/2010
            ElectronIsoTypePtCutoff=30.,  # TW added 13/10/2010
            ElectronLooseIdRequired=False, # TW added 13/10/2010
            ElectronTightIdRequired=False, # TW added 13/10/2010
            RequireLooseIdForInitialFilter=True, # TW added 14/10/2010
        ),
        Photons=PSet(
            EtCut=40.,
            EtaEBMaxCut=1.479,
            EtaEEMinCut=1.525,
            EtaEEMaxCut=2.5,
            TrkIsoCut=2.,
            CaloIsoCut=6.,
            UseID=True,
            IDReq=1,
            PhotonJetDeltaR=0.5,         # TW added 13/10/2010
            PhotonIsoTypePtCutoff=30.,
        ),
    ),
    # Controls which bits of the ntuple will be used by the code
    Ntuple=PSet(
        Weight="User",
        Electrons=PSet(
            Prefix="electron",
            Suffix="Pat",
            LooseID="EIDLoose",
            TightID="EIDTight"),
        Muons=PSet(
            Prefix="muon",
            Suffix="Pat",
            LooseID="IsGlobalMuon",
            TightID="IDGlobalMuonPromptTight"),
        SecMuons=PSet(
            Prefix="muon",
            Suffix="PF"),
        Taus=PSet(
            Prefix="tau",
            Suffix="PF"),
        SecTaus=PSet(
            Prefix="tauHPS",
            Suffix="PF"),
        Jets=PSet(
            Prefix="ak5Jet",
            Suffix="Pat",
            Uncorrected=False,
            UseGenJets=False),
        SecJets=PSet(
            Prefix="ak5JetPF2PAT",
            Suffix="Pat",
            Uncorrected=False, #<TW date="07/11/2010" />
            ),
        TerJets=PSet(
            Prefix="ak5JetJPT",
            Suffix="Pat",
            Uncorrected=False,
            ),
        Photons=PSet(
             Prefix="photon",
             Suffix="Pat")
        ),
    NT7=PSet(
        JetCorrType='MC',
        Smear=PSet(
            IsJetSmeared=False,
            SmearJetType='pT',
            SmearJetFactor=0.,
            SmearJetNonGaussNorm=0.,
            SmearJetRespFuncFileName='./Response.root'
            ),
        GenMatch=PSet(
            JetEtaLTReq=100.,
            ElecPzLTReqForMatch=998.,
            MuonPzLTReqForMatch=998.
            ),
        Xclean=PSet(
            ElecCcAssocElecReq=False,
            MuonCcAssocMuonReq=False,
            JetCcAssocJetReq=False,
            PhotCcAssocPhotReq=False,
            )
        )

    )
