TLegend *legend() {
  
 TLegend *leg2 = new TLegend(0.57,0.6,0.92,0.92);
 leg2->SetFillStyle(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.04);
 leg2->SetTextFont(42); 
 
 return leg2;

}

TCanvas* getaCanvas(TString name)
{

  TCanvas* aCanvas = new TCanvas(name);

  aCanvas->SetFillColor(0);
  aCanvas->SetBottomMargin(0.125);
  aCanvas->SetLeftMargin(0.125);
  aCanvas->SetFrameFillColor(0);
  aCanvas->SetFrameBorderMode(0);
  aCanvas->SetFrameLineWidth(2);
  return aCanvas;
}

TH2* readHist2D(TString nameHist,TString nameFile, int rebin)
{
 TFile* file = new TFile(nameFile);
 // file->ls();
 // TDirectory* dir = (TDirectory*)file->Get(Dirname);
 // dir->ls();
 TH2* hist = (TH2*)file->Get(nameHist);
 // hist->SetLineWidth(2);
 if(rebin>0) hist->RebinX(rebin);
 hist->GetXaxis()->SetTitleSize(.055);
 hist->GetYaxis()->SetTitleSize(.055);
 hist->GetXaxis()->SetLabelSize(.05);
 hist->GetYaxis()->SetLabelSize(.05);
 hist->SetStats(kFALSE);

 return hist;

}

TH3* readHistLO(TString nameHist,TString nameFile, int rebin)
{
 TFile* file = new TFile(nameFile);
 // file->ls();
 // TDirectory* dir = (TDirectory*)file->Get(Dirname);
 // dir->ls();
 TH3* hist = (TH3*)file->Get(nameHist);
 // hist->SetLineWidth(2);
 if(rebin>0) hist->RebinX(rebin);
 hist->GetXaxis()->SetTitleSize(.055);
 hist->GetYaxis()->SetTitleSize(.055);
 hist->GetXaxis()->SetLabelSize(.05);
 hist->GetYaxis()->SetLabelSize(.05);
 hist->SetStats(kFALSE);

 return hist;

}

TH2* addHist2D(TString nameHist,TString nameFile) 
{
  TFile *file=new TFile(nameFile);

  TH2* hist = readHist2D(nameHist+"_gg",nameFile,0);
  hist->Add(readHist2D(nameHist+"_ng",nameFile,0));
  hist->Add(readHist2D(nameHist+"_sb",nameFile,0));
  hist->Add(readHist2D(nameHist+"_tb",nameFile,0));
  hist->Add(readHist2D(nameHist+"_bb",nameFile,0));
  hist->Add(readHist2D(nameHist+"_ns",nameFile,0));
  hist->Add(readHist2D(nameHist+"_ss",nameFile,0));
  hist->Add(readHist2D(nameHist+"_ll",nameFile,0));
  hist->Add(readHist2D(nameHist+"_nn",nameFile,0));
  hist->Add(readHist2D(nameHist+"_sg",nameFile,0));

  return hist;

}

 TH2* addHistDen2D(TString nameHist,TString nameFile) 
{
  TFile *file=new TFile(nameFile);

  TH2* hist = readHist2D(nameHist+"_gg_noweight",nameFile,0);
  hist->Add(readHist2D(nameHist+"_ng_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_sb_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_tb_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_bb_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_ns_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_ss_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_ll_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_nn_noweight",nameFile,0));
  hist->Add(readHist2D(nameHist+"_sg_noweight",nameFile,0));

  return hist;

}


TH2* drawLoEff(TString hname1, TString hname2, TString filename1, TString filename2, TString header) {

  TH3D *ref=readHistLO(hname2,filename1,0);
  TH3D *sel=readHistLO(hname1,filename1,0);
  sel->Add(readHistLO(hname1,filename2,0));
  //  ref->RebinX(2); sel->RebinY(2);

  TH2D *eff=ref->Clone(); eff->Reset();
  eff->Divide(sel,ref);

  TLegend *leg = legend();
  leg->SetHeader(header);

  gStyle->SetPalette(1);
  eff->Draw("COLZ");

  leg->Draw("SAME");

  return eff;


}

