#include <map>
#include <vector>
#include <string>
#include <utility>
#include <Math/PositionVector3D.h>
#include <Math/PtEtaPhiM4D.h>
#include <Math/PxPyPzE4D.h>
#include <Math/Point3D.h>
#include <Math/LorentzVector.h>

#ifdef __CINT__
typedef std::map<std::string,bool>                                trigger_t ;
typedef std::map<std::string,int>                                trigger_p ;

#pragma link C++ typedef  trigger_t ;
#pragma link C++ typedef  trigger_p ;
#pragma link C++ class    trigger_t+;
#pragma link C++ class    trigger_p+;

#pragma link C++ class    std::pair<std::string,bool>+;
#pragma link C++ class    std::pair<const std::string,bool>+;
//#pragma link C++ class std::pair<std::string,int>+;
//these pairs don't work,
//break everything. If you are trying to emulate anything in this file beware
//putting this in breaks your world and were not needed for me in the int
//case. Zoe

typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > LV;
#pragma link C++ class ROOT::Math::PtEtaPhiM4D<float>+;
#pragma link C++ class ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >+;
// #pragma link C++ function ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >::operator+(LV);
// #pragma link C++ function ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> >::operator-(LV);

typedef ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<float> > PV;
#pragma link C++ class ROOT::Math::Cartesian3D<float>+;
#pragma link C++ class ROOT::Math::DisplacementVector3D<ROOT::Math::Cartesian3D<float> >+;
#pragma link C++ class ROOT::Math::PositionVector3D<ROOT::Math::Cartesian3D<float> >+;
#endif
