#include "LimitCalc.hh"

string convertIn(double number)
{
  stringstream ss;
  ss << number;
  return ss.str();
}



FourBin::FourBin(double non_, double noff_, double nonbar_, double noffbar_,double rhonom_, double rhoSigma_,double tauprime_,TString method_):non(non_),noff(noff_),nonbar(nonbar_),noffbar(noffbar_),rhonom(rhonom_),rhonomSigma(rhoSigma_),tau(noffbar_/nonbar_),tauprime(tauprime_),method(method_){

  
  //put everything into strings
  TString S_non = convertIn(non);
  TString S_noff = convertIn(noff);

  TString S_nonUp = convertIn(non+10);
  TString S_noffUp = convertIn(noff*10);

  TString S_nonbar = convertIn(nonbar);
  TString S_nonbarUp = convertIn(nonbar*10);
  TString S_nonbarLow = convertIn(nonbar/10);

  TString S_noffbar = convertIn(noffbar);
  TString S_noffbarUp = convertIn(noffbar*10);
  TString S_noffbarLow = convertIn(noffbar/10);

  TString S_tau = convertIn(tau);
  TString S_tauUp = convertIn(tau*10);

  TString S_rhonom = convertIn(rhonom);
  TString S_rhonomUp = convertIn(rhonom*10);

  TString S_rhonomSigma = convertIn(rhonomSigma);

  TString S_tauprime = convertIn(tauprime);
  TString S_tauprimeLow = convertIn(tauprime/10);
  TString S_tauprimeUp = convertIn(tauprime+2);
  

  // make model
  wspace = new RooWorkspace("wspace");

  wspace->factory("Poisson::on(non[0,"+S_nonUp+"], sum::splusb(s[0.5,0,"+S_nonUp+"],b["+S_non+",0,"+S_nonUp+"]))");
  wspace->factory("Poisson::off(noff[0,"+S_noffUp+"], sum::sprimeplusboff(prod::taub(b,tau["+S_tau+",0.,"+S_tauUp+"],rho["+S_rhonom+",0,10]),prod::sprime(s,tauprime[0])))");
  
  wspace->factory("Poisson::onbar(nonbar["+S_nonbarLow+","+S_nonbarUp+"], bbar["+S_nonbar+","+S_nonbarLow+","+S_nonbarUp+"])");
  wspace->factory("Poisson::offbar(noffbar["+S_noffbarLow+","+S_noffbarUp+"], prod::lambdaoffbar(bbar, tau))");
  wspace->factory("Gaussian::mcCons(rhonom["+S_rhonom+",0,"+S_rhonomUp+"], rho, sigma["+S_rhonomSigma+"])");
  // wspace->factory("Gaussian::SmcCons(tauprimenom["+S_tauprime+",0,"+S_tauprimeUp+"],tauprime,tauprimesigma[.3])");
 
  
  wspace->factory("PROD::model(on,off,onbar,offbar,mcCons)");
  wspace->defineSet("obs","non,noff,nonbar,noffbar,rhonom");
  
  wspace->factory("Uniform::prior_poi({s})");
  wspace->factory("Uniform::prior_nuis({b,bbar,tau, rho})");
  wspace->factory("PROD::prior(prior_poi,prior_nuis)"); 

  wspace->defineSet("poi","s");
  wspace->defineSet("nuis","b,tau,rho,bbar");
  //  wspace->defineSet("mSuGraCons","tauprimenom");
  
  const RooArgSet* lolArgSet=wspace->set("obs");
  newSet=new RooArgSet(*lolArgSet);
  
  newSet->setRealValue("non"    ,non);
  newSet->setRealValue("noff"   ,noff);
  newSet->setRealValue("nonbar" ,nonbar);
  newSet->setRealValue("noffbar",noffbar);
  newSet->setRealValue("rhonom" ,rhonom);
  //  newSet->setRealValue("tauprimenom",tauprime_);

  data=new RooDataSet("obsDataSet","title",*lolArgSet);
  
    
  data->add(*lolArgSet);
  wspace->import(*data);


  modelConfig = new ModelConfig("FourBins");
  
}

 Int_t FourBin::IsIn(double tauprimenom_, double signalnom_){

   RooRealVar *tauPrime = wspace->var("tauprime");
   // cout << "myTauPrime " << myTauPrime << endl;
   tauPrime->setVal(tauprimenom_);
   // tauPrime->Print();
   
    
  
    modelConfig->SetWorkspace(*wspace);
    modelConfig->SetPdf(*wspace->pdf("model"));
    modelConfig->SetPriorPdf(*wspace->pdf("prior"));
    modelConfig->SetParametersOfInterest(*wspace->set("poi"));
    modelConfig->SetNuisanceParameters(*wspace->set("nuis"));
    wspace->import(*modelConfig);
    // wspace->writeToFile("FourBin.root");
  

  
    //  RooMsgService::instance().setStreamStatus(0,kFALSE);
    // RooMsgService::instance().setStreamStatus(1,kFALSE);
    // RooMsgService::instance().setStreamStatus(2,kFALSE);
   

  //for convenience later define realvar for signal
    RooRealVar *s = wspace->var("s");
    
    s->setVal(1);
   
    //  wspace->Print();

    

    //////////////////////////////////////////////////
    // If you want to see the covariance matrix uncomment
    wspace->pdf("model")->fitTo(*data,PrintLevel(-1));



   RooArgList nuispar(*wspace->set("nuis"));
    for(int i = 0; i < nuispar.getSize();++i){
     RooRealVar &par = (RooRealVar&) nuispar[i];
     par.setMin(std::max(par.getVal()-10*par.getError(),par.getMin() ) );
     par.setMax(std::min(par.getVal()+10*par.getError(),par.getMax() ) );
    }
    

    RooArgList spar(*wspace->set("poi"));
    for(int i = 0; i < spar.getSize();++i){
      RooRealVar &pars = (RooRealVar&) spar[i];
      pars.setMin(std::max(pars.getVal()-10*pars.getError(),pars.getMin() ) );
      pars.setMax(std::min(pars.getVal()+10*pars.getError(),pars.getMax() ) );
    }
    
   

    // cout << " method " << method << endl;

   if(method == "Profile"){


     cout << " profile likelihood " << endl;
     // use ProfileLikelihood
     ProfileLikelihoodCalculator plc(*data, *modelConfig);
     plc.SetConfidenceLevel(0.95);
     LikelihoodInterval* plInt = plc.GetInterval();
     RooFit::MsgLevel msglevel = RooMsgService::instance().globalKillBelow();
     RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
     plInt->LowerLimit( *wspace->var("s") ); // get ugly print out of the way. Fix.
     RooMsgService::instance().setGlobalKillBelow(msglevel);
    
     ////////////////////////////////////
     // querry intervals
     cout << " " << endl;
     Double_t lowerlimit_pl =  plInt->LowerLimit( *s );
     Double_t upperlimit_pl =  plInt->UpperLimit( *s ); 

     cout << "Profile Likelihood interval on s = [" << 
       lowerlimit_pl << ", " <<
       upperlimit_pl << "]" << endl; 

     if(upperlimit_pl == 0) return -1;

     if(signalnom_ < upperlimit_pl) return 1;
     else return 0;
      //  cout  << " signal " << signalnom_ << " tauprimenom " << tauprimenom_ << endl;
     //  return plInt->IsInInterval(RooArgSet(*s));
     
   }

   if(method == "FC"){
     
     cout << " start Feldman Cousins " << endl;
     // use FeldmaCousins (takes ~20 min)  
     FeldmanCousins fc(*data, *modelConfig);
     fc.SetConfidenceLevel(0.95);
     //number counting: dataset always has 1 entry with N events observed
     fc.FluctuateNumDataEntries(false); 
     fc.UseAdaptiveSampling(true);
     fc.SetNBins(70);
     PointSetInterval* fcInt = NULL;
     // takes 7 minutes
     if(method == "FC" || method == "all"){
       fcInt = (PointSetInterval*) fc.GetInterval(); // fix cast
     }
     double_t lowerlimit_fc =  fcInt->LowerLimit( *wspace->var("s") ) ;
     double_t upperlimit_fc =  fcInt->UpperLimit( *wspace->var("s") ) ;
     cout << "Feldman Cousins interval on s = [" << lowerlimit_fc
      << ", " << upperlimit_fc
      << "]" << endl;
    //Feldman Cousins interval on s = [18.75 +/- 2.45, 83.75 +/- 2.45]
     

     if(upperlimit_fc == 0) return -1;
     if(signalnom_ < upperlimit_fc) return 1;
     else return 0;
    
     

   }
   
    
  if(method == "Bayes"){

    cout << " start bayesian " << endl;
    // use BayesianCalculator (only 1-d parameter of interest, slow for this problem)  
    BayesianCalculator bc(*data, *modelConfig);
    bc.SetConfidenceLevel(0.95);
    SimpleInterval* bInt = NULL;
    if(wspace->set("poi")->getSize() == 1)   {
      bInt = bc.GetInterval();
    } else{
      cout << "Bayesian Calc. only supports on parameter of interest" << endl;
    }
    if( wspace->set("poi")->getSize() == 1)   {
      double_t lowerlimit_bInt =  bInt->LowerLimit() ;
      double_t upperlimit_bInt =  bInt->UpperLimit() ;
      
      cout << "Bayesian interval on s = [" << lowerlimit_bInt
	   << ", " << upperlimit_bInt
	   << "]" << endl;
      
      if(upperlimit_bInt == 0) return -1;
      if(signalnom_ < upperlimit_bInt) return 1;
      else return 0;
     
    } 
     else return -1;
  }
  
  

  if(method == "MCMC"){

    cout << " start MCMC " << endl;
    // use MCMCCalculator  (takes about 1 min)
    // Want an efficient proposal function, so derive it from covariance
    // matrix of fit
    RooFitResult* fit = wspace->pdf("model")->fitTo(*data,Save());
    ProposalHelper ph;
    ph.SetVariables((RooArgSet&)fit->floatParsFinal());
    ph.SetCovMatrix(fit->covarianceMatrix());
    ph.SetUpdateProposalParameters(kTRUE); // auto-create mean vars and add mappings
    ph.SetCacheSize(100);
    ProposalFunction* pf = ph.GetProposalFunction();
    
    MCMCCalculator mc(*data, *modelConfig);
    mc.SetConfidenceLevel(0.95);
    mc.SetProposalFunction(*pf);
    mc.SetNumBurnInSteps(1); // first N steps to be ignored as burn-in
    mc.SetNumIters(50000);
    mc.SetLeftSideTailFraction(0.5); // make a central interval
    MCMCInterval* mcInt = NULL;
    
    mcInt = mc.GetInterval();

    double_t lowerlimit_mcInt =  mcInt->LowerLimit(*wspace->var("s")) ;
    double_t upperlimit_mcInt =  mcInt->UpperLimit(*wspace->var("s")) ;
      
    cout << " interval on s = [" << lowerlimit_mcInt
	 << ", " << upperlimit_mcInt
	 << "]" << endl;
    
    if(upperlimit_mcInt == 0) return -1;
    if(signalnom_ < upperlimit_mcInt) return 1;
    else return 0;
    
  }


  return false;
  

  //////////////////////////////////////
  // Make some  plots


  /*  TCanvas* c1 = (TCanvas*) gROOT->Get("c1");  
  if(!c1)    c1 = new TCanvas("c1");
   c1->Divide(3);
   c1->cd(1);

  LikelihoodIntervalPlot* lrplot = new LikelihoodIntervalPlot(plInt);
  lrplot->Draw();
 
  if( wspace->set("poi")->getSize() == 1)   {
    c1->cd(2);
    RooPlot* bplot = bc.GetPosteriorPlot();
    bplot->Draw();// the plot takes a long time
  } 

  
  if(wspace->set("poi")->getSize() == 1)    c1->cd(3);
  else  c1->cd(2);
  MCMCIntervalPlot mcPlot(*mcInt); 
  mcPlot.Draw();
  */

  ///////////////////////////////////
}




