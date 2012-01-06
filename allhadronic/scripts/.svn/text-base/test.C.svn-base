#include "./utility.C"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TMultiGraph.h"
#include "TPad.h"
#include "TString.h"
#include "TStyle.h"
#include "TTimeStamp.h"
#include <sstream>

// -----------------------------------------------------------------------------
//
void test() {

  time_t start = TTimeStamp().GetSec();

  set_plot_style();

  bool draw = true;
  //bool debug = true;

  // Define analysis configuration
  PSet ps;
  defaultPSet(ps);

  // Response plots
  if (false) {
    //xSectDistr(ps);
    responseProfile();
    return;
  }
  
  // Print configuration
  std::stringstream ss;
  printPSet(ps,ss);
  std::cout << ss.str() << std::endl;
  
  // Params to store
  DoubleVV ratio, ratio_errh, ratio_errl, pass, pass_err, fail, fail_err;
  IntV length;
  clear( ratio, ratio_errh, ratio_errl, pass, pass_err, fail, fail_err, length );
  init( ps, ratio, ratio_errh, ratio_errl, pass, pass_err, fail, fail_err, length );
  
  // Loop through Meff bins 
  int loop = 0;
  int nloops = ps.nmeff;
  for ( int imeff = 0; imeff < ps.nmeff; ++imeff ) {

    // Generate numbers in (x1,x2) plane
    DoubleVV dalitz;
    generateTruth( ps, imeff, dalitz, true );

    // Integrate across dalitz plane
    integrate( ps, imeff, dalitz, ratio, ratio_errh, ratio_errl, 
	       pass, pass_err, fail, fail_err, length );
    
    // Labeling
    std::stringstream ss;
    ss << "Meff" << int( ps.meff_bins[imeff] );
    
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
    if (draw) hr = pad->DrawFrame(ps.min,ps.min,ps.max,ps.max);
    
    // Histo title
    if (hr) {
      std::stringstream sss;
      sss << "M_{eff}=" << ps.meff_bins[imeff] << " GeV"
	  << ", p_{T1}=" << dr(ps.pt1_bins[imeff],1) << " GeV"
	  << ", p_{T2}=" << dr(ps.pt2_bins[imeff],1) << " GeV"
	  << ", p_{T3}=" << dr(ps.pt3_bins[imeff],1) << " GeV";
      hr->SetTitle( sss.str().c_str() );
      hr->GetXaxis()->SetTitle( "x_{2}" );
      hr->GetYaxis()->SetTitle( "x_{1}" );
    }
    
    // Create 2D cross-section plot
    TH2D* his = 0;
    if (draw) his = new TH2D(TString("Histo"+ss.str()),"",
			     ps.nbins,ps.min,ps.max,
			     ps.nbins,ps.min,ps.max);
    
    //double x3 = ( 2. * ps.pt3_bins[imeff] ) / ( ps.meff_bins[imeff] + ps.pt3_bins[imeff] );
    
    // Fill 2D cross-section plot
    for ( int x2_bin = 0; x2_bin < ps.nbins; ++x2_bin ) { 
      for ( int x1_bin = 0; x1_bin < ps.nbins; ++x1_bin ) { 
// 	std::cout << " Fill:"
// 		  << " x2_bin: " << x2_bin 
// 		  << " x2: " << val(x2_bin,nbins) 
// 		  << " x1_bin: " << x1_bin 
// 		  << " x1: " << val(x1_bin,nbins) 
// 		  << " val: " << dalitz[x2_bin][x1_bin]
// 		  << std::endl;
	if (his) his->Fill( val(x2_bin,ps)+ps.width/2.,
			    val(x1_bin,ps)+ps.width/2.,
			    dalitz[x2_bin][x1_bin] ); 
      }
    }
    
    // Draw 2D cross-section plot
    gStyle->SetPalette(1);
    if (his) {
      //his->SetMaximum( his->GetMaximum()*10. );
      //his->SetMinimum( his->GetMinimum(1.e-12)*0.1 );
//       his->SetMaximum( 1.e9 );
//       his->SetMinimum( 1.e0 );
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
    //TH1F* hframe = 0;
    if (draw) overlay->DrawFrame(pad->GetUxmin(),
				 pad->GetUymin(),
				 pad->GetUxmax(),
				 pad->GetUymax());
	  
    // Graphs of AlphaT contours
    TMultiGraph* mg = 0;
    if (draw) {
      mg = new TMultiGraph();
      for ( Int_t icut = 0; icut < (int)ps.cutValues.size(); icut++ ) {
	Double_t alpha_t = ps.cutValues[icut];
	const Int_t n = ps.nbins;
	DoubleV x1(n,0.);
	DoubleV x2(n,0.);
	for ( Int_t x2_bin = 0; x2_bin < ps.nbins; x2_bin++ ) {
	  x2[x2_bin] = x2_bin * ps.width;
	  x1[x2_bin] = cutAlgoInverse(ps.cutValues[icut],x2[x2_bin],ALGO_TYPE);
	}
	TGraph* gr = new TGraph(n,&x2.front(),&x1.front());
	mg->Add(gr,"l");
      }
      mg->Draw();
    }
	  
    if (c1) c1->cd();
    if (c1) c1->SaveAs(TString(ss.str()+".png"));
    if (c1) c1->SaveAs(TString(ss.str()+".pdf"));
    if (c1) c1->SaveAs(TString(ss.str()+".C"));

  }

  // Canvas for ratio vs Meff
  if (false) {
    
    TCanvas* c2 = new TCanvas( "c2", "" );
    c2->SetRightMargin(0.2);
    c2->SetLogy();
    c2->cd();
    TMultiGraph* mg2 = new TMultiGraph();

    DoubleV err( ps.nmeff, 0. );
    for ( Int_t icut = 0; icut < (int)ps.cutValues.size(); icut++ ) {
      if ( length[icut] == 0 ) { continue; }
//       TGraphAsymmErrors* gr = new TGraphAsymmErrors( length[icut], 
//  						     &ps.meff_bins.front(), 
//  						     &err.front(),
//  						     &err.front(),
//  						     &ratio[icut].front(),
//  						     &ratio_errl[icut].front(),
//  						     &ratio_errh[icut].front() );
      TGraph* gr = new TGraphAsymmErrors( length[icut], 
 					  &ps.meff_bins.front(), 
 					  &ratio[icut].front() );
      std::stringstream ss;
      ss << "a_{T}=" << ps.cutValues[icut];
// 	 << " Meff=" << meff_bins[imeff]
// 	 << ", p_{T3}=" << pt3_bins[imeff];
      mg2->Add(gr,"lp");
      gr->SetTitle(TString(ss.str()));
      gr->SetLineColor(2+icut);
      gr->SetLineWidth(2);
      gr->SetMarkerStyle(20+icut);
      gr->SetMarkerColor(2+icut);
      gr->SetMarkerSize(1.5);
    }
    
    mg2->Draw("a");
    mg2->GetYaxis()->SetRangeUser(1.e-6,1.e0);
    c2->Update();
    c2->BuildLegend(0.81,0.1,0.99,0.9);
    
    // Save canvases
    c2->cd();
    c2->SaveAs("RatioVsMeff.png");
    c2->SaveAs("RatioVsMeff.pdf");
    c2->SaveAs("RatioVsMeff.C");
    
  }
  
  time_t stop = TTimeStamp().GetSec();
  std::cout << " Time taken: " << stop - start <<  " seconds" << std::endl;

}
