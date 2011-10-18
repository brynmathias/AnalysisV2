#include "TH2D.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TF1.h"
#include "TProfile.h"
#include "TRandom3.h"
#include "TStyle.h"
#include "TTimeStamp.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include "Math/LorentzVector.h"
#include "Math/PtEtaPhiM4D.h"
#include "Math/PxPyPzM4D.h"
#include "Math/QuantFunc.h"

// -----------------------------------------------------------------------------
// 
void set_plot_style() {
  
  const Int_t NRGBs = 5;
  const Int_t NCont = 255;
  
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };

  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);
  
}

// -----------------------------------------------------------------------------
// 
bool DEBUG = true;
int MEFF_BINNING = 0; // 0 = test, 1 = 3 bins, 2 = 11 bins, 3 = 6 bins

// -----------------------------------------------------------------------------
// 1 = AlphaT, 2 = 3-jet cross-section, 3 = ...
int ALGO_TYPE = 2; 

// -----------------------------------------------------------------------------
// 
typedef std::vector<int> IntV;
typedef std::vector<double> DoubleV;
typedef std::vector<DoubleV> DoubleVV;
typedef ROOT::Math::LorentzVector< ROOT::Math::PtEtaPhiE4D<double> > PtEtaPhiM;
typedef ROOT::Math::LorentzVector< ROOT::Math::PxPyPzM4D<double> > PxPyPzM;

// -----------------------------------------------------------------------------
// 
TRandom3 rndm( TTimeStamp().GetNanoSec() );

// -----------------------------------------------------------------------------
// 
double dr( double x, int decimal_places ) {
  if ( decimal_places < 0 ) { return x; }
  if ( x == 0. ) { return 0.; }
  return floor(x*pow(10.,decimal_places)+0.5)/pow(10.,decimal_places); 
}

// -----------------------------------------------------------------------------
// 
double xSect( double x1, double x2 ) {
  return ( x1*x1 + x2*x2 ) / ( ( 1 - x1 ) * ( 1 - x2 ) ); 
}

// -----------------------------------------------------------------------------
// 
double xSect( double x ) { return xSect(x,x); }

// -----------------------------------------------------------------------------
// 
double cutAlgo( const double x1, 
		const double x2, 
		const int type ) {
  double val = -1.;
  if      ( type == 1 ) { val = x1+x2-1 > 0. ? x2 / ( 2. * sqrt( x1 + x2 - 1 ) ) : -1.; }
  else if ( type == 2 ) { val = xSect(x1,x2); }
  return val;
}

// -----------------------------------------------------------------------------
// 
double cutAlgoInverse( const double val,
		       const double x2, 
		       const int type ) {
  double x1 = -1.;
  if ( type == 1 ) { 
    x1 = pow((x2-2.*pow(val,2))/(2.*val),2) + 1 - pow(val,2); 
  } else if ( type == 2 ) { 
    /*
      s = ( ( x1^2 + x2^2 ) / ( (1-x1) * (1-x2) ); 
      is solved in quadratic form:
      ax1^2 + bx1 + c = 0
      where:
      a = 1
      b = s(1-x2)
      c = x2^2 + x2*s - s
      and: 
      x1 = ( -b +/- sqrt( b^2 - 4ac ) ) / 2a
    */
    double a = 1.;
    double b = val * ( 1 - x2 );
    double c = x2*x2 + x2*val - val;
    double d = b*b - 4*a*c;
    return ( d >= 0. ? ( -1.*b + sqrt(d) ) / ( 2.*a ) : -1. );
  }
  return x1;
}

// -----------------------------------------------------------------------------
// 
struct PSet {
  // Cut variable and values
  int cutType;
  DoubleV cutValues;
  // Normalisation
  double norm;
  // Histo binning
  int nbins;
  double min;
  double max;
  double width;
  // Meff bins
  int nmeff;
  double meff_min;
  double meff_max;
  double meff_width;
  DoubleV meff_bins;
  // Default scale and thresholds  
  double meff_default;
  double pt1_default;
  double pt2_default;
  double pt3_default;
  double x1_default;
  double x2_default;
  double x3_default;
  // Scaled thresholds
  bool scale;
  DoubleV pt1_bins;
  DoubleV pt2_bins;
  DoubleV pt3_bins;
  DoubleV x1_bins;
  DoubleV x2_bins;
  DoubleV x3_bins;
  // Completion
  int loop;
  int nloop;
};

