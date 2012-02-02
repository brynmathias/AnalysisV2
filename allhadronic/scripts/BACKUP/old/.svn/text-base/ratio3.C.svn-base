// -----------------------------------------------------------------------------
/*
*/  
int ratio3() {

  // Constants and arrays

  Int_t multi = 2;

  TString eq = "Eq";

  const Int_t n = 4;
  float pt[n]     = { 50., 40., 30., 20. };
  Int_t colour[n] = { 1, 2, 3, 4 };

  const Int_t m = 3;
  Int_t style[m]  = { kOpenCross, kOpenSquare, kFullSquare };
  
  const Int_t ngr = 1000;
  double x3[ngr];
  double r[ngr];

  int count = 0;
  int loop = 0;

  // General style

  gStyle->SetOptStat(0);
  
  // Canvas for RECO curves 

  TCanvas* reco_canvas = new TCanvas("Reco");
  reco_canvas->SetFillColor(0);
  reco_canvas->SetLineColor(0); 
  reco_canvas->SetLogy();
  
  // Legend for RECO curves 

  TLegend* reco_legend = new TLegend( 0.5, 0.7, 0.88, 0.88, NULL, "brNDC" );
  reco_legend->SetFillColor(0);
  reco_legend->SetLineColor(0); 
  
  // Loop through pt bins

  for ( Int_t i = 0; i < n; ++i ) {

    std::stringstream pt_can;
    pt_can << "PtBin" << pt[i];
    
    // Canvas for Pt bin

    TCanvas* pt_canvas = new TCanvas(TString(pt_can.str()));
    pt_canvas->SetFillColor(0);
    pt_canvas->SetLineColor(0); 
    pt_canvas->SetLogy();
    
    // Legend for Pt bin

    TLegend* pt_legend = new TLegend( 0.5, 0.7, 0.88, 0.88, NULL, "brNDC" );
    pt_legend->SetFillColor(0);
    pt_legend->SetLineColor(0); 

    // Open files

    std::stringstream ss;
    ss << "results/Reco" << pt[i] << "_QCDPythia6.root";
    TString name(ss.str());
    TFile* file = new TFile(name);
    if ( file->IsZombie() || !(file->IsOpen()) ) { continue; }
    file->cd();

    double max = 0.;
    double min = 1.e12;
    
    // Loop through RECO and GEN

    for ( Int_t j = 1; j < m; ++j ) {

      // Define names of histos to open 

      std::stringstream pre;
      std::stringstream post;
      if ( j == 0 ) {
	pre << "Ratio50/GenHt" << eq << "PreAlphaT0.5_" << multi;
	post << "Ratio50/GenHt" << eq << "PostAlphaT0.5_" << multi;
      } else if ( j == 1 ) {
	pre << "Ratio50/GenHt" << eq << "PreAlphaT0.5_" << multi;
	post << "Ratio50/GenHt" << eq << "PostAlphaT0.5_" << multi;
      } else if ( j == 2 ) {
	pre << "Ratio50/Ht" << eq << "PreAlphaT0.5_" << multi;
	post << "Ratio50/Ht" << eq << "PostAlphaT0.5_" << multi;
      }

      // Create ratio histo

      TH1* denominator = (TH1*)file->Get(TString(pre.str()));
      TH1* numerator = (TH1*)file->Get(TString(post.str()));
      int rebin = 5;
      numerator->Rebin(rebin);
      denominator->Rebin(rebin);
      TH1* ratio = (TH1*)numerator->Clone();
      ratio->Divide(denominator);
      ratio->SetMarkerStyle(style[j]);
      ratio->SetMarkerSize(1.5);
      ratio->SetMarkerColor(colour[i]);
      ratio->SetBarOffset(0.1*i);
      ratio->GetXaxis()->SetRangeUser(200.,550.);
      if ( ratio->GetMaximum() > max ) {
	max = ratio->GetMaximum();
	ratio->SetMaximum(max*10.);
      }
      if ( ratio->GetMinimum() > 0 && 
	   ratio->GetMinimum() < min ) {
	min = ratio->GetMinimum();
	ratio->SetMinimum(min/10.);
      }

      //ratio->GetYaxis()->SetRangeUser(4.e-3,4.e-2);
      //ratio->GetYaxis()->SetRangeUser(2.e-7,2.e-3);

      // Draw histos on canvas for pt bins

      pt_canvas->cd();
      if ( j == 1 ) ratio->Draw("");
      else ratio->Draw("same");
      
      std::stringstream pt_leg;
      if ( j == 0 ) {
 	pt_leg << "p_{T}^{min} = " << pt[i] << " GeV, MC truth (N_{jets}^{reco} = " << multi << ")";
      } else if ( j == 1 ) {
 	pt_leg << "p_{T}^{min} = " << pt[i] << " GeV, GEN";//MC truth";// (N_{jets}^{gen} = " << multi << ")";
      } else if ( j == 2 ) {
 	pt_leg << "p_{T}^{min} = " << pt[i] << " GeV, RECO";
      }
      pt_legend->AddEntry( ratio, TString(pt_leg.str()), "lep" );

      // Draw histos on canvas for RECO only
      
      if ( j == 2 ) {
	reco_canvas->cd();
	if ( i == 0 ) ratio->Draw("");
	else ratio->Draw("same");
	std::stringstream reco_leg;
	reco_leg << "p_{T}^{min} = " << pt[i];
	reco_legend->AddEntry( ratio, TString(reco_leg.str()), "lep" );
      }

      loop++;
      
    }

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
    
    pt_canvas->cd();
    pt_legend->Draw("same");
    pt_canvas->Update();
    pt_canvas->SaveAs(TString(pt_can.str()+".png"));
    pt_canvas->SaveAs(TString(pt_can.str()+".C"));
    
  }

  reco_canvas->cd();
  reco_legend->Draw("same");
  reco_canvas->Update();
  reco_canvas->SaveAs(TString("Reco.png"));
  reco_canvas->SaveAs(TString("Reco.C"));
  
//   TCanvas* c2 = new TCanvas("C2");
//   c2->SetLogy();
//   c2->SetFillColor(0);
//   gStyle->SetOptStat(0);
//   if ( count > 0 ) {
//     TGraph* graph = new TGraph(count,x3,r); 
//     graph->Draw("a*");
//   }

  
}
