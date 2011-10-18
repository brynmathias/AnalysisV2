#ifndef allhadronic_include_Utility_hh
#define allhadronic_include_Utility_hh

#include "Types.hh"
#include <Math/PtEtaPhiE4D.h>

namespace allhadronic {

  // Useful typedefs
  typedef unsigned int uint;
  typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<double> > PtEtaPhiE;

  // Sorting algorithms
  inline bool SortByEt( const LorentzV& first, const LorentzV& second ) { return ( first.Et() > second.Et() ); }
  inline bool SortByPt( const LorentzV& first, const LorentzV& second ) { return ( first.Pt() > second.Pt() ); }

  // Returns massless jet
  inline LorentzV massless( const LorentzV& jet ) { return LorentzV( jet.Px(), jet.Py(), jet.Pz(), jet.P() )*=(jet.P()>0.?jet.E()/jet.P():0.); }
  
}

#endif // allhadronic_include_Utility_hh
