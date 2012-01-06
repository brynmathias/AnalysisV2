#include "BkgdEstPlottingOps.hh"
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

#include <strstream>
#include <iostream>
#include <fstream>


#include "JetData.hh"
#include "CommonOps.hh"
/*
#include "LHAPDF/LHAPDF.h"


using namespace Operation;



 PDFPlottingOps::PDFPlottingOps( const Utils::ParameterSet& ps ) :  
   dirName_( ps.Get<std::string>("DirectoryName")),
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




 PDFPlottingOps::~PDFPlottingOps(){}

 
void PDFPlottingOps::Start( Event::Data& ev ) {

 

  initDir( ev.OutputFile(), dirName_.c_str() );
  
  BookHistos();

   //Set up the PDF uncertainty calculation:
  const int SUBSET = 0; //pdf subset
  if(verbose_ == true)std::cout << "initialising PDF Set" << std::endl;
  LHAPDF::Verbosity verbose = LHAPDF::SILENT; //set to silent so it doesn't print out a load of stuff (see the include/LHAPDF.h for more)
  LHAPDF::setVerbosity(verbose);
 
  //Set up the PDF uncertainty calculation:

  const string NAME1 = "/afs/cern.ch/user/t/trommers/scratch0/LHAPDFlibs/bin/cteq66.LHgrid"; //location of the pdf set
  const string NAME2 = "/afs/cern.ch/user/t/trommers/scratch0/LHAPDFlibs/bin/MSTW2008nlo68cl.LHgrid"; //location of the pdf set
  const string NAME3 = "/afs/cern.ch/user/t/trommers/scratch0/LHAPDFlibs/bin/NNPDF20_100.LHgrid";

  LHAPDF::initPDFSet(1,NAME1);
  LHAPDF::initPDFSet(2,NAME2);
  LHAPDF::initPDFSet(3,NAME3);
 
  
 
  LHAPDF::initPDF(0);

 
  
}

void PDFPlottingOps::BookHistos() {

  
   
   BookHistArray( H_M0_M12_cteq66,
		  "m0_m12_cteq66",
		  ";m0;m12",
		  xBins_,xLow_,xHigh_, //m0
		  yBins_,yLow_,yHigh_, //m12
		  zBins_,zLow_,zHigh_, //mChi
		  45, 0, 1,false );

   BookHistArray( H_M0_M12_MSTW2008,
		  "m0_m12_MSTW2008",
		  ";m0;m12",
		  xBins_,xLow_,xHigh_, //m0
		  yBins_,yLow_,yHigh_, //m12
		  zBins_,zLow_,zHigh_, //mChi
		  41, 0, 1,false );

   BookHistArray( H_M0_M12_NNPDF,
		  "m0_m12_NNPDF",
		  ";m0;m12",
		  xBins_,xLow_,xHigh_, //m0
		  yBins_,yLow_,yHigh_, //m12
		  zBins_,zLow_,zHigh_, //mChi
		  101, 0, 1,false );

   BookHistArray( H_M0_M12_pdfweight,
		  "m0_m12_pdfweight",
		  ";m0;m12",
		  xBins_,xLow_,xHigh_, //m0
		  yBins_,yLow_,yHigh_, //m12
		  100,0,10, //mChi
		  sets_, 0, 1,false );
  
}


bool PDFPlottingOps::Process( Event::Data& ev ) {
  
  double M0=0;
  double M12=0;
  double MChi =0;
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
 
  
  //now set up the baseline values with which to weight relative to:
  double pdf1 = ev.genpdf1();
  double pdf2 = ev.genpdf2();
  
  if(verbose_ == true){
    std::cout << "pdf1: " << pdf1 << std::endl;
    std::cout << "pdf2: " << pdf2 << std::endl;
  }
  
  for(unsigned int k = 1; k <= 3; ++k){
    const int NUMBER = LHAPDF::numberPDF(k);

    if(verbose_ == true)cout << " number " << NUMBER << endl;
    
    for (int n = 0; n < NUMBER + 1; ++n) {
      if(verbose_ == true)cout << "Set number: " << n << endl;
      LHAPDF::usePDFMember(k,n);
      double newpdf1 =  LHAPDF::xfx(k,ev.genx1(), ev.genQ(), ev.genid1())/ev.genx1();
      double newpdf2 =  LHAPDF::xfx(k,ev.genx2(), ev.genQ(), ev.genid2())/ev.genx2();
      double PDFUncWeight = (newpdf1/pdf1)*(newpdf2/pdf2);
      
      if(verbose_ == true)cout << " n " << n << " k " << k << " M12 " << M12 << " chi " << " pdfweight " << PDFUncWeight << endl;
      
      
      if(k==1)H_M0_M12_cteq66[n]->Fill(M0,M12,MChi,weight*PDFUncWeight);
      if(k==2)H_M0_M12_MSTW2008[n]->Fill(M0,M12,MChi,weight*PDFUncWeight);
      if(k==3)H_M0_M12_NNPDF[n]->Fill(M0,M12,MChi,weight*PDFUncWeight);

     
    }
  }
  return true;
   
}





std::ostream& PDFPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "PDF mSuGra scan 2d Plots ";
  return ostrm;
}



*/


