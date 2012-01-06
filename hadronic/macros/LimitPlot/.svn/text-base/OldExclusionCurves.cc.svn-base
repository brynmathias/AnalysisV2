#include "ExclusionPlot.hh"


TGraph* set_sneutrino_d0_1(){
  double sn_m0[14]= {0,  0, 48, 55, 80, 90,100,105,109,105,100, 72, 55,0};
  double sn_m12[14]={0,140,210,220,237,241,242,241,230,220,210,170,150,0};

  TGraph* sn_d0_gr = new TGraph(14,sn_m0,sn_m12);

  sn_d0_gr->SetFillColor(kGreen+3);
  sn_d0_gr->SetFillStyle(3001);

  return sn_d0_gr;
}

TGraph* set_sneutrino_d0_2(){
  double sn_m0[9]= {0, 45, 75,115,130,150,163,185,0};
  double sn_m12[9]={0,140,170,213,202,183,168,140,0};

  TGraph* sn_d0_gr_2 = new TGraph(9,sn_m0,sn_m12);

  sn_d0_gr_2->SetFillColor(kGreen+3);
  sn_d0_gr_2->SetFillStyle(3001);

  return sn_d0_gr_2;
}

TGraph* set_lep_ch(Int_t tanBeta){
  if(tanBeta == 3) return set_lep_ch_tanBeta3();
  if(tanBeta == 10) return set_lep_ch_tanBeta10();
  if(tanBeta == 50) return set_lep_ch_tanBeta50();
  return set_lep_ch_tanBeta3();
}

TGraph* set_lep_ch_tanBeta10(){

  double ch_m0[23]={   0,100,200,  300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2000,0};
  double ch_m12[23]={163,162,160.7,159.3,157.6,155.9,154.1,152.3,150.8,149.4,148.2,147.4,146.9,146.6,146.7,147.2,148.1,149.6,151.8,154.8,159.2,0,0};


  
  TGraph* ch_gr = new TGraph(23,ch_m0,ch_m12);

  ch_gr->SetFillColor(8);
  ch_gr->SetLineColor(8);
  //  ch_gr->SetLineWidth(3);
  ch_gr->SetFillStyle(1001);

  return ch_gr;

}



TGraph* set_lep_ch_tanBeta3(){

  double ch_m0[17];
  double ch_m12[17];

  ch_m0[0] = 0;
  ch_m0[1] = 100;
  ch_m0[2] = 150;
  ch_m0[3] = 200;
  ch_m0[4] = 250;
  ch_m0[5] = 300;
  ch_m0[6] = 350;
  ch_m0[7] = 400;
  ch_m0[8] = 450;
  ch_m0[9] = 500;
  ch_m0[10] = 550;
  ch_m0[11] = 600;
  ch_m0[12] = 650;
  ch_m0[13] = 700;
  ch_m0[14] = 750;
  ch_m0[15] = 750;
  ch_m0[16] = 0;
  
  ch_m12[0] = 170;
  ch_m12[1] = 168;
  ch_m12[2] = 167;
  ch_m12[3] = 165;
  ch_m12[4] = 163;
  ch_m12[5] = 161;
  ch_m12[6] = 158;
  ch_m12[7] = 156;
  ch_m12[8] = 154;
  ch_m12[9] = 152;
  ch_m12[10] = 150;
  ch_m12[11] = 148;
  ch_m12[12] = 147;
  ch_m12[13] = 145;
  ch_m12[14] = 144;
  ch_m12[15] = 0;
  ch_m12[16] = 0;
  
  TGraph* ch_gr = new TGraph(17,ch_m0,ch_m12);

  ch_gr->SetFillColor(3);
  ch_gr->SetLineColor(3);
  // ch_gr->SetLineWidth(3);
  ch_gr->SetFillStyle(3001);

  return ch_gr;

}


