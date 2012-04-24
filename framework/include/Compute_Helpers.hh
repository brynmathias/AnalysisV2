/*! \file Compute_Helpers.hh
 * \brief Helper functions for computation
 */

#ifndef COMPUTE_HELPERS_HH
#define COMPUTE_HELPERS_HH

#include "Compute_Variable.hh"
#include <cstdlib>
#include "Types.hh"
#include "Utils.hh"

namespace Event {
  class GenObject;
}


/*! \brief Namespace for all computation-related code.
 */
namespace Compute {

  // Inlined and separated
  Double_t inline MomentumToEta( Double_t px, Double_t py, Double_t pz ) { //!< Calc eta using momentum 3-vector.
    Double_t p = sqrt( px*px + py*py + pz*pz );
    return ( 0.5 * ( log( ( p + pz ) / ( p - pz ) ) ) );
  }


  // Recoil MET
  class RecoilMET : public Compute::Variable<LorentzV, RecoilMET> {
  public:
    RecoilMET(const Event::Data & ev);
    void _Update() const;
  };

  // Object sum
  class ObjSum : public Compute::Variable<LorentzV, ObjSum> {
  public:
    ObjSum(const Event::Data & ev);
    void _Update() const;
  };

  // Object sum
  class SumEt : public Compute::Variable<Double_t, SumEt> {
  public:
    SumEt(const Event::Data & ev);
    void _Update() const;
  };

  // Common jets MHT
  class CommonMHT : public Compute::Variable<LorentzV, CommonMHT> {
  public:
    CommonMHT(const Event::Data & ev);
    void _Update() const;
  };

  // Common jets and Muon MHT
  class CommonMHTTakeMu : public Compute::Variable<LorentzV, CommonMHTTakeMu> {
  public:
    CommonMHTTakeMu(const Event::Data & ev);
    void _Update() const;
  };

  // Common jets HT
  class CommonHT : public Compute::Variable<Double_t, CommonHT> {
  public:
    CommonHT(const Event::Data & ev);
    void _Update() const;
  };

  // Common jets and muons HT
  class CommonHTTakeMu : public Compute::Variable<Double_t, CommonHTTakeMu> {
  public:
    CommonHTTakeMu(const Event::Data & ev);
    void _Update() const;
  };

  class CommonMT : public Compute::Variable<Double_t, CommonMT> {
  public:
    CommonMT(const Event::Data & ev);
    void _Update() const;
  };

