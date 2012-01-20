#include "ICF_NtupleData.hh"


#include "ICF_Compute.hh"

#include <cmath>
#include <string>
#include <stdexcept>
#include "EventData.hh"
#include "Utils.hh"
namespace ICF{

Event::Element<std::vector<int>* , NtupleData>&
NtupleData::GetMuonIDBranch(const std::string & id){
  if(id=="IsGlobalMuon") return muonIsGlobalMuon;
  else if(id=="IDGlobalMuonPromptTight") return muonIDGlobalMuonPromptTight;
  else throw std::invalid_argument("Invalid muon ID specified: "+id);
}

Event::Element<std::vector<float>* , NtupleData>&
NtupleData::GetElectronIDBranch(const std::string & id){
  if(id=="EIDLoose") return electronEIDLoose;
  else if(id=="EIDTight") return electronEIDTight;
  else throw std::invalid_argument("Invalid electron ID specified: "+id);
}




NtupleData::NtupleData(const std::string & fileName,
                       const std::vector<std::string> & fileList,
           const std::string & dataSetName,
           UInt_t lastEntry,
           UInt_t firstEntry,
           double reWeight) :
    Event::NtupleData(fileName,fileList,dataSetName, lastEntry,
                      firstEntry),
    mElectronPrefix(Utils::GetConfig<std::string>("Ntuple.Electrons.Prefix")),
    mElectronSuffix(Utils::GetConfig<std::string>("Ntuple.Electrons.Suffix")),
    mEIDLoose(Utils::GetConfig<std::string>("Ntuple.Electrons.LooseID")),
    mEIDTight(Utils::GetConfig<std::string>("Ntuple.Electrons.TightID")),
    mMuonPrefix(Utils::GetConfig<std::string>("Ntuple.Muons.Prefix")),
    mMuonSuffix(Utils::GetConfig<std::string>("Ntuple.Muons.Suffix")),
    //MICHELE ->Secondary Muon Collection
    mSecMuonPrefix(Utils::GetConfig<std::string>("Ntuple.SecMuons.Prefix")),
    mSecMuonSuffix(Utils::GetConfig<std::string>("Ntuple.SecMuons.Suffix")),

    //MICHELE ->Secondary Muon Collection
    mMuonIDLoose(Utils::GetConfig<std::string>("Ntuple.Muons.LooseID")),
    mMuonIDTight(Utils::GetConfig<std::string>("Ntuple.Muons.TightID")),
    mJetPrefix(Utils::GetConfig<std::string>("Ntuple.Jets.Prefix")),
    mJetSuffix(Utils::GetConfig<std::string>("Ntuple.Jets.Suffix")),
    //AGB - Sec jet collection
    mSecJetPrefix(Utils::GetConfig<std::string>("Ntuple.SecJets.Prefix")),
    mSecJetSuffix(Utils::GetConfig<std::string>("Ntuple.SecJets.Suffix")),
    mTerJetPrefix(Utils::GetConfig<std::string>("Ntuple.TerJets.Prefix")),
    mTerJetSuffix(Utils::GetConfig<std::string>("Ntuple.TerJets.Suffix")),
    mTauPrefix(Utils::GetConfig<std::string>("Ntuple.Taus.Prefix")),
    mTauSuffix(Utils::GetConfig<std::string>("Ntuple.Taus.Suffix")),
    mSecTauPrefix(Utils::GetConfig<std::string>("Ntuple.SecTaus.Prefix")),
    mSecTauSuffix(Utils::GetConfig<std::string>("Ntuple.SecTaus.Suffix")),
    mPhotonPrefix(Utils::GetConfig<std::string>("Ntuple.Photons.Prefix")),
    mPhotonSuffix(Utils::GetConfig<std::string>("Ntuple.Photons.Suffix")),

    // General event data
    RunNumber(mDataTree,"run",this),
    EventNumber(mDataTree,"event",this),
    pthat(mDataTree,"genpthat",this),
    LumiSection(mDataTree,"lumiSection",this),
    IsData(mDataTree,"isRealData",this),
    SusyCrossSection(mDataTree,"susyScanCrossSection",this),
    M0(mDataTree,"susyScanM0",this),
    M12(mDataTree,"susyScanM12",this),
    Mu(mDataTree,"susyScanMu",this),
    SMSvalid(mDataTree,"SimpModelScanHandleValid",this),
    MChi(mDataTree,"SimpModelScanxCHI",this),
    MG(mDataTree,  "SimpModelScanmGL",this),
    MLSP(mDataTree,"SimpModelScanmLSP",this),
    TanBeta(mDataTree,"susyScantanbeta",this),
    MGluino(mDataTree, "susyScanMassGluino", this),
    MSquark(mDataTree, "susyScanMassSquark", this),
    MChi0(mDataTree, "susyScanChi0", this),
    RA2TrackingFailureFilter(mDataTree, "Result", this),
    RA2ecaldeadcellfilterflag(mDataTree, "ecaldeadcellfilterflag", this),
    hbheNoiseFilter(mDataTree, "hbheNoiseFilterResult", this),
    beamHaloCSCTightHaloId(mDataTree, "beamHaloCSCTightHaloId", this),
    tracksNEtaLT0p9AllTracks(mDataTree, "tracksNEtaLT0p9AllTracks", this),
    tracksNEta0p9to1p5AllTracks(mDataTree, "tracksNEta0p9to1p5AllTracks", this),
    tracksNEtaGT1p5AllTracks(mDataTree, "tracksNEtaGT1p5AllTracks", this),
    tracksNEtaLT0p9HighPurityTracks(mDataTree, "tracksNEtaLT0p9HighPurityTracks", this),
    tracksNEta0p9to1p5HighPurityTracks(mDataTree, "tracksNEta0p9to1p5HighPurityTracks", this),
    tracksNEtaGT1p5HighPurityTracks(mDataTree, "tracksNEtaGT1p5HighPurityTracks", this),

