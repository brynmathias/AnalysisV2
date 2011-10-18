#include "utility.C"
#include "TGraph.h"
#include "TMultiGraph.h"

// -----------------------------------------------------------------------------
//
void dalitz() {
  
  time_t start = TTimeStamp().GetSec();

  bool draw = true;
  bool debug = true;
  
  // Binning
  int xbins = 100;
  int ybins = 100;
  double xmax = 1.0;
  double xmin = 0.0;
  double ymax = 1.0;
  double ymin = 0.0;
  double xbin_centre = ( ( xmax - xmin ) / xbins ) / 2.;
  double ybin_centre = ( ( ymax - ymin ) / ybins ) / 2.;
  
  // Arrays for nested loops
  
  const int nat = 1;
  double at[nat];
  for ( int ii = 0; ii < nat; ++ii ) { at[ii] = 0.55 + ii * 0.001; } 
  
  const int npt = 1;
  double pt[npt] = { 50. };
  
  const int nht = 1;
  double ht[nht];
  for ( int ii = 0; ii < nht; ++ii ) { ht[ii] = 150. + ii * 50.; }
  
  double x3_max = 1.0; 
  if ( npt > 0 && nht > 0 ) { x3_max = ( 2. * pt[npt-1]) / ( ht[0] + pt[npt-1] ); }
  x3_max = x3_max < 1.0 ? x3_max : 1.0;
  double x1_min = ( 2. - x3_max ) / 2.;
  
  const int nx = 3;
  double step = ( 1. - x1_min ) / nx;
  
  step = int(1000.*step)/1000.;
  
  const int nx1 = nx+1;
  double x1_cut[nx1];
  for ( int ii = 0; ii < nx1; ++ii ) { x1_cut[ii] = x1_min + ii * step; }
  
  int loop = 0;
  int nloops = npt * nht * nx1;
  
  // Loop through bins 
  for ( int ipt = 0; ipt < npt; ++ipt ) {
    for ( int ix1 = 0; ix1 < nx1; ++ix1 ) {
      for ( int iht = 0; iht < nht; ++iht ) {
	std::cout << "Completed " 
		  << 100.*float(loop)/float(nloops) 
		  << "%..." 
		  << std::endl; 
	loop++;
	  
	double x3 = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	
	// Labeling
	std::stringstream ss;
	ss << "pT" << int(pt[ipt])
	   << "x" << int(1000*x1_cut[ix1])
	   << "HT" << int(ht[iht]);
	  
	// New canvas for plots
	TCanvas* c1 = 0;
	if (draw) c1 = new TCanvas( TString("Canvas"+ss.str()), "" );
	  
	// Pad for cross-section plot
	TPad* pad = 0;
	if (draw) pad = new TPad(TString("Pad"+ss.str()),"",0.,0.,1.,1.);
	if (pad) {
	  pad->SetGrid();
	  pad->Draw();
	  pad->cd();
	  pad->SetLogz();
	}
	TH1F* hr = 0;
	if (draw) hr = pad->DrawFrame(0.,0.,1.,1.);

	// Histo title
	if (hr) {
	  std::stringstream sss;
	  sss << "p_{T}=" << pt[ipt]
	      << ", x_{1}=" << x1_cut[ix1]
	      << ", HT=" << ht[iht];
	  hr->SetTitle( sss.str().c_str() );
	  hr->GetXaxis()->SetTitle( "x_{2}" );
	  hr->GetYaxis()->SetTitle( "x_{1}" );
	}
	  
	// Create 2D cross-section plot
	TH2D* his = 0;
	if (draw) his = new TH2D(TString("Histo"+ss.str()),"",
				 xbins,xmin,xmax,
				 ybins,ymin,ymax);
	  
	// Fill 2D cross-section plot
	for ( int xbin = 0; xbin < xbins; ++xbin ) { 
	  for ( int ybin = 0; ybin < ybins; ++ybin ) { 
	    double x2 = ( ( xmax - xmin ) / xbins ) * xbin + xmin;
	    double x1 = ( ( ymax - ymin ) / ybins ) * ybin + ymin;
	    double val = ( x1*x1 + x2*x2 ) / ( ( 1 - x1 ) * ( 1 - x2 ) ); 
	      
	    if ( !constrainPhaseSpace( x1, x2, x3 ) ) { continue; }
	      
	    if ( x1 < x1_cut[ix1] ) { continue; }
	      
	    double alpha_t =  x2 / ( 2 * sqrt(x1+x2-1) );
	    if (his) his->Fill( x2+xbin_centre, x1+ybin_centre, val ); 
	  }
	}
	  
	// Draw 2D cross-section plot
	gStyle->SetPalette(1);
	if (his) {
	  his->SetMaximum( his->GetMaximum() );
	  his->SetMinimum( his->GetMinimum(1.e-12) );
	  his->Draw("COLZsame");
	}

	// Pad for AlphaT contours
	if (c1) c1->cd();
	TPad* overlay = 0;
	if (draw) overlay = new TPad(TString("Overlay"+ss.str()),"",0.,0.,1.,1.);
	if (overlay) {
	  overlay->SetFillStyle(4000);
	  overlay->SetFillColor(0);
	  overlay->SetFrameFillStyle(4000);
	  overlay->Draw();
	  overlay->cd();
	}
	TH1F* hframe = 0;
	if (draw) overlay->DrawFrame(pad->GetUxmin(),
				     pad->GetUymin(),
				     pad->GetUxmax(),
				     pad->GetUymax());
	  
	// Graphs of AlphaT contours
	TMultiGraph* mg = 0;
	if (draw) {
	  mg = new TMultiGraph();
	  for ( Int_t iat = 0; iat < nat; iat++ ) {
	    Double_t alpha_t = at[iat];
	    const Int_t n_ = 100;
	    Double_t x1_[n_];
	    Double_t x2_[n_];
	    for ( Int_t j = 0; j < 100; j++ ) {
	      x2_[j] = j*0.01;
	      Double_t temp = ( x2_[j] - 2. * alpha_t * alpha_t ) / ( 2. * alpha_t );
	      x1_[j] = temp * temp + 1 - alpha_t * alpha_t;
	    }
	    TGraph* gr = new TGraph(n_,x2_,x1_);
	    mg->Add(gr,"l");
	  }
	  mg->Draw();
	}
	  
	if (c1) c1->cd();
	if (c1) c1->SaveAs(TString(ss.str()+".png"));
	  
      }
    }
  }

}
