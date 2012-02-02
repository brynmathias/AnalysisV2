#include <TCanvas.h>
#include <TDirectory.h>
#include <TFile.h>
#include <TF1.h>
#include <TGraphAsymmErrors.h>
#include <TH1D.h>
#include <TLegend.h>
#include <TMath.h>
#include <TPaveStats.h>
#include <TStyle.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

Double_t errorFunc( Double_t* x, Double_t* par ) {
  return 0.5*par[0]*(1. + TMath::Erf( (x[0] - par[1]) / (sqrt(2.)*par[2]) )) ;
}

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

void turnon() {

  //std::string filename("../python/TurnOn_HT_Run2011A_PromptReco_v1.root");
  //std::string filename("../python/TurnOn_HT_Run2011_promptReco_DCS.root");
  std::string filename("../python/TurnOn_data.root");

  int rebin = 10;

  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);

  std::vector<std::string> triggers;
  
  // Menu 1

  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");
  triggers.push_back("HLT_HT260_MHT60_v2");

  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");
  triggers.push_back("HLT_HT300_MHT75_v2");

  triggers.push_back("HLT_HT240_v2");
  triggers.push_back("HLT_HT260_v2");
  triggers.push_back("HLT_HT260_v2");
  triggers.push_back("HLT_HT300_v2");
  triggers.push_back("HLT_HT300_v2");
  triggers.push_back("HLT_HT300_v2");
  triggers.push_back("HLT_HT360_v2");
  triggers.push_back("HLT_HT360_v2");
  triggers.push_back("HLT_HT360_v2");
  triggers.push_back("HLT_HT360_v2");
  triggers.push_back("HLT_HT440_v2");
  triggers.push_back("HLT_HT440_v2");
  triggers.push_back("HLT_HT440_v2");
  triggers.push_back("HLT_HT440_v2");
  triggers.push_back("HLT_HT440_v2");
  triggers.push_back("HLT_HT520_v2");
  triggers.push_back("HLT_HT520_v2");
  triggers.push_back("HLT_HT520_v2");
  triggers.push_back("HLT_HT520_v2");
  triggers.push_back("HLT_HT520_v2");
  triggers.push_back("HLT_HT520_v2");

  // Menu 2

  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");
  triggers.push_back("HLT_HT250_MHT60_v2");

  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");
  triggers.push_back("HLT_HT300_MHT75_v3");

  triggers.push_back("HLT_HT250_v2");
  triggers.push_back("HLT_HT250_v2");
  triggers.push_back("HLT_HT300_v3");
  triggers.push_back("HLT_HT300_v3");
  triggers.push_back("HLT_HT300_v3");
  triggers.push_back("HLT_HT350_v2");
  triggers.push_back("HLT_HT350_v2");
  triggers.push_back("HLT_HT350_v2");
  triggers.push_back("HLT_HT350_v2");
  triggers.push_back("HLT_HT400_v2");
  triggers.push_back("HLT_HT400_v2");
  triggers.push_back("HLT_HT400_v2");
  triggers.push_back("HLT_HT400_v2");
  triggers.push_back("HLT_HT400_v2");
  triggers.push_back("HLT_HT450_v2");
  triggers.push_back("HLT_HT450_v2");
  triggers.push_back("HLT_HT450_v2");
  triggers.push_back("HLT_HT450_v2");
  triggers.push_back("HLT_HT450_v2");
  triggers.push_back("HLT_HT450_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT500_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");
  triggers.push_back("HLT_HT550_v2");

  // Menu 3
  
  std::vector<std::string> prefilters;

  // Menu 1

  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT260_v2");

  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT300_v2");

  prefilters.push_back("HLT_HT160_v2");
  prefilters.push_back("HLT_HT160_v2");
  prefilters.push_back("HLT_HT240_v2");
  prefilters.push_back("HLT_HT160_v2");
  prefilters.push_back("HLT_HT240_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT160_v2");
  prefilters.push_back("HLT_HT240_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT160_v2");
  prefilters.push_back("HLT_HT240_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT360_v2");
  prefilters.push_back("HLT_HT160_v2");
  prefilters.push_back("HLT_HT240_v2");
  prefilters.push_back("HLT_HT260_v2");
  prefilters.push_back("HLT_HT300_v2");
  prefilters.push_back("HLT_HT360_v2");
  prefilters.push_back("HLT_HT420_v2");

  // Menu 2

  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT250_v2");

  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT300_v3");

  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT300_v3");

  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT350_v2");

  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT350_v2");
  prefilters.push_back("HLT_HT400_v2");

  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT350_v2");
  prefilters.push_back("HLT_HT400_v2");
  prefilters.push_back("HLT_HT450_v2");

  prefilters.push_back("HLT_HT150_v2");
  prefilters.push_back("HLT_HT200_v2");
  prefilters.push_back("HLT_HT250_v2");
  prefilters.push_back("HLT_HT300_v3");
  prefilters.push_back("HLT_HT350_v2");
  prefilters.push_back("HLT_HT400_v2");
  prefilters.push_back("HLT_HT450_v2");
  prefilters.push_back("HLT_HT500_v2");

  // Menu 3

  prefilters.resize(triggers.size(),"");

  std::vector<std::string> vars;

  // Menu 1

  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");

  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");

  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");

  // Menu 2

  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");

  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("MHToverHT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");
  vars.push_back("AlphaT");

  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");
  vars.push_back("HT");

  // Menu 3

  vars.resize(triggers.size(),"");
  
  std::vector<int> htbins;

  // Menu 1

  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);

  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);

  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(1);
  htbins.push_back(1);
  htbins.push_back(1);
  htbins.push_back(1);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);

  // Menu 2

  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);

  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(2);

  htbins.push_back(0);
  htbins.push_back(0);
  htbins.push_back(1);
  htbins.push_back(1);
  htbins.push_back(1);
  htbins.push_back(2);
  htbins.push_back(2);
  htbins.push_back(2);
  htbins.push_back(2);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(3);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(4);
  htbins.push_back(5);
  htbins.push_back(5);
  htbins.push_back(5);
  htbins.push_back(5);
  htbins.push_back(5);
  htbins.push_back(5);
  htbins.push_back(5);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);
  htbins.push_back(6);

  // Menu 3

  htbins.resize(triggers.size(),0);
  
  std::vector<std::string> multi;
  multi.resize(triggers.size(),"ge2");
  
  TFile* f =  new TFile(filename.c_str(),"READ");
  if ( f && !f->IsZombie() ) { 
    std::cout << "Opened file: " << f->GetName() << std::endl; 
  } else { 
    std::cout << "Could not find file " << std::endl; 
    return; 
  }
  
  TDirectory* d = (f==0?0:(TDirectory*)f->Get("TurnOn"));
  if (d) { std::cout << "Opened dir: " << d->GetName() << std::endl; }
  else { 
    std::cout << "Could not find dir " << std::endl; 
    return; 
  }
  
  for ( int ii = 0; ii < triggers.size(); ++ii ) {
    
//     TCanvas* c1 = new TCanvas(std::string("turnon"+ii).c_str(),
// 			      std::string("turnon"+ii).c_str(),
// 			      600,600);
//     c1->Divide(2,2);

    std::stringstream ss; 
    ss << "turnon_" << ii << ".pdf";
    TCanvas* c2 = new TCanvas(ss.str().c_str(),
			      ss.str().c_str(),
			      600,600);

    //TLegend* legend = new TLegend( 0.7, 0.6, 0.85, 0.7, NULL, "brNDC" );
       
    std::stringstream name_t; 
    name_t << "TurnOn_" << triggers[ii] << "_given_" << prefilters[ii] << "_" << vars[ii] << "_Bin" << htbins[ii] << "_all";
    TH1D* h_t = (d==0?0:(TH1D*)d->Get(name_t.str().c_str()));
    if (h_t) { std::cout << "Opened histo: " << h_t->GetName() << std::endl; }
    else { 
      std::cout << "Could not find histo " << name_t.str() << std::endl; 
      continue;
    }
    h_t->Rebin(rebin);

//     c1->cd(2);
//     TH1D* i_t = (h_t==0?0:(TH1D*)h_t->Clone());
//     if (i_t) calcIntegral(i_t,true);
//     i_t->Draw();
    
    std::stringstream name_g; 
    name_g << "Given_" << triggers[ii] << "_given_" << prefilters[ii] << "_" << vars[ii] << "_Bin" << htbins[ii] << "_all";
    TH1D* h_g = (d==0?0:(TH1D*)d->Get(name_g.str().c_str()));
    if (h_g) { std::cout << "Opened histo: " << h_g->GetName() << std::endl; }
    else { 
      std::cout << "Could not find histo " << name_g.str() << std::endl; 
      continue; 
    }
    h_g->Rebin(rebin);

    std::stringstream name_p; 
    name_p << "PreFilters_" << triggers[ii] << "_given_" << prefilters[ii] << "_" << vars[ii] << "_Bin" << htbins[ii] << "_all";
    TH1D* h_p = (d==0?0:(TH1D*)d->Get(name_p.str().c_str()));
    if (h_p) { std::cout << "Opened histo: " << h_p->GetName() << std::endl; }
    else { 
      std::cout << "Could not find histo " << name_p.str() << std::endl; 
      continue; 
    }
    h_p->Rebin(rebin);

    TH1D* h_e = 0;
    if ( h_g != 0 && h_p != 0 ) {
      h_e = (TH1D*)h_g->Clone();
      h_e->Divide(h_p);
    }
    if (h_e) { std::cout << "Opened histo: " << h_e->GetName() << std::endl; }
    else { 
      std::cout << "Could not find histo " << std::endl; 
      continue; 
    }

    double xhigh   = 1000.;
    double epsilon = 1000.;
    double mu      = 1000.;
    double sigma   = 1000.;
    if ( vars[ii] == "AlphaT" || vars[ii] == "MHToverHT" ) { 
      xhigh = 1.; 
    } else {
    }

//     double xmin = 200.;
//     double xmax = 500.;
//     double ymin = 0.;
//     double ymax = 0.;

//     c1->cd(1);
//     h_t->Draw();
//     c1->cd(2);
//     h_g->Draw();
//     c1->cd(3);
//     h_p->Draw();
//     c1->cd(4);
//     h_e->Fit("fermiFunction","R+");    
//     h_e->Draw();
    
    c2->cd();
    h_e->Draw();
    if ( vars[ii] == "HT" )        h_e->GetXaxis()->SetRangeUser(200.,700.);
    if ( vars[ii] == "MHT" )       h_e->GetXaxis()->SetRangeUser(0.,400.);
    if ( vars[ii] == "MHToverHT" ) h_e->GetXaxis()->SetRangeUser(0.0,0.7);
    if ( vars[ii] == "AlphaT" )    h_e->GetXaxis()->SetRangeUser(0.4,0.7);
    h_e->GetYaxis()->SetTitle("efficiency");
    h_e->GetYaxis()->SetRangeUser(-0.1,5.1);


    double max = h_e->GetXaxis()->GetXmax();
    double min = h_e->GetXaxis()->GetXmin();
    TF1 *fermiFunction = new TF1("fermiFunction",errorFunc,0.,max,3);
    Double_t params[3] = {1.,(max-min)/2.,(max-min)/10.};            
    fermiFunction->SetParameters(params);
    fermiFunction->SetParNames("#varepsilon","#mu","#sigma");
    fermiFunction->SetLineColor(2);
    fermiFunction->SetLineWidth(3);
    h_e->Fit("fermiFunction","R+");    

    c2->Update();
    TPaveStats* st = (TPaveStats*)h_e->FindObject("stats");
    if (st) {
      st->SetTextSize(0.04);
      st->SetX1NDC(st->GetX1NDC());
      st->SetX2NDC(st->GetX2NDC());
      st->SetY1NDC(st->GetY1NDC()-0.6);
      st->SetY2NDC(st->GetY2NDC()-0.5);
    }

    //legend->AddEntry( h_t, triggers[ii].c_str(), "pl" );

    c2->SaveAs(std::string(name_t.str()+".pdf").c_str()); 
    
  }
  
