#ifndef lepvalCuts_hh
#define lepvalCuts_hh

#include "Operation.hh"
#include "EventData.hh"

namespace lepval{

  class LepValHT_Cut : public Operation::_Base{

  public:

    LepValHT_Cut(double htcut);
    ~LepValHT_Cut();
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream & ostrm);

  private:

    double _htcut;

  };
}
#endif
