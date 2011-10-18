#ifndef Zplots_hh
#define Zplots_hh

#include "Operation.hh"
#include "PlottingBase.hh"

namespace Operation {
  class Zplots : public PlottingBase {
    
  public:
    // Standard Operation methods.
    
    Zplots(const std::string & foldername);
    ~Zplots();
    void BookHistos();
    void Start(Event::Data & ev);
    bool Process(Event::Data & ev);
    std::ostream& Description(std::ostream& ostrm);
    
  private:
    
    std::string mFolderName;
    
    TH1D* LP_pos;
    TH1D* LP_neg;
    TH1D* LP_tot;

    TH2D* Mass2DP;
    TH2D* Mass2DM;
    TH2D* EtaPhiP;
    TH2D* EtaPhiM;


    TH1D* MassP;
    TH1D* MassM;
    TH1D* Mass100P;
    TH1D* Mass100M;
    TH1D* MTM;
    TH1D* MTP;
    TH1D* MTF;
    TH1D* MTS;
    TH1D* MTL;
 

  }; //~Zplots class

} 

#endif
