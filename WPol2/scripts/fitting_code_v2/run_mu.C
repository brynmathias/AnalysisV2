void run_mu() {
  
  gSystem->Load("libRooFit"); 
  gSystem->Load("libRooFitCore");
  gSystem->Load("libMatrix");
  gSystem->Load("libGpad");
  
  using namespace RooFit;

  gROOT->ProcessLine(".L RooWPlus.cxx++");
  gSystem->Load("RooWPlus_cxx.so");
  gROOT->ProcessLine(".L RooWMinus.cxx++");
  gSystem->Load("RooWMinus_cxx.so");
  
  gROOT->ProcessLine(".L RooWPlusExt.cxx++");
  gSystem->Load("RooWPlusExt.so");
  gROOT->ProcessLine(".L RooWMinusExt.cxx++");

 

  gSystem->Load("RooWMinusExt_cxx.so");
 
  gROOT->ProcessLine(".x roo_fitWH_mu.C");

}
