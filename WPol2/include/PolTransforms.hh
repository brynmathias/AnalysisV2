#ifndef _PolTransforms_HH_
#define _PolTransforms_HH_

#include <iostream>
#include "TLorentzVector.h"
#include <cmath>

namespace Operation {

  TLorentzVector HTransform(const TLorentzVector & input_particle, const TLorentzVector & w_vector);
  TLorentzVector CSTransform(const TLorentzVector & input_particle, const TLorentzVector & w_vector);


}
#endif
