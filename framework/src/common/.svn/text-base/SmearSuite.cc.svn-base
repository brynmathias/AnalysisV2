/*! \file SmearSuite.cc
 */

#include "SmearSuite.hh"

TRandom Gauss;
  
namespace Event {

  void smearPt(TLorentzVector & lorVec,float smearFactor){

    float actualSmearFactor = Gauss.Gaus(0.,smearFactor);

    int flipSign = rand();
    if(flipSign > (RAND_MAX/2)) actualSmearFactor = 1 + actualSmearFactor;
    else actualSmearFactor = 1 - actualSmearFactor;
    
    lorVec = lorVec*actualSmearFactor;


 }


  TH1F* makeResponseFunction(float nonGaussianNormalization, TH1F* gaussianPart, TH1F* nonGaussianPart)
  {
      TH1F* Response = new TH1F("Response", "", 160, -4, 4.);//numbers from Elif's analysis. these may need finalizing!
      int nbins =  gaussianPart->GetXaxis()->GetNbins();
      double *x1 = new double[nbins];
      double *y1 = new double[nbins];

      if(nonGaussianNormalization == 0.0){//take only gaussian part
	  for (int bin = 0; bin < nbins; ++bin) {
	      x1[bin] = gaussianPart->GetXaxis()->GetBinCenter(bin);
	      y1[bin] = gaussianPart->GetBinContent(bin);
	      Response->Fill(x1[bin],y1[bin]);
	  }
      }else{ // now combine with non-gaussian by using some numbers from Elif's analysis. these may need finalizing!
	  for (int bin = 0; bin < nbins; ++bin) {
	      x1[bin] = gaussianPart->GetXaxis()->GetBinCenter(bin);
	      if(x1[bin] < 0.75){//under measured jet estimation from QCD multi-jet sample
		  y1[bin] = nonGaussianPart->GetBinContent(bin) * (nonGaussianNormalization);
	      }else if(x1[bin] >= 0.75 && x1[bin] < 1.20){//gaussian peak estimation from Photon-Jet sample and di-jet sample.
							  // TODO: find a fix for hard coded numbers!
		  y1[bin] = gaussianPart->GetBinContent(bin);
	      }else{//over measured jet estimation from QCD multi-jet sample
		  y1[bin] = nonGaussianPart->GetBinContent(bin) * (nonGaussianNormalization);
	      }
	      Response->Fill(x1[bin],y1[bin]);
	  }
      }
      return Response;
  }

  void smearPtFunction(TLorentzVector & lorVec, TH1F* responseFunc) {
    lorVec = lorVec * (responseFunc->GetRandom());
  }

  void smearPhi(TLorentzVector & lorVec, float smearFactor){
    float actualSmearFactor = Gauss.Gaus(0.,smearFactor);

    int flipSign = rand();
    
    if(flipSign > (RAND_MAX/2))lorVec.SetPhi(lorVec.Phi() + actualSmearFactor);
    else lorVec.SetPhi(lorVec.Phi() - actualSmearFactor);
  }

  void scalePt(TLorentzVector & lorVec, float scaleFactor, float etaMin, float etaMax){
    if(lorVec.Eta() > etaMin && lorVec.Eta() < etaMax)lorVec = lorVec*scaleFactor;
  }

} // ~namespace Event
