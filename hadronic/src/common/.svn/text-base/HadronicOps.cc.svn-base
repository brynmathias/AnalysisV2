#include "HadronicOps.hh"
#include "AlphaT.hh"
#include <iostream>
#include <string>
#include "TString.h"
#include <fstream>
//#include "NLOTools.hh"
#include "Types.hh"
using namespace Operation;




// -----------------------------------------------------------------------------
//
gensignalProcessID::gensignalProcessID( int cut1 ,int cut2,int cut3,int cut4 )
  : cut1_(cut1),
  cut2_(cut2),
  cut3_(cut3),
  cut4_(cut4)
  {;}

// -----------------------------------------------------------------------------
//
bool gensignalProcessID::Process( Event::Data& ev ) {
  //  cout << " ev.gensignalProcessID() " << ev.gensignalProcessID() << " cut_1 " << cut1_ << " cut2 " << cut2_ << endl;
  if (( ev.gensignalProcessID() == cut1_) ||( ev.gensignalProcessID() == cut2_ ) || (ev.gensignalProcessID() == cut3_) || (ev.gensignalProcessID() == cut4_)) { return true; }
  return false;
}

// -----------------------------------------------------------------------------
//
std::ostream& gensignalProcessID::Description( std::ostream &ostrm ) {
  ostrm << "gensignalProcessID filterd for processes " << cut1_ << " or "  << cut2_ << " ";
  return ostrm;
}


//


//
genProcess::genProcess(std::string  cut_process ):
cut_process_(cut_process)
  {;}

// -----------------------------------------------------------------------------
//
bool genProcess::Process( Event::Data& ev ) {

  //  cout << " ev.genProcess() " << ev.genProcess() << " cut_1 " << cut1_ << " cut2 " << cut2_ << endl;

  // TString thisprocess = NLO::GetProcess(ev);
  // cout << " cut process " << cut_process_ << " this process " << thisprocess << endl;

  // if(thisprocess ==cut_process_)return true;
  // cout << " here " << endl;
  return false;
}

// -----------------------------------------------------------------------------
//
std::ostream& genProcess::Description( std::ostream &ostrm ) {
  ostrm << "genProcess filterd for processes " << cut_process_ << " ";
  return ostrm;
}


//



// -----------------------------------------------------------------------------
//
HadronicHT_SecondJetCut::HadronicHT_SecondJetCut(float Jet, float HT):
secondJetCut_(Jet),
  HTCut_(HT)
  {;}
// -----------------------------------------------------------------------------
//
bool HadronicHT_SecondJetCut::Process( Event::Data& ev){
  if(ev.JD_CommonJets().accepted.size()<2) return false;
  if( ev.CommonHT() > HTCut_ && ev.JD_CommonJets().accepted[1]->Pt()  > secondJetCut_){ return true; }
  else return false;
}

// -----------------------------------------------------------------------------
//
std::ostream& HadronicHT_SecondJetCut::Description( std::ostream &ostrm ) {
  ostrm << "Second Jet Pt  > " << secondJetCut_ << " Event HT > " << HTCut_ << " " ;
  return ostrm;
}




// -----------------------------------------------------------------------------
//
HadronicAlphaT::HadronicAlphaT( float cut )
  : cut_(cut)
  {;}

// -----------------------------------------------------------------------------
//
bool HadronicAlphaT::Process( Event::Data& ev ) {
  if ( ev.CommonObjects().size() < 2 ||
    ev.CommonObjects().size() > 50 ) { return false; }
  if ( AlphaT()( ev.CommonObjects() ) > cut_ ) { return true; }
  return false;
}

// -----------------------------------------------------------------------------
//
std::ostream& HadronicAlphaT::Description( std::ostream &ostrm ) {
  ostrm << "HadronicAlphaT " << cut_ << " " ;
  return ostrm;
}


//
MHTovHT::MHTovHT(float cut)
  : cut_(cut)
  {;}

bool MHTovHT::Process(Event::Data& ev){

  if(ev.CommonMHT().Pt()/ev.CommonHT() > cut_)return true;
  else return false;
}

//
std::ostream& MHTovHT::Description( std::ostream &ostrm ) {
  ostrm << " " << cut_ << " " ;
  return ostrm;
}

