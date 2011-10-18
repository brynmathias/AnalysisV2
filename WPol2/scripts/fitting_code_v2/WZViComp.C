

#include "contourZ.C"
#include <vector.h>
#include <TMatrix.h>
#include <stdio.h>
#include <math.h>



void WZViComp()
{
 RooPlot* frame=new RooPlot(-1.,1.,0.,1.);

 RooEllipse *Wpl=ellipse(frame,0.57,0.26,0.05,0.07,0.91,kRed);
 RooEllipse *Wmi=ellipse(frame,0.53,0.29,0.07,0.08,0.84,kGreen);
 RooEllipse *Z=ellipse(frame,0.51,0.26,0.04,0.04,-0.89,kBlack);

    TCanvas *c= new TCanvas("c","",600,600);
  frame->Draw();
  frame->GetXaxis()->SetTitle("V_{L}");
  frame->GetYaxis()->SetTitle("V_{R}");
frame->SetAxisRange(0,1,"X");
frame->SetAxisRange(0,1,"Y");

 c->Update();



}

