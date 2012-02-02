#ifndef ICF_NTUPLEDATA_HH
#define ICF_NTUPLEDATA_HH
#include "NtupleData.hh"
#include "ICF_Compute.hh"
#include "EventElement.hh"


#include "Types.hh"
#include <map>

namespace ICF{
  class NtupleData : public Event::NtupleData {
  public:
    NtupleData(const std::string & fileName,
      const std::vector<std::string> & fileList,
      const std::string & dataSetName,
      UInt_t lastEntry,
      UInt_t firstEntry = 0,
      double reWeight = 1.0);
    ~NtupleData();
    Double_t GetStoredEventWeight() const;

  private:
    NtupleData();
  private:
    const std::string mElectronPrefix;
    const std::string mElectronSuffix;
    const std::string mEIDLoose;
    const std::string mEIDTight;
    const std::string mMuonPrefix;
    const std::string mMuonSuffix;
  //MICHELE ->Secondary Muon Collection
    const std::string mSecMuonPrefix;
    const std::string mSecMuonSuffix;
  //MICHELE ->Secondary Muon Collection
    const std::string mMuonIDLoose;
    const std::string mMuonIDTight;
    const std::string mJetPrefix;
    const std::string mJetSuffix;
  //AGB ->Secondary Jet Collection 28/10/10
    const std::string mSecJetPrefix;
    const std::string mSecJetSuffix;
  //<TW comment="tertiary jet collection" date="12/11/2010">
    const std::string mTerJetPrefix;
    const std::string mTerJetSuffix;
  //</TW>
  //
    const std::string mTauPrefix;
    const std::string mTauSuffix;
    const std::string mSecTauPrefix;
    const std::string mSecTauSuffix;
    const std::string mPhotonPrefix;
    const std::string mPhotonSuffix;
  public:

  // Event
    Event::Element<UInt_t, NtupleData> RunNumber;
    Event::Element<UInt_t, NtupleData> EventNumber;
    Event::Element<floatle, NtupleData> pthat;
    Event::Element<UInt_t, NtupleData> LumiSection;
    Event::Element<bool, NtupleData> IsData;

    Event::Element<floatle,NtupleData> SusyCrossSection;
    Event::Element<floatle,NtupleData> M0;
    Event::Element<floatle,NtupleData> M12;
    Event::Element<floatle,NtupleData> Mu;
    Event::Element<bool,NtupleData> SMSvalid;
    Event::Element<floatle,NtupleData> MChi;
    Event::Element<floatle,NtupleData> MG;
    Event::Element<floatle,NtupleData> MLSP;

    Event::Element<floatle,NtupleData> TanBeta;
    Event::Element<floatle,NtupleData> MGluino;
    Event::Element<floatle,NtupleData> MSquark;
    Event::Element<floatle,NtupleData> MChi0;


    Event::Element<bool, NtupleData> RA2TrackingFailureFilter;
    Event::Element<bool, NtupleData> RA2ecaldeadcellfilterflag;

    Event::Element<bool, NtupleData> hbheNoiseFilter;
    Event::Element<bool, NtupleData> beamHaloCSCTightHaloId;
    Event::Element<int, NtupleData> tracksNEtaLT0p9AllTracks;
    Event::Element<int, NtupleData> tracksNEta0p9to1p5AllTracks;
    Event::Element<int, NtupleData> tracksNEtaGT1p5AllTracks;
    Event::Element<int, NtupleData> tracksNEtaLT0p9HighPurityTracks;
    Event::Element<int, NtupleData> tracksNEta0p9to1p5HighPurityTracks;
    Event::Element<int, NtupleData> tracksNEtaGT1p5HighPurityTracks;

    Event::Element<std::vector<floatle>*, NtupleData> vertexNdof;
    Event::Element<std::vector<int>*, NtupleData> vertexIsFake;
    Event::Element<std::vector<floatle>*, NtupleData> vertexSumPt;
    Event::Element<std::vector<ICF_XYZPoint>* , NtupleData> vertexPosition;
    Event::Element<std::vector<int>*, NtupleData> vertexNtrks;

    Event::Element<unsigned, NtupleData> physicsDeclared;

  // Electrons
    Event::Element<ICF_LorentzVs* , NtupleData> electronP4;
    Event::Element<ICF_XYZPoints*  , NtupleData> electronVx;
    Event::Element<std::vector<int>* , NtupleData> electronCharge;
    Event::Element<std::vector<float>* , NtupleData> electronTrkIso;
    Event::Element<std::vector<float>* , NtupleData> electronEcalIso;
    Event::Element<std::vector<float>* , NtupleData> electronHcalIso;
    Event::Element<std::vector<float>* , NtupleData> electronTrkIso03;
    Event::Element<std::vector<float>* , NtupleData> electronEcalIso03;
    Event::Element<std::vector<float>* , NtupleData> electronHcalIso03;
    Event::Element<std::vector<float> * , NtupleData> electronChargedHadronIso;
    Event::Element<std::vector<float> * , NtupleData> electronNeutralHadronIso;
    Event::Element<std::vector<float> * , NtupleData> electronPhotonIso;
    Event::Element<std::vector<float>* , NtupleData> electronEIDLoose;
    Event::Element<std::vector<float>* , NtupleData> electronEIDTight;
    Event::Element<std::vector<float>* , NtupleData>& electronIDLoose;
    Event::Element<std::vector<float>* , NtupleData>& electronIDTight;
    Event::Element<std::vector<float>*, NtupleData> electronTrkPt;
    Event::Element<std::vector<float>*, NtupleData> electronEcalE;
    Event::Element<std::vector<int>* , NtupleData> electronKFCharge;
    Event::Element<std::vector<int>* , NtupleData> electronSCCharge;
    Event::Element<std::vector<float>*, NtupleData> electronESuperClusterEta;
    Event::Element<std::vector<float>*, NtupleData> electronMva;
    Event::Element<std::vector<float>* , NtupleData> electronEcalEnergy;