    vertexNdof(mDataTree, "vertexNdof", this),
    vertexIsFake(mDataTree, "vertexIsFake", this),
    vertexSumPt(mDataTree, "vertexSumPt", this),
    vertexPosition(mDataTree,"vertexPosition",this),
    vertexNtrks(mDataTree,"vertexNtrks",this),

    physicsDeclared(mDataTree, "physicsDeclared",this),

    // Electrons
    electronP4(mDataTree,mElectronPrefix+"P4"+mElectronSuffix,this),
    electronVx(mDataTree,mElectronPrefix+"Vertex"+mElectronSuffix,this),
    electronCharge(mDataTree,mElectronPrefix+"Charge"+mElectronSuffix,this),

    electronTrkIso(mDataTree,mElectronPrefix+"TrackIso"+mElectronSuffix,this),
    electronEcalIso(mDataTree,mElectronPrefix+"EcalIso"+mElectronSuffix,this),
    electronHcalIso(mDataTree,mElectronPrefix+"HcalIso"+mElectronSuffix,this),
    // dR03
    electronTrkIso03(mDataTree,mElectronPrefix+"Dr03TkSumPt"+mElectronSuffix,this),
    electronEcalIso03(mDataTree,mElectronPrefix+"Dr03EcalRecHitSumEt"+mElectronSuffix,this),
    electronHcalIso03(mDataTree,mElectronPrefix+"Dr03HcalTowerSumEt"+mElectronSuffix,this),

    electronChargedHadronIso(mDataTree,mElectronPrefix+"ChargedHadronIso"+mElectronSuffix,this),
    electronNeutralHadronIso(mDataTree,mElectronPrefix+"NeutralHadronIso"+mElectronSuffix,this),
    electronPhotonIso(mDataTree,mElectronPrefix+"PhotonIso"+mElectronSuffix,this),
    electronEIDLoose(mDataTree,mElectronPrefix+"EIDLoose"+mElectronSuffix,this),
    electronEIDTight(mDataTree,mElectronPrefix+"EIDTight"+mElectronSuffix,this),
    electronIDLoose(GetElectronIDBranch(mEIDLoose)),
    electronIDTight(GetElectronIDBranch(mEIDTight)),
    electronTrkPt(mDataTree,mElectronPrefix+"GsfTrackPt"+mElectronSuffix,this),
    electronEcalE(mDataTree,mElectronPrefix+"EcalEnergy"+mElectronSuffix,this),
    electronKFCharge( mDataTree,mElectronPrefix+"ClosestCtfTrackCharge"+mElectronSuffix,this),
    electronSCCharge( mDataTree,mElectronPrefix+"ScPixCharge"+mElectronSuffix,this),
    electronESuperClusterEta( mDataTree,mElectronPrefix+"ESuperClusterEta"+mElectronSuffix,this),
    electronMva(mDataTree, mElectronPrefix+"Mva"+mElectronSuffix,this),
    electronEcalEnergy(mDataTree,mElectronPrefix+"EcalEnergy"+mElectronSuffix,this),

    // e EWK Id variables
    electronHoE(mDataTree,mElectronPrefix+"HcalOverEcal"+mElectronSuffix,this),
    electronDeltaPhiAtVtx(mDataTree,mElectronPrefix+"DeltaPhiSuperClusterTrackAtVtx"+mElectronSuffix,this),
    electronDeltaEtaAtVtx(mDataTree,mElectronPrefix+"DeltaEtaSuperClusterTrackAtVtx"+mElectronSuffix,this),
    electronSigmaIetaIeta(mDataTree,mElectronPrefix+"SigmaIetaIeta"+mElectronSuffix,this),
    electronHasValidHitInFirstPixelBarrel(mDataTree,mElectronPrefix+"HasValidHitInFirstPixelBarrel"+mElectronSuffix,this),
    electronESuperClusterOverP(mDataTree,mElectronPrefix+"ESuperClusterOverP"+mElectronSuffix,this),
    electronFbrem(mDataTree,mElectronPrefix+"Fbrem"+mElectronSuffix,this),
    electronGsfTrackDxy(mDataTree,mElectronPrefix+"GsfTrackDxy"+mElectronSuffix,this),
    electronGsfTrackDxyBS(mDataTree,mElectronPrefix+"GsfTrackDxyBS"+mElectronSuffix, this),
    electronGsfTrackVertexz(mDataTree,mElectronPrefix+"GsfTrackVertexz"+mElectronSuffix,this),


    // Electron conversion ID variables1
    electronConversionDCot(mDataTree, mElectronPrefix + "ConversionDCot" + mElectronSuffix, this),
    electronConversionDist(mDataTree, mElectronPrefix + "ConversionDist" + mElectronSuffix, this),
    electronConversionPartnerTrackTrackerExpectedHitsInner(mDataTree,
                                                           mElectronPrefix +
                                                           "ConversionPartnerTrackTrackerExpectedHitsInner" +
                                                           mElectronSuffix, this),
    electronGsfTrackTrackerExpectedHitsInner(mDataTree,
                                             mElectronPrefix + "GsfTrackTrackerExpectedHitsInner" + mElectronSuffix, this),

    // Muons
    muonP4(mDataTree,mMuonPrefix+"P4"+mMuonSuffix,this),
    muonVx(mDataTree,mMuonPrefix+"Vertex"+mMuonSuffix,this),
    muonCharge(mDataTree,mMuonPrefix+"Charge"+mMuonSuffix,this),
    muonTrkIso(mDataTree,mMuonPrefix+"TrackIso"+mMuonSuffix,this),
    muonEcalIso(mDataTree,mMuonPrefix+"EcalIso"+mMuonSuffix,this),
    muonHcalIso(mDataTree,mMuonPrefix+"HcalIso"+mMuonSuffix,this),

    muonTrkIso03(mDataTree,mMuonPrefix+"IsolationR03sumPt"+mMuonSuffix,this),
    muonEcalIso03(mDataTree,mMuonPrefix+"IsolationR03emEt"+mMuonSuffix,this),
    muonHcalIso03(mDataTree,mMuonPrefix+"IsolationR03hadEt"+mMuonSuffix,this),

