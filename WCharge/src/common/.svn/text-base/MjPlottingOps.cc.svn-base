#include "MjPlottingOps.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include "GenObject.hh"
#include "TRandom.h"


// -----------------------------------------------------------------------------
//
MjPlottingOps::MjPlottingOps(const std::string & filename, const Utils::ParameterSet& ps ) :
  // Misc
  dirName_(   filename),
  p0metparRes( ps.Get<double>("p0METparRes") ),
  p1metparRes( ps.Get<double>("p1METparRes") ),
  p0metperRes( ps.Get<double>("p0METperRes") ),
  p1metperRes( ps.Get<double>("p1METperRes") ),
  p0metparBias( ps.Get<double>("p0METparBias") ),
  p1metparBias( ps.Get<double>("p1METparBias") ),
  p2metparBias( ps.Get<double>("p2METparBias") ),
  p0metperBias( ps.Get<double>("p0METperBias") ),
  p1metperBias( ps.Get<double>("p1METperBias") ),
  p2metperBias( ps.Get<double>("p2METperBias") ),
  lepRes( ps.Get<double>("LepResolution") ),
  lepScale( ps.Get<double>("LepScale") )
{}

// -----------------------------------------------------------------------------
//
MjPlottingOps::~MjPlottingOps() {}

// -----------------------------------------------------------------------------
//
void MjPlottingOps::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
  

}

// -----------------------------------------------------------------------------
//
void MjPlottingOps::BookHistos() {

  random = new TRandom();
  
  for (int ih=0;ih<EtaCh_Bins;ih++){
    TString sel = "h_reco"+Suffix[ih];
	TString cor = "h_corr"+Suffix[ih];
    h_sel[ih]= new TH1F(sel,sel,200,0,100.);
	h_cor[ih]= new TH1F(cor,cor,200,0,100.);
  }
  
  
}

// -----------------------------------------------------------------------------
// PROCESS
bool MjPlottingOps::Process( Event::Data& ev ) {
  float w=ev.GetEventWeight();
  std::vector<Event::GenObject> Mj_Electrons;  //define Electron Container
  std::vector<Event::GenObject> Mj_Neutrinos;  //define Netrino Container
  std::vector<Event::GenObject> Mj_W;          //define W Container
  TDirectory *Dir = ev.OutputFile()->GetDirectory(dirName_.c_str());
  //----------
  //Fill Particle Vectors
  //----------
  for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();
      j != ev.GenParticles().end();
      ++j) {                                          //Loop all Gen particles
    if (j->GetStatus()==3){                           //All stable particles
      int ID = abs(j->GetID());
      switch (ID){
        case 11: //Electron
          Mj_Electrons.push_back(*j);
          break;
        case 12: //Neutrino 
          Mj_Neutrinos.push_back(*j); 
          break;
        case 24: //W Boson
          Mj_W.push_back(*j);
          break;
      }//End Switch
    }//End If
  }//End Gen Loop
  
  double recomet = ev.PFMET().Pt();
  
  if( Mj_W.size()==1&&
      Mj_Electrons.size()==1 && 
      Mj_Neutrinos.size()==1){
    float met=Mj_Neutrinos[0].Pt();
    TVector2 Wtr(Mj_W[0].Px(),Mj_W[0].Py());
    TVector2 nutr(Mj_Neutrinos[0].Px(),Mj_Neutrinos[0].Py());
    float Dx=Mj_W[0].Px()-Mj_Electrons[0].Px()-Mj_Neutrinos[0].Px();
    float pt=Mj_Electrons[0].Pt();
    int   id=Mj_Electrons[0].GetID();
    float eta=Mj_Electrons[0].Eta();
    float ptW=Mj_W[0].Pt();
    
    TString Prefix_sel="h_reco";
    TString Prefix_cor="h_corr"; 
  
    TString Suffix="";
    if      ((fabs(eta)<0.4)&&(fabs(eta)>0.0))  Suffix = "_eta1";
    else if ((fabs(eta)<0.8)&&(fabs(eta)>0.4))  Suffix = "_eta2";
    else if ((fabs(eta)<1.2)&&(fabs(eta)>0.8))  Suffix = "_eta3";
    else if ((fabs(eta)<1.6)&&(fabs(eta)>1.2))  Suffix = "_eta4";
    else if ((fabs(eta)<2.0)&&(fabs(eta)>1.6))  Suffix = "_eta5";
    else if ((fabs(eta)<2.4)&&(fabs(eta)>2.0))  Suffix = "_eta6";

    if (Suffix==""){
      return false;
      //cout<<"ETA-Charge bin does not exist"<<endl;
      //assert(0);
    }

    if (id==11) Suffix+="_pos";
    if (id==-11) Suffix+="_neg";

    if (fabs(Dx)<0.01 && pt>25){
      //      cout<<"PT W "<<ptW<<" "<<Wtr.X()<<" "<<Wtr.Y()<<endl;
      //      cout<<"pt nu "<<met<<" "<<nutr.X()<<" "<<nutr.Y()<<endl;
      float Angle=Wtr.DeltaPhi(nutr);
      //      float biasTr=p0metparBias+(ptW*p1metparBias);
      //      cout<<"Angle "<<Angle<<"  "<<met*cos(Angle)<<" "<<met*sin(Angle)<<" "<<biasTr<<endl;
      float metpar=random->Gaus((met*cos(Angle))+(p0metparBias+((p1metparBias/sqrt(ptW))+ p2metparBias*ptW)), p0metparRes+(ptW*p1metparRes) );
      float metper=random->Gaus((met*sin(Angle))+(p0metperBias+((p1metperBias/sqrt(ptW))+ p2metperBias*ptW)), p0metperRes+(ptW*p1metperRes) );
      float metmod=sqrt(metpar*metpar+metper*metper);
      
      bool acc= (((fabs(eta)<1.56)&&(fabs(eta)>1.44))|| (fabs(eta)>2.4));
      if (!acc){
        TH1F *h1;
        Dir->GetObject(Prefix_cor,h1);
        h1->Fill(metmod,w);
        Dir->GetObject(Prefix_sel,h1);
        h1->Fill(recomet,w);
		
		Dir->GetObject(Prefix_cor+Suffix,h1);
        h1->Fill(metmod,w);
		Dir->GetObject(Prefix_sel+Suffix,h1);
        h1->Fill(recomet,w);
		return true;
      }
    }      
  } 
  return false;
}//End Method

// -----------------------------------------------------------------------------
//
std::ostream& MjPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "Mj's PlottingOps ";
  return ostrm;
}

// -----------------------------------------------------------------------------
//S


// -----------------------------------------------------------------------------
//


// -----------------------------------------------------------------------------
//


// -----------------------------------------------------------------------------
//