  // EWK ID variables
    Event::Element<std::vector<float>* , NtupleData> electronHoE;
    Event::Element<std::vector<float>* , NtupleData> electronDeltaPhiAtVtx;
    Event::Element<std::vector<float>* , NtupleData> electronDeltaEtaAtVtx;
    Event::Element<std::vector<float>* , NtupleData> electronSigmaIetaIeta;
    Event::Element<std::vector<int>* , NtupleData> electronHasValidHitInFirstPixelBarrel;
    Event::Element<std::vector<float>* ,  NtupleData> electronESuperClusterOverP;
    Event::Element<std::vector<float>* ,  NtupleData> electronFbrem;
    Event::Element<std::vector<floatle>*, NtupleData> electronGsfTrackDxy;
    Event::Element<std::vector<floatle>*, NtupleData> electronGsfTrackDxyBS;
    Event::Element<std::vector<floatle>*, NtupleData> electronGsfTrackVertexz;

  // Electron conversion ID variables
    Event::Element<std::vector<floatle> * , NtupleData> electronConversionDCot;
    Event::Element<std::vector<floatle> *, NtupleData> electronConversionDist;
    Event::Element<std::vector<int> *, NtupleData> electronConversionPartnerTrackTrackerExpectedHitsInner;
    Event::Element<std::vector<int> *, NtupleData> electronGsfTrackTrackerExpectedHitsInner;

  // Muons
    Event::Element<ICF_LorentzVs*, NtupleData> muonP4;
    Event::Element<ICF_XYZPoints*  , NtupleData> muonVx;
    Event::Element<std::vector<int>* , NtupleData> muonCharge;
    Event::Element<std::vector<float>* , NtupleData> muonTrkIso;
    Event::Element<std::vector<float>* , NtupleData> muonEcalIso;
    Event::Element<std::vector<float>* , NtupleData> muonHcalIso;
    Event::Element<std::vector<float>* , NtupleData> muonTrkIso03;
    Event::Element<std::vector<float>* , NtupleData> muonEcalIso03;
    Event::Element<std::vector<float>* , NtupleData> muonHcalIso03;
    Event::Element<std::vector<float> * , NtupleData> muonChargedHadronIso;
    Event::Element<std::vector<float> * , NtupleData> muonNeutralHadronIso;
    Event::Element<std::vector<float> * , NtupleData> muonPhotonIso;
    Event::Element<std::vector<int>* , NtupleData> muonIDTMLastStationAngTight;
    Event::Element<std::vector<int>* , NtupleData> muonIDTMOneStationLoose;
    Event::Element<std::vector<int>* , NtupleData> muonIsTrackerMuon;
    Event::Element<std::vector<int>* , NtupleData> muonIsGlobalMuon;
    Event::Element<std::vector<int>* , NtupleData> muonIDGlobalMuonPromptTight;
    Event::Element<std::vector<int>* , NtupleData> & muonIDLoose;
    Event::Element<std::vector<int>* , NtupleData> & muonIDTight;
    Event::Element<std::vector<floatle>* , NtupleData> muonVertexChi2;
    Event::Element<std::vector<floatle>* , NtupleData> muonVertexNdof;
    Event::Element<std::vector<floatle>* , NtupleData> muonInnerTrackdxy;
    Event::Element<std::vector<floatle>* , NtupleData> muonInnerTrackdxyError;
    Event::Element<std::vector<floatle>* , NtupleData> muonInnerTrackdxyBS;
    Event::Element<std::vector<floatle>* , NtupleData> muonInnerTrackdz;
    Event::Element<std::vector<floatle>* , NtupleData> muonGlobalTrackdxy;
    Event::Element<std::vector<floatle>* , NtupleData> muonGlobalTrackdxyBS;
    Event::Element<std::vector<floatle>* , NtupleData> muonGlobalTrackdxyError;
    Event::Element<std::vector<floatle>* , NtupleData> muonGlobalTrackNormChi2;
    Event::Element<std::vector<floatle>* , NtupleData> muonInnerTrackNormChi2;
    Event::Element<std::vector<unsigned>* , NtupleData> muonGlobalTracknumberOfValidHits;
    Event::Element<std::vector<unsigned>* , NtupleData> muonInnerTracknumberOfValidHits;
    Event::Element<std::vector<unsigned>* , NtupleData> muonOuterTracknumberOfValidHits;
  //Jad: Add num pixel hits and num matches in muon chambers
    Event::Element<std::vector<unsigned>* , NtupleData> muonNumberOfMatches;
    Event::Element<std::vector<unsigned>* , NtupleData> muonNumberOfValidPixelHits;
    Event::Element<std::vector<float> * , NtupleData> muonEcalVetoDep;
    Event::Element<std::vector<float> * , NtupleData> muonHcalVetoDep;

    // LG: latest definition of MuID doesn't run on all ntuples
    Event::Element<ICF_LorentzVs*, NtupleData> muonInnerTrackP4;
    Event::Element<ICF_LorentzVs*, NtupleData> muonOuterTrackP4;
    Event::Element<ICF_LorentzVs*, NtupleData> muonGlobalTrackP4;