    muonChargedHadronIso(mDataTree,mMuonPrefix+"ChargedHadronIso"+mMuonSuffix,this),
    muonNeutralHadronIso(mDataTree,mMuonPrefix+"NeutralHadronIso"+mMuonSuffix,this),

    muonPhotonIso(mDataTree,mMuonPrefix+"PhotonIso"+mMuonSuffix,this),

    muonIDTMLastStationAngTight(mDataTree,mMuonPrefix+"TMLastStationAngTight"+mMuonSuffix,this),
    muonIsTrackerMuon(mDataTree,mMuonPrefix+"IsTrackerMuon"+mMuonSuffix,this),
    muonIsGlobalMuon(mDataTree,mMuonPrefix+"IsGlobalMuon"+mMuonSuffix,this),
    muonIDGlobalMuonPromptTight(mDataTree,mMuonPrefix+"IDGlobalMuonPromptTight"+mMuonSuffix,this),
    muonIDLoose(GetMuonIDBranch(mMuonIDLoose)),
    muonIDTight(GetMuonIDBranch(mMuonIDTight)),

    muonVertexChi2(mDataTree,mMuonPrefix+"VertexChi2"+mMuonSuffix,this),
    muonVertexNdof(mDataTree,mMuonPrefix+"VertexNdof"+mMuonSuffix,this),
    muonInnerTrackdxy(mDataTree,mMuonPrefix+"InnerTrackDxy"+mMuonSuffix,this),
    muonInnerTrackdxyError(mDataTree,mMuonPrefix+"InnerTrackDxyError"+mMuonSuffix,this),
    muonInnerTrackdxyBS(mDataTree,mMuonPrefix+"InnerTrackDxyBS"+mMuonSuffix,this),
    muonInnerTrackdz(mDataTree,mMuonPrefix+"InnerTrackDz"+mMuonSuffix,this),
    muonGlobalTrackdxy(mDataTree,mMuonPrefix+"GlobalTrackDxy"+mMuonSuffix,this),
    muonGlobalTrackdxyBS(mDataTree,mMuonPrefix+"GlobalTrackDxyBS"+mMuonSuffix,this),
    muonGlobalTrackdxyError(mDataTree,mMuonPrefix+"GlobalTrackDxyError"+mMuonSuffix,this),
    muonGlobalTrackNormChi2(mDataTree,mMuonPrefix+"GlobalTracknormalizedChi2"+mMuonSuffix,this),
    muonInnerTrackNormChi2(mDataTree,mMuonPrefix+"InnerTrackNormalizedChi2"+mMuonSuffix,this),
    muonGlobalTracknumberOfValidHits(mDataTree,mMuonPrefix+"GlobalTracknumberOfValidHits"+mMuonSuffix,this),
    muonInnerTracknumberOfValidHits(mDataTree,mMuonPrefix+"InnerTrackNumberOfValidHits"+mMuonSuffix,this),
    muonOuterTracknumberOfValidHits(mDataTree,mMuonPrefix+"OuterTrackNumberOfValidHits"+mMuonSuffix,this),
    //Jad: Add num pixel hits and num matches in muon chambers
    muonNumberOfMatches(mDataTree,mMuonPrefix+"NumberOfMatches"+mMuonSuffix,this),
    muonNumberOfValidPixelHits(mDataTree,mMuonPrefix+"NumberOfValidPixelHits"+mMuonSuffix,this),

    // LG: add branches for the latest MuID that run over the latest ntuples only.
    muonInnerTrackP4(mDataTree,mMuonPrefix+"InnerTrackP4"+mMuonSuffix,this),
    muonOuterTrackP4(mDataTree,mMuonPrefix+"OuterTrackP4"+mMuonSuffix,this),
    muonGlobalTrackP4(mDataTree,mMuonPrefix+"GlobalTrackP4"+mMuonSuffix,this),

    muonEcalVetoDep(mDataTree,mMuonPrefix+"EcalVetoDep"+mMuonSuffix,this),
    muonHcalVetoDep(mDataTree,mMuonPrefix+"HcalVetoDep"+mMuonSuffix,this),

    muonGlobalTracknumberOfValidTrackerHits(mDataTree,mMuonPrefix+"GlobalTracknumberOfValidTrackerHits"+mMuonSuffix,this),
    muonNumberOfPixelLayersWithMeasurement(mDataTree,mMuonPrefix+"NumberOfPixelLayersWithMeasurement"+mMuonSuffix,this),
    muonInnerTrackVertexz(mDataTree,mMuonPrefix+"InnerTrackVertexz"+mMuonSuffix,this),
    muonGlobalTrackPTsigma(mDataTree,mMuonPrefix+"SigmaPt"+mMuonSuffix,this),


    //MICHELE ->Secondary Muon Collection
    secMuonP4(mDataTree,mSecMuonPrefix+"P4"+mSecMuonSuffix,this),
    secMuonCharge(mDataTree,mSecMuonPrefix+"Charge"+mSecMuonSuffix,this),
    secMuonTrkIso(mDataTree,mSecMuonPrefix+"TrackIso"+mSecMuonSuffix,this),
    secMuonEcalIso(mDataTree,mSecMuonPrefix+"EcalIso"+mSecMuonSuffix,this),
    secMuonHcalIso(mDataTree,mSecMuonPrefix+"HcalIso"+mSecMuonSuffix,this),

    secMuonTrkIso03(mDataTree,mSecMuonPrefix+"IsolationR03sumPt"+mSecMuonSuffix,this),
    secMuonEcalIso03(mDataTree,mSecMuonPrefix+"IsolationR03emEt"+mSecMuonSuffix,this),
    secMuonHcalIso03(mDataTree,mSecMuonPrefix+"IsolationR03hadEt"+mSecMuonSuffix,this),

    secMuonChargedHadronIso(mDataTree,mSecMuonPrefix+"ChargedHadronIso"+mSecMuonSuffix,this),
    secMuonNeutralHadronIso(mDataTree,mSecMuonPrefix+"NeutralHadronIso"+mSecMuonSuffix,this),