// -----------------------------------------------------------------------------
// 
void defaultPSet( PSet& ps ) {
  // Cut variable
  ps.cutType = ALGO_TYPE;
  if ( ps.cutType == 1 ) { 
    for ( int ii = 0; ii < 1; ++ii ) { ps.cutValues.push_back( 0.5 + (ii+1) * 0.01 ); } 
  } else if ( ps.cutType == 2 ) { 
    for ( int ii = 0; ii < 1; ++ii ) { ps.cutValues.push_back( cutAlgo(0.9+ii*0.05,0.9+ii*0.05,2) ); } 
  }
  // Histo binning
  ps.norm = 2.;
  ps.nbins = 200;
  ps.min = 0.;
  ps.max = 0.5*ps.norm;
  ps.width = ( ps.max - ps.min ) / ( 1. * ps.nbins );
  // Meff binning
  if ( MEFF_BINNING == 1 ) { 
    ps.nmeff = 3; 
    ps.meff_min = 400.; 
    ps.meff_max = 550.; 
    ps.meff_width = 50.; 
  } else if ( MEFF_BINNING == 2 ) { 
    ps.nmeff = 11;
    ps.meff_min = 400.;
    ps.meff_max = 510.;
    ps.meff_width = ( ps.meff_max - ps.meff_min ) / ( 1. * ps.nmeff );
  } else if ( MEFF_BINNING == 3 ) { 
    ps.nmeff = 6;
    ps.meff_min = 250.;
    ps.meff_max = 550.;
    ps.meff_width = ( ps.meff_max - ps.meff_min ) / ( 1. * ps.nmeff );
  } else {
    ps.nmeff = 1; 
    ps.meff_min = 400.; 
    ps.meff_max = 450.; 
    ps.meff_width = 50.; 
  }
  ps.meff_bins.clear();
  for ( int imeff = 0; imeff < ps.nmeff; ++imeff ) { 
    ps.meff_bins.push_back( ps.meff_min + imeff * ps.meff_width ); 
  }
  // Scale and jet pT threshold defaults
  ps.norm = 2.;
  if ( MEFF_BINNING == 1 || MEFF_BINNING == 2 ) { ps.meff_default = 500.; }
  else { ps.meff_default = 400.; }
  ps.pt1_default = 100.;
  ps.pt2_default = 100.;
  ps.pt3_default = 50.;
  ps.x1_default = ps.norm * ps.pt1_default / ps.meff_default;
  ps.x2_default = ps.norm * ps.pt2_default / ps.meff_default;
  ps.x3_default = ps.norm * ps.pt3_default / ps.meff_default;
  ps.scale = true;
  ps.pt1_bins.clear();
  ps.pt2_bins.clear();
  ps.pt3_bins.clear();
  ps.x1_bins.clear();
  ps.x2_bins.clear();
  ps.x3_bins.clear();
  for ( int imeff = 0; imeff < ps.nmeff; ++imeff ) { 
    double pt1 = ps.pt1_default * ps.meff_bins[imeff] / ps.meff_default;
    double pt2 = ps.pt2_default * ps.meff_bins[imeff] / ps.meff_default;
    double pt3 = ps.pt3_default * ps.meff_bins[imeff] / ps.meff_default;
    ps.pt1_bins.push_back( ps.scale ? pt1 : ps.pt1_default );
    ps.pt2_bins.push_back( ps.scale ? pt2 : ps.pt2_default );
    ps.pt3_bins.push_back( ps.scale ? pt3 : ps.pt3_default );
    ps.x1_bins.push_back( ps.norm * ps.pt1_bins[imeff] / ps.meff_bins[imeff] );
    ps.x2_bins.push_back( ps.norm * ps.pt2_bins[imeff] / ps.meff_bins[imeff] );
    ps.x3_bins.push_back( ps.norm * ps.pt3_bins[imeff] / ps.meff_bins[imeff] );
  }
//   // Completion
//   ps.loop = 0;
//   ps.nloop = ps.nmeff;
}

// -----------------------------------------------------------------------------
// 
void printPSet( const PSet& ps, std::stringstream& ss ) {
  ss << "[printPSet] Printing configuration..." 
     << std::endl
     << " Histo:    "
     << " norm=" << ps.norm
     << ", nbins=" << ps.nbins
     << ", min=" << ps.min
     << ", max=" << ps.max
     << std::endl
     << " Meff:     "
     << " nbins=" << ps.nmeff
     << ", min=" << ps.meff_min
     << ", max=" << ps.meff_max
     << ", (bin,Meff)=";
  for ( int imeff = 0; imeff < ps.nmeff; ++imeff ) { 
    if ( imeff > 3 && ps.nmeff - imeff > 1 ) { ss << "."; }
    else { ss << "(" << imeff << "," << ps.meff_bins[imeff] << "), "; }
  }
  ss << std::endl
     << " Defaults: "
     << " Meff=" << ps.meff_default
     << ", pT1 =" << ps.pt1_default
     << ", pT2=" << ps.pt2_default
     << ", pT3=" << ps.pt3_default
     << ", scale? " << ( ps.scale ? "True" : "False" ) 
     << std::endl
     << " pT thresh: "
     << "(bin,pT1,pT2,pT3)=";
  for ( int imeff = 0; imeff < ps.nmeff; ++imeff ) { 
    if ( imeff > 3 && ps.nmeff - imeff > 1 ) { ss << "."; }
    else { 
      ss << "(" 
	 << imeff << ","
	 << dr(ps.pt1_bins[imeff],1) << ","
	 << dr(ps.pt2_bins[imeff],1) << ","
	 << dr(ps.pt3_bins[imeff],1) 
	 << "), ";
    }
  }
  ss << std::endl
     << " xi thresh: "
     << "(bin,x1,x2,x3)=";
  for ( int imeff = 0; imeff < ps.nmeff; ++imeff ) { 
    if ( imeff > 3 && ps.nmeff - imeff > 1 ) { ss << "."; }
    else { 
      ss << "(" 
	 << imeff << ","
	 << dr(ps.x1_bins[imeff],3) << ","
	 << dr(ps.x2_bins[imeff],3) << ","
	 << dr(ps.x3_bins[imeff],3) 
	 << "), ";
    }
  }
  ss << std::endl;
}

