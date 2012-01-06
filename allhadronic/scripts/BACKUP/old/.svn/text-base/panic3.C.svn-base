#include <vector>

// -----------------------------------------------------------------------------
//  
TH1* his( TH1* input, Int_t nbins, Double_t xlow, Double_t xhigh ) {
  if ( !input ) { return 0; }
  TString name( TString( input->GetName() ) + "_Copy" );
  TH1F* output = new TH1F( name, "", input->GetNbinsX(), xlow, xhigh );
  for ( Int_t bin = 1; bin < input->GetNbinsX()+1; ++bin ) {
    Double_t centre = input->GetBinLowEdge(bin) + input->GetBinWidth(bin)/2.;
    if ( centre > xlow && 
	 centre < xhigh && 
	 input->GetBinContent(bin) > 0. ) {
      output->Fill( centre, input->GetBinContent(bin) );
    }
  }
  output->Sumw2();
  output->Rebin(Int_t(input->GetNbinsX()/nbins));
  return output;
}

// -----------------------------------------------------------------------------
// 
void calcRatio( int nfile, int nat, int npt, int nht, 
		int style, std::string his, std::string type, std::string files, 
		double at, double pt, double ht, double minht, double maxht, 
		double ratio, double error, double length ) {

  // Loop through data/MC files 
  for ( Int_t ifile = 0; ifile < nfile; ++ifile ) {
    
    // Open file
    TString name(files[ifile]);
    TFile* file = new TFile(name);
    if ( file->IsZombie() || !(file->IsOpen()) ) { continue; }
    file->cd();
    
    // Loop through bins of AlphaT
    for ( int iat = 0; iat < nat; ++iat ) {
      
      // Loop through bins of pT
      for ( int ipt = 0; ipt < npt; ++ipt ) {
	
	length[ifile][iat][ipt] = 0;

	// Directory and histo names
	std::stringstream dir;
	std::stringstream pre;
	std::stringstream post;
	dir << "Ratio" << at[iat];
	pre << dir.str() << "Pt" << pt[ipt] << ".0/" << his[ifile] << eq << "Pre" << "_" << multi;
	post << dir.str() << "Pt" << pt[ipt] << ".0/" << his[ifile] << eq << "Post" << "_" << multi;
	//std::cout << pre.str() << std::endl;
	//std::cout << post.str() << std::endl;
	
	// Create ratio histo
	TH1* denominator = his( (TH1*)file->Get(TString(pre.str())), nht, minht, maxht );
	TH1* numerator = his( (TH1*)file->Get(TString(post.str())), nht, minht, maxht );
 	TH1* ratio_his = (TH1*)numerator->Clone(TString(numerator->GetName())+"_Clone");
 	ratio_his->Divide(denominator);
 	//ratio_his->Divide(numerator,denominator,1.,1.,"b"); //@@ poisson errors
	
	// Loop through bins of HT
	for ( int iht = 0; iht < nht; ++iht ) {
	  
	  ratio[ifile][iat][ipt][iht] = ratio_his->GetBinContent(iht+1);
	  error[ifile][iat][ipt][iht] = ratio_his->GetBinError(iht+1);
	  
	  if ( ratio[ifile][iat][ipt][iht] > 0. ) { 
	    //std::cout << "ratio: " << ratio[ifile][iat][ipt][iht] << std::endl;
	    length[ifile][iat][ipt]++; 
	  }
	  
	} // HT

	if (numerator) { delete numerator; }
	if (denominator) { delete denominator; }

      } // pT
    } // aT

    if (file) {
      file->cd();
      file->Close();
      delete file;
    } 

  } // file

}

