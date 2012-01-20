/*! \file Manager.cc
 * \brief File containing source code for the Operation::Manager class.
 */

#include "BkgdManager.hh"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <TH1.h>
#include <TString.h>
#include <TLegend.h>
#include <TStyle.h>
#include <map>
#include "BayesianUpperLimit.hh"
#include "ExclusionPlot.hh"
//#include <pair.h>


#include "Math/DistFunc.h"
#include "Math/Math.h"
#include "Math/SpecFuncMathCore.h"
#include "Math/ProbFuncMathCore.h"
#include <TCanvas.h>
#include "LimitCalc.hh"


using namespace ROOT::Math;
#include <cmath>
#include "Math/IParamFunction.h"


using namespace std;


namespace Operation {

  //========================================
  // Operation Manager class implementation
  //========================================
  BkgdManager::BkgdManager() {}


  void BkgdManager::ReadIn(const Utils::ParameterSet & cuts,
			   const Utils::ParameterSet & samples,
			   const Utils::ParameterSet & mSuGraSettings){

    outputDir=samples.Get<std::string>("outputDir");

    input_plotName=samples.Get<std::string>("plotName");

    tanBeta = mSuGraSettings.Get<int>("tanBeta");
    if(tanBeta == 10)mSuGraFile = samples.Get<std::string>("mSuGra_tanB10");
    else if(tanBeta ==3) mSuGraFile = samples.Get<std::string>("mSuGra_tanB3");
    else {cout << " only tanbeta 3 or 10 are valid! exit!"; return;}
  
    nbins_x = mSuGraSettings.Get<int>("nbins_x");
    nbins_y = mSuGraSettings.Get<int>("nbins_y");
    min_x = mSuGraSettings.Get<int>("min_x");
    min_y = mSuGraSettings.Get<int>("min_y");
    max_x = mSuGraSettings.Get<int>("max_x");
    max_y = mSuGraSettings.Get<int>("max_y");
    binsize_x = mSuGraSettings.Get<int>("binsize_x");
    binsize_y = mSuGraSettings.Get<int>("binsize_y");
    
    
    //define the bkgdDataSets classes for data in different var3 ranges
    Data_Var3range1 = new bkgdDataSets(outputDir,"data_Var3range1",cuts,input_plotName,"0");
    Data_Var3range2 = new bkgdDataSets(outputDir,"data_Var3range2",cuts,input_plotName,"1");
    Data_Var3range3 = new bkgdDataSets(outputDir,"data_Var3range3",cuts,input_plotName,"2");
    
    //define the EWK bkgdDataSets classes for data in different var3 ranges
    EWK_Var3range1 = new bkgdDataSets(outputDir,"ewk_Var3range1",cuts,input_plotName,"0");
    EWK_Var3range2 = new bkgdDataSets(outputDir,"ewk_Var3range2",cuts,input_plotName,"1");
    EWK_Var3range3 = new bkgdDataSets(outputDir,"ewk_Var3range3",cuts,input_plotName,"2");
    
    //define the QCD bkgdDataSets classes for data in different var3 ranges
    QCD_Var3range1 = new bkgdDataSets(outputDir,"qcd_Var3range1",cuts,input_plotName,"0");
    QCD_Var3range2 = new bkgdDataSets(outputDir,"qcd_Var3range2",cuts,input_plotName,"1");
    QCD_Var3range3 = new bkgdDataSets(outputDir,"qcd_Var3range3",cuts,input_plotName,"2"); 
    
    
    //define the bkgdDataSets classes for signal plus background in different var3 ranges
    SplusB_Var3range1 = new bkgdDataSets(outputDir,"splusb_Var3range1",cuts,input_plotName,"0");
    SplusB_Var3range2 = new bkgdDataSets(outputDir,"splusb_Var3range2",cuts,input_plotName,"1");
    SplusB_Var3range3 = new bkgdDataSets(outputDir,"splusb_Var3range3",cuts,input_plotName,"2");
    
    
    //define the bkgdDataSets classes for background only in different var3 ranges
    B_Var3range1 = new bkgdDataSets(outputDir,"b_Var3range1",cuts,input_plotName,"0");
    B_Var3range2 = new bkgdDataSets(outputDir,"b_Var3range2",cuts,input_plotName,"1");
    B_Var3range3 = new bkgdDataSets(outputDir,"b_Var3range3",cuts,input_plotName,"2");
    
    //put everything in vectors for ease of use
    std::vector<bkgdDataSets*> SplusBDataSets;
    std::vector<bkgdDataSets*> BDataSets;
    std::vector<bkgdDataSets*> EWKDataSets;
    std::vector<bkgdDataSets*> QCDDataSets;
    std::vector<bkgdDataSets*> DataDataSets;
    
    std::vector<bkgdDataSets*>::iterator iter = SplusBDataSets.begin();
    std::vector<bkgdDataSets*>::iterator biter = BDataSets.begin();
    std::vector<bkgdDataSets*>::iterator citer = EWKDataSets.begin();
    std::vector<bkgdDataSets*>::iterator diter = QCDDataSets.begin();
    std::vector<bkgdDataSets*>::iterator eiter = DataDataSets.begin();

    SplusBDataSets.push_back(SplusB_Var3range1);
    SplusBDataSets.push_back(SplusB_Var3range2);
    SplusBDataSets.push_back(SplusB_Var3range3);
    
    DataDataSets.push_back(Data_Var3range1);
    DataDataSets.push_back(Data_Var3range2);
    DataDataSets.push_back(Data_Var3range3);
    
    BDataSets.push_back(B_Var3range1);
    BDataSets.push_back(B_Var3range2);
    BDataSets.push_back(B_Var3range3);
    BDataSets.push_back(SplusB_Var3range1);
    BDataSets.push_back(SplusB_Var3range2);
    BDataSets.push_back(SplusB_Var3range3);
    
    EWKDataSets.push_back(EWK_Var3range1);
    EWKDataSets.push_back(EWK_Var3range2);
    EWKDataSets.push_back(EWK_Var3range3);
    
    QCDDataSets.push_back(QCD_Var3range1);
    QCDDataSets.push_back(QCD_Var3range2);
    QCDDataSets.push_back(QCD_Var3range3);
  
  
  
    //read in datasets  if config file gives a name else don't
    
    cout << " read in signal " << endl;
    if(samples.Get<std::string>("Signal")!= "") for(iter = SplusBDataSets.begin();iter != SplusBDataSets.end();++iter)(*iter)->addDataSet(samples.Get<std::string>("Signal"));            
    
    cout << " read in data " << endl;
    if(samples.Get<std::string>("Data")!="") for(eiter = DataDataSets.begin();eiter != DataDataSets.end();++eiter)(*eiter)->addDataSet(samples.Get<std::string>("Data"));            
  
    cout << " read in zinv " << endl;
    if(samples.Get<std::string>("Background.Zinv")!= ""){
      for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.Zinv"));
    for(citer = EWKDataSets.begin();citer != EWKDataSets.end();++citer) (*citer)->addDataSet(samples.Get<std::string>("Background.Zinv"));
    }
  
    cout << " read in zjets " << endl;
    if(samples.Get<std::string>("Background.Zjets")!= ""){
      for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.Zjets"));
      for(citer = EWKDataSets.begin();citer != EWKDataSets.end();++citer) (*citer)->addDataSet(samples.Get<std::string>("Background.Zjets"));
    }
    
    cout << " read in W jets " << endl;
    if(samples.Get<std::string>("Background.Wjets")!= ""){
      for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.Wjets"));
      for(citer = EWKDataSets.begin();citer != EWKDataSets.end();++citer) (*citer)->addDataSet(samples.Get<std::string>("Background.Wjets"));
    }

    cout << " read in ttbar jets " << endl;
    if(samples.Get<std::string>("Background.ttbar")!= ""){
      for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.ttbar"));
      for(citer = EWKDataSets.begin();citer != EWKDataSets.end();++citer) (*citer)->addDataSet(samples.Get<std::string>("Background.ttbar"));
    }
    
    cout << " read in qcd " << endl;
    if(samples.Get<std::string>("Background.QCD")!= ""){
      for(biter = BDataSets.begin();biter != BDataSets.end();++biter) (*biter)->addDataSet(samples.Get<std::string>("Background.QCD"));
      for(diter = QCDDataSets.begin();diter != QCDDataSets.end();++diter) (*diter)->addDataSet(samples.Get<std::string>("Background.QCD"));
    }
    


    //merge datasets and plots
    if(SplusB_Var3range1->NbrDataSets() != 0){cout << " SplusB Var3 range 1" << endl; SplusB_Var3range1->mergePlots();}
    if(SplusB_Var3range2->NbrDataSets() != 0){cout << " SplusB Var3 range 2" << endl; SplusB_Var3range2->mergePlots();}
    if(SplusB_Var3range3->NbrDataSets() != 0){cout << " SplusB Var3 range 3" << endl; SplusB_Var3range3->mergePlots();}
    
    if(B_Var3range1->NbrDataSets() != 0){cout << " B Var3 range 1" << endl;  B_Var3range1->mergePlots();}
    if(B_Var3range2->NbrDataSets() != 0){cout << " B Var3 range 2" << endl; B_Var3range2->mergePlots();}
    if(B_Var3range3->NbrDataSets() != 0){cout << " B Var3 range 3" << endl; B_Var3range3->mergePlots();}
    
    if(EWK_Var3range1->NbrDataSets() != 0){cout << " EWK Var3 range 1" << endl;  EWK_Var3range1->mergePlots();}
    if(EWK_Var3range2->NbrDataSets() != 0){cout << " EWK Var3 range 2" << endl; EWK_Var3range2->mergePlots();}
    if(EWK_Var3range3->NbrDataSets() != 0){cout << " EWK Var3 range 3" << endl; EWK_Var3range3->mergePlots();}
    
    if(QCD_Var3range1->NbrDataSets() != 0){cout << " QCD Var3 range 1" << endl;  QCD_Var3range1->mergePlots();}
    if(QCD_Var3range2->NbrDataSets() != 0){cout << " QCD Var3 range 2" << endl; QCD_Var3range2->mergePlots();}
    if(QCD_Var3range3->NbrDataSets() != 0){cout << " QCD Var3 range 3" << endl; QCD_Var3range3->mergePlots();}
    
    if(Data_Var3range1->NbrDataSets() != 0){cout << " Data Var3 range 1" << endl;  Data_Var3range1->mergePlots();}
    if(Data_Var3range2->NbrDataSets() != 0){cout << " Data Var3 range 2" << endl; Data_Var3range2->mergePlots();}
    if(Data_Var3range3->NbrDataSets() != 0){cout << " Data Var3 range 3" << endl; Data_Var3range3->mergePlots();}

    Double_t HTcut_Second = 350;
    Double_t HTcut_First = 250;
    Double_t HTcut_FirstUp = 350;

    Double_t lumi = 10;

    Double_t non_bkgd = B_Var3range3->D_PassFrom(HTcut_Second)/100*lumi;
    Double_t noff_bkgd = B_Var3range3->D_PassFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;
    Double_t nonbar_bkgd = B_Var3range3->D_FailFrom_To(HTcut_Second,200000)/100*lumi;
    Double_t noffbar_bkgd = B_Var3range3->D_FailFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;

    Double_t non_QCD = QCD_Var3range3->D_PassFrom(HTcut_Second)/100*lumi;
    Double_t noff_QCD = QCD_Var3range3->D_PassFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;
    Double_t nonbar_QCD = QCD_Var3range3->D_FailFrom_To(HTcut_Second,200000)/100*lumi;
    Double_t noffbar_QCD = QCD_Var3range3->D_FailFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;

    cout << " non_bkgd " << non_bkgd << " non_QCD " << non_QCD << endl;
    cout << " noff_bkgd " << noff_bkgd << " noff_QCD " << noff_QCD << endl;
    cout << " nonbar_bkgd " << nonbar_bkgd << " nonbar_QCD " << nonbar_QCD << endl;
    cout << " noffbar_bkgd " << noffbar_bkgd << " noffbar_QCD " << noffbar_QCD << endl;

    cout << " tau_bkgd " << noffbar_bkgd/nonbar_bkgd << " tau_QCD " << noffbar_QCD/nonbar_QCD << endl;


    
  }