    secMuonPhotonIso(mDataTree,mSecMuonPrefix+"PhotonIso"+mSecMuonSuffix,this),

    secMuonIDTMLastStationAngTight(mDataTree,mSecMuonPrefix+"TMLastStationAngTight"+mSecMuonSuffix,this),
    secMuonIsTrackerMuon(mDataTree,mSecMuonPrefix+"IsTrackerMuon"+mSecMuonSuffix,this),
    secMuonIsGlobalMuon(mDataTree,mSecMuonPrefix+"IsGlobalMuon"+mSecMuonSuffix,this),
    secMuonIDGlobalMuonPromptTight(mDataTree,mSecMuonPrefix+"IDGlobalMuonPromptTight"+mSecMuonSuffix,this),
    secMuonVertexChi2(mDataTree,mSecMuonPrefix+"VertexChi2"+mSecMuonSuffix,this),
    secMuonVertexNdof(mDataTree,mSecMuonPrefix+"VertexNdof"+mSecMuonSuffix,this),
    secMuonInnerTrackdxy(mDataTree,mSecMuonPrefix+"InnerTrackDxy"+mSecMuonSuffix,this),
    secMuonInnerTrackdxyError(mDataTree,mSecMuonPrefix+"InnerTrackDxyError"+mSecMuonSuffix,this),
    secMuonInnerTrackdxyBS(mDataTree,mSecMuonPrefix+"InnerTrackDxyBS"+mSecMuonSuffix,this),
    secMuonInnerTrackdz(mDataTree,mSecMuonPrefix+"InnerTrackDz"+mSecMuonSuffix,this),
    secMuonGlobalTrackdxy(mDataTree,mSecMuonPrefix+"GlobalTrackDxy"+mSecMuonSuffix,this),
    secMuonGlobalTrackdxyError(mDataTree,mSecMuonPrefix+"GlobalTrackdxyError"+mSecMuonSuffix,this),
    secMuonGlobalTrackNormChi2(mDataTree,mSecMuonPrefix+"GlobalTracknormalizedChi2"+mSecMuonSuffix,this),
    secMuonInnerTrackNormChi2(mDataTree,mSecMuonPrefix+"InnerTrackNormalizedChi2"+mSecMuonSuffix,this),
    secMuonGlobalTracknumberOfValidHits(mDataTree,mSecMuonPrefix+"GlobalTracknumberOfValidHits"+mSecMuonSuffix,this),
    secMuonInnerTracknumberOfValidHits(mDataTree,mSecMuonPrefix+"InnerTrackNumberOfValidHits"+mSecMuonSuffix,this),
    secMuonOuterTracknumberOfValidHits(mDataTree,mSecMuonPrefix+"OuterTrackNumberOfValidHits"+mSecMuonSuffix,this),
    secmuonGlobalTrackPTsigma(mDataTree,mSecMuonPrefix+"SigmaPt"+mSecMuonSuffix,this),
    //MICHELE ->Secondary Muon Collection
    // Taus
    tauP4(mDataTree,mTauPrefix+"P4"+mTauSuffix,this),
    tauVx(mDataTree,mTauPrefix+"Vertex"+mTauSuffix,this),
    tauCharge(mDataTree,mTauPrefix+"Charge"+mTauSuffix,this),
    tauIdbyDecay(mDataTree,mTauPrefix+"TauIdByDecay"+mTauSuffix,this),
    tauIdbyLooseIsolation(mDataTree,mTauPrefix+"TauIdByLooseIsolation"+mTauSuffix,this),
    tauIdbyMediumIsolation(mDataTree,mTauPrefix+"TauIdByMediumIsolation"+mTauSuffix,this),
    tauIdbyTightIsolation(mDataTree,mTauPrefix+"TauIdByTightIsolation"+mTauSuffix,this),
    tauIdAgainstElectron(mDataTree,mTauPrefix+"TauIdagainstElectron"+mTauSuffix,this),
    tauIdAgainstMuon(mDataTree,mTauPrefix+"TauIdagainstMuon"+mTauSuffix,this),
    tauTauIdbyTaNC(mDataTree,mTauPrefix+"TauIdbyTaNC"+mTauSuffix,this),
    tauTauIdbyTaNCfrOnePercent(mDataTree,mTauPrefix+"TauIdbyTaNCfrOnePercent"+mTauSuffix,this),
    tauTauIdbyTaNCfrHalfPercent(mDataTree,mTauPrefix+"TauIdbyTaNCfrHalfPercent"+mTauSuffix,this),
    tauTauIdbyTaNCfrQuarterPercent(mDataTree,mTauPrefix+"TauIdbyTaNCfrQuarterPercent"+mTauSuffix,this),
    tauTauIdbyTaNCfrTenthPercent(mDataTree,mTauPrefix+"TauIdbyTaNCfrTenthPercent"+mTauSuffix,this),



    secTauP4(mDataTree,mSecTauPrefix+"P4"+mSecTauSuffix,this),
    secTauVx(mDataTree,mSecTauPrefix+"Vertex"+mSecTauSuffix,this),
    secTauCharge(mDataTree,mSecTauPrefix+"Charge"+mSecTauSuffix,this),
    secTauIdbyDecay(mDataTree,mSecTauPrefix+"TauIdByDecay"+mSecTauSuffix,this),
    secTauIdbyLooseIsolation(mDataTree,mSecTauPrefix+"TauIdByLooseIsolation"+mSecTauSuffix,this),
    secTauIdbyMediumIsolation(mDataTree,mSecTauPrefix+"TauIdByMediumIsolation"+mSecTauSuffix,this),
    secTauIdbyTightIsolation(mDataTree,mSecTauPrefix+"TauIdByTightIsolation"+mSecTauSuffix,this),
    secTauIdAgainstElectron(mDataTree,mSecTauPrefix+"TauIdagainstElectron"+mSecTauSuffix,this),
    secTauIdAgainstMuon(mDataTree,mSecTauPrefix+"TauIdagainstMuon"+mSecTauSuffix,this),
    secTauTauIdbyTaNC(mDataTree,mSecTauPrefix+"TauIdbyTaNC"+mSecTauSuffix,this),
    secTauTauIdbyTaNCfrOnePercent(mDataTree,mSecTauPrefix+"TauIdbyTaNCfrOnePercent"+mSecTauSuffix,this),
    secTauTauIdbyTaNCfrHalfPercent(mDataTree,mSecTauPrefix+"TauIdbyTaNCfrHalfPercent"+mSecTauSuffix,this),
    secTauTauIdbyTaNCfrQuarterPercent(mDataTree,mSecTauPrefix+"TauIdbyTaNCfrQuarterPercent"+mSecTauSuffix,this),
    secTauTauIdbyTaNCfrTenthPercent(mDataTree,mSecTauPrefix+"TauIdbyTaNCfrTenthPercent"+mSecTauSuffix,this),

