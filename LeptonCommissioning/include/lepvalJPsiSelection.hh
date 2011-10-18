#ifndef lepvalJPsiSelection_hh
#define lepvalJPsiSelection_hh

#include "Compute_User.hh"
#include "EventData.hh"


namespace lepval{

  class LepValJPsiMu : public Compute::User<std::vector<Event::Lepton const *>, LepValJPsiMu> {

  public:
    
    LepValJPsiMu(bool applyselec, double d0, double dz, double normchi2Global, double normchi2Trk, double siTrkHits);
    ~LepValJPsiMu();
    void _Update() const;
    std::ostream& Description(std::ostream & ostrm);

  private:
    
    bool _applyselec; 
    double _d0, _dz, _normchi2Global, _normchi2Trk, _siTrkHits;

  };

}

#endif
    
    
    
