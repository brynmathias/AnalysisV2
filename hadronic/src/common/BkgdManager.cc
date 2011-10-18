/*! \file Manager.cc
 * \brief File containing source code for the Operation::Manager class.
 */

#include "BkgdManager.hh"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <TH1.h>
#include <TLegend.h>
#include <map>
//#include <pair.h>


#include "Math/DistFunc.h"
#include "Math/Math.h"
#include "Math/SpecFuncMathCore.h"
#include "Math/ProbFuncMathCore.h"
#include <TCanvas.h>



using namespace ROOT::Math;
#include <cmath>
#include "Math/IParamFunction.h"


using namespace std;


namespace Operation {

  //========================================
  // Operation Manager class implementation
  //========================================
  BkgdManager::BkgdManager() {}

  BkgdManager::~BkgdManager() {}



void BkgdManager::Run(const Utils::ParameterSet & cuts,
		      const Utils::ParameterSet & samples) { 



  std::string outputDir=samples.Get<std::string>("outputDir");


  std::string plotName=samples.Get<std::string>("plotName");

 

  //define the bkgdDataSets classes for signal plus background in different var3 ranges
   bkgdDataSets SplusB_Var3range1(outputDir,"splusb_Var3range1",cuts,plotName,"0");
   bkgdDataSets SplusB_Var3range2(outputDir,"splusb_Var3range2",cuts,plotName,"1");
   bkgdDataSets SplusB_Var3range3(outputDir,"splusb_Var3range3",cuts,plotName,"2");
 

 

  //define the bkgdDataSets classes for background only in different var3 ranges
   bkgdDataSets B_Var3range1(outputDir,"b_Var3range1",cuts,plotName,"0");
   bkgdDataSets B_Var3range2(outputDir,"b_Var3range2",cuts,plotName,"1");
   bkgdDataSets B_Var3range3(outputDir,"b_Var3range3",cuts,plotName,"2");


  std::vector<bkgdDataSets*> SplusBDataSets;
  std::vector<bkgdDataSets*> BDataSets;

  std::vector<bkgdDataSets*>::iterator iter = SplusBDataSets.begin();
  std::vector<bkgdDataSets*>::iterator biter = BDataSets.begin();

  SplusBDataSets.push_back(&SplusB_Var3range1);
  SplusBDataSets.push_back(&SplusB_Var3range2);
  SplusBDataSets.push_back(&SplusB_Var3range3);

  BDataSets.push_back(&B_Var3range1);
  BDataSets.push_back(&B_Var3range2);
  BDataSets.push_back(&B_Var3range3);
  BDataSets.push_back(&SplusB_Var3range1);
  BDataSets.push_back(&SplusB_Var3range2);
  BDataSets.push_back(&SplusB_Var3range3);
  
  
  //read in datasets  
  if(samples.Get<std::string>("Signal")!= "nothing"){
    for(iter = SplusBDataSets.begin();iter != SplusBDataSets.end();++iter)(*iter)->addDataSet(samples.Get<std::string>("Signal"));          
  }
  if(samples.Get<std::string>("Background.Zinv")!= "nothing") for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.Zinv"));
  if(samples.Get<std::string>("Background.Zjets")!= "nothing") for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.Zjets"));
  if(samples.Get<std::string>("Background.Wjets")!= "nothing") for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.Wjets"));
  if(samples.Get<std::string>("Background.QCD")!= "nothing") for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.QCD"));


  //merge datasets and plots
  if(SplusB_Var3range1.NbrDataSets() != 0){cout << " SplusB Var3 range 1" << endl; SplusB_Var3range1.mergePlots();}
  if(SplusB_Var3range2.NbrDataSets() != 0){cout << " SplusB Var3 range 2" << endl; SplusB_Var3range2.mergePlots();}
  if(SplusB_Var3range3.NbrDataSets() != 0){cout << " SplusB Var3 range 3" << endl; SplusB_Var3range3.mergePlots();}

  if(B_Var3range1.NbrDataSets() != 0){cout << " B Var3 range 1" << endl;  B_Var3range1.mergePlots();}
  if(B_Var3range2.NbrDataSets() != 0){cout << " B Var3 range 2" << endl; B_Var3range2.mergePlots();}
  if(B_Var3range3.NbrDataSets() != 0){cout << " B Var3 range 3" << endl; B_Var3range3.mergePlots();}

  //build x as double ratio from MC bkgd only expectation
  Double_t x = 1;

  if(SplusB_Var3range1.PassSize() > 0){
    x = (B_Var3range1.Pass(1)/B_Var3range1.Fail(1))/(B_Var3range3.Pass(1)/B_Var3range3.Fail(1));
    cout << " x " << x << endl;
  }
  else cout << " attention no bins in var1 " << endl;

  cout << " calculate significance Signal " << endl;
  CalculateSignificance(cuts,SplusB_Var3range1,SplusB_Var3range3,x);

  cout << " calculate significance Bkgd (control) " << endl;
  CalculateSignificance(cuts,B_Var3range1,B_Var3range3,x);
  
 

  } // ~Manager::Run method.

  
  double BkgdManager::CalculateSignificance(const Utils::ParameterSet & cuts,const bkgdDataSets &sample_Var3range1,const bkgdDataSets &sample_Var3range3,Double_t x ){

    //Do the little necessary calculation for Signal plus Bkgd
    unsigned int maxBins = cuts.Get<int>("nBinVar1");
  
    Double_t allSum = 0;
    Int_t ndof = 0;
    
    for(unsigned int i = 1; i <= sample_Var3range1.PassSize() && i <= maxBins; i++){

      
      //take X from Bkgd MC
   
      Double_t Summe = 0;
      Double_t tau = x*sample_Var3range1.Fail(i)/sample_Var3range3.Fail(i);
      Double_t non = sample_Var3range3.Pass(i);
      Double_t noff = sample_Var3range1.Pass(i);

      if(non != 0 && noff != 0 && non/sample_Var3range3.Fail(i) >= noff/sample_Var3range1.Fail(i)){
	ndof++;
	Summe= non*TMath::Log((non)*(1+tau)/(non+noff))+noff*TMath::Log((noff)*(1+tau)/((non+noff)*tau));
      }
     

      cout << " Summe " << Summe << endl;
      
      allSum += Summe;
      
    }
    
    Double_t chisquare = 0;
    
    //chisquare_cdf fails if chisquare too large
    if(2*allSum <= 70) chisquare = 2*allSum;
    else chisquare = 70;
    
    Double_t sump = 1 - chisquared_cdf(chisquare,ndof);
    
    Double_t Z_Pl = sqrt(2)*TMath::ErfInverse(1-sump);
    
    cout << " Z_Pl " << Z_Pl << endl;
    
    return Z_Pl;

  }


} //~namespace Operation
