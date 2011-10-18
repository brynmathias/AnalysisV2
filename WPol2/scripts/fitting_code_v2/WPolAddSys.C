

#include "contour.C"
#include <vector.h>
#include <TMatrix.h>
#include <stdio.h>
#include <math.h>


TMatrix*  AddQuadratic(vector<TMatrix*> myMatrices,float A_4, float A0, TString name, bool charge)
{

 float sum[4] = {0.,0.,0.,0.};

  for (unsigned int i=0;i<myMatrices.size();i++)
    {
      sum[0] += (*myMatrices[i])(0,0);
      sum[1] += (*myMatrices[i])[0][1];
      sum[2] += (*myMatrices[i])[1][0];
      sum[3] += (*myMatrices[i])[1][1];
    }
   std::cout << " combined covariance matrix (stat=X)"<< endl; 
   std::cout << sum[0] << " "<<  sum[1] <<endl;
   std::cout << sum[2] << " "<<  sum[3] <<endl;
   std::cout << "Uncertainty on f_l - f_R = "<< sqrt(sum[0])<< endl; 
   std::cout << "Uncertainty on f_0 = "<< sqrt(sum[3])<< endl;
   std::cout << "correlation: "<<  sum[1]/sqrt(sum[0]*sum[3])<<  endl;

   contour(A_4,A0,sqrt(sum[0]),sqrt(sum[3]),sum[1]/sqrt(sum[0]*sum[3]),name,charge);
   return   new TMatrix(2,2,sum);
}


TMatrix*  Add(vector<TMatrix*> myMatrices)
{
  TMatrixT<float>* aMatrix = (myMatrices[0]);
  for (unsigned int i=1;i<myMatrices.size();i++)
    {
      (*aMatrix) += (*myMatrices[i]);
   }
   std::cout << " combined covariance matrix (stat=X)"<< endl; 
   aMatrix->Print();
   
   for (unsigned int i=0;i<aMatrix->GetNrows();i++)
     {
       
       std::cout << "paramer "<< i << " uncertainty: "<<  sqrt((*aMatrix)(i,i)) << endl;
       
       for  (unsigned int j=0;j<aMatrix->GetNrows();j++)
	 {
	   if (j<=i) continue;
	   std::cout << "paramer "<< i <<j <<" correlation: " << (*aMatrix)(i,j)/(sqrt((*aMatrix)(i,i))*sqrt((*aMatrix)(j,j))) << endl;
	 }
     }
   return  aMatrix;
}


// this method return a covariance matrix assuming 100% correlation. Input are the "steps" per one sigma change in the parameter space after applying the systematic uncertainty.
TMatrix*  Get100CorCov(float systD_FL_m_FR, float systD_F0)
{
  float covSystF_JES[4] = {(systD_FL_m_FR*systD_FL_m_FR),(systD_FL_m_FR*systD_F0),(systD_FL_m_FR*systD_F0),(systD_F0*systD_F0)};
  TMatrix*  covSystM_JES = new TMatrix(2,2,covSystF_JES);
  return  covSystM_JES;
}

TMatrix*  Get0CorCov(float systD_FL_m_FR, float systD_F0)
{
 float covSystF_JES[4] = {(systD_FL_m_FR*systD_FL_m_FR),0,0,(systD_F0*systD_F0)};
  TMatrix*  covSystM_JES = new TMatrix(2,2,covSystF_JES);
  return  covSystM_JES;

}



void PrintSig(TMatrix* cov,float* a)
{
  TMatrix DeltaH(cov->GetNrows(),1,a); 
  TMatrix DeltaV(1,cov->GetNrows(),a);
  // cov->AMultB(*cov)
  //  TMatrix mult = TMatrix::matrixMultiply(*cov,DeltaH);
  TMatrix ma(1,1);
  cov->Invert();
  ma =  DeltaV*(*cov)*DeltaH ;
  std::cout << "sigma distance to data: " << sqrt(ma(0,0))  <<endl;
}

