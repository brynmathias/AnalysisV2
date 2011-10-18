#include <TCanvas.h>
#include <TDirectory.h>
#include <TFile.h>
#include <TGraphAsymmErrors.h>
#include <TH1D.h>
#include <TLegend.h>
#include <TStyle.h>
#include <iostream>
#include <string>
#include <vector>


void calcIntegral( TH1D* cum, bool greater_than ) {

  double val = 0.;
  double err = 0.;

  // Loop through bins 
  int nbins = cum->GetNbinsX();
  for ( int ibin = 0; ibin <= nbins+1; ibin++ ) {
    
    // Check direction
    int bin = ibin;
    if ( greater_than ) { bin = nbins+1 - ibin; }
    
    // Running totals
    val += cum->GetBinContent(bin);
    err += cum->GetBinError(bin) * cum->GetBinError(bin);
    
    // Set bin content and error
    cum->SetBinContent(bin,val);
    cum->SetBinError(bin,sqrt(err));
    
  }
  
  // Number of entries
  cum->SetEntries(nbins+1);

}


void trigger() {

  gStyle->SetOptStat(1111111);
  
  std::vector<std::string> trig;
  trig.push_back("HLT_HT150_v2");
  trig.push_back("HLT_HT150_AlphaT0p60_v1");
  
  std::vector<std::string> his;
  his.push_back("ge2");
  his.push_back("eq2");
  his.push_back("eq3");
  his.push_back("ge4");
  
  TFile* f =  new TFile(std::string("../Trigger_HT_Run2011A_PromptReco_v1.root").c_str(),"READ");
  if ( f && !f->IsZombie() ) { 
    std::cout << "Opened file: " << f->GetName() << std::endl; 
  } else { 
    std::cout << "Could not find file " << std::endl; 
    //return; 
  }
	  
  TDirectory* d = (f==0?0:(TDirectory*)f->Get("Triggers"));
  if (d) { std::cout << "Opened dir: " << d->GetName() << std::endl; }
  else { 
    std::cout << "Could not find dir " << std::endl; 
    //return; 
  }
  
  TCanvas* c1 = new TCanvas(std::string("trigger").c_str(),
			    std::string("trigger").c_str(),
			    600,600);
  c1->Divide(1,2);

  TLegend* legend = new TLegend( 0.7, 0.6, 0.85, 0.7, NULL, "brNDC" );
  
  std::vector<TH1D*> h(trig.size(),0);
  std::vector<TH1D*> i(trig.size(),0);
  
  for ( int ii = 0; ii < trig.size(); ++ii ) {
    
    std::string str;
    str = trig[ii]+"_all";
//     if      ( his[jj] == "eq2" ) { str = trig[ii]+"_2"; }
//     else if ( his[jj] == "eq3" ) { str = trig[ii]+"_3"; }
//     else if ( his[jj] == "ge4" ) { str = trig[ii]+"_4"; }
//     else                         { str = trig[ii]+"_all"; }
    
    h[ii] = (d==0?0:(TH1D*)d->Get(str.c_str()));
    if (h[ii]) { std::cout << "Opened histo: " << h[ii]->GetName() << std::endl; }
    else { 
      std::cout << "Could not find histo " << std::endl; 
      //continue; 
    }
    
    i[ii] = (h[ii]==0?0:(TH1D*)h[ii]->Clone());
    if (i[ii]) calcIntegral(i[ii],true);
    
    legend->AddEntry( h[ii], trig[ii].c_str(), "pl" );
    
  }
  
//   TGraphAsymmErrors* gr1 = new TGraphAsymmErrors();
//   if ( h[0] && h[1] ) gr1->BayesDivide(h[0],h[1]);
  
//   TGraphAsymmErrors* gr2 = new TGraphAsymmErrors();
//   if ( i[0] && i[1] ) gr2->BayesDivide(i[0],i[1]);
	  
  c1->cd(1);
  if ( h[0] && h[1] ) { 
    h[0]->GetXaxis()->SetTitle("#alpha_{T}");
    h[0]->SetLineColor(kRed);
    h[0]->SetFillColor(kRed-10);
    h[0]->GetXaxis()->SetRangeUser(0.,1.);
    h[0]->Draw("");
    h[1]->GetXaxis()->SetTitle("#alpha_{T}");
    h[1]->GetXaxis()->SetRangeUser(0.,1.);
    h[1]->Draw("sameP");
    
    legend->SetTextSize(0.035);
    //legend->SetFillColor(0);
    //legend->SetLineColor(0); 
    //legend->SetShadowColor(0); 
    legend->Draw("same");
    
  }

  c1->cd(2);
  if ( i[0] && i[1] ) { 
    i[0]->GetXaxis()->SetTitle("#alpha_{T} > cut value");
    i[0]->GetXaxis()->SetRangeUser(0.,1.);
    i[0]->SetLineColor(kRed);
    i[0]->SetFillColor(kRed-10);
    i[0]->Draw("LF2");
    i[1]->GetXaxis()->SetTitle("#alpha_{T} > cut value");
    i[1]->GetXaxis()->SetRangeUser(0.,1.);
    i[1]->Draw("sameP");

    legend->SetTextSize(0.035);
    legend->SetFillColor(0);
    legend->SetLineColor(0); 
    legend->SetShadowColor(0); 
    legend->Draw("same");

  }
  
//   c1->cd(3);
//   if ( h[0] && h[1] ) { 
//     gr1->GetXaxis()->SetTitle("#alpha_{T}");
//     gr1->GetYaxis()->SetTitle("Differential Efficiency");
//     gr1->GetXaxis()->SetRangeUser(0.,1.);
//     gr1->Draw("alp");
//   }
  
//   c1->cd(4);
//   if ( i[0] && i[1] ) {
//     gr2->GetXaxis()->SetTitle("#alpha_{T} > cut value");
//     gr2->GetYaxis()->SetTitle("Cumulative Efficiency");
//     gr2->GetXaxis()->SetRangeUser(0.4,1.0);
//     gr2->GetYaxis()->SetRangeUser(0.9,1.);
//     gr2->Draw("alp");
//   }
  
  //c1->Update();
  c1->SaveAs(std::string("trigger.pdf").c_str());
  
}
