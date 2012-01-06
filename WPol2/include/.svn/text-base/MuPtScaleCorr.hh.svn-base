#ifndef __MUPTSCALECORR_HH_
#define __MUPTSCALECORR_HH_

#include "TLorentzVector.h"
#include "TProfile3D.h"
#include <vector>
#include "EventData.hh"
#include "GenObject.hh"

namespace Operation {

  double MCPtBinsCorrection(double pt, double eta, double phi, int charge);
  TLorentzVector MuPtScaleCorrIdealGen(int, TLorentzVector, bool, Event::Data*);
  TLorentzVector MuPtScaleCorr(int, TLorentzVector, bool);
}

#endif