TGraph* set_lep_ch_tanBeta50(){

  double ch_m0[21];
  double ch_m12[21];

  ch_m0[0] = 200;
  ch_m0[1] = 250;
  ch_m0[2] = 300;
  ch_m0[3] = 350;
  ch_m0[4] = 400;
  ch_m0[5] = 450;
  ch_m0[6] = 500;
  ch_m0[7] = 550;
  ch_m0[8] = 600;
  ch_m0[9] = 650;
  ch_m0[10] = 700;
  ch_m0[11] = 750;
  ch_m0[12] = 800;
  ch_m0[13] =850;
  ch_m0[14] = 900;
  ch_m0[15] = 950;
  ch_m0[16] = 1000;
  ch_m0[17] = 1050;
  ch_m0[18] = 1100;
  ch_m0[19] = 1100;
  ch_m0[20] = 200;
 
  ch_m12[0] = 157;
  ch_m12[1] = 156;
  ch_m12[2] = 156;
  ch_m12[3] = 155;
  ch_m12[4] = 155;
  ch_m12[5] = 154;
  ch_m12[6] = 154;
  ch_m12[7] = 153;
  ch_m12[8] = 153;
  ch_m12[9] = 152;
  ch_m12[10] = 152;
  ch_m12[11] = 152;
  ch_m12[12] = 152;
  ch_m12[13] = 152;
  ch_m12[14] = 152;
  ch_m12[15] = 153;
  ch_m12[16] = 153;
  ch_m12[17] = 153;
  ch_m12[18] = 154;
  ch_m12[19] = 0;
  ch_m12[20] = 0;
  
  
  TGraph* ch_gr = new TGraph(21,ch_m0,ch_m12);

  ch_gr->SetFillColor(3);
  ch_gr->SetLineColor(3);
  ch_gr->SetFillStyle(3001);

  return ch_gr;

}




TGraph* set_lep_sl(Int_t tanBeta){
  
  int n = 0;

  cout << " tanbeta " << tanBeta << endl;

  TGraph* lep_sl_t3;

 

  //contour from D0 trilepton paper (PLB 680 (2009) 34-43)
  if (tanBeta==3){
    double sl_m0_t3[] ={0,  0, 10, 20, 30, 40, 50, 60, 70, 77,88,95};
    double sl_m12_t3[]={0,245,242,239,232,222,209,189,165,140,60,0};
    n = 12;
    lep_sl_t3 = new TGraph(n,sl_m0_t3,sl_m12_t3);
    lep_sl_t3->SetFillColor(5);
    lep_sl_t3->SetLineColor(5);
    lep_sl_t3->SetFillStyle(3001);
    
    return lep_sl_t3;
  }
  //CMS PTDR-II
  //* Selectron_R line mass=99, ISASUGRA7.69, A0=0, m_top=175, tan(beta]=10
  if (tanBeta==10 || tanBeta==50){
    double sl_m0_t10[]={ 0,  0, 11, 20, 24, 49, 70, 82,88,90};
    double sl_m12_t10[]={0,240,237,233,230,200,150,100,50,0};
    n = 10;

    lep_sl_t3 = new TGraph(n,sl_m0_t10,sl_m12_t10);
    lep_sl_t3->SetFillColor(5);
    lep_sl_t3->SetLineColor(5);
    lep_sl_t3->SetFillStyle(1001);
  
    return lep_sl_t3;
  }

  return lep_sl_t3;
}


TGraph* set_tev_sg_cdf(Int_t tanBeta){

 
  //New CHF from CDF plot in ICHEP2010 talk (E. Halkiadakis)
  double sg_m0[]= {0,  0, 30, 75,150,185,225,310,360,400,430,500,600,600};
  double sg_m12[]={0,162,168,170,160,150,130,120,109,108,100, 96, 95,  0};
  int np=14;

  TGraph* sg_gr = new TGraph(np,sg_m0,sg_m12);

  //  gStyle->SetHatchesLineWidth(3);

  sg_gr->SetFillColor(2);
  sg_gr->SetLineColor(2);
  //  sg_gr->SetLineWidth(3);
  //  sg_gr->SetFillStyle(3001); 
  sg_gr->SetFillStyle(1001); 

  return sg_gr;

}

TGraph* set_tev_sg_d0(Int_t tanBeta){

  //official D0 contour from P. Verdier
  double sgd_m0[]= {0,  0., 25., 80.,100.,150.,192.,250.,300. ,350.,400.,450. ,500.,600.,600.,0.};
  double sgd_m12[]={0,167.,167.,163.,162.,157.,149.,136.,125.5,116.,109.,106.5,105.,105.,  0.,0.};
  int npd=16;

  TGraph* sgd_gr = new TGraph(npd,sgd_m0,sgd_m12);

  gStyle->SetHatchesLineWidth(3);

  sgd_gr->SetFillColor(kMagenta+3);
  sgd_gr->SetLineColor(kMagenta+3);
  sgd_gr->SetLineWidth(3);
  sgd_gr->SetFillStyle(3335);

  return sgd_gr;

}





