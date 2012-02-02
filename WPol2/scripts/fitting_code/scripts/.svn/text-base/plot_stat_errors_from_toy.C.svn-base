void plot_stat_errors_from_toy() {
  //this macro is used to take the toy experiments in bins of fit range, and fit a gaussian to it
  //the results of these fits are then plotted in a TGraph or equivalent.

  gROOT->SetStyle("Plain");
  //gStyle->SetPadTickY(0);
  gStyle->SetOptStat(0);

  TString charge = "minus";
  bool printextrahists = false;
  TString path = "results/";

  TFile *file0 = TFile::Open(path+"outputfile_"+charge+"50toinf.root");
  TFile *file1 = TFile::Open(path+"outputfile_nominalvalues50toinf.root");
  TFile *file2 = TFile::Open(path+"outputfile_mhtshiftp3pcvalues50toinf.root");
  TFile *file3 = TFile::Open(path+"outputfile_mhtshiftm3pcvalues50toinf.root");

  TH1D * summaryhist_flfr = new TH1D("summaryhist_flfr","",30,-0.05,2.95);
  TH1D * summaryhist_f0 = new TH1D("summaryhist_f0","",30,-0.05,2.95);

  TH1D * staterror_flfr = new TH1D("staterror_flfr","",30,-0.05,2.95);
  TH1D * plussysterror_flfr = new TH1D("plussysterror_flfr","",30,-0.05,2.95);
  TH1D * minussysterror_flfr = new TH1D("minussysterror_flfr","",30,-0.05,2.95);
  TH1D * plustotalerror_flfr = new TH1D("plustotalerror_flfr","",30,-0.05,2.95);
  TH1D * minustotalerror_flfr = new TH1D("minustotalerror_flfr","",30,-0.05,2.95);

  TH1D * staterror_f0 = new TH1D("staterror_f0","",30,-0.05,2.95);
  TH1D * plussysterror_f0 = new TH1D("plussysterror_f0","",30,-0.05,2.95);
  TH1D * minussysterror_f0 = new TH1D("minussysterror_f0","",30,-0.05,2.95);
  TH1D * plustotalerror_f0 = new TH1D("plustotalerror_f0","",30,-0.05,2.95);
  TH1D * minustotalerror_f0 = new TH1D("minustotalerror_f0","",30,-0.05,2.95);

  TH1D * nominalvalue = (TH1D*)((TH1D*)file1->Get("flfr_nominalvalues_hist"+charge)->Clone());
  TH1D * p3pcsystshiftvalue = (TH1D*)((TH1D*)file2->Get("flfr_mhtshiftp3pcvalues_hist"+charge)->Clone());
  TH1D * m3pcsystshiftvalue = (TH1D*)((TH1D*)file3->Get("flfr_mhtshiftm3pcvalues_hist"+charge)->Clone());
  TH1D * nominalvaluef0 = (TH1D*)((TH1D*)file1->Get("f0_nominalvalues_hist"+charge)->Clone());
  TH1D * p3pcsystshiftvaluef0 = (TH1D*)((TH1D*)file2->Get("f0_mhtshiftp3pcvalues_hist"+charge)->Clone());
  TH1D * m3pcsystshiftvaluef0 = (TH1D*)((TH1D*)file3->Get("f0_mhtshiftm3pcvalues_hist"+charge)->Clone());

  if(printextrahists) {
    TCanvas * c1 = new TCanvas("c1","c1",500,500);
    TCanvas * c2 = new TCanvas("c2","c2",500,500);
    TCanvas * c3 = new TCanvas("c3","c3",500,500);
    TCanvas * c4 = new TCanvas("c4","c4",500,500);
    TCanvas * c5 = new TCanvas("c5","c5",500,500);
    TCanvas * c6 = new TCanvas("c6","c6",500,500);
    TCanvas * c7 = new TCanvas("c7","c7",500,500);
    TCanvas * c8 = new TCanvas("c8","c8",500,500);
    TCanvas * c9 = new TCanvas("c9","c9",500,500);
    TCanvas * c10 = new TCanvas("c10","c10",500,500);
    TCanvas * c11 = new TCanvas("c11","c11",500,500);
    TCanvas * c12 = new TCanvas("c12","c12",500,500);
  }

  TCanvas * cSummaryflfr = new TCanvas("cSummaryflfr","cSummaryflfr",800,800);
  TCanvas * cSummaryf0 = new TCanvas("cSummaryf0","cSummaryf0",800,800);

  std::vector<double> means(5);
  std::vector<double> sigmas(5);
  std::vector<double> means2(5);
  std::vector<double> sigmas2(5);

  //for the tgraphs
  double x_values_stat[5] = {0.0};
  double x_values_syst[5] = {0.0};
  double x_values_total[5] = {0.0};
  double err_x_low[5] = {0.0};
  double err_x_high[5] = {0.0};
  double y_values[5] = {0.0};
  double staterr_y_low_flfr[5] = {0.0};
  double staterr_y_high_flfr[5] = {0.0};
  double systerr_y_low_flfr[5] = {0.0};
  double systerr_y_high_flfr[5] = {0.0};
  double toterr_y_low_flfr[5] = {0.0};
  double toterr_y_high_flfr[5] = {0.0};
  double staterr_y_low_f0[5] = {0.0};
  double staterr_y_high_f0[5] = {0.0};
  double systerr_y_low_f0[5] = {0.0};
  double systerr_y_high_f0[5] = {0.0};
  double toterr_y_low_f0[5] = {0.0};
  double toterr_y_high_f0[5] = {0.0};

  //the fit range parameters
  double xmin = -0.4;
  double xmax = 1.6;
  for(unsigned int i=0; i<5; i++) {

    char buffer [50];
    int n;
    n=sprintf (buffer, "%.2f", (xmax-xmin));
    //printf ("[%s] is a %d char long string\n",buffer,n);
    TString mystring = buffer;
    //cout << mystring << endl;

    TH1D * hist1 = (TH1D*)((TH1D*)file0->Get("flfrtoystudyhist_fitrange"+mystring)->Clone());
    TH1D * hist2 = (TH1D*)((TH1D*)file0->Get("f0toystudyhist_fitrange"+mystring)->Clone());
    hist1->Rebin(10);
    hist2->Rebin(10);
    TF1 * f1 = new TF1("f1","gaus",0.28,0.4);
    TF1 * f2 = new TF1("f2","gaus",0.0,0.5);
    if(charge == "plus") {
      if(xmax-xmin == 1.80) {
	TFitResultPtr r1 = (hist1->Fit(f1,"SR"));
	TFitResultPtr r2 = (hist2->Fit(f2,"SR"));
      } else {
	TFitResultPtr r1 = (hist1->Fit(f1,"S"));
	TFitResultPtr r2 = (hist2->Fit(f2,"S"));
      }
    } else {
      TFitResultPtr r1 = (hist1->Fit(f1,"S"));
      TFitResultPtr r2 = (hist2->Fit(f2,"S"));
    }
    //r1->Print("V");
    //r1->Value(1); // the mean
    //r1->Value(2); // the sigma
    summaryhist_flfr->Fill(xmax-xmin,r1->Value(1));
    summaryhist_flfr->SetBinError(summaryhist_flfr->FindBin(xmax-xmin),r1->Value(2));
    summaryhist_f0->Fill(xmax-xmin,r2->Value(1));
    summaryhist_f0->SetBinError(summaryhist_f0->FindBin(xmax-xmin),r2->Value(2));
    //staterror_flfr->Fill((xmax-xmin),(r1->Value(2)/r1->Value(1)));

    double nominalv = nominalvalue->GetBinContent(nominalvalue->FindBin(xmax-xmin));
    double nominals = nominalvalue->GetBinError(nominalvalue->FindBin(xmax-xmin));
    double nominalvf0 = nominalvaluef0->GetBinContent(nominalvaluef0->FindBin(xmax-xmin));
    double nominalsf0 = nominalvaluef0->GetBinError(nominalvaluef0->FindBin(xmax-xmin));

    staterror_flfr->Fill((xmax-xmin),nominals/nominalv);
    staterror_f0->Fill((xmax-xmin),nominalsf0/nominalvf0);

    cout << "nominalv = " << nominalv << endl;
    cout << "nominals = " << nominals << endl;
    cout << "nominalvf0 = " << nominalvf0 << endl;
    cout << "nominalsf0 = " << nominalsf0 << endl;
    
    TH1D * pullexample = new TH1D("pullexample","pullexample",200,-1.05,0.95);
    TH1D * pullexample2 = new TH1D("pullexample2","pullexample2",200,-1.05,0.95);
    TH1D * hist1norebin = (TH1D*)((TH1D*)file0->Get("flfrtoystudyhist_fitrange"+mystring)->Clone());
    TH1D * hist2norebin = (TH1D*)((TH1D*)file0->Get("f0toystudyhist_fitrange"+mystring)->Clone());
    unsigned int total = hist1norebin->GetNbinsX();
    for(unsigned int j=0; j<total; j++) {
      double bincontent = hist1norebin->GetBinContent(j);
      double norm = ((hist1norebin->GetBinCenter(j) - nominalv));
      pullexample->Fill(norm,bincontent);
    }
    total = hist2norebin->GetNbinsX();
    for(unsigned int j=0; j<total; j++) {
      double bincontent = hist2norebin->GetBinContent(j);
      double norm = ((hist2norebin->GetBinCenter(j) - nominalvf0));
      pullexample2->Fill(norm,bincontent);
    }

    TF1 * f3 = new TF1("f3","gaus",-0.07,1.0);
    TF1 * f4 = new TF1("f4","gaus",-0.3,0.3);
    if(charge == "plus") {
      if(xmax-xmin == 1.8 ) {
	TFitResultPtr r3 = (pullexample->Fit(f3,"SR"));
	TFitResultPtr r4 = (pullexample2->Fit(f4,"SR"));
      } else {
	TFitResultPtr r3 = (pullexample->Fit(f3,"S"));
	TFitResultPtr r4 = (pullexample2->Fit(f4,"S"));
      }
    } else {
      TFitResultPtr r3 = (pullexample->Fit(f3,"S"));
      TFitResultPtr r4 = (pullexample2->Fit(f4,"S"));
    }
    means.at(i) = r3->Value(1);
    sigmas.at(i) = r3->Value(2) / nominals;
    means2.at(i) = r4->Value(1);
    sigmas2.at(i) = r4->Value(2) / nominalsf0;
    //cout << "mean = " << r3->Value(1) << endl;
    //cout << "sigma = " << r3->Value(2) << endl;
    //cout << "sigma ratio = " << r3->Value(2) / nominals << endl;

    
    double sysshiftp3pcv = p3pcsystshiftvalue->GetBinContent(p3pcsystshiftvalue->FindBin(xmax-xmin));
    double sysshiftm3pcv = m3pcsystshiftvalue->GetBinContent(m3pcsystshiftvalue->FindBin(xmax-xmin));
    double sysshiftp3pcvf0 = p3pcsystshiftvaluef0->GetBinContent(p3pcsystshiftvaluef0->FindBin(xmax-xmin));
    double sysshiftm3pcvf0 = m3pcsystshiftvaluef0->GetBinContent(m3pcsystshiftvaluef0->FindBin(xmax-xmin));
    if(charge == "plus") {
      plussysterror_flfr->Fill((xmax-xmin),(sysshiftp3pcv / nominalv)-1.0);
      minussysterror_flfr->Fill((xmax-xmin), 1.0 - (sysshiftm3pcv / nominalv));
      plustotalerror_flfr->Fill((xmax-xmin),TMath::Sqrt(((sysshiftp3pcv / nominalv)-1.0) * ((sysshiftp3pcv / nominalv)-1.0) + (nominals/nominalv)*(nominals/nominalv)));
      minustotalerror_flfr->Fill((xmax-xmin),TMath::Sqrt((1.0-(sysshiftm3pcv / nominalv)) * (1.0-(sysshiftm3pcv / nominalv)) + (nominals/nominalv)*(nominals/nominalv)));
    } else {
      plussysterror_flfr->Fill((xmax-xmin),1.0 - (sysshiftp3pcv / nominalv));
      minussysterror_flfr->Fill((xmax-xmin), (sysshiftm3pcv / nominalv) - 1.0);
      plustotalerror_flfr->Fill((xmax-xmin),TMath::Sqrt((1.0-(sysshiftp3pcv / nominalv)) * (1.0-(sysshiftp3pcv / nominalv)) + (nominals/nominalv)*(nominals/nominalv)));
      minustotalerror_flfr->Fill((xmax-xmin),TMath::Sqrt(((sysshiftm3pcv / nominalv)-1.0) * ((sysshiftm3pcv / nominalv)-1.0) + (nominals/nominalv)*(nominals/nominalv)));
    }

    plussysterror_f0->Fill((xmax-xmin),(sysshiftp3pcvf0 / nominalvf0)-1.0);
    minussysterror_f0->Fill((xmax-xmin), 1.0-(sysshiftm3pcvf0 / nominalvf0));
    plustotalerror_f0->Fill((xmax-xmin),TMath::Sqrt(((sysshiftp3pcvf0 / nominalvf0)-1.0) * ((sysshiftp3pcvf0 / nominalvf0)-1.0) + (nominalsf0/nominalvf0)*(nominalsf0/nominalvf0)));
    minustotalerror_f0->Fill((xmax-xmin),TMath::Sqrt((1.0-(sysshiftm3pcvf0 / nominalvf0)) * (1.0-(sysshiftm3pcvf0 / nominalvf0)) + (nominalsf0/nominalvf0)*(nominalsf0/nominalvf0)));    


    //for the tgraphs which summarises all the above information:
    x_values_total[i] = (xmax-xmin);
    x_values_stat[i] = (xmax-xmin)-0.01;
    x_values_syst[i] = (xmax-xmin)+0.01;
    y_values[i] = 0.0;
    err_x_low[i] = 0.0;
    err_x_high[i] = 0.0;
    staterr_y_low_flfr[i] = (nominals/nominalv) * 100.0;
    staterr_y_high_flfr[i] = (nominals/nominalv) * 100.0;
    staterr_y_low_f0[i] = (nominalsf0/nominalvf0) * 100.0;
    staterr_y_high_f0[i] = (nominalsf0/nominalvf0) * 100.0;
    if(charge == "plus") {
      systerr_y_high_flfr[i] = ((sysshiftp3pcv / nominalv)-1.0) * 100.0;
      systerr_y_low_flfr[i] = (1.0 - (sysshiftm3pcv / nominalv)) * 100.0;
      toterr_y_high_flfr[i] = 100.0 * TMath::Sqrt(((sysshiftp3pcv / nominalv)-1.0) * ((sysshiftp3pcv / nominalv)-1.0) + (nominals/nominalv)*(nominals/nominalv));
      toterr_y_low_flfr[i] = 100.0 * TMath::Sqrt((1.0-(sysshiftm3pcv / nominalv)) * (1.0-(sysshiftm3pcv / nominalv)) + (nominals/nominalv)*(nominals/nominalv));
    } else {
      systerr_y_high_flfr[i] = (1.0 - (sysshiftp3pcv / nominalv)) * 100.0;
      systerr_y_low_flfr[i] = ((sysshiftm3pcv / nominalv) - 1.0) * 100.0;
      toterr_y_high_flfr[i] = 100.0 * TMath::Sqrt((1.0-(sysshiftp3pcv / nominalv)) * (1.0-(sysshiftp3pcv / nominalv)) + (nominals/nominalv)*(nominals/nominalv));
      toterr_y_low_flfr[i] = 100.0 * TMath::Sqrt(((sysshiftm3pcv / nominalv)-1.0) * ((sysshiftm3pcv / nominalv)-1.0) + (nominals/nominalv)*(nominals/nominalv));
    }
    systerr_y_high_f0[i] = 100.0 * ((sysshiftp3pcvf0 / nominalvf0)-1.0);
    systerr_y_low_f0[i] = 100.0 * (1.0-(sysshiftm3pcvf0 / nominalvf0));
    toterr_y_high_f0[i] = 100.0 * TMath::Sqrt(((sysshiftp3pcvf0 / nominalvf0)-1.0) * ((sysshiftp3pcvf0 / nominalvf0)-1.0) + (nominalsf0/nominalvf0)*(nominalsf0/nominalvf0));
    toterr_y_low_f0[i] = 100.0 * TMath::Sqrt((1.0-(sysshiftm3pcvf0 / nominalvf0)) * (1.0-(sysshiftm3pcvf0 / nominalvf0)) + (nominalsf0/nominalvf0)*(nominalsf0/nominalvf0));

    xmin+=0.1;
    xmax-=0.1;
    }

  for(unsigned int k=0; k<means.size(); k++) {
    cout << "mean fl-fr = " << means.at(k) << endl; 
    cout << "sigma fl-fr = " << sigmas.at(k) << endl;
    cout << "mean f0 = " << means2.at(k) << endl; 
    cout << "sigma f0 = " << sigmas2.at(k) << endl;
  }

  const unsigned int numbins = 5;
  TGraphAsymmErrors * flfrsummaryhist_stat = new TGraphAsymmErrors(numbins, x_values_stat, y_values, err_x_low, err_x_high, staterr_y_low_flfr, staterr_y_high_flfr);
  TGraphAsymmErrors * flfrsummaryhist_syst = new TGraphAsymmErrors(numbins, x_values_syst, y_values, err_x_low, err_x_high, systerr_y_low_flfr, systerr_y_high_flfr);
  TGraphAsymmErrors * flfrsummaryhist_total = new TGraphAsymmErrors(numbins, x_values_total, y_values, err_x_low, err_x_high, toterr_y_low_flfr, toterr_y_high_flfr);
  TGraphAsymmErrors * f0summaryhist_stat = new TGraphAsymmErrors(numbins, x_values_stat, y_values, err_x_low, err_x_high, staterr_y_low_f0, staterr_y_high_f0);
  TGraphAsymmErrors * f0summaryhist_syst = new TGraphAsymmErrors(numbins, x_values_syst, y_values, err_x_low, err_x_high, systerr_y_low_f0, systerr_y_high_f0);
  TGraphAsymmErrors * f0summaryhist_total = new TGraphAsymmErrors(numbins, x_values_total, y_values, err_x_low, err_x_high, toterr_y_low_f0, toterr_y_high_f0);

  legflfr = new TLegend(0.138,0.137,0.396,0.251,NULL,"brNDC");
  legflfr->AddEntry(flfrsummaryhist_stat,"Statistical","l");
  legflfr->AddEntry(flfrsummaryhist_syst,"Systematic","l");
  legflfr->AddEntry(flfrsummaryhist_total,"Total","l");
  legflfr->SetFillColor(kWhite);
  legflfr->SetBorderSize(0);
  legflfr->SetTextFont(62);

  legf0 = new TLegend(0.138,0.137,0.396,0.251,NULL,"brNDC");
  legf0->AddEntry(f0summaryhist_stat,"Statistical","l");
  legf0->AddEntry(f0summaryhist_syst,"Systematic","l");
  legf0->AddEntry(f0summaryhist_total,"Total","l");
  legf0->SetFillColor(kWhite);
  legf0->SetBorderSize(0);
  legf0->SetTextFont(62);


  if(printextrahists) {
    c1->cd();
    summaryhist_flfr->SetMarkerStyle(20);
    summaryhist_flfr->Draw("EX0");
    summaryhist_flfr->GetXaxis()->SetTitle("fit range size");
    summaryhist_flfr->GetXaxis()->SetRangeUser(0.5,2.5);
    summaryhist_flfr->GetYaxis()->SetTitle("(f_{L} - f_{R})");
    summaryhist_flfr->GetYaxis()->SetRangeUser(0.0,0.5);
    //pullexample2->Draw();
    c2->cd();
    summaryhist_f0->SetMarkerStyle(20);
    summaryhist_f0->Draw("EX0");
    summaryhist_f0->GetXaxis()->SetTitle("fit range size");
    summaryhist_f0->GetXaxis()->SetRangeUser(0.5,2.5);
    summaryhist_f0->GetYaxis()->SetTitle("(f_{L} - f_{R})");
    summaryhist_f0->GetYaxis()->SetRangeUser(0.0,0.5);
    c3->cd();
    staterror_flfr->GetXaxis()->SetTitle("fit range size");
    staterror_flfr->GetXaxis()->SetRangeUser(0.5,2.5);
    staterror_flfr->GetYaxis()->SetTitle("percentage error / 100");
    staterror_flfr->Draw("hist");
    //summaryhist_f0->Draw("E");
    c4->cd();
    staterror_f0->GetXaxis()->SetTitle("fit range size");
    staterror_f0->GetXaxis()->SetRangeUser(0.5,2.5);
    staterror_f0->GetYaxis()->SetTitle("percentage error / 100");
    staterror_f0->Draw("hist");
    c5->cd();
    //pullexample->Draw("hist");
    plussysterror_flfr->GetXaxis()->SetTitle("fit range size");
    plussysterror_flfr->GetXaxis()->SetRangeUser(0.5,2.5);
    plussysterror_flfr->GetYaxis()->SetRangeUser(0.0,0.2);
    plussysterror_flfr->Draw("hist");
    plussysterror_flfr->GetYaxis()->SetTitle("percentage error / 100");
    //plustotalerror_f0->Draw("hist");
    c6->cd();
    //minustotalerror_f0->Draw("hist");
    minussysterror_flfr->GetXaxis()->SetTitle("fit range size");
    minussysterror_flfr->GetXaxis()->SetRangeUser(0.5,2.5);
    minussysterror_flfr->GetYaxis()->SetRangeUser(0.0,0.2);
    minussysterror_flfr->GetYaxis()->SetTitle("percentage error / 100");
    minussysterror_flfr->Draw("hist");
    c7->cd();
    plussysterror_f0->GetXaxis()->SetTitle("fit range size");
    plussysterror_f0->GetXaxis()->SetRangeUser(0.5,2.5);
    plussysterror_f0->GetYaxis()->SetRangeUser(0.0,0.5);
    plussysterror_f0->GetYaxis()->SetTitle("percentage error / 100");
    plussysterror_f0->Draw("hist");
    c8->cd();
    minussysterror_f0->GetXaxis()->SetTitle("fit range size");
    minussysterror_f0->GetXaxis()->SetRangeUser(0.5,2.5);
    minussysterror_f0->GetYaxis()->SetRangeUser(0.0,0.5);
    minussysterror_f0->GetYaxis()->SetTitle("percentage error / 100");
    minussysterror_f0->Draw("hist");
    c9->cd();
    plustotalerror_flfr->GetXaxis()->SetTitle("fit range size");
    plustotalerror_flfr->GetXaxis()->SetRangeUser(0.5,2.5);
    plustotalerror_flfr->GetYaxis()->SetRangeUser(0.0,0.5);
    plustotalerror_flfr->GetYaxis()->SetTitle("percentage error / 100");
    plustotalerror_flfr->Draw("hist");
 
    c10->cd();
    minustotalerror_flfr->GetXaxis()->SetTitle("fit range size");
    minustotalerror_flfr->GetXaxis()->SetRangeUser(0.5,2.5);
    minustotalerror_flfr->GetYaxis()->SetRangeUser(0.0,0.5);
    minustotalerror_flfr->GetYaxis()->SetTitle("percentage error / 100");
    minustotalerror_flfr->Draw("hist");

    c11->cd();
    plustotalerror_f0->GetXaxis()->SetTitle("fit range size");
    plustotalerror_f0->GetXaxis()->SetRangeUser(0.5,2.5);
    plustotalerror_f0->GetYaxis()->SetRangeUser(0.0,0.5);
    plustotalerror_f0->GetYaxis()->SetTitle("percentage error / 100");
    plustotalerror_f0->Draw("hist");

    c12->cd();
    minustotalerror_f0->GetXaxis()->SetTitle("fit range size");
    minustotalerror_f0->GetXaxis()->SetRangeUser(0.5,2.5);
    minustotalerror_f0->GetYaxis()->SetRangeUser(0.0,0.5);
    minustotalerror_f0->GetYaxis()->SetTitle("percentage error / 100");
    minustotalerror_f0->Draw("hist");
  }

  cSummaryflfr->cd();
  flfrsummaryhist_stat->SetTitle("");
  flfrsummaryhist_stat->SetMarkerColor(kBlue);
  flfrsummaryhist_stat->SetMarkerStyle(20);
  flfrsummaryhist_stat->SetLineColor(kBlue);
  flfrsummaryhist_stat->SetLineWidth(2);
  flfrsummaryhist_stat->GetYaxis()->SetRangeUser(-30.0,30.0);
  if(charge == "plus") flfrsummaryhist_stat->GetYaxis()->SetTitle("(f_{L}-f_{R})^{+} percentage error");
  else flfrsummaryhist_stat->GetYaxis()->SetTitle("(f_{L}-f_{R})^{-} percentage error");
  //flfrsummaryhist_stat->GetXaxis()->SetRangeUser(0.1,3.5);
  flfrsummaryhist_stat->GetXaxis()->SetTitle("fit range size");
  flfrsummaryhist_stat->Draw("AP");

  flfrsummaryhist_syst->SetMarkerColor(kRed);
  flfrsummaryhist_syst->SetMarkerStyle(20);
  flfrsummaryhist_syst->SetLineColor(kRed);
  flfrsummaryhist_syst->SetLineWidth(2);
  flfrsummaryhist_syst->Draw("same P");

  flfrsummaryhist_total->SetMarkerColor(kBlack);
  flfrsummaryhist_total->SetMarkerStyle(20);
  flfrsummaryhist_total->SetLineColor(kBlack);
  flfrsummaryhist_total->SetLineWidth(2);
  flfrsummaryhist_total->Draw("same P");
  legflfr->DrawClone();

  cSummaryf0->cd();
  f0summaryhist_stat->SetTitle("");
  f0summaryhist_stat->SetMarkerColor(kBlue);
  f0summaryhist_stat->SetMarkerStyle(20);
  f0summaryhist_stat->SetLineColor(kBlue);
  f0summaryhist_stat->SetLineWidth(2);
  f0summaryhist_stat->GetYaxis()->SetRangeUser(-90.0,90.0);
  if(charge == "plus") f0summaryhist_stat->GetYaxis()->SetTitle("f_{0}^{+} percentage error");
  else f0summaryhist_stat->GetYaxis()->SetTitle("f_{0}^{-} percentage error");
  //f0summaryhist_stat->GetXaxis()->SetRangeUser(0.1,3.5);
  f0summaryhist_stat->GetXaxis()->SetTitle("fit range size");
  f0summaryhist_stat->Draw("AP");

  f0summaryhist_syst->SetMarkerColor(kRed);
  f0summaryhist_syst->SetMarkerStyle(20);
  f0summaryhist_syst->SetLineColor(kRed);
  f0summaryhist_syst->SetLineWidth(2);
  f0summaryhist_syst->Draw("same P");

  f0summaryhist_total->SetMarkerColor(kBlack);
  f0summaryhist_total->SetMarkerStyle(20);
  f0summaryhist_total->SetLineColor(kBlack);
  f0summaryhist_total->SetLineWidth(2);
  f0summaryhist_total->Draw("same P");
  legf0->DrawClone();

  return;
}