void WPolSys()
{

  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // W muon minus:
  
  // vector for covariance matrices
  vector<TMatrix*> myMatrices;
  // initial covariance matrix of fit result}: statistical only
  float covStatF[4] = {0.001331,0.001249,0.001249,0.007528}; //{00,01,10,11}
  TMatrix*  covStatM = new TMatrix(2,2,covStatF);
  myMatrices.push_back(covStatM);
  cout <<   "minus"  << sqrt(0.001331) << " "<< sqrt(0.007528) << endl;

  // adding JES uncertainty: charge -
  float systD_FL_m_FR = -0.029; // error in FL_FR
  float systD_F0 = 0.123; // error in F0
  myMatrices.push_back(Get100CorCov(systD_FL_m_FR,systD_F0));

  // adding Muon scale uncertainty uncertainty: charge -
  float systD_mu_FL_m_FR = 0.002; // error in FL_FR
  float systD_mu_F0 = 0.004; // error in F0
  myMatrices.push_back(Get100CorCov(systD_mu_FL_m_FR,systD_mu_F0));

  // adding JES resolustion uncertainty uncertainty: charge -
  float systD_JR_FL_m_FR = 0.012; // error in FL_FR
  float systD_JR_F0 = 0.006; // error in F0
  myMatrices.push_back(Get100CorCov(systD_JR_FL_m_FR,systD_JR_F0));

  // 
  float a[2] = {0.039,0.002}; // MC difference
  std::cout << " W muon minus: "  <<endl;
  TMatrix* newCov = AddQuadratic(myMatrices,0.24,0.183,"Wmuonminus",false);
  RooPlot *contour0=ellipse(0.24,0.183,sqrt(0.001451),sqrt(0.008542),0.001358/sqrt(0.001451*0.008542),"EM");
  contour0->SetFillColor(kGreen);
  contour0->SetFillStyle(1);
  contour0->Draw("same");
  

  PrintSig(newCov,a);
  std::cout  <<endl;


  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // W muon plus:

  vector<TMatrix*> WPMatrices;
  // initial covariance matrix of fit result: statistical only
  float covStatFWP[4] = {0.001306,-0.002217,-0.002217,0.007268}; //{00,01,10,11}
  TMatrix*  covStatMWP = new TMatrix(2,2,covStatFWP);
  WPMatrices.push_back(covStatMWP);
  cout <<   "minus"  << sqrt(0.001306) << " "<< sqrt(0.007268) << endl;
  // adding JES uncertainty: charge +
  float systD_FL_m_FR_WP = 0.011; // error in FL_FR
  float systD_F0_WP = 0.092; // error in F0
  WPMatrices.push_back(Get100CorCov(systD_FL_m_FR_WP,systD_F0_WP));

  // adding Muon scale uncertainty uncertainty: charge +
  float systD_mu_FL_m_FR_WP = 0.004; // error in FL_FR
  float systD_mu_F0_WP = -0.036; // error in F0
  WPMatrices.push_back(Get100CorCov(systD_mu_FL_m_FR_WP,systD_mu_F0_WP));

  // adding JES resolustion uncertainty uncertainty: charge +
  float systD_JR_FL_m_FR_WP = 0.012; // error in FL_FR
  float systD_JR_F0_WP = -0.004; // error in F0
  WPMatrices.push_back(Get100CorCov(systD_JR_FL_m_FR_WP,systD_JR_F0_WP));

  // adding JES uncertainty
  float a_WP[2] = {0.039,0.002};// MC difference W Plus
   std::cout << " W muon plus: "  <<endl;
   TMatrix* newCovWP = AddQuadratic(WPMatrices,0.31,0.171,"Wmuonplus",true);

  RooPlot *contour=ellipse(0.31,0.171,sqrt(0.001292),sqrt(0.007446),-0.002226/sqrt(0.001292*0.007446),"EM");
  contour->SetFillColor(kGreen);
  contour->Draw("same");

  PrintSig(newCovWP,a);
  std::cout  <<endl;

  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // W electron  plus:
  vector<TMatrix*> WPeMatrices;
  // initial covariance matrix of fit result: statistical only
  float covStatFWPe[4] = {0.06*0.06,-.0295*0.06*0.19,-.0295*0.06*0.19,0.19*0.19}; //{00,01,10,11}
  TMatrix*  covStatMWPe = new TMatrix(2,2,covStatFWPe);
  WPeMatrices.push_back(covStatMWPe);

  // adding JES uncertainty: charge +
  float systD_FL_m_FR_WPe = 0.027; // error in FL_FR
  float systD_F0_WPe = 0.078; // error in F0
  WPeMatrices.push_back(Get100CorCov(systD_FL_m_FR_WPe,systD_F0_WPe));

  // adding Electron scale uncertainty uncertainty: charge +
  float systD_mu_FL_m_FR_WPe = -0.019; // error in FL_FR
  float systD_mu_F0_WPe = 0.016; // error in F0
  WPeMatrices.push_back(Get100CorCov(systD_mu_FL_m_FR_WPe,systD_mu_F0_WPe));

  // adding JES resolustion uncertainty uncertainty: charge +
  float systD_JR_FL_m_FR_WPe = 0.037; // error in FL_FR
  float systD_JR_F0_WPe = -0.039; // error in F0
  WPeMatrices.push_back(Get100CorCov(systD_JR_FL_m_FR_WPe,systD_JR_F0_WPe));


  // adding JES resolustion uncertainty uncertainty: QCD stat
  float systD_JR_FL_m_FR_WPpQ = 0.002; // error in FL_FR
  float systD_JR_F0_WPpQ = 0.014; // error in F0
  WPeMatrices.push_back(Get0CorCov(systD_JR_FL_m_FR_WPpQ,systD_JR_F0_WPpQ));

  // adding JES resolustion uncertainty uncertainty: QCD bias
  float systD_JR_FL_m_FR_WPpQS = 0.002; // error in FL_FR
  float systD_JR_F0_WPpQS = 0.003; // error in F0
  WPeMatrices.push_back(Get0CorCov(systD_JR_FL_m_FR_WPpQS,systD_JR_F0_WPpQS));


  TMatrix* newCovWPe = AddQuadratic(WPeMatrices,0.277,0.24,"Welectronplus",true);
  RooPlot *contoure=ellipse(0.277,0.24,0.06,0.19,-.0295,"EM");
  contoure->SetFillColor(kGreen);
  contoure->SetFillStyle(1);
  contoure->Draw("same");

  PrintSig(newCovWPe,a);
  std::cout  <<endl;


  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // W electron  Minus:
  vector<TMatrix*> WPmMatrices;
  // initial covariance matrix of fit result: statistical only
  float covStatFWPm[4] = {0.069*0.069,-.204*0.069*0.2,-.204*0.069*0.2,0.2*0.2}; //{00,01,10,11}
  TMatrix*  covStatMWPm = new TMatrix(2,2,covStatFWPm);
  WPmMatrices.push_back(covStatMWPm);

  // adding JES uncertainty: charge +
  float systD_FL_m_FR_WPm = -0.042; // error in FL_FR
  float systD_F0_WPm = 0.15; // error in F0
  WPmMatrices.push_back(Get100CorCov(systD_FL_m_FR_WPm,systD_F0_WPm));

  // adding Electron scale uncertainty uncertainty: charge +
  float systD_mu_FL_m_FR_WPm = -0.017; // error in FL_FR
  float systD_mu_F0_WPm = 0.014; // error in F0
  WPmMatrices.push_back(Get100CorCov(systD_mu_FL_m_FR_WPm,systD_mu_F0_WPm));

  // adding JES resolustion uncertainty uncertainty: charge +
  float systD_JR_FL_m_FR_WPm = 0.046; // error in FL_FR
  float systD_JR_F0_WPm = 0.047; // error in F0
  WPmMatrices.push_back(Get100CorCov(systD_JR_FL_m_FR_WPm,systD_JR_F0_WPm));


  // adding JES resolustion uncertainty uncertainty: QCD stat
  float systD_JR_FL_m_FR_WPmQ = 0.014; // error in FL_FR
  float systD_JR_F0_WPmQ = 0.066; // error in F0
  WPmMatrices.push_back(Get0CorCov(systD_JR_FL_m_FR_WPmQ,systD_JR_F0_WPmQ));

  // adding JES resolustion uncertainty uncertainty: QCD bias
  float systD_JR_FL_m_FR_WPmQS = 0.007; // error in FL_FR
  float systD_JR_F0_WPmQS = 0.036; // error in F0
  WPmMatrices.push_back(Get0CorCov(systD_JR_FL_m_FR_WPmQS,systD_JR_F0_WPmQS));


  // adding JES uncertainty
  float a_WPm[2] = {0.039,0.002};// MC difference W Plus
   std::cout << " W electron minus: "  <<endl;
  TMatrix* newCovWPm = AddQuadratic(WPmMatrices,0.187,0.13,"WelectronMinus",false);
 
  RooPlot *contourem=ellipse(0.187,0.13,0.069,0.2,-.204,"EM");
  contourem->SetFillColor(kGreen);
  contourem->SetFillStyle(1);
  contourem->Draw("same");


  PrintSig(newCovWPm,a);
  std::cout  <<endl;

  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // W combined Minus:

  vector<TMatrix*> WPamMatrices;
  // initial covariance matrix of fit result: statistical only
  float covStatFWPam[4] = {0.031*0.031,0.304*0.031*0.078, 0.304*0.031*0.078,0.078*0.078};//{00,01,10,11}
  TMatrix*  covStatMWPam = new TMatrix(2,2,covStatFWPam);
  WPamMatrices.push_back(covStatMWPam);

  // adding JES uncertainty: charge +
  float systD_FL_m_FR_WPam = 0.033; // error in FL_FR
  float systD_F0_WPam = -0.133; // error in F0
   WPamMatrices.push_back(Get100CorCov(systD_FL_m_FR_WPam,systD_F0_WPam));

  // adding Electron scale uncertainty uncertainty: charge +
  float systD_mu_FL_m_FR_WPam = -0.013; // error in FL_FR
  float systD_mu_F0_WPam = 0.011; // error in F0
    WPamMatrices.push_back(Get100CorCov(systD_mu_FL_m_FR_WPam,systD_mu_F0_WPam));

  // adding JES resolustion uncertainty uncertainty: charge +
  float systD_JR_FL_m_FR_WPam = 0.035; // error in FL_FR
  float systD_JR_F0_WPam = 0.023; // error in F0
    WPamMatrices.push_back(Get100CorCov(systD_JR_FL_m_FR_WPam,systD_JR_F0_WPam));
  // adding JES uncertainty
  float a_WPam[2] = {0.039,0.002};// MC difference W Plus
  std::cout << " W ecombined minus: "  << endl;
  // muon scale
  float systD_co_mi_FL_m_FR_WP = 0.002; // error in FL_FR
  float systD_co_mi_F0_WP = 0.007; // error in F0
  WPMatrices.push_back(Get100CorCov(systD_co_mi_FL_m_FR_WP,systD_co_mi_F0_WP));

  TMatrix* newCovWPam = AddQuadratic(WPamMatrices,0.226,0.162,"Wecombinedminus",false);
  RooPlot *contour2=ellipse(0.226,0.162,0.031,0.078,0.304,"EM");
  contour2->Draw("same");


  PrintSig(newCovWPam,a);
  std::cout  <<endl;
  // W combined Plus:
  vector<TMatrix*> WPapMatrices;
  // initial covariance matrix of fit result: statistical only 
  float covStatFWPap[4] = {0.031*0.031, -0.660*0.031*0.075 , -0.660*0.031*0.075 ,0.075*0.075 }; //{00,01,10,11}
  TMatrix*  covStatMWPap = new TMatrix(2,2,covStatFWPap);
  WPapMatrices.push_back(covStatMWPap);

  // adding JES uncertainty: charge +
  float systD_FL_m_FR_WPap = 0.016; // error in FL_FR
  float systD_F0_WPap = 0.087; // error in F0
  WPapMatrices.push_back(Get100CorCov(systD_FL_m_FR_WPap,systD_F0_WPap));

  // adding Electron scale uncertainty uncertainty: charge +
  float systD_mu_FL_m_FR_WPap = -0.012; // error in FL_FR
  float systD_mu_F0_WPap = 0.008; // error in F0
  WPapMatrices.push_back(Get100CorCov(systD_mu_FL_m_FR_WPap,systD_mu_F0_WPap));

  // adding JES resolustion uncertainty uncertainty: charge +
  float systD_JR_FL_m_FR_WPap = 0.027; // error in FL_FR
  float systD_JR_F0_WPap = -0.015; // error in F0
  WPapMatrices.push_back(Get100CorCov(systD_JR_FL_m_FR_WPap,systD_JR_F0_WPap));
 
  // muon sdcale
  float systD_co_pl_FL_m_FR_WP = 0.003; // error in FL_FR
  float systD_co_pl_F0_WP = -0.008; // error in F0
  WPMatrices.push_back(Get100CorCov(systD_co_pl_FL_m_FR_WP,systD_co_pl_F0_WP));

  // adding JES uncertainty
  float a_WPap[2] = {0.039,0.002};// MC difference W Plus
  std::cout << " W ecombined plus: "  <<endl;
  TMatrix* newCovWPap = AddQuadratic(WPapMatrices,0.300,0.192,"Wecombinedplus",true);
  PrintSig(newCovWPap,a);
  std::cout  <<endl;
  RooPlot *contour1=ellipse(0.300,0.192,0.031,0.075,-0.660,"EM");
  contour1->SetFillColor(kGreen);
  contour1->SetFillStyle(1001);
  //  if(contour1->	IsTransparent()) cout << "why" <<endl;
  contour1->Draw("same");
  

}

void WPolSys4x4()
{

  // ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  // W muon minus:
  
  // vector for covariance matrices
  vector<TMatrix*> myMatrices;
  // initial covariance matrix of fit result: statistical only (block diagonal:
  float covStatF[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //{00,01,10,11}
  TMatrix*  covStatM = new TMatrix(4,4,covStatF);
  myMatrices.push_back(covStatM);

  // adding JES uncertainty
  // adding JES resolustion uncertainty uncertainty
  // adding Muon scale uncertainty uncertainty
  // adding Electron scale uncertainty uncertainty

}
