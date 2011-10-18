void getViZ() 
{
  TString Hist1 = "MC_WPlots_50to75/MC_CosThetaStar1Plus";
  TString Hist2 = "MC_WPlots_75to100/MC_CosThetaStar1Plus";
  TString Hist3 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus";

  TFile *data1 = new TFile("../results/GenRoutines_ZJets-lite_madgraph.root");

  TCanvas *c1 = getCanvas(TString("ZMC_CosThetaStar1Plus"), 900, 320);

  //Cos(theta*) histograms:
  TH1D *h1 = getHist(data1, Hist1, TString("cos(#theta*)"), 3.0);
  h1->GetYaxis()->SetTitle("Events / 1 pb^{-1}");
  //h1->Scale(10.0);

  TH1D *h2 = getHist(data1, Hist2, TString("cos(#theta*)"), 1.0);
  h2->GetYaxis()->SetTitle("Events / 1 pb^{-1}");
  //h2->Scale(10.0);

  TH1D *h3 = getHist(data1, Hist3, TString("cos(#theta*)"), 1.0);
  h3->GetYaxis()->SetTitle("Events / 1 pb^{-1}");
  //h3->Scale(10.0);

  //here is the fi fit:
  TF1 * f2 = new TF1("f2","[2]*((1-x)*(1-x)/4*[0] + (1+x)*(1+x)/4*[1] + (1.0-[0]-[1])*(1-x*x)/2)",-0.99,1.00);

  //|cL| = 0.5 - sin^2(theta_W)
  //|cR| = sin^2(theta_W)
  double cL = 0.269;
  double cR = 0.231;
  double alpha = ((cL*cL + cR*cR) / (cL*cL*cL*cL - cR*cR*cR*cR)) * (cL*cL);
  double beta = ((cL*cL + cR*cR) / (cL*cL*cL*cL - cR*cR*cR*cR)) * (cR*cR);

  //Cos Theta* fits:
  std::cout << "Fit for WPt 50-75, Plus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c1->cd(1));
  h1->DrawCopy("histe");
  TFitResultPtr r1 = (h1->Fit(f2,"S"));
  f2->DrawCopy("same");
  TMatrixDSym cov = r1->GetCovarianceMatrix();
  cout << "fL = " << f2->GetParameter(0) << " +/- " << f2->GetParError(0) << endl;
  cout << "fR = " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
  cout << "VL = " << alpha*f2->GetParameter(0) - beta*f2->GetParameter(1) << " +/- " << sqrt((cov[0][0] * alpha * alpha) + (cov[1][1] * beta * beta) - (2.0 * alpha * beta * cov[0][1])) << endl;
  cout << "VR = " << alpha*f2->GetParameter(1) - beta*f2->GetParameter(0) << " +/- " << sqrt((cov[1][1] * alpha * alpha) + (cov[0][0] * beta * beta) - (2.0 * alpha * beta * cov[0][1])) << endl;
  //r1->Print("V");

  

  std::cout << std::endl << "Fit for WPt 75-100, Plus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c1->cd(2));
  h2->DrawCopy("histe");
  TFitResultPtr r2 = (h2->Fit(f2,"S"));
  f2->DrawCopy("same");
  TMatrixDSym cov = r2->GetCovarianceMatrix();
  cout << "fL = " << f2->GetParameter(0) << " +/- " << f2->GetParError(0) << endl;
  cout << "fR = " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
  cout << "VL = " << alpha*f2->GetParameter(0) - beta*f2->GetParameter(1) << " +/- " << sqrt((cov[0][0] * alpha * alpha) + (cov[1][1] * beta * beta) - (2.0 * alpha * beta * cov[0][1])) << endl;
  cout << "VR = " << alpha*f2->GetParameter(1) - beta*f2->GetParameter(0) << " +/- " << sqrt((cov[1][1] * alpha * alpha) + (cov[0][0] * beta * beta) - (2.0 * alpha * beta * cov[0][1])) << endl;
  //r2->Print("V");

  std::cout << std::endl << "Fit for WPt 100-inf, Plus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c1->cd(3));
  h3->DrawCopy("histe");
  TFitResultPtr r3 = (h3->Fit(f2,"S"));
  f2->DrawCopy("same");
  TMatrixDSym cov = r3->GetCovarianceMatrix();
  cout << "fL = " << f2->GetParameter(0) << " +/- " << f2->GetParError(0) << endl;
  cout << "fR = " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
  cout << "VL = " << alpha*f2->GetParameter(0) - beta*f2->GetParameter(1) << " +/- " << sqrt((cov[0][0] * alpha * alpha) + (cov[1][1] * beta * beta) - (2.0 * alpha * beta * cov[0][1])) << endl;
  cout << "VR = " << alpha*f2->GetParameter(1) - beta*f2->GetParameter(0) << " +/- " << sqrt((cov[1][1] * alpha * alpha) + (cov[0][0] * beta * beta) - (2.0 * alpha * beta * cov[0][1])) << endl;
  //r3->Print("V");

  //c1->Print(".png");

  return;
}

TCanvas * getCanvas(TString &name, unsigned int &xwidth, unsigned int &ywidth) 
{
  TCanvas * aCanvas = new TCanvas(name, name, xwidth, ywidth);
  aCanvas->SetFillColor(0);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->Divide(3,1);
  return aCanvas;
}

TH1D * getHist(TFile* datafile, TString & histpath, TString & xaxislabel, double & yaxismax, unsigned int rebin=5)
{
  TH1D *h1 = (TH1D*)datafile->Get(histpath);
  h1->Rebin(rebin);
  h1->GetXaxis()->SetRangeUser(-1.,1.);
  h1->GetXaxis()->SetNdivisions(505);
  h1->GetXaxis()->SetTitleSize(0.0625);
  h1->GetYaxis()->SetTitleSize(0.0625);
  h1->GetXaxis()->SetTitleOffset(1.00);
  h1->GetYaxis()->SetTitleOffset(1.20);
  h1->GetXaxis()->SetTitle(xaxislabel);
  h1->GetXaxis()->SetLabelSize(0.052);
  h1->GetYaxis()->SetLabelSize(0.052);
  h1->GetYaxis()->SetRangeUser(0.,yaxismax);
  return h1;
}

void setPadMargins(TVirtualPad* pad)
{
  pad->SetTopMargin(0.050);
  pad->SetBottomMargin(0.200);
  pad->SetLeftMargin(0.200);
  return;
}

TLatex * labelLatex(double &x, double &y, TString &label)
{
  TLatex *t1 = new TLatex(x, y, label);
  t1->SetNDC(kTRUE);
  t1->SetTextSize(0.070);
  return t1;
}