// -----------------------------------------------------------------------------
//
PFMET::PFMET(float cut)
  : cut_(cut)
  {;}

bool PFMET::Process(Event::Data& ev){
  if(ev.PFMET().Pt() > cut_)return true;
  else return false;
}

//
std::ostream& PFMET::Description( std::ostream &ostrm ) {
  ostrm << " " << cut_ << " " ;
  return ostrm;
}

// -----------------------------------------------------------------------------
//
ReversedPFMET::ReversedPFMET(float cut)
  : cut_(cut)
  {;}

bool ReversedPFMET::Process(Event::Data& ev){
  if(ev.PFMET().Pt() < cut_)return true;
  else return false;
}

//
std::ostream& ReversedPFMET::Description( std::ostream &ostrm ) {
  ostrm << " " << cut_ << " " ;
  return ostrm;
}
//-------------------------------------------------------------------

BabyMHT::BabyMHT(float cut)
  : cut_(cut)
  {;}

bool BabyMHT::Process(Event::Data& ev){
  if( ev.JD_CommonJets().babyHT.Pt() > cut_)return true;
  else return false;
}

//
std::ostream& BabyMHT::Description( std::ostream &ostrm ) {
  ostrm << " " << cut_ << " " ;
  return ostrm;
}

//-------------------------------------------------------------------

ReversedBabyMHT::ReversedBabyMHT(float cut)
  : cut_(cut)
  {;}

bool ReversedBabyMHT::Process(Event::Data& ev){
  if( ev.JD_CommonJets().babyHT.Pt() < cut_)return true;
  else return false;
}

//
std::ostream& ReversedBabyMHT::Description( std::ostream &ostrm ) {
  ostrm << " " << cut_ << " " ;
  return ostrm;
}

//-------------------------------------------------------------------

/*LowPtBiasedDphi::LowPtBiasedDphi(float cut)
: cut_(cut)
{;}

bool LowPtBiasedDphi::Process(Event::Data& ev){
if( ev.LowPtBiasedCommonRecoilMETJetDPhi() < cut_)return true;
else return false;
}

//
std::ostream& LowPtBiasedDphi::Description( std::ostream &ostrm ) {
ostrm << " " << cut_ << " " ;
return ostrm;
}
*/

//-------------------------------------------------------------------
MHToverMET::MHToverMET(float cut, float threshold)
  : cut_(cut),
  threshold_(threshold)
  {;}

bool MHToverMET::Process(Event::Data& ev){


  PolarLorentzV mHT(0.,0.,0.,0.);
  std::vector<Event::Jet const *>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
  std::vector<Event::Jet const *>::const_iterator jjet = ev.JD_CommonJets().accepted.end();
  std::vector<Event::Jet const *>::const_iterator ibaby = ev.JD_CommonJets().baby.begin();
  std::vector<Event::Jet const *>::const_iterator jbaby = ev.JD_CommonJets().baby.end();
  for(; ijet!=jjet; ++ijet){
    if( (*ijet)->Pt() > threshold_){
      mHT -= (**ijet);
    }
  }
  for( ; ibaby!=jbaby; ++ibaby){
    if( (*ibaby)->pt() > threshold_ ){
      mHT -= (**ibaby);
    }
  }

  LorentzV calomet = LorentzV(*ev.metP4caloTypeII());

  for(int i = 0; i < int(ev.LD_CommonElectrons().accepted.size());i++){
    calomet = calomet+(*ev.LD_CommonElectrons().accepted[i]);
  }
  for(int i = 0; i < int(ev.PD_CommonPhotons().accepted.size());i++){
    calomet = calomet+(*ev.PD_CommonPhotons().accepted[i]);
  }
  for(int i = 0; i < int(ev.LD_CommonMuons().accepted.size());i++){
    calomet = calomet+(*ev.LD_CommonMuons().accepted[i]);
  }



  if( mHT.Pt()/calomet.Pt()  < cut_)return true;
  else return false;
}

//
std::ostream& MHToverMET::Description( std::ostream &ostrm ) {
  ostrm << "Passing MHT over MET cut of: " << cut_ << " " ;
  return ostrm;
}
//
MHToverPFMET::MHToverPFMET(float cut)
  : cut_(cut)
  {;}