// -----------------------------------------------------------------------------
// 
double response( double pt ) {
  /*
    sigma(pT)/pT = sqrt( sgn(N) * (N/pT)^2 + S^2 * pT^{m-1} + C^2 )
  */
  double width = sqrt( 1. * 4.8 * pow((4.8/pt),2) + pow(0.54,2) * pow(pt,-0.69) + 0. ); 
  return rndm.Gaus(pt,pt*width);
}

// -----------------------------------------------------------------------------
// 
TCanvas* responseProfile() {

  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  int pt_bins = 100;
  double pt_min = 0.;
  double pt_max = 1000.;

  int resp_bins = 100;
  double resp_min = 0.;
  double resp_max = 2.;
  
  TCanvas* c1 = new TCanvas("ResponseCanvas","Response");
  c1->SetLogz();
  c1->SetLogx();
  //c1->SetRightMargin(2.5);

  TProfile* prof = new TProfile("ResponseProfile",
				"",
				pt_bins,
				pt_min,
				pt_max,
				resp_min,
				resp_max);
  prof->Sumw2();
  prof->SetMarkerStyle(21);
  prof->SetMarkerSize(0.5);

  TH2D* his2d = new TH2D("Response2D",
			 "Jet p_{T} resolution;p_{T}^{reco} [GeV];p_{T}^{reco}/p_{T}^{truth}",
			 pt_bins,
			 pt_min,
			 pt_max,
			 resp_bins,
			 resp_min,
			 resp_max);
  //his2d->SetTitleOffset(0);
  
  for ( int ii = 0; ii < pt_bins; ++ii ) {
    double pt = pt_min + (ii+1) * (pt_max-pt_min)/pt_bins;
    for ( int jj = 0; jj < 1000; ++jj ) {
      double val = response(pt);
      prof->Fill(pt,(val-pt)/pt,1.);
      his2d->Fill(pt,val/pt,1.);
    }
  }
  
  his2d->GetXaxis()->SetRangeUser(30.,1000.);
  prof->GetXaxis()->SetRangeUser(30.,1000.);
  his2d->Draw("COLZ");
  prof->Draw("E1same");

  if (c1) c1->cd();
  if (c1) c1->SaveAs("Response.png");
  if (c1) c1->SaveAs("Response.pdf");
  if (c1) c1->SaveAs("Response.C");
  
  return c1;
  
}  

// // -----------------------------------------------------------------------------
// // 
// double xSectFunc( double* x, double* par ) {
//   double x1 =x[0];
//   double f = xSect(x1,x1);
//   return f;
// }

// -----------------------------------------------------------------------------
// 
TF1* xSect( const PSet& ps ) {
  return new TF1("3jet","(2*x*x)/((1-x)*(1-x))",ps.min,ps.max);
}

// -----------------------------------------------------------------------------
// 
TCanvas* xSectDistr( const PSet& ps ) {
  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  
  TCanvas* c1 = new TCanvas("CrossSectionCanvas","CrossSection");
  c1->SetLogy();
  
  TF1* fit = (TF1*)xSect(ps);
  fit->Draw();
  
  if (c1) c1->cd();
  if (c1) c1->SaveAs("CrossSection.png");
  if (c1) c1->SaveAs("CrossSection.pdf");
  if (c1) c1->SaveAs("CrossSection.C");
  
  return c1;
  
}

// -----------------------------------------------------------------------------
// 
double val( int bin, const PSet& ps ) {
  return ps.min + (ps.max-ps.min) * (bin*1.)/(ps.nbins*1.);
}

// -----------------------------------------------------------------------------
// returns false if (x2,x1) fails any of the kinematic constraints
bool constrainPhaseSpace( double x1, double x2, double x3 = 0. ) {
  return ( x1 >= 0. &&
	   x2 >= 0. &&
	   x3 <= 2. &&
	   x1 >= x2 &&                   // jet ordering by Pt
	   ( x1 + x2 ) <= 2. &&          // from relation "x1 + x2 + x3 = 2"
	   x1 < 1.  &&                   // from "lost jet" and relation "xmiss = -x1 -x2"
	   ( x1 + x2 ) >= 1. );          // from "lost jet" and relation "xmiss = -x1 -x2"
}

// -----------------------------------------------------------------------------
// returns true if passes jet threshold ("jet 0" = Meff check)
bool passThreshold( const PSet& ps, int imeff, int jet, double pt ) {
  if ( jet > 0 ) {
    return ( ( jet == 1 && pt > ps.pt1_bins[imeff] ) ||
	     ( jet == 2 && pt > ps.pt2_bins[imeff] ) ||
	     ( jet == 3 && pt < ps.pt3_bins[imeff] ) );
  } else {
    return ( pt > ps.meff_bins[imeff] && ( ps.nmeff - imeff > 1 ? pt < ps.meff_bins[imeff+1] : true ) );
  }
}

// -----------------------------------------------------------------------------
//
void clearTruth( const PSet& ps, DoubleVV& dalitz ) {
  if ( dalitz.empty() ) { return; }
  for ( int x2_bin = 0; x2_bin < ps.nbins; ++x2_bin ) { dalitz[x2_bin].clear(); }
  dalitz.clear();
}