    Event::Element<std::vector<unsigned>* , NtupleData> muonGlobalTracknumberOfValidTrackerHits;
    Event::Element<std::vector<unsigned>* , NtupleData> muonNumberOfPixelLayersWithMeasurement;
    Event::Element<std::vector<floatle>* , NtupleData> muonInnerTrackVertexz;
    Event::Element<std::vector<float>* , NtupleData> muonGlobalTrackPTsigma;


  //MICHELE ->Secondary Muon Collection
    Event::Element<ICF_LorentzVs*, NtupleData> secMuonP4;
    Event::Element<std::vector<int>* , NtupleData> secMuonCharge;
    Event::Element<std::vector<float>* , NtupleData> secMuonTrkIso;
    Event::Element<std::vector<float>* , NtupleData> secMuonEcalIso;
    Event::Element<std::vector<float>* , NtupleData> secMuonHcalIso;
    Event::Element<std::vector<float>* , NtupleData> secMuonTrkIso03;
    Event::Element<std::vector<float>* , NtupleData> secMuonEcalIso03;
    Event::Element<std::vector<float>* , NtupleData> secMuonHcalIso03;
    Event::Element<std::vector<float> * , NtupleData> secMuonChargedHadronIso;
    Event::Element<std::vector<float> * , NtupleData> secMuonNeutralHadronIso;
    Event::Element<std::vector<float> * , NtupleData> secMuonPhotonIso;
    Event::Element<std::vector<int>* , NtupleData> secMuonIDTMLastStationAngTight;
    Event::Element<std::vector<int>* , NtupleData> secMuonIDTMOneStationLoose;
    Event::Element<std::vector<int>* , NtupleData> secMuonIsTrackerMuon;
    Event::Element<std::vector<int>* , NtupleData> secMuonIsGlobalMuon;
    Event::Element<std::vector<int>* , NtupleData> secMuonIDGlobalMuonPromptTight;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonVertexChi2;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonVertexNdof;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonInnerTrackdxy;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonInnerTrackdxyError;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonInnerTrackdxyBS;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonInnerTrackdz;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonGlobalTrackdxy;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonGlobalTrackdxyError;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonGlobalTrackNormChi2;
    Event::Element<std::vector<floatle>* , NtupleData> secMuonInnerTrackNormChi2;
    Event::Element<std::vector<unsigned>* , NtupleData> secMuonGlobalTracknumberOfValidHits;
    Event::Element<std::vector<unsigned>* , NtupleData> secMuonInnerTracknumberOfValidHits;
    Event::Element<std::vector<unsigned>* , NtupleData> secMuonOuterTracknumberOfValidHits;
    Event::Element<std::vector<double>* , NtupleData> secmuonGlobalTrackPTsigma;
  //MICHELE ->Secondary Muon Collection

  // Taus
    Event::Element<ICF_LorentzVs* , NtupleData> tauP4;
    Event::Element<ICF_XYZPoints*  , NtupleData> tauVx;
    Event::Element<std::vector<int>* , NtupleData> tauCharge;
 //    Event::Element<std::vector<floatle>* , NtupleData> tauTrkIso;
//     Event::Element<std::vector<floatle>* , NtupleData> tauEcalIso;
//     Event::Element<std::vector<floatle>* , NtupleData> tauHcalIso;


    Event::Element<std::vector<int>* , NtupleData> tauIdbyDecay;
    Event::Element<std::vector<int>* , NtupleData> tauIdbyLooseIsolation;
    Event::Element<std::vector<int>* , NtupleData> tauIdbyMediumIsolation;
    Event::Element<std::vector<int>* , NtupleData> tauIdbyTightIsolation;
    Event::Element<std::vector<int>* , NtupleData> tauIdAgainstElectron;
    Event::Element<std::vector<int>* , NtupleData> tauIdAgainstMuon;
    Event::Element<std::vector<float>* , NtupleData> tauTauIdbyTaNC;
    Event::Element<std::vector<int>* , NtupleData> tauTauIdbyTaNCfrOnePercent;
    Event::Element<std::vector<int>* , NtupleData> tauTauIdbyTaNCfrHalfPercent;
    Event::Element<std::vector<int>* , NtupleData> tauTauIdbyTaNCfrQuarterPercent;
    Event::Element<std::vector<int>* , NtupleData> tauTauIdbyTaNCfrTenthPercent;

    Event::Element<ICF_LorentzVs* , NtupleData> secTauP4;
    Event::Element<ICF_XYZPoints*  , NtupleData> secTauVx;
    Event::Element<std::vector<int>* , NtupleData> secTauCharge;
    Event::Element<std::vector<int>* , NtupleData> secTauIdbyDecay;
    Event::Element<std::vector<int>* , NtupleData> secTauIdbyLooseIsolation;
    Event::Element<std::vector<int>* , NtupleData> secTauIdbyMediumIsolation;
    Event::Element<std::vector<int>* , NtupleData> secTauIdbyTightIsolation;
    Event::Element<std::vector<int>* , NtupleData> secTauIdAgainstElectron;
    Event::Element<std::vector<int>* , NtupleData> secTauIdAgainstMuon;
    Event::Element<std::vector<float>* , NtupleData> secTauTauIdbyTaNC;
    Event::Element<std::vector<int>* , NtupleData> secTauTauIdbyTaNCfrOnePercent;
    Event::Element<std::vector<int>* , NtupleData> secTauTauIdbyTaNCfrHalfPercent;
    Event::Element<std::vector<int>* , NtupleData> secTauTauIdbyTaNCfrQuarterPercent;
    Event::Element<std::vector<int>* , NtupleData> secTauTauIdbyTaNCfrTenthPercent;



