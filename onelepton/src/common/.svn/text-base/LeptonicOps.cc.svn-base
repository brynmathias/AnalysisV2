#include "LeptonicOps.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "Lepton.hh"
#include "KinSuite.hh"
#include "ThrustStuff.hh"
#include "GenMatrixBin.hh"
#include <iostream>

namespace Operation {

//================
// Sum Pt lep cut
//================

  DphiPTW_muCut::DphiPTW_muCut(float Dphi)
    : mDphiPTW_mu(Dphi)
  {;}
  
  bool DphiPTW_muCut::Process(Event::Data & ev) {
    
    std::vector <Event::Lepton const *> theRECOLepton;
    
    if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()==0) ) {
      theRECOLepton = ev.LD_CommonMuons().accepted;
    }
    
    if ( (ev.LD_CommonMuons().accepted.size()==0) && (ev.LD_CommonElectrons().accepted.size()>0) ) {
      theRECOLepton = ev.LD_CommonElectrons().accepted;
    }  
    if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()>0) ) {
      //  cout << "WARNING: ANplots has common muon AND Electron, it does not know what to plot!!!"<<endl;
      return false;
    }
    
    if (theRECOLepton.size()==0){
      // cout << "  ANplots does require at least one lepton: plots not filled "<<endl;
      return true;
    } 
    
    // define variables
    LorentzV pfMHT = ev.PFMET() + *(theRECOLepton.at(0));


    if( fabs(ROOT::Math::VectorUtil::DeltaPhi(*theRECOLepton.at(0),pfMHT)) > mDphiPTW_mu) return true;
    return false;
}

std::ostream& DphiPTW_muCut::Description(std::ostream &ostrm) {
  ostrm << " Dphi(PTW,mu) > "<< mDphiPTW_mu ;
  return ostrm;
}


//================
// Sum Pt lep cut
//================

  PTlepCut::PTlepCut(float Pt,float PtUP)
    : mPTlep(Pt),mPTlepUP(PtUP)
  {;}
  
  bool PTlepCut::Process(Event::Data & ev) {
    
    float  HTlep= 0;
    
    for ( std::vector<Event::Lepton const *>::const_iterator i = ev.LD_CommonElectrons().accepted.begin();
	  i != ev.LD_CommonElectrons().accepted.end();
	  i++ ) {

      HTlep+=(**i).Pt();
    }
    //cout << " and now HT lep is : " << HTlep << endl;
    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = ev.LD_CommonMuons().accepted.begin();
	i != ev.LD_CommonMuons().accepted.end();
	  i++ ) {
    HTlep+=(**i).Pt();
  }
  //cout << "finally HT lep is : " << HTlep << endl;
  if( mPTlepUP < 0) return (HTlep > mPTlep);
  return (HTlep > mPTlep&&HTlep < mPTlepUP);
 
}
std::ostream& PTlepCut::Description(std::ostream &ostrm) {
  ostrm <<mPTlep<< " > PTlep > " << mPTlep << " GeV ";
  return ostrm;
}
//================
// Sum Pt lep cut
//================

  PTmuCut::PTmuCut(float Pt)
    : mPTmu(Pt)
  {;}
  
  bool PTmuCut::Process(Event::Data & ev) {
    
  
    if(ev.LD_CommonMuons().accepted.size()<1) return false;
    else return ev.LD_CommonMuons().accepted.at(0)->Pt()>mPTmu;
    return false;
 
}
std::ostream& PTmuCut::Description(std::ostream &ostrm) {
  ostrm <<mPTmu<< " > PTmu > ";
  return ostrm;
}


  PTZCut::PTZCut(float Pt)
    : mPTmu(Pt)
  {;}
  
  bool PTZCut::Process(Event::Data & ev) {
    
  
    if(ev.LD_CommonMuons().accepted.size()!=2) return false;
     std::vector <Event::Lepton const *> theRECOLepton;
     bool isMu = false;
     
     if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()==0) ) {
       theRECOLepton = ev.LD_CommonMuons().accepted;
       isMu = true;
     }
     
     if ( (ev.LD_CommonMuons().accepted.size()==0) && (ev.LD_CommonElectrons().accepted.size()>0) ) {
       theRECOLepton = ev.LD_CommonElectrons().accepted;
     }  
     if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()>0) ) {
       //  cout << "WARNING: ANplots has common muon AND Electron, it does not know what to plot!!!"<<endl;
       return true;
     }


     if(theRECOLepton.size()==2&theRECOLepton.at(0)->GetCharge()!=theRECOLepton.at(1)->GetCharge())
       {
	 LorentzV theZ = (*theRECOLepton.at(0))+(*theRECOLepton.at(1));
	 
	 if( ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1)))>76  &&   ROOT::Math::VectorUtil::InvariantMass(*(theRECOLepton.at(0)),*(theRECOLepton.at(1)))<107&&theZ.Pt()>mPTmu) return true;
	  
       }

    return false;
 
}
std::ostream& PTZCut::Description(std::ostream &ostrm) {
  ostrm <<mPTmu<< " > PTmu > ";
  return ostrm;
}



