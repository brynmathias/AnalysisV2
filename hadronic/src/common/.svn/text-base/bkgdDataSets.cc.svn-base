#include "bkgdDataSets.hh"



#include <TCanvas.h>
#include <TLegend.h>
#include <TString.h>

#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>

#include <iostream>


using namespace std;

bkgdDataSets::bkgdDataSets(TString dirname,std::string filename,const Utils::ParameterSet& ps,TString plotName,TString range ) : dirname_(dirname),filename_(filename),signalLow(ps.Get<double>("signalLow")),signalUp(ps.Get<double>("signalUp")),bkgdLow(ps.Get<double>("bkgdLow")),TH2DPlotName(plotName+range),RebinX(ps.Get<int>("rebinX")){}

bkgdDataSets::~bkgdDataSets() {
   
  //delete dataset
  dataFileVec.clear();
}

void bkgdDataSets::addDataSet(std::string dataSet)
{

  // Create vector of ROOT files, one entry for each dataset
  TString dsRootFileName = dataSet;

    
  TFile* testFile = new TFile(dsRootFileName, "read");
 
  dataFileVec.push_back(testFile);
 
  
} // end of addDataSet method



void bkgdDataSets::mergePlots(){

  int it = 0;
 
    
  //define cut on y axis
  Double_t signalLowbin = (signalLow-((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetYaxis()->GetXmin())/(((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetYaxis()->GetBinWidth(1));
  Double_t signalUpbin = (signalUp-((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetYaxis()->GetXmin())/(((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetYaxis()->GetBinWidth(1));



  if(signalUp == -1) signalUpbin = -1;
  else if(signalUpbin >= (((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetNbinsY())){
    signalUpbin = -1;
  }


  Double_t bkgdLowbin = (bkgdLow-((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetYaxis()->GetXmin())/(((TH2D*)(*dataFileVec.begin())->Get(TH2DPlotName))->GetYaxis()->GetBinWidth(1));

  

  //add all datasets once for var2 (signalregion) and once for var2 (backgroundregion)
  for (vector<TFile*>::iterator tfileIt = dataFileVec.begin();tfileIt!=dataFileVec.end();tfileIt++)
    {    
      ((TH2D*)(*tfileIt)->Get(TH2DPlotName))->RebinX(RebinX);
  
      // cout << " signalLowbin " << signalLowbin << " signalUpbin " << signalUpbin << " bkgdLowbin " << bkgdLowbin << endl;
     
      /// cout << " allevents " << ((TH2D*)(*tfileIt)->Get(TH2DPlotName))->Integral() << endl;

      //events which are in signal region of var2
      TH1D* test_signal = ((TH2D*)(*tfileIt)->Get(TH2DPlotName))->ProjectionX("signal_bkgd",int(signalLowbin+1),int(signalUpbin),"e");
      //events which are in background region of var2
      TH1D* test_bkgd = ((TH2D*)(*tfileIt)->Get(TH2DPlotName))->ProjectionX("bkgd",int(bkgdLowbin) ,int(signalLowbin),"e");

   
      if(it == 0){
	AddedSignal_Bkgd = new TH1D(*test_signal);
	AddedSignal = new TH1D(*test_signal);
	AddedBkgd = new TH1D(*test_bkgd);
      }
      else{
	AddedSignal_Bkgd->Add(test_signal);
	AddedSignal->Add(test_signal);
	AddedBkgd->Add(test_bkgd);
      }

      it++;
    }//end loop over data files
    
  //make one histogram with ratios
  AddedSignal_Bkgd->Divide(AddedSignal_Bkgd,AddedBkgd,1,1,"B");

  Int_t var1bins = AddedSignal->GetNbinsX();

  //fill vector of non(pass cut) and noff(don't pass cut) events
  for(int i =1; i <= var1bins; i++){
    cout << " var1 bin " << i << " pass " << AddedSignal->GetBinContent(i) << " fail " << AddedBkgd->GetBinContent(i) << endl;
    pass.push_back(AddedSignal->GetBinContent(i));
    fail.push_back(AddedBkgd->GetBinContent(i));
  }

}