  // Jets
    Event::Element<ICF_LorentzVs* , NtupleData> jetP4;
    Event::Element<std::vector<floatle>* , NtupleData> jetCorrFactor;
    Event::Element<std::vector<float>* ,  NtupleData> jetEtaEtaMoment;
    Event::Element<std::vector<float>* ,  NtupleData> jetPhiPhiMoment;
    bool isPFJet;
    Event::Element<std::vector<float>* , NtupleData> jetFEm;
    Event::Element<std::vector<float>* , NtupleData> jetEMFcharged;
    Event::Element<std::vector<float>* , NtupleData> jetEMFneutral;
    Event::Element<std::vector<float>* , NtupleData> jetFneutralHad;
    Event::Element<std::vector<float>* , NtupleData> jetFchargedHad;
    Event::Element<std::vector<int>* , NtupleData> jetNcharged;
    Event::Element<std::vector<int>* , NtupleData> jetNneutral;
    Event::Element<std::vector<int>*,NtupleData> jetLooseID;
    Event::Element<std::vector<int>*,NtupleData> jetMinimalID;
    Event::Element<std::vector<int>*,NtupleData> jetTightID;
    Event::Element<std::vector<float>* , NtupleData> jetJetIDResEMF; //!< Restricted EM fraction.
    Event::Element<std::vector<float>* , NtupleData> jetJetIDFHPD;
    Event::Element<std::vector<float>* , NtupleData> jetJetIDFRBX;
    Event::Element<std::vector<int>* , NtupleData> jetJetIDN90Hits;
    Event::Element<std::vector<float>* , NtupleData> jetBtagSimpleSV;
    Event::Element<std::vector<int>* , NtupleData> jetPFJetIDLoose;

    Event::Element<std::vector<float>* , NtupleData> jetTrkCountingHighEffBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetTrkCountingHighPurBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSimpleSecondaryVertexHighEffBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSimpleSecondaryVertexHighPurBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetCombinedSecondaryVertexBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetCombinedSecondaryVertexMVABJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetJetProbabilityBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetJetBProbabilityBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSoftElectronByIP3dBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSoftElectronByPtBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSoftMuonBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSoftMuonByIP3dBJetTags;
    Event::Element<std::vector<float>* , NtupleData> jetSoftMuonByPtBJetTags;
    Event::Element<std::vector<int>* , NtupleData> jetgenJetFlavour;

  //AGB 28/10/10 Sec Jet Collection
    Event::Element<ICF_LorentzVs*, NtupleData> secjetP4;
    Event::Element<std::vector<floatle>*, NtupleData> secjetCorrFactor; //<TW date="07/11/2010" />
    bool secjetisPFJet;
    Event::Element<std::vector<float>*, NtupleData> secjetFEm;
    Event::Element<std::vector<float>*, NtupleData> secjetEMFcharged;
    Event::Element<std::vector<float>*, NtupleData> secjetEMFneutral;
    Event::Element<std::vector<float>*, NtupleData> secjetFneutralHad;
    Event::Element<std::vector<float>*, NtupleData> secjetFchargedHad;
    Event::Element<std::vector<int>*, NtupleData> secjetNneutral;
    Event::Element<std::vector<int>*, NtupleData> secjetNcharged;
    Event::Element<std::vector<int>*, NtupleData> secjetLooseID;
    Event::Element<std::vector<int>*, NtupleData> secjetMinimalID;
    Event::Element<std::vector<int>*, NtupleData> secjetTightID;
    Event::Element<std::vector<float>* , NtupleData> secjetJetIDResEMF; //!< Restricted EM fraction.
    Event::Element<std::vector<float>* , NtupleData> secjetJetIDFHPD;
    Event::Element<std::vector<float>* , NtupleData> secjetJetIDFRBX;
    Event::Element<std::vector<int>* , NtupleData> secjetJetIDN90Hits;
    Event::Element<std::vector<float>*, NtupleData> secjetTrkCountingHighEffBJetTags;
  //<TW comment="Tertiary jet collection" date="12/11/2010">
    Event::Element<ICF_LorentzVs*, NtupleData> terjetP4;
    Event::Element<std::vector<floatle>*, NtupleData> terjetCorrFactor;
    bool terjetisPFJet;
    Event::Element<std::vector<float>*, NtupleData> terjetFEm;
    Event::Element<std::vector<float>*, NtupleData> terjetEMFcharged;
    Event::Element<std::vector<float>*, NtupleData> terjetEMFneutral;
    Event::Element<std::vector<float>*, NtupleData> terjetFneutralHad;
    Event::Element<std::vector<float>*, NtupleData> terjetFchargedHad;
    Event::Element<std::vector<int>*, NtupleData> terjetNneutral;
    Event::Element<std::vector<int>*, NtupleData> terjetNcharged;
    Event::Element<std::vector<int>*, NtupleData> terjetLooseID;
    Event::Element<std::vector<int>*, NtupleData> terjetMinimalID;
    Event::Element<std::vector<int>*, NtupleData> terjetTightID;
    Event::Element<std::vector<float>* , NtupleData> terjetJetIDResEMF; //!< Restricted EM fraction.
    Event::Element<std::vector<float>* , NtupleData> terjetJetIDFHPD;
    Event::Element<std::vector<float>* , NtupleData> terjetJetIDFRBX;
    Event::Element<std::vector<int>* , NtupleData> terjetJetIDN90Hits;
    Event::Element<std::vector<float>*, NtupleData> terjetTrkCountingHighEffBJetTags;
  //</TW>

