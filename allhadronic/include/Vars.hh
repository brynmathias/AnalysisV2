#ifndef allhadronic_include_Vars_hh
#define allhadronic_include_Vars_hh

#include "Types.hh"
#include "Utility.hh"
#include <sstream>

namespace allhadronic {
  
  /**
     Simple container class for jet- and event-level variables
  */
  class Vars {
    
  public:
    
    Vars();
    
    void clear();
    void push_back( const LorentzV& );
    void update();
    void print( std::stringstream& );
    
    const std::vector<LorentzV>& jets() const;
    const std::vector<bool>& pseudo() const;
    const LorentzV& jet1() const;
    const LorentzV& jet2() const;
    int njets() const;
    double ht() const;
    double dht() const;
    LorentzV mht() const;
    double at() const;
    double meff() const;
    double x1() const;
    double x2() const;
    //int bin() const;
    bool updated() const;
    
  private:
    
    std::vector<LorentzV> jets_;
    std::vector<bool> pseudo_;
    LorentzV j1_;
    LorentzV j2_;
    double ht_;
    double dht_;
    LorentzV mht_;
    double at_;
    double meff_;
    double x1_;
    double x2_;
    bool updated_;
    
  };
  
  inline const std::vector<LorentzV>& Vars::jets() const { return jets_; }
  inline const std::vector<bool>& Vars::pseudo() const { return pseudo_; }
  inline const LorentzV& Vars::jet1() const { return j1_; }
  inline const LorentzV& Vars::jet2() const { return j2_; }
  inline int Vars::njets() const { return jets_.size(); }
  inline double Vars::ht() const { return ht_; }
  inline double Vars::dht() const { return dht_; }
  inline LorentzV Vars::mht() const { return mht_; }
  inline double Vars::at() const { return at_; }
  inline double Vars::meff() const { return meff_; }
  inline double Vars::x1() const { return x1_; }
  inline double Vars::x2() const { return x2_; }
  inline bool Vars::updated() const { return updated_; }

}

#endif // allhadronic_include_Vars_hh
