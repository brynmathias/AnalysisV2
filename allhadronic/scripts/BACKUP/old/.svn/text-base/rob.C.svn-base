// -----------------------------------------------------------------------------
//
void rob() {

  // Binning
  
  int xbins = 100;
  int ybins = 100;
  
  double xmax = 1.0;
  double xmin = 0.0;
//   double xrange = xmax - xmin;
//   xmax += xrange / xbins / 2;
//   xmin -= xrange / xbins / 2;
//   //xbins++;
  
  double ymax = 1.0;
  double ymin = 0.0;
//   double yrange = ymax - ymin;
//   ymax += yrange / ybins / 2;
//   ymin -= yrange / ybins / 2;
//   //ybins++;

  std::cout << " Binning: "
	    << " xbins: " << xbins
	    << " ybins: " << xbins
	    << " xmin: " << xmin
	    << " xmax: " << xmax
	    << " ymin: " << ymin
	    << " ymax: " << ymax
	    << std::endl;
  
  // Examples values of pt1, pt2, mht, x1, x2, x3, sigma and alpha_t
//   double pt1 = 50.;
//   double pt2 = 50.;
//   double mht = 50.;
//   double x1 = ( 2. * pt1 ) / ( pt1 + pt2 + mht );
//   double x2 = ( 2. * pt2 ) / ( pt1 + pt2 + mht );
//   double x3 = 2 - x1 - x2;
//   double sigma =  ( x1*x1 + x2*x2 ) / ( (1-x1) * (1-x2) );
//   double alpha_t =  x2 / ( 2 * sqrt(x1+x2-1) );
//   std::cout << " pt1: " << pt1
// 	    << " pt2: " << pt2
// 	    << " mht: " << mht 
// 	    << " x1: " << x1
// 	    << " x2: " << x2
// 	    << " x3: " << x3
// 	    << " sigma: " << sigma
// 	    << " alpha_t: " << alpha_t
// 	    << std::endl;
  
  // Cross section
  TCanvas* c1 = new TCanvas( "Contours", "" );
  //c1->SetGridx(1);
  //c1->SetGridy(1);

  TPad* pad = new TPad("pad","",0.,0.,1.,1.);
  pad->SetGrid();
  pad->Draw();
  pad->cd();
  pad->SetLogz(1);

  TH1F* hr = pad->DrawFrame(0.,0.,1.,1.);
  
  const int nx = 3;
  const int ny = 10;
  double pt[nx] = { 30., 50., 100. };
  double ht[ny];
  for ( int ii = 0; ii < ny; ++ii ) { ht[ii] = 150. + ii * 50.; }
  double ratio[nx][ny];
  
  double xbin_centre = ( ( xmax - xmin ) / xbins ) / 2.;
  double ybin_centre = ( ( ymax - ymin ) / ybins ) / 2.;
  TH2D* his = new TH2D("Contours","",xbins,xmin,xmax,ybins,ymin,ymax);
  for ( int ii = 0; ii < nx; ++ii ) {
    for ( int jj = 0; jj < ny; ++jj ) {
      double x3 = ( 2. * pt[ii] ) / ( ht[jj] + pt[ii] );
      double n = 0.;
      double d = 0.;
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
	  if ( alpha_t > 0.5 ) n+= val;
	  if ( ii == 2 && jj == 9 ) { his->Fill( x2+xbin_centre, x1+ybin_centre, val ); }
	}
      }
      double r = 0.;
      if ( d > 0. ) { r = n/d; }
      ratio[ii][jj] = r;
      std::cout << " Pt: " << pt[ii]
		<< " ht: " << ht[jj]
		<< " x3: " << x3
		<< " r: " << r
		<< " n: " << n
		<< " d: " << d
		<< std::endl;
    }
  }
  gStyle->SetPalette(1);
  his->SetMaximum( his->GetMaximum() );
  his->SetMinimum( his->GetMinimum(1.e-12) );
  his->Draw("COLZsame");
  

//   c1->cd();
//   TPad* overlay = new TPad("overlay","",0.,0.,1.,1.);
//   overlay->SetFillStyle(4000);
//   overlay->SetFillColor(0);
//   overlay->SetFrameFillStyle(4000);
//   overlay->Draw();
//   overlay->cd();

//   Double_t pxmin = pad->GetUxmin();
//   Double_t pymin = pad->GetUymin();
//   Double_t pxmax = pad->GetUxmax();
//   Double_t pymax = pad->GetUymax();
//   TH1F* hframe = overlay->DrawFrame(pxmin,pymin,pxmax,pymax);

//   TMultiGraph* mg = new TMultiGraph();
//   for ( Int_t i = 0; i < 10; i++ ) {
//     Double_t alpha_t = 0.5 + i*0.01;
//     const Int_t n_ = 100;
//     Double_t x1_[n_];
//     Double_t x2_[n_];
//     for ( Int_t j = 0; j < 100; j++ ) {
//       x2_[j] = j*0.01;
//       Double_t temp = ( x2_[j] - 2. * alpha_t * alpha_t ) / ( 2. * alpha_t );
//       x1_[j] = temp * temp + 1 - alpha_t * alpha_t;
//     }
//     TGraph* gr = new TGraph(n_,x2_,x1_);
//     mg->Add(gr,"l");
//   }
//   mg->Draw();


//   TCanvas* c2 = new TCanvas( "Contours1", "" );
//   c2->cd();
//   TMultiGraph* mg2 = new TMultiGraph();
//   for ( Int_t ii = 0; ii < 3; ii++ ) {
//     TGraph* gr = new TGraph(ny,ht,ratio[ii]);
//     mg2->Add(gr,"l");
//   }
//   mg2->Draw("a");
  
//   c1->cd();
//   c1->SaveAs("c1.png");
//   c2->cd();
//   c2->SaveAs("c2.png");

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

