#include "./common/style.C"
#include <string.h>
#include "TCanvas.h"
#include "TFile.h"
#include "TH2D.h"
#include "TLatex.h"
#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

//-----------------------------------------------------------------------------
//
int compare( const char* wild, const char* string ) {
  
  const char *cp = NULL, *mp = NULL;
  
  while ((*string) && (*wild != '*')) {
    if ((*wild != *string) && (*wild != '?')) {
      return 0;
    }
    wild++;
    string++;
  }
  
  while (*string) {
    if (*wild == '*') {
      if (!*++wild) {
        return 1;
      }
      mp = wild;
      cp = string+1;
    } else if ((*wild == *string) || (*wild == '?')) {
      wild++;
      string++;
    } else {
      wild = mp;
      string = cp++;
    }
  }
  
  while (*wild == '*') {
    wild++;
  }
  return !*wild;

}

//-----------------------------------------------------------------------------
//
void trigger_hadd() {

  // in an interactive ROOT session, edit the file names
  // Target and FileList, then
  // root > .L hadd.C
  // root > hadd()
  
  double lumi = 2720.;
  
  int run_min = 161217;
  int run_max = -1;
  
  //std::string file_name("Trigger_HT42_incomplete");
  //std::string file_name("Trigger_HT_Run2011A_L1OffSet");
  //std::string file_name("Trigger_HT_Run2011A_AllReco_17June");
  //std::string file_name("Trigger_HT_Run2011A");
  //std::string file_name("Trigger_HT_Run2011A_1fb");
  //std::string file_name("Trigger_HTRun2011AB_Complete");
  std::string file_name("Trigger_HTRun2011AB");
  
  std::string dir_name("Triggers");
  std::string his_name = "TriggersVsRunNumber";
  
  std::vector<std::string> filters;

//    filters.push_back("HLT_HT25?_MHT??_v*");
//    //filters.push_back("HLT_HT26?_MHT??_v*");
//    filters.push_back("HLT_HT3??_MHT??_v*");
//    filters.push_back("HLT_HT4??_MHT??_v*");
//    filters.push_back("HLT_HT5??_MHT??_v*");
  
//    filters.push_back("HLT_HT25?_AlphaT0p??_v*");
//   //filters.push_back("HLT_HT26?_AlphaT0p??_v*");
   filters.push_back("HLT_HT3??_AlphaT0p??_v*");
   filters.push_back("HLT_HT4??_AlphaT0p??_v*");
   filters.push_back("HLT_HT5??_AlphaT0p??_v*");

//   //filters.push_back("HLT_HT1??_v*");
//   //filters.push_back("HLT_HT2??_v*");
//   filters.push_back("HLT_HT25?_v*");
//   //filters.push_back("HLT_HT26?_v*");
//   filters.push_back("HLT_HT3??_v*");
//   filters.push_back("HLT_HT4??_v*");
//   filters.push_back("HLT_HT5??_v*");
//   filters.push_back("HLT_HT6??_v*");
//   filters.push_back("HLT_HT7??_v*");
//   filters.push_back("HLT_HT8??_v*");
//   filters.push_back("HLT_HT9??_v*");
//   filters.push_back("HLT_HT9??_v*");
//   filters.push_back("HLT_HT1???_v*");

//   filters.push_back("HLT_Mu?_HT???_v*");
//   filters.push_back("HLT_Mu??_HT???_v*");

  
  typedef std::map<int,float> Runs;
  typedef std::map<std::string,Runs> Triggers;
  Triggers trigs;
  std::vector<int> runs;
  
  for ( int ii = 0; ii < 1000; ++ii ) {
    
    // Construct file name
    std::stringstream ss;
    ss << "./" << file_name << "_" << ii << ".root";
    
    // Attempt to open file
    TFile* file = new TFile(ss.str().c_str());
    if ( file->IsZombie() || !(file->IsOpen()) ) { 
      if (file) { delete file; }
      std::cout << "Could not find file: " << ss.str() << std::endl; 
      continue; 
    } else {
      file->cd();
      std::cout << "Opened file: " << file->GetName() << std::endl; 
    }
    
    TDirectory* dir = (TDirectory*)file->Get(dir_name.c_str());
    if (dir) { std::cout << "Opened dir: " << dir->GetName() << std::endl; }
    else { 
      std::cout << "Could not find dir: " << dir_name << std::endl; 
      return; 
    }
    
    TH2D* his = (TH2D*)dir->Get(his_name.c_str());
    if (his) { std::cout << "Opened histo: " << his->GetName() << std::endl; }
    else { 
      std::cout << "Could not find histo: " << his_name << std::endl; 
      return; 
    }

    // Loop through x-bins 
    for ( int xbin = 0; xbin < his->GetNbinsX(); ++xbin ) {
      
      // Retrieve trigger name (and its prescale) from x-bin label
      std::string trigger = his->GetXaxis()->GetBinLabel(xbin+1);

      // Check if trigger passes the filter 
      std::vector<std::string>::const_iterator ifilter = filters.begin();
      std::vector<std::string>::const_iterator jfilter = filters.end();
      for ( ; ifilter != jfilter; ++ifilter ) {
	if ( compare( ifilter->c_str(), trigger.c_str() ) ) { break; }
      }
      if ( ifilter == jfilter ) { continue; }
      
      // Loop through y-bins (prescale values)
      for ( int ybin = 0; ybin < his->GetNbinsY(); ++ybin ) {
	
	// Check for non-zero content
	double weight = his->GetBinContent(xbin+1,ybin+1);
	if ( weight == 0. ) { continue; }
	
	// Retrieve prescale value (or run number from y-bin label)
	int yval = (int)his->GetYaxis()->GetBinLowEdge(ybin+1);
	yval = atoi(his->GetYaxis()->GetBinLabel(ybin+1));

	// Limit run range
	if ( ( run_min < 0 || yval >= run_min ) &&
	     ( run_max < 0 || yval <= run_max ) ) {
	  
	  // Cache runs used	
	  if ( weight > 0 ) { 
	    if ( find( runs.begin(), runs.end(), yval ) == runs.end() ) { runs.push_back( yval ); }
	  }
	
	  //trigger = ( trigger.size() > 3 ? std::string(trigger.substr(0,trigger.size()-3)) : "" );
	  
	  // Populate map with histogram contents
	  Triggers::const_iterator iter = trigs.find( trigger );
	  if ( iter == trigs.end() ) {
	    // If trigger name not found
	    trigs[trigger][yval] = weight;
	  } else {
	    if ( iter->second.find(yval) == iter->second.end() ) {
	      // If trigger name found but prescale not found
	      trigs[trigger][yval] = weight;
	    }
	  }
	  
	}
	
      } // y-bins
    } // x-bins

    if (file) {
      file->Close();
      delete file;
    }

  } // files

  // Open new file to save triggers and prescales
  std::stringstream sss;
  sss << file_name << ".root";
  TFile* file = new TFile(sss.str().c_str(),"RECREATE");
  if ( file->IsZombie() || !(file->IsOpen()) ) { 
    if (file) { delete file; }
    std::cout << "Could not create file: " << sss.str() << std::endl; 
    return; 
  } else {
    file->cd();
    std::cout << "Opened file: " << file->GetName() << std::endl; 
  }

  // Create new dir
  TDirectory* dir = file->mkdir("Triggers");
  dir->cd();

  // Create histogram
  TH2D* his = new TH2D( "Triggers", 
			";Run number;",
			10000, 0., 10000.,
			trigs.size(), 0., trigs.size()
			);
  his->GetXaxis()->Set( runs.size(), 0., runs.size() );
  his->Sumw2();


  // Cache info
  std::string last_trigger = "None";
  std::string last_version = "None";
  std::vector<int> indices;

  // -----------------------------------------------------------------------------
  // Print some debug  
  std::stringstream ss;
  ss << " List of " << trigs.size()
     << " triggers that fired"
     << std::endl;
  Triggers::const_reverse_iterator ii = trigs.rbegin();
  Triggers::const_reverse_iterator jj = trigs.rend();
  for ( ; ii != jj; ++ii ) {
    ss << " Trigger \"" << ii->first << "\""
       << std::endl;
    
    std::string curr_trigger = ii->first.substr( 0, ii->first.find("_v") );
    std::string curr_version = ii->first.substr( ii->first.find("_v") );
    if ( last_trigger == "None" || 
	 ( curr_trigger != last_trigger ||
	   curr_version != last_version ) ) { 
      int tmp = ii->second.empty() ? 0 : ii->second.begin()->first;
      if ( tmp && find( indices.begin(), indices.end(), tmp ) == indices.end() ) { 
	indices.push_back(tmp); 
      }
    }
    last_trigger = curr_trigger;
    last_version = curr_version;
    
    Runs::const_iterator iii = ii->second.begin();
    Runs::const_iterator jjj = ii->second.end();
    for ( ; iii != jjj; ++iii ) {
      std::stringstream run; run << iii->first << std::endl;
      his->Fill(run.str().c_str(),ii->first.substr(4).c_str(),iii->second*1.);
      ss << "  Run number: " 
	 << iii->first
	 << " Events: " << iii->second
	 << std::endl;
    }    
  }
  std::cout << ss.str() << std::endl;
  
  // Print Trigger list for PSet
  std::stringstream ssss;
  ssss << " Triggers = [" << std::endl;
  Triggers::const_iterator iiii = trigs.begin();
  Triggers::const_iterator jjjj = trigs.end();
  for ( iiii = trigs.begin(); iiii != jjjj; ++iiii ) {
    ssss << "\"" << iiii->first << "\"," << std::endl;
  }
  ssss << "],";
  std::cout << ssss.str() << std::endl;
  
  // -----------------------------------------------------------------------------
  // Set labels 
  his->GetXaxis()->LabelsOption("a");
  for ( int index = 2; index < his->GetNbinsX(); ++index ) {
    int tmp = atoi(his->GetXaxis()->GetBinLabel( index ));
    if ( find( indices.begin(), indices.end(), tmp ) == indices.end() ) { 
      his->GetXaxis()->SetBinLabel( index, "" );
    }
  }

  // -----------------------------------------------------------------------------
  // Draw with some cosmetics
  setTDRStyle();
  set_plot_style();
  //int size = 600;
  TCanvas* canvas = new TCanvas("Triggers","Triggers");//,size,size);
  canvas->SetLeftMargin(0.25);
  canvas->SetRightMargin(0.2);
  canvas->SetBottomMargin(0.12);
//   canvas->SetLeftMargin(0.15);
//   canvas->SetRightMargin(0.2);
//   canvas->SetBottomMargin(0.3);
  his->Draw("COLZ");
  his->GetZaxis()->SetRangeUser(1.,10000.);
  his->GetXaxis()->SetTitleOffset(1.4);
  his->GetXaxis()->SetNoExponent();
  his->GetXaxis()->SetLabelSize(0.03);
  his->GetYaxis()->SetLabelSize(0.03);
  
  double max = pow( 10., int( log10(his->GetMaximum())*10. + 0.5 )/10. );
  his->GetZaxis()->SetTitle("Prescale");
  his->GetZaxis()->SetTitleOffset(1.5);
  his->GetZaxis()->SetRangeUser(0.,max);
  gStyle->SetOptStat(0);
  //gStyle->SetPalette(1);
  canvas->SetLogz();
  
  TLatex* prelim = new TLatex( 0.25, 0.96, "#scale[0.8]{CMS 2011 preliminary}" );
  prelim->SetTextSize(0.025);
  prelim->SetNDC();
  
  std::stringstream ss1; ss1 << "#int L dt = " << std::setprecision(3) << lumi/1000. << " fb^{-1}, #sqrt{s} = 7 TeV";
  TLatex* lumis = new TLatex( 0.8, 0.96, ss1.str().c_str() );
  lumis->SetTextAlign(32);
  lumis->SetTextSize(0.020);
  lumis->SetNDC();
  
  prelim->Draw("same");
  lumis->Draw("same");
  canvas->Modified();
  canvas->SaveAs( std::string(file_name+".pdf").c_str() );
  //canvas->SaveAs( std::string(file_name+".C").c_str() );
  canvas->Write();

//   // Write histo to file and close
//   his->Write();
//   if (file) {
//     file->Close();
//     delete file;
//   }
  
}
