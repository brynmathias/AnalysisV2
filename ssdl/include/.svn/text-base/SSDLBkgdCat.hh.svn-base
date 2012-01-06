#ifndef SSDLBkgdCat_hh
#define SSDLBkgdCat_hh
#include "PlottingBase.hh"
#include "Operation.hh"
#include "EventData.hh"

namespace SSDL{

  class SSDLBkgdCat : public PlottingBase{

  public:

    SSDLBkgdCat(double htcut, double mhtcut,const std::string & folderName);
    ~SSDLBkgdCat();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream & ostrm);
    void BookHistos();

  private:

    double _htcut, _mhtcut;
    std::string mFoldername;
    TH1D* h_ee,* h_mumu, *h_tautau, *h_emu, *h_etau, *h_mutau;

  };
} 

#endif
