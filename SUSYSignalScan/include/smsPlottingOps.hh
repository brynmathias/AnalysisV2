#ifndef SMSPLOTTINGOPS
#define SMSPLOTTINGOPS

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
#include "Math/VectorUtil.h"
#include "ThrustStuff.hh"
#include "TH3.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

// #include <strstream>
#include <iostream>
// #include <fstream>
// #include "LHAPDF/LHAPDF.h"

class TH1D;
class TH2D;



namespace Operation {

  class smsPlottingOps : public PlottingBase {


  public:

    smsPlottingOps( const Utils::ParameterSet& );
    ~smsPlottingOps();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();
    //     void BookHistos(){}
    std::string dirName_;
    bool verbose_;

    std::vector<TH3D *> H_M0_M12_mChi_noweight;


    int    xBins_;
    double xLow_;
    double xHigh_;
    int    yBins_;
    double yLow_;
    double yHigh_;
    int    zBins_;
    double zLow_;
    double zHigh_;

    double ChiCut_;
  }; //~mSuGra scan class
}
#endif
