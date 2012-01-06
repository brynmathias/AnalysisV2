void runZ() {
  
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

  gROOT->ProcessLine(".L RooZPlus.cxx+");
  gSystem->Load("RooZPlus_cxx.so");
  // gROOT->ProcessLine(".L RooWMinus.cxx++");
  // gSystem->Load("RooWMinus_cxx.so");
  
  gROOT->ProcessLine(".L RooZPlusExtended.cxx+");
  gSystem->Load("RooZPlusExtended_cxx.so");
  // gROOT->ProcessLine(".L RooWMinusExtended.cxx++");
  // gSystem->Load("RooWMinusExtended_cxx.so");

  gROOT->ProcessLine(".x roo_fitZH.C");

}
