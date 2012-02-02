#include "Operation.hh"
#include "Utils.hh"


namespace WPol{
class DebugElectronID : public Operation::_Base {
 public:
  DebugElectronID(int id_to_apply,
                  const Utils::ParameterSet & ps,
                  const std::string & prefix = "Cuts"
                  );

  ~DebugElectronID();

  void Start(Event::Data & ev);

  //Based on Paolo Meridiani's corrections
  float dPhiCorr(double elePhi , double eleEta);
  float dEtaCorr(double elePhi , double eleEta);

  bool Process(Event::Data & ev);

  std::ostream & Description(std::ostream & ostrm);

 private:
  const std::string mName;
  bool mIso;
  bool mHoE;
  bool mDeltaEta, mDeltaPhi;
  bool mShh;
  bool mConv;
  bool mConvExtra;

  double mRelCombIsoBarrel, mRelCombIsoEndcap;
  double mTrkIsoBarrel, mTrkIsoEndcap;
  double mEcalIsoBarrel, mEcalIsoEndcap;
  double mHcalIsoBarrel, mHcalIsoEndcap;
  double mHoEBarrel, mHoEEndcap;
  double mDeltaPhiBarrel, mDeltaPhiEndcap;
  double mDeltaEtaBarrel, mDeltaEtaEndcap;
  double mSigmaIEtaIEtaBarrel, mSigmaIEtaIEtaEndcap;
  double mDCot, mDist;
  int mMissingHits;
  bool mSupressErrors;
  bool mCorrEEMisalig;
  int mIDToApply;
};
}