  BkgdManager::~BkgdManager() {}



 


 

 void BkgdManager::Run(const Utils::ParameterSet & cuts,
		       const Utils::ParameterSet & significance) { 

   //set all variables
  TString outputPlotName = outputDir+significance.Get<std::string>("outputPlotName");
  TString mSuGraDir = significance.Get<std::string>("mSuGraDir");
  TString mSuGraHist = significance.Get<std::string>("mSuGraHist");  
  TString method = significance.Get<std::string>("method");

  TFile* output = new TFile(outputPlotName, "RECREATE" );
  if ( !output || output->IsZombie() ) { std::cout << " zombie alarm output is a zombie " << std::endl; }
    
  //  ExclusionPlot myExclusionPlot = ExclusionPlot(mSuGraFile,mSuGraDir,mSuGraHist,tanBeta,outputPlotName);


  
  if(significance.Get<std::string>("CutAndCountOrRatio") == "CutAndCount"){

    cout << " ******************Cut And Count************************************** " << endl;
    TH2F* myCutAndCountPlot = CutAndCount(significance,cuts,*B_Var3range3,*SplusB_Var3range3,*Data_Var3range3,*QCD_Var3range3,*EWK_Var3range3,method);

    //make MSUGRA plot 
    // TH1F* myPlot = myExclusionPlot.makeExclusionPlot(upperLimit,lumi,1,method+"hist");
    output->cd();
    
    myCutAndCountPlot->Write();

    output->Write();
    output->Close();
    delete output;
    return;
  }

  cout << " ******************************************************************** " << endl;

  
  if(significance.Get<std::string>("CutAndCountOrRatio") == "Ratio"){
  
    cout << " ******************RATIO METHOD************************************** " << endl;
    TH2F* ratioPlot = RatioMethod(significance,cuts,*B_Var3range3,*SplusB_Var3range3,*Data_Var3range3,method);
    output->cd();
    ratioPlot->Write();
    
    output->Write();
    output->Close();
    delete output; 
    return;
 
  }

  return;
  
} // ~Manager::Run method.

TH2F* BkgdManager::CutAndCount(const Utils::ParameterSet& significance,const Utils::ParameterSet& cuts,const bkgdDataSets &B_Var3range3,const bkgdDataSets&SplusB_Var3range3,const bkgdDataSets &Data_Var3range3,bkgdDataSets &QCD_Var3range3,bkgdDataSets &EWK_Var3range3,TString method){

    //read in important
    Double_t lumi = significance.Get<double>("lumi");
    Double_t exclusionCL = significance.Get<double>("exclusion_significance");
    Double_t precision = significance.Get<double>("precision");
    Int_t integration_upperLimit = significance.Get<int>("integration_upperLimit");
    Double_t testFactor = significance.Get<double>("testFactor");
    Double_t HTcut = cuts.Get<double>("HTcut_Second");
 
    //number of passed events
    Double_t passedEvents = 0;
     if(B_Var3range3.NbrDataSets() != 0)passedEvents = B_Var3range3.D_PassFrom(HTcut)/100*lumi;
     else{ cout << " ! bgkd is empty " << endl; }

    //cout << " expected background " << passedEvents;

    //set number of observed events. Either from data or round MC bkgd
    Int_t I_passedEvents = -1;
    if(significance.Get<int>("useRealData") == 0){
      I_passedEvents = testFactor*passedEvents+0.5;
      cout << " fake data " << I_passedEvents << endl;
    }
    else{
      I_passedEvents = testFactor*Data_Var3range3.D_PassFrom(HTcut)+0.5;
      cout << " real data " << I_passedEvents<< endl;;
    }

    Double_t qcdEvents = 0;
    if(QCD_Var3range3.NbrDataSets() != 0) qcdEvents = QCD_Var3range3.D_PassFrom(HTcut)/100*lumi;

    Double_t ewkEvents = 0;
    if(EWK_Var3range3.NbrDataSets() != 0)ewkEvents = EWK_Var3range3.D_PassFrom(HTcut)/100*lumi;
    
    Double_t sys = ewkEvents*significance.Get<double>("uncertainty_ewk")+ qcdEvents*significance.Get<double>("uncertainty_qcd");
    
     cout << " QCD events " << qcdEvents << " ewk events " << ewkEvents << " error on background " << sys << endl;
     cout << " Signal Events " << SplusB_Var3range3.D_PassFrom(HTcut)/100*lumi-B_Var3range3.D_PassFrom(HTcut)/100*lumi<<endl;
  
    Double_t upperLimit = -1;
    if(method == "Bayes"){
      upperLimit =   BayesianUpperLimit(I_passedEvents,0.,passedEvents,sys,exclusionCL,precision,integration_upperLimit);
      
      // int nev, double sac, double xbg, double sbg,   double cl, double prec, double smax )
      cout << " Bayesian Upper Limit " << upperLimit << endl;
    
    }
    else upperLimit = CaC(I_passedEvents,passedEvents,sys,method);


    //make 2d signal plot
    TString mSuGraDir = significance.Get<std::string>("mSuGraDir");
    TString mSuGraHist = significance.Get<std::string>("mSuGraHist");
  
    TH2F* yield = yieldPlot(mSuGraFile, mSuGraDir, mSuGraHist);
    TH2F* hsig = new TH2F("hist_"+method,"hist_"+method,nbins_x,min_x,max_x,nbins_y,min_y,max_y);
  
    for(int m0 = 0; m0 < nbins_x; m0++){//start from small m0
  
      for(int m12 = nbins_y; m12 > 0; m12--){//start from large m12

	Double_t s = yield->GetBinContent(m0+1,m12)/100*lumi;

	if(s > upperLimit )hsig->SetBinContent(m0+1,m12,1);
	else hsig->SetBinContent(m0+1,m12,0);
	
      }
    }

    return hsig;

  }