  // Photons
    Event::Element<ICF_LorentzVs* , NtupleData> photonP4;
    Event::Element<std::vector<float>*,NtupleData> photonEcalRecHitSumEtConeDR04;
    Event::Element<std::vector<float>*,NtupleData> photonHcalDepth1TowSumEtConeDR04;
    Event::Element<std::vector<float>*,NtupleData> photonHcalDepth2TowSumEtConeDR04;
    Event::Element<std::vector<float>*,NtupleData> photonTrkSumPtHollowConeDR04;
    Event::Element<std::vector<float>*,NtupleData> photonHadronicOverEm;
    Event::Element<std::vector<float>*,NtupleData> photonHasPixelSeed;
    Event::Element<std::vector<float>*,NtupleData> photonR9;
    Event::Element<std::vector<floatle>*,NtupleData> photonSuperClusterEnergy;
    Event::Element<std::vector<float>*,NtupleData> photonSigmaIetaIeta;
    Event::Element<std::vector<floatle>*,NtupleData> photonSuperClusterPhiWidth;
    Event::Element<std::vector<floatle>*,NtupleData> photonSuperClusterEtaPhiWidth;
    Event::Element<std::vector<int>*,NtupleData> photonSuperClusterNXtals;
    Event::Element<std::vector<float>*,NtupleData> photonPatTrkIso;
    Event::Element<std::vector<float>*,NtupleData> photonPatEcalIso;
    Event::Element<std::vector<float>*,NtupleData> photonPatHcalIso;
    Event::Element<std::vector<float>*,NtupleData> photonPatCaloIso;
    Event::Element<std::vector<int>*,NtupleData> photonPatIDLoose;
    Event::Element<std::vector<int>*,NtupleData> photonPatIDTight;
    Event::Element<std::vector<float>*,NtupleData> photonSwissCross;
    Event::Element<std::vector<float>*,NtupleData> photonE2overE9;
    Event::Element<std::vector<float>*,NtupleData> photonSeedTime;
    Event::Element<std::vector<float>*,NtupleData> photonTime2;
    Event::Element<std::vector<float>*,NtupleData> photonSeedEnergy;
    Event::Element<std::vector<float>*,NtupleData> photonEnergy2;
    Event::Element<std::vector<float>*,NtupleData> photonE2x2;
    Event::Element<std::vector<float>*,NtupleData> photonE3x3;
    Event::Element<std::vector<float>*,NtupleData> photonE4x4;
    Event::Element<std::vector<float>*,NtupleData> photonE5x5;

  // Gen Info
    Event::Element<int, NtupleData> gensignalProcessID;
    Event::Element<bool, NtupleData> genHandleValid;
    Event::Element<ICF_LorentzVs* , NtupleData> genP4;
    Event::Element<std::vector<int>* , NtupleData> genStatus;
    Event::Element<std::vector<int>* , NtupleData> genHasMother;
    Event::Element<std::vector<int>* , NtupleData> genMotherStored;
    Event::Element<std::vector<int>* , NtupleData> genMother;
    Event::Element<std::vector<int>* , NtupleData> genPdgId;
    Event::Element<ICF_LorentzVs*,NtupleData> genJetP4;
    Event::Element<std::vector<int>*,NtupleData> genJetMatchIndex;
    Event::Element<ICF_LorentzV*, NtupleData>  genMetP4True;
    Event::Element<ICF_LorentzV*, NtupleData>  genMetP4IC5;
    Event::Element<std::vector<int>*,NtupleData> genMetMatchExistsIC5;
    Event::Element<ICF_LorentzV*, NtupleData>  genMetP4AK5;
    Event::Element<std::vector<int>*,NtupleData> genMetMatchExistsAK5;
    Event::Element<ICF_LorentzV*, NtupleData>  genMetP4PF;
    Event::Element<std::vector<int>*,NtupleData> genMetMatchExistsPF;
    Event::Element<ICF_LorentzV*, NtupleData>  genMetP4TC;
    Event::Element<std::vector<int>*,NtupleData> genMetMatchExistsTC;
    bool useGenJets;
  //JM add new gen mother branches
    Event::Element<std::vector<int>* , NtupleData> genMotherIndex;
    Event::Element<std::vector<int>* , NtupleData> genMotherPdgId;
  //JM add information on the PDFs
    Event::Element<int , NtupleData> genid1;
    Event::Element<int , NtupleData> genid2;
    Event::Element<floatle , NtupleData> genx1;
    Event::Element<floatle , NtupleData> genx2;
    Event::Element<floatle , NtupleData> genpdf1;
    Event::Element<floatle , NtupleData> genpdf2;
    Event::Element<float , NtupleData> genQ;

  // MET
    Event::Element<ICF_LorentzV*, NtupleData>  metP4ak5;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4calo;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4ic5;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4pf;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4pfTypeI;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4tc;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4nohfcalo;
  // Event::Element<ICF_LorentzV*, NtupleData>  metP4caloTypeI;
    Event::Element<ICF_LorentzV*, NtupleData>  metP4caloTypeII;

  // SumET
    Event::Element<float, NtupleData>  sumEtPF;

  // HLT
    Event::Element<std::map<std::string,bool>* ,NtupleData> hlt;
    Event::Element<std::map<std::string,int>* ,NtupleData> hlt_prescaled;
    Event::Element<bool,NtupleData> hltHandleValid;

