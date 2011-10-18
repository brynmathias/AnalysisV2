//#ifndef CountsAndBSMGrids
//#define CountsAndBSMGrids

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

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

   class CountsAndBSMGrids : public PlottingBase {

   public:

     CountsAndBSMGrids( const Utils::ParameterSet& );
     ~CountsAndBSMGrids();

     void Start( Event::Data& );
     bool Process( Event::Data& );

     Double_t GetKfactor(Int_t m0, Int_t m12, TString process,TString kFactorFile);
     std::ostream& Description( std::ostream& );
 private:

     void BookHistos();
     TH1D * SMHist;
     TH2D * H_M0_M12;
     TH1D * CxjetsMultHist;
     TH2D * CxjetsMult_Meff_Hist;
     TH2D * CxjetsMult_Meff_prime_Hist;
     TH2D* CxjetsMult_HTlep_Hist;
     TH2D* CxjetsMult_HThad_Hist;
     TH1D * MuPhiPlus;
     TH1D * MuPhiMinus;

     std::string dirName_;
     std::string mSuGraFile_;
     int    xBins_;
     double xLow_;
     double xHigh_;
     int    yBins_;
     double yLow_;
     double yHigh_;


   };
}
//#endif
