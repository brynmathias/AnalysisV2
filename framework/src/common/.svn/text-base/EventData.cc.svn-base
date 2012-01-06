/*! \file EventData.cc
 * \brief Source code for the Event::Data class.
 */

#include "EventData.hh"
//#include "SmearSuite.hh"
#include "Math/VectorUtil.h"
#include "AlphaT.hh"
#include "Photon.hh"
#include "Jet.hh"
#include "Lepton.hh"
#include "GenObject.hh"
#include "Utils.hh"
#include "KinSuite.hh"
#include <iostream>
#include "Razor.hh"

namespace Event {

Data::Data(const Utils::ParameterSet & sample,
           std::map<std::string,Compute::UserBase*> &user_vars,
           std::vector<std::pair<std::string,
           Compute::ObjectFilter<Lepton>*> > &muon_filters,
           std::vector<std::pair<std::string,
           Compute::ObjectFilter<Lepton>*> > & electron_filters,
           std::vector<std::pair<std::string,
     Compute::ObjectFilter<Lepton>*> > & tau_filters,
           std::vector<std::pair<std::string,
           Compute::ObjectFilter<Photon>*> > & photon_filters,
           std::vector<std::pair<std::string,
           Compute::ObjectFilter<Jet>*> > & jet_filters,
           std::vector<std::pair<std::string,
           Compute::ObjectFilter<ICF_LorentzV>*> > & met_filters,
           Compute::EventWeight::FilterList weight_filters
           ) :
    ND_CLASS(sample.Get<std::string>("File"),
             sample.Contains("FileList") ? sample.Get<std::vector<std::string> >("FileList") :
             std::vector<std::string>(),
             sample.Get<std::string>("Name"),
             sample.Get<int>("LastEntry"),
             sample.Get<int>("FirstEntry")),
    mUserVars(user_vars),
    // Cached computed quantities
    GetEventWeight(*this),
    WeightProducer(*this),
    CC(*this),
    RecoilMET(*this),
    ObjSum(*this),
    SumEt(*this),
    CommonHT(*this),
    CommonMHT(*this),
    CommonMT(*this),
    CommonMinDPhi(*this),
    CommonMinBiasDPhi(*this),
    JetMinDPhi(*this),
    JetMinBiasDPhi(*this),
    JetMETMinDPhi(*this),
    CommonMinDEt(*this),
    CommonAlphaT(*this),
    LeptonicAlphaT(*this),
    HadronicAlphaT(*this),
    CommonMT2(*this),
    CommonRecoilMET(*this),
    CommonObjectSum(*this),
    CommonRecoil(*this),
    CommonSumEt(*this),
    CommonRecoilMETJetDPhi(*this),
    BiasedCommonRecoilMETJetDPhi(*this),
    LowPtBiasedCommonRecoilMETJetDPhi(*this),
    CommonObjects(*this),
    LeptonicObjects(*this),
    HadronicObjects(*this),
    CommonJetsAndElectrons(*this),
    CommonMeff(*this),
    CommonThrustStuff(*this),
    M3(*this),
    Razor_MR(*this),
    Razor_MRt(*this),
    LD_CommonElectrons(*this),
    LD_CommonMuons(*this),
    LD_CommonTaus(*this),
    // Cached photonic data
    PD_CommonPhotons(*this),
    MC_GenLeptons(*this),
    MC_SSFinalState(*this),
    MC_TheLeptons(*this),
    MC_TheIsolatedLeptons(*this),