// -----------------------------------------------------------------------------
//
void resizeTruth( const PSet& ps, DoubleVV& dalitz ) {
  if ( (int)dalitz.size() < ps.nbins ) { dalitz.resize( ps.nbins, DoubleV( ps.nbins, 0. ) ); }
  for ( int x2_bin = 0; x2_bin < ps.nbins; ++x2_bin ) { 
    if ( (int)dalitz[x2_bin].size() < ps.nbins ) { dalitz[x2_bin].resize( ps.nbins, 0. ); }
  }
}

// -----------------------------------------------------------------------------
//
void printTruth( const PSet& ps, DoubleVV& dalitz ) {
  std::stringstream ss;
  ss << "[printTruth] Print contents of array" << std::endl;
  ss << " x2-size: " << dalitz.size() << std::endl;
  for ( int x2_bin = 0; x2_bin < ps.nbins; ++x2_bin ) { 
    ss << " x2: " << x2_bin << ", x1-size: " << dalitz[x2_bin].size() << std::endl;
    for ( int x1_bin = 0; x1_bin < ps.nbins; ++x1_bin ) { 
      if ( dalitz[x2_bin][x1_bin] > 0. ) {
	ss << ", x1: " << x1_bin << ", val: " << dalitz[x2_bin][x1_bin];
      }
    }
    ss << std::endl;
  } 
  std::cout << ss.str() << std::endl;
}

// -----------------------------------------------------------------------------
// 
void calcPt( const PSet& ps, 
	     const int imeff, 
	     const double x1, 
	     const double x2, 
	     const double x3, 
	     double& pt1, 
	     double& pt2, 
	     double& pt3 ) {
  pt1 = ps.meff_bins[imeff] * x1 / ps.norm;
  pt2 = ps.meff_bins[imeff] * x2 / ps.norm;
  pt3 = ps.meff_bins[imeff] * x3 / ps.norm;
  if (false) {
    std::cout << "[calcJetPt]" 
	      << " imeff: " << imeff
	      << " meff: " << ps.meff_bins[imeff]
	      << " x1: " << x1
	      << " x2: " << x2
	      << " x3: " << ( ps.norm - x1 - x2 )
	      << " pt1: " << pt1
	      << " pt2: " << pt2
	      << " pt3: " << pt3
	      << std::endl;
  }
}

// -----------------------------------------------------------------------------
// 
void applyReco( const PSet& ps, 
		double& pt1, 
		double& pt2, 
		double& pt3,
		double& x1, 
		double& x2, 
		double& x3 ) {

  // Calc Meff
  double meff = pt1 + pt2 + pt3;

  // Apply mis-measurement to (visible) jets
  pt1 = response(pt1);
  pt2 = response(pt2);

  // Check for negative values
  pt1 = pt1 < 0. ? 0. : pt1; 
  pt2 = pt2 < 0. ? 0. : pt2; 

  // Reorder jets if necessary
  if ( pt2 > pt1 ) { double tmp = pt2; pt1 = pt2; pt2 = tmp; }

  // Calc phi b/w jet #1 and jet #2
  double phi = atan(1)*4. - acos( ( pow(x1,2) + pow(x2,2) - pow(x3,2) ) / ( 2. * x1 * x2 ) );
  
  // Lorentz vectors 
  PtEtaPhiM vpt1(pt1,0.,0.,0.);
  PtEtaPhiM vpt2(pt2,0.,phi,0.);
  PtEtaPhiM vpt3; vpt3 -= ( vpt1 + vpt2 );

  pt1 = vpt1.Pt();
  pt2 = vpt2.Pt();
  pt3 = vpt3.Pt();

  // Re-calc Meff
  meff = pt1 + pt2 + pt3;

  // Calc xi
  x1 = ps.norm * pt1 / meff;
  x2 = ps.norm * pt2 / meff;
  x3 = ps.norm * pt3 / meff;
  
//   std::cout << "[applyReco] DEBUG"
// 	    << "  pt1: " << pt1
// 	    << ", pt2: " << pt2
// 	    << ", pt3: " << pt3
// // 	    << ", vpt1: " << vpt1.Pt()
// // 	    << ", vpt2: " << vpt2.Pt()
// // 	    << ", vpt3: " << vpt3.Pt()
// // 	    << ", phi1: " << vpt1.Phi()
// // 	    << ", phi2: " << vpt2.Phi()
// // 	    << ", phi3: " << vpt3.Phi()
// 	    << ", vpx1: " << vpt1.Px()
// 	    << ", vpy1: " << vpt1.Py()
// 	    << ", vpx2: " << vpt2.Px()
// 	    << ", vpy2: " << vpt2.Py()
// 	    << ", vpx3: " << vpt3.Px()
// 	    << ", vpy3: " << vpt3.Py()
// 	    << std::endl;
  
}