bool MHToverPFMET::Process(Event::Data& ev){
  return ( ev.CommonMHT().Pt()/ev.PFMET().Pt()  < cut_);
}

//
std::ostream& MHToverPFMET::Description( std::ostream &ostrm ) {
  ostrm << "Passing MHT over PF MET cut of: " << cut_ << " " ;
  return ostrm;
}


//-------------------------------------------------------------------




BabyMHTovHT::BabyMHTovHT(float cut)
  : cut_(cut)
  {;}

bool BabyMHTovHT::Process(Event::Data& ev){
  if( ev.JD_CommonJets().killedHT.Pt()/ev.CommonHT() > cut_)return true;
  else return false;
}

//
std::ostream& BabyMHTovHT::Description( std::ostream &ostrm ) {
  ostrm << " " << cut_ << " " ;
  return ostrm;
}


MHTOvCaloMETCut::MHTOvCaloMETCut(float cut)
  : cut_(cut)
  {;}

bool MHTOvCaloMETCut::Process(Event::Data& ev){

  LorentzV calomet = LorentzV(*ev.metP4caloTypeII());

  for(int i = 0; i < int(ev.LD_CommonElectrons().accepted.size());i++){
    calomet = calomet+(*ev.LD_CommonElectrons().accepted[i]);
  }
  for(int i = 0; i < int(ev.PD_CommonPhotons().accepted.size());i++){
    calomet = calomet+(*ev.PD_CommonPhotons().accepted[i]);
  }
  for(int i = 0; i < int(ev.LD_CommonMuons().accepted.size());i++){
    calomet = calomet+(*ev.LD_CommonMuons().accepted[i]);
  }

  if(ev.CommonMHT().Pt()/calomet.Pt() < cut_) return true;
  return false;

}

std::ostream& MHTOvCaloMETCut::Description(std::ostream &ostrm){
  ostrm << " (MHT)/CaloMET < " << cut_ << " " ;
  return ostrm;
}


//---------------------------------------------------------

MHTPFMETDiffOvMeffCut::MHTPFMETDiffOvMeffCut(float cut)
  : cut_(cut)
  {;}

bool MHTPFMETDiffOvMeffCut::Process(Event::Data& ev){



  if(ev.PD_CommonPhotons().accepted.size()==0&& ev.LD_CommonMuons().accepted.size()==0 && ev.LD_CommonElectrons().accepted.size()==0)
  {
    if((ev.CommonMHT().Pt()-ev.PFMET().Pt())/(ev.CommonMHT().Pt()+ev.CommonHT()) < cut_) return true;
  }

  // if there is a "common" photon in (photon control sample)
  if(ev.PD_CommonPhotons().accepted.size()==1)
  {
    if((ev.CommonMHT().Pt()-(ev.PFMET()+(*(ev.PD_CommonPhotons().accepted[0]))).Pt())/(ev.CommonMHT().Pt()+ev.CommonHT()) < cut_) return true;
  }

  // if there is a "common" photon in (photon control sample)
  if(ev.LD_CommonElectrons().accepted.size()==1)
  {
    if((ev.CommonMHT().Pt()-(ev.PFMET()+(*(ev.LD_CommonElectrons().accepted[0]))).Pt())/(ev.CommonMHT().Pt()+ev.CommonHT()) < cut_) return true;
  }

  // if there is a "common" muon in (photon control sample)
  if(ev.LD_CommonMuons().accepted.size()==1)
  {
    if((ev.CommonMHT().Pt()-(ev.PFMET()+(*(ev.LD_CommonMuons().accepted[0]))).Pt())/(ev.CommonMHT().Pt()+ev.CommonHT()) < cut_) return true;
  }

  return false;

}

std::ostream& MHTPFMETDiffOvMeffCut::Description(std::ostream &ostrm){
  ostrm << " (MHT-PFMET)/Meff < " << cut_ << " " ;
  return ostrm;
}

struct DrJetColl{
  double Dr;
  LorentzV Jet;
  DrJetColl(double Dr_, LorentzV& Jet_)
    : Dr(Dr_), Jet(Jet_) {}
};