    JD_CommonJets(*this),
    JD_EMJets(*this),
    GenMatrix(*this),
    mMETFilters(met_filters)
  {
    mOutputFile = new TFile(sample.Get<std::string>("OutputFile").c_str(),
                            "recreate");

    if ( mOutputFile == 0 ) {
      std::runtime_error("Could not open output file");
    }

    std::string NtupleWeightMode=Utils::GetConfig<std::string>("Ntuple.Weight");
    bool use_weight_producer = false;
    double desired_lumi = sample.Get<double>("Reweight");
    if(sample.Contains("Events") && sample.Get<int>("Events") <= 0)
      throw std::invalid_argument("Non positive value for Events.");
    if(NtupleWeightMode=="User"){
      if(sample.Contains("Weights.CrossSection") ||
         sample.Contains("Weights.Events") ||
         sample.Contains("Weights.PtBin") ){
        if(!sample.Contains("Weights.CrossSection") ||
           !sample.Contains("Weights.Events") ||
           !sample.Contains("Weights.PtBin") )
          throw std::invalid_argument("Missing array in Weights section.");
        use_weight_producer = true;
        std::vector<double> xcs= sample.Get<std::vector<double> >("Weights.CrossSection");
        std::vector<int> evts= sample.Get<std::vector<int> >("Weights.Events");
        std::vector<double> ptbins= sample.Get<std::vector<double> >("Weights.PtBin");
        if((xcs.size() != evts.size()) || (evts.size() != ptbins.size()))
          throw std::invalid_argument("Weights arrays differ in size");
        WeightProducer.Init(desired_lumi,xcs,evts,ptbins);
      }
    }


    int nevents = sample.Contains("Events") ? sample.Get<int>("Events") : 0;
    double weight = sample.Contains("Weight") ? sample.Get<double>("Weight") : -1;
    double cross_section = sample.Contains("CrossSection") ? sample.Get<double>("CrossSection") : 0;
    GetEventWeight.Init(NtupleWeightMode, desired_lumi, cross_section,
                           weight, nevents, use_weight_producer, weight_filters);
    GetEventWeight.Print(std::cout);
    std::cout << std::endl;
    // Muon filters
    for(std::vector<std::pair<std::string,
            Compute::ObjectFilter<Lepton>*> >::iterator ii
            = muon_filters.begin(); ii!=muon_filters.end();++ii){
      if(LD_CommonMuons.XClean){
        if(ii->first=="PreCC") CC.muon_pre_proc.Add(ii->second);
        else if(ii->first=="PostCC") CC.muon_post_proc.Add(ii->second);
        else{
          std::string e_str="Invalid order parameter for filter: "+ii->first;
          throw std::invalid_argument(e_str);
        }
      }
      else{
        LD_CommonMuons.muon_proc.Add(ii->second);
      }
    }

    // Electron filters
    for(std::vector<std::pair<std::string,
    Compute::ObjectFilter<Lepton>*> >::iterator ii
    = electron_filters.begin(); ii!=electron_filters.end();++ii){
      if(LD_CommonElectrons.XClean){
        if(ii->first=="PreCC") CC.electron_pre_proc.Add(ii->second);
        else if(ii->first=="PostCC") CC.electron_post_proc.Add(ii->second);
        else{
          std::string e_str="Invalid order parameter for filter: "+ii->first;
          throw std::invalid_argument(e_str);
        }
      }
      else{
        LD_CommonElectrons.electron_proc.Add(ii->second);
      }
    }

    // Tau filters
    for(std::vector<std::pair<std::string,
    Compute::ObjectFilter<Lepton>*> >::iterator ii
    = tau_filters.begin(); ii!=tau_filters.end();++ii){

      if(LD_CommonTaus.XClean){
        if(ii->first=="PreCC") CC.tau_pre_proc.Add(ii->second);
        else if(ii->first=="PostCC") CC.tau_post_proc.Add(ii->second);
        else{
          std::string e_str="Invalid order parameter for filter: "+ii->first;
          throw std::invalid_argument(e_str);
        }
      }
      else{
        LD_CommonTaus.tau_proc.Add(ii->second);
      }
    }

    // Photon filters
    for(std::vector<std::pair<std::string,
    Compute::ObjectFilter<Photon>*> >::iterator ii
    = photon_filters.begin(); ii!=photon_filters.end();++ii){
      if(PD_CommonPhotons.XClean){
        if(ii->first=="PreCC") CC.photon_pre_proc.Add(ii->second);
        else if(ii->first=="PostCC") CC.photon_post_proc.Add(ii->second);
        else{
          std::string e_str="Invalid order parameter for filter: "+ii->first;
          throw std::invalid_argument(e_str);
        }
      }
      else{
        PD_CommonPhotons.photon_proc.Add(ii->second);
      }
    }
    // Jet filters
    for(std::vector<std::pair<std::string,
            Compute::ObjectFilter<Jet>*> >::iterator ii
    = jet_filters.begin(); ii!=jet_filters.end();++ii){
      if(JD_CommonJets.XClean){
        if(ii->first=="PreCC") CC.jet_pre_proc.Add(ii->second);
        else if(ii->first=="PostCC") CC.jet_post_proc.Add(ii->second);
        else{
          std::string e_str="Invalid order parameter for filter: "+ii->first;
          throw std::invalid_argument(e_str);
        }
      }
      else{
        JD_CommonJets.jet_proc.Add(ii->second);
      }
    }
    PFMET.met_proc.AddFilters(mMETFilters, "pfMET");
  }


