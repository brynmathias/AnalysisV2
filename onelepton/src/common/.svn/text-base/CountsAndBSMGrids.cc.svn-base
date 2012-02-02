#include "CountsAndBSMGrids.hh"
#include "EventData.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "LeptonicOps.hh"

using namespace Operation;

CountsAndBSMGrids::CountsAndBSMGrids(  const Utils::ParameterSet& ps ) :
  dirName_( ps.Get<std::string>("DirectoryName")),
  mSuGraFile_(ps.Get<std::string>("mSUGRAFile")),
  xBins_(ps.Get<int>("xBins")),
  xLow_(ps.Get<double>("xLow")),
  xHigh_(ps.Get<double>("xHigh")),
  yBins_(ps.Get<int>("yBins")),
  yLow_(ps.Get<double>("yLow")),
  yHigh_(ps.Get<double>("yHigh"))
{

}

CountsAndBSMGrids::~CountsAndBSMGrids(){}


void CountsAndBSMGrids::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), dirName_.c_str() );
  BookHistos();

}

void CountsAndBSMGrids::BookHistos()
{

  H_M0_M12 = new  TH2D("SUSYGrid",";m_{0};m{1/2}", xBins_,xLow_,xHigh_, //m0
		       yBins_,yLow_,yHigh_ //m12
		       );
  SMHist= new  TH1D("SM_Events",";;events",1,0,2);
  CxjetsMultHist= new  TH1D("CxjetsMult",";charge #times no of jets;events",21,-10.5,10.5);
  CxjetsMult_Meff_Hist = new TH2D("CxjetsMult_Meff_Hist", ";charge #times no of jets;M_{eff}", 21, -10.5, 10.5, 500, 0, 2000);
  CxjetsMult_HTlep_Hist = new TH2D("CxjetsMult_HTlep_Hist", ";charge #times no of jets;H_{T}^{lep}", 21, -10.5, 10.5, 500, 0, 2000);
  CxjetsMult_HThad_Hist = new TH2D("CxjetsMult_HThad_Hist", ";charge #times no of jets;H_{T}^{had}", 21, -10.5, 10.5, 500, 0, 2000);
  CxjetsMult_Meff_prime_Hist = new TH2D("CxjetsMult_Meff_prime_Hist", ";charge #times no of jets;M_{eff}^{prime}", 21, -10.5, 10.5, 500, 0, 2000);

  MuPhiPlus= new  TH1D("MuPhiPlus",";#phi;",10,-TMath::Pi(),TMath::Pi());
  MuPhiMinus= new  TH1D("MuPhiMinus",";#phi;",10,-TMath::Pi(),TMath::Pi());


}
std::ostream& CountsAndBSMGrids::Description( std::ostream& ostrm ) {
  ostrm << "BSM 2d event yield Plots OR simple one bin hist for SM";
  return ostrm;
}

bool CountsAndBSMGrids::Process( Event::Data& ev ) {
  Double_t weight = ev.GetEventWeight();
  Double_t modweight = ev.GetEventWeight();


  // std::vector <Event::Lepton const *> theRECOLepton;
  //  bool isMu= false;

  //  if(ev.LD_CommonMuons().accepted.size()>0 && ev.LD_CommonElectrons().accepted.size() ==0)
  //    {
  //     theRECOLepton = ev.LD_CommonMuons().accepted;
  //     isMu = true;
  //   }

  //  if(ev.LD_CommonMuons().accepted.size()==0 && ev.LD_CommonElectrons().accepted.size()>0)
  //    {
  //      theRECOLepton = ev.LD_CommonElectrons().accepted;
  //   }

  // if(ev.LD_CommonMuons().accepted.size()>0 && ev.LD_CommonElectrons().accepted.size() > 0)
  //    {
  //        cout << "WARNING: ttWPlottingOps has common muon AND Electron, it does not know what to plot!!!"<<endl;
  //     return true;
  //   }

  // if (theRECOLepton.size()==0)
  //    {
  //     cout << "  ttWPlottingOps does require at least one lepton: plots not filled "<<endl;
  //     return true;
  //   }

  //   int Cxjetmult = ev.JD_CommonJets().accepted.size()*(theRECOLepton.at(0)->GetCharge());
  //  CxjetsMultHist->Fill(Cxjetmult, ev.GetEventWeight());
 CxjetsMultHist->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());
 //  double HTlep = ev.CommonHT() + theRECOLepton.at(0)->Pt();
   double HThad = ev.CommonHT();
   //  double Meff = HTlep +ev.PFMET().Pt();
   //   double Meff_prime = (ev.PFMET() + *(theRECOLepton.at(0))).Pt() + ev.CommonHT();

   //  if (theRECOLepton.at(0)->GetCharge() < 0 ) MuPhiMinus->Fill(theRECOLepton.at(0)->Phi(), ev.GetEventWeight());
   //  if (theRECOLepton.at(0)->GetCharge() > 0 ) MuPhiPlus->Fill(theRECOLepton.at(0)->Phi(), ev.GetEventWeight());

   //  CxjetsMult_HTlep_Hist->Fill(Cxjetmult, HTlep, ev.GetEventWeight());
   CxjetsMult_HThad_Hist->Fill(ev.JD_CommonJets().accepted.size(), HThad, ev.GetEventWeight());
   //  CxjetsMult_Meff_Hist->Fill(Cxjetmult, Meff, ev.GetEventWeight());
   //  CxjetsMult_Meff_prime_Hist->Fill(Cxjetmult, Meff_prime, ev.GetEventWeight());

  if(!ev.M0.enabled()||!ev.M12.enabled())// so it is not a SUSY grid
    {
      SMHist->Fill(1,weight);
      return true;
    }

  bool kFactor = true;
  string kFactorFile = mSuGraFile_;
  double M0;
  double M12;

  if(ev.M0.enabled()){
    M0 = ev.M0();

  }
  if(ev.MG.enabled()){
    M0 = ev.MG();
  }
  if(ev.M12.enabled()){
    M12 = ev.M12();
  }
  if(ev.MLSP.enabled()){
    M12 = ev.MLSP();
  }

  H_M0_M12->Fill(M0,M12,modweight);

 return true;
}

Double_t CountsAndBSMGrids::GetKfactor(Int_t m0, Int_t m12, TString process,TString kFactorFile){

  ifstream myfile(kFactorFile);
  if(!myfile.good()) cout << "file is not there " << endl;
  if(myfile.is_open()){

    while(!myfile.eof()){

      double kFactor = 1;
      double LO;
      double NLO;
      int thism0;
      int thism12;
      char thisprocess[80];
      myfile>>thism0;
      myfile>>thism12;
      myfile>>thisprocess;
      myfile>>LO;
      myfile>>NLO;
      myfile>>kFactor;

      TString sthisprocess(thisprocess);

      if(thism0 == m0 && thism12 == m12){
        if( process.CompareTo(thisprocess) == 0){
          return kFactor;
        }
      }
    }
    myfile.close();
  }
  return 1;
}