TGraph* set_tev_stau(Int_t tanBeta){

    double st_m0_tanBeta3[] = {0,10,20,30,40,50,60,70,80,90,100,0};
    double st_m12_tanBeta3[] = {337,341,356,378,406,439,473,510,548,587,626,626};   

    double st_m0_tanBeta10[] =  {0,   10, 20, 30, 40, 50, 60, 70, 80,90, 100,110,130,150,0};
    double st_m12_tanBeta10[] = {213,220,240,275,312,352,393,435,476,518,559,600,682,763,763};

    double st_m0_tanBeta50[] = {200,210,220,230,240,250,260,270,280,290,310,325,200,200};
    double st_m12_tanBeta50[] = {206,226,246,267,288,310,332,354,376,399,450,500,500,206};

    double st_m0_tanBeta40[] = {380,450,380};
    double st_m12_tanBeta40[] = {590,780,780};

    TGraph* st_gr_tanBeta3 = new TGraph(12,st_m0_tanBeta3,st_m12_tanBeta3);
    TGraph* st_gr_tanBeta10 = new TGraph(15,st_m0_tanBeta10,st_m12_tanBeta10);
    TGraph* st_gr_tanBeta50 = new TGraph(14,st_m0_tanBeta50,st_m12_tanBeta50);
    TGraph* st_gr_tanBeta40 = new TGraph(3,st_m0_tanBeta40,st_m12_tanBeta40);

    st_gr_tanBeta3->SetFillColor(40);
    st_gr_tanBeta3->SetFillStyle(1001);

    st_gr_tanBeta50->SetFillColor(40);
    st_gr_tanBeta50->SetFillStyle(1001);
    
    st_gr_tanBeta10->SetFillColor(40);
    st_gr_tanBeta10->SetFillStyle(1001);

    st_gr_tanBeta40->SetFillColor(40);
    st_gr_tanBeta40->SetFillStyle(1001);


    if(tanBeta == 3)return st_gr_tanBeta3;
    if(tanBeta == 10)return st_gr_tanBeta10;
    if(tanBeta == 50)return st_gr_tanBeta50;
    if(tanBeta == 40)return st_gr_tanBeta40;

    return st_gr_tanBeta3;

}


TF1* constant_squark(int tanBeta,int i){
//---lines of constant gluino/squark
  double coef1[] = {2.54068e+04, 5.86979e+04, 1.07751e+05, 1.81108e+05, 2.64621e+05};
  double coef2[] = {1.88535e-01, 1.93101e-01, 2.00899e-01, 2.21128e-01, 2.21160e-01};
  double coef3[] = {2.54068e+04, 5.86979e+04, 1.07751e+05, 1.81108e+05, 2.64621e+05};

  char hname[200];

  sprintf(hname,"lnsq_%i",i); 
  if (tanBeta == 10) TF1* lnsq = new TF1(hname,"sqrt([0]-x*x*[1]+[2])",0,2000);
  if (tanBeta == 40) TF1* lnsq = new TF1(hname,"sqrt([0]-x*x*[1]+[2])",380,2000);
  lnsq->SetParameter(0,coef1[i]);
  lnsq->SetParameter(1,coef2[i]);
  lnsq->SetParameter(2,coef3[i]);
  lnsq->SetLineWidth(1);
  lnsq->SetLineColor(kGray);

  return lnsq;
}

//Sanjay update 2
// TF1* constant_squark(int tanBeta,int i){
// //---lines of constant gluino/squark
// // squarks are min of first two generations

//   double coef1[] = {2.67058e+04, 6.39642e+04, 1.16565e+05, 1.95737e+05, 2.86190e+05};
//   double coef2[] = {1.98772e-01, 2.11242e-01, 2.17734e-01, 2.39535e-01, 2.39768e-01};
//   double coef3[] = {2.67058e+04, 6.39641e+04, 1.16565e+05, 1.95736e+05, 2.86189e+05};