TH2* drawEff(TString hname1, TString hname2, TString filename1, TString filename2, TString header) {

  TH2D *ref=addHistDen2D(hname2,filename1);
  TH2D *sel=addHist2D(hname1,filename1);
  //  sel->Add(addHist2D(hname1,filename2));
  //  ref->RebinX(2); sel->RebinY(2);

  TH2D *eff=ref->Clone(); eff->Reset();
  eff->Divide(sel,ref);

  TLegend *leg = legend();
  leg->SetHeader(header);

  gStyle->SetPalette(1);
  sel->Draw("COLZ");

  // leg->Draw("SAME");

  return sel;


}

TH2* buildHist(TString hname, TString filename) {

  TH2D *sel=addHist2D(hname,filename);
  //  sel->Add(addHist2D(hname1,filename2));
  //  ref->RebinX(2); sel->RebinY(2);

  return sel;


}

TH2* cmssmNloXsSub(TString filename, TString denDir, TString sub) {
  //  h = ratio(s["file"], s["beforeDir"], "m0_m12_%s"%process, s["beforeDir"], "m0_m12_%s_noweight"%process)
  TH2D *num=readHist2D(denDir+"m0_m12_"+sub,filename,0);
  TH2D *den=readHist2D(denDir+"m0_m12_"+sub+"_noweight",filename,0);

  TH2D *ratio=num->Clone();
  ratio->Divide(den);

  return ratio;
}

TH2* cmssmNloEffSub(TString filename, TString numDir, TString denDir, TString sub) {
  //  h = ratio(s["file"], s["beforeDir"], "m0_m12_%s"%process, s["beforeDir"], "m0_m12_%s_noweight"%process)
  TH2D *num=readHist2D(numDir+"m0_m12_"+sub,filename,0);
  TH2D *den=readHist2D(denDir+"m0_m12_"+sub+"_noweight",filename,0);

  TH2D *ratio=num->Clone();
  ratio->Divide(den);
  ratio->Divide(cmssmNloXsSub(filename,denDir,sub));

  return ratio;
}

TH2* cmssmNloXsTimesEffSub(TString filename, TString numDir, TString denDir, TString sub) {

  TH2D *h=cmssmNloXsSub(filename,denDir,sub); h->Multiply(cmssmNloEffSub(filename,numDir,denDir,sub));

  return h;

}

TH2* cmssmNloYieldHisto(TString filename, TString numDir, TString denDir) {

  TH2D *h=cmssmNloXsTimesEffSub(filename,numDir,denDir,"gg");
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"ng"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"sb"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"tb"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"bb"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"ns"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"ss"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"ll"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"nn"));
  h->Add(cmssmNloXsTimesEffSub(filename,numDir,denDir,"sg"));

  return h;

}

TH2* cmssmNloXsHisto(TString filename, TString denDir) {
  //  h = ratio(s["file"], s["beforeDir"], "m0_m12_%s"%process, s["beforeDir"], "m0_m12_%s_noweight"%process)
  TH2D *num=addHist2D(denDir+"m0_m12",filename);
  TH2D *den=addHistDen2D(denDir+"m0_m12",filename);

  TH2D *ratio=num->Clone();
  ratio->Divide(den);

  return ratio;
}


TH2* cmssmNloEffHisto(TString filename, TString numDir, TString denDir)  {
  //        h = ratio(s["file"], s["afterDir"], "m0_m12_%s"%process, s["beforeDir"], "m0_m12_%s_noweight"%process) 
  TH2D *num=addHist2D(numDir+"m0_m12",filename);
  TH2D *den=addHistDen2D(denDir+"m0_m12",filename);
  TH2D *ratio=num->Clone();
  ratio->Divide(den);
  ratio->Divide(cmssmNloXsHisto(filename,denDir));

  //#eff weighted by xs
  //  out.Divide(cmssmNloXsHisto(model, scale)) #divide by total xs
  return ratio;

}

