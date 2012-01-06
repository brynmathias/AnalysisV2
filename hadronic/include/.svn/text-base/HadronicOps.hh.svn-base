#ifndef hadronic_include_HadronicOps_hh
#define hadronic_include_HadronicOps_hh

#include "EventData.hh"
#include "Math/VectorUtil.h"
#include "Operation.hh"
#include "TH1F.h"
#include "DeadECALDR.hh"


namespace Operation {

   class genProcess : public Operation::_Base{
    public:
      genProcess ( std::string  );
      ~genProcess () {;}
      bool Process( Event::Data& );
      std::ostream& Description( std::ostream& );
    private:
      std::string  cut_process_;
    };



    class gensignalProcessID : public Operation::_Base{
    public:
      gensignalProcessID ( int ,int,int,int );
      ~gensignalProcessID () {;}
      bool Process( Event::Data& );
      std::ostream& Description( std::ostream& );
    private:
      /* data */
      int cut1_;
      int cut2_;
      int cut3_;
      int cut4_;
    };

  class HadronicHT_SecondJetCut : public Operation::_Base
  {
  public:
    HadronicHT_SecondJetCut (float, float);
    ~HadronicHT_SecondJetCut (){};
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float secondJetCut_;
    float HTCut_;
  };


  class HadronicAlphaT : public Operation::_Base {
  public:
    HadronicAlphaT( float );
    ~HadronicAlphaT() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };

 class NPvs : public Operation::_Base {

  public:


   NPvs(const std::string & comparison, UInt_t number);

    ~NPvs(); //!< Destructor.

   bool Process(Event::Data & ev);

    std::ostream& Description(std::ostream& ostrm);

 private:

   //--------------------------------
   Operation::_Compare<UInt_t> *mComparison; //!< Comparison string, i.e. "==", ">=", etc.
   UInt_t mNumber;           //!< Number of common leptons with which to compare.

 }; // ~Num verticies




  class UnCorrCut : public Operation::_Base {
  public:
    UnCorrCut( float );
    ~UnCorrCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };

  class DeadECALCut : public Operation::_Base {
  public:
    DeadECALCut( float,float,float,float,int,bool,TString );
    ~DeadECALCut() {;}
    bool Process( Event::Data& );
    bool Process( Event::Data&, std::vector<LorentzV>&, std::vector<LorentzV>& );
    std::ostream& Description( std::ostream& );
  private:
    float cut2_;
    float cut_;
    float minBiasCut_;
    float minJetPtCut_;
    int nBadCells_;
    bool deadECALFromFile_;
    TString deadECALfile_;
   };

  class MHTOvCaloMETCut: public Operation::_Base{
  public:
    MHTOvCaloMETCut( float );
    ~MHTOvCaloMETCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;

  };

  class MHTPFMETDiffOvMeffCut: public Operation::_Base{
  public:
    MHTPFMETDiffOvMeffCut( float );
    ~MHTPFMETDiffOvMeffCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;

  };


  class MHToverMET: public Operation::_Base{
  public:
    MHToverMET( float, float );
    ~MHToverMET() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
    float threshold_;
  };
  class MHToverPFMET: public Operation::_Base{
  public:
    MHToverPFMET( float );
    ~MHToverPFMET() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;

  };




  class ReversedPFMET : public Operation::_Base {
  public:
    ReversedPFMET( float );
    ~ReversedPFMET() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };

  class PFMET : public Operation::_Base {
  public:
    PFMET( float );
    ~PFMET() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };

  class BabyMHT : public Operation::_Base {
  public:
    BabyMHT( float );
    ~BabyMHT() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };

  class ReversedBabyMHT : public Operation::_Base {
  public:
    ReversedBabyMHT( float );
    ~ReversedBabyMHT() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };

   class BabyMHTovHT : public Operation::_Base {
  public:
    BabyMHTovHT( float );
    ~BabyMHTovHT() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };


  class MHTovHT : public Operation::_Base {
  public:
    MHTovHT( float );
    ~MHTovHT() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };
  /*
  class LowPtBiasedDphi : public Operation::_Base {
  public:
    LowPtBiasedDphi( float );
    ~LowPtBiasedDphi() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
   };

  */

  class HadronicCut : public Operation::_Base {
  public:
    HadronicCut( float );
    ~HadronicCut() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };


  class VertexPtOverHT : public Operation::_Base {
  public:
    VertexPtOverHT( float );
    ~VertexPtOverHT() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
  };

  class TriggerMHT_Emu : public Operation::_Base {
  public:
     TriggerMHT_Emu(float, float);
    ~TriggerMHT_Emu() {;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
    float Threshold_;
  };



  class TriggerHT_Emu : public Operation::_Base {
  public:
    TriggerHT_Emu (float, float);
    ~TriggerHT_Emu (){;}
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
  private:
    float cut_;
    float Threshold_;
    /* data */
  };

  class confiurableOddJet : public Operation::_Base
  {
  public:
    confiurableOddJet (float);
    ~confiurableOddJet (){;}
    bool Process( Event::Data& );
    std::ostream&  Description( std::ostream& );
  private:
    float Threshold_;
    /* data */
  };




  class sumRecHitPtCut : public Operation::_Base
  {
  public:
    sumRecHitPtCut (float);
    ~sumRecHitPtCut (){;}
    bool Process( Event::Data& );
    std::ostream&  Description( std::ostream& );
  private:
    float cut_;
  };


}

#endif // hadronic_include_HadronicOps_hh





