#ifndef CROSS_CLEAN_HH
#define CROSS_CLEAN_HH

#include "Lepton.hh"
#include "Jet.hh"
#include "Photon.hh"
#include "Utils.hh"
#include <sstream>
#include <vector>
#include <map>

namespace Compute{

// Type of Kill operation
enum KillCode{
  jet_kills_muon,
  jet_kills_electron,
  jet_kills_photon,
  electron_kills_jet,
  photon_kills_jet,
  kill_jet,
  kill_electron,
  kill_muon,
  kill_photon,
  kill_none=0
};

// A Kill operation
struct KillOp{
  KillCode op; // kill type
  const LorentzV* killer; // object doing killing
  int idx; // Index of object to kill
  int kill_idx; // Index of object doing killing
  double dr_;
  KillOp(const LorentzV* _killer, KillCode _op,int _idx,int _kill_idx):
    op(_op), killer(_killer),idx(_idx),kill_idx(_kill_idx){}

  KillOp(): op(kill_none),killer(0),idx(0){}
  void print( std::stringstream& ) const;
  void terse( std::stringstream& ) const;
  std::string killCode() const;
  std::string killerStr() const;
  std::string killedStr() const;
};


class LeptonFilter{
 private:
  double mPtCut;        //!< pt cut below which the energy deposit corresponding to the "lepton" is ignored.
  double mTrkIsoCut;
  double mEtaCut;       //!< eta cut above which the energy deposit corresponding to the "lepton" is ignored.
	bool mRequireLooseIdToPassInitialFilter; //!< Require the lepton to pass loose ID criteria to even consider the lepton? (TW added.)
 public:
  //LeptonFilter(double pt_cut, double eta_cut): // TW commented out to accomodate ID requirement.
  LeptonFilter(double pt_cut, double eta_cut, bool requireLooseIdToPassInitialFilter):
      mPtCut(pt_cut),
			mEtaCut(eta_cut),
			mRequireLooseIdToPassInitialFilter(requireLooseIdToPassInitialFilter)
	{}

  bool operator()(const Event::Lepton* lep) const{
    return (lep->Pt() > mPtCut &&
            //lep->GetLooseId() && // TW - this requirement is hard-coded, and does not follow the new spec
						// The new specification requires that we keep leptons that fail ID cuts with
						// pT > threshold for later comparison with jets and other objects.
						// Previously, any lepton failing loose ID was discarded regardless of pt.
            ((lep->GetLooseId() && mRequireLooseIdToPassInitialFilter) || (!mRequireLooseIdToPassInitialFilter)) &&
            fabs(lep->Eta()) < mEtaCut);
  }
};

class JetFilter{
 private:
  double mPtCut;
  double mFEmCut;
  double mEtaCut;
 public:
  JetFilter(double pt_cut,  double eta_cut):
      mPtCut(pt_cut),mEtaCut(eta_cut){}

  bool operator()(const Event::Jet* jet) const{
    return (jet->Pt() > mPtCut &&
            fabs(jet->Eta()) < mEtaCut);
  }
};

  class PhotonFilter{
  private:
    double mEtCut;
    double mEtaEBMaxCut;
    double mEtaEEMinCut;
    double mEtaEEMaxCut;
  public:
    PhotonFilter(double EtCut,  double EtaEBMaxCut, double EtaEEMinCut, double EtaEEMaxCut):
      mEtCut(EtCut),
      mEtaEBMaxCut(EtaEBMaxCut),
      mEtaEEMinCut(EtaEEMinCut),
      mEtaEEMaxCut(EtaEEMaxCut)
    {}

