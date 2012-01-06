#ifndef deadECALDR_hh
#define deadECALDR_hh


#include "CommonOps.hh"
#include "EventData.hh"
#include "KinSuite.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "Types.hh"
#include "mt2_bisect.hh"
#include "AlphaT.hh"
#include "Jet.hh"
#include "Math/VectorUtil.h"
#include "JetData.hh"
#include <fstream>


double  DeadECALDR_File(TString deadECALfile,float jetphi,float jeteta, int nBad);
double  DeadECALDR( Event::Data& ev,float jetphi,float jeteta, unsigned int nBad);

double NoisyECALRecHitDR( Event::Data& ev,float jetphi,float jeteta, int status);
double NoisyHCALRecHitDR( Event::Data& ev,float jetphi,float jeteta, int status);

#endif