// -----------------------------------------------------------------------------
// 
void print( const std::string& str,
	    const int imeff, 
	    const double pt1, 
	    const double pt2, 
	    const double pt3,
	    const double x1, 
	    const double x2, 
	    const double x3 ) {
  std::stringstream ss;
  ss << "[print] " << str
     << std::endl
     << " Meff bin:" << imeff
     << std::endl
     << " (pT1,pT2,pT3)=" 
     << "(" 
     << dr(pt1,1) << ","
     << dr(pt2,1) << ","
     << dr(pt3,1) 
     << ")" 
     << std::endl
     << " Meff=" << ( pt1 + pt2 + pt3 )
     << ", HT=" << ( pt1 + pt2 )
     << ", MHT=" << pt3
     << std::endl
     << " (x1,x2,x3)=" 
     << "(" 
     << dr(x1,3) << ","
     << dr(x2,3) << ","
     << dr(x3,3) 
     << ")" ;
  std::cout << ss.str() << std::endl;
}

// -----------------------------------------------------------------------------
// Create 2D vector: dalitz[x2][x1]
void generateTruth( const PSet& ps, 
		    const int imeff, 
		    DoubleVV& dalitz, 
		    const bool random = false, 
		    const int ntries = 100 ) {

  // Reset array
  clearTruth(ps,dalitz);
  resizeTruth(ps,dalitz);
  
  if ( !random ) {

    // One entry per bin
    for ( int x2_bin = 0; x2_bin < ps.nbins; ++x2_bin ) { 
      for ( int x1_bin = 0; x1_bin < ps.nbins; ++x1_bin ) { 
	double x1 = val(x1_bin,ps);
	double x2 = val(x2_bin,ps);
	if ( !constrainPhaseSpace(x1,x2) ) { continue; }
	dalitz[x2_bin][x1_bin] = xSect(x1,x2);
      }
    }

  } else {
    
    int nloop = ps.nbins*ps.nbins*ntries;
    for ( int ir = 0; ir < nloop; ++ir ) {
      
      // Generate random xi vales
      double x1 = 0.;
      double x2 = 0.;
      if ( true ) { 
	x1 = rndm.Rndm();
	x2 = rndm.Rndm();
      } else {
	x2 = rndm.Rndm();
	if ( ALGO_TYPE == 1 ) { x1 = cutAlgoInverse( 0.51, x2, ALGO_TYPE ); }
	else { x1 = cutAlgoInverse( cutAlgo(0.9,0.9,ALGO_TYPE), x2, ALGO_TYPE ); }
      }
      double x3 = ps.norm - x1 - x2;
      
      // Constrain truth to allowed phase space
      if ( !constrainPhaseSpace(x1,x2,x3) ) { continue; }

      // Calc pT values from truth
      double pt1 = 0.;
      double pt2 = 0.;
      double pt3 = 0.;
      calcPt(ps,imeff,x1,x2,x3,pt1,pt2,pt3);
      
      //print("BEFORE",imeff,pt1,pt2,pt3,x1,x2,x3);
      
      // Apply RECO 
      applyReco(ps,pt1,pt2,pt3,x1,x2,x3);
      
      // Apply pT thresholds on jets ("jet 0" = Meff check)
//       if ( !passThreshold(ps,imeff,1,pt1) ) { continue; }
//       if ( !passThreshold(ps,imeff,2,pt2) ) { continue; }
//       if ( !passThreshold(ps,imeff,3,pt3) ) { continue; }
      
      // Check if Meff falls within given bin
      if ( !passThreshold(ps,imeff,0,pt1+pt2+pt3) ) { continue; }
      
      // Constrain RECO to allowed phase space
      if ( !constrainPhaseSpace(x1,x2,x3) ) { continue; }
      
      // Store result
      int x2_bin = int(ps.nbins*x2);
      int x1_bin = int(ps.nbins*x1);
      dalitz[x2_bin][x1_bin] = xSect(x1,x2);

//           std::cout << "Completed " 
// 	      << int(100.*loop/nloops)
// 	      << "%..." 
// 	      << std::endl; loop++;



    }

  }

  //printTruth(ps,dalitz);

}

// -----------------------------------------------------------------------------
// 
//void createHisto( TH2D* his, std::stringstream& ss, const PSet& ps, DoubleVV& dalitz ) {
//}

// -----------------------------------------------------------------------------
//
void clear( DoubleVV& ratio,
	    DoubleVV& ratio_errh,
	    DoubleVV& ratio_errl,
	    DoubleVV& pass,
	    DoubleVV& pass_err,
	    DoubleVV& fail,
	    DoubleVV& fail_err,
	    IntV& length ) {

  // Clear vectors
  ratio.clear();
  ratio_errh.clear();
  ratio_errl.clear();
  pass.clear();
  pass_err.clear();
  fail.clear();
  fail_err.clear();
  length.clear();

}

// -----------------------------------------------------------------------------
//
void init( const PSet& ps,
	   DoubleVV& ratio,
	   DoubleVV& ratio_errh,
	   DoubleVV& ratio_errl,
	   DoubleVV& pass,
	   DoubleVV& pass_err,
	   DoubleVV& fail,
	   DoubleVV& fail_err,
	   IntV& length ) {

  // Init vectors
  ratio.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  ratio_errh.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  ratio_errl.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  pass.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  pass_err.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  fail.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  fail_err.resize( ps.cutValues.size(), DoubleV( ps.nmeff, 0. ) );
  length.resize( ps.cutValues.size(), 0 );

}

