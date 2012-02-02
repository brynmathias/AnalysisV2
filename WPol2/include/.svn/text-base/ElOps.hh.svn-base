#include "EventData.hh"
#include "WPol.hh"
#include "Operation.hh"
#include "Utils.hh"

namespace WPol{

/* ApplyLeptonCut
 * This operation applies the given filter and pt cut to the
 * selected common lepton type. If exact is true, exactly
 * nLeptons leptons must pass the cuts, otherwise >= nLeptons
 * are required.
 */
class ApplyLeptonCut : public Operation::_Base{
 public:
  ApplyLeptonCut(const std::string & lep_type,
                 const double pt_cut,
                 Compute::ObjectFilter<Event::Lepton>* filter,
                 int nLeptons,
                 bool exact);
  ~ApplyLeptonCut();
  void Start(Event::Data & ev);
  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  LeptonType mLeptonType;
  double mPtCut;
  Compute::ObjectFilter<Event::Lepton>* mFilter;
  int mNLeptons;
  bool mExact;
};

class MassWindowCut : public Operation::_Base{
 public:
  MassWindowCut(const std::string & lep_type,
                const Utils::ParameterSet & ps);
  ~MassWindowCut();
  bool Process(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  LeptonType mLeptonType;
  double mMassLower;
  double mMassUpper;
  int mNetCharge;
  bool mMatchCharge;
};

class GenLeptonType : public Operation::_Base{
public:
  GenLeptonType(const std::string & lep_type,
               const std::string & mc_type);
  ~GenLeptonType();

  bool Process(Event::Data & ev);

  std::ostream & Description(std::ostream & ostrm);
private:
LeptonType mLeptonType;
MCLeptonType mMCType;
};


  class PFMHTCut : public Operation::_Base {

  public:

    PFMHTCut(float mMHTvalue );

    ~PFMHTCut(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mMHTvalue;           //!<

  }; // ~caloMETCut class

 class RECOpfMTCut : public Operation::_Base {

  public:

    RECOpfMTCut(const std::string & lep_type, double cut);
    ~RECOpfMTCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

    double mCut;
    LeptonType mLeptonType;
  }; // ~RECOpfMTCut class

 class ChargeAgreement : public Operation::_Base {

  public:

    ChargeAgreement();
    ~ChargeAgreement();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:

  };

 class CombRelIsoCut : public Operation::_Base {

  public:

    CombRelIsoCut(double cut);
    ~CombRelIsoCut();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
   double mCut;
  };



}
