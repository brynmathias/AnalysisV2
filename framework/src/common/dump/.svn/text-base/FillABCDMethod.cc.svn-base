#include "FillABCDMethod.hh"
#include <iostream>
#include <fstream>

namespace Operation {

  CallABCDMethod::CallABCDMethod(const std::string & fileName) : 
    mFileName(fileName) {
    //insert fileName for output file,  name of the var1_vs_var2, axis title for var1, axis title for var2, number of bins in var 1, minBin in Var1, maxBin in Var1, number of bins in var 2, minBin in Var2, maxBin in Var2, cut in variable 1     
    recoilMET_vs_etaLeading = new ABCDMethod(fileName,"recoilMET_vs_etaLeading","recoilMET","etaLeading",500,0,500,10,0,5,200); 
    METsign_vs_etaLeading = new ABCDMethod(fileName,"METsign_vs_etaLeading","METsignificance","etaLeading",120,0,1.2,10,0,5,0.55);
    alphaT_vs_etaLeading_HT_250_350 = new ABCDMethod(fileName,"alphaT_vs_etaLeading_HT_250-350","alphaT","etaLeading",300,0,3,10,0,5,0.55); 
    alphaT_vs_etaLeading_HT_350 = new ABCDMethod(fileName,"alphaT_vs_etaLeading_HT_350","alphaT","etaLeading",300,0,3,10,0,5,0.55);
  };

  std::ostream& CallABCDMethod::Description(std::ostream &ostrm) {
    // ostrm << "ABCDMethod " << recoilMET_vs_etaLeading->Description(ostrm) << METsign_vs_etaLeading->Description(ostrm);
    return ostrm;
  }

  CallABCDMethod::~CallABCDMethod(){ 
    delete recoilMET_vs_etaLeading; 
    delete METsign_vs_etaLeading;
    delete alphaT_vs_etaLeading_HT_250_350;
    delete alphaT_vs_etaLeading_HT_350;
  }

  bool CallABCDMethod::Process(Event::Data & ev){
    if(ev.JD_CommonJets().accepted.size()>0){

      Double_t var1 =  ev.CommonRecoilMET().Pt(); 
      Double_t var2 = fabs(ev.JD_CommonJets().accepted[0]->Eta());
      
      recoilMET_vs_etaLeading->Process(ev.GetEventWeight(),var1,var2);
      
      var1 = ev.CommonRecoilMET().Pt()/ev.CommonSumEt();
      METsign_vs_etaLeading->Process(ev.GetEventWeight(),var1,var2);

      // JJ - I'm presuming we can't process if CommonAlphaT can't be processed
      // so encapsulate in a check to avoid throwing exceptions
      if ( ev.CommonObjects().size() >= 1 &&
	   ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN() ) {
	var1 = ev.CommonAlphaT();
	if(ev.CommonSumEt() > 250 && ev.CommonSumEt() < 350)
	  alphaT_vs_etaLeading_HT_250_350->Process(ev.GetEventWeight(),var1,var2);
	else if (ev.CommonSumEt() > 350)
	  alphaT_vs_etaLeading_HT_350->Process(ev.GetEventWeight(),var1,var2);
      }
    }
    return true;
  }

  ABCDMethod::ABCDMethod(const std::string & fileName,
			 const std::string & processName,
			 TString var1Name,
			 TString var2Name,
			 UInt_t numberBinsVar1,
			 float MinVar1,
			 float MaxVar1,
			 UInt_t numberBinsVar2,
			 float MinVar2,
			 float MaxVar2,
			 Double_t cutSignal) :
    cut_signal(cutSignal),
    process_name(processName){

    TString name = fileName + "/"+  fileName + "_ABCD_" + processName;
    name = name + ".root";
    cout << " name " << name << endl;
    File = new TFile(name,"recreate");

    TString AxisTitle = ";"+var2Name+";events/fb^{-1}";
    TString ProfileAxisTitle = ";"+var2Name+";"+var1Name;

    ABCD_Profile = new TProfile("TProfile_var2_vs_var1",ProfileAxisTitle,numberBinsVar2,MinVar2,MaxVar2);
    ABCD_TH2D = new TH2D("TH2D_var2_vs_var1",ProfileAxisTitle,numberBinsVar2,MinVar2,MaxVar2,numberBinsVar1,MinVar1,MaxVar1);
    ABCD_TH2D->Sumw2();
    ABCD_PlotSignal = new TH1D("Signal",AxisTitle,numberBinsVar2,MinVar2,MaxVar2);
    ABCD_PlotSignal->Sumw2();
    ABCD_PlotBkgd = new TH1D("Bkgd",AxisTitle,numberBinsVar2,MinVar2,MaxVar2);
    ABCD_PlotBkgd->Sumw2();
  }
  
  std::ostream& ABCDMethod::Description(std::ostream &ostrm) {
    ostrm << " (ABCD Method: "<< process_name << ")";
    return ostrm;
  }

  ABCDMethod::~ABCDMethod(){ 
    File->Write();
    File->Close();
    delete File;
  }

  bool ABCDMethod::Process(Double_t weight, Double_t var1, Double_t var2){
    File->cd();
    ABCD_Profile->Fill(var2,var1,weight);
    ABCD_TH2D->Fill(var2,var1,weight);

    if(var1 > cut_signal){//defined as signal
      ABCD_PlotSignal->Fill(var2,weight);
    }
    else ABCD_PlotBkgd->Fill(var2,weight); //defined as bkgd
       
    return true;
  }
  
}

