#ifndef ISRPLOTTINGOPS
#define ISRPLOTTINGOPS

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

   class ISRPlottingOps : public PlottingBase {

  public:
    ISRPlottingOps( const Utils::ParameterSet& );
    ~ISRPlottingOps();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream &);

  private:

    void BookHistos();

    std::string dirName_;
    std::string ISRFile_;
    std::string ISRDir_;

    

    std::vector<TH3D *> H_M0_M12;

    std::vector<TH3D *> H_M0_M12_X;

    std::vector<TH3D *> H_M0_M12_ISRWeight;

    std::vector<TH3D *> H_M0_M12_njets;

    std::vector<TH3D *> H_M0_M12_njets_ISR;


    TH3D* hist;

    TH3D* getHisto( TString path,
		    TString nameHist,
		    TString nameFile
		    ); 

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