  class CommonMinDPhi : public Compute::Variable<Double_t, CommonMinDPhi> {
  public:
    CommonMinDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class CommonMinBiasDPhi : public Compute::Variable<Double_t, CommonMinBiasDPhi> {
  public:
    CommonMinBiasDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class JetMinDPhi : public Compute::Variable<Double_t, JetMinDPhi> {
  public:
    JetMinDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class JetMinBiasDPhi : public Compute::Variable<Double_t, JetMinBiasDPhi> {
  public:
    JetMinBiasDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class JetMETMinDPhi : public Compute::Variable<Double_t, JetMETMinDPhi> {
  public:
    JetMETMinDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class CommonMinDEt : public Compute::Variable<Double_t, CommonMinDEt> {
  public:
    CommonMinDEt(const Event::Data & ev);
    void _Update() const;
  };

  class CommonAlphaT : public Compute::Variable<Double_t, CommonAlphaT> {
  public:
    CommonAlphaT(const Event::Data & ev);
    void _Update() const;
  private:
    const bool AlphaTwithEt;

  };

  class LeptonicAlphaT : public Compute::Variable<Double_t, LeptonicAlphaT> {
  public:
    LeptonicAlphaT(const Event::Data & ev);
    void _Update() const;
  private:
    const bool AlphaTwithEt;
  };

  class HadronicAlphaT : public Compute::Variable<Double_t, HadronicAlphaT> {
  public:
    HadronicAlphaT(const Event::Data & ev);
    void _Update() const;
  private:
    const bool AlphaTwithEt;

  };

  class HadronicAlphaTTakeMu : public Compute::Variable<Double_t, HadronicAlphaTTakeMu> {
  public:
    HadronicAlphaTTakeMu(const Event::Data & ev);
    void _Update() const;
  private:
    const bool AlphaTwithEt;

  };


  class CommonMT2 : public Compute::Variable<Double_t, CommonMT2> {
  public:
    CommonMT2(const Event::Data & ev);
    void _Update() const;
  };



  class CommonRecoilMET : public Compute::Variable<LorentzV, CommonRecoilMET> {
  public:
    CommonRecoilMET(const Event::Data & ev);
    void _Update() const;
  };
 class CommonMeff : public Compute::Variable<Double_t, CommonMeff> {
  public:
    CommonMeff(const Event::Data & ev);
    void _Update() const;
  };
  class CommonObjectSum : public Compute::Variable<LorentzV, CommonObjectSum> {
  public:
    CommonObjectSum(const Event::Data & ev);
    void _Update() const;
  };

  class CommonRecoil : public Compute::Variable<LorentzV, CommonRecoil> {
  public:
    CommonRecoil(const Event::Data & ev);
    void _Update() const;
  };

  class CommonSumEt : public Compute::Variable<Double_t, CommonSumEt> {
  public:
    CommonSumEt(const Event::Data & ev);
    void _Update() const;
  };

  class CommonRecoilMETJetDPhi : public Compute::Variable<Double_t, CommonRecoilMETJetDPhi> {
  public:
    CommonRecoilMETJetDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class BiasedCommonRecoilMETJetDPhi : public Compute::Variable<Double_t, BiasedCommonRecoilMETJetDPhi> {
  public:
    BiasedCommonRecoilMETJetDPhi(const Event::Data & ev);
    void _Update() const;
  };

  class LowPtBiasedCommonRecoilMETJetDPhi : public Compute::Variable<Double_t, LowPtBiasedCommonRecoilMETJetDPhi> {
  public:
    LowPtBiasedCommonRecoilMETJetDPhi(const Event::Data & ev);
    void _Update() const;
  };

  // Common objects
  class CommonObjects : public Compute::Variable<std::vector<LorentzV>, CommonObjects> {
  public:
    CommonObjects(const Event::Data & ev);
    void _Update() const;
  };
  class LeptonicObjects : public Compute::Variable<std::vector<LorentzV>, LeptonicObjects> {
  public:
    LeptonicObjects(const Event::Data & ev);
    void _Update() const;
  };
  class HadronicObjects : public Compute::Variable<std::vector<LorentzV>, HadronicObjects> {
  public:
    HadronicObjects(const Event::Data & ev);
    void _Update() const;
  };



  class CommonJetsAndElectrons : public Compute::Variable<std::vector<LorentzV>, CommonJetsAndElectrons> {
  public:
    CommonJetsAndElectrons(const Event::Data & ev);
    void _Update() const;
  };


  class CommonJetsAndMuons : public Compute::Variable<std::vector<LorentzV>, CommonJetsAndMuons> {
  public:
    CommonJetsAndMuons(const Event::Data & ev);
    void _Update() const;
  };


  class M3 : public Compute::Variable<Double_t, M3> {
  public:
    M3(const Event::Data & ev);
    void _Update() const;
  };


  class Razor_MR : public Compute::Variable<Double_t, Razor_MR> {
  public:
    Razor_MR(const Event::Data & ev);
    void _Update() const;

  };

  class Razor_MRt : public Compute::Variable<Double_t, Razor_MRt> {
  public:
    Razor_MRt(const Event::Data & ev);
    void _Update() const;

  };




class WeightProducer : public Compute::Variable<double,WeightProducer>{
 public:
  WeightProducer(const Event::Data &ev);
  void Init(double required_lumi,
            const std::vector<double> & xcs,
            const std::vector<int> & evts,
            const std::vector<double> & ptbins);
  void _Update() const;
  std::ostream & Output(std::ostream & ostrm) const;
 private:
  std::vector<double> mPtBins;
  std::vector<int> mEventsPerBin;
  std::vector<double> mCrossSections;
  std::vector<double> mWeights;
};

class EventWeight : public Compute::Variable<double, EventWeight>{
 public:
  typedef std::vector<std::pair<std::string,
                                Compute::ObjectFilter<double>* > > FilterList;

  enum WeightMode{
    MSUGRA,
    CONSTANT,
    NTUPLE,
    PRODUCER,
    NEVENTS,
    USER
  };
  EventWeight(const Event::Data &ev);
  void Init(const std::string mode,
            double desired_lumi,
            double cross_section,
            double _weight,
            int nevents,
            bool use_weight_producer,
            EventWeight::FilterList & filters);
  void _Update() const;
  std::ostream & Print(std::ostream & ostrm);
 private:
  EventWeight::WeightMode mMode;
  mutable Compute::ObjectProcessor<double> weight_proc;
  double mDesiredLumi;
  double mCrossSection;
  double mWeight;
  int mNEvents;
};

} // ~ namespace Compute

#endif //~COMPUTE_HELPERS_HH