    //--------------------------------------------
    // Jets
    jetP4(mDataTree,mJetPrefix+"CorrectedP4"+mJetSuffix,this),
    jetCorrFactor(mDataTree,mJetPrefix+"CorrFactor"+mJetSuffix,this),
    jetEtaEtaMoment(mDataTree,mJetPrefix+"Eta2Moment"+mJetSuffix,this),
    jetPhiPhiMoment(mDataTree,mJetPrefix+"Phi2Moment"+mJetSuffix,this),
    jetPFJetIDLoose(mDataTree,mJetPrefix+"PFJetIDloose"+mJetSuffix,this),
    isPFJet( mJetPrefix.find("PF") != std::string::npos ),
    jetFEm(), //@@ Calo only
    jetEMFcharged(), //@@ PF only
    jetEMFneutral(), //@@ PF only
    jetFneutralHad(), //@@ PF only
    jetFchargedHad(), //@@ PF only
    jetNcharged(), //@@ PF only
    jetNneutral(), //@@ PF only
    jetLooseID(), //@@ Calo only
    jetMinimalID(), //@@ Calo only
    jetTightID(), //@@ Calo only
    //    jetEmEnergyFraction(),
    jetJetIDResEMF(), //@@ Calo only
    jetJetIDFHPD(), //@@ Calo only
    jetJetIDFRBX(), //@@ Calo only
    jetJetIDN90Hits(), //@@ Calo only

    //AGB - 28/10/10 <TW date="07/11/2010" />
    secjetP4(mDataTree,mSecJetPrefix+"CorrectedP4"+mSecJetSuffix,this),
    secjetCorrFactor(mDataTree,mSecJetPrefix+"CorrFactor"+mSecJetSuffix,this),
    secjetisPFJet(mSecJetPrefix.find("PF") != std::string::npos),
    secjetFEm(),
    secjetEMFcharged(), //@@ PF only
    secjetEMFneutral(), //@@ PF only
    secjetFneutralHad(), //@@ PF only
    secjetFchargedHad(), //@@ PF only
    secjetNneutral(), //@@ PF only
    secjetNcharged(), //@@ PF only
    secjetLooseID(), //@@ Calo only
    secjetMinimalID(), //@@ Calo only
    secjetTightID(), //@@ Calo only
    secjetJetIDResEMF(), //@@ Calo only
    secjetJetIDFHPD(), //@@ Calo only
    secjetJetIDFRBX(), //@@ Calo only
    secjetJetIDN90Hits(), //@@ Calo only
    secjetTrkCountingHighEffBJetTags(mDataTree,mSecJetPrefix+"TrkCountingHighEffBJetTags"+mSecJetSuffix,this),