struct sort_by_Dr
{
  bool operator () (const DrJetColl& lhs , const DrJetColl& rhs) // replace YourStruct
  {
    return lhs.Dr < rhs.Dr;
  }
};

DeadECALCut::DeadECALCut(float cut2,float cut,float minBiasCut,float minJetPtCut,int nBadCells,bool deadECALFromFile,TString deadECALfile):cut2_(cut2),cut_(cut),minBiasCut_(minBiasCut),minJetPtCut_(minJetPtCut),nBadCells_(nBadCells),deadECALFromFile_(deadECALFromFile),deadECALfile_(deadECALfile){;}

bool DeadECALCut::Process(Event::Data& ev) {

  std::vector<LorentzV> jets;
  std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
  std::vector<Event::Jet const*>::const_iterator jjet = ev.JD_CommonJets().accepted.end();
  for ( ; ijet != jjet; ++ijet ) { jets.push_back(**ijet); }

  std::vector<LorentzV> baby;
  std::vector<Event::Jet const*>::const_iterator ibaby = ev.JD_CommonJets().baby.begin();
  std::vector<Event::Jet const*>::const_iterator jbaby = ev.JD_CommonJets().baby.end();
  for ( ; ibaby != jbaby; ++ibaby ) { baby.push_back(**ibaby); }

  return Process( ev, jets, baby );

}

bool DeadECALCut::Process( Event::Data& ev,
         std::vector<LorentzV>& jets,
         std::vector<LorentzV>& baby ) {

  // cout << " +++++++++++++++++++START DEAD ECAL CUT++++++++++++++ " << endl;
  double minDeltaEta = 100.;
  float deadECALDR = 10.;
  PolarLorentzV mHT(0.,0.,0.,0.);

  std::vector<LorentzV> newJetCollection;
  std::vector<DrJetColl> biasDPhiList;

  std::vector<LorentzV>::const_iterator ijet = jets.begin();
  std::vector<LorentzV>::const_iterator jjet = jets.end();
  for(; ijet!=jjet; ++ijet){
    if( ijet->Pt() > minJetPtCut_){
      newJetCollection.push_back( *ijet );
      mHT -= (*ijet);
    }
  }

  std::vector<LorentzV>::const_iterator ibaby = baby.begin();
  std::vector<LorentzV>::const_iterator jbaby = baby.end();
  for( ; ibaby!=jbaby; ++ibaby){
    if( ibaby->pt() > minJetPtCut_ ){
      newJetCollection.push_back( *ibaby);
      mHT -= (*ibaby);
    }
  }

  std::vector<LorentzV>::iterator i = newJetCollection.begin();
  std::vector<LorentzV>::iterator j = newJetCollection.end();
  for( ; i!=j; ++i){
    DrJetColl EventInfo( fabs(ROOT::Math::VectorUtil::DeltaPhi(*i, mHT + *i ) ) , *i  );
    biasDPhiList.push_back(EventInfo);
  }

  std::sort(biasDPhiList.begin(),biasDPhiList.end(),sort_by_Dr());


  for(size_t i = 0; i < biasDPhiList.size(); ++i)
  {
    // cout << "biasDphi " << biasDPhiList[i].Dr << endl;
    if(biasDPhiList[i].Dr < minBiasCut_){
      // cout << "Jet info: eta,phi,pt, " << biasDPhiList[i].Jet.Eta() <<  " " << biasDPhiList[i].Jet.Phi() << " " << biasDPhiList[i].Jet.Pt() <<endl;
      minDeltaEta = fabs( fabs( biasDPhiList[i].Jet.Eta() ) - 1.5 ); // 1.5 is the Barrel - EndCap boundary. BM

      try{deadECALDR = DeadECALDR(ev,biasDPhiList[i].Jet.Phi(),
        biasDPhiList[i].Jet.Eta(),nBadCells_);
      // cout << "DeadEcalDR " << deadECALDR << endl;
    }
    catch(...){
      deadECALDR = DeadECALDR_File(deadECALfile_,biasDPhiList[i].Jet.Phi(),
        biasDPhiList[i].Jet.Eta(),nBadCells_);
    }
      // cout << "dead EcalDr" << deadECALDR << " DeltaEta" << minDeltaEta << endl;
    if(deadECALDR < cut_ || minDeltaEta < cut2_ )return false;
  }
}


return true;


}

