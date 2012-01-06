// -----------------------------------------------------------------------------
/*
*/  
int ratio() {
  
  TCanvas* canvas = new TCanvas("Ratio");
  canvas->SetLogy();
  canvas->SetFillColor(0);
  gStyle->SetOptStat(0);
  
  TLegend* legend = new TLegend( 0.6, 0.6, 0.8, 0.8, NULL, "brNDC" );
  legend->SetFillColor(0);
  legend->SetLineColor(0); 
  
  const Int_t n = 6;
  TString sample[n] = { "Gen100", "Gen50", "Gen30", "Reco100", "Reco50", "Reco30" };
  Int_t style[n]  = { 20, 21, 22, 24, 25, 26 };
  Int_t colour[n] = { 2, 3, 4, 2, 3, 4 };
//   TString sample[n] = { "Gen100" };
//   Int_t style[n]  = { 20 };
//   Int_t colour[n] = { 2 };
  
  for ( Int_t i = 0; i < n; ++i ) {
    TString name = "results/All/" + sample[i] + "_QCDPythia6.root";
    TFile* file = new TFile(name);
    file->cd();
    TH1* numerator = (TH1*)file->Get("PostAlphaT/HT_2");
    TH1* denominator = (TH1*)file->Get("PreAlphaT/HT_2");
    int rebin = 1;
    numerator->Rebin(rebin);
    denominator->Rebin(rebin);
    TH1* ratio = numerator->Clone();
    ratio->GetXaxis()->SetRangeUser(0.,1400.);
    ratio->Divide(denominator);
    ratio->SetMarkerStyle(style[i]);
    ratio->SetMarkerColor(colour[i]);

    canvas->cd();
    if ( i == 0 ) ratio->Draw("");
    else ratio->Draw("same");
    legend->AddEntry( ratio, sample[i], "lep" );

    if (0) {

      int nbins = ratio->GetNbinsX();
      int bin_width = ratio->GetBinWidth(1);
      
      double lower = 0.;
      double upper = 1400.;
      
      int bin_lower = int( ( lower - ratio->GetBinLowEdge(1) ) / bin_width );
      for ( Int_t ii = bin_lower; ii < ratio->GetNbinsX()-1; ++ii ) {
	if ( ratio->GetBinContent(ii) > 0. ) { 
	  lower = ratio->GetBinCenter(ii);
	  break;
	}
      }
      int bin_upper = int( ( upper - ratio->GetBinLowEdge(1) ) / bin_width );
      for ( Int_t ii = bin_upper; ii > 0; --ii ) {
	if ( ratio->GetBinContent(ii) > 0. ) { 
	  upper = ratio->GetBinCenter(ii);
	  break;
	}
      }
      if (0) {
	std::cout << " bin_width: " << bin_width
		  << " bin_lower: " << bin_lower
		  << " bin_upper: " << bin_upper
		  << " lower: " << lower
		  << " upper: " << upper
		  << std::endl;
      }

      TF1* fit = new TF1(sample[i],"expo",lower,upper); 
      fit->SetLineColor(colour[i]);
      fit->SetLineWidth(1);
      ratio->Fit(sample[i],"QR","same");

    }

  }
  
  canvas->cd();
  legend->Draw("same");
  canvas->Update();

  

  
}