    //<TW comment="Tertiary jet collection." date="12/11/2010">
    terjetP4(mDataTree,mTerJetPrefix+"CorrectedP4"+mTerJetSuffix,this),
    terjetCorrFactor(mDataTree,mTerJetPrefix+"CorrFactor"+mTerJetSuffix,this),
    terjetisPFJet(mTerJetPrefix.find("PF") != std::string::npos),
    terjetFEm(),
    terjetEMFcharged(), //@@ PF only
    terjetEMFneutral(), //@@ PF only
    terjetFneutralHad(), //@@ PF only
    terjetFchargedHad(), //@@ PF only
    terjetNneutral(), //@@ PF only
    terjetNcharged(), //@@ PF only
    terjetLooseID(), //@@ Calo only
    terjetMinimalID(), //@@ Calo only
    terjetTightID(), //@@ Calo only
    terjetJetIDResEMF(), //@@ Calo only
    terjetJetIDFHPD(), //@@ Calo only
    terjetJetIDFRBX(), //@@ Calo only
    terjetJetIDN90Hits(), //@@ Calo only
    //</TW>
    //
    // Photons
    photonP4(mDataTree,mPhotonPrefix+"P4"+mPhotonSuffix,this),
    photonEcalRecHitSumEtConeDR04(mDataTree,mPhotonPrefix+"EcalRecHitEtConeDR04"+mPhotonSuffix,this),
    photonHcalDepth1TowSumEtConeDR04(mDataTree,mPhotonPrefix+"HcalDepth1TowSumEtConeDR04"+mPhotonSuffix,this),
    photonHcalDepth2TowSumEtConeDR04(mDataTree,mPhotonPrefix+"HcalDepth2TowSumEtConeDR04"+mPhotonSuffix,this),
    photonTrkSumPtHollowConeDR04(mDataTree,mPhotonPrefix+"TrkSumPtHollowConeDR04"+mPhotonSuffix,this),
    photonHadronicOverEm(mDataTree,mPhotonPrefix+"HadronicOverEm"+mPhotonSuffix,this),
    photonHasPixelSeed(mDataTree,mPhotonPrefix+"HasPixelSeed"+mPhotonSuffix,this),
    photonR9(mDataTree,mPhotonPrefix+"R9"+mPhotonSuffix,this),
    photonSuperClusterEnergy(mDataTree,mPhotonPrefix+"SuperClusterEnergy"+mPhotonSuffix,this),
    photonSigmaIetaIeta(mDataTree,mPhotonPrefix+"SigmaIetaIeta"+mPhotonSuffix,this),
    photonSuperClusterPhiWidth(mDataTree,mPhotonPrefix+"SuperClusterPhiWidth"+mPhotonSuffix,this),
    photonSuperClusterEtaPhiWidth(mDataTree,mPhotonPrefix+"SuperClusterEtaPhiWidth"+mPhotonSuffix,this),
    photonSuperClusterNXtals(mDataTree,mPhotonPrefix+"SuperClusterNXtals"+mPhotonSuffix,this),
    photonPatTrkIso(mDataTree,mPhotonPrefix+"TrkIso"+mPhotonSuffix,this),
    photonPatEcalIso(mDataTree,mPhotonPrefix+"EcalIso"+mPhotonSuffix,this),
    photonPatHcalIso(mDataTree,mPhotonPrefix+"HcalIso"+mPhotonSuffix,this),
    photonPatCaloIso(mDataTree,mPhotonPrefix+"CaloIso"+mPhotonSuffix,this),
    photonPatIDLoose(mDataTree,mPhotonPrefix+"IDLoose"+mPhotonSuffix,this),
    photonPatIDTight(mDataTree,mPhotonPrefix+"IDTight"+mPhotonSuffix,this),
    photonSwissCross(mDataTree,mPhotonPrefix+"SwissCross"+mPhotonSuffix,this),
    photonE2overE9(mDataTree,mPhotonPrefix+"E2overE9"+mPhotonSuffix,this),
    photonSeedTime(mDataTree,mPhotonPrefix+"SeedTime"+mPhotonSuffix,this),
    photonTime2(mDataTree,mPhotonPrefix+"Time2"+mPhotonSuffix,this),
    photonSeedEnergy(mDataTree,mPhotonPrefix+"SeedEnergy"+mPhotonSuffix,this),
    photonEnergy2(mDataTree,mPhotonPrefix+"Energy2"+mPhotonSuffix,this),
    photonE2x2(mDataTree,mPhotonPrefix+"e2x2"+mPhotonSuffix,this),
    photonE3x3(mDataTree,mPhotonPrefix+"e3x3"+mPhotonSuffix,this),
    photonE4x4(mDataTree,mPhotonPrefix+"e4x4"+mPhotonSuffix,this),
    photonE5x5(mDataTree,mPhotonPrefix+"e5x5"+mPhotonSuffix,this),

    // Gen info
    gensignalProcessID(mDataTree, "gensignalProcessID",this),
    genHandleValid(mDataTree,"genHandleValid",this),
    genP4(mDataTree,"genP4",this),
    genStatus(mDataTree,"genStatus",this),
    genHasMother(mDataTree,"genHasMother",this),
    genMotherStored(mDataTree,"genMotherStored",this),
    genMother(mDataTree,"genMother",this),
    genPdgId(mDataTree,"genPdgId",this),
    genJetP4(mDataTree,"gen"+mJetPrefix+"GenJetsP4"+mJetSuffix,this),
    genJetMatchIndex(mDataTree,mJetPrefix+"GenJetMatchIndex"+mJetSuffix,this),
    genMetP4True(mDataTree,"genmetP4True",this),
    genMetP4IC5(mDataTree,"metGenMetP4IC5",this),
    genMetMatchExistsIC5(mDataTree,"metGenMetMatchExistsIC5",this),
    genMetP4AK5(mDataTree,"metGenMetP4AK5",this),
    genMetMatchExistsAK5(mDataTree,"metGenMetMatchExistsAK5",this),
    genMetP4PF(mDataTree,"metGenMetP4PF",this),
    genMetMatchExistsPF(mDataTree,"metGenMetMatchExistsPF",this),
    genMetP4TC(mDataTree,"metGenMetP4TC",this),
    genMetMatchExistsTC(mDataTree,"metGenMetMatchExistsTC",this),
    useGenJets(false),
    //adding the new gen mother branches:
    genMotherIndex(mDataTree,"genMotherIndex",this),
    genMotherPdgId(mDataTree,"genMotherPdgId",this),
    //adding the PDF information branches
    genid1(mDataTree,"genid1",this),
    genid2(mDataTree,"genid2",this),
    genx1(mDataTree,"genx1",this),
    genx2(mDataTree,"genx2",this),
    genpdf1(mDataTree,"genpdf1",this),
    genpdf2(mDataTree,"genpdf2",this),
    genQ(mDataTree,"genQ",this),

    // MET
    metP4ak5(mDataTree,"metP4AK5",this),
    metP4calo(mDataTree,"metP4Calo",this),
    metP4ic5(mDataTree,"metP4IC5",this),
    metP4pf(mDataTree,"metP4PF",this),
    metP4pfTypeI(mDataTree,"metP4TypeIPF",this),
    metP4tc(mDataTree,"metP4TC",this),
    metP4nohfcalo(mDataTree,"metnohfP4Calo",this),
    //   metP4caloTypeI(mDataTree,"metP4AK5TypeI",this),
    metP4caloTypeII(mDataTree,"metP4AK5TypeII",this),

    // SumET
    sumEtPF(mDataTree,"metSumEtPF",this),

    // HLT
    hlt(mDataTree,"triggered",this),
    hlt_prescaled(mDataTree,"prescaled",this),
    hltHandleValid(mDataTree,"hltHandleValid",this),
    // L1T
    l1t(mDataTree,"L1triggered",this),
    l1t_prescaled(mDataTree,"L1prescaled",this),
    l1tHandleValid(mDataTree,"L1HandleValid",this),