    // L1T
    Event::Element<std::map<std::string,bool>* , NtupleData> l1t;
    Event::Element<std::map<std::string,int>* ,NtupleData> l1t_prescaled;
    Event::Element<bool,NtupleData> l1tHandleValid;



  // Dirty Rec Hits
    Event::Element<bool ,NtupleData> rechitCaloHandleValidEb;
    Event::Element<std::vector<float>* ,NtupleData> rechitCaloTimeEb;
    Event::Element<std::vector<unsigned>* ,NtupleData> rechitCaloFlagWordEb;
    Event::Element<std::vector<int>* ,NtupleData> rechitCaloSeverityLevelEb;
    Event::Element<std::vector<PolarLorentzV>* ,NtupleData> rechitCaloP4Eb;
    Event::Element<bool ,NtupleData> rechitCaloHandleValidEe;
    Event::Element<std::vector<float>* ,NtupleData> rechitCaloTimeEe;
    Event::Element<std::vector<unsigned>* ,NtupleData> rechitCaloFlagWordEe;
    Event::Element<std::vector<int>* ,NtupleData> rechitCaloSeverityLevelEe;
    Event::Element<std::vector<PolarLorentzV>* ,NtupleData> rechitCaloP4Ee;


    Event::Element<std::vector<int>* ,NtupleData> rechitCaloSeverityLevelHbhe;
    Event::Element<std::vector<int>* ,NtupleData> rechitCaloSeverityLevelHf;
    Event::Element<std::vector<PolarLorentzV>* ,NtupleData> rechitCaloP4Hbhe;
    Event::Element<std::vector<PolarLorentzV>* ,NtupleData> rechitCaloP4Hf;


    Event::Element<std::vector<PolarLorentzV>*, NtupleData> ecalDeadTowerTrigPrimP4;
    Event::Element<std::vector<unsigned>*,NtupleData> ecalDeadTowerNBadXtals;
    Event::Element<std::vector<unsigned>*,NtupleData> ecalDeadTowerMaxStatus;

  // Beam spot position
    Event::Element<ICF_XYZPoint*,NtupleData> BeamSpotPosition;

  private:
    Event::Element<std::vector<int>* , NtupleData>&
      GetMuonIDBranch(const std::string & id);
    Event::Element<std::vector<float>* , NtupleData>&
      GetElectronIDBranch(const std::string & id);

  public:
  //Methods for accessing event details
    UInt_t GetRunNumber() const { return RunNumber();}
    UInt_t GetLumiSec() const { return LumiSection();}
    UInt_t GetEventNumber() const { return EventNumber();}
    bool GetIsData() const { return IsData();}
  // Accessor methods. Please add here to use quantities not encapsulated
  // by a physics object class (e.g. Lepton, Jet etc.)
    ICF_XYZPoint GetBeamSpotPosition() const { return *BeamSpotPosition();}
    Double_t GetMuonGlobalTrackdxy(int index) const { return muonGlobalTrackdxy()->at(index); }
    Double_t GetMuonGlobalTrackdxyBS(int index) const { return muonGlobalTrackdxyBS()->at(index); }
    Double_t GetMuonGlobalTrackdxyError(int index) const { return muonGlobalTrackdxyError()->at(index); }
    Double_t GetMuonGlobalTrackNormChi2(int index) const { return muonGlobalTrackNormChi2()->at(index); }
    Double_t GetMuonInnerTrackNormChi2(int index) const { return muonInnerTrackNormChi2()->at(index); }
    UInt_t GetMuonGlobalTracknumberOfValidHits(int index) const { return muonGlobalTracknumberOfValidHits()->at(index); }
    UInt_t GetMuonInnerTracknumberOfValidHits(int index) const { return muonInnerTracknumberOfValidHits()->at(index);}
    UInt_t GetMuonOuterTracknumberOfValidHits(int index) const {return muonOuterTracknumberOfValidHits()->at(index);}


    Double_t GetElectronD0(int index) const {return - electronGsfTrackDxy()->at(index); }
    Double_t GetElectronD0BS(int index) const {return - electronGsfTrackDxyBS() -> at(index);}
    Double_t GetMuonCombD0(int index) const {return muonGlobalTrackdxy()->at(index)*-1.; }
    ICF_XYZPoint GetElectronVx(int index) const {return electronVx() -> at(index);}

    Double_t GetSusyCrossSection() const{return SusyCrossSection();}
    Double_t GetM0() const{return M0();}
    Double_t GetMG() const{return MG();}
    Double_t GetMLSP() const { return MLSP(); }
    Double_t GetM12() const { return M12(); }
    Double_t GetMu() const{return Mu();}
    Double_t GetMChi() const{ return MChi();}
    Double_t GetTanBeta() const{return TanBeta();}
    int GetgensignalProcessID() const{return gensignalProcessID();}


    bool GetRA2TrackingFailureFilter() const{return RA2TrackingFailureFilter();}
    bool GetRA2ecaldeadcellfilterflag() const{return RA2ecaldeadcellfilterflag();}
    bool GethbheNoiseFilterResult() const{return hbheNoiseFilter();}
    bool GethbeamHaloCSCTightHaloIdResult() const{return beamHaloCSCTightHaloId();}

    unsigned GettracksNEtaLT0p9AllTracks()            const{return tracksNEtaLT0p9AllTracks(); }
    unsigned GettracksNEta0p9to1p5AllTracks()         const{return tracksNEta0p9to1p5AllTracks();}
    unsigned GettracksNEtaGT1p5AllTracks()            const{return tracksNEtaGT1p5AllTracks(); }
    unsigned GettracksNEtaLT0p9HighPurityTracks()     const{return tracksNEtaLT0p9HighPurityTracks();}
    unsigned GettracksNEta0p9to1p5HighPurityTracks()  const{return tracksNEta0p9to1p5HighPurityTracks();}
    unsigned GettracksNEtaGT1p5HighPurityTracks()     const{return tracksNEtaGT1p5HighPurityTracks();}


