void run() {
  
  gROOT->ProcessLine(".L RooWPlus.cxx++");
  gSystem->Load("RooWPlus_cxx.so");
  gROOT->ProcessLine(".L RooWMinus.cxx++");
  gSystem->Load("RooWMinus_cxx.so");
  
  gROOT->ProcessLine(".x make_fit.C");

}
