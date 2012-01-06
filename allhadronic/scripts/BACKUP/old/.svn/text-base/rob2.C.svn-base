// -----------------------------------------------------------------------------
//
void rob2() {

  time_t start = TTimeStamp().GetSec();

  bool draw = false;
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
  
  // Misc
  const int nat = 1;
  double at[nat];
  for ( int ii = 0; ii < nat; ++ii ) { at[ii] = 0.55 + ii * 0.005; } //@@ 0.505 -> 0.55

  const int npt = 1;
  double pt[npt];
  for ( int ii = 0; ii < npt; ++ii ) { pt[ii] = 50. - ii * 10.; } 

  const int nht = 10;
  double ht[nht];
  for ( int ii = 0; ii < nht; ++ii ) { ht[ii] = 150. + ii * 50.; }

  double ratio[nat][npt][nht];
  double length[nat][npt];
  
  // Loop through bins of AlphaT, MinPt and HT 
  for ( int iat = 0; iat < nat; ++iat ) {
    if (debug) std::cout << "aT bin: " << iat << " nbins: " << nat << std::endl;
    for ( int ipt = 0; ipt < npt; ++ipt ) {
      if (debug) std::cout << " pT bin: " << ipt << " nbins: " << npt << std::endl;
      length[iat][ipt] = 0;
      for ( int iht = 0; iht < nht; ++iht ) {
	if (debug) std::cout << "  HT bin: " << iht << " nbins: " << nht << std::endl;
	double x3 = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	double n = 0.;
	double d = 0.;
	
	// Labeling
	std::stringstream ss;
	ss << "AlphaT" << 100*at[iat] << "Pt" << pt[ipt] << "Ht" << ht[iht];

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
	    if ( x1 < x2 ||      // jet ordering by Pt
		 x1 + x2 > 2. || // from relation "x1 + x2 + x3 = 2"
		 x1 > 1.0 ||     // from "lost jet" and relation "xmiss = -x1 -x2"
		 x1 + x2 < 1.    // from "lost jet" and relation "xmiss = -x1 -x2"
		 ) { continue; }
	    if ( ( x1 + x2 ) < ( 2 - x3 ) ) { continue; }
	    d += val;
	    double alpha_t =  x2 / ( 2 * sqrt(x1+x2-1) );
	    if ( alpha_t > at[iat] ) n += val;
	    if (his) his->Fill( x2+xbin_centre, x1+ybin_centre, val ); 
	  }
	}
      
	// Ratio
	if ( d > 0. ) { 
	  ratio[iat][ipt][iht] = n/d;
	  if ( ratio[iat][ipt][iht] > 0. ) { 
	    length[iat][ipt]++; 
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
	  for ( Int_t i = 0; i < 10; i++ ) {
	    Double_t alpha_t = 0.5 + i*0.01;
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

  // Debug
  if (0) {
    for ( int iat = 0; iat < nat; ++iat ) {
      std::cout << " AlphaT: " << at[iat] << std::endl;
      for ( int ipt = 0; ipt < npt; ++ipt ) {
	std::cout << "  Pt: " << pt[ipt] << std::endl; 
	std::cout << "  Length: " << length[iat][ipt] << std::endl; 
	for ( int iht = 0; iht < nht; ++iht ) {
	  double x3 = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	  std::cout << "   HT: " << ht[iht]
		    << " x3: " << x3
		    << " ratio: " << ratio[iat][ipt][iht]
		    << std::endl;
	}
      }
    }
  }

  // Canvas for ratios from theory 
  TCanvas* c2 = new TCanvas( "c2", "" );
  c2->SetLogy();
  c2->cd();
  TMultiGraph* mg2 = new TMultiGraph();
  for ( Int_t iat = 0; iat < nat; iat++ ) {
    for ( Int_t ipt = 0; ipt < npt; ipt++ ) {
      if ( length[iat][ipt] == 0 ) { continue; }
      TGraph* gr = new TGraph(length[iat][ipt],ht,ratio[iat][ipt]);
      std::stringstream ss;
      ss << "AlphaT=" << at[iat] << ", Pt=" << pt[ipt];
      mg2->Add(gr,"lp");
      gr->SetTitle(TString(ss.str()));
      gr->SetLineColor(2+iat);
      gr->SetLineWidth(2);
      gr->SetMarkerStyle(20+ipt);
      gr->SetMarkerColor(2+iat);
      gr->SetMarkerSize(1.5);
    }
  }
  mg2->Draw("a");
  //mg2->GetYaxis()->SetRangeUser(1.e-5,1.e-1);
  c2->Update();
  c2->BuildLegend(0.8,0.1,0.99,0.9);
  
  // Save canvases
  c2->cd();
  c2->SaveAs("c2.C");
  c2->SaveAs("c2.png");

  // Canvas for ratios from theory 
  TCanvas* c3 = new TCanvas( "c3", "" );
  c3->SetLogy();
  c3->cd();
  TMultiGraph* mg3 = new TMultiGraph();
  for ( Int_t iat = 0; iat < nat; iat++ ) {
    for ( Int_t ipt = 0; ipt < npt; ipt++ ) {
      if ( length[iat][ipt] == 0 ) { continue; }
      double x3_[nht];
      for ( Int_t iht = 0; iht < nht; iht++ ) {
	x3_[iht] = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
      }
      TGraph* gr = new TGraph(length[iat][ipt],x3_,ratio[iat][ipt]);
      std::stringstream ss;
      ss << "AlphaT=" << at[iat] << ", Pt=" << pt[ipt];
      mg3->Add(gr,"lp");
      gr->SetTitle(TString(ss.str()));
      gr->SetLineColor(2+iat);
      gr->SetLineWidth(2);
      gr->SetMarkerStyle(20+ipt);
      gr->SetMarkerColor(2+iat);
      gr->SetMarkerSize(1.5);
    }
  }
  mg3->Draw("a");
  //mg3->GetYaxis()->SetRangeUser(1.e-5,1.e-1);
  c3->Update();
  c3->BuildLegend(0.8,0.1,0.99,0.9);

  time_t stop = TTimeStamp().GetSec();
  std::cout << " Time taken: " << stop - start <<  " seconds" << std::endl;

}





//   // AlphaT
//   {
//     TCanvas* c1 = new TCanvas( "AlphaT", "" );
//     c1->SetGridx(1);
//     c1->SetGridy(1);
//     TH2D* his = new TH2D("AlphaT","",xbins,xmin,xmax,ybins,ymin,ymax);
//     for ( int xbin = 0; xbin < xbins; ++xbin ) { 
//       for ( int ybin = 0; ybin < ybins; ++ybin ) { 
//   	double x2 = ( ( xmax - xmin ) / xbins ) * xbin + xmin;
//   	double x1 = ( ( ymax - ymin ) / ybins ) * ybin + ymin;
//   	double val = 2*x2 / ( 2. * sqrt( 2*x1 + 2*x2 - 1 ) ); 
//   	//if ( x1 < x2 ) { continue; }
//   	if ( ( x1 + x2 ) > 2. ) { continue; }
//   	if ( ( x1 + x2 ) < 0.5 ) { continue; }
//   	if ( val > 0.6 ) { continue; }
//   	his->Fill( x2, x1, val );
//       }
//     }
//     gStyle->SetPalette(1);
//     his->SetMaximum( his->GetMaximum() );
//     his->SetMinimum( his->GetMinimum(1.e-12) );
//     his->Draw("COLZ");
//   }
  
//   // Contours for mht = 5,10...
//   int n = 10;
//   for ( int i = 0; i < n; ++i ) {
//     TF2* c = new TF2( "Contour", "(x*x+y*y)/((1-x)*(1-y))", 0., 0.5, 0., 0.5 );
//     c->SetContour(1);
//     double pt1 = 50.;
//     double pt2 = 50.;
//     double mht = 5 + i * 5.;
//     double x1 = pt1 / ( pt1 + pt2 + mht );
//     double x2 = pt2 / ( pt1 + pt2 + mht );
//     double sigma =  
//       ( ( x1 * x1 ) + ( x2 * x2 ) ) 
//       / ( ( 1 - x1 ) * ( 1 - x2 ) );
//     std::cout << " i: " << i
//   	      << " pt1: " << pt1
//   	      << " pt2: " << pt2
//   	      << " mht: " << mht 
//   	      << " x1: " << x1
//   	      << " x2: " << x2
//   	      << " sigma: " << sigma
//   	      << std::endl;
//     c->SetContourLevel(0,sigma);
//     c->SetNpx(100);
//     c->SetNpy(100);
//     c->Draw("Same");
//   }
  
//   // Contours for alpha_t = 0.5,0.51...
//   if (0) {
//     TF2* c = new TF2( "AlphaT", "(2*x)/(2*sqrt(2*x+2*y-1))", 0., 0.5, 0., 0.5 );
//     int m = 5;
//     double array[5];
//     for ( int i = 0; i < 5; ++i ) { array[i] = 0.5 + i * 0.01; }
//     c->SetContour(5,array);
//     c->SetNpx(100);
//     c->SetNpy(100);
//     c->Draw("Same");
//   }

