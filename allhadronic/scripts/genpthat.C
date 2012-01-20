#include "common/overlay.C"

// -----------------------------------------------------------------------------
int genpthat() {
  
  setTDRStyle();
  
  TFile* output_file = new TFile( "Plots.root", "RECREATE" );
  if ( !output_file || output_file->IsZombie() ) { return -1; }

  bool log = true;
  bool norm = false;
  int rebin = 1;
  int integral = -1;
  std::string binnice = "#hat{p_{T}}";

  std::string dir = "/vols/cms02/bainbrid/qcd/stable/SUSY2/results/v07/";

  std::vector<std::string> bins;
  bins.push_back("15");
  bins.push_back("30");
  bins.push_back("50");
  bins.push_back("80");
  bins.push_back("120");
  bins.push_back("170");
  bins.push_back("300");
  bins.push_back("470");
  bins.push_back("600");
  bins.push_back("800");
  bins.push_back("1000");
  bins.push_back("1400");
  bins.push_back("1800");
  
  std::vector<std::string> names;
  for ( int i = 0; i < bins.size(); ++i ) {
    names.push_back("GenPtHat");
  }
  
  std::vector<std::string> files;
  for ( int ii = 0; ii < bins.size(); ++ii ) {
    string ss = "";
    if ( ii == bins.size()-1 ) { ss = "TEST_QCD_Pt_"+bins[ii]+".root"; }
    else { ss = "TEST_QCD_Pt_"+bins[ii]+"to"+bins[ii+1]+".root"; }
    files.push_back(dir+ss);
  }
  
  std::vector<std::string> titles;
//   titles.resize(bins.size());
//   copy( bins.begin(), bins.end(), titles.begin() );
  for ( int ii = 0; ii < bins.size(); ++ii ) {
    if ( ii == bins.size()-1 ) { titles.push_back(binnice+" > "+bins[ii]); }
    else { titles.push_back(bins[ii]+" < "+binnice+" < "+bins[ii+1]); }
  }
  
  std::vector<int> marker_style; 
  marker_style.resize(files.size(),24);

  std::vector<int> marker_colour; 
  for ( int ii = 1; ii < files.size(); ++ii ) { marker_colour.push_back(kRed-9+ii); }

  std::vector<float> marker_size; 
  for ( int ii = 1; ii < files.size(); ++ii ) { marker_size.push_back(1.+0.25*ii); }

  std::vector<float> lumis; 
  lumis.resize(files.size(),4600.);

  TCanvas* c2 = createPlot( output_file,
			    "GenPtHat", 
			    files, 
			    names, 
			    titles, 
			    marker_style, 
			    marker_colour, 
			    marker_size, 
			    lumis,
			    4600., 
			    rebin, // rebin 
			    norm,  // normalise
			    log,   // log
			    -1.,   // min
			    -1.,   // max
			    integral );   // integrate from Nth bin
  
  output_file->Write();
  output_file->Close();
  delete output_file; 

  return 0;

}


