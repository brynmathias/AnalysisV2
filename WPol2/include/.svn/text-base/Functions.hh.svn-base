#ifndef _Functions_HH_
#define _Functions_HH_

#include "Operation.hh"
#include "EventData.hh"
#include "GenObject.hh"
#include "PlottingBase.hh"
#include "TProfile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "Math/VectorUtil.h"
#include "TLorentzVector.h"
#include "GenMatrixBin.hh"
#include "Structures.hh"
#include "AiFactors.hh"
#include "mcreco50AiFactors.hh"
#include "mcreco50ReweightingFactors.hh"
#include "mcreco100ReweightingFactors.hh"
#include "mcreco50to75ReweightingFactors.hh"
#include "mcreco75to100ReweightingFactors.hh"
#include "reweightingFactors.hh"

namespace Operation {


  TLorentzVector TLVConvert(const LorentzV * particle);

  jSolutionsW FindBoost(const TLorentzVector jMuon, const double jVWPx, const double jVWPy,
                        const double jVWPz, const bool cheat=true, const bool approximate=true,
                        const double jVWM=80.4);


  std::vector< std::vector<jFitParameters> > & GetFitParameters();
  std::vector< std::vector<jFitParameters> > & GetWeightFitParameters(const unsigned int & phase_space);
  std::vector< std::vector<jFitParameters> > & GetWeightFitParametersZ(const unsigned int & phase_space);
  std::vector< std::vector<jAiFitParameters> > & GetAiFitParameters(const unsigned int & phase_space);
  std::vector< std::vector<jAiFitParameters> > & GetAiFitParametersZ(const unsigned int & phase_space);
  std::vector< std::vector<jFitParameters> > & GetZFitParameters();

  double BinFraction(const double & alpha, const double & beta, const double & gamma, const unsigned int & bin);
  double IntegralValue(const double & a, const double & b, const double & alpha, const double & beta, const double & gamma);
  double CorrFactor(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type);
  double CorrFactorWeight(const double & PTW, const double & YW, const bool & poscharge, const unsigned int & norm_type, const unsigned int & phase_space=0);
  double CorrFactorWeightZ(const double & PTW, const double & YW, const bool & poscharge, const unsigned int & norm_type, const unsigned int & phase_space=0);
  unsigned int GetPTbin(const double & PTW);
  unsigned int GetYbin(const double & YW);
  double AiCorrFactor(const double & PTW, const double & YW, const double & costhetastar, const double & phistar, const bool & poscharge, const unsigned int & scale_ai, const double & scale_factor, const unsigned int & phase_space, const bool & relative);
  double AiCorrFactorZ(const double & PTW, const double & YW, const double & costhetastar, const double & phistar, const bool & poscharge, const unsigned int & scale_ai, const double & scale_factor, const unsigned int & phase_space, const bool & relative);
  double AiFunction(const double & costhetastar, const double & phistar, const double & A0, const double & A1, const double & A2, const double & A3, const double & A4);
  double CorrFactorZ(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type);

  double CSPhiBinFraction(const double & alpha, const double & beta, const double & gamma, const unsigned int & bin);
  double CSPhiBinFractionTemplate(const unsigned int & norm_type, const unsigned int & bin);
  double CSCosThetaBinFraction(const double & alpha, const double & beta, const double & gamma, const unsigned int & bin);
  double CSCosThetaBinFractionTemplate(const unsigned int & norm_type, const unsigned int & bin);
  std::vector< std::vector<jFitParameters> > & GetCSPhiFitParameters();
  std::vector< std::vector<jFitParameters> > & GetCSPhiZFitParameters();
  std::vector< std::vector<jFitParameters> > & GetCSCosThetaZFitParameters();
  double CSPhiIntegralValue(const double & a, const double & b, const double & alpha, const double & beta, const double & gamma);
  double CSPhiCorrFactor(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type, const TString & boson_type);
  double CSCosThetaIntegralValue(const double & a, const double & b, const double & alpha, const double & beta, const double & gamma);
  double CSCosThetaCorrFactor(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type, const TString & boson_type);

  double GetVertexReweighting(int numVertices);
double GetVertexReweightingElectron(int numVertices);
} // ~namespace Operation
#endif