  Data::~Data() {
    mOutputFile->Write();

    delete mOutputFile;

  }

  TFile *Data::OutputFile() const {
    return mOutputFile;
  }


  //////////////////////////////
  // Computed functions
  //////////////////////////////
  Double_t Data::hadAlpha_t() const {
    std::vector<bool> pseudoAll;
    double alpha_t = AlphaT()(JD_CommonJets().accepted, pseudoAll, true);
    if(pseudoAll.size() != JD_CommonJets().accepted.size()){abort();}
    return alpha_t;
  }

  float Data::comRecoilMetdPhi(LorentzV const * vec1) const {
    return fabs(ROOT::Math::VectorUtil::DeltaPhi(*vec1, CommonRecoilMET()));
  }

  float Data::biasedComRecoilMetdPhi(LorentzV const * vec1) const {
    LorentzV newComRecoilMET = CommonMHT() + (*vec1);
    return fabs(ROOT::Math::VectorUtil::DeltaPhi(newComRecoilMET,*vec1)) ;
  }

  float Data::lowPtbiasedComRecoilMetdPhi(LorentzV const * vec1) const {
    LorentzV babyHT_30(0.,0.,0.,0.);
    for( std::vector<Event::Jet const*>::const_iterator iI =JD_CommonJets().baby.begin(); iI != JD_CommonJets().baby.end();
   ++iI) {
    if((*iI)->Pt() > 30.){ babyHT_30 +=(**iI); }
    }
    LorentzV newComRecoilMET = CommonRecoilMET() + babyHT_30 + (*vec1);
    return fabs(ROOT::Math::VectorUtil::DeltaPhi(newComRecoilMET,*vec1)) ;
  }

  //////////////////////////////
  // Static helper functions
  //////////////////////////////
  float Data::MT(LorentzV const * vec1, LorentzV const * vec2) const {
    float  my_MT = sqrt(2)*sqrt( vec1->Pt()*vec2->Pt() - vec1->Pt()*vec2->Pt() *
                 (cos( ROOT::Math::VectorUtil::DeltaPhi(*vec1,*vec2) ) ) );
    return my_MT;
  }

  float Data::LP(LorentzV const * vecLep, LorentzV const * vecW) const {
    float  my_LP = (vecLep->Px()*vecW->Px()+ vecLep->Py()*vecW->Py())/ (vecW->Pt()*vecW->Pt());
    return my_LP;
  }

  float Data::MScosThetaStar2Part(LorentzV const * vec1, LorentzV const * vec2) const {
    float JetZAv = vec1->Pz()+vec2->Pz();
    float theta1 = fabs(cos(atan((vec1->Pt()/fabs(vec1->Pz()-JetZAv/2)))));
    return theta1;
  }

  float Data::cosThetaStar2Part(LorentzV const * vec1,LorentzV const * vec2) const {
    return fabs(  tanh( (vec1->Eta()-vec2->Eta()) / 2 ) );
  }


  //===================================
  // Data global helper functions
  //===================================
  // These now will have been taken care of by the Kinematic Suite,
  // so these should be deprecated or moved to analysis specific files.

   // Matching function
  Int_t Data::leptonMatch(const LorentzV *vec, int type) {
    // type = 1 for electrons matching , and type = 2 for muons matching
    // Matching paramters
    float mo_DRmax=0.5; // float mo_dPtbyPtmax=4.;

    int lType=-1;
    if (type==1) {  lType=13;}
    else if (type==2) {lType=11;}
    int iMatch=-1;

    int iLep=0;
    for (std::vector<Event::GenObject const *>::const_iterator par = MC_GenLeptons().begin();  par != MC_GenLeptons().end(); ++par) {

      iLep++;
      // ID and Status
      Int_t pID = (*par)->GetID(); if ( abs(pID)==lType ) { continue; }
      Int_t iStat = (*par)->GetStatus(); if (iStat!=1) { continue; }
      //      cout << " Debug. pID: " << pID << ", status: " << iStat << ", pt: " << (*par)->Pt() << "\n";
      float dR = ROOT::Math::VectorUtil::DeltaR(**par, *vec);
      //   float dPtbyPt = fabs(((*par)->Pt() - vec->Pt()))/((*par)->Pt());

      if  (dR < mo_DRmax) { // && dPtbyPt < mo_dPtbyPtmax) {
        iMatch = (iLep-1);
        mo_DRmax = dR ;
    //  mo_dPtbyPtmax = dPtbyPt;
      }
    }  // end loop on GenLep block

    return iMatch;
    // returns the position of the GenLepton in the relevant vector
  }

