void simrun() {
  
  gSystem->Load("libRooFit"); 
  gSystem->Load("libRooFitCore");
  gSystem->Load("libMatrix");
  gSystem->Load("libGpad");
  
  using namespace RooFit;

  gROOT->ProcessLine(".L eRooWPlus.cxx++");
  gSystem->Load("eRooWPlus_cxx.so");
  gROOT->ProcessLine(".L eRooWMinus.cxx++");
  gSystem->Load("eRooWMinus_cxx.so");
  
  // gROOT->ProcessLine(".L eRooWPlusExtended.cxx++");
  // gSystem->Load("eRooWPlusExtended_cxx.so");
  //gROOT->ProcessLine(".L eRooWMinusExtended.cxx++");
  // gSystem->Load("eRooWMinusExtended_cxx.so");

  gROOT->ProcessLine(".L RooWPlus.cxx++");
  gSystem->Load("RooWPlus_cxx.so");
  gROOT->ProcessLine(".L RooWMinus.cxx++");
  gSystem->Load("RooWMinus_cxx.so");
  
  // gROOT->ProcessLine(".L RooWPlusExtended.cxx++");
  // gSystem->Load("RooWPlusExtended_cxx.so");
  // gROOT->ProcessLine(".L RooWMinusExtended.cxx++");
  //gSystem->Load("RooWMinusExtended_cxx.so");

  gROOT->ProcessLine(".x roo_sim.C");

}
