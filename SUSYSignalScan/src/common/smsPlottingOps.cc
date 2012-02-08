#include "smsPlottingOps.hh"
#include "EventData.hh"
#include "GenMatrixBin.hh"
#include "Math/VectorUtil.h"
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


using namespace Operation;


//----------------------------------------------------------------------
smsPlottingOps::smsPlottingOps(  const Utils::ParameterSet& ps ) :
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
  verbose_(ps.Get<bool>("verbose")),
  ChiCut_(ps.Get<double>("MChiCut"))
{}


smsPlottingOps::~smsPlottingOps(){}

//
void smsPlottingOps::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();
}

//
void smsPlottingOps::BookHistos() {


    BookHistArray( H_M0_M12_mChi_noweight,
                   "m0_m12_mChi_noweight",
                   ";m0;m12;mChi;",
                   xBins_,xLow_,xHigh_, //m0
                   yBins_,yLow_,yHigh_, //m12
                   zBins_,zLow_,zHigh_, //mChi
                   1,0,1,false);


}




bool smsPlottingOps::Process( Event::Data& ev ) {
  // Event weight

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

  //NLO stuff: for the calculation of the NLO cross-section the processes are filled separately
  if(verbose_){
    std::cout << "The following branches are enabled/disabled\n" <<
        "M0 " << ev.M0.enabled() << "\n" <<
        "MG " << ev.MG.enabled() << "\n" <<
        "M12 " << ev.M12.enabled() << "\n" <<
        "MLSP " << ev.MLSP.enabled() << "\n" <<
        "MChi " << ev.MChi.enabled() << "\n";
  }



  if((ev.M0.enabled() || ev.MG.enabled())){
    if(ChiCut_ != -1 && MChi == ChiCut_){
      H_M0_M12_mChi_noweight[0]->Fill(M0,M12,MChi,1);
    }
    else if (ChiCut_ == -1) {
      H_M0_M12_mChi_noweight[0]->Fill(M0,M12,MChi,1);
    }
  }
  return true;
}


//
std::ostream& smsPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "sms scan 2d Plots ";
  return ostrm;
}
