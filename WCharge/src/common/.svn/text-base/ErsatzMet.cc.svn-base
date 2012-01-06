#include "ErsatzMet.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include "GenObject.hh"
#include "TRandom.h"
#include "TString.h"

// -----------------------------------------------------------------------------
//
ErsatzMet::ErsatzMet(const std::string & filename, const Utils::ParameterSet& ps ) :
  // Misc
  dirName_(   filename)
{}

// -----------------------------------------------------------------------------
//
ErsatzMet::~ErsatzMet() {}

// -----------------------------------------------------------------------------
//
void ErsatzMet::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
  

}

// -----------------------------------------------------------------------------
//
void ErsatzMet::BookHistos() {

  TString ib[10]={"_0","_1","_2","_3","_4","_5","_6","_7","_8","_9"};
  for (int i1=0;i1<10;i1++){
    for (int i2=0;i2<10;i2++){
      for (int i3=0;i3<10;i3++){
	TString tit1= "neu"+ib[i1]+ib[i2]+ib[i3];
	TString tit2= "antineu"+ib[i1]+ib[i2]+ib[i3];
	TString tit3= "ele"+ib[i1]+ib[i2]+ib[i3];
	TString tit4= "pos"+ib[i1]+ib[i2]+ib[i3];
	NeuFromW[i1][i2][i3] = new TH1D(tit1,tit1,30,0.,60.);
	AntiNeuFromW[i1][i2][i3] = new TH1D(tit2,tit2,30,0.,60.);	
	EleFromZ[i1][i2][i3] = new TH1D(tit3,tit3,30,0.,60.);
	PosFromZ[i1][i2][i3] = new TH1D(tit4,tit4,30,0.,60.);		
      }
    }
  }
}

// -----------------------------------------------------------------------------
// PROCESS
bool ErsatzMet::Process( Event::Data& ev ) {
  //  float w=ev.GetEventWeight();
  std::vector<Event::GenObject> Mj_Electrons;  //define Electron Container
  std::vector<Event::GenObject> Mj_Neutrinos;  //define Netrino Container
  std::vector<Event::GenObject> Mj_W;          //define W Container
  std::vector<Event::GenObject> Mj_Z;          //define Z Container
  

  
  //----------
  //Fill Particle Vectors
  //----------
  for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();
       j != ev.GenParticles().end();
       ++j) {      //Loop all Gen particles
    if (j->GetStatus()==3){                           //All stable particles
       int ID = abs(j->GetID());
      //      int ID = abs(j->GetID());
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
      case 23:
	Mj_Z.push_back(*j);
      }//End Switch
      
    }//End If
  }//End Gen Loop
  
  
  
  
  
  if( Mj_W.size()==1&&
      Mj_Electrons.size()==1 && 
      Mj_Neutrinos.size()==1){

    int iWeta=int((Mj_W[0].Eta()+5.));
    if (iWeta<0) iWeta=0;
    if (iWeta>9) iWeta=9;
    int iWPt=int(Mj_W[0].Pt()/5.);
    if (iWPt>9) iWPt=9;
    
    int iLPt=int(Mj_Electrons[0].Pt()/5.);
    if (iLPt>9) iLPt=9;
    if (Mj_W[0].GetID()==24) 
      NeuFromW[iWeta][iWPt][iLPt]->Fill(Mj_Neutrinos[0].Pt());
    
    if (Mj_W[0].GetID()==-24) 
      AntiNeuFromW[iWeta][iWPt][iLPt]->Fill(Mj_Neutrinos[0].Pt());
  
  }



  if( Mj_Z.size()==1&&
      Mj_Electrons.size()==2){
    int iZeta=int((Mj_Z[0].Eta()+5.));
    if (iZeta<0) iZeta=0;
    if (iZeta>9) iZeta=9;
    int iZPt=int(Mj_Z[0].Pt()/5.);
    if (iZPt>9) iZPt=9;

    if ((Mj_Electrons[0].GetID()==-11) &&(Mj_Electrons[1].GetID()==11)){
      int iposPt=int(Mj_Electrons[0].Pt()/5.);
      int ielePt=int(Mj_Electrons[1].Pt()/5.);
      if (iposPt>9) iposPt=9;
      if (ielePt>9) ielePt=9;
      EleFromZ[iZeta][iZPt][iposPt]->Fill(Mj_Electrons[1].Pt());
      PosFromZ[iZeta][iZPt][ielePt]->Fill(Mj_Electrons[0].Pt());
    }

    if ((Mj_Electrons[0].GetID()==11) &&(Mj_Electrons[1].GetID()==-11)){
      int iposPt=int(Mj_Electrons[1].Pt()/5.);
      int ielePt=int(Mj_Electrons[0].Pt()/5.);
      if (iposPt>9) iposPt=9;
      if (ielePt>9) ielePt=9;
      EleFromZ[iZeta][iZPt][iposPt]->Fill(Mj_Electrons[0].Pt());
      PosFromZ[iZeta][iZPt][ielePt]->Fill(Mj_Electrons[1].Pt());
    }   
  }


  return true; //No WENU in this event
}//End Method

// -----------------------------------------------------------------------------
//
std::ostream& ErsatzMet::Description( std::ostream& ostrm ) {
  ostrm << "Ersatz Operation";
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


