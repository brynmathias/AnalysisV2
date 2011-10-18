/*! \file PlotHandler.hh
 * \brief Header file for the PlotHandler class.
 */
#ifndef PlotHandler_h
#define PlotHandler_h

#include <TString.h>
#include <TFile.h>
#include <TGraphErrors.h>
#include <vector>
#include <TH2D.h>

/**
 * \brief Class that handles the processing of the ntuples and making the merged histograms.
 *
 * \author CMS SUSY Dijet Analysis Team
 * \date Summer 2008
 */
class PlotHandler {

 public:

  PlotHandler(std::string name = "");
  ~PlotHandler();

  /**
   * \brief Adds a dataset to the histogram to be plotted
   *
   * \param String with the name of the dataset to add.
   */
  void addDataSet(std::string dataSet);

  /**
   * \brief This method plots S/B for a single 1 D histogram it takes the first dataset as signal the rest as background
   * Also writes a graphics file to the output directory.
   *
   * \param Name of the histogram, common to all datasets.
   */
  //void PlotHandler::SoverB(char* histname,bool smaller);


  /**
   * \brief This method plots 1D histograms, named "histname", onto a single canvas
   * Also writes a graphics file to the output directory.
   *
   * \param Name of the histogram, common to all datasets.
   * \param Flag to indicate whether to have a legend or not.
   * \param Draw options to pass when plotting the histogram.
   */
  void merge1DHist(char* foldername, char* histname, bool legend=false, TString drawOpt="");
  
  /**
   * \brief 
   * 
   * This method splits a canvas in as many pads as datasets and 
   * plots 2D histos in the different pads
   * 
   * \param Name of the 2D histogram to plot and save
   */
  //void make2DHist(char* histname);


  //void makeABCD(char* histname,Double_t cut_varX,Double_t fitstart, Double_t fitend); 
    
  //void makePrediction(TH1D& Predicted,TString histname,const TF1 &Fit,const TH1D& histo);

private:

  std::string dirname_; //!< Output directory (hardcoded...)
  std::vector<TFile*> dataFileVec; //!< Vector of ROOT files from the datasets

  // Plot drawing options (one vector entry for each dataset)
  std::vector<int> colorVec;
  std::vector<int> linewidthVec;
  std::vector<int> linestyleVec;
  std::vector<TString> dataNameVec;
  std::vector<TString> drawOptVec;
  std::vector<TString> legendVec;

};
#endif //~PlotHandler_h