//================
// Sum Pt lep cut
//================

  SumPTlepCut::SumPTlepCut(float sumEt,float sumEtUP)
    : mSumPTlep(sumEt),mSumPTlepUP(sumEtUP)
  {;}
  
  bool SumPTlepCut::Process(Event::Data & ev) {
    
    float  HTlep= ev.PFMET().Pt();
    
    for ( std::vector<Event::Lepton const *>::const_iterator i = ev.LD_CommonElectrons().accepted.begin();
	  i != ev.LD_CommonElectrons().accepted.end();
	  i++ ) {

      HTlep+=(**i).Pt();
    }
    //cout << " and now HT lep is : " << HTlep << endl;
    // Muons
    for ( std::vector<Event::Lepton const *>::const_iterator i = ev.LD_CommonMuons().accepted.begin();
	i != ev.LD_CommonMuons().accepted.end();
	  i++ ) {
  
      // default adding all leptons
      ///  HTlep+=(**i).Pt();
      // +++++++++++++++++++

      // update for Z events, taking leadin mu

      if( ev.LD_CommonMuons().accepted.size()==1) HTlep+=(**i).Pt();
      if( ev.LD_CommonMuons().accepted.size()==2){ 
	HTlep = ev.LD_CommonMuons().accepted.at(1)->Pt() + (ev.PFMET()+(*(ev.LD_CommonMuons().accepted.at(0)))).Pt();
	break;
      }
  }
  //cout << "finally HT lep is : " << HTlep << endl;
  if( mSumPTlepUP < 0) return (HTlep > mSumPTlep);
  return (HTlep > mSumPTlep&&HTlep < mSumPTlepUP);
 
}

std::ostream& SumPTlepCut::Description(std::ostream &ostrm) {
  ostrm <<mSumPTlep<< " > HTlep > " << mSumPTlep << " GeV ";
  return ostrm;
}

  MuonCheck::MuonCheck()
  {;}

  bool MuonCheck::Process(Event::Data & ev) {
    

  std::vector <Event::Lepton const *> theRECOLepton;
  
   if(ev.LD_CommonMuons().accepted.size()>0)
     {
       theRECOLepton = ev.LD_CommonMuons().accepted;
     }
   else return false;

   int indexMin=-1;
   float Drmin = 1000;

   for(int i = 0 ; i<ev.secMuonP4()->size(); i++)
     {
       int iM  = (theRECOLepton.at(0))->GetIndex();

       if( fabs(ROOT::Math::VectorUtil::DeltaR ((ev.secMuonP4()->at(i)),*(theRECOLepton.at(0) )))<Drmin){
	 Drmin=fabs(ROOT::Math::VectorUtil::DeltaR ((ev.secMuonP4()->at(i)),*(theRECOLepton.at(0) )));
	 indexMin = i;
       }

       //   if(fabs(ev.secMuonP4()->at(0).Pt()-ev.muonP4()->at(iM).Pt())/ev.muonP4()->at(iM).Pt()>0.2) return false;
       //    try{
       //    if(ev.muonGlobalTrackPTsigma()->at(iM)/((theRECOLepton.at(0))->Pt()*(theRECOLepton.at(0))->Pt())<0.001);	  return true;
       //     }
       //     catch(std::invalid_argument & e) {}
       // return true;
     }
   if(indexMin==-1) return false;
   if(fabs(ev.secMuonP4()->at(indexMin).Pt()-theRECOLepton.at(0)->Pt())/theRECOLepton.at(0)->Pt()>0.2) return false;
   return true;
   /*
   if(ev.secMuonP4()->size()>0)
     {
       int iM  = (theRECOLepton.at(0))->GetIndex();

       if( fabs(ROOT::Math::VectorUtil::DeltaR ((ev.secMuonP4()->at(0)),*(theRECOLepton.at(0) )))>0.001) return false;
       if(fabs(ev.secMuonP4()->at(0).Pt()-ev.muonP4()->at(iM).Pt())/ev.muonP4()->at(iM).Pt()>0.2) return false;
       //    try{
       //    if(ev.muonGlobalTrackPTsigma()->at(iM)/((theRECOLepton.at(0))->Pt()*(theRECOLepton.at(0))->Pt())<0.001);	  return true;
       //     }
       //     catch(std::invalid_argument & e) {}
       return true;
     }

   */   
}

std::ostream& MuonCheck::Description(std::ostream &ostrm) {
  ostrm << " Checks if muon is also PFMuon "  ;
  return ostrm;
}

  PFMETCutBin::PFMETCutBin(float metVal,float METvalueUP) :
    mMETvalue(metVal),mMETvalueUP(METvalueUP) {}

  PFMETCutBin::~PFMETCutBin() {}

  bool PFMETCutBin::Process(Event::Data & ev) {
    if (mMETvalueUP<0) return (ev.PFMET().Pt()>mMETvalue);
    if (ev.PFMET().Pt()>mMETvalue&&ev.PFMET().Pt()<mMETvalueUP) return true;
    return false;
  }

  std::ostream& PFMETCutBin::Description(std::ostream &ostrm) {
    ostrm << mMETvalueUP << "> PF METCut > " << mMETvalue << " GeV): ";
    return ostrm;
  }


  HTPTCut::HTPTCut(float sumPt,float sumPtUp)
    : mHTPTCutVal(sumPt), mHTPTCutValUp(sumPtUp)
{;}

bool HTPTCut::Process(Event::Data & ev) {

  float HTPT=0;

   if (ev.JD_CommonJets().accepted.size()>=1) {
	for (std::vector<Event::Jet const *>::const_iterator j=ev.JD_CommonJets().accepted.begin();
	     j!=ev.JD_CommonJets().accepted.end(); j++) {
	  HTPT+=(**j).Pt();
	}
      }
   if (mHTPTCutValUp<=0) return (mHTPTCutVal < HTPT);
   return (mHTPTCutVal < HTPT&& mHTPTCutValUp > HTPT);
}

