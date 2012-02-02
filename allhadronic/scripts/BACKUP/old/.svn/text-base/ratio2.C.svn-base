// -----------------------------------------------------------------------------
/*
*/  
int ratio2() {

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

  // Loop through pt bins
  for ( Int_t i = 0; i < n; ++i ) {

    std::stringstream can;
    can << "Pt" << pt[i];
    
    TCanvas* canvas = new TCanvas(TString("Ratio"+can.str()));
    canvas->SetLogy();
    canvas->SetFillColor(0);
    gStyle->SetOptStat(0);
    
    TLegend* legend = new TLegend( 0.5, 0.7, 0.88, 0.88, NULL, "brNDC" );
    legend->SetFillColor(0);
    legend->SetLineColor(0); 
    
    std::stringstream ss;
    ss << "results/all/Reco" << pt[i] << "_QCDPythia6.root";
    TString name(ss.str());
    TFile* file = new TFile(name);
    if ( file->IsZombie() || !(file->IsOpen()) ) { continue; }
    file->cd();
    
    // Loop through MC reco, MC gen (binned by Nreco), MC gen (binned by Ngen)
    for ( Int_t j = 0; j < m; ++j ) {
      
      std::stringstream pre;
      std::stringstream post;
      if ( j == 0 ) {
	pre << "Ratio50/GenHtPreAlphaT0.5_2";
	post << "Ratio50/GenHtPostAlphaT0.5_2";
      } else if ( j == 1 ) {
	pre << "Ratio50/GenHtGenMultiPreAlphaT0.5_2";
	post << "Ratio50/GenHtGenMultiPostAlphaT0.5_2";
      } else if ( j == 2 ) {
	pre << "Ratio50/HtPreAlphaT0.5_2";
	post << "Ratio50/HtPostAlphaT0.5_2";
      }

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
      ratio->GetYaxis()->SetRangeUser(4.e-3,4.e-2);
      
//       if ( i < 3 ) {
// 	for ( Int_t ii = 1; ii < ratio->GetNbinsX(); ++ii ) {
// 	  double val = ratio->GetBinContent(ii);
// 	  if ( val == 0. ) { continue; }
// 	  if ( count < ngr ) { 
// 	    double ht = ratio->GetBinLowEdge(ii);
// // 	    if ( ht < 150. || ht > 650. ) { continue; }
// 	    double temp = ( 2. * pt[i] ) / ( ht + pt[i] );
// // 	    std::cout << " ht: " << ht 
// // 		      << " pt: " << pt[i]
// // 		      << " x3: " << temp
// // 		      << std::endl;
// 	    x3[count] = temp;
// 	    r[count] = val;
// 	    count++;
// 	  }
// 	}
//       }
      
      canvas->cd();
      if ( j == 0 ) ratio->Draw("");
      else ratio->Draw("same");
      loop++;
      
      std::stringstream leg;
      if ( j == 0 ) {
 	leg << "p_{T}^{min} = " << pt[i] << " GeV, MC truth (N_{jets}^{reco} = 2)";
      } else if ( j == 1 ) {
 	leg << "p_{T}^{min} = " << pt[i] << " GeV, MC truth (N_{jets}^{gen} = 2)";
      } else if ( j == 2 ) {
 	leg << "p_{T}^{min} = " << pt[i] << " GeV, RECO";
      }
      legend->AddEntry( ratio, TString(leg.str()), "lep" );
      
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

    canvas->cd();
    legend->Draw("same");
    canvas->Update();
    
    canvas->SaveAs(TString(can.str()+".pdf"));
    canvas->SaveAs(TString(can.str()+".png"));
    canvas->SaveAs(TString(can.str()+".C"));
    
  }
  
//   TCanvas* c2 = new TCanvas("C2");
//   c2->SetLogy();
//   c2->SetFillColor(0);
//   gStyle->SetOptStat(0);
//   if ( count > 0 ) {
//     TGraph* graph = new TGraph(count,x3,r); 
//     graph->Draw("a*");
//   }

  
}