  int Data::leptonType(int imatch) {

    int type=-1;

    if (imatch<0) {
      // std::cout << "there was not a match" << std::endl;
      return type; }

    int mother = -1;
    if (imatch>=0) {
      mother = abs(MC_GenLeptons()[imatch]->GetMotherID());
    }

    if (mother<=0) { return type; }

    if (mother>99 && mother<1000000) {type=10;} // heavy flavor

     if (mother>999999) { type=1; } // SUSY particle
     if (mother==24 || mother==6) {type=2;}  // W-decay (or t->Wb -> b l nu)
     if (mother==23) {type=3;}  // Z-decay
     if (mother==15) {type=4;} // tau decay
     if (mother>24 && mother<43) {
     //  cout << "Mother is a " << mother << endl;
       type=1;}
     if ( (mother>0 && mother<6) || mother==21 ) { type=5; } // includes virtual W/Z* decays
    // if (type<0 ) {cout << "mother is " << mother << endl;}
     if ( mother==111 || mother==130 || mother==211 || mother==311
     || mother==321 || mother==310 || mother==313 || mother==323 ) {type=9;}

    return type;
  }


  // Could these be moved to a different file? Do we need a separate GenData analysis set?
  void  Data::PrintGen() {
    cout<< endl;
    cout<<"+++++++++++++++++  MC Info +++++++++++++++++++++++"<<endl;
    int i=0;
    for (std::vector<GenObject>::const_iterator j = GenParticles().begin();  j != GenParticles().end(); ++j) {
      //      i++;
      //      if (i==0 || i==1) continue;

      if (j->GetStatus()==100) continue;
      cout <<" index: "<<i; //-1;
      cout << " Id: " <<j->GetID();
      cout << " Mother: " <<j->GetMother();
      cout << " MotherID: " << j->GetMotherID();
      cout << " Et "<<j->Et();
      cout << " Pt " <<j->Pt();
      cout << " Eta "<<j->Eta();
      cout << " Phi "<<j->Phi();
      cout << " Status "<<j->GetStatus();
      cout<< endl;
      i++;
    }
  }



  void  Data::PrintGenLeptons() {
    cout<< endl;
    //    cout<<"+++++++++++++++++  MC Info - GenLeptons +++++++++++++++++++++++"<<endl;
    int i=0;

    for (std::vector<Event::GenObject const *>::const_iterator j = MC_GenLeptons().begin();  j != MC_GenLeptons().end(); ++j) {

      if ((*j)->GetStatus()==100) continue;
      cout << " Index: " << i;
      cout << " Id: " << (*j)->GetID();
      cout << " Mother: " << (*j)->GetMother();
      cout << " Et " << (*j)->Et();
      cout << " Pt " << (*j)->Pt();
      cout << " Eta " << (*j)->Eta();
      cout << " Phi " << (*j)->Phi();
      cout << " Status " << (*j)->GetStatus();
      cout << endl;
      i++;

    }
  }



  int  Data::GenWtoTau() {
    int tauW=0;
    for (std::vector<GenObject>::const_iterator j = GenParticles().begin();  j != GenParticles().end(); ++j) {
      if(fabs(j->GetID())==15&&j->GetMother()>-1&&j->GetMother()<100)
    {
      if(fabs(GenParticles()[j->GetMother()].GetID()==23)||fabs(GenParticles()[j->GetMother()].GetID()==24)) tauW++;
    }
    }
    return tauW;
  }

  int  Data::GenWtoMuon() {
    int muonW=0;
    for (std::vector<GenObject>::const_iterator j = GenParticles().begin();  j != GenParticles().end(); ++j) {
      if(fabs(j->GetID())==13&&j->GetMother()>-1&&j->GetMother()<100)
    {
      if(fabs(GenParticles()[j->GetMother()].GetID()==23)||fabs(GenParticles()[j->GetMother()].GetID()==24)) muonW++;
    }
    }
    return muonW;
  }

