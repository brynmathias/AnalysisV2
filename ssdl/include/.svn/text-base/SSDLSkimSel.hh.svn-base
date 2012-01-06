#ifndef SSDLSkimSel_hh
#define SSDLSkimSel_hh
#include "Operation.hh"
#include "EventData.hh"
#include "Utils.hh"
#include "LepFilters.hh"

namespace SSDL{

  class SSDLSkimSel : public Operation::_Base{

  public:

    SSDLSkimSel(const Utils::ParameterSet & ps1, const Utils::ParameterSet & ps2, const Utils::ParameterSet & ps2pat, const Utils::ParameterSet & ps3);
    ~SSDLSkimSel();
    
    void Start(Event::Data & ev);

    bool Process(Event::Data & ev);
    
    std::ostream& Description(std::ostream & ostrm);

  private:

    CustomEleId elid;
    CustomMuonId muidpf;
    CustomMuonId muidpat;
    CustomTauId tauid;
    int ele,mu,tau;

  };

}

#endif
