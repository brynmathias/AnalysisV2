void getcovmatrix() 
{
/*
  TString Hist1 = "MC_CSFramePlots_100toinf/MC_CSWMuonPlusCosTheta";
  TString Hist2 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusCosTheta";

  TString Hist3 = "MC_CSFramePlots_100toinf/MC_CSWMuonPlusPhi";
  TString Hist4 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusPhi";

  TString Hist5 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus";
  TString Hist6 = "MC_WPlots_100toinf/MC_CosThetaStar1Minus";
 
  TFile *data1 = new TFile("results/CSFrame_WJets_madgraph_muononly.root");
  TFile *data2 = new TFile("results/GenW_WJets_madgraph_ICVAR_reweighting_test_muononly.root");
*/

  TString Hist1 = "MC_CSFramePlots_100toinf/MC_CSWMuonPlusPhi";
  TFile *data1 = new TFile("results/GenW_CS_WJets_madgraph_CSPhi_reweighting_test.root");

  TCanvas *c1 = new TCanvas();
  TCanvas *c2 = new TCanvas();

  TH1D *hplus = (TH1D*)data1->Get(Hist1);
  hplus->Rebin(10);

  hplus->GetXaxis()->SetRangeUser(-3.,3.);

  TF1 * f2 = new TF1("f2","[0] + ((3.0*TMath::Pi()/16.0)*[1]*TMath::Cos(x)) + (([2]/4.0)*TMath::Cos(2.0*x))",-3.,3.);
  TFitResultPtr r1 = (hplus->Fit(f2,"S"));
  const TMatrixDSym& cov = r1->GetCovarianceMatrix();
  r1->Print("V");
  cout << "par2: " << f2->GetParameter(2) << endl;

  //calculate values of A2 and A3 with the appropriate errors
  double A2_val = 4.0 * f2->GetParameter(2) / (f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2)); //the factor 4 is 1/k1...
  double A3_val = (16.0/(3.0*TMath::Pi())) * f2->GetParameter(1) / (f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2));

  double A2dfdgamma = (f2->GetParameter(0) + f2->GetParameter(1))/((f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2))*(f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2)));
  double A2dfdalpha = -1.0*f2->GetParameter(2)/((f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2))*(f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2)));
  double A2dfdbeta = A2dfdalpha;

  double A2comp1 = cov[2][2] * A2dfdgamma * A2dfdgamma;
  double A2comp2 = cov[0][0] * A2dfdalpha * A2dfdalpha;
  double A2comp3 = cov[1][1] * A2dfdbeta * A2dfdbeta;
  double A2comp4 = cov[1][2] * A2dfdgamma * A2dfdbeta * 2.0;
  double A2comp5 = cov[0][2] * A2dfdalpha * A2dfdgamma * 2.0;
  double A2comp6 = cov[0][1] * A2dfdalpha * A2dfdbeta * 2.0;

  double A2_err2 = A2comp1 + A2comp2 + A2comp3 + A2comp4 + A2comp5 + A2comp6;
  double A2_err = 4.0*sqrt(A2_err2);

  double A3dfdbeta = (f2->GetParameter(0) + f2->GetParameter(2))/((f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2))*(f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2)));
  double A3dfdalpha = -1.0*f2->GetParameter(1)/((f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2))*(f2->GetParameter(0) + f2->GetParameter(1) + f2->GetParameter(2)));
  double A3dfdgamma = A2dfdalpha;

  double A3comp1 = cov[2][2] * A3dfdgamma * A3dfdgamma;
  double A3comp2 = cov[0][0] * A3dfdalpha * A3dfdalpha;
  double A3comp3 = cov[1][1] * A3dfdbeta * A3dfdbeta;
  double A3comp4 = cov[1][2] * A3dfdgamma * A3dfdbeta * 2.0;
  double A3comp5 = cov[0][2] * A3dfdalpha * A3dfdgamma * 2.0;
  double A3comp6 = cov[0][1] * A3dfdalpha * A3dfdbeta * 2.0;

  double A3_err2 = A3comp1 + A3comp2 + A3comp3 + A3comp4 + A3comp5 + A3comp6;;
  double A3_err = (16.0/(3.0*TMath::Pi())) * sqrt(A3_err2);

  cout << "A2 = " << A2_val << " +/- " << A2_err << endl;
  cout << "A3 = " << A3_val << " +/- " << fabs(A3_err) << endl;

/*
  TH1D *h1 = (TH1D*)data1->Get(Hist1);
  TH1D *h2 = (TH1D*)data1->Get(Hist2);
  h1->Rebin(5);
  h2->Rebin(5);

  TH1D *h3 = (TH1D*)data1->Get(Hist3);
  TH1D *h4 = (TH1D*)data1->Get(Hist4);
  h3->Rebin(5);
  h4->Rebin(5);

  TH1D *h5 = (TH1D*)data2->Get(Hist5);
  TH1D *h6 = (TH1D*)data2->Get(Hist6);
  h5->Rebin(5);
  h6->Rebin(5);

  c1->cd();
  TF1 * f1 = new TF1("f1","[2]*(((1.0+(0.5*[0]))+([1]*x))+((1.0-(1.5*[0]))*(x*x)))",-0.99,1.00);
  TFitResultPtr r1 = (h1->Fit(f1,"S"));
  r1->Print("V");

//  TFitResultPtr r2 = (h2->Fit(f1,"S"));
//  r2->Print("V");

//  TF1 * f2 = new TF1("f2","[2]*( (1.0 - ([0]/4.0)) - ((3.0*TMath::Pi()/16.0)*[1]*x) + (([0]/2.0)*(x*x))  )",-0.99,1.00);
  TF1 * f2 = new TF1("f2","[2]*( 1.0 + ((3.0*TMath::Pi()/16.0)*[1]*TMath::Cos(x)) + (([0]/4.0)*TMath::Cos(2.0*x))  )",-0.99,1.00);
//  TFitResultPtr r3 = (h3->Fit(f2,"S"));
//  r3->Print("V");

//  TFitResultPtr r4 = (h4->Fit(f2,"S"));
//  r4->Print("V");

  c2->cd();
  TF1 * f3 = new TF1("f3","[2]*((1-x)*(1-x)/4*[0] + (1+x)*(1+x)/4*[1] + (1.0-[0]-[1])*(1-x*x)/2)",-0.99,1.00);
  TF1 * f4 = new TF1("f4","[2]*( (1+(x*x)) + 0.5*[0]*(1.0 - (3.0*x*x)) + [1]*x )",-0.99,1.00);
  TFitResultPtr r5 = (h5->Fit(f4,"S"));
  r5->Print("V");

//  TFitResultPtr r6 = (h6->Fit(f4,"S"));
//  r6->Print("V");

*/
  return;
}