    // Dirty Rec Hits
    rechitCaloHandleValidEb(mDataTree, "rechitCaloHandleValidEb", this),
    rechitCaloTimeEb(mDataTree, "rechitCaloTimeEb", this),
    rechitCaloFlagWordEb(mDataTree, "rechitCaloFlagWordEb", this),
    rechitCaloSeverityLevelEb(mDataTree, "rechitCaloSeverityLevelEb", this),
    rechitCaloP4Eb(mDataTree, "rechitCaloP4Eb", this),
    rechitCaloHandleValidEe(mDataTree, "rechitCaloHandleValidEe", this),
    rechitCaloTimeEe(mDataTree, "rechitCaloTimeEe", this),
    rechitCaloFlagWordEe(mDataTree, "rechitCaloFlagWordEe", this),
    rechitCaloSeverityLevelEe(mDataTree, "rechitCaloSeverityLevelEe", this),
    rechitCaloP4Ee(mDataTree, "rechitCaloP4Ee", this),
    rechitCaloSeverityLevelHbhe(mDataTree, "rechitCaloSeverityLevelHbhe", this),
    rechitCaloSeverityLevelHf(mDataTree, "rechitCaloSeverityLevelHf", this),
    rechitCaloP4Hbhe(mDataTree, "rechitCaloP4Hbhe", this),
    rechitCaloP4Hf(mDataTree, "rechitCaloP4Hf", this),

    //DEAD ECAL Towers
    ecalDeadTowerTrigPrimP4(mDataTree,"ecalDeadTowerTrigPrimP4",this),
    ecalDeadTowerNBadXtals(mDataTree,"ecalDeadTowerNBadXtals",this),
    ecalDeadTowerMaxStatus(mDataTree,"ecalDeadTowerMaxStatus",this),

    BeamSpotPosition(mDataTree,"beamSpotPosition",this),

