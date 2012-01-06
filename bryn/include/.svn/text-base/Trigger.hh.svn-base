#ifndef hadronic_include_Trigger_hh
#define hadronic_include_Trigger_hh

#include "PlottingBase.hh"
#include "Utils.hh"
#include "Types.hh"

class TH1D;
class TH2D;

namespace Operation {

  class Trigger : public PlottingBase {

  public:

    Trigger( const Utils::ParameterSet& );
    ~Trigger();

    void Start( Event::Data& );
    bool Process( Event::Data& );

    std::ostream& Description( std::ostream& );

  private:

    void BookHistos();

    std::string dirName_;
    UInt_t nMin_;
    UInt_t nMax_;
    bool ECompare(const LorentzV & o1, const LorentzV & o2);
    std::vector<TH1D*>  MET70SecondJet50;
    std::vector<TH1D*>  MET50SecondJet70;
    std::vector<TH1D*>  MET50SecondJet50;
    std::vector<TH1D*>  MHT70SecondJet70;
    std::vector<TH1D*>  MHT70SecondJet50;
    std::vector<TH1D*>  MHT50SecondJet70;
    std::vector<TH1D*>  MHT50SecondJet50;
    std::vector<TH1D*>  Ht200SecondJet70;
    std::vector<TH1D*>  Ht200Jet70;
    std::vector<TH1D*>  Ht150SecondJet70;
    std::vector<TH1D*>  Ht200SecondJet50;
    std::vector<TH1D*>  Ht200Jet50;
    std::vector<TH1D*>  Ht150Jet70;
    std::vector<TH1D*>  Ht150SecondJet50;
    std::vector<TH1D*>  Ht150Jet50;
    std::vector<TH1D*>  Ht300;
    std::vector<TH1D*>  Ht250;
    std::vector<TH1D*>  Ht200;
    std::vector<TH1D*>  Ht;
    std::vector<TH1D*>  MET60SecondJet35;
    std::vector<TH1D*>  Meffective250SecondJet35;
    std::vector<TH1D*>  Meffective250SecondJet40;
    std::vector<TH1D*>  Meffective250SecondJet45;
    std::vector<TH1D*>  Meffective325;
    std::vector<TH1D*>  Meffective300;
    std::vector<TH1D*>  Meffective275;
    std::vector<TH1D*>  Meffective250;
    std::vector<TH1D*>  Meffective450;
    std::vector<TH1D*>  Meffective425;
    std::vector<TH1D*>  Meffective400;
    std::vector<TH1D*>  Meffective375;
    std::vector<TH1D*>  Meffective350;
    std::vector<TH1D*>  MET45_HT250;
    std::vector<TH1D*>  MET50_HT250;
    std::vector<TH1D*>  MET65_HT200;
    std::vector<TH1D*>  MET80_HT180;
    std::vector<TH1D*>  HT260_MHT60;
    std::vector<TH1D*>  MET70SecondJet70;
    bool StandardPlots_;
    void StandardPlots();
    bool StandardPlots( Event::Data& );
    bool AlphaT_;
    bool Alphat( Event::Data &);
    void Alphat();
    };

  }

#endif // hadronic_include_Trigger_hh