void myfitmacro5() {
//this macro is used to see the effects of the fit range on the fl-fr and f0 fit results
//combining both the stat (data) and systematic (MC) error using TGraphAsymm errors

  gROOT->SetStyle("Plain");
  //gStyle->SetPadTickY(0);
  gStyle->SetOptStat(0);

  TFile *file0 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_WJets_madgraph_June2010.root");
  TFile *file1 = TFile::Open("results/hltmu15_goodevsel_newtemplates/RecoRoutines_W-selection_realdata.root");
  TFile *file2 = TFile::Open("results/hltmu15_goodevsel_newtemplates/syst_shift_pfmht/RecoRoutines_W-selection_WJets_madgraph_June2010_shift_pfmht_m3pc.root");
  TFile *file3 = TFile::Open("results/hltmu15_goodevsel_newtemplates/syst_shift_pfmht/RecoRoutines_W-selection_WJets_madgraph_June2010_shift_pfmht_p3pc.root");

  TString charge[2] = {"Plus", "Minus"};
  TString bin = "100toinf";
  TString extratitle = "";//"_PTWp1pc";
  float int_lumi_data = 1.0; 
  float int_lumi_mc = 35.0; //to scale the MC which is produced relative to 1/pb

  TString canvas_title1 = "fl-fr_fitrangestatquadsyst_" + bin;
  TString canvas_title2 = "f0_fitrangestatquadsyst_" + bin;

  TCanvas * c1 = new TCanvas(canvas_title1,canvas_title1,500,500);
  TCanvas * c2 = new TCanvas(canvas_title2,canvas_title2,500,500);

  double reference_value_flfr[2] = {1.0, 1.0};
  double reference_value_f0[2] = {1.0, 1.0};

  const unsigned int num_fit_range_bins = 9;

  //make the array two bigger than you want so you can put two dummy values at the equivalent of xmin and xmax in TGraph
  //done automatically - see loop below
  double x_values[num_fit_range_bins] = {0.0};
  double err_x_low[num_fit_range_bins] = {0.0};
  double err_x_high[num_fit_range_bins] = {0.0};

  double y_values_flfr_plus[num_fit_range_bins] = {0.0};
  double y_values_flfr_minus[num_fit_range_bins] = {0.0};
  double y_values_f0_plus[num_fit_range_bins] = {0.0};
  double y_values_f0_minus[num_fit_range_bins] = {0.0};

  double err_y_low_flfr_plus[num_fit_range_bins] = {0.0};
  double err_y_low_flfr_minus[num_fit_range_bins] = {0.0};
  double err_y_low_f0_plus[num_fit_range_bins] = {0.0};
  double err_y_low_f0_minus[num_fit_range_bins] = {0.0};

  double err_y_high_flfr_plus[num_fit_range_bins] = {0.0};
  double err_y_high_flfr_minus[num_fit_range_bins] = {0.0};
  double err_y_high_f0_plus[num_fit_range_bins] = {0.0};
  double err_y_high_f0_minus[num_fit_range_bins] = {0.0};


  unsigned int rebin_factor = 10;

  for(unsigned int j=0;j<2; j++) {
    double fit_range_min = -0.1;
    double fit_range_max = 1.2;
	for(unsigned int i=0; i<(num_fit_range_bins - 2); i++) {
      TH1F * Data_template_mc = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+extratitle)->Clone());
	  TH1F * Data_template = (TH1F*)((TH1F*)file1->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+extratitle)->Clone());
      TH1F * Data_template_m3pc = (TH1F*)((TH1F*)file2->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+extratitle)->Clone());
      TH1F * Data_template_p3pc = (TH1F*)((TH1F*)file3->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+extratitle)->Clone());
    
      TH1F * LH_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LH"))->Clone();
      TH1F * RH_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_RH"))->Clone();
      TH1F * LO_template = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LO"))->Clone();

      TH1F * LH_template_copy2 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LH"))->Clone();
      TH1F * RH_template_copy2 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_RH"))->Clone();
      TH1F * LO_template_copy2 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LO"))->Clone();

      TH1F * LH_template_copy3 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LH"))->Clone();
      TH1F * RH_template_copy3 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_RH"))->Clone();
      TH1F * LO_template_copy3 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LO"))->Clone();

      TH1F * LH_template_copy4 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LH"))->Clone();
      TH1F * RH_template_copy4 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_RH"))->Clone();
      TH1F * LO_template_copy4 = (TH1F*)((TH1F*)file0->Get("RECO_PolPlots_"+bin+"/RECO_ICVarPF"+charge[j]+"_LO"))->Clone();
	
      std::vector<double> results(8);
      results = fit_macro(Data_template, LH_template, RH_template, LO_template, rebin_factor, fit_range_min, fit_range_max, int_lumi_data);
      std::vector<double> results_mc(8);
      results_mc = fit_macro(Data_template_mc, LH_template_copy2, RH_template_copy2, LO_template_copy2, rebin_factor, fit_range_min, fit_range_max, int_lumi_mc);
      std::vector<double> results_m3pc(8);
      results_m3pc = fit_macro(Data_template_m3pc, LH_template_copy3, RH_template_copy3, LO_template_copy3, rebin_factor, fit_range_min, fit_range_max, int_lumi_mc);
      std::vector<double> results_p3pc(8);
      results_p3pc = fit_macro(Data_template_p3pc, LH_template_copy4, RH_template_copy4, LO_template_copy4, rebin_factor, fit_range_min, fit_range_max, int_lumi_mc);

      cout << endl << "Fit Results (" << charge[j] << " charge, fitrangemin: " << fit_range_min << ", fitrangemax: " << fit_range_max << ")" << endl;
      cout << "fL: " << results.at(0) << " +/- " << results.at(4) << endl;
      cout << "fR: " << results.at(1) << " +/- " << results.at(5) << endl;
      cout << "f0: " << results.at(2) << " +/- " << results.at(6) << endl;
      cout << "fL-fR: " << results.at(3) << " +/- " << results.at(7) << endl;

      double fit_range_size = fit_range_max - fit_range_min;

      if(j==0) {
	   x_values[i] = fit_range_size;
	   err_x_low[i] = 0.0;
	   err_x_high[i] = 0.0;

	   y_values_flfr_plus[i] = results.at(3); //result from fit to DATA
	   y_values_f0_plus[i] = results.at(2); //result from fit to DATA

	   err_y_high_flfr_plus[i] = fabs(results_p3pc.at(3) - results_mc.at(3)); //systematic error - difference over the same fit range from mc:p3pc
	   err_y_high_flfr_plus[i] = TMath::Sqrt((err_y_high_flfr_plus[i]*err_y_high_flfr_plus[i]) + (results.at(7)*results.at(7))); //add in quad to data stat error
	   err_y_low_flfr_plus[i] = fabs(results_m3pc.at(3) - results_mc.at(3)); //systematic error - difference over the same fit range from mc:p3pc
       err_y_low_flfr_plus[i] = TMath::Sqrt((err_y_low_flfr_plus[i]*err_y_low_flfr_plus[i]) + (results.at(7)*results.at(7))); //add in quad to data stat error

	   err_y_high_f0_plus[i] = fabs(results_p3pc.at(2) - results_mc.at(2));
	   err_y_high_f0_plus[i] = TMath::Sqrt((err_y_high_f0_plus[i]*err_y_high_f0_plus[i]) + (results.at(6)*results.at(6)));
	   err_y_low_f0_plus[i] = fabs(results_m3pc.at(2) - results_mc.at(2));
       err_y_low_f0_plus[i] = TMath::Sqrt((err_y_low_f0_plus[i]*err_y_low_f0_plus[i]) + (results.at(6)*results.at(6)));

	  } else {
	   y_values_flfr_minus[i] = results.at(3);
       y_values_f0_minus[i] = results.at(2);
       
	   //remember that for the minus charge, the fl-fr increases as mht is scaled down and vice versa
	   err_y_high_flfr_minus[i] = fabs(results_m3pc.at(3) - results_mc.at(3)); //systematic error - difference over the same fit range from mc:p3pc
	   err_y_high_flfr_minus[i] = TMath::Sqrt((err_y_high_flfr_minus[i]*err_y_high_flfr_minus[i]) + (results.at(7)*results.at(7))); //add in quad to data stat error
	   err_y_low_flfr_minus[i] = fabs(results_p3pc.at(3) - results_mc.at(3)); //systematic error - difference over the same fit range from mc:p3pc
       err_y_low_flfr_minus[i] = TMath::Sqrt((err_y_low_flfr_minus[i]*err_y_low_flfr_minus[i]) + (results.at(7)*results.at(7))); //add in quad to data stat error

	   err_y_high_f0_minus[i] = fabs(results_p3pc.at(2) - results_mc.at(2));
	   err_y_high_f0_minus[i] = TMath::Sqrt((err_y_high_f0_minus[i]*err_y_high_f0_minus[i]) + (results.at(6)*results.at(6)));
	   err_y_low_f0_minus[i] = fabs(results_m3pc.at(2) - results_mc.at(2));
       err_y_low_f0_minus[i] = TMath::Sqrt((err_y_low_f0_minus[i]*err_y_low_f0_minus[i]) + (results.at(6)*results.at(6)));


	  }
      
	  if(i==0) {
		reference_value_flfr[j] = results_mc.at(3);
	    reference_value_f0[j] = results_mc.at(2);
	  }

    fit_range_min+=0.05;
    fit_range_max-=0.05;

    }
  }

  c1->cd();
  x_values[num_fit_range_bins - 1] = 5.0;
  
  TGraphAsymmErrors * flfrplusgraph = new TGraphAsymmErrors(num_fit_range_bins, x_values, y_values_flfr_plus, err_x_low, err_x_high, err_y_low_flfr_plus, err_y_high_flfr_plus);
  flfrplusgraph->SetTitle("");
  flfrplusgraph->SetMarkerColor(kBlue);
  flfrplusgraph->SetMarkerStyle(20);
  flfrplusgraph->SetLineColor(kBlue);
  flfrplusgraph->GetYaxis()->SetRangeUser(0.0,0.5);
  flfrplusgraph->GetYaxis()->SetTitle("(f_{L}-f_{R}) data fit result");
  flfrplusgraph->GetXaxis()->SetRangeUser(0.1,3.5);
  flfrplusgraph->GetXaxis()->SetTitle("fit range size");
  flfrplusgraph->Draw("AP");

  TGraphAsymmErrors * flfrminusgraph = new TGraphAsymmErrors(num_fit_range_bins, x_values, y_values_flfr_minus, err_x_low, err_x_high, err_y_low_flfr_minus, err_y_high_flfr_minus);
  flfrminusgraph->SetMarkerColor(kRed);
  flfrminusgraph->SetMarkerStyle(20);
  flfrminusgraph->SetLineColor(kRed);
  flfrminusgraph->Draw("same P");

   TGaxis *axis = new TGaxis(2.4,0.0, 2.4, 0.5,-reference_value_flfr[0],(0.5-reference_value_flfr[0]),520,"+L");
   axis->SetLineColor(kBlue);
   axis->SetTextColor(kBlue);
   axis->SetTitleColor(kBlack);
   axis->Draw();

   TGaxis *axis2 = new TGaxis(2.9,0.0, 2.9, 0.5,-reference_value_flfr[1],(0.5-reference_value_flfr[1]),520,"+L");
   axis2->SetTitle("(f_{L}-f_{R}) Data - MC");
   axis2->SetTitleOffset(1.7);
   axis2->SetLineColor(kRed);
   axis2->SetTextColor(kRed);
   axis2->SetTitleColor(kBlack);
   axis2->Draw();

  leg = new TLegend(0.141,0.761,0.399,0.875,NULL,"brNDC");
  leg->AddEntry(flfrplusgraph,"Plus","p");
  leg->AddEntry(flfrminusgraph,"Minus","p");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextFont(62);
  leg->DrawClone();

  c2->cd();
  TGraphAsymmErrors * f0plusgraph = new TGraphAsymmErrors(num_fit_range_bins, x_values, y_values_f0_plus, err_x_low, err_x_high, err_y_low_f0_plus, err_y_high_f0_plus);
  f0plusgraph->SetTitle("");
  f0plusgraph->SetMarkerColor(kBlue);
  f0plusgraph->SetMarkerStyle(20);
  f0plusgraph->SetLineColor(kBlue);
  f0plusgraph->GetYaxis()->SetRangeUser(0.0,0.5);
  f0plusgraph->GetYaxis()->SetTitle("f_{0} data fit result");
  f0plusgraph->GetXaxis()->SetRangeUser(0.1,3.5);
  f0plusgraph->GetXaxis()->SetTitle("fit range size");
  f0plusgraph->Draw("AP");

  TGraphAsymmErrors * f0minusgraph = new TGraphAsymmErrors(num_fit_range_bins, x_values, y_values_f0_minus, err_x_low, err_x_high, err_y_low_f0_minus, err_y_high_f0_minus);
  f0minusgraph->SetMarkerColor(kRed);
  f0minusgraph->SetMarkerStyle(20);
  f0minusgraph->SetLineColor(kRed);
  f0minusgraph->Draw("same P");

   TGaxis *axis3 = new TGaxis(2.4,0.0, 2.4, 0.5,-reference_value_f0[0],(0.5-reference_value_f0[0]),520,"+L");
   axis3->SetLineColor(kBlue);
   axis3->SetTextColor(kBlue);
   axis3->Draw();

   TGaxis *axis4 = new TGaxis(2.9,0.0, 2.9, 0.5,-reference_value_f0[1],(0.5-reference_value_f0[1]),520,"+L");
   axis4->SetLineColor(kRed);
   axis4->SetTextColor(kRed);
   axis4->SetTitle("f_{0} Data - MC");
   axis4->SetTitleOffset(1.7);
   axis4->SetTitleColor(kBlack);
   axis4->Draw();
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