//   char hname[200];

//   sprintf(hname,"lnsq_%i",i); 
//   TF1* lnsq = new TF1(hname,"sqrt([0]-x*x*[1]+[2])",0,2000);
//   lnsq->SetParameter(0,coef1[i]);
//   lnsq->SetParameter(1,coef2[i]);
//   lnsq->SetParameter(2,coef3[i]);
//   lnsq->SetLineWidth(1);
//   lnsq->SetLineColor(kGray);

//   return lnsq;
// }

TF1* constant_gluino(int tanBeta,int i){
//---lines of constant gluino/squark
  char hname[200];
  sprintf(hname,"lngl_%i",i); 

  double coef1[] = {201.77, 311.027, 431.582, 553.895, 676.137};
  double coef2[] = {-0.0146608, -0.01677, -0.022244, -0.0271851, -0.0292212};
    
  if (tanBeta == 10) TF1* lngl = new TF1(hname,"[0]+x*[1]",0,2000);
  if (tanBeta == 40) TF1* lngl = new TF1(hname,"[0]+x*[1]",380,2000);

  lngl->SetParameter(0,coef1[i]);
  lngl->SetParameter(1,coef2[i]);
  lngl->SetLineWidth(1);
  lngl->SetLineColor(kGray);

  return lngl;
}


TLatex* constant_squark_text(Int_t it,TF1& lnsq,Int_t tanBeta_){
  char legnm[200];

  sprintf(legnm,"#font[92]{#tilde{q}(%i)GeV}",500+250*it);
  Double_t place_x = 170;
  if(tanBeta_ == 40 )place_x = 390;
  //  cout << "Sq text pos: " << lnsq.Eval(-50+place_x+10*it) << endl;

  TLatex* t3 = new TLatex(place_x+10*it,lnsq.Eval(-50+place_x+10*it)+5,legnm);
  t3->SetTextSize(0.03);
  t3->SetTextAngle(-30+it*5);
  if (tanBeta_ == 40)  t3->SetTextAngle(-40+it*5);
  t3->SetTextColor(kGray+2);
  
  return t3;
}


TLatex* constant_gluino_text(Int_t it,TF1& lngl, Int_t tanBeta_){
  char legnm[200];

  sprintf(legnm,"#font[12]{#tilde{g}}#font[92]{(%i)GeV}",500+250*it);

  Double_t place_x = 423;
  Double_t place_y = 18;
  if (tanBeta_ == 10 ) {
    place_x = 1650;
    place_y = 10;
  }
  if (tanBeta_ == 40 ) {
    place_x = 1700;
    place_y = 10;
  }

  //  cout << "Gl text pos: " << lngl.Eval(480) << endl;

  TLatex* t4 = new TLatex(place_x,place_y+lngl.Eval(800+it*100),legnm);
  t4->SetTextSize(0.03);
  t4->SetTextAlign(13);
  t4->SetTextColor(kGray+2);

  return t4;
}



TLegend* makeStauLegend(Double_t txtsz,Int_t tanBeta_){
  Double_t ypos_1 = 0.76;
  Double_t ypos_2 = 0.78;
  Double_t xpos_1 = 0.16;
  Double_t xpos_2 = 0.17;
  if(tanBeta_ == 10){
    xpos_1 = 0.155;
    xpos_2 = 0.165;
    ypos_1 = 0.76;
    ypos_2 = 0.4;

  }
   if(tanBeta_ == 40){
    xpos_1 = 0.143;
    xpos_2 = 0.153;
    ypos_1 = 0.83;
    ypos_2 = 0.85;

  }
  TLegend* legst = new TLegend(xpos_1,ypos_1,xpos_2,ypos_2);
  legst->SetHeader("#tilde{#tau} = LSP");
  legst->SetFillStyle(0);
  legst->SetBorderSize(0);
  legst->SetTextSize(0.03);
  legst->SetTextAngle(+80);
  if (tanBeta_ == 40) legst->SetTextAngle(75);

  return legst;
}