// -----------------------------------------------------------------------------
//
void integrate( const PSet& ps,
		const int imeff,
		const DoubleVV& dalitz,
   		DoubleVV& ratio,
   		DoubleVV& ratio_errh,
   		DoubleVV& ratio_errl,
   		DoubleVV& pass,
   		DoubleVV& pass_err,
   		DoubleVV& fail,
   		DoubleVV& fail_err,
   		IntV& length ) {

  // Iterate through cut values
  for ( int icut = 0; icut < (int)ps.cutValues.size(); ++icut ) {

    // Loop through xi bins
    for ( int x2_bin = 0; x2_bin < ps.nbins; ++x2_bin ) { 
      for ( int x1_bin = 0; x1_bin < ps.nbins; ++x1_bin ) { 
	
	// Value of cut variable for given bin in (x1,x2) 
	double x2 = val(x2_bin,ps);
	double x1 = val(x1_bin,ps);
	double var = cutAlgo(x1,x2,ALGO_TYPE);

	    
	// Add bin content to numerator and denominator 
	double val = dalitz[x2_bin][x1_bin] * ( ps.width * ps.width );// / ( ps.nbins * ps.nbins );
	if ( var > ps.cutValues[icut] ) { 
	  pass[icut][imeff] += val; 
	  pass_err[icut][imeff] += val*val; 
	} else { 
	  fail[icut][imeff] += val;
	  fail_err[icut][imeff] += val*val;
	}
	
      }
    }

    // Error is sqrt of sum of weights squared
    pass_err[icut][imeff] = sqrt(pass_err[icut][imeff]);
    fail_err[icut][imeff] = sqrt(fail_err[icut][imeff]);
    
    // Calculate ratio
    if ( fail[icut][imeff] > 0. ) { 
      ratio[icut][imeff] = pass[icut][imeff]/fail[icut][imeff]; 
      if ( ratio[icut][imeff] > 0. ) { length[icut]++; }
    }
    
    // Calc upper and lower bounds on ratio
//     double r = ratio[icut][imeff];
//     double t = pass[icut][imeff] + fail[icut][imeff];
//     if ( t > 0. ) { 
//       Double_t sigma = std::sqrt(r*(1.-r)/t);
//       Double_t alpha = ( 1. - 0.683 ) / 2.;
//       Double_t delta = ROOT::Math::normal_quantile(1-alpha,sigma);
//       ratio_errh[icut][imeff] = (r+delta) > 1. ? 1. : r+delta;
//       ratio_errl[icut][imeff] = (r-delta) < 0. ? 0. : r-delta;
//     } else {
//       ratio_errh[icut][imeff] = 1.;
//       ratio_errl[icut][imeff] = 0.;
//     }
    ratio_errh[icut][imeff] = ratio[icut][imeff] * ( pass[icut][imeff] > 0. ? pass_err[icut][imeff] / pass[icut][imeff] : 0. );
    ratio_errl[icut][imeff] = ratio[icut][imeff] * ( pass[icut][imeff] > 0. ? pass_err[icut][imeff] / pass[icut][imeff] : 0. );

//     std::cout << " icut: " << ps.cutValues[icut]
// 	      << " imeff: " << imeff
// 	      << " pass: " << pass[icut][imeff]
// 	      << " +/- " << pass_err[icut][imeff]
// 	      << " fail: " << fail[icut][imeff]
// 	      << " +/- " << fail_err[icut][imeff]
// 	      << " ratio: " << ratio[icut][imeff]
// 	      << " + " << ratio_errh[icut][imeff]
// 	      << " - " << ratio_errl[icut][imeff]
// 	      << " length: " << length[icut]
// 	      << std::endl;

  }
  
}

// // -----------------------------------------------------------------------------
// //
// void integrate( int nbins, 
// 		double alpha_t,
// 		double pt,
// 		//double x1,
// 		double ht,
// 		double& numerator,
// 		double& denominator, 
// 		double xlow, 
// 		double xhigh, 
// 		double ylow, 
// 		double yhigh  ) {
  
//   // Calculate X3
//   double x3 = ( 2. * pt ) / ( ht + pt );
  
//   // Bin widths
//   double xwidth = ( xhigh - xlow ) / nbins;
//   double ywidth = ( yhigh - ylow ) / nbins;
  
//   // Loop through bins
//   for ( int xbin = 0; xbin < nbins; ++xbin ) { 
//     for ( int ybin = 0; ybin < nbins; ++ybin ) { 
      
//       // (x,y) for bottom-left corner of bin
//       double xbl = xlow + xwidth * xbin;
//       double ybl = ylow + ywidth * ybin;
      
//       // Check if bottom-left corner of bin passes the kinematic constraints
//       bool pass = constrain(ybl,xbl,x3);
//       if ( !pass ) { continue; }
      
//       // Check x1 is greater than some min threshold
//       //if ( ybl < x1 ) { continue; }

//       // AlphaT values at corners of bin
//       double nbl = ybl + xbl - 1;
//       double abl = nbl < 0. ? 1.e9 : xbl / ( 2. * sqrt( nbl ) ); 

//       // Cross-section values at corners
//       bool bbl = xbl < 1. && ybl < 1.;
//       double cbl = !bbl ? 0. : ( xbl*xbl + ybl*ybl ) / ( ( 1. - xbl ) * ( 1. - ybl ) ); 
      
