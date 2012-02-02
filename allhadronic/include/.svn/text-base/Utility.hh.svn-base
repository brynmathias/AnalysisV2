#ifndef allhadronic_include_Utility_hh
#define allhadronic_include_Utility_hh

#include "Types.hh"
#include <Math/PtEtaPhiE4D.h>

namespace allhadronic {

  // Useful typedefs
  //typedef unsigned int uint;

  typedef std::vector<LorentzV> LorentzVs;

  typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<float> > PtEtaPhiE;
  
  // Sorting algorithms
  inline bool SortByEt( const LorentzV& first, const LorentzV& second ) { return ( first.Et() > second.Et() ); }
  inline bool SortByPt( const LorentzV& first, const LorentzV& second ) { return ( first.Pt() > second.Pt() ); }

  // Returns massless jet
  inline LorentzV massless( const LorentzV& jet ) { return LorentzV( jet.Et(), jet.Eta(), jet.Phi(), 0. ); }
  
}

#endif // allhadronic_include_Utility_hh
