#ifndef SSDLEventPicker_hh
#define SSDLEventPicker_hh
#include "Operation.hh"
#include "Utils.hh"
#include "EventData.hh"

//AGB - An operation that lets you pick events from any data given a (set of) run, ls and event.

namespace SSDL{
  
  class SSDLEventPicker : public Operation::_Base{
    
  public:

    SSDLEventPicker(const Utils::ParameterSet& pset);
   
    ~SSDLEventPicker();

    void Start(Event::Data& ev);
    
    bool Process(Event::Data& ev);

    std::ostream& Description(std::ostream& ostrm);
    

  private:
    bool _PickEvents;
    std::vector<int> _Runs, _Lumis, _Events;

  };

}

#endif
    