//       // Add value at bottom-left corner to numerator and denominator 
//       denominator += (cbl*xwidth*ywidth)/(nbins*nbins);
//       if ( abl > alpha_t ) { numerator += (cbl*xwidth*ywidth)/(nbins*nbins); }
      
//     }
//   }
  
// }

// // -----------------------------------------------------------------------------
// //
// void integrate( int nbins, 
// 		double alpha_t,
// 		double pt,
// 		double x1,
// 		double ht,
// 		double& numerator,
// 		double& denominator, 
// 		double xlow, 
// 		double xhigh, 
// 		double ylow, 
// 		double yhigh  ) {
  
//   // Calculate X3
//   double x3 = ( 2. * pt ) / ( ht + pt );
  
//   // Bin widths
//   double xwidth = ( xhigh - xlow ) / nbins;
//   double ywidth = ( yhigh - ylow ) / nbins;
  
//   // Loop through bins
//   for ( int xbin = 0; xbin < nbins; ++xbin ) { 
//     for ( int ybin = 0; ybin < nbins; ++ybin ) { 
      
//       // (x,y) for bottom-left corner of bin
//       double xbl = xlow + xwidth * xbin;
//       double ybl = ylow + ywidth * ybin;
      
//       // Check if bottom-left corner of bin passes the kinematic constraints
//       bool pass = constrain(ybl,xbl,x3);
//       if ( !pass ) { continue; }
      
//       // Check x1 is greater than some min threshold
//       if ( ybl < x1 ) { continue; }

//       // AlphaT values at corners of bin
//       double nbl = ybl + xbl - 1;
//       double abl = nbl < 0. ? 1.e9 : xbl / ( 2. * sqrt( nbl ) ); 

//       // Cross-section values at corners
//       bool bbl = xbl < 1. && ybl < 1.;
//       double cbl = !bbl ? 0. : ( xbl*xbl + ybl*ybl ) / ( ( 1. - xbl ) * ( 1. - ybl ) ); 
      
//       // Add value at bottom-left corner to numerator and denominator 
//       denominator += (cbl*xwidth*ywidth)/(nbins*nbins);
//       if ( abl > alpha_t ) { numerator += (cbl*xwidth*ywidth)/(nbins*nbins); }
      
//     }
//   }
  
// }

// -----------------------------------------------------------------------------
//
// void integrateR( int depth, 
// 		 int ndepth, 
// 		 int* nbins, 
// 		 double x3,
// 		 double alpha_t,
// 		 double& numerator,
// 		 double& denominator, 
// 		 double xlow, 
// 		 double xhigh, 
// 		 double ylow, 
// 		 double yhigh  ) {
  
//   bool debug1 = false;
//   bool debug2 = false;

//   // Count number of iterations
//   depth++;

//   double exponent = 0.;
//   for ( int ii = 0; ii < ndepth; ++ii ) { exponent += log10(nbins[depth-1]); }
//   if ( exponent > 12. ) {
//     std::cout << " Too many bins required! " << std::endl;
//     return;
//   }
  
//   // Bin widths
//   double xwidth = ( xhigh - xlow ) / nbins[depth-1];
//   double ywidth = ( yhigh - ylow ) / nbins[depth-1];

//   if (debug1) std::cout << "depth: " << depth
// 			<< " ndepth: " << ndepth
// 			<< " nbins[depth-1]: " << nbins[depth-1]
// 			<< " x3: " << x3
// 			<< " at: " << alpha_t
// 			<< " xlow: " << xlow
// 			<< " xhigh: " << xhigh
// 			<< " ylow: " << ylow
// 			<< " yhigh: " << yhigh
// 			<< " xwidth: " << xwidth
// 			<< " ywidth: " << ywidth
// 			<< std::endl;

//   // Counters
//   int npass = 0;
//   int nfail = 0;
//   int nedge = 0;
//   int nabove = 0;
//   int nbelow = 0;
//   int nstraddles = 0;

//   // Loop through bins
//   for ( int xbin = 0; xbin < nbins[depth-1]; ++xbin ) { 
//     for ( int ybin = 0; ybin < nbins[depth-1]; ++ybin ) { 
      
//       // (x,y) for bottom-left corner of bin
//       double xbl = xlow + xwidth * xbin;
//       double ybl = ylow + ywidth * ybin;

//       // (x,y) for bottom-right corner of bin
//       double xbr = xlow + xwidth * (xbin+1);
//       double ybr = ylow + ywidth * ybin;

//       // (x,y) for top-left corner of bin
//       double xtl = xlow + xwidth * xbin;
//       double ytl = ylow + ywidth * (ybin+1);

//       // (x,y) for top-right corner of bin
//       double xtr = xlow + xwidth * (xbin+1);
//       double ytr = ylow + ywidth * (ybin+1);
      
//       // Check if all corners of bin pass or fail the kinematic constraints
//       bool pass = constrain(ybl,xbl,x3) && constrain(ybr,xbr,x3) && constrain(ytl,xtl,x3) && constrain(ytr,xtr,x3);
//       bool fail = !constrain(ybl,xbl,x3) && !constrain(ybr,xbr,x3) && !constrain(ytl,xtl,x3) && !constrain(ytr,xtr,x3);
//       bool edge = !pass && !fail;
      
//       if (pass) npass++;
//       if (fail) nfail++;
//       if (edge) nedge++;
      
