#ifndef triggerStudies_include_Ops_hh
#define triggerStudies_include_Ops_hh

#include "EventData.hh"
#include "Math/VectorUtil.h"
#include "Operation.hh"
#include "TH1F.h"

namespace Operation {
  class AlphatTriggerCut : public Operation::_Base {
  public:
    AlphatTriggerCut( float ,float,float);
    ~AlphatTriggerCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
  float cut_;
  float HTthresh_;
  float LowerBound_;
  };

  class MeffTriggerCut : public Operation::_Base {
  public:
    MeffTriggerCut( float ,float,float);
    ~MeffTriggerCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
  float cut_;
  float JetThreshold_;
  float MhtThreshold_;
  };


  class HtTriggerCut : public Operation::_Base {
  public:
    HtTriggerCut( float ,float);
    ~HtTriggerCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
  float cut_;
  float JetThreshold_;
  };



}

#endif // triggerStudies_include_Ops_hh
