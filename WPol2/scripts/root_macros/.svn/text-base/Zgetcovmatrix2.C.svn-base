void Zgetcovmatrix2() 
{
  TString Hist1 = "MC_CSFramePlots_50to75/MC_CSWMuonPlusCosTheta";
  TString Hist2 = "MC_CSFramePlots_50to75/MC_CSWMuonMinusCosTheta";
  TString Hist3 = "MC_CSFramePlots_75to100/MC_CSWMuonPlusCosTheta";
  TString Hist4 = "MC_CSFramePlots_75to100/MC_CSWMuonMinusCosTheta";
  TString Hist5 = "MC_CSFramePlots_100toinf/MC_CSWMuonPlusCosTheta";
  TString Hist6 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusCosTheta";

  TString Hist7 = "MC_WPlots_50to75/MC_CosThetaStar1Plus";
  TString Hist8 = "MC_WPlots_50to75/MC_CosThetaStar1Minus";
  TString Hist9 = "MC_WPlots_75to100/MC_CosThetaStar1Plus";
  TString Hist10 = "MC_WPlots_75to100/MC_CosThetaStar1Minus";
  TString Hist11 = "MC_WPlots_100toinf/MC_CosThetaStar1Plus";
  TString Hist12 = "MC_WPlots_100toinf/MC_CosThetaStar1Minus";

  TString Hist13 = "MC_CSFramePlots_50to75/MC_CSWMuonPlusPhi";
  TString Hist14 = "MC_CSFramePlots_50to75/MC_CSWMuonMinusPhi";
  TString Hist15 = "MC_CSFramePlots_75to100/MC_CSWMuonPlusPhi";
  TString Hist16 = "MC_CSFramePlots_75to100/MC_CSWMuonMinusPhi";
  TString Hist17 = "MC_CSFramePlots_100toinf/MC_CSWMuonPlusPhi";
  TString Hist18 = "MC_CSFramePlots_100toinf/MC_CSWMuonMinusPhi";

  TFile *data1 = new TFile("results/GenW_CS_ZJets-lite_madgraph_50_75_100_plus.root");
  //TFile *data2 = new TFile("results/GenW_CS_ZJets_madgraph_50_75_100_minus.root");

  TCanvas *c1 = getCanvas(TString("MC_CSZLeptonPlusCosTheta"), 900, 320);
  //TCanvas *c2 = getCanvas(TString("MC_CSWLeptonMinusCosTheta"), 900, 320);
  TCanvas *c3 = getCanvas(TString("MC_ZLeptonPlusCosThetaStar1"), 900, 320);
  //TCanvas *c4 = getCanvas(TString("MC_CosThetaStar1Minus"), 900, 320);
  TCanvas *c5 = getCanvas(TString("MC_CSZLeptonPlusPhi"), 900, 320);
  //TCanvas *c6 = getCanvas(TString("MC_CSWLeptonMinusPhi"), 900, 320);

  //Collins Soper cos(theta) histograms
  TH1D *h1 = getHist(data1, Hist1, TString("cos(#theta_{CS})"), 30.0);
  //TH1D *h2 = getHist(data2, Hist2, TString("cos(#theta_{CS})"), 30.0);

  TH1D *h3 = getHist(data1, Hist3, TString("cos(#theta_{CS})"), 10.0);
  //TH1D *h4 = getHist(data2, Hist4, TString("cos(#theta_{CS})"), 10.0);

  TH1D *h5 = getHist(data1, Hist5, TString("cos(#theta_{CS})"), 10.0);
  //TH1D *h6 = getHist(data2, Hist6, TString("cos(#theta_{CS})"), 10.0);

  //Cos(theta*) histograms:
  TH1D *h7 = getHist(data1, Hist7, TString("cos(#theta*)"), 30.0);
  //TH1D *h8 = getHist(data1, Hist8, TString("cos(#theta*)"), 90.0);

  h7->GetYaxis()->SetTitle("Events / 10 pb^{-1}");
  //h8->GetXaxis()->SetTitle("Events / 10 pb^{-1}");

  TH1D *h9 = getHist(data1, Hist9, TString("cos(#theta*)"), 10.0);
  //TH1D *h10 = getHist(data1, Hist10, TString("cos(#theta*)"), 30.0);

  h9->GetYaxis()->SetTitle("Events / 10 pb^{-1}");
  //h10->GetXaxis()->SetTitle("Events / 10 pb^{-1}");

  TH1D *h11 = getHist(data1, Hist11, TString("cos(#theta*)"), 10.0);
  //TH1D *h12 = getHist(data1, Hist12, TString("cos(#theta*)"), 30.0);

  h11->GetYaxis()->SetTitle("Events / 10 pb^{-1}");  
  //h12->GetXaxis()->SetTitle("Events / 10 pb^{-1}");

  //Collins Soper phi histograms
  TH1D *h13 = getHist(data1, Hist13, TString("#phi_{CS}"), 20.0, 10);
  //TH1D *h14 = getHist(data2, Hist14, TString("#phi_{CS}"), 20.0, 10);

  h13->GetXaxis()->SetRangeUser(-3.1,3.1);
  //h14->GetXaxis()->SetRangeUser(-3.1,3.1);

  TH1D *h15 = getHist(data1, Hist15, TString("#phi_{CS}"), 10.0, 10);
  //TH1D *h16 = getHist(data2, Hist16, TString("#phi_{CS}"), 10.0, 10);

  h15->GetXaxis()->SetRangeUser(-3.1,3.1);
  //h16->GetXaxis()->SetRangeUser(-3.1,3.1);

  TH1D *h17 = getHist(data1, Hist17, TString("#phi_{CS}"), 10.0, 10);
  //TH1D *h18 = getHist(data2, Hist18, TString("#phi_{CS}"), 10.0, 10);

  h17->GetXaxis()->SetRangeUser(-3.1,3.1);
  //h18->GetXaxis()->SetRangeUser(-3.1,3.1);

  //here is the Ai fit:
  //TF1 * f1 = new TF1("f1","[2]*(((1.0+(0.5*[0]))+([1]*x))+((1.0-(1.5*[0]))*(x*x)))",-1.00,1.00);
  //since we are not sensitive to [1] we don't know the sign of cos(theta_CS) because we cannot "tag" one of the beams like at tevatron
  TF1 * f1 = new TF1("f1","[1]*(((1.0+(0.5*[0])))+((1.0-(1.5*[0]))*(x*x)))",-1.00,1.00);

  std::cout << "Fit for ZPt 50-75, Plus Charge, CS Cos Theta: " << std::endl;
  setPadMargins(c1->cd(1));
  h1->DrawCopy("histe");
  //h1->Fit(f1, "0");
  TFitResultPtr r1 = (h1->Fit(f1,"S"));
  f1->DrawCopy("same");

  TLatex *t1 = labelLatex(0.25,0.25,"50<P_{T}(Z)<75 [GeV]");
  t1->DrawClone("same");
  r1->Print("V");

  std::cout << std::endl << "Fit for ZPt 75-100, Plus Charge, CS Cos Theta: " << std::endl;
  setPadMargins(c1->cd(2));
  h3->DrawCopy("histe");
  //h3->Fit(f1, "0");
  TFitResultPtr r3 = (h3->Fit(f1,"S"));
  f1->DrawCopy("same");
  TLatex *t3 = labelLatex(0.25,0.25,"75<P_{T}(Z)<100 [GeV]");
  t3->DrawClone("same");
  r3->Print("V");

  std::cout << std::endl << "Fit for ZPt 100-inf, Plus Charge, CS Cos Theta: " << std::endl;
  setPadMargins(c1->cd(3));
  h5->DrawCopy("histe");
  //h5->Fit(f1, "0");
  TFitResultPtr r5 = (h5->Fit(f1,"S"));
  f1->DrawCopy("same");
  TLatex *t5 = labelLatex(0.3,0.25,"P_{T}(Z)>100 [GeV]");
  t5->DrawClone("same");
  r5->Print("V");
/*
  std::cout << std::endl << "Fit for ZPt 50-75, Minus Charge, CS Cos Theta: " << std::endl;
  setPadMargins(c2->cd(1));
  h2->DrawCopy("histe");
  //h2->Fit(f1, "0");
  TFitResultPtr r2 = (h2->Fit(f1,"S"));
  f1->DrawCopy("same");
  TLatex *t2 = labelLatex(0.25,0.25,"50<P_{T}(Z)<75 [GeV]");
  t2->DrawClone("same");
  r2->Print("V");

  std::cout << std::endl << "Fit for ZPt 75-100, Minus Charge, CS Cos Theta: " << std::endl;
  setPadMargins(c2->cd(2));
  h4->DrawCopy("histe");
  //h4->Fit(f1, "0");
  TFitResultPtr r4 = (h4->Fit(f1,"S"));
  f1->DrawCopy("same");
  TLatex *t4 = labelLatex(0.25,0.25,"75<P_{T}(Z)<100 [GeV]");
  t4->DrawClone("same");
  r4->Print("V");

  std::cout << std::endl << "Fit for ZPt 100-inf, Minus Charge, CS Cos Theta: " << std::endl;
  setPadMargins(c2->cd(3));
  h6->DrawCopy("histe");
  //h6->Fit(f1, "0");
  TFitResultPtr r6 = (h6->Fit(f1,"S"));
  f1->DrawCopy("same");
  TLatex *t6 = labelLatex(0.3,0.25,"P_{T}(Z)>100 [GeV]");
  t6->DrawClone("same");
  r6->Print("V");
*/

  //here is the fi fit:
  TF1 * f2 = new TF1("f2","[2]*((1-x)*(1-x)/4*[0] + (1+x)*(1+x)/4*[1] + (1.0-[0]-[1])*(1-x*x)/2)",-0.99,1.00);

  //Cos Theta* fits:
  std::cout << "Fit for WPt 50-75, Plus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c3->cd(1));
  h7->DrawCopy("histe");
  //h7->Fit(f1, "0");
  TFitResultPtr r7 = (h7->Fit(f2,"S"));
  f2->DrawCopy("same");
  t1->DrawClone("same");
  r7->Print("V");

  std::cout << std::endl << "Fit for WPt 75-100, Plus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c3->cd(2));
  h9->DrawCopy("histe");
  //h9->Fit(f1, "0");
  TFitResultPtr r9 = (h9->Fit(f2,"S"));
  f2->DrawCopy("same");
  t3->DrawClone("same");
  r9->Print("V");

  std::cout << std::endl << "Fit for WPt 100-inf, Plus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c3->cd(3));
  h11->DrawCopy("histe");
  //h11->Fit(f1, "0");
  TFitResultPtr r11 = (h11->Fit(f2,"S"));
  f2->DrawCopy("same");
  t5->DrawClone("same");
  r11->Print("V");
/*
  std::cout << std::endl << "Fit for WPt 50-75, Minus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c4->cd(1));
  h8->DrawCopy("histe");
  //h8->Fit(f1, "0");
  TFitResultPtr r8 = (h8->Fit(f1,"S"));
  f1->DrawCopy("same");
  t2->DrawClone("same");
  r8->Print("V");

  std::cout << std::endl << "Fit for WPt 75-100, Minus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c4->cd(2));
  h10->DrawCopy("histe");
  //h10->Fit(f1, "0");
  TFitResultPtr r10 = (h10->Fit(f1,"S"));
  f1->DrawCopy("same");
  t4->DrawClone("same");
  r10->Print("V");

  std::cout << std::endl << "Fit for WPt 100-inf, Minus Charge, Cos Theta*: " << std::endl;
  setPadMargins(c4->cd(3));
  h12->DrawCopy("histe");
  //h12->Fit(f1, "0");
  TFitResultPtr r12 = (h12->Fit(f1,"S"));
  f1->DrawCopy("same");
  t6->DrawClone("same");
  r12->Print("V");
*/
  TF1 * f3 = new TF1("f2","[2]*( 1.0 + ((3.0*TMath::Pi()/16.0)*[1]*TMath::Cos(x)) + (([0]/4.0)*TMath::Cos(2.0*x))  )",-3.1,3.1);
  
  //TF1 * f2 = new TF1("f2","[0] - ((3.0*TMath::Pi()/16.0)*[1]*TMath::Cos(x)) + (([2]/4.0)*TMath::Cos(2.0*x))",-3.1,3.1);
  //TF1 * f2 = new TF1("f2","([0] - 0.25*[2] + (3.0*TMath::Pi()/16.0)*[1] ) + ((-3.0*TMath::Pi()/16.0)*[1]*(1.0 + TMath::Cos(x))) + (([2]/4.0)*(1.0 + TMath::Cos(2.0*x)))",-3.1,3.1);

  //Collins Soper Phi fits:
  std::cout << "Fit for ZPt 50-75, Plus Charge, CS Phi: " << std::endl;
  setPadMargins(c5->cd(1));
  h13->DrawCopy("histe");
  //h13->Fit(f2, "0");
  TFitResultPtr r13 = (h13->Fit(f3,"S"));
  f3->DrawCopy("same");
  t1->DrawClone("same");
  r13->Print("V");

  std::cout << std::endl << "Fit for ZPt 75-100, Plus Charge, CS Phi: " << std::endl;
  setPadMargins(c5->cd(2));
  h15->DrawCopy("histe");
  //h15->Fit(f2, "0");
  TFitResultPtr r15 = (h15->Fit(f3,"S"));
  f3->DrawCopy("same");
  t3->DrawClone("same");
  r15->Print("V");

  std::cout << std::endl << "Fit for ZPt 100-inf, Plus Charge, CS Phi: " << std::endl;
  setPadMargins(c5->cd(3));
  h17->DrawCopy("histe");
  //h17->Fit(f2, "0");
  TFitResultPtr r17 = (h17->Fit(f3,"S"));
  f3->DrawCopy("same");
  t5->DrawClone("same");
  r17->Print("V");
/*
  std::cout << std::endl << "Fit for ZPt 50-75, Minus Charge, CS Phi: " << std::endl;
  setPadMargins(c6->cd(1));
  h14->DrawCopy("histe");
  //h14->Fit(f2, "0");
  TFitResultPtr r14 = (h14->Fit(f2,"S"));
  f2->DrawCopy("same");
  t2->DrawClone("same");
  r14->Print("V");

  std::cout << std::endl << "Fit for ZPt 75-100, Minus Charge, CS Phi: " << std::endl;
  setPadMargins(c6->cd(2));
  h16->DrawCopy("histe");
  //h16->Fit(f2, "0");
  TFitResultPtr r16 = (h16->Fit(f2,"S"));
  f2->DrawCopy("same");
  t4->DrawClone("same");
  r16->Print("V");

  std::cout << std::endl << "Fit for ZPt 100-inf, Minus Charge, CS Phi: " << std::endl;
  setPadMargins(c6->cd(3));
  h18->DrawCopy("histe");
  //h18->Fit(f2, "0");
  TFitResultPtr r18 = (h18->Fit(f2,"S"));
  f2->DrawCopy("same");
  t6->DrawClone("same");
  r18->Print("V");
*/
  c1->Print(".png");
  //c2->Print(".png");
  c3->Print(".png");
  //c4->Print(".png");
  c5->Print(".png");
  //c6->Print(".png");

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