  int  Data::GenWtoElectron()
  {
    int tauW=0;
    for (std::vector<GenObject>::const_iterator j = GenParticles().begin();  j != GenParticles().end(); ++j) {
      if(fabs(j->GetID())==11&&j->GetMother()>-1&&j->GetMother()<100)
    {
      if(fabs(GenParticles()[j->GetMother()].GetID()==23)||fabs(GenParticles()[j->GetMother()].GetID()==24)) tauW++;
    }
    }
    return tauW;
  }



  float Data::ComJetOverlap(LorentzV * vec1)
  {

    float overlapMin = 9999.;

    for ( std::vector<Event::Jet const *>::const_iterator iJ = JD_CommonJets().accepted.begin();
      iJ != JD_CommonJets().accepted.end();
      iJ++ ) {

       float myDR = fabs( ROOT::Math::VectorUtil::DeltaR (**iJ, *vec1));

       if( myDR < overlapMin ) { overlapMin = myDR; }
      }
    return overlapMin;
  }



  // This could be generalised and moved to the Kinematic Suite.
  bool  Data::OverlapsJet(LorentzV * vec1, float dR, float dEt)
  {
    bool overlap = false;
    for (std::vector<Jet>::const_iterator iJ = JD_Jets().begin();
     iJ != JD_Jets().end();
     ++iJ)
      {
    if( fabs( ROOT::Math::VectorUtil::DeltaR (*iJ,*vec1) ) < dR && fabs( iJ->Et()-vec1->Et() )<dEt) overlap =true;
      }
    return overlap;
  }

  void Data::PrintStableVisRec()
  {
    cout << " List of stable visible common Rec objects:"<<endl;
    cout << "Jets:" <<endl;
    LorentzV test(0,0,0,0);
    for (std::vector<Event::Jet const *>::const_iterator iph = JD_CommonJets().accepted.begin();
     iph != JD_CommonJets().accepted.end();
     ++iph) {
      cout << "Pt: " << (*iph)->Pt()
       << " Phi: "<<  (*iph)->Phi()
       << " Eta: "<<  (*iph)->Eta()
       <<" fem: "<< (*iph)->GetEmFrac()
       << endl;
      test+=  (**iph);
    }
    cout << "MHT Pt: " << test.Pt() <<" phi " << (-test).Phi() << " "<< CommonRecoilMET().Pt() << endl;

    if(LD_CommonMuons().accepted.size()>0) cout << "Muons:" <<endl;
    for (std::vector<Event::Lepton const *>::const_iterator iph = LD_CommonMuons().accepted.begin();
     iph != LD_CommonMuons().accepted.end();
     ++iph) {
      cout << "Pt: " << (*iph)->Pt()
       << " Phi: " << (*iph)->Phi()
       << " Eta: " << (*iph)->Eta()
       << endl;
    }

    if(LD_CommonElectrons().accepted.size()>0) cout << "Elis:" <<endl;
    for (std::vector<Event::Lepton const *>::const_iterator iph = LD_CommonElectrons().accepted.begin();
     iph != LD_CommonElectrons().accepted.end();
     ++iph) {
      cout << "Pt: " << (*iph)->Pt()
       << " Phi: " << (*iph)->Phi()
       << " Eta: " << (*iph)->Eta()
       << endl;
    }

    if(LD_CommonTaus().accepted.size()>0) cout << "Taus:" <<endl;
    for (std::vector<Event::Lepton const *>::const_iterator iph = LD_CommonTaus().accepted.begin();
     iph != LD_CommonTaus().accepted.end();
     ++iph) {
      cout << "Pt: " << (*iph)->Pt()
       << " Phi: " << (*iph)->Phi()
       << " Eta: " << (*iph)->Eta()
       << endl;
    }

    if(PD_CommonPhotons().accepted.size()>0) cout << "Photons:" <<endl;
    for (std::vector<Event::Photon const *>::const_iterator iph = PD_CommonPhotons().accepted.begin();
     iph != PD_CommonPhotons().accepted.end();
     ++iph) {
      cout << "Pt: " << (*iph)->Pt()
       << " Phi: " <<  (*iph)->Phi()
       << " Eta: " <<  (*iph)->Eta()
       << endl;
    }

    // JJ - bug here - referenced tausnot commontaus
    if(LD_CommonTaus().accepted.size()>0) cout << "Taus:" <<endl;
    for (std::vector<Event::Lepton const *>::const_iterator iph = LD_CommonTaus().accepted.begin();
     iph != LD_CommonTaus().accepted.end();
     ++iph) {
      cout << "Pt: " << (*iph)->Pt()
       << " Phi: "<< (*iph)->Phi()
       << " Eta: "<< (*iph)->Eta()
       << endl;
    }
  }

