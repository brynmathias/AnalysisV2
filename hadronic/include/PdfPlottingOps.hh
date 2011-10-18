#ifndef PDFPLOTTINGOPS
#define PDFPLOTTINGOPS

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

#include <strstream>
#include <iostream>
#include <fstream>

class TH1D;
class TH2D;

namespace Operation {

  class PDFPlottingOps : public PlottingBase {

  public:
    PDFPlottingOps( const Utils::ParameterSet& );
    ~PDFPlottingOps();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream &);

  private:

    void BookHistos();

      std::string dirName_;
   

   

    std::vector<TH3D *> H_M0_M12_cteq66;
    std::vector<TH3D *> H_M0_M12_MSTW2008;
    std::vector<TH3D *> H_M0_M12_NNPDF;
    
    std::vector<TH3D *> H_M0_M12_pdfweight;

    int    xBins_;
    double xLow_;
    double xHigh_;
    int    yBins_;
    double yLow_;
    double yHigh_;
    int    zBins_;
    double zLow_;
    double zHigh_;
    int sets_;

    bool verbose_;

  };

}

#endif // hadronic_include_BkgdEstPlottingOps_hh