std::ostream& HTPTCut::Description(std::ostream &ostrm) {
  ostrm << "HTlep > " << mHTPTCutVal << " GeV ";
  return ostrm;
}

  HTthrustCut::HTthrustCut(float sumPt,float sumPtUp)
    : mHTthrustCutVal(sumPt), mHTthrustCutValUp(sumPtUp)
{;}

bool HTthrustCut::Process(Event::Data & ev) {

  ThrustStuff thrust = ev.CommonThrustStuff();
  float HTthrust=thrust.HTFmin;
  if (mHTthrustCutValUp<=0) return (mHTthrustCutVal < HTthrust);
  return (mHTthrustCutVal < HTthrust&& mHTthrustCutValUp > HTthrust);
}

std::ostream& HTthrustCut::Description(std::ostream &ostrm) {
  ostrm << "HT thrust minor > " << mHTthrustCutVal << " GeV ";
  return ostrm;
}


//================
// HTlep cut
//================

HTlepCut::HTlepCut(float sumEt)
  : mHTlepCutVal(sumEt)
{;}

bool HTlepCut::Process(Event::Data & ev) {

  float HTlep=ev.CommonHT(); // so far only hadronic HT

  //  cout << "HT lep is : " << HTlep << " and the HT " << ev.CommonHT() <<  endl;
  for ( std::vector<Event::Lepton const *>::const_iterator i = ev.LD_CommonElectrons().accepted.begin();
	i != ev.LD_CommonElectrons().accepted.end();
	i++ ) {

    HTlep+=(**i).Pt();
  }
  //cout << " and now HT lep is : " << HTlep << endl;
  // Muons
  for ( std::vector<Event::Lepton const *>::const_iterator i = ev.LD_CommonMuons().accepted.begin();
	i != ev.LD_CommonMuons().accepted.end();
	i++ ) {
    HTlep+=(**i).Pt();
  }
  //cout << "finally HT lep is : " << HTlep << endl;
  return (HTlep > mHTlepCutVal);
}

std::ostream& HTlepCut::Description(std::ostream &ostrm) {
  ostrm << "HTlep > " << mHTlepCutVal << " GeV ";
  return ostrm;
}

  //================
  // PF LP Cut
  //================
  PFLPCut::PFLPCut(float LPVal) :
    mLPvalue(LPVal) {}

  PFLPCut::~PFLPCut() {}

  bool PFLPCut::Process(Event::Data & ev) {

    LorentzV mht(0,0,0,0);
    LorentzV lep(0,0,0,0);
    int lepNO=0;
    if (ev.LD_CommonMuons().accepted.size() ){
      mht =  ev.PFMET() + *(ev.LD_CommonMuons().accepted[0]);
      lep =  *(ev.LD_CommonMuons().accepted[0]);
      lepNO++;
    }
    if (ev.LD_CommonElectrons().accepted.size() ){
      mht = ev.PFMET() + *(ev.LD_CommonElectrons().accepted[0]);
      lep =  *(ev.LD_CommonElectrons().accepted[0]);
      lepNO++;
    }
    if(lepNO!=1)  return false;
    if (mLPvalue>0){
    if (ev.LP(&lep,&mht)<mLPvalue) return true;
    }
    // if LP cut <0, the
    if (mLPvalue<0){
      if (ev.LP(&lep,&mht)>-mLPvalue) return true;
    }
    return false;
  }

  std::ostream& PFLPCut::Description(std::ostream &ostrm) {
    ostrm << "PF LPCut> " << mLPvalue << " ";
    return ostrm;
  }

  /*
 //================
  // PF LP Cut
  //================
  PFLPWPTCut::PFLPWPTCut(float LPVal) :
    mLPvalue(LPVal) {}

  PFLPWPTCut::~PFLPWPTCut() {}

  bool PFLPWPTCut::Process(Event::Data & ev) {

    LorentzV mht(0,0,0,0);
    LorentzV lep(0,0,0,0);
    int lepNO=0;
    if (ev.LD_CommonMuons().accepted.size() ){
      mht =  ev.PFMET() + *(ev.LD_CommonMuons().accepted[0]);
      lep =  *(ev.LD_CommonMuons().accepted[0]);
      lepNO++;
    }
    if (ev.LD_CommonElectrons().accepted.size() ){
      mht = ev.PFMET() + *(ev.LD_CommonElectrons().accepted[0]);
      lep =  *(ev.LD_CommonMuons().accepted[0]);
      lepNO++;
    }
    if(lepNO!=1)  return false;
  

 
    if ((-(ev.LP(&lep,&mht)-1))*ev.PFMET().Pt()>mLPvalue) return true;
    
    return false;
  }

  std::ostream& PFLPWPTCut::Description(std::ostream &ostrm) {
    ostrm << "PF LPCut> " << mLPvalue << " ";
    return ostrm;
  }

  */


 //================
  // PF Meff Cut
  //================
  PFMeffWCut::PFMeffWCut(const std::string & comparison,float MeffVal) :
    mMeffVal(MeffVal) {
    if(strcmp(">",comparison.c_str())) mcomparison=true;
      if(strcmp("<",comparison.c_str()))  mcomparison=false;
}

  PFMeffWCut::~PFMeffWCut() {}

  bool PFMeffWCut::Process(Event::Data & ev) {

    LorentzV  mht = ev.PFMET();

    if (ev.LD_CommonMuons().accepted.size() ){
      mht += *(ev.LD_CommonMuons().accepted[0]);

    }
    if (ev.LD_CommonElectrons().accepted.size() ){
      mht += *(ev.LD_CommonElectrons().accepted[0]);
    }


    if( mcomparison && ev.CommonHT()+mht.Pt()<mMeffVal) return true;
      if( !mcomparison && ev.CommonHT()+mht.Pt()>mMeffVal) return true;

    return false;
  }

  std::ostream& PFMeffWCut::Description(std::ostream &ostrm) {
    ostrm << "PFMeffWCut "<< mMeffVal << " ";
    return ostrm;
  }



