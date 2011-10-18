#include "BkgdEstPlottingOps.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "GenMatrixBin.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include <sstream>
#include <string>
#include <iomanip>

#include <strstream>
#include <iostream>
#include <fstream>


#include "JetData.hh"
#include "CommonOps.hh"


using namespace Operation;


// -----------------------------------------------------------------------------
//
BkgdEstPlottingOps::BkgdEstPlottingOps( const Utils::ParameterSet& ps ) :
  // Misc
dirName_( ps.Get<std::string>("DirectoryName") ),
  nMin_( ps.Get<int>("MinObjects") ),
  nMax_( ps.Get<int>("MaxObjects") ),
  m0_felder_(ps.Get<int>("m0_felder") ),
  m12_felder_(ps.Get<int>("m12_felder"))
{
  m0_feld_save = 0;


  vector<Double_t> HT_lrange;
  vector<Double_t> HT_hrange;

  HT_lrange.push_back(300);
  HT_lrange.push_back(350);
  HT_lrange.push_back(450);

  HT_hrange.push_back(350);
  HT_hrange.push_back(450);
  HT_hrange.push_back(99999);


  vector<Double_t> allHT_lrange;
  allHT_lrange.push_back(0);
  allHT_lrange.push_back(0);
  allHT_lrange.push_back(0);

  vector<Double_t> allHT_hrange;
  allHT_hrange.push_back(99999);
  allHT_hrange.push_back(99999);
  allHT_hrange.push_back(99999);


  vector<Double_t> Meff_lrange;
  vector<Double_t> Meff_hrange;

  Meff_lrange.push_back(300);
  Meff_lrange.push_back(500);
  Meff_lrange.push_back(1000);

  Meff_hrange.push_back(400);
  Meff_hrange.push_back(1000);
  Meff_hrange.push_back(99999999.);

  //  std::cout << " book msugra histo " << std::endl;

  /* alphaT_vs_etaLeading_HT = new ABCDMethod**[m0_felder_];
  MHTovHT_vs_etaLeading_HT = new ABCDMethod**[m0_felder_];
  ThrustDeltaPhi_vs_etaLeading_HT = new ABCDMethod**[m0_felder_];
  MissingTransverse_vs_etaLeading_HT = new ABCDMethod**[m0_felder_];
  MissingTransverse_vs_etaLeading_Meff = new ABCDMethod**[m0_felder_];
  MHT_vs_etaLeading_HT = new ABCDMethod**[m0_felder_];*/

    alphaT_vs_HT = new ABCDMethod**[m0_felder_];


  for(int i = 0; i < m0_felder_; i++){ //m0 80 felder



    /*  alphaT_vs_etaLeading_HT[i] = new ABCDMethod*[m12_felder_];
    MHTovHT_vs_etaLeading_HT[i] = new ABCDMethod*[m12_felder_];
    ThrustDeltaPhi_vs_etaLeading_HT[i] = new ABCDMethod*[m12_felder_];
    MissingTransverse_vs_etaLeading_HT[i] = new ABCDMethod*[m12_felder_];
    MissingTransverse_vs_etaLeading_Meff[i] = new ABCDMethod*[m12_felder_];
    MHT_vs_etaLeading_HT[i] = new ABCDMethod*[m12_felder_];*/

    //std::cout << " book first field " << std::endl;
      alphaT_vs_HT[i] = new ABCDMethod*[m12_felder_];
    // std::cout << " end book first field " << std::endl;


    // cout << " m12_felder " << m12_felder_ << endl;

    for(int j = 0; j < m12_felder_; j++){ //m1/2 25 felder

      ostringstream StrOne_low;
      ostringstream StrTwo_low;

      ostringstream StrOne_high;
      ostringstream StrTwo_high;


      Double_t stringi_low = i*50;
      Double_t stringj_low = j*20+100;

      Double_t stringi_high = (i+1)*50;
      Double_t stringj_high = (j+1)*20+100;

      StrOne_low << stringi_low;
      StrTwo_low << stringj_low;

      StrOne_high << stringi_high;
      StrTwo_high << stringj_high;

      std::string I_low(StrOne_low.str());
      std::string J_low(StrTwo_low.str());

      std::string I_high(StrOne_high.str());
      std::string J_high(StrTwo_high.str());


      /*    alphaT_vs_etaLeading_HT[i][j] = new ABCDMethod(dirName_,"alphaT_vs_etaLeading_M0_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high+"_HT","alphaT","etaLeading",300,0,3,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);

MHTovHT_vs_etaLeading_HT[i][j] = new ABCDMethod(dirName_,"MHTovHT_vs_etaLeading_M0_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high+"_HT","MHTovHT","etaLeading",100,0,1,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);

ThrustDeltaPhi_vs_etaLeading_HT[i][j] = new ABCDMethod(dirName_,"ThrustDeltaPhi_vs_etaLeading_M0_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high+"_HT","ThrustDeltaPhi","etaLeading",33,0,3.3,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);


MissingTransverse_vs_etaLeading_HT[i][j] = new ABCDMethod(dirName_,"MissingTransverse_vs_etaLeading_M0_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high+"_HT","MissingTransverse","etaLeading",200,0,1000,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);


MissingTransverse_vs_etaLeading_Meff[i][j] = new ABCDMethod(dirName_,"MissingTransverse_vs_etaLeading_M0_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high+"_Meff","MissingTransverse","etaLeading",200,0,1000,6,0,3,Meff_lrange,Meff_hrange,nMin_,nMax_);


MHT_vs_etaLeading_HT[i][j] = new ABCDMethod(dirName_,"MHT_vs_etaLeading_M0_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high+"_HT","MHT","etaLeading",200,0,10000,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_); */

      //  std::cout << " book second two fields " << std::endl;

  alphaT_vs_HT[i][j] = new ABCDMethod(dirName_,"alphaT_vs_HT_"+I_low+"_"+I_high+"_M12_"+J_low+"_"+J_high,"alphaT","HT",300,0,3,400,0,2000,allHT_lrange,allHT_hrange,nMin_,nMax_);

      // std::cout << " end book second two fields " << std::endl;

}
}
  // cout << " m12_felder_2 " << m12_felder_ << endl;
if(m12_felder_ == 0 && m0_felder_ == 0){//no mSuGra

    //cout << " no MSUGRA " << endl;

    /*   alphaT_vs_etaLeading_HT[0] = new ABCDMethod*[m12_felder_];
    MHTovHT_vs_etaLeading_HT[0] = new ABCDMethod*[m12_felder_];
    ThrustDeltaPhi_vs_etaLeading_HT[0] = new ABCDMethod*[m12_felder_];
    MissingTransverse_vs_etaLeading_HT[0] = new ABCDMethod*[m12_felder_];
    MissingTransverse_vs_etaLeading_Meff[0] = new ABCDMethod*[m12_felder_];
    MHT_vs_etaLeading_HT[0] = new ABCDMethod*[m12_felder_];*/

      alphaT_vs_HT[0] = new ABCDMethod*[m12_felder_];


    /*  alphaT_vs_etaLeading_HT[0][0] = new ABCDMethod(dirName_,"alphaT_vs_etaLeading_HT","alphaT","etaLeading",300,0,3,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);

MHTovHT_vs_etaLeading_HT[0][0] = new ABCDMethod(dirName_,"MHTovHT_vs_etaLeading_HT","MHTovHT","etaLeading",100,0,1,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);

ThrustDeltaPhi_vs_etaLeading_HT[0][0] = new ABCDMethod(dirName_,"ThrustDeltaPhi_vs_etaLeading_HT","ThrustDeltaPhi","etaLeading",33,0,3.3,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);

MissingTransverse_vs_etaLeading_HT[0][0] = new ABCDMethod(dirName_,"MissingTransverse_vs_etaLeading_HT","MissingTransverse","etaLeading",200,0,1000,6,0,3,HT_lrange,HT_hrange,nMin_,nMax_);

MissingTransverse_vs_etaLeading_Meff[0][0] = new ABCDMethod(dirName_,"MissingTransverse_vs_etaLeading_Meff","MissingTransverse","etaLeading",200,0,1000,6,0,3,Meff_lrange,Meff_hrange,nMin_,nMax_);

MHT_vs_etaLeading_HT[0][0] = new ABCDMethod(dirName_,"MHT_vs_etaLeading_HT","MHT","etaLeading",200,0,10000,6,0,3,Meff_lrange,Meff_hrange,nMin_,nMax_);*/

  alphaT_vs_HT[0][0] = new ABCDMethod(dirName_,"alphaT_vs_HT","alphaT","HT",300,0,3,400,0,2000,allHT_lrange,allHT_hrange,nMin_,nMax_);

}

  //std::cout << " end book msugra histos " << std::endl;

}

