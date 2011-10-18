#ifndef bryn_include_Ops_hh
#define bryn_include_Ops_hh

#include "EventData.hh"
#include "Math/VectorUtil.h"
#include "Operation.hh"
// #include "DeadECALDR.hh"


namespace Operation {


class confHT : public Operation::_Base
{
public:
  confHT (float JetEtThreshold,float cutVal);
  ~confHT (){;}
  bool Process( Event::Data&);
  std::ostream& Description( std::ostream& );
private:
  float JetEt_;

  float cut_;
};



class alphaTriggerEmu : public Operation::_Base
{
public:
  alphaTriggerEmu (float aT_Thresh,float JetEtThreshold, float HTThreshold,int maxNjets);
 ~alphaTriggerEmu (){;}
  bool Process( Event::Data&);
  std::ostream& Description( std::ostream& );
private:
  /* data */
  float aTCut_;
  float HtCut_;
  float JetEt_;
  int maxNjets_;
};

}

#endif // bryn_include_Ops_hh





