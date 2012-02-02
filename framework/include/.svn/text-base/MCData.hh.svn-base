/*! \file MCData.hh
 * \brief Header file for the Monte Carlo data container EventStuff::MCData.
 */
#ifndef MCData_hh
#define MCData_hh

#include <vector>
#include "Compute_Variable.hh"
#include "Types.hh"
namespace Event {
  class GenObject;
}

namespace Compute {
  namespace MC {

    ////////////////////////////////
    // Help functions
    ////////////////////////////////
    void PrintParticle(const Event::GenObject & p);
    void PrintGen(const Event::Data & ev); //!< Prints out the Gen Info collection.
    void PrintChain(const Event::Data & ev);
    void PrintEndChain(const Event::Data & ev); //!< Prints the end of the chain.
    void PrintGenLeptons(const Event::Data & ev);

//     class Leptons : public Compute::Variable<std::vector<int>, Leptons> {
//     public:
//       Leptons(const Event::Data & ev);
//       void _Update() const;
//     };

  // added loukas
  class GenLeptons :
        public Compute::Variable<std::vector<Event::GenObject const *>,
                                 GenLeptons> {
   public:
    GenLeptons(const Event::Data & ev);
    void _Update() const;
   private:
    const double mElEtCut;
    const double mElEtaCut;
    const double mMuEtCut;
    const double mMuEtaCut;
  };
  // ~ added loukas

    class SingleLepMET : public Compute::Variable<LorentzV, SingleLepMET> {
    public:
      SingleLepMET(const Event::Data & ev);
      void _Update() const;
    };

    class SingleLepHT : public Compute::Variable<Double_t, SingleLepHT> {
    public:
      SingleLepHT(const Event::Data & ev);
      void _Update() const;
    };

    class SingleLepMHT : public Compute::Variable<LorentzV, SingleLepMHT> {
    public:
      SingleLepMHT(const Event::Data & ev);
      void _Update() const;
    };

    struct First_Data {
      std::vector<std::pair<int, int> > tau;
      int mother;
    };
    class First : public Compute::Variable<First_Data, First> {
    public:
      First(const Event::Data & ev);
      void _Update() const;
    };

    struct Second_Data {
      std::vector<std::pair<int, int> > tau;
      int mother;
    };
    class Second : public Compute::Variable<Second_Data, Second> {
    public:
      Second(const Event::Data & ev);
      void _Update() const;
    };

    class LeptonsTau : public Compute::Variable<std::vector<int>, LeptonsTau> {
    public:
      LeptonsTau(const Event::Data & ev);
      void _Update() const;
    };

    struct Final_Data {
      int state;
      int tau;
    };
    class Final : public Compute::Variable<Final_Data, Final> {
    public:
      Final(const Event::Data & ev);
      void _Update() const;
    };

    class AllLeptons : public Compute::Variable<std::vector<Event::GenObject const *>, AllLeptons> {
    public:
      AllLeptons(const Event::Data & ev);
      void _Update() const;
    };

    class TheLeptons : public Compute::Variable<std::vector<Event::GenObject const *>, TheLeptons> {
    public:
      TheLeptons(const Event::Data & ev);
      void _Update() const;
    };

    class TheIsolatedLeptons : public Compute::Variable<std::vector<Event::GenObject const *>, TheIsolatedLeptons> {
    public:
      TheIsolatedLeptons(const Event::Data & ev);
      void _Update() const;
    };

    class TheNeutrinos : public Compute::Variable<std::vector<Event::GenObject const *>, TheNeutrinos> {
    public:
      TheNeutrinos(const Event::Data & ev);
      void _Update() const;
    };

    class TheLSPs : public Compute::Variable<std::vector<Event::GenObject const *>, TheLSPs> {
    public:
      TheLSPs(const Event::Data & ev);
      void _Update() const;
    };

    class ThePartons : public Compute::Variable<std::vector<Event::GenObject const *>, ThePartons> {
    public:
      ThePartons(const Event::Data & ev);
      void _Update() const;
    };

    class AllPartons : public Compute::Variable<std::vector<Event::GenObject const *>, AllPartons> {
    public:
      AllPartons(const Event::Data & ev);
      void _Update() const;
    };

    class SSFinalState : public Compute::Variable<int, SSFinalState> {
    public:
      SSFinalState(const Event::Data & ev);
      void _Update() const;
    private:
      TheIsolatedLeptons lep_;
    };

    // General gen particle data access.



    // Public data member access
    //---------------------------
    //const std::vector<GenObject> & GetGenParticles(); //!< Get a const ref to the GenParticles.

    /*! \brief Returns a bool indicating whether gen particle with index i was from a SUSY cascade.
     *
     * \author Marc Weinberg
     *
     * @param [in] index The index of the gen particle to query.
     * @return If particle present, whether from a SUSY cascade or not. Otherwise false.
     */
    //Bool_t WasItSusy(UInt_t index);

    // General gen particle data
    //std::vector<GenObject> GenParticles; //!< Vector of the gen particles as obtained from the Ntuple.

    // Leptonic gen particle data
    //bool IsMCSSDilepton();
    //int  SSFinalState(){return 34;};
    //int  SSFinalStateTauDecay();
    //std::vector<int> Leptons();
    //int  FirstLeptonMother();
    //int  SecondLeptonMother();
    //std::vector<std::pair<int,int> > FirstTauProducts();
    //std::vector<std::pair<int,int> > SecondTauProducts();


    //}; // ~class MCData

  } // ~namespace MC
} // ~namespace Compute

#endif //~MCData_hh
