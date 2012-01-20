#include "utility.C"
#include "TGraph.h"
#include "TMultiGraph.h"

// -----------------------------------------------------------------------------
//
void ellis() {

  time_t start = TTimeStamp().GetSec();
  
  // Arrays for nested loops
  
  const int nat = 10;
  double at[nat];
  for ( int ii = 0; ii < nat; ++ii ) { at[ii] = 0.505 + ii * 0.005; } 
  
  const int npt = 1;
  double pt[npt] = { 50. };
  //for ( int ii = 0; ii < npt; ++ii ) { pt[ii] = 100. - ii * 10.; } 
  
  const int nht = 20;
  double ht[nht];
  for ( int ii = 0; ii < nht; ++ii ) { ht[ii] = 150. + ii * 25.; }
  
  double x3_max = 1.0; 
  if ( npt > 0 && nht > 0 ) { x3_max = ( 2. * pt[npt-1]) / ( ht[0] + pt[npt-1] ); }
  x3_max = x3_max < 1.0 ? x3_max : 1.0;
  double x1_min = ( 2. - x3_max ) / 2.;
  
  const int nx = 0;
  double step = 0.;
  if ( nx > 0 ) { step = ( 1. - x1_min ) / nx; }
  step = int(1000.*step)/1000.;
  
  const int nx1 = nx+1;
  double x1[nx1];
  for ( int ii = 0; ii < nx1; ++ii ) { x1[ii] = x1_min + ii * step; }
  
  double ratio[nat][npt][nx1][nht];
  double length[nat][npt][nx1];
  
  int loop = 0;
  int nloops = nat * npt * nht * nx1;

  // Loop through bins
  for ( int iat = 0; iat < nat; ++iat ) {
    for ( int ipt = 0; ipt < npt; ++ipt ) {
      for ( int ix1 = 0; ix1 < nx1; ++ix1 ) {
	length[iat][ipt][ix1] = 0;
	for ( int iht = 0; iht < nht; ++iht ) {
	  std::cout << "Completed " 
		    << 100.*float(loop)/float(nloops) 
		    << "%..." 
		    << std::endl; loop++;

	  // Integrate over x1,x2 phase space
	  double numerator = 0.;
	  double denominator = 0.;
	  integrate( 100, 
		     at[iat], pt[ipt], x1[ix1], ht[iht], 
		     numerator, denominator, 
		     0., 1., 0., 1. );

	  // Calculate ratio
	  if ( denominator > 0. ) { 
	    ratio[iat][ipt][ix1][iht] = numerator/denominator;
	    if ( ratio[iat][ipt][ix1][iht] > 0. ) { length[iat][ipt][ix1]++; }
	  }

	}
      }
    }
  }

  // Debug
  if (true) {
    for ( int iat = 0; iat < nat; ++iat ) {
      for ( int ipt = 0; ipt < npt; ++ipt ) {
	for ( int ix1 = 0; ix1 < nx1; ++ix1 ) {
	  std::cout << " AlphaT= " << at[iat]
		    << ", Pt= " << pt[ipt]
		    << ", X1= " << x1[ix1]
		    << ", Length= " << length[iat][ipt][ix1]
		    << std::endl; 
	  for ( int iht = 0; iht < length[iat][ipt][ix1]; ++iht ) {
	    double x3 = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	    std::cout << "  HT= " << ht[iht]
		      << ", X3= " << x3
		      << ", ratio= " << ratio[iat][ipt][ix1][iht]
		      << std::endl;
	  }
	}
      }
    }
  }

  // Canvas for ratio vs HT
  if (true) {

    TCanvas* c2 = new TCanvas( "c2", "" );
    c2->SetRightMargin(0.2);
    c2->SetLogy();
    c2->cd();
    TMultiGraph* mg2 = new TMultiGraph();

    for ( Int_t iat = 0; iat < nat; iat++ ) {
      for ( Int_t ipt = 0; ipt < npt; ipt++ ) {
	for ( Int_t ix1 = 0; ix1 < nx1; ix1++ ) {
	  if ( length[iat][ipt][ix1] == 0 ) { continue; }
	  TGraph* gr = new TGraph(length[iat][ipt][ix1],ht,ratio[iat][ipt][ix1]);
	  std::stringstream ss;
	  ss << "a_{T}=" << at[iat]
	     << ", p_{T}=" << pt[ipt]
	     << ", x_{1}=" << x1[ix1];
	  mg2->Add(gr,"lp");
	  gr->SetTitle(TString(ss.str()));
	  gr->SetLineColor(2+iat);
	  gr->SetLineWidth(2);
	  gr->SetMarkerStyle(20+ix1);
	  gr->SetMarkerColor(2+iat);
	  gr->SetMarkerSize(1.5);
	}
      }
    }
    
    mg2->Draw("a");
    //mg2->GetYaxis()->SetRangeUser(1.e-5,1.e-1);
    c2->Update();
    c2->BuildLegend(0.81,0.1,0.99,0.9);
    
    // Save canvases
    c2->cd();
    c2->SaveAs("c2.C");
    c2->SaveAs("c2.png");
    
  }
  
  // Canvas for ratio vs X3
  if (false) {
    
    TCanvas* c3 = new TCanvas( "c3", "" );
    c3->SetRightMargin(0.2);
    c3->SetLogy();
    c3->cd();
    TMultiGraph* mg3 = new TMultiGraph();

    for ( Int_t iat = 0; iat < nat; iat++ ) {
      for ( Int_t ipt = 0; ipt < npt; ipt++ ) {
	for ( Int_t ix1 = 0; ix1 < nx1; ix1++ ) {
	  if ( length[iat][ipt][ix1] == 0 ) { continue; }
	  double x3_[nht];
	  for ( Int_t iht = 0; iht < nht; iht++ ) {
	    x3_[iht] = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	  }
	  TGraph* gr = new TGraph(length[iat][ipt][ix1],x3_,ratio[iat][ipt][ix1]);
	  std::stringstream ss;
	  ss << "a_{T}=" << at[iat]
	     << ", p_{T}=" << pt[ipt]
	     << ", x_{1}=" << x1[ix1];
	  mg3->Add(gr,"lp");
	  gr->SetTitle(TString(ss.str()));
	  gr->SetLineColor(2+iat);
	  gr->SetLineWidth(2);
	  gr->SetMarkerStyle(20+ix1);
	  gr->SetMarkerColor(2+iat);
	  gr->SetMarkerSize(1.5);
	}
      }
    }

    mg3->Draw("a");
    //mg3->GetYaxis()->SetRangeUser(1.e-5,1.e-1);
    c3->Update();
    c3->BuildLegend(0.81,0.1,0.99,0.9);

    // Save canvases
    c3->cd();
    c3->SaveAs("c3.C");
    c3->SaveAs("c3.png");
    
  } // canvas

  time_t stop = TTimeStamp().GetSec();
  std::cout << " Time taken: " << stop - start <<  " seconds" << std::endl;

}