// -----------------------------------------------------------------------------
//
BkgdEstPlottingOps::~BkgdEstPlottingOps() {



}

// -----------------------------------------------------------------------------
//
void BkgdEstPlottingOps::Start( Event::Data& ev ) {



  initDir( ev.OutputFile(), dirName_.c_str() );

  BookHistos();
}

// -----------------------------------------------------------------------------
//
void BkgdEstPlottingOps::BookHistos() {

  // std::cout << " book bkgd est histos " << std::endl;

  for(int i = 0; i < m0_felder_; i++){
    for(int j = 0; j < m12_felder_; j++){
      // alphaT_vs_etaLeading_HT[i][j]->BookHistos();

      /*  MHTovHT_vs_etaLeading_HT[i][j]->BookHistos();

ThrustDeltaPhi_vs_etaLeading_HT[i][j]->BookHistos();

MissingTransverse_vs_etaLeading_HT[i][j]->BookHistos();

MissingTransverse_vs_etaLeading_Meff[i][j]->BookHistos();

MHT_vs_etaLeading_HT[i][j]->BookHistos();*/

      //std::cout << " book histo " << " m0 " << i << " m12 " << j <<std::endl;
  alphaT_vs_HT[i][j]->BookHistos();
      // std::cout << " end book histo " << std::endl;

}
}
if(m0_felder_ == 0 && m12_felder_ == 0){

    // std::cout << " book single histo " << std::endl;

    /*   alphaT_vs_etaLeading_HT[0][0]->BookHistos();

MHTovHT_vs_etaLeading_HT[0][0]->BookHistos();

ThrustDeltaPhi_vs_etaLeading_HT[0][0]->BookHistos();

MissingTransverse_vs_etaLeading_HT[0][0]->BookHistos();

MissingTransverse_vs_etaLeading_Meff[0][0]->BookHistos();

MHT_vs_etaLeading_HT[0][0]->BookHistos();
*/
alphaT_vs_HT[0][0]->BookHistos();


}




}