    LD_Electrons(*this),
    LD_Muons(*this),
    //MICHELE ->Secondary Muon Collection
    LD_SecMuons(*this),
    //MICHELE ->Secondary Muon Collection
    LD_Taus(*this),
    LD_SecTaus(*this),
    PD_Photons(*this),
    JD_Jets(*this),
    //AGB - 28/10/10
    JD_SecJets(*this),
    JD_TerJets(*this), //<TW date="13/11/2010" />
    GenParticles(*this),
    MPT(*this),
    AK5MET(*this),
    CaloMET(*this),
    IC5MET(*this),
    PFMET(*this),
    TCMET(*this),
    CaloMETnohf(*this),
    CaloMETtypeII(*this)

{
  std::cout<<"Secondary jet collection: "<<mSecJetPrefix<<"    "<<mSecJetSuffix<<std::endl;
  std::cout<<"Tertiary jet collection: "<<mTerJetPrefix<<"   "<<mTerJetSuffix<<std::endl;

  typedef Event::Element<std::vector<float>*,NtupleData> Floats;
  typedef Event::Element<std::vector<int>*,NtupleData> Ints;

  if ( !isPFJet ) {
    jetFEm = Floats(mDataTree,mJetPrefix+"EmEnergyFraction"+mJetSuffix,this); //@@ Calo only
    jetLooseID = Ints(mDataTree,mJetPrefix+"JetIDloose"+mJetSuffix,this); //@@ Calo only
    jetMinimalID = Ints(mDataTree,mJetPrefix+"JetIDminimal"+mJetSuffix,this); //@@ Calo only
    jetTightID = Ints(mDataTree,mJetPrefix+"JetIDtight"+mJetSuffix,this); //@@ Calo only
    jetJetIDResEMF  = Floats(mDataTree,mJetPrefix+"JetIDResEMF" +mJetSuffix,this); //@@ Calo only
    jetJetIDFHPD    = Floats(mDataTree,mJetPrefix+"JetIDFHPD"   +mJetSuffix,this); //@@ Calo only
    jetJetIDN90Hits = Ints(mDataTree,mJetPrefix+"JetIDN90Hits"  +mJetSuffix,this); //@@ Calo only
    jetJetIDFRBX    = Floats(mDataTree,mJetPrefix+"JetIDFRBX"   +mJetSuffix,this); //@@ Calo only
  } else {
    jetEMFcharged = Floats(mDataTree,mJetPrefix+"FchargedEm"+mJetSuffix,this); //@@ PF
    jetEMFneutral = Floats(mDataTree,mJetPrefix+"FneutralEm"+mJetSuffix,this); //@@ PF
    jetFneutralHad = Floats(mDataTree,mJetPrefix+"FneutralHad"+mJetSuffix,this); //@@ PF
    jetFchargedHad = Floats(mDataTree,mJetPrefix+"FchargedHad"+mJetSuffix,this); //@@ PF
    jetNcharged = Ints(mDataTree,mJetPrefix+"Ncharged"+mJetSuffix,this); //@@ PF
    jetNneutral = Ints(mDataTree,mJetPrefix+"Nneutral"+mJetSuffix,this); //@@ PF
  }

 if ( !secjetisPFJet ) {
    secjetFEm = Floats(mDataTree,mSecJetPrefix+"EmEnergyFraction"+mSecJetSuffix,this); //@@ Calo only
    secjetLooseID = Ints(mDataTree,mSecJetPrefix+"JetIDloose"+mSecJetSuffix,this); //@@ Calo only
    secjetMinimalID = Ints(mDataTree,mSecJetPrefix+"JetIDminimal"+mSecJetSuffix,this); //@@ Calo only
    secjetTightID = Ints(mDataTree,mSecJetPrefix+"JetIDtight"+mSecJetSuffix,this); //@@ Calo only
    secjetJetIDResEMF  = Floats(mDataTree,mSecJetPrefix+"JetIDResEMF" +mSecJetSuffix,this); //@@ Calo only
    secjetJetIDFHPD    = Floats(mDataTree,mSecJetPrefix+"JetIDFHPD"   +mSecJetSuffix,this); //@@ Calo only
    secjetJetIDN90Hits = Ints(mDataTree,mSecJetPrefix+"JetIDN90Hits"  +mSecJetSuffix,this); //@@ Calo only
    secjetJetIDFRBX    = Floats(mDataTree,mSecJetPrefix+"JetIDFRBX"   +mSecJetSuffix,this); //@@ Calo only
  } else {
    secjetEMFcharged = Floats(mDataTree,mSecJetPrefix+"FchargedEm"+mSecJetSuffix,this); //@@ PF
    secjetEMFneutral = Floats(mDataTree,mSecJetPrefix+"FneutralEm"+mSecJetSuffix,this); //@@ PF
    secjetFneutralHad = Floats(mDataTree,mSecJetPrefix+"FneutralHad"+mSecJetSuffix,this); //@@ PF
    secjetFchargedHad = Floats(mDataTree,mSecJetPrefix+"FchargedHad"+mSecJetSuffix,this); //@@ PF
    secjetNcharged = Ints(mDataTree,mSecJetPrefix+"Ncharged"+mSecJetSuffix,this); //@@ PF
    secjetNneutral = Ints(mDataTree,mSecJetPrefix+"Nneutral"+mSecJetSuffix,this); //@@ PF
  }

 if ( !terjetisPFJet ) {
    terjetFEm = Floats(mDataTree,mTerJetPrefix+"EmEnergyFraction"+mTerJetSuffix,this); //@@ Calo only
    terjetLooseID = Ints(mDataTree,mTerJetPrefix+"JetIDloose"+mTerJetSuffix,this); //@@ Calo only
    terjetMinimalID = Ints(mDataTree,mTerJetPrefix+"JetIDminimal"+mTerJetSuffix,this); //@@ Calo only
    terjetTightID = Ints(mDataTree,mTerJetPrefix+"JetIDtight"+mTerJetSuffix,this); //@@ Calo only
    terjetJetIDResEMF  = Floats(mDataTree,mTerJetPrefix+"JetIDResEMF" +mTerJetSuffix,this); //@@ Calo only
    terjetJetIDFHPD    = Floats(mDataTree,mTerJetPrefix+"JetIDFHPD"   +mTerJetSuffix,this); //@@ Calo only
    terjetJetIDN90Hits = Ints(mDataTree,mTerJetPrefix+"JetIDN90Hits"  +mTerJetSuffix,this); //@@ Calo only
    terjetJetIDFRBX    = Floats(mDataTree,mTerJetPrefix+"JetIDFRBX"   +mTerJetSuffix,this); //@@ Calo only
  } else {
    terjetEMFcharged = Floats(mDataTree,mTerJetPrefix+"FchargedEm"+mTerJetSuffix,this); //@@ PF
    terjetEMFneutral = Floats(mDataTree,mTerJetPrefix+"FneutralEm"+mTerJetSuffix,this); //@@ PF
    terjetFneutralHad = Floats(mDataTree,mTerJetPrefix+"FneutralHad"+mTerJetSuffix,this); //@@ PF
    terjetFchargedHad = Floats(mDataTree,mTerJetPrefix+"FchargedHad"+mTerJetSuffix,this); //@@ PF
    terjetNneutral = Ints(mDataTree,mTerJetPrefix+"Nneutral"+mTerJetSuffix,this); //@@ PF
    terjetNcharged = Ints(mDataTree,mTerJetPrefix+"Ncharged"+mTerJetSuffix,this); //@@ PF
  }

 //  tauTauIdbyTaNC = Floats(mDataTree,mTauPrefix+"TauIdbyTaNC"+mTauSuffix,this);

  jetBtagSimpleSV = Floats(mDataTree,mJetPrefix+"SimpleSecondaryVertexBJetTags"+mJetSuffix,this);
// Get B-tagging and flavor information
  jetTrkCountingHighEffBJetTags = Floats(mDataTree,mJetPrefix+"TrkCountingHighEffBJetTags"+mJetSuffix,this);
  jetTrkCountingHighPurBJetTags = Floats(mDataTree,mJetPrefix+"TrkCountingHighPurBJetTags"+mJetSuffix,this);
  jetSimpleSecondaryVertexHighEffBJetTags = Floats(mDataTree,mJetPrefix+"SimpleSecondaryVertexHighEffBJetTags"+mJetSuffix,this);
  jetSimpleSecondaryVertexHighPurBJetTags = Floats(mDataTree,mJetPrefix+"SimpleSecondaryVertexHighPurBJetTags"+mJetSuffix,this);
  jetCombinedSecondaryVertexBJetTags = Floats(mDataTree,mJetPrefix+"CombinedSecondaryVertexBJetTags"+mJetSuffix,this);
  jetCombinedSecondaryVertexMVABJetTags = Floats(mDataTree,mJetPrefix+"CombinedSecondaryVertexMVABJetTags"+mJetSuffix,this);
  jetJetProbabilityBJetTags = Floats(mDataTree,mJetPrefix+"JetProbabilityBJetTags"+mJetSuffix,this);
  jetJetBProbabilityBJetTags = Floats(mDataTree,mJetPrefix+"JetBProbabilityBJetTags"+mJetSuffix,this);
  jetSoftElectronByIP3dBJetTags = Floats(mDataTree,mJetPrefix+"SoftElectronByIP3dBJetTags"+mJetSuffix,this);
  jetSoftElectronByPtBJetTags = Floats(mDataTree,mJetPrefix+"SoftElectronByPtBJetTags"+mJetSuffix,this);
  jetSoftMuonBJetTags = Floats(mDataTree,mJetPrefix+"SoftMuonBJetTags"+mJetSuffix,this);
  jetSoftMuonByIP3dBJetTags = Floats(mDataTree,mJetPrefix+"SoftMuonByIP3dBJetTags"+mJetSuffix,this);
  jetSoftMuonByPtBJetTags = Floats(mDataTree,mJetPrefix+"SoftMuonByPtBJetTags"+mJetSuffix,this);
  jetgenJetFlavour=Ints(mDataTree,mJetPrefix+"genJetFlavour"+mJetSuffix,this);




  if ( Utils::Config::Instance().Contains("Ntuple.Jets.UseGenJets") ) {
    useGenJets = Utils::GetConfig<bool>("Ntuple.Jets.UseGenJets");
  }

}

NtupleData::~NtupleData(){}

Double_t NtupleData::GetStoredEventWeight() const {
  throw std::invalid_argument("Stored weights not available in CAF format ntuples");
}



}

