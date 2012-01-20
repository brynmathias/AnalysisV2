#ifndef ICF_COMPUTE_HH
#define ICF_COMPUTE_HH

#include "Compute_Variable.hh"
#include <cstdlib>
#include <vector>
#include "Lepton.hh"
#include "GenObject.hh"
#include "Photon.hh"
#include "Jet.hh"
#include "Utils.hh"
namespace ICF{
class NtupleData;
}

namespace ICF{
  // Generator-level particles
class GenParticles : public Compute::Variable<std::vector<Event::GenObject>, GenParticles,ICF::NtupleData> {
  public:
    GenParticles(const ICF::NtupleData & ev);
    void _Update() const;
  };

   // Electrons
class Electrons : public Compute::Variable<std::vector<Event::Lepton>, Electrons, ICF::NtupleData> {
 public:
  Electrons(const ICF::NtupleData & ev);
  void _Update() const;
};

    // Muons
    class Muons : public Compute::Variable<std::vector<Event::Lepton>, Muons,ICF::NtupleData> {
    public:
      Muons(const ICF::NtupleData & ev);
      void _Update() const;
    };
    // Muons
    class SecMuons : public Compute::Variable<std::vector<Event::Lepton>, SecMuons,ICF::NtupleData> {
    public:
      SecMuons(const ICF::NtupleData & ev);
      void _Update() const;
    };
    // Taus
    class Taus : public Compute::Variable<std::vector<Event::Lepton>, Taus,ICF::NtupleData> {
    public:
      Taus(const ICF::NtupleData & ev);
      void _Update() const;
    };

    class SecTaus : public Compute::Variable<std::vector<Event::Lepton>, SecTaus,ICF::NtupleData> {
    public:
      SecTaus(const ICF::NtupleData & ev);
      void _Update() const;
    };
 // Jets
  class Jets : public Compute::Variable<std::vector<Event::Jet>, Jets,ICF::NtupleData> {
  private:
    const bool Uncorrectedjets;
    
    public:
      Jets(const ICF::NtupleData & ev);
      void _Update() const;
    };

  //AGB - 28/10/10
  class SecJets : public Compute::Variable<std::vector<Event::Jet>, SecJets, ICF::NtupleData> {
   public:
    SecJets(const ICF::NtupleData & ev);
    void _Update() const;
   private: //<TW date="07/11/2010" />
    const bool mUncorrectedSecJets;
  };

	/*! \brief Tertiary jet collection.
	 * @author T. Whyntie
	 * @date 13/11/2010
	 */
  class TerJets : public Compute::Variable<std::vector<Event::Jet>, TerJets, ICF::NtupleData> {
   public:
    TerJets(const ICF::NtupleData & ev);
    void _Update() const;
   private:
    const bool mUncorrectedTerJets;
  };

    // Moved from ICF::NtupleData
    class Photons : public Compute::Variable<std::vector<Event::Photon>, Photons,ICF::NtupleData> {
    public:
      Photons(const ICF::NtupleData & ev);
      void _Update() const;
    };

// Missing track pt computational variable
class MPT : public Compute::Variable<LorentzV, MPT,ICF::NtupleData> {
  public:
  MPT(const ICF::NtupleData & ev);
    void _Update() const;
  };


// AK5MET
class AK5MET : public Compute::Variable<LorentzV, AK5MET,ICF::NtupleData> {
 public:
  AK5MET(const ICF::NtupleData & ev);
  void _Update() const;
};

// CaloMET
class CaloMET : public Compute::Variable<LorentzV, CaloMET,ICF::NtupleData> {
 public:
  CaloMET(const ICF::NtupleData & ev);
  void _Update() const;
};

// IC5MET computational variable
class IC5MET : public Compute::Variable<LorentzV, IC5MET,ICF::NtupleData> {
 public:
  IC5MET(const ICF::NtupleData & ev);
  void _Update() const;
};

// PFMET computational variable
class PFMET : public Compute::Variable<LorentzV, PFMET,ICF::NtupleData> {
 public:
  PFMET(const ICF::NtupleData & ev);
  void _Update() const;
  mutable Compute::ObjectProcessor<ICF_LorentzV> met_proc;
};

// TCMET computational variable
class TCMET : public Compute::Variable<LorentzV, TCMET,ICF::NtupleData> {
 public:
  TCMET(const ICF::NtupleData & ev);
  void _Update() const;
};

// CaloMETnohf computational variable
class CaloMETnohf : public Compute::Variable<LorentzV,
                                             CaloMETnohf,ICF::NtupleData>{
public:
  CaloMETnohf(const ICF::NtupleData & ev);
  void _Update() const;
};



// CaloMETtypeII computational variable
class CaloMETtypeII : public Compute::Variable<LorentzV,
                                             CaloMETtypeII,ICF::NtupleData>{
public:
  CaloMETtypeII(const ICF::NtupleData & ev);
  void _Update() const;
};


}
#endif