//       // If all fail, do not consider bin
//       if ( fail ) { continue; }

//       // AlphaT values at corners of bin
//       double nbl = ybl + xbl - 1;
//       double nbr = ybr + xbr - 1;
//       double ntl = ytl + xtl - 1;
//       double ntr = ytr + xtr - 1;
//       double abl = nbl < 0. ? 1.e9 : xbl / ( 2. * sqrt( nbl ) ); 
//       double abr = nbr < 0. ? 1.e9 : xbr / ( 2. * sqrt( nbr ) ); 
//       double atl = ntl < 0. ? 1.e9 : xtl / ( 2. * sqrt( ntl ) ); 
//       double atr = ntr < 0. ? 1.e9 : xtr / ( 2. * sqrt( ntr ) ); 
      
//       // Difference b/w values at corners and cut value
//       double dbl = abl - alpha_t;
//       double dbr = abr - alpha_t;
//       double dtl = atl - alpha_t;
//       double dtr = atr - alpha_t;

//       // Check if bin falls below, above or straddles cut AlphaT value
//       bool below = dbl<0. && dbr<0. && dtl<0. && dtr<0.;
//       bool above = dbl>0. && dbr>0. && dtl>0. && dtr>0.;
//       bool straddles = !above && !below;
      
//       if (above) nabove++;
//       if (below) nbelow++;
//       if (straddles) nstraddles++;
      
//       // Cross-section values at corners
//       bool bbl = xbl < 1. && ybl < 1.;
//       bool bbr = xbr < 1. && ybr < 1.;
//       bool btl = xtl < 1. && ytl < 1.;
//       bool btr = xtr < 1. && ytr < 1.;
//       double cbl = !bbl ? 0. : ( xbl*xbl + ybl*ybl ) / ( ( 1. - xbl ) * ( 1. - ybl ) ); 
//       double cbr = !bbr ? 0. : ( xbr*xbr + ybr*ybr ) / ( ( 1. - xbr ) * ( 1. - ybr ) ); 
//       double ctl = !btl ? 0. : ( xtl*xtl + ytl*ytl ) / ( ( 1. - xtl ) * ( 1. - ytl ) ); 
//       double ctr = !btr ? 0. : ( xtr*xtr + ytr*ytr ) / ( ( 1. - xtr ) * ( 1. - ytr ) ); 
      
//       if ( ( edge || straddles ) && depth < ndepth ) {

// 	if (debug2) std::cout << " depth: " << depth << std::endl;

// 	if (debug2) std::cout << " xbin: " << xbin
// 			      << " ybin " << ybin
// 			      << " bl: " << xbl
// 			      << "," << ybl
// 			      << " br: " << xbr
// 			      << "," << ybr
// 			      << " tl: " << xtl
// 			      << "," << ytl
// 			      << " tr: " << xtr
// 			      << "," << ytr
// 			      << std::endl;

// 	if (debug2) std::cout << " pbl: " << constrain(ybl,xbl,x3)
// 			      << " pbr: " << constrain(ybr,xbr,x3)
// 			      << " ptl: " << constrain(ytl,xtl,x3)
// 			      << " ptr: " << constrain(ytr,xtr,x3)
// 			      << " pass: " << pass
// 			      << " fail: " << fail
// 			      << " edge: " << edge
// 			      << std::endl;

// 	if (debug2) std::cout << " abl: " << abl
// 			      << " abr: " << abr
// 			      << " atl: " << atl
// 			      << " atr: " << atr
// 			      << std::endl;

// 	if (debug2) std::cout << " dbl: " << dbl
// 			      << " dbr: " << dbr
// 			      << " dtl: " << dtl
// 			      << " dtr: " << dtr
// 			      << std::endl;
	
// 	if (debug2) std::cout << " above: " << above
// 			      << " below: " << below
// 			      << " straddles: " << straddles
// 			      << std::endl;
	
// 	if (debug2) std::cout << " cbl: " << cbl
// 			      << " cbr: " << cbr
// 			      << " ctl: " << ctl
// 			      << " ctr: " << ctr
// 			      << std::endl;
	
// 	// If bin at edge of kinematically allowed region or alpha_t cut is straddles bin, iterate again
// 	integrate( depth, ndepth, nbins, x3, alpha_t, numerator, denominator, xbl, xbr, ybl, ytl );
	
//       } else {
	
// 	// Check bin widths
// 	if ( xwidth == 0. || ywidth == 0. ) { continue; }
	
//  	// Add value at bottom-left corner to numerator and denominator 
// 	denominator += (cbl*xwidth*ywidth)/(nbins[depth-1]*nbins[depth-1]);
// 	if ( abl > alpha_t ) { 
// 	  numerator += (cbl*xwidth*ywidth)/(nbins[depth-1]*nbins[depth-1]); 
// 	}
//       }
      
//     } // loop
//   } // loop
  
//   if (debug1) std::cout << " depth: " << depth
// 			<< " npass: " << npass
// 			<< " nfail: " << nfail
// 			<< " nedge: " << nedge
// 			<< " nabove: " << nabove
// 			<< " nbelow: " << nbelow
// 			<< " nstraddles: " << nstraddles
// 			<< " numerator: " << numerator
//  			<< " denominator: " << denominator
// 			<< std::endl;
// }