// -----------------------------------------------------------------------------
//
bool BkgdEstPlottingOps::Process( Event::Data& ev ) {

  // Event weight
  Double_t weight = ev.GetEventWeight();

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


  ThrustStuff aThrustStuff = ev.CommonThrustStuff();

  //accepted (pt,eta,id) jets
  std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();

  // cout  << " mo " << M0 << endl;

  //Fill alphaT eta HT plots
  Double_t var1 = fabs((*ijet)->Eta());

  Double_t var2_alphaT = -1;
  if(ev.CommonObjects().size() > 1 && ev.CommonObjects().size() <= Event::KS_MinDEt_MaxN())var2_alphaT = ev.CommonAlphaT();

  Double_t var2_MHTovHT = ev.CommonRecoilMET().Pt()/ev.CommonSumEt();

  Double_t var2_ThrustDeltaPhi = fabs(TMath::Pi()-aThrustStuff.pjetDphi);

  Double_t var2_MissingTransverse =  ev.CommonSumEt();
  if( fabs(TMath::Pi()-aThrustStuff.pjetDphi) < TMath::Pi()/2)  var2_MissingTransverse = 0.5*ev.CommonSumEt()*sin(fabs(TMath::Pi()-aThrustStuff.pjetDphi));

  Double_t var2_MHT = ev.CommonRecoilMET().Pt();


  Double_t var3 = ev.CommonSumEt();

  Double_t var3_Meff = ev.CommonRecoilMET().Pt()+ev.CommonSumEt();

  Int_t numJets = ev.JD_CommonJets().accepted.size();

  Double_t DPhiOne;
  Double_t DPhiTwo ;
  Double_t DPhiThree=99;


  try{//works only for mSuGra scan files
    int m0_feld = (int)(M0/50+0.5);
    int m12_feld = (int)((M12-100)/20+0.5);

      // if(m0_feld !=  m0_feld_save)  cout << " m0 " << M0 << " feld " << m0_feld << " m12 " << M12 << " feld " << m12_feld << endl;
    m0_feld_save = m0_feld;

    if(m0_feld < m0_felder_ && m12_feld < m12_felder_){

  //Fill alphaT eta HT plots
      if(var2_alphaT != -1) {
    //alphaT_vs_etaLeading_HT[m0_feld][m12_feld]->Process(weight,var1,var2_alphaT,var3,numJets);
        alphaT_vs_HT[m0_feld][m12_feld]->Process(weight,var3,var2_alphaT,var3,numJets);
      }

  //Fill MHT/HT eta HT plots
  /*  MHTovHT_vs_etaLeading_HT[m0_feld][m12_feld]->Process(weight,var1,var2_MHTovHT,var3,numJets);

//Fill ThrustDeltaPhi eta HT plots
ThrustDeltaPhi_vs_etaLeading_HT[m0_feld][m12_feld]->Process(weight,var1,var2_ThrustDeltaPhi,var3,numJets);

//Fill missing_transverse eta HT plots
MissingTransverse_vs_etaLeading_HT[m0_feld][m12_feld]->Process(weight,var1,var2_MissingTransverse,var3,numJets);

//Fill missing_transverse eta Meff plots
MissingTransverse_vs_etaLeading_Meff[m0_feld][m12_feld]->Process(weight,var1,var2_MissingTransverse,var3_Meff,numJets);


std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
DPhiOne = ROOT::Math::VectorUtil::DeltaPhi(ev.CommonRecoilMET(),*(*ijet));
++ijet;
DPhiTwo = ROOT::Math::VectorUtil::DeltaPhi(ev.CommonRecoilMET(),*(*ijet));
DPhiThree = 99;


if(ev.JD_CommonJets().accepted.size() > 2){
//  cout << " dphi one " << DPhiOne << " dphi two " << DPhiTwo << " dphi three " << DPhiThree << endl;
++ijet;
DPhiThree = ROOT::Math::VectorUtil::DeltaPhi(ev.CommonRecoilMET(),*(*ijet));
}

//Fill MHT eta HT plots (RA2 cuts)
if(fabs(DPhiOne) >= 0.3 && fabs(DPhiTwo) >= 0.5 && fabs(DPhiThree) >= 0.3){
//  MHT_vs_etaLeading_HT[m0_feld][m12_feld]->Process(weight,var1,var2_MHT,var3,numJets);
}
*/
}
}
catch(...){//for all other files

        //Fill alphaT eta HT plots
  if(var2_alphaT != -1){
  //  alphaT_vs_etaLeading_HT[0][0]->Process(weight,var1,var2_alphaT,var3,numJets);
    alphaT_vs_HT[0][0]->Process(weight,var3,var2_alphaT,var3,numJets);
  }

  //Fill MHT/HT eta HT plots
      /*  MHTovHT_vs_etaLeading_HT[0][0]->Process(weight,var1,var2_MHTovHT,var3,numJets);

//Fill ThrustDeltaPhi eta HT plots
ThrustDeltaPhi_vs_etaLeading_HT[0][0]->Process(weight,var1,var2_ThrustDeltaPhi,var3,numJets);

//Fill missing_transverse eta HT plots
MissingTransverse_vs_etaLeading_HT[0][0]->Process(weight,var1,var2_MissingTransverse,var3,numJets);

//Fill missing_transverse eta Meff plots
MissingTransverse_vs_etaLeading_Meff[0][0]->Process(weight,var1,var2_MissingTransverse,var3_Meff,numJets);


std::vector<Event::Jet const*>::const_iterator ijet = ev.JD_CommonJets().accepted.begin();
DPhiOne = ROOT::Math::VectorUtil::DeltaPhi(ev.CommonRecoilMET(),*(*ijet));
++ijet;
DPhiTwo = ROOT::Math::VectorUtil::DeltaPhi(ev.CommonRecoilMET(),*(*ijet));
DPhiThree = 99;
if(ev.JD_CommonJets().accepted.size() > 2){
++ijet;
DPhiThree = ROOT::Math::VectorUtil::DeltaPhi(ev.CommonRecoilMET(),*(*ijet));
}

//  cout << " dphi one " << DPhiOne << " dphi two " << DPhiTwo << " dphi three " << DPhiThree << endl;

//Fill MHT eta HT plots (RA2 cuts)
if(fabs(DPhiOne) >= 0.3 && fabs(DPhiTwo) >= 0.5 && fabs(DPhiThree) >= 0.3){
MHT_vs_etaLeading_HT[0][0]->Process(weight,var1,var2_MHT,var3,numJets);
}
*/


}


return true;
}


