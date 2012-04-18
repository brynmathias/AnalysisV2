/*! \file PlottingBase.cc
 * \brief File containing implementation of the Plotting operation base class.
 */

#include "PlottingBase.hh"
#include "TDirectory.h"

PlottingBase::PlottingBase() {}

void PlottingBase::initDir(TDirectory* aFileOut, const char* folderName) {
  aFileOut->cd();
  TDirectory * mydir = aFileOut->mkdir(folderName, folderName);
  mydir->cd();
}

TDirectory* PlottingBase::returnDir(TDirectory* aFileOut, const char* folderName){
  aFileOut->cd();
  TDirectory* mydir = aFileOut->mkdir(folderName,folderName);
  mydir->cd();
  return mydir;

}

TString PlottingBase::GetInt(UInt_t myInt) {
  TString mystring;
  char mychars[10];
  sprintf(mychars, "%d", myInt);
  mystring = mychars;
  return mystring;
}

void PlottingBase::BookHistArray(std::vector<TH1D*>& histarray,
				 TString histname,
				 TString title,
				 UInt_t xbins, Double_t xmin, Double_t xmax,
				 UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep,
				 Bool_t zero_is_all ) {
  
  if ( xbins == 0 ) { std::cerr << "ZERO bins in X coordinate!" << std::endl; return; }
  
  std::vector<Double_t> xarray;
  for ( UInt_t ii = 0; ii <= xbins; ++ii ) { xarray.push_back( xmin + ii*(xmax-xmin)/(xbins*1.) ); }

  BookHistArray( histarray,
		 histname , 
		 title,
		 xbins, &xarray.front(),
		 numhists, histnumstart, histnumstep, 
		 zero_is_all );
}

void PlottingBase::BookHistArray(std::vector<TH1D*>& histarray,
				 TString histname,
				 TString title,
				 UInt_t xbins, Double_t* xarray,
				 UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep,
				 Bool_t zero_is_all ) {
  
  histarray.clear();
  TString fullhistname;

  // Loop over the histograms to book.
  for (UInt_t i=histnumstart; i<(histnumstart + numhists*histnumstep); i+=histnumstep) {

    // Determine the name of the histogram from the supplied options.
    if (numhists==1) fullhistname =  histname;
    else if (zero_is_all && i==0) fullhistname = histname + "_all";
    else fullhistname = histname + "_" + GetInt(i);

    // Create the histogram
    TH1D * temphist = new TH1D( fullhistname, title, xbins, xarray );
    temphist->Sumw2();
    
    // Add the histogram to the vector.
    histarray.push_back(temphist);
  } // end of loop over histograms to book
  
} // end of BookHistArray (1D) helper function.

void PlottingBase::BookHistArray( std::vector<TH2D*>& histarray,
				  TString histname , 
				  TString title,
				  UInt_t xbins, Double_t* xarray,
				  UInt_t ybins, Double_t ymin, Double_t ymax,
				  UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, 
				  Bool_t zero_is_all ) {
  
  histarray.clear();
  TString fullhistname;
  
  // Loop over the histograms to book.
  for (UInt_t i=histnumstart; i<(histnumstart + numhists*histnumstep); i+=histnumstep) {
    
    // Determine the name of the histogram from the supplied options.
    if (numhists==1) fullhistname =  histname;
    else if (zero_is_all && i==0) fullhistname = histname + "_all";
    else fullhistname = histname + "_" + GetInt(i);
    
    // Create the histogram
    TH2D * temphist = new TH2D(fullhistname, title, xbins, xarray, ybins, ymin, ymax);
    temphist->Sumw2();
    
    // Add the histogram to the vector.
    histarray.push_back(temphist);

  } // end of loop over histograms to book
  
} // end of BookHistArray (2D) helper function.


