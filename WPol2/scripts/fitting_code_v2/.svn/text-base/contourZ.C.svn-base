#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooChebychev.h"
#include "RooAddPdf.h"
#include "RooMinuit.h"
#include "RooSimultaneous.h"
#include "RooCategory.h"
#include "RooPlot.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"

void contourZ() {


  RooPlot* frame=new RooPlot(-1.,1.,0.,1.);

 // lookup the 2x2 covariance matrix elements for these variables
  //format:
  //RooEllipse *data = ellipse(frame,x1,x2,s1,s2,rho,"MEVH");
  // Double_t x1= ;//par1->getVal();
  // Double_t x2= ;//par2->getVal();
  // Double_t s1= ;//par1->getError();
  // Double_t s2= ;//par2->getError();
  // Double_t rho= ;//correlation(parName1, parName2);

// user recoroutines rew8
  RooEllipse *dataCorr0_mcCorr0 = ellipse(frame,2.5843e-02,2.9928e-01,4.94e-02,6.84e-02,-0.04601,kMagenta);
  RooEllipse *dataCorr0_mcCorr1 = ellipse(frame,2.6015e-02,2.8708e-01,5.36e-02,8.32e-03,1,kMagenta+1);
  RooEllipse *dataCorr0_mcCorr2 = ellipse(frame,2.4431e-02,2.8670e-01,4.96e-02,6.83e-02,-0.04208,kMagenta+2);
  RooEllipse *dataCorr1_mcCorr1= ellipse(frame,-3.9355e-02,3.1596e-01,4.95e-02,6.89e-02,-0.03861,kMagenta-1);
  RooEllipse *dataCorr1_mcCorr2 = ellipse(frame,-4.1982e-02,3.0285e-01,4.96e-02,6.89e-02,-0.03564,kMagenta-2);

// use genroutines rew9MC
 RooEllipse *markerMCGenLevAnalyticalCorr0= ellipse(frame,0.0429,0.2109,0.0064,0.0081,-0.0153,kGreen);
RooEllipse *markerMCGenLevTemplatesCorr0 = ellipse(frame,3.5601e-02,2.1139e-01,2.84e-02,3.65e-02,-0.01906,kBlue);
RooEllipse *markerMCGenLevAcceptanceTemplatesCorr0 = ellipse(frame,3.7072e-02,2.1021e-01,4.55e-02,6.04e-02,-0.0432,kGreen);

 RooEllipse *markerMCGenLevAnalyticalCorr1= ellipse(frame,0.0411548,0.21129,0.0170367,0.0216702,-0.026834,kGreen+1);
RooEllipse *markerMCGenLevTemplatesCorr1 = ellipse(frame,3.5596e-02,2.1138e-01,2.84e-02,3.65e-02,-0.02005,kBlue+1);

 RooEllipse *markerMCGenLevAnalyticalCorr2= ellipse(frame,0.0433825,0.215755,0.0170178,0.0216462,-0.029015,kGreen+2);
RooEllipse *markerMCGenLevTemplatesCorr2 = ellipse(frame,3.5595e-02,2.1138e-01,2.84e-02,3.65e-02,-0.01848,kBlue+2);

// use recoroutines rew8
 RooEllipse *markerMCRecoLevCorr0 =  ellipse(frame,3.3757e-02,2.1184e-01,5.56e-02,7.42e-02,-0.03722,kRed);
 RooEllipse *markerMCRecoLevCorr1 =  ellipse(frame,3.3989e-02,2.0861e-01,5.56e-02,7.43e-02,-0.03822,kRed+1);
 RooEllipse *markerMCRecoLevCorr2 =  ellipse(frame,3.3716e-02,2.1108e-01,5.58e-02,7.45e-02,-0.0353,kRed+2);



  gROOT->SetStyle("Plain"); 
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0); 


  TCanvas *c= new TCanvas("c","",600,600);


  frame->Draw();
  frame->GetXaxis()->SetTitle("f_{L}-f_{R}");
  frame->GetYaxis()->SetTitle("f_{0}");
frame->SetAxisRange(-0.1,0.1,"X");
frame->SetAxisRange(0.12,0.4,"Y");

 TLegend* leg = new TLegend(0.1, 0.7, 0.5, 0.9);
leg->AddEntry(dataCorr0_mcCorr0,"fit to 2010 data corr0 with MC reco templates corr0","l");
leg->AddEntry(dataCorr0_mcCorr1,"fit to 2010 data corr0 with MC reco templates corr1","l");
leg->AddEntry(dataCorr0_mcCorr1,"fit to 2010 data corr0 with MC reco templates corr2","l");
leg->AddEntry(dataCorr1_mcCorr1,"fit to 2010 data corr1 with MC reco templates corr1","l");
leg->AddEntry(dataCorr1_mcCorr2,"fit to 2010 data corr1 with MC reco templates corr2","l");
leg->AddEntry(markerMCGenLevAnalyticalCorr0,"gen level corr0, analytical fit, full stats","l");
leg->AddEntry(markerMCGenLevAnalyticalCorr1,"gen level corr1, analytical fit, full stats","l");
leg->AddEntry(markerMCGenLevAnalyticalCorr2,"gen level corr2, analytical fit, full stats","l");
leg->AddEntry(markerMCGenLevTemplatesCorr0,"gen level corr0, template fit, scaled 36/pb","l");
leg->AddEntry(markerMCGenLevTemplatesCorr1,"gen level corr1, template fit, scaled 36/pb","l");
leg->AddEntry(markerMCGenLevTemplatesCorr2,"gen level corr2, template fit, scaled 36/pb","l");
leg->AddEntry(markerMCGenLevAcceptanceTemplatesCorr0,"gen level, template fit with acceptance, scaled 36/pb","l");
leg->AddEntry(markerMCRecoLevCorr0,"reco level corr0, MC template fit, scaled 36/pb","l");
leg->AddEntry(markerMCRecoLevCorr1,"reco level corr1, MC template fit, scaled 36/pb","l");
leg->AddEntry(markerMCRecoLevCorr2,"reco level corr2, MC template fit, scaled 36/pb","l");
leg->Draw();
c->Update();

  //contour2->Draw("SAME");