    Double_t GetvertexNdof(int index) const{ return vertexNdof()->at(index);}
    Int_t GetvertexIsFake(int index) const { return vertexIsFake()->at(index);}
    ICF_XYZPoint GetvertexPosition(int index) const {return vertexPosition()->at(index);}
    Int_t GetVertexSize() const { return vertexPosition()->size();}
    Int_t GetvertexNtrks(int index) const {return vertexNtrks()->at(index);}
    unsigned GetphysicsDeclared() const {return physicsDeclared();}

    bool GetMuonTMLastStationAngTight(int index) const {return  muonIDTMLastStationAngTight()->at(index);}
    bool IsMuonGlobal(int index) const {return muonIsGlobalMuon()->at(index);}
    bool IsMuonTracker(int index) const {return muonIsTrackerMuon()->at(index);}
    bool IsGlobalMuonPromptTight(int index) const {return muonIDGlobalMuonPromptTight()->at(index);}
    Double_t GetMuonInnerTrackDxy(int index) const {return muonInnerTrackdxy()->at(index);}
    Double_t GetMuonInnerTrackDxyError(int index) const {return muonInnerTrackdxyError()->at(index);}
    Double_t GetMuonInnerTrackDxyBS(int index) const {return muonInnerTrackdxyBS()->at(index);}
    Double_t GetMuonInnerTrackDz(int index) const {return muonInnerTrackdz()->at(index);}
    ICF_XYZPoint GetMuonVx(int index) const {return muonVx() -> at(index);}

    // LG :
    ICF_LorentzV GetMuonInnerTrackP4(int index) const { return muonInnerTrackP4()->at(index); }
    ICF_LorentzV GetMuonOuterTrackP4(int index) const { return muonOuterTrackP4()->at(index); }
    ICF_LorentzV GetMuonGlobalTrackP4(int index) const { return muonGlobalTrackP4()->at(index); }
    Float_t GetMuonEcalVetoDep(int index) const {return  muonEcalVetoDep()->at(index);}
    Float_t GetMuonHcalVetoDep(int index) const {return  muonHcalVetoDep()->at(index);}


    Float_t GetMuonChHadIso(int index) const {return  muonChargedHadronIso()->at(index);}
    Float_t GetMuonNeuHadIso(int index) const {return  muonNeutralHadronIso()->at(index);}
    Float_t GetMuonPhotonIso(int index) const {return  muonPhotonIso()->at(index);}

    Float_t GetMuonTrkIso03(int index)const {return  muonTrkIso03()->at(index);}
    Float_t GetMuonEcalIso03(int index)const {return  muonEcalIso03()->at(index);}
    Float_t GetMuonHcalIso03(int index)const {return  muonHcalIso03()->at(index);}

    Float_t GetElectronTrkIso03(int index) const {return electronTrkIso03()->at(index);}
    Float_t GetElectronEcalIso03(int index) const {return electronEcalIso03()->at(index);}
    Float_t GetElectronHcalIso03(int index) const {return electronHcalIso03()->at(index);}

    Double_t GetElectronHoE(int index) const {return electronHoE()->at(index); }
    Double_t GetElectronDeltaPhiAtVtx(int index) const {return electronDeltaPhiAtVtx()->at(index); }
    Double_t GetElectronDeltaEtaAtVtx(int index) const {return electronDeltaEtaAtVtx()->at(index); }
    Double_t GetElectronSigmaIetaIeta(int index) const {return electronSigmaIetaIeta()->at(index); }
    Double_t GetElectronESuperClusterOverP(int index) const {return electronESuperClusterOverP()->at(index); }
    Double_t GetElectronTrkPt(int index) const {return electronTrkPt()->at(index);}
    Double_t GetElectronFbrem(int index) const {return electronFbrem()->at(index); }
    Int_t GetElectronHasValidHitInFirstPixelBarrel(int index) const {return electronHasValidHitInFirstPixelBarrel()->at(index); }

    Int_t GetElectronKFCharge(int index) const {return electronKFCharge()->at(index);}
    Int_t GetElectronSCCharge(int index) const {return electronSCCharge()->at(index);}

    Double_t GetElectronESuperClusterEta(int index) const {return electronESuperClusterEta()->at(index);}

    Double_t GetElectronEcalEnergy(int index) const {return electronEcalE()->at(index);}

    Double_t GetElectronDCot(int index) const { return electronConversionDCot()->at(index);}
    Double_t GetElectronDist(int index) const { return electronConversionDist()->at(index);}
    Int_t GetElectronPartnerTrackTrackerExpectedHitsInner(int index) const {
      return electronConversionPartnerTrackTrackerExpectedHitsInner()->at(index);
    }

    Int_t GetElectronGsfTrackTrackerExpectedHitsInner(int index) const{
      return electronGsfTrackTrackerExpectedHitsInner()->at(index);
    }

    float GetElectronMva(int index) const {return electronMva()->at(index); }
    Float_t GetElectronChHadIso(int index) const {return  electronChargedHadronIso()->at(index);}
    Float_t GetElectronNeuHadIso(int index) const {return  electronNeutralHadronIso()->at(index);}
    Float_t GetElectronPhotonIso(int index) const {return  electronPhotonIso()->at(index);}

