#include "Plot_Prediction.hh"
#include "DrawOptions.hh"

#include <TCanvas.h>
#include <TLegend.h>

#include <TROOT.h>
#include <TF1.h>
#include <TH1.h>

#include <iostream>

using namespace std;







Plot_Prediction::Plot_Prediction(TString dirname,TString filename,std::vector<TH1D* >& Histos) : dirname_(dirname),filename_(filename),histos(Histos) {


 
  TString outFileName = dirname_+"/"+ filename + ".root";
  rootFile = new TFile(outFileName,"recreate");
  rootFile->cd();


}
Plot_Prediction::~Plot_Prediction() {}





void Plot_Prediction::Plot(){

  rootFile->cd();

  std::vector<TH1D* >::iterator i = histos.begin();


 //Draw plot of events measured with alphaT> cut_signal as a function of variable 2
  TCanvas myCanvas(filename_);
  setPad(0.30); 

  TLegend myLegend(0.63, 0.73, 0.9, 0.93);

  int it = 0;
  Double_t maxsize=0;

  //iterate over all histos in vector
  while ( i != histos.end() ) {
    setPlotStyle(*(i));
    if(it == 0){ 
      (*i)->Draw(); 
      maxsize = (*i)->GetMaximum();
    }
    else{
      if((*i)->GetMaximum() >maxsize )  maxsize = (*i)->GetMaximum();
      (*i)->Draw("same");
      
    }
    
    myLegend.AddEntry((*i),(*i)->GetName());
    it++;
    ++i;
  }//end while iterating over histos

  (*(histos.begin()))->SetMaximum(maxsize*1.4); 
   
  myLegend.Draw();
  myCanvas.Write();

  TString outFile = dirname_+"/"+filename_+".eps";
  myCanvas.SaveAs(outFile);
   
  cout << " save in " << rootFile->GetName() << endl;

  rootFile->Write();
  rootFile->Close();
  delete rootFile; 

}

//set plot style
//for having nice plots
template<class T> void Plot_Prediction::setPlotStyle(T& plot){
  plot->GetXaxis()->SetTitleOffset( 0.8 );
  plot->GetYaxis()->SetTitleOffset( 1.8 );
 
  plot->GetYaxis()->SetTitleSize( 0.075 );
  plot->GetXaxis()->SetTitleSize( 0.075 );

  Float_t labelSize = 0.07;
  plot->GetXaxis()->SetLabelSize( labelSize );
  plot->GetYaxis()->SetLabelSize( labelSize );
  plot->GetXaxis()->SetNdivisions( 406, kTRUE );
  plot->GetXaxis()->SetLabelOffset( 0.02 );
  plot->GetYaxis()->SetLabelOffset( 0.015 );
 }

//set Style of your pad
void Plot_Prediction::setPad(Double_t leftMargin){
  Float_t theScale =1.;
  gPad->SetTicks();
  gPad->SetLeftMargin  ( leftMargin*theScale );
  gPad->SetRightMargin ( 0.065*theScale );
  gPad->SetTopMargin( 0.09*theScale  );
  gPad->SetBottomMargin( 0.150*theScale  );
}