// -----------------------------------------------------------------------------
//
std::ostream& BkgdEstPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "BkgdEst 2d Plots ";
  return ostrm;
}






ABCDMethod::ABCDMethod(const std::string& fileName,TString processName,TString Var1Name,TString Var2Name, UInt_t NumberBinsVar1, float minVar1, float maxVar1, UInt_t NumberBinsVar2, float minVar2,float maxVar2,const vector<Double_t>& lrange,const vector<Double_t>&hrange,Int_t minNumJets,Int_t maxNumJets) : var1Name(Var1Name),var2Name(Var2Name),numberBinsVar1(NumberBinsVar1),MinVar1(minVar1),MaxVar1(maxVar1),numberBinsVar2(NumberBinsVar2),MinVar2(minVar2),MaxVar2(maxVar2),process_name(processName),Lrange(lrange),Hrange(hrange),MinNumJets(minNumJets),MaxNumJets(maxNumJets){



  if(Lrange.size() != Hrange.size())cout << " error should never happen " << endl;

}


ABCDMethod::~ABCDMethod(){ }

void ABCDMethod::BookHistos(){



  TString ProfileAxisTitle = ";"+var2Name+";"+var1Name;


// std::cout << " ABCD book histos " << process_name << " num " << Hrange.size() << std::endl;
  //book hist array for different jet multiplicities 0: all jets multiplicities; 1:>2 jets; 2: 2 jets; 3: 3 jets; 4: >3 jets
  BookHistArray( ABCD_TH2D,
    process_name,
    ProfileAxisTitle,
    numberBinsVar2,MinVar2,MaxVar2,
    numberBinsVar1,MinVar1,MaxVar1,
    Hrange.size(), 0, 1,false );


// std::cout << " end ABCD book histos " << std::endl;


}

std::ostream& ABCDMethod::Description(std::ostream &ostrm) {
  ostrm << " (ABCD Method: "<< process_name << ")";
  return ostrm;
}



bool ABCDMethod::Process(Double_t weight, Double_t var1, Double_t var2, Double_t var3,Int_t numJets){

  if(Lrange.size() != Hrange.size())return false;

  if(numJets < MinNumJets || numJets > MaxNumJets)return false;

  for(unsigned int i = 0; i < ABCD_TH2D.size(); i++){

    if(var3 > Lrange[i] && var3 < Hrange[i])ABCD_TH2D[i]->Fill(var1,var2,weight);


  }


  return true;


}