TLegend* makeExpLegend(TGraph& sg_gr, TGraph& sgd_gr,TGraph& ch_gr,TGraph& sl_gr,TGraph& tev_sn,Double_t txtsz,Int_t tanbeta){
  TLegend* legexp = new TLegend(0.66,0.73,0.99,0.9,NULL,"brNDC");
  legexp->SetFillColor(0);
  legexp->SetShadowColor(0);
  legexp->SetTextSize(txtsz);
  legexp->SetBorderSize(0);

  sg_gr.SetLineColor(1);
  //  legexp->AddEntry(&sg_gr,"CDF  #tilde{#font[12]{g}}, #tilde{#font[12]{q}}, #scale[0.8]{tan#beta=5, #mu<0}","f"); 
  //  legexp->AddEntry(&sgd_gr,"D0   #tilde{#font[12]{g}}, #tilde{#font[12]{q}}, #scale[0.8]{tan#beta=3, #mu<0}","f"); 
  legexp->AddEntry(&sg_gr,"CDF  #tilde{#font[12]{g}}, #tilde{#font[12]{q}}, #scale[0.8]{tan#beta=5, #mu<0}","f"); 
  legexp->AddEntry(&sgd_gr,"D0   #tilde{#font[12]{g}}, #tilde{#font[12]{q}}, #scale[0.8]{tan#beta=3, #mu<0}","f"); 
  ch_gr.SetLineColor(1);
  legexp->AddEntry(&ch_gr,"LEP2   #tilde{#chi}_{1}^{#pm}","f");  
  sl_gr.SetLineColor(1);
  if(tanbeta != 40) legexp->AddEntry(&sl_gr,"LEP2   #tilde{#font[12]{l}}^{#pm}","f"); 
  if(tanbeta == 3) legexp->AddEntry(&tev_sn,"D0  #chi^{#pm}_{1}, #chi^{0}_{2}","f");  
 

  return legexp;

}

TGraph* set_NoEWSB(Int_t tanBeta){

    double st_m0_tanBeta10[]  = { 0, 70, 90,  80,  60, 1000, 1090, 1170, 1240, 1320, 1370, 1440, 1500, 1550, 1610, 1660, 1720, 1780, 1830, 1860, 1920, 1970 , 2000, 2000, 0};
    double st_m12_tanBeta10[] = {10.,10.,20., 30., 40., 50.,  60.,  70.,  80.,  90.,  100., 110., 120., 130., 140., 150., 160., 170., 180., 190., 200., 210., 220,   0,   0}; 

//// Needs to be modified
    double st_m0_tanBeta40[] = { 0, 70, 90,  80,  60, 1000, 1090, 1170, 1240, 1320, 1370, 1440, 1500, 1550, 1610, 1660, 1720, 1780, 1830, 1860, 1920, 1970 , 2000, 2000, 0};
    double st_m12_tanBeta40[]= {10.,10.,20., 30., 40., 50.,  60.,  70.,  80.,  90.,  100., 110., 120., 130., 140., 150., 160., 170., 180., 190., 200., 210., 220,   0,   0};

    TGraph* st_gr_tanBeta10 = new TGraph(25,st_m0_tanBeta10,st_m12_tanBeta10);
    TGraph* st_gr_tanBeta40 = new TGraph(25,st_m0_tanBeta40,st_m12_tanBeta40);

    
    st_gr_tanBeta40->SetFillColor(40);
    st_gr_tanBeta40->SetFillStyle(1001);
    
    st_gr_tanBeta10->SetFillColor(40);
    st_gr_tanBeta10->SetFillStyle(1001);

    if(tanBeta == 10)return st_gr_tanBeta10;
    if(tanBeta == 40)return st_gr_tanBeta40;
}


TLegend* makeNoEWSBLegend(Double_t txtsz,Int_t tanBeta_){
  Double_t ypos_1 = 0.10;
  Double_t ypos_2 = 0.20;
  Double_t xpos_1 = 0.82;
  Double_t xpos_2 = 0.92;
  if(tanBeta_ == 40){
    xpos_1 = 0.10;
    xpos_2 = 0.20;
    ypos_1 = 0.85;
    ypos_2 = 0.95;

  }

  TLegend* legst = new TLegend(xpos_1,ypos_1,xpos_2,ypos_2);
  legst->SetHeader("NoEWSB");
  legst->SetFillStyle(0);
  legst->SetBorderSize(0);
  legst->SetTextSize(0.04);
  legst->SetTextAngle(30);

  return legst;
}