TCanvas *c2 = new TCanvas("2011_4_1","2011_4_1",600,600);

 RooPlot* frame2=new RooPlot(-1.,1.,0.,1.);

 RooEllipse *data41Corr = ellipse(frame2,2.9773e-02,2.2361e-01,1.88e-02,2.53e-02,-0.03088,kMagenta);
 RooEllipse *data41onlyMCCorr = ellipse(frame2,0.0371439,0.217617,0.018751,0.0252248,-0.03386,kMagenta+2);
 RooEllipse *MCRecoLevCorr =  ellipse(frame2,3.4895e-02,2.0779e-01,2.20e-02,2.93e-02,-0.0491,kRed);
 RooEllipse *MCRecoLev =  ellipse(frame2,0.0376024,0.229521,0.0187051,0.0252698,-0.03753,kRed+2);
 RooEllipse *MCGenLevAnalytical= ellipse(frame2,0.0332975,0.216766,0.00598647,0.00763462,-0.021725,kGreen);

 frame2->Draw();
 frame2->GetXaxis()->SetTitle("f_{L}-f_{R}");
 frame2->GetYaxis()->SetTitle("f_{0}");
 frame2->SetAxisRange(-0.1,0.1,"X");
 frame2->SetAxisRange(0.12,0.4,"Y");

 TLegend* leg2 = new TLegend(0.1, 0.7, 0.5, 0.9);
 leg2->AddEntry(data41Corr,"fit to 2011 data up to 163817 corr with MC reco templates corr","l");
 leg2->AddEntry(data41onlyMCCorr,"fit to 2011 data up to 163817 with MC reco templates corr","l");
 leg2->AddEntry(MCRecoLevCorr,"mc reco level corr, MC template fit, scaled 240/pb","l");
 leg2->AddEntry(MCRecoLev,"mc reco level, MC template fit, scaled 240/pb","l");
 leg2->AddEntry(MCGenLevAnalytical,"mc gen level, analytical fit","l");
 leg2->Draw();

 c2->Update();

}

TMarker *buildMark(double x1,double x2, Color_t color = kBlack, Style_t style=20){
TMarker *out = new TMarker(x1,x2,style);
out->SetMarkerColor(color);
return out;
};

RooEllipse *ellipse(RooPlot *frame, double x1, double x2, double s1, double s2, double rho, Color_t color, const char* options="MEVH") {

  TString opt(options);

  // add a 1-sigma error ellipse, if requested
  if(opt.Contains("E")) {
    RooEllipse *contour= new RooEllipse("contour",x1,x2,s1,s2,rho);
    contour->SetLineWidth(2) ;
    contour->SetLineColor(color);
    frame->addPlotable(contour);
  }

  // add the error bar for parameter 1, if requested
  if(opt.Contains("1")) {
    TLine *hline= new TLine(x1-s1,x2,x1+s1,x2);
    hline->SetLineColor(kRed);
    frame->addObject(hline);
  }

  if(opt.Contains("2")) {
    TLine *vline= new TLine(x1,x2-s2,x1,x2+s2);
    vline->SetLineColor(kRed);
    frame->addObject(vline);
  }

  if(opt.Contains("B")) {
    TBox *box= new TBox(x1-s1,x2-s2,x1+s1,x2+s2);
    box->SetLineStyle(kDashed);
    box->SetLineColor(kRed);
    box->SetFillStyle(0);
    frame->addObject(box);
  }

  if(opt.Contains("H")) {
    TLine *line= new TLine(x1-rho*s1,x2-s2,x1+rho*s1,x2+s2);
    line->SetLineStyle(kDashed);
    line->SetLineColor(color);
    line->SetLineWidth(2) ;
    frame->addObject(line);
    if(opt.Contains("A")) {
      TGaxis *axis= new TGaxis(x1-s1,x2-s2,x1+s1,x2-s2,-1.,+1.,502,"-=");
      axis->SetLineColor(kBlue);
      frame->addObject(axis);
    }
  }

  if(opt.Contains("V")) {
    TLine *line= new TLine(x1-s1,x2-rho*s2,x1+s1,x2+rho*s2);
    line->SetLineStyle(kDashed);
    line->SetLineColor(color);
    line->SetLineWidth(2) ;
    frame->addObject(line);
    if(opt.Contains("A")) {
      TGaxis *axis= new TGaxis(x1-s1,x2-s2,x1-s1,x2+s2,-1.,+1.,502,"-=");
      axis->SetLineColor(kBlue);
      frame->addObject(axis);
    }
  }

  // add a marker at the fitted value, if requested
  if(opt.Contains("M")) {
    TMarker *marker= new TMarker(x1,x2,20);
    marker->SetMarkerColor(color);
    frame->addObject(marker);
  }


  return contour;
}