// -----------------------------------------------------------------------------
//
std::ostream& DeadECALCut::Description( std::ostream &ostrm ) {
  ostrm << "Dead ECAL cut " << cut_ << " " ;
  return ostrm;
}
// -----------------------------------------------------------------------------



UnCorrCut::UnCorrCut( float cut )
  : cut_(cut)
  {;}


bool UnCorrCut::Process( Event::Data& ev ) {


  int leadUnCorjet = -1;
  double LeadUnCorEn = 0.;
  for(unsigned int i = 0; i < ev.JD_CommonJets().accepted.size() && ev.JD_CommonJets().accepted[i]->GetIndex() >= 0; i++){

    if ( (ev.JD_CommonJets().accepted[i]->Pt()/ev.GetJetCorrFactor(ev.JD_CommonJets().accepted[i]->GetIndex())) > LeadUnCorEn){ // loop though all jets and calculate uncor energy, compare to some tmp value, if larger than tmp value set tmp value to uncor enegy
      LeadUnCorEn = ev.JD_CommonJets().accepted[i]->Pt()/ev.GetJetCorrFactor(ev.JD_CommonJets().accepted[i]->GetIndex());
      leadUnCorjet = i; // set the index of the leading uncor jet

    }
  }

  if( LeadUnCorEn > cut_ ) { return true; } // check the leading uncor jet has cor Pt > cut
  else{return false;}


}

// -----------------------------------------------------------------------------
//
std::ostream& UnCorrCut::Description( std::ostream &ostrm ) {
  ostrm << "Leading uncorrected jet has PT > " << cut_ << " " ;
  return ostrm;
}

// -----------------------------------------------------------------------------


