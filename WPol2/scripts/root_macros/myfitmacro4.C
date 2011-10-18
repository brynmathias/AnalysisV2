void myfitmacro4() {
//this macro is used to see the effects of the fit range on the fl-fr and f0 fit results
  gROOT->SetStyle("Plain");
  //gStyle->SetPadTickY(0);
  gStyle->SetOptStat(0);

  TFile *file0 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile *file1 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_realdata.root");

  TString charge[2] = {"Plus", "Minus"};
  TString bin = "75to100";
  TString extratitle = "";//"_PTWp1pc";
  float int_lumi = 1.0; //to scale the MC which is produced relative to 1/pb

  TH1F * summary_hist_plus_flfr = new TH1F("summary_hist_plus_flfr",";fit range size;(f_{L}-f_{R})",25,-0.05,2.45);
  TH1F * summary_hist_minus_flfr = new TH1F("summary_hist_minus_flfr",";fit range size;(f_{L}-f_{R})",25,-0.05,2.45);
  TH1F * summary_hist_plus_f0 = new TH1F("summary_hist_plus_f0",";fit range size;f_{0}",25,-0.05,2.45);
  TH1F * summary_hist_minus_f0 = new TH1F("summary_hist_minus_f0",";fit range size;f_{0}",25,-0.05,2.45);

  TH1F * flfr_summary_hist[2] = {summary_hist_plus_flfr, summary_hist_minus_flfr};
  TH1F * f0_summary_hist[2] = {summary_hist_plus_f0, summary_hist_minus_f0};

  TCanvas * c1 = new TCanvas("fl-fr_fitrangesyst","fl-fr_fitrangesyst",500,500);
  TCanvas * c2 = new TCanvas("f0_fitrangesyst","f0_fitrangesyst",500,500);

  double reference_value[2] = {1.0, 1.0};

  unsigned int rebin_factor = 10;

  for(unsigned int j=0;j<2; j++) {
    double fit_range_min = -0.25;
    double fit_range_max = 1.25;
	for(unsigned int i=0; i<8; i++) {
      TH1F * Data_template = (TH1F*)((TH1F*)file1->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+extratitle)->Clone());
    
      TH1F * LH_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LH"))->Clone();
      TH1F * RH_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_RH"))->Clone();
      TH1F * LO_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LO"))->Clone();
    
      std::vector<double> results(8);
      results = fit_macro(Data_template, LH_template, RH_template, LO_template, rebin_factor, fit_range_min, fit_range_max, int_lumi);

      cout << endl << "Fit Results (" << charge[j] << " charge, fitrangemin: " << fit_range_min << ", fitrangemax: " << fit_range_max << ")" << endl;
      cout << "fL: " << results.at(0) << " +/- " << results.at(4) << endl;
      cout << "fR: " << results.at(1) << " +/- " << results.at(5) << endl;
      cout << "f0: " << results.at(2) << " +/- " << results.at(6) << endl;
      cout << "fL-fR: " << results.at(3) << " +/- " << results.at(7) << endl;

      double fit_range_size = fit_range_max - fit_range_min;

      flfr_summary_hist[j]->Fill(fit_range_size,results.at(3));
      flfr_summary_hist[j]->SetBinError(flfr_summary_hist[j]->FindBin(fit_range_size),results.at(7));
      f0_summary_hist[j]->Fill(fit_range_size,results.at(2));
      f0_summary_hist[j]->SetBinError(f0_summary_hist[j]->FindBin(fit_range_size),results.at(6));

      if(j==0) {
	flfr_summary_hist[j]->SetMarkerStyle(20);
	flfr_summary_hist[j]->SetMarkerColor(kBlue);
	f0_summary_hist[j]->SetMarkerStyle(20);
	f0_summary_hist[j]->SetMarkerColor(kBlue);
      } else { 
	flfr_summary_hist[j]->SetMarkerStyle(20);
	flfr_summary_hist[j]->SetMarkerColor(kRed);
	f0_summary_hist[j]->SetMarkerStyle(20);
	f0_summary_hist[j]->SetMarkerColor(kRed);
      }
    
//       if(j==0){
//  	summary_hist_plus->Fill(scale_shift[i],results.at(3));
//  	summary_hist_plus->SetBinError(summary_hist_plus->FindBin(scale_shift[i]),results.at(7));
// 	//summary_hist_plus->Fill(scale_shift[i],(results.at(3) - reference_value[j])/reference_value[j]);
//  	summary_hist_plus->SetMarkerStyle(3);
//       } else {
//  	summary_hist_minus->Fill(scale_shift[i],results.at(3));
//  	summary_hist_minus->SetBinError(summary_hist_minus->FindBin(scale_shift[i]),results.at(7));
// 	//summary_hist_minus->Fill(scale_shift[i],(results.at(3) - reference_value[j])/reference_value[j]);
// 	summary_hist_minus->SetMarkerStyle(5);
// 	summary_hist_minus->SetMarkerColor(kRed);
//       }

    fit_range_min+=0.05;
    fit_range_max-=0.05;

    }
  }

  c1->cd();
  flfr_summary_hist[0]->GetYaxis()->SetRangeUser(0.0,0.5);
  flfr_summary_hist[0]->Draw("E1X0");
  flfr_summary_hist[1]->Draw("E1X0 same");

  leg = new TLegend(0.593,0.178,0.851,0.294,NULL,"brNDC");
  leg->AddEntry(flfr_summary_hist[0],"Plus","p");
  leg->AddEntry(flfr_summary_hist[1],"Minus","p");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->DrawClone();

