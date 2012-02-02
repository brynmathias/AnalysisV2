#include "PhotonOps.hh"
#include "PhotonCompute.hh"

namespace Operation {

  NumSelectedPhotons::NumSelectedPhotons(const std::string & comparison,
       UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  bool NumSelectedPhotons::Process(Event::Data & ev) {
    std::vector<Event::Photon const*> photons = ev.Get<SelectedPhotons>("SelectedPhotons")();
    return (*mComparison)(UInt_t(photons.size()),mNumber);
  }

  std::ostream& NumSelectedPhotons::Description(std::ostream &ostrm) {
    ostrm << "Number of Selected Photons " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }


  NumSelectedJets::NumSelectedJets(const std::string & comparison,
       UInt_t number) :
    mNumber(number) {
    if ( strcmp("==",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, EQ>);
    } else if ( strcmp("!=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, NEQ>);
    } else if ( strcmp("<",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LT>);
      } else if ( strcmp(">",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GT>);
      } else if ( strcmp(">=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, GTEQ>);
  } else if ( strcmp("<=",comparison.c_str()) == 0 ) {
      mComparison = reinterpret_cast<_Compare<UInt_t> *>(new Operation::Compare<UInt_t, LTEQ>);
    } else {
      throw std::invalid_argument(std::string("Invalid operation"));
    }
  }

  bool NumSelectedJets::Process(Event::Data & ev) {
    std::vector<Event::Jet const*> jets = ev.Get<SelectedJets>("SelectedJets")();
    return (*mComparison)(UInt_t(jets.size()),mNumber);
  }

  std::ostream& NumSelectedJets::Description(std::ostream &ostrm) {
    ostrm << "Number of Jets " << mComparison->type();
    ostrm << " " << mNumber << ")";
    return ostrm;
  }


  PrescaleFilter::PrescaleFilter(const std::string & bit, const int value):
    mTriggerBit(bit),
    mValue(value)
  {}

  bool PrescaleFilter::Process(Event::Data & ev) {
    std::map<std::string,bool>::const_iterator it=ev.hlt()->find(mTriggerBit);
    std::map<std::string,int>::const_iterator p=ev.hlt_prescaled()->find(mTriggerBit);
    //std::cout << mTriggerBit << ": Prescale = " << p->second << std::endl;
    // Check that triggers exists and prescales are 1.
    if (it!=ev.hlt()->end() && p->second == mValue) {
      return true;
    }

    return false;
  }

  std::ostream& PrescaleFilter::Description(std::ostream &ostrm) {
    ostrm << "PrescaleFilter " << mTriggerBit;
    return ostrm;
  }


  SpikeSelector::SpikeSelector(){}

  bool SpikeSelector::Process(Event::Data & ev) {
    for (std::vector<Event::Photon const *>::const_iterator pho = ev.PD_CommonPhotons().accepted.begin(); pho != ev.PD_CommonPhotons().accepted.end(); ++pho) {
      if (ev.photonE2overE9()->at((*pho)->GetIndex()) + ev.photonSeedEnergy()->at((*pho)->GetIndex())/ev.photonE3x3()->at((*pho)->GetIndex()) < 0.96 && ev.photonTime2()->at((*pho)->GetIndex()) < -5.) return true;
    }
    return false;
  }

  std::ostream& SpikeSelector::Description(std::ostream &ostrm) {
    ostrm << "Spike Selector: |t2| > 5ns & E2/E9 < 0.96";
    return ostrm;
  }

  DeadTTCut::DeadTTCut(){}

  bool DeadTTCut::Process(Event::Data & ev) {
    for (std::vector<PolarLorentzV>::const_iterator p4 = ev.ecalDeadTowerTrigPrimP4()->begin(); p4 != ev.ecalDeadTowerTrigPrimP4()->end(); ++p4) {
      if (p4->pt() > 20.) return false;
    }
    return true;
  }

  std::ostream& DeadTTCut::Description(std::ostream &ostrm) {
    ostrm << "Dead TT Cut";
    return ostrm;
  }

  SignalFilter::SignalFilter(const int mSquark, const int mGluino) :
    mSquark_(mSquark),
    mGluino_(mGluino)
  {}

  bool SignalFilter::Process(Event::Data & ev) {
    if (ev.MChi0() == 150 && ev.MSquark() == mSquark_ && ev.MGluino() == mGluino_) return true;
    return false;
  }

  std::ostream& SignalFilter::Description(std::ostream &ostrm) {
    ostrm << "SignalFilter";
    return ostrm;
  }

 //===========
  // Photon Pt Cut
  //===========
  PhotonPtCut::PhotonPtCut(float value) :
  mCut(value) {}

  PhotonPtCut::~PhotonPtCut() {}

  bool PhotonPtCut::Process(Event::Data & ev) {
    std::vector<Event::Photon const*> photons = ev.Get<SelectedPhotons>("SelectedPhotons")();
    if(photons.size()==0) return true;
    return (photons[0]->Pt() > mCut );
  }

  std::ostream& PhotonPtCut::Description(std::ostream &ostrm) {
    ostrm << "Leading Photon Pt > " << mCut << " GeV: ";
    return ostrm;
  }

 //============
  // Categorize
  //===========
  Categorize::Categorize(const int value) :
  mCut(value) {}

  bool Categorize::Process(Event::Data & ev) {
    int nSelected = 0;
    int nControl = 0;
    int nSidebandSelected = 0;
    int nSidebandControl = 0;
    for (std::vector<Event::Photon const*>::const_iterator photon = ev.PD_CommonPhotons().accepted.begin(); photon != ev.PD_CommonPhotons().accepted.end(); ++photon) {
      if ((*photon)->GetIntID() == 3) nSelected++;
      else if ((*photon)->GetIntID() == 2) nControl++;
      else if ((*photon)->GetIntID() == 1) nSidebandSelected++;
      else nSidebandControl++;
    }
    if (nSelected >= 1) ev.SetCategory(4);
    else if (nControl >= 1) ev.SetCategory(3);
    else if (nSidebandSelected >= 1) ev.SetCategory(2);
    else ev.SetCategory(1);
    return true;
  }

  std::ostream& Categorize::Description(std::ostream &ostrm) {
    ostrm << "Categorize ";
    return ostrm;
  }

 //============
  // Category
  //===========
  Category::Category(const int value) :
  mCut(value) {}

  bool Category::Process(Event::Data & ev) {
    if (ev.GetCategory() == mCut) return true;
  }

  std::ostream& Category::Description(std::ostream &ostrm) {
    ostrm << "Category = " << mCut << ": ";
    return ostrm;
  }

}