//   TGraphAsymmErrors* gr1 = new TGraphAsymmErrors();
//   if ( h[0] && h[1] ) gr1->BayesDivide(h[0],h[1]);
  
//   TGraphAsymmErrors* gr2 = new TGraphAsymmErrors();
//   if ( i[0] && i[1] ) gr2->BayesDivide(i[0],i[1]);
	  
//   c1->cd(1);
//   if ( h[0] && h[1] ) { 
//     h[0]->GetXaxis()->SetTitle("#alpha_{T}");
//     h[0]->SetLineColor(kRed);
//     h[0]->SetFillColor(kRed-10);
//     h[0]->GetXaxis()->SetRangeUser(0.,1.);
//     h[0]->Draw("");
//     h[1]->GetXaxis()->SetTitle("#alpha_{T}");
//     h[1]->GetXaxis()->SetRangeUser(0.,1.);
//     h[1]->Draw("sameP");
    
//     legend->SetTextSize(0.035);
//     //legend->SetFillColor(0);
//     //legend->SetLineColor(0); 
//     //legend->SetShadowColor(0); 
//     legend->Draw("same");
    
//   }

//   c1->cd(2);
//   if ( i[0] && i[1] ) { 
//     i[0]->GetXaxis()->SetTitle("#alpha_{T} > cut value");
//     i[0]->GetXaxis()->SetRangeUser(0.,1.);
//     i[0]->SetLineColor(kRed);
//     i[0]->SetFillColor(kRed-10);
//     i[0]->Draw("LF2");
//     i[1]->GetXaxis()->SetTitle("#alpha_{T} > cut value");
//     i[1]->GetXaxis()->SetRangeUser(0.,1.);
//     i[1]->Draw("sameP");

//     legend->SetTextSize(0.035);
//     legend->SetFillColor(0);
//     legend->SetLineColor(0); 
//     legend->SetShadowColor(0); 
//     legend->Draw("same");

//   }
  
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
  
}