  TH2F* BkgdManager::RatioMethod(const Utils::ParameterSet& significance,const Utils::ParameterSet &cuts,const bkgdDataSets &B_Var3range3,const bkgdDataSets&SplusB_Var3range3,const bkgdDataSets &Data_Var3range3,TString method){

    Double_t lumi = significance.Get<double>("lumi");
    Double_t rhonomSigma = significance.Get<double>("rhonomSigma");
    Double_t HTcut_First = cuts.Get<double>("HTcut_First");
    Double_t HTcut_FirstUp = cuts.Get<double>("HTcut_FirstUp");
    Double_t HTcut_Second = cuts.Get<double>("HTcut_Second");
    
   
    //bkgd only
    Double_t non_bkgd = B_Var3range3.D_PassFrom(HTcut_Second)/100*lumi;
    Double_t noff_bkgd = B_Var3range3.D_PassFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;
    Double_t nonbar_bkgd = B_Var3range3.D_FailFrom_To(HTcut_Second,200000)/100*lumi;
    Double_t noffbar_bkgd = B_Var3range3.D_FailFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;

    Double_t tau = noffbar_bkgd/nonbar_bkgd; 
    Double_t rhonom = noff_bkgd/non_bkgd/tau;
    
  
    //signal plus background
    Double_t non_splusb = SplusB_Var3range3.D_PassFrom(HTcut_Second)/100*lumi;
    Double_t noff_splusb = SplusB_Var3range3.D_PassFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;
    Double_t nonbar_splusb = SplusB_Var3range3.D_FailFrom(HTcut_Second)/100*lumi;
    Double_t noffbar_splusb = SplusB_Var3range3.D_FailFrom_To(HTcut_First,HTcut_FirstUp)/100*lumi;

    //signal only
    Double_t non_s = non_splusb-non_bkgd;
    Double_t noff_s = noff_splusb-noff_bkgd;
    Double_t nonbar_s = nonbar_splusb-nonbar_bkgd;
    Double_t noffbar_s = noffbar_splusb-noffbar_bkgd;
    Double_t tauprime = noff_s/non_s;
    
    //make mSuGra exclusion line plot
    TString mSuGraDir = significance.Get<std::string>("mSuGraDir");
    TString mSuGraHist = significance.Get<std::string>("mSuGraHist");  
   
    
    TH2F* yieldNon = yieldPlot(mSuGraFile,"mSuGraScan_350",mSuGraHist);
    TH2F* yieldNoff = yieldPlot(mSuGraFile,"mSuGraScan_250",mSuGraHist);

    
    
    Double_t s = 0;

    
    TH2F* h_ratio_sig = new TH2F("ratiohist_"+method,"ratiohist_"+method,nbins_x,min_x,max_x,nbins_y,min_y,max_y);
    FourBin myFourBin = FourBin(non_bkgd, noff_bkgd, nonbar_bkgd, noffbar_bkgd,rhonom,rhonomSigma,tauprime,method);

   
    cout << " tauprime " << tauprime << endl;

    //for(int m0 = 0; m0 < 3; m0++){
    // for(int m12 = 0; m12 < 3; m12++){

    for(int m0 = 0; m0 < yieldNon->GetXaxis()->GetNbins();m0++){
     
      for(int m12 = yieldNon->GetYaxis()->GetNbins(); m12 > 0; m12--){
	  
	tauprime = (yieldNoff->GetBinContent(m0+1,m12)/yieldNon->GetBinContent(m0+1,m12));
	s = yieldNon->GetBinContent(m0+1,m12)/100*lumi;
	  
	if(s < 1) h_ratio_sig->SetBinContent(m0+1,m12,0);
	else{
	  int isIn = myFourBin.IsIn(tauprime,s);
	  cout << " m0 " << m0 << " m12 " << m12 << " s " << s << " tauprime " << tauprime << " isIn "<< isIn << endl;
	  if(isIn == 0)h_ratio_sig->SetBinContent(m0+1,m12,1);
	  else if(isIn == 1) h_ratio_sig->SetBinContent(m0+1,m12,0);
	  else if(isIn == -1)h_ratio_sig->SetBinContent(m0+1,m12,-1);
	}
	
      }//end second for loop
    }//end first for loop

    return h_ratio_sig;
    
  }

  
  
} //~namespace Operation