NPvs::NPvs(const std::string & comparison,
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
          NPvs::~NPvs() { delete mComparison; }


          bool NPvs::Process( Event::Data& ev ) {return (*mComparison)(UInt_t((ev.vertexPosition())->size()),
            mNumber);
        }



// -----------------------------------------------------------------------------
//
        std::ostream& NPvs::Description( std::ostream &ostrm ) {
          ostrm << "Number Primary vertex cut (num " << mComparison->type();
          ostrm << " " << mNumber << ")";
          return ostrm;
        }








// -----------------------------------------------------------------------------
//
        HadronicCut::HadronicCut( float cut )
          : cut_(cut)
          {;}

// -----------------------------------------------------------------------------
//
        bool HadronicCut::Process( Event::Data& ev ) {

          double cut = 0.;

          if (1) {

            UInt_t n = ev.CommonObjects().size();
            LorentzV mht = ev.CommonRecoilMET();

            std::vector<bool> pseudo;
            AlphaT()( ev.CommonObjects(), pseudo, false );
            if ( pseudo.size() != ev.CommonObjects().size() ) { abort(); }

            LorentzV lv1(0.,0.,0.,0.);
            LorentzV lv2(0.,0.,0.,0.);
            if ( n == 2 ) {
              lv1 = ev.CommonObjects()[0];
              lv2 = ev.CommonObjects()[1];
            } else if ( n > 2 ) {
              for ( unsigned int i = 0; i < ev.CommonObjects().size(); ++i ) {
                if ( pseudo[i] ) { lv1 += ev.CommonObjects()[i]; }
                else             { lv2 += ev.CommonObjects()[i]; }
              }
              if ( lv2.Pt() > lv1.Pt() ) { LorentzV tmp = lv1; lv1 = lv2; lv2 = tmp; }
            }

//     double rho_a = lv2.Pt() / ( lv1.Pt() + lv2.Pt() + mht.Pt() );
//     double rho_b = lv1.Pt() / ( lv1.Pt() + lv2.Pt() + mht.Pt() );

            double m_jj  = ( lv1 + lv2 ).M();
//     double m2_jj  = ( lv1 + lv2 ).M2();
//     double mt_jj  = ( lv1 + lv2 ).Mt();
//     double mt2_jj  = ( lv1 + lv2 ).Mt2();

//     double mt_j1_mht = ( lv1 + mht ).Mt();
//     double mt2_j1_mht = ( lv1 + mht ).Mt2();

//     double mt_j2_mht = ( lv2 + mht ).Mt();
//     double mt2_j2_mht = ( lv2 + mht ).Mt2();

            cut = m_jj;
          }

          return cut < cut_;

        }

// -----------------------------------------------------------------------------
//
        std::ostream& HadronicCut::Description( std::ostream &ostrm ) {
          ostrm << "HadronicCut " << cut_ << " " ;
          return ostrm;
        }
// -----------------------------------------------------------------------------
//


        VertexPtOverHT::VertexPtOverHT( float cut )
          : cut_(cut)
          {;}


        bool VertexPtOverHT::Process( Event::Data& ev ) {
          if(!ev.vertexSumPt.enabled()){return true;}
          double  VertexPt = 0.;
          for(std::vector<floatle>::const_iterator vtx =
            ev.vertexSumPt()->begin();
          vtx != ev.vertexSumPt()->end();++vtx){

            if(!ev.vertexIsFake()->at( vtx-ev.vertexSumPt()->begin()) &&
            fabs((ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Z()) < 24.0 &&
            ev.vertexNdof()->at( vtx-ev.vertexSumPt()->begin() ) > 4
            && (ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Rho() < 2.0 ){

              VertexPt += *vtx;

              }
          }
            // cout << "Sum of vertex Pt/HT  is "  << VertexPt/ev.CommonHT() << endl;
          if( VertexPt/ev.CommonHT() > cut_ ) { return true; } // check the leading uncor jet has cor Pt > cut
          else{return false;}
        }

// -----------------------------------------------------------------------------
//
        std::ostream& VertexPtOverHT::Description( std::ostream &ostrm ) {
          ostrm << "Checking that  sum Vertex Pt / HT is  > " << cut_ << " " ;
          return ostrm;
        }

// -----------------------------------------------------------------------------
//
        TriggerMHT_Emu::TriggerMHT_Emu( float cut, float Threshold)
          : cut_(cut),
          Threshold_(Threshold) {;}

        bool TriggerMHT_Emu::Process( Event::Data& ev ){
          LorentzV TriggerMHT;
          std::vector<Event::Jet >::const_iterator ijet = ev.JD_Jets().begin();
          std::vector<Event::Jet >::const_iterator jjet = ev.JD_Jets().end();
          for ( ; ijet != jjet; ++ijet ){
            if( ijet->Pt() > Threshold_ ){ TriggerMHT += *ijet ;}
          }

          if( TriggerMHT.Pt() > cut_ ) return true;
          else return false;
        }

// -----------------------------------------------------------------------------
//
        std::ostream& TriggerMHT_Emu::Description( std::ostream &ostrm ) {
          ostrm << "MHT from jets above " << Threshold_ << " is  < " << cut_ << " GeV " ;
          return ostrm;
        }
// -----------------------------------------------------------------------------
//




// -----------------------------------------------------------------------------
//

// -----------------------------------------------------------------------------
//
        TriggerHT_Emu::TriggerHT_Emu( float cut, float Threshold)
          : cut_(cut),
          Threshold_(Threshold) {;}

        bool TriggerHT_Emu::Process( Event::Data& ev ){
          float TriggerHT;
          std::vector<Event::Jet >::const_iterator ijet = ev.JD_Jets().begin();
          std::vector<Event::Jet >::const_iterator jjet = ev.JD_Jets().end();
          for ( ; ijet != jjet; ++ijet ){
            if( ijet->Pt() > Threshold_ ){ TriggerHT += (*ijet).Et(); }
          }

          if( TriggerHT > cut_ ) return true;
          else return false;
        }

// -----------------------------------------------------------------------------
//
        std::ostream& TriggerHT_Emu::Description( std::ostream &ostrm ) {
          ostrm << "HT from jets above " << Threshold_ << " is  < " << cut_ << " GeV " ;
          return ostrm;
        }
// -----------------------------------------------------------------------------
//

        confiurableOddJet::confiurableOddJet( float threshold ) :
        Threshold_(threshold){;}

        bool confiurableOddJet::Process( Event::Data& ev){
          std::vector<Event::Jet const *>::const_iterator ijet = ev.JD_CommonJets().odd.begin();
          std::vector<Event::Jet const *>::const_iterator jjet = ev.JD_CommonJets().odd.end();
          for( ; ijet != jjet; ++ijet){
            if((*ijet)->Pt() > Threshold_) return false;
          }
          return true;
        }
// -----------------------------------------------------------------------------
//

        std::ostream& confiurableOddJet::Description( std::ostream &ostrm ) {
          ostrm << "OddJet Veto using configurable Jet Threshold of  " << Threshold_ << " GeV " ;
          return ostrm;
        }





// -----------------------------------------------------------------------------
//






        sumRecHitPtCut::sumRecHitPtCut( float sumRecHitPtCut)
          : cut_(sumRecHitPtCut){;}

        bool sumRecHitPtCut::Process( Event::Data& ev ){
        std::vector<PolarLorentzV>::const_iterator iEcalB=ev.rechitCaloP4Eb()->begin();
        std::vector<PolarLorentzV>::const_iterator jEcalB=ev.rechitCaloP4Eb()->end();
        std::vector<PolarLorentzV>::const_iterator iEcalE=ev.rechitCaloP4Ee()->begin();
        std::vector<PolarLorentzV>::const_iterator jEcalE=ev.rechitCaloP4Ee()->end();
        std::vector<PolarLorentzV>::const_iterator iHbHe=ev.rechitCaloP4Hbhe()->begin();
        std::vector<PolarLorentzV>::const_iterator jHbHe=ev.rechitCaloP4Hbhe()->end();
        std::vector<PolarLorentzV>::const_iterator iHF=ev.rechitCaloP4Hf()->begin();
        std::vector<PolarLorentzV>::const_iterator jHF=ev.rechitCaloP4Hf()->end();
        std::vector<PolarLorentzV> RecHitcollection;

        float sumRecHitPt = 0.;
        // cout << " Starting EB " << endl;
        for(int idx = 0; iEcalB!=jEcalB;++iEcalB,++idx){
          if( ev.rechitCaloSeverityLevelEb()->at(idx) > 1 and  (*iEcalB).Pt()>0)
         RecHitcollection.push_back(*iEcalB);
         //sumRecHitPt += (*iEcalB).Pt();
        }
        // cout << " Starting EE " << endl;
        for(int idx = 0; iEcalE!=jEcalE;++iEcalE,++idx){
          if( ev.rechitCaloSeverityLevelEe()->at(idx) > 1 and (*iEcalE).Pt()>0)
          RecHitcollection.push_back(*iEcalE);
         // sumRecHitPt += (*iEcalE).Pt();
        }
        // cout << " Starting HEHB " << endl;
        for(int idx = 0; iHbHe!=jHbHe;++iHbHe,++idx){
          if( ev.rechitCaloSeverityLevelHbhe()->at(idx) > 9 and (*iHbHe).Pt()>0)
          RecHitcollection.push_back(*iHbHe);
        // sumRecHitPt += (*iHbHe).Pt();
        }
        // cout << " Starting HF " << endl;
        for(int idx = 0; iHF!=jHF;++iHF,++idx){
          if( ev.rechitCaloSeverityLevelHf()->at(idx) > 9 and (*iHF).Pt()>0 )
          RecHitcollection.push_back(*iHF);
         // sumRecHitPt += (*iHF).Pt();
        }


        for (std::vector<PolarLorentzV>::const_iterator it = RecHitcollection.begin() ; it != RecHitcollection.end() ; it++){

         std::vector<PolarLorentzV>::const_iterator in = it + 1;

        if(*it==*in){
        //cout << "duplicate event that is " <<  *it << "and " << *in << endl;
        }
        else {

        sumRecHitPt += it->Pt();

        }

}




        if( sumRecHitPt > cut_ ) return false;
        else return true;
        }

// -----------------------------------------------------------------------------
//
        std::ostream& sumRecHitPtCut::Description( std::ostream &ostrm ) {
          ostrm << "Veto Events with sum of cleaned rechits above " << cut_ << " GeV " ;
          return ostrm;
        }
// -----------------------------------------------------------------------------
//
