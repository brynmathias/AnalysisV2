void myfitmacro2() {
//do single fits and look at fit result histograms
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);

  TFile *file0 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile *file1 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_realdata.root");
  TFile *file2 = TFile::Open("results/hltmu15_goodevsel_newtemplates/syst_shift_pfmht/RecoRoutines_W-selection_WJets_madgraph_June2010_shift_pfmht_m3pc.root");

  TString charge = "Minus";
  TString bin = "50toinf";
  TString extratitle = "";//"_PTWp1pc";
  float int_lumi = 1.0; //to scale the MC which is produced relative to 1/pb

  //TH1F * Data_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge+extratitle)->Clone());
  TH1F * Data_template = (TH1F*)((TH1F*)file1->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge))->Clone();
  //TH1F * Data_template = (TH1F*)((TH1F*)file2->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge))->Clone();

  TH1F * LH_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge+"_LH"))->Clone();
  TH1F * RH_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge+"_RH"))->Clone();
  TH1F * LO_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge+"_LO"))->Clone();

  unsigned int rebin_factor = 10;
  float fit_range_min = -0.4;
  float fit_range_max = 1.5;

  Data_template->Rebin(rebin_factor);

  LH_template->Rebin(rebin_factor);
  RH_template->Rebin(rebin_factor);
  LO_template->Rebin(rebin_factor);

  unsigned int fit_range_min_bin = LH_template->FindBin(fit_range_min);
  unsigned int fit_range_max_bin = LH_template->FindBin(fit_range_max);

  unsigned int array_size = fit_range_max_bin - fit_range_min_bin;

  cout << "fit_range_min_bin: " << fit_range_min_bin << endl;
  cout << "fit_range_max_bin: " << fit_range_max_bin << endl;
  cout << "array size: " << array_size << endl;

  TMatrixF A_matrixT(3,array_size);
  TMatrixF A_matrix(array_size,3);
  TMatrixF y_matrix(array_size,1);
  TMatrixF V_matrix(array_size,array_size);
  TMatrixF V_matrixI(array_size,array_size);
  TMatrixF C_matrix(3,3);
  TMatrixF C_matrixI(3,3);
  TMatrixF S_matrix(3,1);
  TMatrixF thetahat_matrix(3,1);

  unsigned int j=0;
  //double manual_test = 0.0;
  for(unsigned int i=fit_range_min_bin;i<fit_range_max_bin;i++) {
    //Data_array[j] = Data_template->GetBinContent(i);
    
    A_matrixT[0][j] = LH_template->GetBinContent(i);
    A_matrixT[1][j] = RH_template->GetBinContent(i);
    A_matrixT[2][j] = LO_template->GetBinContent(i);

    A_matrix[j][0] = LH_template->GetBinContent(i);
    A_matrix[j][1] = RH_template->GetBinContent(i);
    A_matrix[j][2] = LO_template->GetBinContent(i);
     
    y_matrix[j][0] = Data_template->GetBinContent(i);
    V_matrix[j][j] = Data_template->GetBinContent(i);

    //manual_test += (LH_template->GetBinContent(i) - RH_template->GetBinContent(i));
    j++;
  }

  //TMatrixF A_matrix(2,LH_template->GetNbinsX());
  //A_matrixT.InsertRow(0,0,LH_array);
  //A_matrixT.InsertRow(1,0,RH_array);
  //A_matrixT.Transpose(A_matrixT);

  //A_matrixT.Print();
  //A_matrix.Print();
  //y_matrix.Print();
  //V_matrix.Print();

  V_matrixI = V_matrix;
  V_matrixI = V_matrixI.Invert();

  C_matrix = (A_matrixT * V_matrixI * A_matrix);
  S_matrix = (A_matrixT * V_matrixI * y_matrix);

  //C_matrix.Print();
  //S_matrix.Print();

  C_matrixI = C_matrix;
  C_matrixI = C_matrixI.Invert();
  C_matrixI.Print();

  thetahat_matrix = (C_matrixI * S_matrix);
  thetahat_matrix.Print();
  double norm_factor = thetahat_matrix[0][0] + thetahat_matrix[1][0] + thetahat_matrix[2][0];
  //remember that E(aX) = aE(X) and var(aX) = a^2var(X)
  double fL_error = TMath::Sqrt(C_matrixI[0][0] / int_lumi)/(norm_factor);
  double fR_error = TMath::Sqrt(C_matrixI[1][1] / int_lumi)/(norm_factor);
  double f0_error = TMath::Sqrt(C_matrixI[2][2] / int_lumi)/(norm_factor);
  double flfr_error = TMath::Sqrt((C_matrixI[0][0] + C_matrixI[1][1] - 2.0*C_matrixI[0][1]) / int_lumi)/(norm_factor);

  cout << endl << "Fit Results" << endl;
  cout << "fL: " << thetahat_matrix[0][0]/norm_factor << " +/- " << fL_error << endl;
  cout << "fR: " << thetahat_matrix[1][0]/norm_factor << " +/- " << fR_error << endl;
  cout << "f0: " << thetahat_matrix[2][0]/norm_factor << " +/- " << f0_error << endl;
  cout << "fL-fR: " << (thetahat_matrix[0][0] - thetahat_matrix[1][0])/norm_factor << " +/- " << flfr_error << endl;


  //now do the plotting:

  LH_template->Scale(thetahat_matrix[0][0]);
  RH_template->Scale(thetahat_matrix[1][0]);
  LO_template->Scale(thetahat_matrix[2][0]);
  TH1F * sum_templates = (TH1F*)LH_template->Clone();

  LH_template->SetLineColor(kRed);
  LH_template->SetLineWidth(2);
  LH_template->SetLineStyle(2);
  RH_template->SetLineColor(kGreen);
  RH_template->SetLineWidth(2);
  RH_template->SetLineStyle(3);
  LO_template->SetLineColor(kYellow);
  LO_template->SetLineWidth(2);
  LO_template->SetLineStyle(9);

  Data_template->SetMarkerStyle(kFullCircle);
  Data_template->SetLineWidth(2);
  Data_template->GetXaxis()->SetRangeUser(fit_range_min-0.1,fit_range_max+0.1);
  Data_template->GetYaxis()->SetRangeUser(0.01,1.8*(Data_template->GetBinContent(Data_template->GetMaximumBin())));
  if(charge == "Minus") Data_template->GetXaxis()->SetTitle("LP Variable Minus");
  else Data_template->GetXaxis()->SetTitle("LP Variable Plus");
  Data_template->GetYaxis()->SetTitle("Events");
  Data_template->Draw("E1");

  sum_templates->Add(RH_template);
  sum_templates->Add(LO_template);
  sum_templates->SetLineColor(kBlue);
  sum_templates->SetLineStyle(1);
  sum_templates->SetLineWidth(3);
  sum_templates->Draw("hist same");
  LH_template->Draw("hist same");
  RH_template->Draw("hist same");
  LO_template->Draw("hist same");

  leg = new TLegend(0.6391466,0.6673143,0.8968254,0.9398748,NULL,"brNDC");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->SetTextSize(0.04857513);

  TString fL_fitresult = "f_{L} = ";
  fL_fitresult += (thetahat_matrix[0][0]/norm_factor);
  fL_fitresult.Remove(13);
  fL_fitresult += " #pm ";
  fL_fitresult += fL_error;
  fL_fitresult.Remove(23);

  TString fR_fitresult = "f_{R} = ";
  fR_fitresult += (thetahat_matrix[1][0]/norm_factor);
  fR_fitresult.Remove(13);
  fR_fitresult += " #pm ";
  fR_fitresult += fR_error;
  fR_fitresult.Remove(23);

  TString f0_fitresult = "f_{0} = ";
  f0_fitresult += (thetahat_matrix[2][0]/norm_factor);
  f0_fitresult.Remove(13);
  f0_fitresult += " #pm ";
  f0_fitresult += f0_error;
  f0_fitresult.Remove(23);

  TString flmfr_fitresult = "(f_{L}-f_{R}) = ";
  flmfr_fitresult += (thetahat_matrix[0][0] - thetahat_matrix[1][0])/norm_factor;
  flmfr_fitresult.Remove(21);
  flmfr_fitresult += " #pm ";
  flmfr_fitresult += flfr_error;
  flmfr_fitresult.Remove(31);
  TLatex *flfr_fitresult = new TLatex(0.2, 0.8, flmfr_fitresult);
  flfr_fitresult->SetNDC(kTRUE);
  flfr_fitresult->SetTextSize(0.050);
  flfr_fitresult->DrawClone("same");

  leg->AddEntry(Data_template, "Data", "p");
  leg->AddEntry(sum_templates, "Fit result", "l");
  leg->AddEntry(LH_template, fL_fitresult, "l");
  leg->AddEntry(RH_template, fR_fitresult, "l");
  leg->AddEntry(LO_template, f0_fitresult, "l");
  leg->DrawClone();
    
  //cout << "manual test = " << manual_test << endl;

  return;
}
