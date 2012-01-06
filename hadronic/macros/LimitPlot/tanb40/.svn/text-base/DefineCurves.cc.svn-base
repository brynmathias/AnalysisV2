#include "ExclusionPlot.hh"



TSpline3* getCLs1080ObsNLO(){

  Int_t nl = 12;
  Double_t xl[12]={  0,100,300,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[12]={540,535,520,490,400,280, 240, 220, 210, 200, 195, 190};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kRed);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kRed);
  s->SetLineStyle(1);
  s->SetLineWidth(3);

  return s;
}


TSpline3* getCLs1080Exp(){

  Int_t nl = 12;
  Double_t xl[12]={  0,100,300,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[12]={510,505,500,460,340,260, 220, 210, 205, 200, 190, 185};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kBlue);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue+3);
  s->SetLineStyle(4);
  s->SetLineWidth(3);

  return s;
}


TSpline3* getCLs1080Up(){

  Int_t nl = 12;
  Double_t xl[12]={  0,100,300,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[12]={540,535,525,490,380,285, 240, 220, 215, 210, 205, 200};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kBlue);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kAzure+1);
  s->SetLineStyle(1);
  s->SetLineWidth(3);

  return s;
}

TSpline3* getCLs1080Low(){

  Int_t nl = 12;
  Double_t xl[12]={  0,100,300,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[12]={485,480,465,420,300,220, 200, 190, 185, 180, 175, 170};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kBlue);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kAzure+1);
  s->SetLineStyle(1);
  s->SetLineWidth(3);

  return s;
}

// Default (flat EWK - zero QCD)
// --------------------------
// Expected limit:
//
// m0:      0 , 100 , 200, 300, 400, 500, 600, 700, 800, 900, 1000
// mean:
// m12:
// + 1 Sigma:
// m12:
// - 1 Sigma
// m12:
//
// Observed Limit:
// m12:
//
//
// Cross check (exp QCD flat EWK)
// -----------------------------
// m12:

TGraphErrors* get1080ObsNLO(){

  Int_t nl = 12;
  Double_t xl[12]={  0, 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2000};
  Double_t yl[12]={560, 560, 550, 510, 440, 320,  270,  250,  230,  220,  215,  210};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}

TGraphErrors* get1080ObsLO(){

  Int_t nl = 12;
  Double_t xl[12]={  0, 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2000};
  Double_t yl[12]={540, 540, 525, 490, 380, 280,  210,  185,  175,  165,  155,  150};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}

TGraphErrors* get1080Up(){

  Int_t nl = 12;
  Double_t xl[12]={  0, 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2000};
  Double_t yl[12]={560, 560, 540, 500, 420, 300,  255,  240,  230,  220,  215,  210};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}
TGraphErrors* get1080Low(){

  Int_t nl = 12;
  Double_t xl[12]= {  0, 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2000};
  Double_t yl[12]= {460, 460, 445, 400, 240, 190,  170,  150,  140,  130,  120,  115};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}


TGraphErrors* get1080Exp(){

  Int_t nl = 12;
  Double_t xl[12]={  0 , 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2000};
  Double_t yl[12]={ 520, 520, 500, 460, 360, 260,  230,  215,  205,  195,  180,  175};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}

//this is just a placeholder
TGraphErrors* get1080SidBandExp(){
  
  Int_t nl = 11;
  Double_t xl[11]={  0 , 100 , 200, 300, 400, 500, 600, 700, 800, 900, 1000};
  Double_t yl[11]={450,  450,  450,  450,  450, 440, 330, 250, 220, 210, 170};
  Double_t exl[11];
  Double_t eyl[11];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}

//this is just a placeholder
TGraphErrors* get1080QCDExpExp(){

  Int_t nl = 12;
  Double_t xl[12]={  0 , 100, 300, 500, 700, 900, 1100, 1300, 1500, 1700, 1900, 2000};
  Double_t yl[12]={ 540, 530, 520, 490, 360, 290,  250,  230,  210,  170,  170,  170};
  Double_t exl[12];
  Double_t eyl[12];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}





TGraphErrors* getATLAScomb(){

  Int_t nl = 10;
  Double_t xl[10]={ 50,150,250,350,450,550,650,750,850,950};
  Double_t yl[10]={360,365,360,345,320,270,220,180,135,133};
  Double_t exl[10];
  Double_t eyl[10];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}



TGraphErrors* getATLASPLHC(){

  Int_t nl = 9;
  //  Double_t xl[10]={  0,100,300,250,350,450,550,650,750,850,950};
  //  Double_t yl[10]={425,420,410,415,400,375,340,300,260,235,205};
  Double_t xl[9]={  0,100,300,500,700,900,1100,1300,1400};
  Double_t yl[9]={425,420,410,351,275,215, 165, 130, 110};
  Double_t exl[9];
  Double_t eyl[9];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);

  //gr1->Draw("LP");

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue);
  s->SetLineStyle(2);
  s->SetLineWidth(3);

  return gr1;

}



TSpline3* getCLs1080ObsNLOtb40(){

  Int_t nl = 10;
  Double_t xl[10]={380,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[10]={520,490,390,290, 230, 210, 205, 200, 195, 190};
  Double_t exl[10];
  Double_t eyl[10];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kRed);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kRed);
  s->SetLineStyle(1);
  s->SetLineWidth(3);

  return s;
}


TSpline3* getCLs1080Exptb40(){

  Int_t nl = 10;
  Double_t xl[10]={380,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[10]={490,460,340,240, 210, 200, 197, 194, 192, 190};
  Double_t exl[10];
  Double_t eyl[10];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kBlue);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kBlue+3);
  s->SetLineStyle(4);
  s->SetLineWidth(3);

  return s;
}


TSpline3* getCLs1080Uptb40(){

  Int_t nl = 10;
  Double_t xl[10]={380,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[10]={500,480,380,280, 225, 215, 210, 206, 203, 200};
  Double_t exl[10];
  Double_t eyl[10];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kBlue);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kAzure+1);
  s->SetLineStyle(1);
  s->SetLineWidth(3);

  return s;
}

TSpline3* getCLs1080Lowtb40(){

  Int_t nl = 10;
  Double_t xl[10]={380,500,700,900,1100,1300,1500,1700,1900,2000};
  Double_t yl[10]={440,420,280,200, 185, 180, 177, 174, 172, 170};
  Double_t exl[10];
  Double_t eyl[10];

  TGraphErrors* gr1 = new TGraphErrors(nl,xl,yl,exl,eyl);
  //  gr1->SetMarkerColor(kBlue);
  //  gr1->SetMarkerStyle(21);

  TSpline3 *s = new TSpline3("grs",gr1);
  s->SetLineColor(kAzure+1);
  s->SetLineStyle(1);
  s->SetLineWidth(3);

  return s;
}

