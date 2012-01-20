#ifndef TYPES_HH
#define TYPES_HH
#include <Math/PxPyPzE4D.h>
#include <Math/LorentzVector.h>
#include <Math/Point3D.h>
#include <Math/GenVector/CoordinateSystemTags.h>
#include <vector>
//#include
#include "TLorentzVector.h"
#include <Math/GenVector/PtEtaPhiE4D.h>
#include <Math/GenVector/PtEtaPhiM4D.h>
#include "Ntuple.hh"

#ifdef _ICF2_
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > ICF_LorentzV  ;
typedef ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<double> > ICF_XYZPoint ;
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > XYZLorentzV;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<double> > PolarLorentzV;
typedef double floatle;
#endif

#ifdef _ICF_
typedef Float_t floatle;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > ICF_LorentzV  ;
typedef ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<Float_t>,ROOT::Math::DefaultCoordinateSystemTag>  ICF_XYZPoint ;
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > XYZLorentzV;
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiE4D<float> > PolarLorentzV;
#endif


typedef ICF_LorentzV LorentzV;
typedef std::vector<ICF_LorentzV> ICF_LorentzVs ;
typedef std::vector<ICF_XYZPoint> ICF_XYZPoints ;

namespace Event{
class Jet;
class GenObject;
class Lepton;
class Photon;
}

typedef std::vector<Event::Jet> JetCollection;
typedef std::vector<Event::GenObject> GenCollection;
typedef std::vector<Event::Lepton> LepCollection;
typedef std::vector<Event::Photon> PhotCollection;

#endif