void PlottingBase::BookHistArray( std::vector<TH2D*>& histarray,
				  TString histname , 
				  TString title,
				  UInt_t xbins, Double_t xmin, Double_t xmax,
				  UInt_t ybins, Double_t* yarray,
				  UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, 
				  Bool_t zero_is_all ) {
  
  histarray.clear();
  TString fullhistname;
  
  // Loop over the histograms to book.
  for (UInt_t i=histnumstart; i<(histnumstart + numhists*histnumstep); i+=histnumstep) {
    
    // Determine the name of the histogram from the supplied options.
    if (numhists==1) fullhistname =  histname;
    else if (zero_is_all && i==0) fullhistname = histname + "_all";
    else fullhistname = histname + "_" + GetInt(i);
    
    TH2D * temphist = new TH2D(fullhistname, title, xbins, xmin, xmax, ybins, yarray);
    temphist->Sumw2();
    
    // Add the histogram to the vector.
    histarray.push_back(temphist);

  } // end of loop over histograms to book
  
} // end of BookHistArray (2D) helper function.


void PlottingBase::BookHistArray( std::vector<TH2D*>& histarray,
				  TString histname , 
				  TString title,
				  UInt_t xbins, Double_t* xarray,
				  UInt_t ybins, Double_t* yarray,
				  UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, 
				  Bool_t zero_is_all ) {
  
  histarray.clear();
  TString fullhistname;
  
  // Loop over the histograms to book.
  for (UInt_t i=histnumstart; i<(histnumstart + numhists*histnumstep); i+=histnumstep) {
    
    // Determine the name of the histogram from the supplied options.
    if (numhists==1) fullhistname =  histname;
    else if (zero_is_all && i==0) fullhistname = histname + "_all";
    else fullhistname = histname + "_" + GetInt(i);
    
    // Create the histogram
    TH2D * temphist = new TH2D(fullhistname, title, xbins, xarray, ybins, yarray);
    temphist->Sumw2();
    
    // Add the histogram to the vector.
    histarray.push_back(temphist);

  } // end of loop over histograms to book
  
} // end of BookHistArray (2D) helper function.




void PlottingBase::BookHistArray(std::vector<TH2D*>& histarray,
				 TString histname , 
				 TString title,
				 UInt_t xbins, Double_t xmin, Double_t xmax,
				 UInt_t ybins, Double_t ymin, Double_t ymax,
				 UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, 
				 Bool_t zero_is_all ) {

  if ( xbins == 0 ) { std::cerr << "ZERO bins in X coordinate!" << std::endl; return; }
  
  std::vector<Double_t> xarray;
  for ( UInt_t ii = 0; ii <= xbins; ++ii ) { xarray.push_back( xmin + ii*(xmax-xmin)/(xbins*1.) ); }
  BookHistArray( histarray,
		 histname , 
		 title,
		 xbins, &xarray.front(),
		 ybins, ymin, ymax,
		 numhists, histnumstart, histnumstep, 
		 zero_is_all );
}

void  PlottingBase::BookHistArray( std::vector<TH3D*>& histarray,
				   TString histname , 
				   TString title,
				   UInt_t xbins, Double_t xmin, Double_t xmax,
				   UInt_t ybins, Double_t ymin, Double_t ymax,
				   UInt_t zbins, Double_t zmin, Double_t zmax,
				   UInt_t numhists, UInt_t histnumstart, UInt_t histnumstep, 
				   Bool_t zero_is_all )
{

histarray.clear();
  TString fullhistname;
  // Loop over the histograms to book.
  for (UInt_t i=histnumstart; i<(histnumstart + numhists*histnumstep); i+=histnumstep) {
    // Determine the name of the histogram from the supplied options.
    if (numhists==1) fullhistname =  histname;
    else if (zero_is_all && i==0) fullhistname = histname + "_all";
    else fullhistname = histname + "_" + GetInt(i);

    // Create the histogram
    TH3D * temphist = new TH3D(fullhistname, title, xbins, xmin, xmax, ybins, ymin, ymax , zbins, zmin, zmax);
    temphist->Sumw2();

    // Add the histogram to the vector.
    histarray.push_back(temphist);
  } // end of loop over histograms to book

} // end of BookHistArray (2D) helper function.

