/*! \file Jet.cc
 * \brief Source code for the (simple!) EventStuff::Jet physics object class.
 */

#include "Jet.hh"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace Event {

  Jet::Jet(Double_t px, Double_t py, Double_t pz, Double_t E,
     Double_t emFrac,
     Int_t index, Bool_t match, Bool_t cc,
     Correction corr,bool IsSmeared,
     int loose, int minimal, int tight ) :
    LorentzV(px, py, pz, E),
    mEmFrac(emFrac),
    mIndex(index),
    mMatched(match),
    mCC(cc),
    corr_(corr),
    isSmeared_(IsSmeared),
    loose_(loose),
    minimal_(minimal),
    tight_(tight)
  {}

  Jet::Jet(const LorentzV& lorentzJet,
     Double_t emFrac,
     Int_t index, Bool_t match, Bool_t cc,
     Correction corr,bool IsSmeared,
     int loose, int minimal, int tight ) :
    LorentzV(lorentzJet),
    mEmFrac(emFrac),
    mIndex(index),
    mMatched(match),
    mCC(cc),
    corr_(corr),
    isSmeared_(IsSmeared),
    loose_(loose),
    minimal_(minimal),
    tight_(tight)
  {}

  Jet::Jet(const LorentzV& lorentzJet,
     Double_t emFrac,
     Int_t index, Bool_t match, Bool_t cc,
     Correction corr,bool IsSmeared ) :
    LorentzV(lorentzJet),
    mEmFrac(emFrac),
    mIndex(index),
    mMatched(match),
    mCC(cc),
    corr_(corr),
    isSmeared_(IsSmeared),
    loose_(true),
    minimal_(true),
    tight_(true)
  {}

  Jet::Jet( const LorentzV& v,
      double emFrac,
      int index,
      int loose,
      int minimal,
      int tight ) :
    LorentzV(v),
    mEmFrac(emFrac),
    mIndex(index),
    mMatched(false), //@@ really?!?!
    mCC(true),       //@@ really?!?!
    corr_(Jet::MC),
    isSmeared_(false),
    loose_(loose),
    minimal_(minimal),
    tight_(tight)
  {}

  Jet::~Jet() {}

  //Bool_t Jet::WasItCc() { return mCC; }

  Jet::Correction Jet::correction( const std::string& corr ) {
    if      ( corr == "RAW" ) { return Jet::RAW; }
    else if ( corr == "CC" ) { return Jet::CC; }
    else if ( corr == "MC" ) { return Jet::MC; }
    else if ( corr == "JPT" ) { return Jet::JPT; }
    else if ( corr == "GEN" ) { return Jet::GEN; }
    std::string tStr;
    tStr = "Invalid jet correction type '" + corr + "'";
    throw std::invalid_argument(tStr);
  }

  std::string Jet::correction( const Correction corr ) {
    if ( corr == Jet::RAW ) { return "RAW"; }
    if ( corr == Jet::CC ) { return "CC"; }
    if ( corr == Jet::MC ) { return "MC"; }
    if ( corr == Jet::JPT ) { return "JPT"; }
    if ( corr == Jet::GEN ) { return "GEN"; }
    std::string tStr;
    tStr = "Coding error, this exception shouldn't be reached";
    throw std::invalid_argument(tStr);
  }

} // ~EventStuff

std::ostream& operator<< ( std::ostream& os, const Event::Jet& input ) {
  std::stringstream ss;
  ss << "[Event::Jet] " << std::endl
     << " Index          : " << input.GetIndex() << std::endl
     << " MatchedToGenJet: " << ( input.WasItMatched() ? "true" : "false" ) << std::endl
     << " CorrectionType : \"" << Event::Jet::correction( input.correction() ) << "\"";
  if ( input.correction() == Event::Jet::GEN ) {
    if ( input.WasItMatched() ) { ss << " (4-vector values below from GenJet!)"; }
    else { ss << " (Not matched to GenJet! 4-vector values below are invalid!)"; }
  }
  ss << std::endl
     << " Px/Py/Pz/E     : "
     << std::setprecision(8) << input.Px() << "/"
     << std::setprecision(8) << input.Py() << "/"
     << std::setprecision(8) << input.Pz() << "/"
     << std::setprecision(8) << input.E() << std::endl
     << " Pt/Et          : "
     << std::setprecision(8) << input.Pt() << "/"
     << std::setprecision(8) << input.Et() << std::endl
     << " eta/phi        : "
     << std::setprecision(8) << input.Eta() << "/"
     << std::setprecision(8) << input.Phi() << std::endl
     << " EM fraction    : " << std::setprecision(8) << input.GetEmFrac() << std::endl;
  os << ss.str();
  return os;
}

