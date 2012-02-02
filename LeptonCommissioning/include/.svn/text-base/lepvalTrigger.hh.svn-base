#ifndef lepvalTrigger_hh
#define lepvalTrigger_hh
#include "Operation.hh"
#include "EventData.hh"

namespace lepval{

  class LepValTrigger : public Operation::_Base{

  public:

    LepValTrigger(const std::string& triggername);

    ~LepValTrigger();

    bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream & ostrm);

  private:

    const std::string mTriggername;

  };
}
#endif