//   TGaxis *axis = new TGaxis(4.5,0.0, 4.5, 0.5,-reference_value[0]/reference_value[0],(0.5-reference_value[0])/reference_value[0],520,"+L");
//   axis->SetLineColor(kBlue);
//   axis->SetTextColor(kBlue);
//   axis->SetTitle("percentage change (f_{L}-f_{R})");
//   axis->SetTitleColor(kBlack);
//   axis->Draw();

//   TGaxis *axis2 = new TGaxis(3.5,0.0, 3.5, 0.5,-reference_value[1]/reference_value[1],(0.5-reference_value[1])/reference_value[1],520,"+L");
//   axis2->SetLineColor(kRed);
//   axis2->SetTextColor(kRed);
//   axis2->Draw();

  c2->cd();
  f0_summary_hist[0]->GetYaxis()->SetRangeUser(-0.6,1.6);
  f0_summary_hist[0]->Draw("E1X0");
  f0_summary_hist[1]->Draw("E1X0 same");
  leg->DrawClone();
  return;
}

std::vector<double> fit_macro(TH1F * data, TH1F * template1, TH1F * template2, TH1F * template3, unsigned int rebin_factor, float fit_range_min, float fit_range_max, float int_lumi) {

  std::vector<double> results(8);

  data->Rebin(rebin_factor);

  template1->Rebin(rebin_factor);
  template2->Rebin(rebin_factor);
  template3->Rebin(rebin_factor);

  unsigned int fit_range_min_bin = template1->FindBin(fit_range_min);
  unsigned int fit_range_max_bin = template1->FindBin(fit_range_max);

  unsigned int array_size = fit_range_max_bin - fit_range_min_bin;

  //cout << "fit_range_min_bin: " << fit_range_min_bin << endl;
  //cout << "fit_range_max_bin: " << fit_range_max_bin << endl;
  //cout << "array size: " << array_size << endl;

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
  for(unsigned int i=fit_range_min_bin;i<fit_range_max_bin;i++) {
    A_matrixT[0][j] = template1->GetBinContent(i);
    A_matrixT[1][j] = template2->GetBinContent(i);
    A_matrixT[2][j] = template3->GetBinContent(i);

    A_matrix[j][0] = template1->GetBinContent(i);
    A_matrix[j][1] = template2->GetBinContent(i);
    A_matrix[j][2] = template3->GetBinContent(i);
     
    y_matrix[j][0] = data->GetBinContent(i);
    V_matrix[j][j] = data->GetBinContent(i);

    j++;
  }

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
  //C_matrixI.Print();

  thetahat_matrix = (C_matrixI * S_matrix);
  //thetahat_matrix.Print();

  double norm_factor = thetahat_matrix[0][0] + thetahat_matrix[1][0] + thetahat_matrix[2][0];
  //remember that E(aX) = aE(X) and var(aX) = a^2var(X)
  double fL_error = TMath::Sqrt(C_matrixI[0][0] / int_lumi)/(norm_factor);
  double fR_error = TMath::Sqrt(C_matrixI[1][1] / int_lumi)/(norm_factor);
  double f0_error = TMath::Sqrt(C_matrixI[2][2] / int_lumi)/(norm_factor);
  double flfr_error = TMath::Sqrt((C_matrixI[0][0] + C_matrixI[1][1] - 2.0*C_matrixI[0][1]) / int_lumi)/(norm_factor);

//   cout << endl << "Fit Results" << endl;
//   cout << "fL: " << thetahat_matrix[0][0]/norm_factor << " +/- " << fL_error << endl;
//   cout << "fR: " << thetahat_matrix[1][0]/norm_factor << " +/- " << fR_error << endl;
//   cout << "f0: " << thetahat_matrix[2][0]/norm_factor << " +/- " << f0_error << endl;
//   cout << "fL-fR: " << (thetahat_matrix[0][0] - thetahat_matrix[1][0])/norm_factor << " +/- " << flfr_error << endl;

  results.at(0)=thetahat_matrix[0][0]/norm_factor;
  results.at(1)=thetahat_matrix[1][0]/norm_factor;
  results.at(2)=thetahat_matrix[2][0]/norm_factor;
  results.at(3)=(thetahat_matrix[0][0] - thetahat_matrix[1][0])/norm_factor;
  results.at(4)=fL_error;
  results.at(5)=fR_error;
  results.at(6)=f0_error;
  results.at(7)=flfr_error;
  return results;
}