// TH2* cmssmNloYieldHisto(TString filename, TString numDir, TString denDir) {

//  TH2D *h=sumHist2D(); 

// }

void plotSys(Double_t m0=1100., Double_t m12=480., double lumi=4679.) {

  TString mudir="/vols/cms02/georgia/SUSYv2_Jan25/onelepton/scripts/resultsMCgrid_metdown_flat/";
  TString edir="/vols/cms02/georgia/SUSYv2_Jan25/onelepton/scripts/e_resultsMCgrid_metdown_flat/";

  TString efile=edir+"Electrons_mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1.root"; 
  TString mufile=mudir+"Muons_mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1.root";

  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  TCanvas *c=getaCanvas("_eff");

  TH2D *mhevt1=cmssmNloYieldHisto(mufile,"Counter_BSMGrid_SumLepPT250secondDcut500_scale1/","Counter_BSMGrid_NoCuts_scale1/");
  TH2D *mhevt2=cmssmNloYieldHisto(mufile,"Counter_BSMGrid_SumLepPT350secondDcut500_scale1/","Counter_BSMGrid_NoCuts_scale1/");
  TH2D *mhevt3=cmssmNloYieldHisto(mufile,"Counter_BSMGrid_SumLepPT450secondDcut500_scale1/","Counter_BSMGrid_NoCuts_scale1/");

  TH2D *hevt1=cmssmNloYieldHisto(efile,"Counter_BSMGrid_SumLepPT250secondDcut500_scale1/","Counter_BSMGrid_NoCuts_scale1/");
  TH2D *hevt2=cmssmNloYieldHisto(efile,"Counter_BSMGrid_SumLepPT350secondDcut500_scale1/","Counter_BSMGrid_NoCuts_scale1/");
  TH2D *hevt3=cmssmNloYieldHisto(efile,"Counter_BSMGrid_SumLepPT450secondDcut500_scale1/","Counter_BSMGrid_NoCuts_scale1/");

  Int_t rbin=4; 
  Double_t step; step=double(rbin)*10.;
  Double_t divf=2.;

  mhevt1->RebinX(rbin); mhevt2->RebinX(rbin); mhevt3->RebinX(rbin);
  mhevt1->RebinY(rbin); mhevt2->RebinY(rbin); mhevt3->RebinY(rbin);
  hevt1->RebinX(rbin); hevt2->RebinX(rbin); hevt3->RebinX(rbin);
  hevt1->RebinY(rbin); hevt2->RebinY(rbin); hevt3->RebinY(rbin);


  m0=0.; m12=0.;

   for (int im0=m0; im0<2000.; im0+=step) {
     for (int im12=m12; im12<800.; im12+=step) {

      int binx1=hevt1->GetXaxis()->FindBin(im0);  int biny1=hevt1->GetYaxis()->FindBin(im12);
      int binx2=hevt2->GetXaxis()->FindBin(im0);  int biny2=hevt2->GetYaxis()->FindBin(im12);
      int binx3=hevt3->GetXaxis()->FindBin(im0);  int biny3=hevt3->GetYaxis()->FindBin(im12);

      double mevt1=lumi*mhevt1->GetBinContent(binx1,biny1)/double(divf);
      double mevt2=lumi*mhevt2->GetBinContent(binx2,biny2)/double(divf);
      double mevt3=lumi*mhevt3->GetBinContent(binx3,biny3)/double(divf);
      
      double evt1=lumi*hevt1->GetBinContent(binx1,biny1)/double(divf);
      double evt2=lumi*hevt2->GetBinContent(binx2,biny2)/double(divf);
      double evt3=lumi*hevt3->GetBinContent(binx3,biny3)/double(divf);
      
      //      if (evt1!=0 || evt2!=0 || evt3!=0) {
	cout << im0 << " " << im12 << "\t" << mevt1 << "\t" << mevt2 << "\t" << mevt3 << 
	  "\t" << evt1 << "\t" << evt2 << "\t" << evt3 << endl;
	//      }
     } //m12 loop 
   } // m0 loop


}
