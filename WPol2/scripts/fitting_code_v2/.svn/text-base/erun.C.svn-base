void erun() {
  
  gSystem->Load("libRooFit"); 
  gSystem->Load("libRooFitCore");
  gSystem->Load("libMatrix");
  gSystem->Load("libGpad");
   gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->Reset();
  gROOT->ProcessLine("setTDRStyle()");
  gStyle->SetOptFit(0);


  using namespace RooFit;

  //  gROOT->ProcessLine(".L eRooWPlus.cxx++");
  gSystem->Load("eRooWPlus_cxx.so");
  // gROOT->ProcessLine(".L eRooWMinus.cxx++");
  gSystem->Load("eRooWMinus_cxx.so");
  
  //  gROOT->ProcessLine(".L eRooWPlusExtended.cxx++");
  //gSystem->Load("eRooWPlusExtended_cxx.so");
  //gROOT->ProcessLine(".L eRooWMinusExtended.cxx++");
  //gSystem->Load("eRooWMinusExtended_cxx.so");

  gROOT->ProcessLine(".x roo_efitWH.C");

}
