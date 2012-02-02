#include "utility.C"

// -----------------------------------------------------------------------------
//
void talk() {
  
  time_t start = TTimeStamp().GetSec();

  bool draw = true;
  bool debug = true;
  
  // Binning
  int xbins = 100;
  int ybins = 100;
  double xmin = 0.0;
  double xmax = 1.0;
  double ymin = 0.0;
  double ymax = 1.0;
  double xbin_centre = ( ( xmax - xmin ) / xbins ) / 2.;
  double ybin_centre = ( ( ymax - ymin ) / ybins ) / 2.;
  
  // AlphaT values
  const int nat = 1;
  double at[nat];
  for ( int ii = 0; ii < nat; ++ii ) { at[ii] = 0.55 + ii * 0.001; } 
  
  // HT regions
  const int nht = 3;
  double ht_min[nht] = { 250., 300., 350. };

  // Jet pT thresholds
  double pt1_min[nht] = { 71.4, 85.7, 100. };
  double pt2_min[nht] = { 71.4, 85.7, 100. };
  double pt3_min[nht] = { 35.7, 42.9., 50. };

  // x fractions
  double x1_min[nht];
  double x2_min[nht];
  double x3_max[nht];
  for ( int ii = 0; ii < nht; ++ii ) { x1_min[ii] = ( 2. * pt1_min[ii]) / ( ht_min[ii] + pt3_min[ii] ); }
  for ( int ii = 0; ii < nht; ++ii ) { x2_min[ii] = ( 2. * pt2_min[ii]) / ( ht_min[ii] + pt3_min[ii] ); }
  for ( int ii = 0; ii < nht; ++ii ) { x3_max[ii] = ( 2. * pt3_min[ii]) / ( ht_min[ii] + pt3_min[ii] ); }
  
  // Loop through bins 
  int loop = 0;
  int nloops = nht;
  for ( int iht = 0; iht < nht; ++iht ) {
    std::cout << "Completed " 
	      << 100.*float(loop)/float(nloops) 
	      << "%..." 
	      << std::endl; 
    loop++;
    
    // Labeling
    std::stringstream ss;
    ss << "HT" << int(ht_min[iht]);
	  
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
      sss << "H_{T}=" << ht_min[iht]
	  << "(p_{T1},p_{T2},p_{T3})=" 
	  << pt1_min[iht] << ","
	  << pt2_min[iht] << ","
	  << pt3_min[iht] << ")"
	  << ", (x_{1},x_{2},x_{3})=" 
	  << x1_min[iht] << ","
	  << x2_min[iht] << ","
	  << x3_max[iht] << ")";
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
	      
	if ( !constrain( x1, x2, x3 ) ) { continue; }
	      
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