  void Data::PrintStableVisAllRec() {
    cout << " List of stable visible all Rec objects:  weight: "<< GetEventWeight() <<endl;
    cout << "Jets:" << endl;

    LorentzV test(0,0,0,0);
    for (std::vector<Event::Jet>::const_iterator iph = JD_Jets().begin();
     iph != JD_Jets().end();
     ++iph) {
      cout << "Pt: " << iph->Pt()
        << " Phi: "<<  iph->Phi()
        << " Eta: "<<  iph->Eta()
        << endl;
      if( iph->Pt()>30)  test+=  (*iph);
      //    cout << "Px: " << iph->Px() << " "<< Jet_ccJetpx[iph->GetIndex()] << endl;
    }
    cout << "all MHT Pt: " << test.Pt() <<" phi " << (-test).Phi() << " "<< CommonRecoilMET().Pt() << endl;
    if(LD_Muons().size()>0) cout << "Muons:" <<endl;
    for (std::vector<Event::Lepton>::const_iterator iph = LD_Muons().begin(); iph != LD_Muons().end(); ++iph) {
      cout << "Pt: " << iph->Pt()
        << " Phi: "<<  iph->Phi()
        << " Eta: "<<  iph->Eta()
        << endl;
    }

    if(LD_Electrons().size()>0) cout << "Elis:" <<endl;
    for (std::vector<Event::Lepton>::const_iterator iph = LD_Electrons().begin(); iph != LD_Electrons().end(); ++iph) {
      cout << "Pt: " << iph->Pt()
        << " Phi: "<<  iph->Phi()
        << " Eta: "<<  iph->Eta()
        << endl;
    }

    if(PD_Photons().size()>0) cout << "Photons:" <<endl;
    for (std::vector<Event::Photon>::const_iterator iph = PD_Photons().begin();
     iph != PD_Photons().end();
     ++iph) {
      cout << "Pt: " << iph->Pt()
        << " Phi: "<<  iph->Phi()
        << " Eta: "<<  iph->Eta()
        << endl;
    }

    if(LD_Taus().size()>0) cout << "Taus:" <<endl;
    for (std::vector<Event::Lepton>::const_iterator iph = LD_Taus().begin();
     iph != LD_Taus().end();
     ++iph) {
      cout << "Pt: " << iph->Pt()
        << " Phi: "<< iph->Phi()
        << " Eta: "<< iph->Eta()
        << endl;
    }
  }

  float Data::GetR1(LorentzV aMET)
  {
    float Dphi1 = fabs(ROOT::Math::VectorUtil::DeltaPhi(aMET,*(JD_CommonJets().accepted[0])));
    float Dphi2 = fabs(ROOT::Math::VectorUtil::DeltaPhi(aMET,*(JD_CommonJets().accepted[1])));
    float R1 = sqrt(Dphi2*Dphi2+(TMath::Pi()-Dphi1)*(TMath::Pi()-Dphi1));
    return R1;
  }

  float Data::GetR2(LorentzV aMET)
  {
    float Dphi1 = fabs(ROOT::Math::VectorUtil::DeltaPhi(aMET,*(JD_CommonJets().accepted[0])));
    float  Dphi2 = fabs(ROOT::Math::VectorUtil::DeltaPhi(aMET,*(JD_CommonJets().accepted[1])));
    float  R2 = sqrt(Dphi1*Dphi1+(TMath::Pi()-Dphi2)*(TMath::Pi()-Dphi2));
    return R2;
  }
 // return index of Genobjet that matches LorentzV in R and has id:id
  int Data::GetMatch(LorentzV aParticle, int id, float R)
  {
    int Index = -1;
    float rmin = R;
    for (std::vector<Event::GenObject>::const_iterator j = GenParticles().begin();  j != GenParticles().end(); ++j) {
      if(fabs((*j).GetID())==id&&fabs(ROOT::Math::VectorUtil::DeltaR((*j),aParticle))<R) {
  rmin=fabs(ROOT::Math::VectorUtil::DeltaPhi((*j),aParticle));
  Index=(*j).GetIndex();
      }
    }
    return Index;
  }


/*
// Jet kinematic info
// NOTE: TW 13/02/2009 Jet_ccJetXX[index] returns the CORRECTED CC jet energies.
// Thus applying the correction factor results in double corrections. Bad :)


*/
} // ~ namespace Event
