#ifndef hadronic_include_ErsatzMet_hh
#define hadronic_include_ErsatzMet_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"
class TRandom;
class TH1D;
class TH2D;
class TH3D;


class ErsatzMet : public PlottingBase {

public:
  
  ErsatzMet(const std::string & filename, const Utils::ParameterSet& );
  ~ErsatzMet();
  void Start( Event::Data& );
  bool Process( Event::Data& );
  std::ostream& Description( std::ostream& );
  
private:
  
  void BookHistos();
  
  // Variables Here
  std::string dirName_;
  TH1D *PosFromZ[10][10][10];
  TH1D *EleFromZ[10][10][10];
  TH1D *NeuFromW[10][10][10];
  TH1D *AntiNeuFromW[10][10][10];   

  
};



#endif // hadronic_include_ErsatzMet_hh