    bool operator()(const Event::Photon* photon) const{
      return (photon->Et() > mEtCut &&
        ( fabs(photon->Eta()) < mEtaEBMaxCut || (fabs(photon->Eta()) > mEtaEEMinCut && fabs(photon->Eta()) < mEtaEEMaxCut) ) );
    }
  };

class CrossCleaner{
 public:
  CrossCleaner(bool MuonJet,
               double MuonTrkIsoCut,
               double MuonCombIsoCut,
      	       bool modifyJetEnergy,
							 double muonJetDeltaR,        // TW added
							 double muonIsoTypePtCutoff,  // TW added
							 bool muLooseIdRequiredForInitialFilter, // TW added
               bool ElectronJet,
               double ElectronTrkIsoCut,
               double ElectronCombIsoCut,
							 double elJetDeltaR,          // TW added
							 double elIsoTypeCutoff,      // TW added
							 bool elLooseIdRequired,      // TW added
							 bool elTightIdRequired,      // TW added
							 bool elLooseIdRequiredForInitialFilter, // TW added
               bool PhotonJet,
               double PhotonTrkIsoCut,
               double PhotonCaloIsoCut,
               int PhotonIDReq,
               bool PhotonUseID,
							 double PhotonJetDeltaR,       // TW added
							 double PhotonIsoTypePtCutoff, // TW added
               CloneVector<Event::Jet> & Jets,
               CloneVector<Event::Lepton> & Muons,
               CloneVector<Event::Lepton> & Electrons,
               CloneVector<Event::Photon> & Photons,
         bool verbose ):
      mMuonJet(MuonJet),
      mMuTrkIsoCut(MuonTrkIsoCut),
      mMuCombIsoCut(MuonCombIsoCut),
      mModifyJetEnergy(modifyJetEnergy),
			mMuonJetDeltaR(muonJetDeltaR),             // TW added
			mMuonIsoTypePtCutoff(muonIsoTypePtCutoff), // TW added
			mMuLooseIdRequiredForInitialFilter(muLooseIdRequiredForInitialFilter), // TW added 14/10/2010
      mElectronJet(ElectronJet),
      mElTrkIsoCut(ElectronTrkIsoCut),
      mElCombIsoCut(ElectronCombIsoCut),
			mElJetDeltaR(elJetDeltaR),                 // TW added
			mElIsoTypePtCutoff(elIsoTypeCutoff),       // TW added
			mElLooseIdRequired(elLooseIdRequired),     // TW added
			mElTightIdRequired(elTightIdRequired),     // TW added
			mElLooseIdRequiredForInitialFilter(elLooseIdRequiredForInitialFilter), // TW added 14/10/2010
      mPhotonJet(PhotonJet),
      mPhotonTrkIsoCut(PhotonTrkIsoCut),
      mPhotonCaloIsoCut(PhotonCaloIsoCut),
      mPhotonIDReq(PhotonIDReq),
      mPhotonUseID(PhotonUseID),
			mPhotonJetDeltaR(PhotonJetDeltaR),             // TW added
			mPhotonIsoTypePtCutoff(PhotonIsoTypePtCutoff), // TW added
      mJets(Jets),
      mMuons(Muons),
      mElectrons(Electrons),
      mPhotons(Photons),
      verbose_(verbose)
 {}

  ~CrossCleaner(){};

  void Reset();
  void Clean();
  void Resolve();
  void Execute();
  void KillMap( std::vector<KillOp>& );

 private:

  bool mMuonJet;
  double mMuTrkIsoCut;
  double mMuCombIsoCut;
  double mModifyJetEnergy;
	double mMuonJetDeltaR;       //!< $\Delta R(j,\mu)$ must be less than this cut value to count as overlapping.
	double mMuonIsoTypePtCutoff; //!< If $p_T^{\mu}$ is less than this cut value, use track isolation; otherwise use combined isolation.
	bool mMuLooseIdRequiredForInitialFilter; //!< Is loose ID required for the muon to pass the initial CC filtering?
  bool mElectronJet;
  double mElTrkIsoCut;
  double mElCombIsoCut;
	double mElJetDeltaR;         //!< $\Delta R(j,e)$ must be less than this cut value to count as overlapping.
	double mElIsoTypePtCutoff;   //!< If $p_{T}^{e}$ is less than this cut value, use track isolation; otherwise use combined isolation.
	bool   mElLooseIdRequired;   //!< Is loose ID required for 
	bool   mElTightIdRequired;   //!< Is tight ID required for
	bool mElLooseIdRequiredForInitialFilter; //!< Is loose ID required for the electron to pass the initial CC filtering?
  bool mPhotonJet;
  double mPhotonTrkIsoCut;
  double mPhotonCaloIsoCut;
  int mPhotonIDReq;
  bool mPhotonUseID;
	double mPhotonJetDeltaR;       //!< $\Delta R(j,\gamma)$ must be less than this cut value to count as overlapping.
  double mPhotonIsoTypePtCutoff; //!< If $p_{T}^{\gamma}$ is less than this cut value, use track isolation; otherwise use ECAL isolation with p_T dependence.
  CloneVector<Event::Jet>& mJets;
  CloneVector<Event::Lepton>& mMuons;
  CloneVector<Event::Lepton>& mElectrons;
  CloneVector<Event::Photon>& mPhotons;
  std::map<const LorentzV*,KillOp> mKillMap;
  bool verbose_;


  KillCode anonymous_kill(KillCode code){
    switch(code){
      case jet_kills_muon:
        return kill_muon;

      case electron_kills_jet:
        return kill_jet;

      case photon_kills_jet:
        return kill_jet;

      case jet_kills_electron:
        return kill_electron;

      case jet_kills_photon:
        return kill_photon;

      default:
        throw std::invalid_argument("Invalid kill found in KillMap");
    }
  }
};
}
#endif