  //   Tau ID by Tau Neural Classifier

    bool IsTauByDecay(int index) const {return tauIdbyDecay()->at(index);}
    bool IsTauByLooseIso(int index) const {return tauIdbyLooseIsolation()->at(index);}
    bool IsTauByMediumIso(int index) const {return tauIdbyMediumIsolation()->at(index);}
    bool IsTauByTightIso(int index) const {return tauIdbyTightIsolation()->at(index);}
    bool IsTauAgainstElectron(int index) const {return tauIdAgainstElectron()->at(index);}
    bool IsTauAgainstMuon(int index) const {return tauIdAgainstMuon()->at(index);}
    float GetTauIdbyTaNC(int index) const {return tauTauIdbyTaNC()->at(index);}         // discriminant variable
    ICF_XYZPoint GetTauVx(int index) const {return tauVx() -> at(index);}
    bool IsTauNCfr100(int index) const {return tauTauIdbyTaNCfrOnePercent()->at(index);}     //   fake rate = 1%
    bool IsTauNCfr050(int index) const {return tauTauIdbyTaNCfrHalfPercent()->at(index);}      //  fake rate = 0.5%
    bool IsTauNCfr025(int index) const {return tauTauIdbyTaNCfrQuarterPercent()->at(index);}   //  fake rate = 0.25%
    bool IsTauNCfr010(int index) const {return tauTauIdbyTaNCfrTenthPercent()->at(index);}   //  fake rate = 0.10%


    Float_t GetBtagTrkCount(int index) const {return jetTrkCountingHighEffBJetTags()->at(index);}
//  Float_t GetBtagSimpleSV(int index) const {return jetBtagSimpleSV()->at(index);}
    Float_t GetSecJetBtagTrkCount(int index) const {return secjetTrkCountingHighEffBJetTags()->at(index);}

  // Btagging discriminants
    Int_t GetBtagJetFlavour(int index) const {return  jetgenJetFlavour()->at(index);}

    Float_t GetBTagResponse(int index, int algo){
      switch (algo){
        case 1: return jetTrkCountingHighEffBJetTags()->at(index);break;
        case 2: return jetTrkCountingHighPurBJetTags()->at(index);break;
        case 3: return jetSimpleSecondaryVertexHighEffBJetTags()->at(index);break;
        case 4: return jetSimpleSecondaryVertexHighPurBJetTags()->at(index);break;
        case 5: return jetCombinedSecondaryVertexBJetTags()->at(index);break;
        case 6: return jetCombinedSecondaryVertexMVABJetTags()->at(index);break;
        case 7: return jetJetProbabilityBJetTags()->at(index);break;
        case 8: return jetJetBProbabilityBJetTags()->at(index);break;
        case 9: return jetSoftElectronByIP3dBJetTags()->at(index);break;
        case 10: return jetSoftElectronByPtBJetTags()->at(index);break;
        case 11: return jetSoftMuonBJetTags()->at(index);break;
        case 12: return jetSoftMuonByIP3dBJetTags()->at(index);break;
        case 13: return jetSoftMuonByPtBJetTags()->at(index);break;
      }
      return -1;
    }


  // Functions corresponding to functions in NT7_NtupleData
    Double_t GetElecD0(int index) const {
      return -electronGsfTrackDxy()->at(index);
    }

    UInt_t GetMuonTrkValidHits(int index) const {
      return muonGlobalTracknumberOfValidHits()->at(index);
    }
    Double_t GetJetCorrFactor(int index) const {
      return jetCorrFactor()->at(index); }

    Double_t GetJetWidth(int index) const {
      float jetW=(jetEtaEtaMoment()->at(index)+jetPhiPhiMoment()->at(index))/2.;
      return  jetW;
    }

  // User should check suitable index is passed to this method!
      LorentzV getMatchedGenJet( int index ) const {
        if ( index >= 0 && index < int(genJetP4()->size()) ) {
          return genJetP4()->at(index);
        } else {
          std::cout << "Warning! Trying to access element " << index
            << " of GenJetP4 vector of size " << genJetP4()->size()
            << "! Returning LorentzV(0,0,0,0)...";
          return LorentzV(0.,0.,0.,0.);
        }
      }

    public:

      Electrons LD_Electrons;
      Muons LD_Muons;
    //MICHELE ->Secondary Muon Collection
      SecMuons LD_SecMuons;
  //MICHELE ->Secondary Muon Collection
      ICF::Taus LD_Taus;
      ICF::SecTaus LD_SecTaus;
      ICF::Photons PD_Photons;
      ICF::Jets JD_Jets;
      ICF::SecJets JD_SecJets;
      ICF::TerJets JD_TerJets; //!< Tertiary jet collection. <TW date="12/11/2010" />
      ICF::GenParticles GenParticles; //!< Vector of generator level particles
      ICF::MPT MPT;
      ICF::AK5MET AK5MET;       //!< fully corrected calorimetric MET using AK5 jets
      ICF::CaloMET CaloMET;     //!< fully corrected calorimetric MET
      ICF::IC5MET IC5MET;       //!< fully corrected calorimetric MET using IC5 jets
      ICF::PFMET PFMET;         //!< fully corrected calorimetric MET using particle flow
      ICF::TCMET TCMET;               //!< fully corrected calorimetric MET using track corrected met
      ICF::CaloMETnohf CaloMETnohf;   //!< fully corrected calorimetric MET without the hf
      ICF::CaloMETtypeII CaloMETtypeII;     //!< fully corrected calorimetric MET

    };
  }

#endif
