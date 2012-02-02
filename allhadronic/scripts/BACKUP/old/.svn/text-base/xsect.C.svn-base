#include "TGraph.h"

// -----------------------------------------------------------------------------
//
void xsect() {

  int xbins = 100;
  int ybins = 100;

  double xmax = 0.5;
  double xmin = 0.0;
  double xrange = xmax - xmin;
  xmax += xrange / xbins / 2;
  xmin -= xrange / xbins / 2;
  xbins++;

  double ymax = 0.5;
  double ymin = 0.0;
  double yrange = ymax - ymin;
  ymax += yrange / ybins / 2;
  ymin -= yrange / ybins / 2;
  ybins++;

  // Examples values of pt1, pt2, mht, x1, x2, x3, sigma and alpha_t

  double pt1 = 50.;
  double pt2 = 50.;
  double mht = 50.;
  double x1 = ( 2. * pt1 ) / ( pt1 + pt2 + mht );
  double x2 = ( 2. * pt2 ) / ( pt1 + pt2 + mht );
  double x3 = 2 - x1 - x2;
  double sigma =  ( x1*x1 + x2*x2 ) / ( (1-x1) * (1-x2) );
  double alpha_t =  x2 / ( 2 * sqrt(x1+x2-1) );
  std::cout << " pt1: " << pt1
	    << " pt2: " << pt2
	    << " mht: " << mht 
	    << " x1: " << x1
	    << " x2: " << x2
	    << " x3: " << x3
	    << " sigma: " << sigma
	    << " alpha_t: " << alpha_t
	    << std::endl;

  // Cross section
  {
    TCanvas* canvas = new TCanvas( "Contours", "" );
    canvas->SetGridx(1);
    canvas->SetGridy(1);
    TH2D* his = new TH2D("Contours","",xbins,xmin,xmax,ybins,ymin,ymax);
    for ( int xbin = 0; xbin < xbins; ++xbin ) { 
      for ( int ybin = 0; ybin < ybins; ++ybin ) { 
	double x2 = ( ( xmax - xmin ) / xbins ) * xbin + xmin;
	double x1 = ( ( ymax - ymin ) / ybins ) * ybin + ymin;
	double val = ( x1*x1 + x2*x2 ) / ( ( 1 - x1 ) * ( 1 - x2 ) ); 
	if ( x1 < x2 ) { continue; }
	if ( ( x1 + x2 ) > 2. ) { continue; }
	if ( val < x3 ) { continue; }
	his->Fill( x2, x1, val );
      }
    }
    gStyle->SetPalette(1);
    his->SetMaximum( his->GetMaximum() );
    his->SetMinimum( his->GetMinimum(1.e-12) );
    his->Draw("COLZ");
  }

  // AlphaT
  {
    TCanvas* canvas = new TCanvas( "AlphaT", "" );
    canvas->SetGridx(1);
    canvas->SetGridy(1);
    TH2D* his = new TH2D("AlphaT","",xbins,xmin,xmax,ybins,ymin,ymax);
    for ( int xbin = 0; xbin < xbins; ++xbin ) { 
      for ( int ybin = 0; ybin < ybins; ++ybin ) { 
  	double x2 = ( ( xmax - xmin ) / xbins ) * xbin + xmin;
  	double x1 = ( ( ymax - ymin ) / ybins ) * ybin + ymin;
  	double val = 2*x2 / ( 2. * sqrt( 2*x1 + 2*x2 - 1 ) ); 
  	//if ( x1 < x2 ) { continue; }
  	if ( ( x1 + x2 ) > 2. ) { continue; }
  	if ( ( x1 + x2 ) < 0.5 ) { continue; }
  	if ( val > 0.6 ) { continue; }
  	his->Fill( x2, x1, val );
      }
    }
    gStyle->SetPalette(1);
    his->SetMaximum( his->GetMaximum() );
    his->SetMinimum( his->GetMinimum(1.e-12) );
    his->Draw("COLZ");
  }
  
  // Contours for mht = 5,10...
  int n = 10;
  for ( int i = 0; i < n; ++i ) {
    TF2* c = new TF2( "Contour", "(x*x+y*y)/((1-x)*(1-y))", 0., 0.5, 0., 0.5 );
    c->SetContour(1);
    double pt1 = 50.;
    double pt2 = 50.;
    double mht = 5 + i * 5.;
    double x1 = pt1 / ( pt1 + pt2 + mht );
    double x2 = pt2 / ( pt1 + pt2 + mht );
    double sigma =  
      ( ( x1 * x1 ) + ( x2 * x2 ) ) 
      / ( ( 1 - x1 ) * ( 1 - x2 ) );
    std::cout << " i: " << i
  	      << " pt1: " << pt1
  	      << " pt2: " << pt2
  	      << " mht: " << mht 
  	      << " x1: " << x1
  	      << " x2: " << x2
  	      << " sigma: " << sigma
  	      << std::endl;
    c->SetContourLevel(0,sigma);
    c->SetNpx(100);
    c->SetNpy(100);
    c->Draw("Same");
  }
  
  // Contours for alpha_t = 0.5,0.51...
  if (0) {
    TF2* c = new TF2( "AlphaT", "(2*x)/(2*sqrt(2*x+2*y-1))", 0., 0.5, 0., 0.5 );
    int m = 5;
    double array[5];
    for ( int i = 0; i < 5; ++i ) { array[i] = 0.5 + i * 0.01; }
    c->SetContour(5,array);
    c->SetNpx(100);
    c->SetNpy(100);
    c->Draw("Same");
  }

  for ( Int_t i = 0; i < 1; i++ ) {
    Double_t alpha_t = 0.55 + i*0.01;
    const Int_t n = 100;
    Double_t x2[n];
    Double_t x1[n];
    for ( Int_t j = 0; j < 100; j++ ) {
      x2[i] = i*0.005;
      Double_t temp = ( x2[i] - 2. * alpha_t * alpha_t ) / ( 2. * alpha_t );
      x1[i] = temp * temp + 1 - alpha_t * alpha_t;
    }
    TGraph* gr = new TGraph(n,x2,x1);
    gr->Draw("ap*l");
  }
  
}
