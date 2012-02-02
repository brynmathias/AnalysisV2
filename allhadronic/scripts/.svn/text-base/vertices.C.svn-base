#include "common/overlay.C"

// -----------------------------------------------------------------------------
int vertices() {
  
  setTDRStyle();
  
  TFile* output_file = new TFile( "Plots.root", "RECREATE" );
  if ( !output_file || output_file->IsZombie() ) { return -1; }

  TCanvas* c1 = 0;
  TCanvas* c2 = 0;

  std::vector<std::string> names;
//   names.push_back("NumVertex_HT0_all");
//   names.push_back("NumVertex_HT275_all");
//   names.push_back("NumVertex_HT325_all");
//   names.push_back("NumVertex_HT375_all");
//   names.push_back("NumVertex_HT475_all");
//   names.push_back("NumVertex_HT575_all");
//   names.push_back("NumVertex_HT675_all");
//   names.push_back("NumVertex_HT775_all");
//   names.push_back("NumVertex_HT875_all");

//   names.push_back("NumVertex_Meff0aT0.501_all");
//   names.push_back("NumVertex_Meff420aT0.501_all");
//   names.push_back("NumVertex_Meff560aT0.501_all");
//   names.push_back("NumVertex_Meff700aT0.501_all");
//   names.push_back("NumVertex_Meff840aT0.501_all");
//   names.push_back("NumVertex_Meff997.9aT0.501_all");
//   names.push_back("NumVertex_Meff1120aT0.501_all");
//   names.push_back("NumVertex_Meff1400aT0.501_all");
//   names.push_back("NumVertex_Meff1260aT0.501_all");


  std::vector<std::string> bins;
  bins.push_back("0");
  bins.push_back("200");
  bins.push_back("300");
  bins.push_back("400");
  bins.push_back("500");
  bins.push_back("600");
  bins.push_back("700");
  bins.push_back("800");
  bins.push_back("900");
  bins.push_back("1000");
  bins.push_back("1100");
  bins.push_back("1200");
  
//   bins.push_back("0");
//   bins.push_back("275");
//   bins.push_back("325");
//   bins.push_back("375");
//   bins.push_back("475");
//   bins.push_back("575");
//   bins.push_back("675");
//   bins.push_back("775");
//   bins.push_back("875");
//   bins.push_back("975");

  std::string dir = "/vols/cms02/bainbrid/qcd/latest/SUSY2/results/v86/";
  
//    std::string var = "Multiplicity";  // DistrAfterAlphaT NumVertex AlphaT BabyJetsMht MeffDistr JetsBabyPt MeffDistr
//    std::string atcut = "_aT0";
//    std::string njets = "";

  std::string var = "AlphaT";  // DistrAfterAlphaT NumVertex  BabyJetsMht MeffDistr JetsBabyPt MeffDistr
  std::string atcut = "";
  std::string njets = "_2";
  
  bool log = false;
  bool norm = true;
  int rebin = 1;
  int integral = -1;
  
  std::string binvar = "Meff";//"HT"; 
  std::string binnice = "M_{eff}";//"H_{T}"; 

//   std::string binvar = "HT"; 
//   std::string binnice = "H_{T}"; 
  
  for ( int i = 0; i < bins.size()-1; ++i ) {
    names.push_back(var+"_"+binvar+bins[i]+atcut+njets);
  }

//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
//   names.push_back(var+"DistrAfterAlphaT_Meff_aT"+atcut+"_"+njets);
  
  // -----------------------------------------------------------------------------
  // Data

  if (0) {
    
    std::string file(dir+"Ratio__data.root");
    //std::string file("../python/Ratio_Data.root");
    
    std::vector<std::string> files, titles;
    std::vector<int> marker_style; 
    std::vector<int> marker_colour; 
    std::vector<float> marker_size; 
    std::vector<float> lumis; 

    files.push_back(file);
    titles.push_back("H_{T} > 275");
    files.push_back(file);
    titles.push_back("275 < H_{T} #leq 325");
    files.push_back(file);
    titles.push_back("325 < H_{T} #leq 375");
    files.push_back(file);
    titles.push_back("375 < H_{T} #leq 475");
    //titles.push_back("H_{T} > 375");
    files.push_back(file);
    titles.push_back("475 < H_{T} #leq 575");
    //titles.push_back("H_{T} > 475");
    files.push_back(file);
    titles.push_back("575 < H_{T} #leq 675");
    files.push_back(file);
    titles.push_back("675 < H_{T} #leq 775");
    files.push_back(file);
    titles.push_back("775 < H_{T} #leq 875");
    files.push_back(file);
    titles.push_back("H_{T} > 875");
    
    marker_style.push_back(20);
    marker_style.resize(files.size(),24);

    marker_colour.push_back(1);
    for ( int ii = 1; ii < files.size(); ++ii ) { marker_colour.push_back(kRed-9+ii); }
    
    marker_size.push_back(1.);
    for ( int ii = 1; ii < files.size(); ++ii ) { marker_size.push_back(1.+0.25*ii); }
    
    lumis.resize(files.size(),100.);
    
    c1 = createPlot( output_file,
		     "Data_NumVertices", 
		     files, 
		     names, 
		     titles, 
		     marker_style, 
		     marker_colour, 
		     marker_size, 
		     lumis,
		     2720., 
		     rebin, // rebin 
		     norm,  // normalise
		     log,   // log
		     -1.,   // min
		     -1.,   // max
		     integral );   // integrate from Nth bin
    
  }
  
  // -----------------------------------------------------------------------------
  // SM
  
  if (1) {
        
    std::vector<std::string> files, titles;
    std::vector<int> marker_style; 
    std::vector<int> marker_colour; 
    std::vector<float> marker_size; 
    std::vector<float> lumis; 

    std::string file(dir+"Ratio__qcdpy.root");
    for ( int i = 0; i < bins.size()-1; ++i ) { files.push_back(file); }
    
    titles.push_back(binnice+" > "+bins[1]); 
    for ( int ii = 1; ii < bins.size()-2; ++ii ) {
      if ( integral < 0 || ii < integral ) { 
	titles.push_back(bins[ii]+" < "+binnice+" #leq "+bins[ii+1]);
      } //else { titles.push_back(binnice+" > "+bins[ii]); }
    }
    titles.push_back(binnice+" > "+bins[titles.size()]); 
    //titles.push_back(binnice+" > "+bins[bins.size()-2]); 
    
    marker_style.push_back(20);
    marker_style.resize(files.size(),24);

    marker_colour.push_back(1);
    for ( int ii = 1; ii < files.size(); ++ii ) { marker_colour.push_back(kRed-9+ii); }
    
    marker_size.push_back(1.);
    for ( int ii = 1; ii < files.size(); ++ii ) { marker_size.push_back(1.+0.25*ii); }
    
    lumis.resize(files.size(),2720.);
    
    c2 = createPlot( output_file,
		     "SM_NumVertices", 
		     files, 
		     names, 
		     titles, 
		     marker_style, 
		     marker_colour, 
		     marker_size, 
		     lumis,
		     2720., 
		     rebin, // rebin 
		     norm,  // normalise
		     log,   // log
		     -1.,   // min
		     -1.,   // max
		     integral );   // integrate from Nth bin
    
  }

  // Vertex reweighting factors

  if ( c1 && c2 ) {
    
    std::vector<TH1F*> h3;
    std::vector<TH1F*> h4;
    for ( int ii = 0; ii <= 8; ++ii ) {
      TH1F* h1 = (TH1F*)c1->GetPrimitive( names[ii].c_str() ); //h1->Sumw2();
      TH1F* h2 = (TH1F*)c2->GetPrimitive( names[ii].c_str() ); //h2->Sumw2();
      if ( integral < 0 || ii <= integral ) { 
 	h3.push_back( new TH1F( *h1 ) ); //h3.back()->Sumw2();
 	h4.push_back( new TH1F( *h2 ) ); //h4.back()->Sumw2();
      }
      h3.back()->Add(h1);
      h4.back()->Add(h2);
    }
    
    std::stringstream ss;
    ss << "VertexWeights = [" << std::endl;

    //std::vector<TH1F*> h5;
    for ( int ii = 0; ii < h3.size(); ++ii ) {
      
       for ( int jj = 0; jj < h3[ii]->GetNbinsX(); ++jj ) {

  	double f1 = h3[ii]->GetBinContent(jj+1);
  	double e1 = h3[ii]->GetBinError(jj+1);

  	double f2 = h4[ii]->GetBinContent(jj+1);
  	double e2 = h4[ii]->GetBinError(jj+1);

 	double f3 = f2 > 0. ? f1/f2 : 1.;
 	double e3 = f3 > 0. ? f3*sqrt( (f1>0.?e1/f1:0.)*(f1>0.?e1/f1:0.) + (f2>0.?e2/f2:0.)*(f2>0.?e2/f2:0.) ) : 0.;
 	double s3 = e3 > 0. ? fabs(f3-1.)/e3 : 10.;
	
 	ss << std::setprecision(2) << std::fixed << s3 << ",";
	
	//his1->Fill(f1>0.?e1/f1:0.,1.);
	//his2->Fill(f2>0.?e2/f2:0.,1.);
	//his3->Fill(f3>0.?e3/f3:0.,1.);
	
 	//std::cout << "test " << f3 << " " << e3 << " " << r3;
 	//if ( fabs(r3) > 1. ) { f3 = 1.; e3 = 0.; }
 	//std::cout << " " << f3 << " " << e3 << " " << std::endl;
	//h5.push_back( new TH1F(*h3[ii]) );
	//h5.back()->SetBinContent(jj+1,f3);
	//h5.back()->SetBinError(jj+1,e3);
 	//ss << std::setprecision(2) << std::fixed << (f3>0.?e3/f3:-1.) << ",";

       }

       ss << "-1.00," << std::endl;

    }
    
    ss << "\t]";
    std::cout << ss.str() << std::endl;
    
    //his1->Draw();
    //his2->Draw();
    //his3->Draw();
      
    //h3.front()->Draw();
      
    //TCanvas* c3 = createCanvas("VertexFactors",output_file,false);
    //c3->cd();
    //for ( int ii = 0; ii < h3.size(); ++ii ) {
    //if ( ii == 0 ) { h3[ii]->Draw(); } 
    //else { h3[ii]->Draw("same"); }
    //}
    
  } else {
    std::cout << "Problem with c1 or c2!" << std::endl;
  }
  
  output_file->Write();
  output_file->Close();
  delete output_file; 

  return 0;

}