double CaC(Double_t observed,Double_t expectedBackground,Double_t sys,TString method)
{
  /////////////////////////////////////////
  // An example of setting a limit in a number counting experiment with uncertainty on background and signal
  /////////////////////////////////////////

  // to time the macro
  //  TStopwatch t;
  //  t.Start();

  TString S_obs = convertIn(observed);
  TString S_obs_up = convertIn(observed*10);

  TString S_exp = convertIn(expectedBackground);
  TString S_exp_up = convertIn(expectedBackground*10);
  TString S_exp_low = convertIn(expectedBackground/10);
  TString S_obs_half = convertIn(observed/2);

  TString S_sys = convertIn(sys/expectedBackground);

  cout << " Sys " << S_sys << endl;

  /////////////////////////////////////////
  // The Model building stage
  /////////////////////////////////////////
  RooWorkspace* wspace = new RooWorkspace();
  wspace->factory("Poisson::countingModel(obs["+S_obs+"+,0,"+S_obs_up+"], sum(s[1,0,+"+S_obs_up+"]*ratioSigEff[1.,0,2.],b["+S_exp+","+S_exp_low+","+S_exp_up+"]*ratioBkgEff[1.,0.,2.]))"); // counting model

  wspace->factory("Gaussian::sigConstraint(1,ratioSigEff,0.01)"); // 5% signal efficiency uncertainty
  wspace->factory("Gaussian::bkgConstraint(1,ratioBkgEff,"+S_sys+")"); // 10% background efficiency uncertainty
  wspace->factory("PROD::modelWithConstraints(countingModel,sigConstraint,bkgConstraint)"); // product of terms
  wspace->Print();

  RooAbsPdf* modelWithConstraints = wspace->pdf("modelWithConstraints"); // get the model
  RooRealVar* obs = wspace->var("obs"); // get the observable
  RooRealVar* s = wspace->var("s"); // get the signal we care about
  RooRealVar* b = wspace->var("b"); // get the background and set it to a constant.  Uncertainty included in ratioBkgEff
  b->setConstant();
  RooRealVar* ratioSigEff = wspace->var("ratioSigEff"); // get uncertaint parameter to constrain
  RooRealVar* ratioBkgEff = wspace->var("ratioBkgEff"); // get uncertaint parameter to constrain
  // RooArgSet constrainedParams(*ratioSigEff, *ratioBkgEff); // need to constrain these in the fit (should change default behavior)
  RooArgSet constrainedParams(*ratioSigEff, *ratioBkgEff); // need to constrain these in the fit (should change default behavior)


  // Create an example dataset with 160 observed events
  obs->setVal(1.);
  RooDataSet* data = new RooDataSet("exampleData", "exampleData", RooArgSet(*obs));
  data->add(*obs);

  RooArgSet all(*s, *ratioBkgEff, *ratioSigEff);

  // not necessary
  modelWithConstraints->fitTo(*data, RooFit::Constrain(RooArgSet(*ratioSigEff, *ratioBkgEff)));

  s->setMin(std::max(s->getVal()-10*s->getError(),s->getMin() ) );
  s->setMax(std::min(s->getVal()+10*s->getError(),s->getMax() ) );

  // Now let's make some confidence intervals for s, our parameter of interest
  RooArgSet paramOfInterest(*s);

  ModelConfig modelConfig(new RooWorkspace());
  modelConfig.SetPdf(*modelWithConstraints);
  modelConfig.SetParametersOfInterest(paramOfInterest);


  // First, let's use a Calculator based on the Profile Likelihood Ratio
  //ProfileLikelihoodCalculator plc(*data, *modelWithConstraints, paramOfInterest); 
  ProfileLikelihoodCalculator plc(*data, modelConfig); 
  plc.SetTestSize(.05);
  ConfInterval* lrint = plc.GetInterval();  // that was easy.

  // Let's make a plot
  TCanvas* dataCanvas = new TCanvas("dataCanvas");
  dataCanvas->Divide(2,1);

  dataCanvas->cd(1);
  LikelihoodIntervalPlot plotInt((LikelihoodInterval*)lrint);
  plotInt.SetTitle("Profile Likelihood Ratio and Posterior for S");
  plotInt.Draw();

  ConfInterval* fcint = NULL;
  FeldmanCousins fc(*data, modelConfig);
  if(method == "FC" || method == "all"){
    // Second, use a Calculator based on the Feldman Cousins technique
   
    fc.UseAdaptiveSampling(true);
    fc.FluctuateNumDataEntries(false); // number counting analysis: dataset always has 1 entry with N events observed
    fc.SetNBins(100); // number of points to test per parameter
    fc.SetTestSize(.05);// 95% CL
    //  fc.SaveBeltToFile(true); // optional
   
    fcint = fc.GetInterval();  // that was easy.
  }

  cout << " before fit " << endl;
  RooFitResult* fit = modelWithConstraints->fitTo(*data, Save(true));
  cout <<" after fit " << endl;

  
    // Third, use a Calculator based on Markov Chain monte carlo
    // Before configuring the calculator, let's make a ProposalFunction
    // that will achieve a high acceptance rate
    ProposalHelper ph;
    ph.SetVariables((RooArgSet&)fit->floatParsFinal());
    ph.SetCovMatrix(fit->covarianceMatrix());
    ph.SetUpdateProposalParameters(true);
    ph.SetCacheSize(100);
    ProposalFunction* pdfProp = ph.GetProposalFunction();  // that was easy
    
    MCMCCalculator mc(*data, modelConfig);
    mc.SetNumIters(20000); // steps to propose in the chain
    mc.SetTestSize(.05); // 95% CL
    mc.SetNumBurnInSteps(40); // ignore first N steps in chain as "burn in"
    mc.SetProposalFunction(*pdfProp);
    mc.SetLeftSideTailFraction(0.5);  // find a "central" interval
    MCMCInterval* mcInt = (MCMCInterval*)mc.GetInterval();  // that was easy

    if(method == "MCMC" || method == "all"){
      // Plot MCMC interval and print some statistics
      MCMCIntervalPlot mcPlot(*mcInt);
      mcPlot.SetLineColor(kMagenta);
      mcPlot.SetLineWidth(2);
      mcPlot.Draw("same");
      
      double mcul = mcInt->UpperLimit(*s);
      double mcll = mcInt->LowerLimit(*s);
      cout << "MCMC lower limit on s = " << mcll << endl;
      cout << "MCMC upper limit on s = " << mcul << endl;
      cout << "MCMC Actual confidence level: "
	   << mcInt->GetActualConfidenceLevel() << endl;
      
      // 3-d plot of the parameter points
      dataCanvas->cd(2);
      // also plot the points in the markov chain
      TTree& chain =  ((RooTreeDataStore*) mcInt->GetChainAsDataSet()->store())->tree();
      chain.SetMarkerStyle(6);
      chain.SetMarkerColor(kRed);
      chain.Draw("s:ratioSigEff:ratioBkgEff","weight_MarkovChain_local_","box"); // 3-d box proporional to posterior
    }

    if(method == "FC" || method == "all"){
    


  }

  if(method == "Profile" || method == "all"){
    // Get Lower and Upper limits from Profile Calculator
    cout << "Profile lower limit on s = " << ((LikelihoodInterval*) lrint)->LowerLimit(*s) << endl;
    cout << "Profile upper limit on s = " << ((LikelihoodInterval*) lrint)->UpperLimit(*s) << endl;
  }

  // Get Lower and Upper limits from FeldmanCousins with profile construction
   if (fcint != NULL && (  method == "FC"|| method == "all")) {
    // the points used in the profile construction
     //    TTree& parameterScan =  ((RooTreeDataStore*) fc.GetPointsToScan()->store())->tree();
     //  parameterScan.SetMarkerStyle(24);
     //  parameterScan.Draw("s:ratioSigEff:ratioBkgEff","","same");

    
    double fcul = ((PointSetInterval*) fcint)->UpperLimit(*s);
    double fcll = ((PointSetInterval*) fcint)->LowerLimit(*s);
    cout << "FC lower limit on s = " << fcll << endl;
    cout << "FC upper limit on s = " << fcul << endl;
    // TLine* fcllLine = new TLine(fcll, 0, fcll, 1);
    // TLine* fculLine = new TLine(fcul, 0, fcul, 1);
    //  fcllLine->SetLineColor(kRed);
    // fculLine->SetLineColor(kRed);
    // // fcllLine->Draw("same");
    // fculLine->Draw("same");
    // dataCanvas->Update();
     }

 
  



  if(method == "Profile" || method == "all")return  ((LikelihoodInterval*) lrint)->UpperLimit(*s);
  if(method == "FC") return ((PointSetInterval*) fcint)->UpperLimit(*s);
  if(method == "MCMC") return mcInt->UpperLimit(*s);

  return -1;

}


