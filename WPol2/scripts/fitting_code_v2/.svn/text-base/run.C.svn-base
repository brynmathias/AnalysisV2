void run() {
  
  gSystem->Load("libRooFit"); 
  gSystem->Load("libRooFitCore");
  gSystem->Load("libMatrix");
  gSystem->Load("libGpad");
  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->Reset();
  gROOT->ProcessLine("setTDRStyle()");
  gStyle->SetOptFit(0);


  //  gROOT->ProcessLine("setTDRStyle()");
  using namespace RooFit;

  gROOT->ProcessLine(".L RooWPlus.cxx++");
  gSystem->Load("RooWPlus_cxx.so");
  gROOT->ProcessLine(".L RooWMinus.cxx++");
  gSystem->Load("RooWMinus_cxx.so");
  
  gROOT->ProcessLine(".L RooWPlusExtended.cxx++");
  gSystem->Load("RooWPlusExtended_cxx.so");
  gROOT->ProcessLine(".L RooWMinusExtended.cxx++");
  gSystem->Load("RooWMinusExtended_cxx.so");

  gROOT->ProcessLine(".x roo_fitWH.C");

}
