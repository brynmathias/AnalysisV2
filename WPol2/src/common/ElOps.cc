#include "ElOps.hh"

namespace WPol{


ApplyLeptonCut::ApplyLeptonCut(const std::string & lep_type,
                               const double pt_cut,
                               Compute::ObjectFilter<Event::Lepton>* filter,
                               int nLeptons,
                               bool exact

):
    mLeptonType(GetLeptonType(lep_type)),
    mPtCut(pt_cut),
    mFilter(filter),
    mNLeptons(nLeptons),
    mExact(exact)

{}

ApplyLeptonCut::~ApplyLeptonCut(){}

void ApplyLeptonCut::Start(Event::Data & ev){
  mFilter->Init(ev);
}

bool ApplyLeptonCut::Process(Event::Data & ev){
  const std::vector<const Event::Lepton*> & leps =
      GetCommonLeptons(ev, mLeptonType);
  int count = 0;
  for(std::vector<const Event::Lepton*>::const_iterator it = leps.begin();
      it != leps.end();
      ++it){
    if(mFilter->Apply(*it) && (*it)->Pt() > mPtCut) count++;
  }
  return (mExact ? count == mNLeptons : count >= mNLeptons);
}

std::ostream & ApplyLeptonCut::Description(std::ostream & ostrm){
  ostrm << "ApplyLeptonCut operation (Pt > " << mPtCut
        << ", Filter: " << *mFilter
        << "NLeptons = " << mNLeptons << ")";
  return ostrm;
}

MassWindowCut::MassWindowCut(const std::string &lep_type,
                             const Utils::ParameterSet & ps):
    mLeptonType(GetLeptonType(lep_type)),
    mMassLower(ps.Get<double>("MassLower")),
    mMassUpper(ps.Get<double>("MassUpper")),
    mNetCharge(ps.Get<int>("NetCharge")),
    mMatchCharge(ps.Get<bool>("MatchCharge"))
{}

MassWindowCut::~MassWindowCut(){}

bool MassWindowCut::Process(Event::Data &ev){
  const std::vector<const Event::Lepton*> & leps =
      GetCommonLeptons(ev, mLeptonType);
  if(leps.size() != 2) return true;
  else{
    double mass = (*(leps[0])+(*leps[1])).M();
    if ( mass > mMassLower && mass < mMassUpper &&
         ((leps[0]->GetCharge() + leps[1]->GetCharge() == mNetCharge)
          || !mMatchCharge)) return false;
    return true;
  }
}

std::ostream & MassWindowCut::Description(std::ostream & ostrm){
  ostrm << "MassWindowCut " << mMassLower
        << " < mass < " << mMassUpper;
  if(mMatchCharge) ostrm << " NetCharge == " << mNetCharge;
  return ostrm;
}


//================
// Cut on leptons of certain MC type
//================
GenLeptonType::GenLeptonType(const std::string & lep_type,
                           const std::string & mc_type):
    mLeptonType(GetLeptonType(lep_type)),
    mMCType(GetMCLeptonType(mc_type))
{}

GenLeptonType::~GenLeptonType() {}

bool GenLeptonType::Process(Event::Data & ev) {
  const Event::Lepton* lep = GetLeadingLepton(ev,mLeptonType);
  if(lep){
int i = ExtendedType(ev,lep,mLeptonType);
    return (i == mMCType);
  }
  else return false;
}

std::ostream& GenLeptonType::Description(std::ostream &ostrm) {
ostrm << "GenLeptonType (" << GetLeptonString(mLeptonType) <<
  ") == " << GetMCLeptonString(mMCType) << " " ;
  return ostrm;
}


  //================
  // PFMET Cut
  //================
  PFMHTCut::PFMHTCut(float metVal) :
    mMHTvalue(metVal) {}

  PFMHTCut::~PFMHTCut() {}

  bool PFMHTCut::Process(Event::Data & ev) {
    if(ev.LD_CommonElectrons().accepted.size() == 0) return false;
    ICF_LorentzV raw_eli = (ev.electronP4()->at(ev.LD_CommonElectrons().accepted[0]->GetIndex()));
    double mht =  (ev.PFMET() + raw_eli).Pt();
    // double mht =  (ev.PFMET() + *(ev.LD_CommonElectrons().accepted[0])).Pt();

if (mht>mMHTvalue) return true;
    return false;
  }

  std::ostream& PFMHTCut::Description(std::ostream &ostrm) {
    ostrm << "PF MHTCut> " << mMHTvalue << " GeV): ";
    return ostrm;
  }

//================
// RECO Cut on PF MT
//================

RECOpfMTCut::RECOpfMTCut(const std::string & lep_type, double cut) :
    mLeptonType(GetLeptonType(lep_type)),
    mCut(cut)
{}

RECOpfMTCut::~RECOpfMTCut() {}

bool RECOpfMTCut::Process(Event::Data & ev) {
  const std::vector<const Event::Lepton*> & leps =
      GetCommonLeptons(ev, mLeptonType);

  // This is a fix required for the transparency corrections to make sense
  ICF_LorentzV raw_eli = (ev.electronP4()->at(leps[0]->GetIndex()));
  ICF_LorentzV pfmet = (ev.PFMET() + raw_eli) - *(leps[0]);

  if(leps.size() >= 1) {
    double MT = sqrt(2.0 * pfmet.Pt() * leps.at(0)->Pt() *
                     (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(leps.at(0)),
                                                                 pfmet))));
    return (MT > mCut);
  }
  return false;
}


std::ostream& RECOpfMTCut::Description(std::ostream &ostrm) {
  ostrm << "RECO pfMT Cut > " << mCut << "GeV";
  return ostrm;
}

//================
// RECO Cut on PF MT
//================

ChargeAgreement::ChargeAgreement()
{}

ChargeAgreement::~ChargeAgreement() {}

bool ChargeAgreement::Process(Event::Data & ev) {
  if(ev.LD_CommonElectrons().accepted.size() < 1) return true;
  bool charge = (ev.LD_CommonElectrons().accepted.at(0)->GetCharge() > 0);
  bool kfcharge = (ev.electronKFCharge()->at(
                       ev.LD_CommonElectrons().accepted.at(0)->GetIndex()) > 0);
  bool sccharge = (ev.electronSCCharge()->at(
                       ev.LD_CommonElectrons().accepted.at(0)->GetIndex()) > 0);
  return ((charge == kfcharge) && (kfcharge == sccharge));
}


std::ostream& ChargeAgreement::Description(std::ostream &ostrm) {
  ostrm << "Three charge agreement";
  return ostrm;
}



CombRelIsoCut::CombRelIsoCut(double cut):
    mCut(cut)
{}

CombRelIsoCut::~CombRelIsoCut() {}

bool CombRelIsoCut::Process(Event::Data & ev) {
  if(ev.LD_CommonElectrons().accepted.size() < 1) return true;
  return (ev.LD_CommonElectrons().accepted[0]->GetCombIsolation() < mCut);
}


std::ostream& CombRelIsoCut::Description(std::ostream &ostrm) {
  ostrm << "Isolation cut < "<< mCut;
  return ostrm;
}





}