// -----------------------------------------------------------------------------
//  
int panic3() {

  // Misc
  int multi = 2;
  TString eq = "Non";

  gStyle->SetOptStat(0);

  // Files to open (MC, data)
  const int nfile = 3;
  int style[nfile] = { kOpenSquare, kFullCircle, kFullSquare };
  std::string his[nfile] = {"GenHt","Ht","Ht"};
  std::string type[nfile] = {"Truth","Data","MC"};
  std::string files[nfile] = {"results/Ratio_QCD_AllPtBins_7TeV_Pythia.root",
			      "results/Ratio_JetMET_ALL_upto230810.root",
			      "results/Ratio_QCD_AllPtBins_7TeV_Pythia.root"};
  
  // AlphaT binning
  const int nat = 8;
  int at[nat] = { 500, 505, 510, 515, 520, 530, 540, 550 };

  // pT binning
  const int npt = 2;
  float pt[npt] = { 50., 30. };

  // HT binning
  const int nht = 10;
  const double minht = 200;
  const double maxht = 700;
  double ht[nht];
  for ( int ii = 0; ii < nht; ++ii ) { ht[ii] = minht + ii * ((maxht-minht)/nht); }

  // Ratio and x3
  double ratio[nfile][nat][npt][nht];
  double error[nfile][nat][npt][nht];
  double length[nfile][nat][npt];
  
  calcRatio( nfile, nat, npt, nht, 
	     style, his, type, files, 
	     at, pt, ht, minht, maxht,
	     ratio, error, length );
  
  // -----------------------------------------------------------------------------
  // R(aT) vs HT for different pT bins
  if (false) {

    // Max and min for y-axis
    double min[nat];
    double max[nat];
    for ( int iat = 0; iat < nat; ++iat ) {
      min[iat] = 1.e12;
      max[iat] = 1.e-12;
      for ( int ifile = 0; ifile < nfile; ++ifile ) {
	for ( int ipt = 0; ipt < npt; ++ipt ) {
	  for ( int iht = 0; iht < nht; ++iht ) {
	    if ( ratio[ifile][iat][ipt][iht] > 0. &&
		 ratio[ifile][iat][ipt][iht] < min[iat] ) {
	      min[iat] = ratio[ifile][iat][ipt][iht];
	    }
	    if ( ratio[ifile][iat][ipt][iht] > 0. &&
		 ratio[ifile][iat][ipt][iht] > max[iat] ) {
	      max[iat] = ratio[ifile][iat][ipt][iht];
	    }
	  }
	}
      }
      std::cout << " iat: " << iat 
		<< " min: " << min[iat]
		<< " max: " << max[iat]
		<< std::endl;
    }
    
    // Scale MC to data using first bin
    int data_file = 1;
    bool anchor = true;
    double scale[nfile][nat][npt];
    for ( int ifile = 0; ifile < nfile; ++ifile ) {
      for ( int iat = 0; iat < nat; ++iat ) {
	for ( int ipt = 0; ipt < npt; ++ipt ) {
	  scale[ifile][iat][ipt] = 1.;
	  double data = ratio[data_file][iat][ipt][0];
	  double other = ratio[ifile][iat][ipt][0];
	  if ( other > 0. ) { scale[ifile][iat][ipt] = data/other; }
	}
      }
    }
    
    // Create plots
    for ( int iat = 0; iat < nat; ++iat ) {

      std::stringstream ss_canvas;
      ss_canvas << "AlphaT" << at[iat]/1000.;
      
      TCanvas* canvas = new TCanvas(TString("RatioVsHT_"+ss_canvas.str()),
				    TString("RatioVsHT_"+ss_canvas.str()));
      canvas->SetFillColor(0);
      canvas->SetLineColor(0); 
      canvas->SetLogy();
      canvas->SetRightMargin(0.2);
      
      TLegend* legend = new TLegend( 0.82, 0.5, 0.98, 0.9, NULL, "brNDC" );
      legend->SetFillColor(0);
      legend->SetLineColor(0); 
      legend->SetShadowColor(0); 
    
      for ( int ifile = 0; ifile < nfile; ++ifile ) {
	for ( int ipt = 0; ipt < npt; ++ipt ) {

	  std::stringstream ss_histo;
	  ss_histo << "RatioVsHt_" << type[ifile] << "_AlphaT" << at[iat]/1000. << "_Pt" << pt[ipt];
 	  TH1D* histo = new TH1D(TString(ss_histo.str()),"",nht,minht,maxht);
	  
 	  for ( int iht = 0; iht < nht; ++iht ) {
 	    if (anchor) { histo->SetBinContent(iht+1,ratio[ifile][iat][ipt][iht]*scale[ifile][iat][ipt]); }
	    else { histo->SetBinContent(iht+1,ratio[ifile][iat][ipt][iht]); }
 	    histo->SetBinError(iht+1,error[ifile][iat][ipt][iht]);
 	  }

	  std::stringstream ss_axis;
	  ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")";
	  
 	  histo->GetYaxis()->SetRangeUser(min[iat]/2.,max[iat]*2.);
 	  histo->GetXaxis()->SetTitle("HT_{reco} [GeV]");
 	  histo->GetYaxis()->SetTitle(TString(ss_axis.str()));
 	  histo->SetMarkerStyle(style[ifile]);
 	  //histo->SetMarkerSize(1.5);
 	  histo->SetMarkerColor(ipt+1);
 	  //histo->SetBarOffset(10.*ipt);
	  
 	  if ( ifile == 0 && ipt == 0 ) { histo->Draw(""); }
 	  else { histo->Draw("same"); }
	  
	  std::stringstream ss_legend;
	  ss_legend << type[ifile] << " p_{T}^{min} = " << pt[ipt];
	  legend->AddEntry( histo, TString(ss_legend.str()), "lep" );
	  
	}
      }

      legend->Draw("same");
      canvas->Update();

      std::stringstream ss_text;
      ss_text << "#alpha_{T} = " << at[iat]/1000.;
      
      TLatex* text = new TLatex(0.5,0.92,TString(ss_text.str()));
      text->SetNDC(kTRUE);
      text->SetTextSize(0.04);
      //text->Draw();

      canvas->SaveAs(TString("RatioVsHT_"+ss_canvas.str()+".png")); 

    }
    
  }

  // -----------------------------------------------------------------------------
  // R(aT) vs X3 for different AlphaT bins
  else {

    // Max and min for y-axis
    double min[nat];
    double max[nat];
    for ( int iat = 0; iat < nat; ++iat ) {
      min[iat] = 1.e12;
      max[iat] = 1.e-12;
      for ( int ifile = 0; ifile < nfile; ++ifile ) {
	for ( int ipt = 0; ipt < npt; ++ipt ) {
	  for ( int iht = 0; iht < nht; ++iht ) {
	    if ( ratio[ifile][iat][ipt][iht] > 0. &&
		 ratio[ifile][iat][ipt][iht] < min[iat] ) {
	      min[iat] = ratio[ifile][iat][ipt][iht];
	    }
	    if ( ratio[ifile][iat][ipt][iht] > 0. &&
		 ratio[ifile][iat][ipt][iht] > max[iat] ) {
	      max[iat] = ratio[ifile][iat][ipt][iht];
	    }
	  }
	}
      }
    }

    // Max x3 bin
    int data_file = 1;
    double x3_max[nat][npt];
    int x3_ipt[nat][npt];
    int x3_iht[nat][npt];
    for ( int iat = 0; iat < nat; ++iat ) {
      for ( int ipt = 0; ipt < npt; ++ipt ) {
	x3_max[iat][ipt] = 1.e-12;
	x3_ipt[iat][ipt] = -1;
	x3_iht[iat][ipt] = -1;
	for ( int iht = 0; iht < nht; ++iht ) {
	  double tmp = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	  if ( tmp > x3_max[iat][ipt] ) {
	    x3_max[iat][ipt] = tmp;
	    x3_ipt[iat][ipt] = ipt;
	    x3_iht[iat][ipt] = iht;
	  }
	}
	std::cout << " iat: " << iat
		  << " ipt: " << ipt
		  << " x3_max: " << x3_max[iat][ipt]
		  << " x3_ipt: " << x3_ipt[iat][ipt]
		  << " x3_iht: " << x3_iht[iat][ipt]
		  << std::endl;
      }
    }

    // Scale MC to data using bin with highest x3 value
    bool anchor = true;
    double scale[nfile][nat][npt];
    for ( int ifile = 0; ifile < nfile; ++ifile ) {
      for ( int iat = 0; iat < nat; ++iat ) {
	for ( int ipt = 0; ipt < npt; ++ipt ) {
	  scale[ifile][iat][ipt] = 1.;
	  if ( x3_ipt[iat][ipt] > -1 && 
	       x3_iht[iat][ipt] > -1 ) {
	    double data = ratio[data_file][iat][x3_ipt[iat][ipt]][x3_iht[iat][ipt]];
	    double other = ratio[ifile][iat][x3_ipt[iat][ipt]][x3_iht[iat][ipt]];
	    if ( other > 0. ) { scale[ifile][iat][ipt] = data/other; }
	  }
	  std::cout << " ifile: " << ifile
		    << " iat: " << iat
		    << " ipt: " << ipt
		    << " scale: " << scale[ifile][iat][ipt]
		    << std::endl;
	}
      }
    }

    for ( int iat = 0; iat < nat; ++iat ) {

      std::stringstream ss_canvas;
      ss_canvas << "AlphaT" << at[iat]/1000.;
      
      TCanvas* canvas = new TCanvas(TString("RatioVsX3_"+ss_canvas.str()),
				    TString("RatioVsX3_"+ss_canvas.str()));
      canvas->SetFillColor(0);
      canvas->SetLineColor(0); 
      canvas->SetLogy();
      canvas->SetRightMargin(0.2);

      TLegend* legend = new TLegend( 0.82, 0.5, 0.98, 0.9, NULL, "brNDC" );
      legend->SetFillColor(0);
      legend->SetLineColor(0); 
      legend->SetShadowColor(0); 
      
      TMultiGraph* mg = new TMultiGraph();

      for ( int ifile = 0; ifile < nfile; ++ifile ) {

	for ( int ipt = 0; ipt < npt; ++ipt ) {

	  double val[nht];
	  double ex[nht];
	  double ey[nht];
	  double x3[nht];
 	  for ( int iht = 0; iht < nht; ++iht ) {
	    if (anchor) { val[iht] = ratio[ifile][iat][ipt][iht]*scale[ifile][iat][ipt]; }
	    else { val[iht] = ratio[ifile][iat][ipt][iht]; }
	    x3[iht] = ( 2. * pt[ipt] ) / ( ht[iht] + pt[ipt] );
	    ex[iht] = 0.;
	    ey[iht] = error[ifile][iat][ipt][iht];
 	  }

	  std::stringstream ss_legend;
	  ss_legend << type[ifile] << " p_{T}^{min} = " << pt[ipt];
	  
	  TGraphErrors* gr = new TGraphErrors(length[ifile][iat][ipt],x3,val,ex,ey);
	  mg->Add(gr,"p");
	  gr->SetTitle(TString(ss_legend.str()));
	  gr->SetLineColor(1+ipt);
	  gr->SetMarkerStyle(style[ifile]);
	  gr->SetMarkerColor(1+ipt);
	  legend->AddEntry( gr, TString(ss_legend.str()), "lep" );

	}
      }

      std::stringstream ss_axis;
      ss_axis << "R(#alpha_{T}=" << at[iat]/1000. << ")";

      mg->Draw("a");
      mg->GetXaxis()->SetTitle("x_{3}");
      mg->GetYaxis()->SetTitle(TString(ss_axis.str()));
      mg->GetYaxis()->SetRangeUser(min[iat]/2.,max[iat]*2.);
      canvas->Update();
      //TLegend* legend = canvas->BuildLegend(0.8,0.5,0.99,0.9);
      //legend->SetFillColor(0);
      //legend->SetLineColor(0); 
      //legend->SetShadowColor(0); 

      legend->Draw("same");
      canvas->Update();

      canvas->SaveAs(TString("RatioVsX3_"+ss_canvas.str()+".png")); 

    }
    
  }

}