//================
  // PFMET Cut
  //================
  PFMHTCut::PFMHTCut(float metVal) :
    mMHTvalue(metVal) {}

  PFMHTCut::~PFMHTCut() {}

  bool PFMHTCut::Process(Event::Data & ev) {
    double mht=99999999.;

    if (ev.LD_CommonMuons().accepted.size() ){
      mht =  (ev.PFMET() + *(ev.LD_CommonMuons().accepted[0])).Pt();
    }

    if (ev.LD_CommonElectrons().accepted.size() ){
      mht =  (ev.PFMET() + *(ev.LD_CommonElectrons().accepted[0])).Pt();
    }

    if (mht>mMHTvalue) return true;
    return false;
  }

  std::ostream& PFMHTCut::Description(std::ostream &ostrm) {
    ostrm << "PF MHTCut> " << mMHTvalue << " GeV): ";
    return ostrm;
  }


  //================                                                                                                                                                                        
  // PFMHT Cut - mu channel                                                                                                                                                              
              
  //================                                                                                                                                                                      

  mPFMHTCut::mPFMHTCut(float metVal) :
    mMHTvalue(metVal) {}

  mPFMHTCut::~mPFMHTCut() {}

  bool mPFMHTCut::Process(Event::Data & ev) {

    double mht=99999999.;

    if (ev.LD_CommonMuons().accepted.size() ){
      mht =  (ev.PFMET() + *(ev.LD_CommonMuons().accepted[0])).Pt();
    }

    if (mht>mMHTvalue) return true;
    return false;
  }

  std::ostream& mPFMHTCut::Description(std::ostream &ostrm) {
    ostrm << "PF MHTCut (mu-channel) > " << mMHTvalue << " GeV): ";
    return ostrm;
  }

  //================                                                                                                                                                                      

  GridPointSelect::GridPointSelect(float M0,float M12 ) :
    M0_(M0),M12_(M12) {}

  bool GridPointSelect::Process(Event::Data & ev) {

    float aM0=0;
    if(ev.M0.enabled()){
      aM0 = ev.M0();
    }
    float aM12=0;
    if(ev.M12.enabled()){
      aM12 = ev.M12();
    }
    if(aM12==M12_&&aM0==M0_) return true;
    else return false;
  }

  std::ostream& GridPointSelect::Description(std::ostream &ostrm) {
    ostrm << "GridPointSelect M12=" << M12_ << ", M0= "<< M0_;
    return ostrm;
  }


  //================
  // MuJet Veto Cut
  //================
  MuJetVeto::MuJetVeto(float mhtVal) :
    mMuJetVetoVal(mhtVal) {}

  //  MuJetVeto::~MuJetVeto() {}

  bool MuJetVeto::Process(Event::Data & ev) {

    if ( ev.LD_CommonMuons().accepted.size() ) {

      //      float dRmin=999.;
      if (ev.JD_CommonJets().accepted.size()>=1) {
	for (std::vector<Event::Jet const *>::const_iterator j=ev.JD_CommonJets().accepted.begin();
	     j!=ev.JD_CommonJets().accepted.end(); j++) {

	  double dR=fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.LD_CommonMuons().accepted[0]), **j));

	  if (dR<mMuJetVetoVal) { return false; }
	}
      }


    }

    return true;
  }

  std::ostream& MuJetVeto::Description(std::ostream &ostrm) {
    ostrm << "DR(mu-jet) Veto > " << mMuJetVetoVal;
    return ostrm;
  }

  UpperMuPtCut::UpperMuPtCut( float cut )
    : cut_(cut)
  {;}

  // -----------------------------------------------------------------------------
  //
  bool UpperMuPtCut::Process( Event::Data& ev ) {

    if (ev.LD_CommonMuons().accepted.size()) {
      return ev.LD_CommonMuons().accepted.at(0)->Pt() <= cut_;
    }

    return true;
  }
  // -----------------------------------------------------------------------------
  //
  std::ostream& UpperMuPtCut::Description( std::ostream &ostrm ) {
    ostrm << "upper muon PT < " << cut_ << " " ;
    return ostrm;
  }

  UpperElePtCut::UpperElePtCut( float cut )
    : cut_(cut)
  {;}

  // -----------------------------------------------------------------------------
  //
  bool UpperElePtCut::Process( Event::Data& ev ) {

    if (ev.LD_CommonElectrons().accepted.size()) {
      return ev.LD_CommonElectrons().accepted.at(0)->Pt() <= cut_;
    }

    return true;
  }
  // -----------------------------------------------------------------------------
  //
  std::ostream& UpperElePtCut::Description( std::ostream &ostrm ) {
    ostrm << "upper electron PT < " << cut_ << " " ;
    return ostrm;
  }


  UnCorLeadCut::UnCorLeadCut( float cut )
    : cut_(cut)
  {;}

  // -----------------------------------------------------------------------------
  //
  bool UnCorLeadCut::Process( Event::Data& ev ) {
    if ( ev.JD_CommonJets().accepted.size() < 1  ) { return false; }

    int leadIndex = 0;
    if (ev.JD_CommonJets().accepted.size()>1) {

      if (ev.JD_CommonJets().accepted[1]->Pt()/ev.JD_CommonJets().accepted[1]->correction()>ev.JD_CommonJets().accepted[0]->Pt()/ev.JD_CommonJets().accepted[0]->correction()) leadIndex = 1;
    }

    if (ev.JD_CommonJets().accepted[leadIndex]->Pt() < cut_){ return false;}

    return true;
  }
  // -----------------------------------------------------------------------------
  //
  std::ostream& UnCorLeadCut::Description( std::ostream &ostrm ) {
    ostrm << "leadin uncorrected jet cut; cor PT > " << cut_ << " " ;
    return ostrm;
  }

  //================
  // Cut on AlphaT from LeptonicObjects
  //================

  LeptonicAlphaTCut::LeptonicAlphaTCut(float AlphaTCut) :
    mAlphaTCut(AlphaTCut) {}

  LeptonicAlphaTCut::~LeptonicAlphaTCut() {}

  bool LeptonicAlphaTCut::Process(Event::Data & ev) {
    if ( ev.LeptonicObjects().size() >= 1 &&
	 ev.LeptonicObjects().size() <= Event::KS_MinDEt_MaxN() ) {
      if ( ev.LeptonicAlphaT() > mAlphaTCut ) return true;
    }
    return false;
  }

  std::ostream& LeptonicAlphaTCut::Description(std::ostream &ostrm) {
    ostrm << "LeptonicAlphaTCut " ;
    return ostrm;
  }



 //================
  // Cut on AlphaT from LeptonicObjects
  //================

  GenNumberLepCut::GenNumberLepCut(int NoLep) :
    mNoLep(NoLep) {}

  GenNumberLepCut::~GenNumberLepCut() {}

  bool GenNumberLepCut::Process(Event::Data & ev) {

    GenMatrixBin myGenMatrixBin(&ev);
    // int aNTau = myGenMatrixBin.the_GenTau.size();
    // int aNMuon = myGenMatrixBin.the_GenMuon.size();
    // int aNEli = myGenMatrixBin.the_GenEli.size();
    // int aNLepton = aNTau+aNMuon+aNEli;
  
    int aNMuon = myGenMatrixBin.the_GenMuonExtra.size();
    int aNEli = myGenMatrixBin.the_GenElectronExtra.size();
    int aNLepton = aNMuon+aNEli;
    if(mNoLep==3)
      {
	int muEliSum = myGenMatrixBin.the_GenMuon.size()+myGenMatrixBin.the_GenEli.size();
	if(myGenMatrixBin.the_GenTau.size()==1&&muEliSum==1)	  return true;
	if(myGenMatrixBin.the_GenTau.size()==2)	  return true;
	else return false;
      }
    if(mNoLep==4)
      {
	int muEliSum = myGenMatrixBin.the_GenMuon.size()+myGenMatrixBin.the_GenEli.size();
	if(myGenMatrixBin.the_GenTau.size()==2)	  return true;
	return false;
      }

    if(aNLepton==mNoLep) return true;

    return false;
  }

  std::ostream& GenNumberLepCut::Description(std::ostream &ostrm) {
    ostrm << "GenNumberLepCut: number of gen lepton (elerton or muon) is equal to "<< mNoLep;
    return ostrm;
  }






  PrintAlphaTEvents::PrintAlphaTEvents() {}

  PrintAlphaTEvents::~PrintAlphaTEvents() {}

  bool PrintAlphaTEvents::Process(Event::Data & ev) {
    if ( ev.LeptonicObjects().size() >= 1 &&
	 ev.LeptonicObjects().size() <= Event::KS_MinDEt_MaxN() ) {

	if(ev.JD_CommonJets().accepted.size() > 0){
	  if ( ev.LeptonicAlphaT() > 0.55 ){
 if(ev.LD_CommonElectrons().accepted.size() > 0){

	   cout << "An electron event has passed aT! It is event number " << ev.EventNumber() << " from Run Number " << ev.RunNumber() << " and LumiSection " << ev.LumiSection() << endl;
 cout << "It has the following characteristics: " << endl;
   ev.PrintStableVisRec();
   cout << "In addition, it has:   HT : " << (ev.CommonHT() + ev.LD_CommonElectrons().accepted.at(0)->Pt()) << " and AlphaT " << ev.LeptonicAlphaT() << " and MHT : " <<  (ev.CommonHT() + ev.LD_CommonElectrons().accepted.at(0)->Pt()+ev.PFMET().Pt()) << " and MHT " << (ev.PFMET().Pt()+ev.LD_CommonElectrons().accepted.at(0)->Pt()) << endl;


 }
 if(ev.LD_CommonMuons().accepted.size() > 0){

	   cout << "A muon event has passed aT! It is event number " << ev.EventNumber() << " from Run Number " << ev.RunNumber() << " and LumiSection " << ev.LumiSection() << endl;
 cout << "It has the following characteristics: " << endl;
   ev.PrintStableVisRec();
   cout << "In addition, it has:   HT : " << (ev.CommonHT() + ev.LD_CommonMuons().accepted.at(0)->Pt()) << " and AlphaT " << ev.LeptonicAlphaT() << " and MHT : " <<  (ev.CommonHT() + ev.LD_CommonMuons().accepted.at(0)->Pt()+ev.PFMET().Pt()) << " and MHT " << (ev.PFMET().Pt()+ev.LD_CommonMuons().accepted.at(0)->Pt()) << endl;


 }
	  }
	}
    }
    return true;
  }

  std::ostream& PrintAlphaTEvents::Description(std::ostream &ostrm) {
    ostrm << "Printed interesting events: " ;
    return ostrm;
  }





  // --------------------
  // NumOfLooseElectrons

  NumOfLooseElectrons::NumOfLooseElectrons(const std::string & comparison, int numOfLooseEls) :
    mNumOfLooseEls(numOfLooseEls) {
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

  NumOfLooseElectrons::~NumOfLooseElectrons() {}


  bool NumOfLooseElectrons::Process(Event::Data & ev) {

    int numOfLooseEls = 0;
    for (std::vector<Lepton>::const_iterator iEl = ev.LD_Electrons().begin();
         iEl != ev.LD_Electrons().end();
         ++iEl) {

	bool isCommon = false;
	for (std::vector<Lepton const *>::const_iterator iCommonEli =ev.LD_CommonElectrons().accepted.begin(); iCommonEli != ev.LD_CommonElectrons().accepted.end(); ++iCommonEli)
	  {
	    if(iEl->GetIndex()==(*iCommonEli)->GetIndex()) isCommon = true;
	  }
	
      if (!isCommon && isLooseElectron(&*iEl)) numOfLooseEls++;

    } // end of looping over the "raw" electrons

    return (*mComparison)(numOfLooseEls,mNumOfLooseEls);
  } // end of bool

  std::ostream& NumOfLooseElectrons::Description(std::ostream &ostrm) {
    ostrm << "NumOfLooseElectrons " << mComparison->type();
    ostrm << " " << mNumOfLooseEls;
    return ostrm;
  }


  // ---------------
  // NumOfLooseMuons

  NumOfLooseMuons::NumOfLooseMuons(const std::string & comparison, int numOfLooseMus) :
    mNumOfLooseMus(numOfLooseMus) {
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
 
  NumOfLooseMuons::~NumOfLooseMuons() {}

  bool NumOfLooseMuons::Process(Event::Data & ev) {

    int numOfLooseMus = 0;
    for (std::vector<Lepton>::const_iterator iMu = ev.LD_Muons().begin();
         iMu != ev.LD_Muons().end();
         ++iMu)
      {	
	if ( ( ((*iMu).Pt()>10.) && (fabs((*iMu).Eta())<2.5) ) &&
	     ( (*iMu).GetCombIsolation() < 0.2 )               &&
	     ( ev.IsMuonGlobal((*iMu).GetIndex()) )
	     )
	  {
	    // check is loose muon is also common muon
	    bool isCommon = false;
	    for (std::vector<Lepton const *>::const_iterator iCommonMu =ev.LD_CommonMuons().accepted.begin(); iCommonMu != ev.LD_CommonMuons().accepted.end(); ++iCommonMu)
	      {
		if(iMu->GetIndex()==(*iCommonMu)->GetIndex()) isCommon = true;
	      }
	    if(!isCommon) numOfLooseMus++;
	  } // end of loose definition
	
      } // end of looping over the "raw" muons
    
    return (*mComparison)(numOfLooseMus,mNumOfLooseMus);
  } // end of bool

  std::ostream& NumOfLooseMuons::Description(std::ostream &ostrm) {
    ostrm << "NumOfLooseMuons " << mComparison->type();
    ostrm << " " << mNumOfLooseMus;
    return ostrm;
  }



  // ---------------
  // NumOfLooseMuons

  NumOfLooseMuonsRA4::NumOfLooseMuonsRA4(const std::string & comparison, int numOfLooseMus) :
    mNumOfLooseMus(numOfLooseMus) {
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
 

  NumOfLooseMuonsRA4::~NumOfLooseMuonsRA4() {}

  bool NumOfLooseMuonsRA4::Process(Event::Data & ev) {

    int numOfLooseMus = 0;
    for (std::vector<Lepton>::const_iterator iMu = ev.LD_Muons().begin();
         iMu != ev.LD_Muons().end();
         ++iMu)
      {	


      try {
  // new definition - 2011

	if ( 
	    ( ((*iMu).Pt()>15.) && (fabs((*iMu).Eta())<2.5) ) &&
	    ( (*iMu).GetCombIsolation() < 0.15 )               &&
	    (ev.IsGlobalMuonPromptTight(iMu->GetIndex())) &&
	    ( ( fabs(ev.muonInnerTrackVertexz()->at(iMu->GetIndex()) - (ev.GetvertexPosition(0).Z())) ) < 1. ) &&
	      fabs(ev.GetMuonInnerTrackDxyBS(iMu->GetIndex())) < 0.1
	    )
	  {
	    // check is loose muon is also common muon
	    bool isCommon = false;
	    for (std::vector<Lepton const *>::const_iterator iCommonMu =ev.LD_CommonMuons().accepted.begin(); iCommonMu != ev.LD_CommonMuons().accepted.end(); ++iCommonMu)
	      {
		if(iMu->GetIndex()==(*iCommonMu)->GetIndex()) isCommon = true;
	      }
	    if(!isCommon) numOfLooseMus++;
	  } // end of loose definition
      

      }

  catch (std::invalid_argument & e)
    {
      // old definition - 2010
      if( 
	 ( ((*iMu).Pt()>15.) && (fabs((*iMu).Eta())<2.5) ) &&
	 ( (*iMu).GetCombIsolation() < 0.15 )               &&
	 (ev.IsGlobalMuonPromptTight(iMu->GetIndex())) &&
	 fabs(ev.GetMuonInnerTrackDz(iMu->GetIndex()))  < 1.  &&
	 fabs(ev.GetMuonInnerTrackDxyBS(iMu->GetIndex())) < 0.1
	 )
	{
	  // check is loose muon is also common muon
	  bool isCommon = false;
	  for (std::vector<Lepton const *>::const_iterator iCommonMu =ev.LD_CommonMuons().accepted.begin(); iCommonMu != ev.LD_CommonMuons().accepted.end(); ++iCommonMu)
	    {
	      if(iMu->GetIndex()==(*iCommonMu)->GetIndex()) isCommon = true;
	    }
	  if(!isCommon) numOfLooseMus++;
	  // end of loose definition
	  
	}
      
    } 
      }
    
    
    // end of looping over the "raw" muons
    
    return (*mComparison)(numOfLooseMus,mNumOfLooseMus);
  } // end of bool


  std::ostream& NumOfLooseMuonsRA4::Description(std::ostream &ostrm) {
    ostrm << "NumOfLooseMuons " << mComparison->type();
    ostrm << " " << mNumOfLooseMus;
    return ostrm;
  }







  // --------------------
  // NumOfLooseElectronsRA4

  NumOfLooseElectronsRA4::NumOfLooseElectronsRA4(const std::string & comparison, int numOfLooseEls,
						 const Utils::ParameterSet & ps, const std::string & prefix) :
  mPtMin(ps.Get<double>("PtMin")),
  mIso(ps.Get<int>("Isolation")),
  mHoE(ps.Get<int>("HoverE")),
  mDeltaEta(ps.Get<int>("DeltaEtaAtVtx")),
  mDeltaPhi(ps.Get<int>("DeltaPhiAtVtx")),
  mShh(ps.Get<int>("SigmaIEtaIEta")),
  mConv(ps.Get<int>("Conversions")),
  mRelCombIsoBarrel(ps.Get<double>(prefix+".RelCombIso.Barrel")),
  mRelCombIsoEndcap(ps.Get<double>(prefix+".RelCombIso.Endcap")),
  mTrkIsoBarrel(ps.Get<double>(prefix+".TrkIso.Barrel")),
  mTrkIsoEndcap(ps.Get<double>(prefix+".TrkIso.Endcap")),
  mEcalIsoBarrel(ps.Get<double>(prefix+".EcalIso.Barrel")),
  mEcalIsoEndcap(ps.Get<double>(prefix+".EcalIso.Endcap")),
  mHcalIsoBarrel(ps.Get<double>(prefix+".HcalIso.Barrel")),
  mHcalIsoEndcap(ps.Get<double>(prefix+".HcalIso.Endcap")),
  mHoEBarrel(ps.Get<double>(prefix+".HoverE.Barrel")),
  mHoEEndcap(ps.Get<double>(prefix+".HoverE.Endcap")),
  mDeltaPhiBarrel(ps.Get<double>(prefix+".DeltaPhi.Barrel")),
  mDeltaPhiEndcap(ps.Get<double>(prefix+".DeltaPhi.Endcap")),
  mDeltaEtaBarrel(ps.Get<double>(prefix+".DeltaEta.Barrel")),
  mDeltaEtaEndcap(ps.Get<double>(prefix+".DeltaEta.Endcap")),
  mSigmaIEtaIEtaBarrel(ps.Get<double>(prefix+".SigmaIEtaIEta.Barrel")),
  mSigmaIEtaIEtaEndcap(ps.Get<double>(prefix+".SigmaIEtaIEta.Endcap")),
  mDCot(ps.Get<double>(prefix+".Conversions.DCot")),
  mDist(ps.Get<double>(prefix+".Conversions.Dist")),
  mMissingHits(ps.Get<int>(prefix+".Conversions.MissingHits")),
  mSupressErrors(ps.Contains("SupressErrors") ? ps.Get<int>("SupressErrors") : false),
  mCorrEEMisalig(ps.Contains("CorrEEMisalig") ? ps.Get<int>("CorrEEMisalig") : false),
  mD0BS(ps.Get<double>("D0BS")),
  mNumOfLooseEls(numOfLooseEls) {
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


  NumOfLooseElectronsRA4::~NumOfLooseElectronsRA4() {}

  void NumOfLooseElectronsRA4::Start(Event::Data & ev) {}

  //Based on Paolo Meridiani's corrections
  float NumOfLooseElectronsRA4::dPhiCorr(double elePhi , double eleEta){
    double C, D, A;
    if (eleEta>1.479){
      C = 0.0;  D = 0.52; A = 2.17;
    }
    else if (eleEta<-1.479){
      C = 0.0; D = 0.45; A = -1.58;
    }
    else return 0;
    return C + (D/325.)*sinh(eleEta)*sin(A-elePhi);
  }


  float NumOfLooseElectronsRA4::dEtaCorr(double elePhi , double eleEta){
    double C, DZ, D, A;
    if (eleEta>1.479){
      C = 0.0013; DZ = -0.06; D = 0.52; A = 2.17;
    }
    else if (eleEta<-1.479){
      C = -0.0013; DZ = -0.32; D = 0.45; A = -1.58;
    }
    else return 0;
    return C + (tanh(eleEta)/325.)*(DZ-D*sinh(eleEta)*cos(elePhi-A));
  }


  bool NumOfLooseElectronsRA4::Process(Event::Data & ev) {

    bool passPtMin = false;
    bool passIso = false;
    bool passHoE = false;
    bool passDeltaEta = false; bool passDeltaPhi = false;
    bool passShh = false;
    bool passConv = false;
    bool passExtra = false;
    
    int numOfLooseEls = 0;
    for (std::vector<Lepton>::const_iterator iEl = ev.LD_Electrons().begin();
         iEl != ev.LD_Electrons().end();
         ++iEl) {

      int iM = (iEl)->GetIndex();


      bool isCommon = false;
      for (std::vector<Lepton const *>::const_iterator iCommonEli =ev.LD_CommonElectrons().accepted.begin(); iCommonEli != ev.LD_CommonElectrons().accepted.end(); ++iCommonEli)
	{
	  if(iEl->GetIndex()==(*iCommonEli)->GetIndex()) isCommon = true;
	}
     
    if (isCommon) continue;
    if ((iEl)->Pt()<mPtMin)  continue;
    if (fabs((iEl)->Eta())>2.5)  continue;

    try{
      passConv = (fabs(ev.GetElectronDCot(iM)) > mDCot || fabs(ev.GetElectronDist(iM)) > mDist);
      passConv &= (ev.GetElectronGsfTrackTrackerExpectedHitsInner(iM) <= mMissingHits);
    }
    catch(std::invalid_argument & e){
      
      if(!mSupressErrors) throw e;
    }
    

    // Barrel
    if (fabs(ev.GetElectronESuperClusterEta(iM)) < 1.4442) {
     
      passIso = ( (((iEl->GetTrkIsolation()) + max(0., iEl->GetEcalIsolation()-1.) + iEl->GetHcalIsolation())/(iEl->Pt())) < mRelCombIsoBarrel );
      passHoE = ( ev.GetElectronHoE(iM) < mHoEBarrel );
      passDeltaPhi = ( fabs(ev.GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiBarrel );
      passDeltaEta = ( fabs(ev.GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaBarrel );
      passShh = ( ev.GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaBarrel );

    }

    // End-caps    
    else if ( (fabs(ev.GetElectronESuperClusterEta(iM)) > 1.566) && (fabs(ev.GetElectronESuperClusterEta(iM)) < 2.5) ) {

      passIso = ( iEl->GetCombIsolation() < mRelCombIsoEndcap );
      passHoE = ( ev.GetElectronHoE(iM) < mHoEEndcap );
      if (mCorrEEMisalig){
	passDeltaPhi = ( fabs(ev.GetElectronDeltaPhiAtVtx(iM)-dPhiCorr(iEl->Phi(),iEl->Eta())) < mDeltaPhiEndcap ) ;
	passDeltaEta = ( fabs(ev.GetElectronDeltaEtaAtVtx(iM)-dEtaCorr(iEl->Phi(),iEl->Eta())) < mDeltaEtaEndcap);
      }
      else{
	passDeltaPhi = ( fabs(ev.GetElectronDeltaPhiAtVtx(iM)) < mDeltaPhiEndcap );
	passDeltaEta = ( fabs(ev.GetElectronDeltaEtaAtVtx(iM)) < mDeltaEtaEndcap);
      }
      passShh = ( ev.GetElectronSigmaIetaIeta(iM) < mSigmaIEtaIEtaEndcap );
      
    }
      
      
    try {
      // 2011 definition
      if (
	  ( fabs(ev.GetElectronD0BS(iM)) < mD0BS) &&
	  ( fabs(ev.electronGsfTrackVertexz()->at(iM) - (ev.GetvertexPosition(0).Z())) < 1. )
	  ) { passExtra = true; }
    }
    catch (std::invalid_argument & e) {
      // 2010 definition
      if (
	  ( fabs(ev.GetElectronD0BS(iM)) < 0.02)
	  ) { passExtra = true; }
    }
    
    if (mIso==passIso && mHoE==passHoE && mDeltaEta==passDeltaEta && mDeltaPhi==passDeltaPhi && mShh==passShh && mConv == passConv && passExtra==true) { numOfLooseEls++; }
    
    
    } // end of looping over the "raw" electrons
    
    
    return (*mComparison)(numOfLooseEls,mNumOfLooseEls);
  } // end of bool

  std::ostream& NumOfLooseElectronsRA4::Description(std::ostream &ostrm) {
    ostrm << "NumOfLooseElectronsRA4 " << mComparison->type();
    ostrm << " " << mNumOfLooseEls;
    return ostrm;
  }





  PrintRunLSEvent::PrintRunLSEvent() {}

  PrintRunLSEvent::~PrintRunLSEvent() {}

  bool PrintRunLSEvent::Process(Event::Data & ev) {

    cout << ev.RunNumber() << ":" << ev.LumiSection() << ":" << ev.EventNumber() << "\n";

    return true;
  }

  std::ostream& PrintRunLSEvent::Description(std::ostream &ostrm) {
    ostrm << "Printed Run:LS:Event " ;
    return ostrm;
  }




} // end namespace

