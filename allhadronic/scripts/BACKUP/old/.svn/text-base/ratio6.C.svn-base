#include <vector>

// -----------------------------------------------------------------------------
/*
*/  
TH1* his( TH1* input, Int_t nbins, Double_t xlow, Double_t xhigh ) {
  if ( !input ) { return 0; }
  TString name( TString(input->GetName()) + "Clone" );
  TH1F* output = new TH1F( name, "", input->GetNbinsX(), xlow, xhigh );
  for ( Int_t bin = 1; bin < input->GetNbinsX()+1; ++bin ) {
    Double_t centre = input->GetBinLowEdge(bin) + input->GetBinWidth(bin)/2.;
    if ( centre > xlow && 
	 centre < xhigh && 
	 input->GetBinContent(bin) > 0. ) {
      output->Fill( centre, input->GetBinContent(bin) );
    }
  }
  output->Sumw2();
  output->Rebin(Int_t(input->GetNbinsX()/nbins));
  return output;
}

// -----------------------------------------------------------------------------
/*
*/  
int ratio6() {

  // Constants and arrays

  Int_t multi = 2;

  const Int_t n_at = 3;
  Int_t at[n_at] = { 500, 510, 550 };
  //for ( int ii = 0; ii < n_at; ++ii ) { at[ii] = 500 + ii * 10; }

  TString eq = "Gt";

  const Int_t n = 4;
  float pt[n]     = { 50., 40., 30., 20. };
  Int_t colour[n] = { 1, 2, 3, 4 };

  const Int_t m = 2;
  Int_t style[m]  = { kOpenSquare, kFullSquare };
  
  const Int_t ngr = 1000;
  double x3[ngr];
  double r[ngr];

  int count = 0;

  // General style

  gStyle->SetOptStat(0);
  
//   // Canvas for RECO curves 
//   TCanvas* reco_canvas = new TCanvas("Reco");
//   reco_canvas->SetFillColor(0);
//   reco_canvas->SetLineColor(0); 
//   reco_canvas->SetLogy();
//   TLegend* reco_legend = new TLegend( 0.5, 0.7, 0.88, 0.88, NULL, "brNDC" );
//   reco_legend->SetFillColor(0);
//   reco_legend->SetLineColor(0); 
//   bool empty = true;
//   double reco_max = 1.e-15.;
//   double reco_min = 1.e15;
  
  // Loop through pt bins

  for ( Int_t i = 0; i < 1; ++i ) {

    std::stringstream pt_can;
    pt_can << "PtBin" << pt[i];
    
    // Canvas for Pt bin
    TCanvas* pt_canvas = new TCanvas(TString(pt_can.str()),"");
    pt_canvas->SetFillColor(0);
    pt_canvas->SetLineColor(0); 
    pt_canvas->SetLogy();
    TLegend* pt_legend = new TLegend( 0.82, 0.5, 0.98, 0.9, NULL, "brNDC" );

    pt_legend->SetFillColor(0);
    pt_legend->SetLineColor(0); 
    bool empty = true;
    double pt_max = 1.e-15.;
    double pt_min = 1.e15;
    std::vector<TH1*> pt_ratio;

    pt_canvas->SetRightMargin(0.2);

    // Open files
    std::stringstream ss;
    ss << "results/4/Reco" << pt[i] << "_QCDPythia6.root";
    TString name(ss.str());
    TFile* file = new TFile(name);
    if ( file->IsZombie() || !(file->IsOpen()) ) { continue; }
    file->cd();
    
    // Loop through AlphaT thresolds
    for ( Int_t iat = 0; iat < n_at; ++iat ) {
      
      // Loop through RECO and GEN
      for ( Int_t j = 0; j < m; ++j ) {
	
	// Define names of histos to open 
	std::stringstream pre;
	std::stringstream post;
	if ( j == 0 ) {
	  pre << "Ratio" << at[iat] << "Pt" << pt[i] << "/GenHt" << eq << "Pre" << "_" << multi;
	  post << "Ratio" << at[iat] << "Pt" << pt[i] << "/GenHt" << eq << "Post" << "_" << multi;
	  std::cout << pre.str() << std::endl;
	  std::cout << post.str() << std::endl;
	} else if ( j == 1 ) {
	  pre << "Ratio" << at[iat] << "Pt" << pt[i] << "/Ht" << eq << "Pre" << "_" << multi;
	  post << "Ratio" << at[iat] << "Pt" << pt[i] << "/Ht" << eq << "Post" << "_" << multi;
	  std::cout << pre.str() << std::endl;
	  std::cout << post.str() << std::endl;
	}
	
	// Create ratio histo
	TH1* denominator = his( (TH1*)file->Get(TString(pre.str())), 45, 200., 650. );
	TH1* numerator = his( (TH1*)file->Get(TString(post.str())), 45, 200., 650. );
	int rebin = 5;
	numerator->Rebin(rebin);
	denominator->Rebin(rebin);
	TH1* ratio = (TH1*)numerator->Clone();
	ratio->Divide(denominator);
	//ratio->Divide(numerator,denominator,1.,1.,"b"); //@@ poisson errors
	ratio->SetMarkerStyle(style[j]);
	ratio->SetMarkerSize(1.2);
	ratio->SetMarkerColor(iat+1);//colour[iat]);
	ratio->SetBarOffset(0.1*i);
	//ratio->GetXaxis()->SetRangeUser(100.,550.);
	ratio->GetYaxis()->SetRangeUser(1.e-7,1.e-1);

	ratio->GetXaxis()->SetTitle("HT_{reco} [GeV]");
	ratio->GetYaxis()->SetTitle("R(#alpha_{T})");
	
 	if ( ratio->GetMaximum() > 0. &&
 	     ratio->GetMaximum() > pt_max ) {
 	  pt_max = ratio->GetMaximum();
 	}
 	if ( ratio->GetMinimum() > 0. && 
 	     ratio->GetMinimum() < pt_min ) {
 	  pt_min = ratio->GetMinimum();
 	}

	pt_ratio.push_back(ratio);

	if ( empty ) { ratio->Draw(""); empty = false; }
        else { ratio->Draw("same"); }

	//ratio->GetYaxis()->SetRangeUser(pt_min/1.1,pt_max*1.1);


	// Text for legend
	std::stringstream pt_leg;
	if ( j == 0 ) { pt_leg << "#alpha_{T} = " << at[iat]/1000. << ", GEN"; }
	else if ( j == 1 ) { pt_leg << "#alpha_{T} = " << at[iat]/1000. << ", RECO"; }
	pt_legend->AddEntry( ratio, TString(pt_leg.str()), "lep" );
	
// 	// Draw histos on canvas for RECO only
// 	if ( j == 1 ) {
// 	  reco_canvas->cd();
// 	  if ( i == 0 ) ratio->Draw("");
// 	  else ratio->Draw("same");
// 	  std::stringstream reco_leg;
// 	  reco_leg << "p_{T}^{min} = " << pt[i];
// 	reco_legend->AddEntry( ratio, TString(reco_leg.str()), "lep" );
// 	}
	
      }
    }

//       if (0) {

// 	int nbins = ratio->GetNbinsX();
// 	int bin_width = ratio->GetBinWidth(1);
      
// 	double lower = 0.;
// 	double upper = 1400.;
      
// 	int bin_lower = int( ( lower - ratio->GetBinLowEdge(1) ) / bin_width );
// 	for ( Int_t ii = bin_lower; ii < ratio->GetNbinsX()-1; ++ii ) {
// 	  if ( ratio->GetBinContent(ii) > 0. ) { 
// 	    lower = ratio->GetBinCenter(ii);
// 	    break;
// 	  }
// 	}
// 	int bin_upper = int( ( upper - ratio->GetBinLowEdge(1) ) / bin_width );
// 	for ( Int_t ii = bin_upper; ii > 0; --ii ) {
// 	  if ( ratio->GetBinContent(ii) > 0. ) { 
// 	    upper = ratio->GetBinCenter(ii);
// 	    break;
// 	  }
// 	}
// 	if (0) {
// 	  std::cout << " bin_width: " << bin_width
// 		    << " bin_lower: " << bin_lower
// 		    << " bin_upper: " << bin_upper
// 		    << " lower: " << lower
// 		    << " upper: " << upper
// 		    << std::endl;
// 	}

// 	TF1* fit = new TF1(sample[i],"expo",lower,upper); 
// 	fit->SetLineColor(colour[i]);
// 	fit->SetLineWidth(1);
// 	ratio->Fit(sample[i],"QR","same");

//       }
      
     pt_canvas->cd();
//      for ( Int_t iii = 0; iii < pt_ratio.size(); ++iii ) {
//        TH1* ratio = pt_ratio[iii];
//        if ( !ratio ) { continue; }
//        if ( ii == 0 ) { ratio->Draw(""); }
//        else { ratio->Draw("same"); }
//        ratio->GetYaxis()->SetRangeUser(pt_min/1.1,pt_max*1.1);
//      }
     pt_legend->Draw("same");
     pt_canvas->Update();
     pt_canvas->SaveAs(TString(pt_can.str()+".png"));
//       pt_canvas->SaveAs(TString(pt_can.str()+".C"));
      
    }

//   reco_canvas->cd();
//   reco_legend->Draw("same");
//   reco_canvas->Update();
//   reco_canvas->SaveAs(TString("Reco.png"));
//   reco_canvas->SaveAs(TString("Reco.C"));
  
//   TCanvas* c2 = new TCanvas("C2");
//   c2->SetLogy();
//   c2->SetFillColor(0);
//   gStyle->SetOptStat(0);
//   if ( count > 0 ) {
//     TGraph* graph = new TGraph(count,x3,r); 
//     graph->Draw("a*");
//   }

  
}
