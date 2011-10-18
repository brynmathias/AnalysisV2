#include "Operation.hh"
#include "EventData.hh"
#include "Compare.hh"
#include "Utils.hh"

namespace Operation{

class NumSelectedPhotons : public Operation::_Base {
  public:
    NumSelectedPhotons(const std::string &, UInt_t);
    ~NumSelectedPhotons() { delete mComparison; }

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    UInt_t mNumber;
};

class NumSelectedJets : public Operation::_Base {
  public:
    NumSelectedJets(const std::string &, UInt_t);
    ~NumSelectedJets() { delete mComparison; }

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);

  private:
    Operation::_Compare<UInt_t> *mComparison;
    UInt_t mNumber;
};

class SpikeSelector : public Operation::_Base {
  public:
    SpikeSelector();
    ~SpikeSelector() {}

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);
};

class DeadTTCut : public Operation::_Base {
  public:
    DeadTTCut();
    ~DeadTTCut() {}

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);
};

class SignalFilter : public Operation::_Base {
  public:
    SignalFilter(int,int);
    ~SignalFilter() {}

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);
  private:
    const int mSquark_;
    const int mGluino_;
};

class PrescaleFilter : public Operation::_Base {
  public:
    PrescaleFilter(const std::string &, int value);
    ~PrescaleFilter() {}

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);
  private:
    const std::string mTriggerBit;
    const int mValue;
};

  class  PhotonPtCut : public Operation::_Base {

  public:

    PhotonPtCut(float mMHTvalue );

    ~ PhotonPtCut(); //!< Destructor.

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

  private:
    // Operation private data members
    //--------------------------------
    float mCut;           //!<

  }; // ~PhotonPtCut class

class Categorize : public Operation::_Base {
  public:
    Categorize(const int value);
    ~Categorize() {}

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);
  private:
    const int mCut;
};

class Category : public Operation::_Base {
  public:
    Category(const int value);
    ~Category() {}

    bool Process(Event::Data &);

    std::ostream& Description(std::ostream &);
  private:
    const int mCut;
};

}
