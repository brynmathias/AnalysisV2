/////////////////////////////////////////////////////////////////////////
//
// 'Limit Example' RooStats tutorial macro #101
// author: Kyle Cranmer
// date June. 2009
//
// This tutorial shows an example of creating a simple
// model for a number counting experiment with uncertainty
// on both the background rate and signal efficeincy. We then 
// use a Confidence Interval Calculator to set a limit on the signal.
//
//
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "TROOT.h"
#include "RooRandom.h"
#include "RooProfileLL.h"
#include "RooAbsPdf.h"
#include "RooStats/HypoTestResult.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "RooTreeDataStore.h"
#include "RooWorkspace.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TStopwatch.h"
#include <sstream>
#include <algorithm>
#include "RooStats/ProfileLikelihoodCalculator.h"
#include "RooStats/MCMCCalculator.h"
#include "RooStats/UniformProposal.h"
#include "RooStats/FeldmanCousins.h"
#include "RooStats/NumberCountingPdfFactory.h"
#include "RooStats/ConfInterval.h"
#include "RooStats/PointSetInterval.h"
#include "RooStats/LikelihoodInterval.h"
#include "RooStats/LikelihoodIntervalPlot.h"
#include "RooStats/RooStatsUtils.h"
#include "RooStats/ModelConfig.h"
#include "RooStats/MCMCInterval.h"
#include "RooStats/MCMCIntervalPlot.h"
#include "RooStats/ProposalFunction.h"
#include "RooStats/ProposalHelper.h"
#include "RooStats/BayesianCalculator.h"
#include "RooFitResult.h"
#include "RooStats/PointSetInterval.h"


// use this order for safety on library loading
using namespace RooFit ;
using namespace RooStats ;

string convertIn(double number);

class FourBin{

public:
  FourBin(double non=21, double noff=62, double nonbar=1.742e+06, double noffbar=1.913e+06, double rhonom=2.8,double rhonomSigma = 0.5,double tauprime = 1.,TString method = "");

  Int_t IsIn(double tauprimenom,double signal);
  
  
private:
  RooWorkspace* wspace;

  ModelConfig* modelConfig;

  RooDataSet* data;
  RooArgSet* newSet;

  Double_t non;
  Double_t noff;
  Double_t nonbar;
  Double_t noffbar;
  Double_t rhonom;
  Double_t rhonomSigma;
  Double_t tau;
  Double_t tauprime;
  Double_t signal;


  TString method;




};

double CaC(Double_t observed=1.,Double_t expectedBackground=0.6,Double_t sys=0.4,TString = "Profile");


