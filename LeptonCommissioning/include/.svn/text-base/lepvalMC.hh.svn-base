#ifndef lepvalMC_hh
#define lepvalMC_hh

#include <vector>
#include "Compute_User.hh"
#include "Types.hh"
#include "EventData.hh"


namespace lepval{

  class IsolatedLeptons : public Compute::User<std::vector<Event::GenObject const *>, IsolatedLeptons> {
  public:
    IsolatedLeptons();
    ~IsolatedLeptons(){}
    void _Update() const;
    std::ostream & Description(std::ostream & ostrm);
  private:
    double mMCLepPtCut, mMCLepEtaCut;
  };
}

#endif
