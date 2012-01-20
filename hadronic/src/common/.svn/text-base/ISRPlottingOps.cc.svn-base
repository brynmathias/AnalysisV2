#include "ISRPlottingOps.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "GenMatrixBin.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include <sstream>
#include <string>
#include <iomanip>
//#include "NLOTools.hh"
#include <strstream>
#include <iostream>
#include <fstream>


#include "JetData.hh"
#include "CommonOps.hh"

//#include "LHAPDF/LHAPDF.h"


using namespace Operation;



 ISRPlottingOps::ISRPlottingOps( const Utils::ParameterSet& ps ) :
   dirName_( ps.Get<std::string>("DirectoryName")),
   ISRFile_(ps.Get<std::string>("ISRFile")),
   ISRDir_(ps.Get<std::string>("ISRDir")),
   xBins_(ps.Get<int>("xBins")),
   xLow_(ps.Get<double>("xLow")),
   xHigh_(ps.Get<double>("xHigh")),
   yBins_(ps.Get<int>("yBins")),
   yLow_(ps.Get<double>("yLow")),
   yHigh_(ps.Get<double>("yHigh")),
   zBins_(ps.Get<int>("zBins")),
   zLow_(ps.Get<double>("zLow")),
   zHigh_(ps.Get<double>("zHigh")),
   sets_(ps.Get<int>("sets")),
   verbose_(ps.Get<bool>("verbose"))
 {




 }




 ISRPlottingOps::~ISRPlottingOps(){}


void ISRPlottingOps::Start( Event::Data& ev ) {



  initDir( ev.OutputFile(), dirName_.c_str() );

  BookHistos();


  hist = getHisto("./",ISRDir_,ISRFile_);


}

void ISRPlottingOps::BookHistos() {



   BookHistArray( H_M0_M12,
      "m0_m12",
      ";m0;m12",
      xBins_,xLow_,xHigh_, //m0
      yBins_,yLow_,yHigh_, //m12
      zBins_,zLow_,zHigh_, //mChi
      1, 0, 1,false );

   BookHistArray( H_M0_M12_ISRWeight,
      "m0_m12_ISRWeight",
      ";m0;m12",
      xBins_,xLow_,xHigh_, //m0
      yBins_,yLow_,yHigh_, //m12
      100,0.,2., //mChi
      1, 0, 1,false );

   BookHistArray( H_M0_M12_X,
      "m0_m12_X",
      ";m0;m12",
      xBins_,xLow_,xHigh_, //m0
      yBins_,yLow_,yHigh_, //m12
      100,0.,1000, //mChi
      1, 0, 1,false );

   BookHistArray( H_M0_M12_njets_ISR,
      "m0_m12_njets_ISR",
      ";m0;m12",
      xBins_,xLow_,xHigh_, //m0
      yBins_,yLow_,yHigh_, //m12
      100,0.,100, //mChi
      1, 0, 1,false );

   BookHistArray( H_M0_M12_njets,
      "m0_m12_njets",
      ";m0;m12",
      xBins_,xLow_,xHigh_, //m0
      yBins_,yLow_,yHigh_, //m12
      100,0.,100, //mChi
      1, 0, 1,false );

}


bool ISRPlottingOps::Process( Event::Data& ev ) {

  double M0 = 0.;
  double M12 = 0.;
  double MChi = 0.;

  if(ev.M0.enabled()){
    M0 = ev.M0();
  }
  if(ev.MG.enabled()){
    M0 = ev.MG();
  }
  if(ev.M12.enabled()){
    M12 = ev.M12();
  }
  if(ev.MLSP.enabled()){
    M12 = ev.MLSP();
  }

  if(ev.MChi.enabled()){
    MChi = ev.MChi();
  }

  Double_t weight = ev.GetEventWeight();

  Int_t numJets = ev.JD_CommonJets().accepted.size();


  double x = 0.;// NLO::ISRProducer(ev);



  int bin = hist->FindBin(M0,M12,x);

  double ISRWeight = hist->GetBinContent(bin);

  // cout << "weight " << ISRWeight << endl;


    H_M0_M12[0]->Fill(M0,M12,MChi,weight*ISRWeight);

    H_M0_M12_ISRWeight[0]->Fill(M0,M12,ISRWeight);

    H_M0_M12_X[0]->Fill(M0,M12,x);

    H_M0_M12_njets_ISR[0]->Fill(M0,M12,numJets,weight*ISRWeight);

    H_M0_M12_njets[0]->Fill(M0,M12,numJets,weight);


  return true;

}





std::ostream& ISRPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "ISR mSuGra scan 2d Plots ";
  return ostrm;
}


TH3D* ISRPlottingOps::getHisto( TString path,
             TString nameHist,
             TString nameFile
        ) {
  TString name = path + nameFile;
  TFile* file =  new TFile(name);

  TH3D* hist = (TH3D*)file->Get(nameHist);
  if (!hist) {
    std::cout << " name: " << nameHist
        << " file: " << nameFile
        << std::endl;
    abort();

  }




  return hist;
}




