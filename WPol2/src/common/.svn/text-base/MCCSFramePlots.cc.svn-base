#include "MCCSFramePlots.hh"
namespace Operation {


  //====================================
  // MCCSFramePlots implementation
  //====================================

  //some comments on the reweighting procedure in the A2 and A3 parameters. Things are slightly more complicated than in the f_{i} case
  //once again, it must be split into the separate charges (unlike at CDF)
  //but also in this case, we are making templates [2](1 + [0]*cos(x) + [1]*cos(2x)) which doesn't quite work
  //since we cannot set [2] to 0 (like we did before (1,0,0) (0,1,0) (0,0,1)) we actually do [0] + [1]*cos(x) + [2]*cos(2x)
  //this means that the parameter [1] is actually A2*norm*some_constant etc
  //another complication is that the integral over cos(x) between (-pi,pi) = 0 so we cannot integrate over it.
  //Need to split this integration up into 3 bits (-pi, -pi/2) (-pi/2, pi/2) (pi/2, pi)
  //also, only take into account |phi|<3.14 (i.e. we are approximating pi) otherwise we remake the plots from (-1.00,1.00) as fractions of pi

  std::vector< std::vector<jFitParameters> > & GetCSPhiFitParameters() {
    static std::vector< std::vector<jFitParameters> > binned_fit_params = init_fit_params_CSPhi();
    return binned_fit_params;
  }

  std::vector< std::vector<jFitParameters> > & GetCSPhiZFitParameters() {
    static std::vector< std::vector<jFitParameters> > binned_fit_paramsZ = init_fit_params_CSPhi_Z();
    return binned_fit_paramsZ;
  }

  std::vector< std::vector<jFitParameters> > & GetCSCosThetaZFitParameters() {
    static std::vector< std::vector<jFitParameters> > binned_fit_paramsZ2 = init_fit_params_CSCosTheta_Z();
    return binned_fit_paramsZ2;
  }

  double CSPhiBinFraction(const double & alpha, const double & beta, const double & gamma, const unsigned int & bin) {

    //the format i'm using for the fit function is as follows:
    //alpha + beta * cos(x) + gamma * cos(2x)
    //the total integral over 2pi will result in 2pi*alpha

    //for all our plots, we have a defined bin width for the gen level cos(theta*) plots
    double bin_width = 0.01;
    //bin 0 by our definition is the bin between -3.15 and -3.14 etc
    //subtract 3.15 to go back to region phi = (-3.15, +3.15)
    double bin_lowedge = double(bin)*bin_width - 3.15;

    //now make some easy to use variable names for the calculation below
    double a = bin_lowedge;
    double b = bin_lowedge + bin_width;

    //unlike the f_i case, the complication here arises that the cosx and cos2x templates can go negative. and the total integral over the range is 0! This means
    //we must rearrange our fit to prevent this, so we have templates for (1+cosx) and (1+cos2x) and 1. Later, when we put these together from roofit, we can
    //extract the A2 and A3 co-efficients with the appropriate errors.

    double bin_integral = CSPhiIntegralValue(a, b, alpha, beta, gamma);

    double total_integral = alpha*6.28;
    double fraction = bin_integral / total_integral;

    return fraction;

  }

  double CSPhiBinFractionTemplate(const unsigned int & norm_type, const unsigned int & bin) {

    //for all our plots, we have a defined bin width for the gen level cos(theta*) plots
    double bin_width = 0.01;
    //bin 0 by our definition is the bin between -3.15 and -3.14 etc
    //subtract 3.15 to go back to region phi = (-3.15, +3.15)
    double bin_lowedge = double(bin)*bin_width - 3.15;

    //now make some easy to use variable names for the calculation below
    double a = bin_lowedge;
    double b = bin_lowedge + bin_width;

    double bin_integral = 0.0;
    //for the 3 different template cases, the total integral is always 2pi (other factors cancel) so we have 1, 1+cos(x) and 1+cos(2x)
    if(norm_type == 0) bin_integral = (b-a);
    if(norm_type == 1) bin_integral = (b+sin(b)) - (a+sin(a));
    if(norm_type == 2) bin_integral = (b+(0.5*sin(2.0*b))) - (a+(0.5*sin(2.0*a)));
    //std::cout << "bin_integral = "<< bin_integral << std::endl;

    double total_integral = (6.28);
    //std::cout << "total_integral = "<< total_integral << std::endl;
    double fraction = bin_integral / total_integral;

    return fraction;

  }

  double CSPhiIntegralValue(const double & a, const double & b, const double & alpha, const double & beta, const double & gamma) {
    //below is what you get if you integrate by hand the three components and evaluate them between b and a
    double alpha_part = (b-a);
    double beta_part = (3.0*TMath::Pi()/16.0) * (sin(b) - sin(a));
    double gamma_part = 0.25 * 0.5 * (sin(2.0*b) - sin(2.0*a)); //when you integrate cos(2x) you get 0.5 sin(2x)
    double total_integral = ((alpha*alpha_part) + (beta*beta_part) + (gamma*gamma_part));
    return total_integral;
  }

  double CSPhiCorrFactor(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type, const TString & boson_type) {

    if(norm_type > 2) std::cout << "Why is norm_type greater than 2? There are only 3 polarisation modes!" << std::endl;
    if(boson_type != "W" && boson_type != "Z") std::cout << "What boson are you trying to look at? I only know of the W and the Z!" << std::endl;
    double alpha=0.0, beta=0.0, gamma=0.0;

    double norm_type_ratio = CSPhiBinFractionTemplate(norm_type, bin);
    //std::cout << "norm_type_ratio = " << norm_type_ratio << std::endl;

    //now here is where the lookup for the appropriate alpha,beta,gamma factors happens according to W Pt and Y bins
    //revise this quanta stuff as appropriate - the bins we are using are:
    //W Pt, 0-50, 50-100, 100+
    //W |Y|, 0-0.5, 0.5-1.0, 1.0-1.5, 1.5-2.0, 2.0-2.5, 2.5-3.0, 3.0+
    unsigned int PTWbin = 0;
    if(PTW <= 50.0) PTWbin = 0;
    if(PTW <= 100.0 && PTW > 50.0) PTWbin = 1;
    if(PTW > 100.0) PTWbin = 2;

    unsigned int YWbin = 0;
    if(fabs(YW) <= 0.5) YWbin=0;
    if(fabs(YW) <= 1.0 && fabs(YW) > 0.5) YWbin=1;
    if(fabs(YW) <= 1.5 && fabs(YW) > 1.0) YWbin=2;
    if(fabs(YW) <= 2.0 && fabs(YW) > 1.5) YWbin=3;
    if(fabs(YW) <= 2.5 && fabs(YW) > 2.0) YWbin=4;
    if(fabs(YW) <= 3.0 && fabs(YW) > 2.5) YWbin=5;
    if(fabs(YW) > 3.0) YWbin=6;

    if(boson_type == "W") {
      if(poscharge) {
	alpha = GetCSPhiFitParameters().at(PTWbin).at(YWbin).alpha_plus;
	beta = -1.0*GetCSPhiFitParameters().at(PTWbin).at(YWbin).beta_plus; //this corrects for the fact that in the fit, we use -3pi/16 when it should be +3pi/16 (just a convention to get the right sign of A3)
	gamma = GetCSPhiFitParameters().at(PTWbin).at(YWbin).gamma_plus;
      }else{
	alpha = GetCSPhiFitParameters().at(PTWbin).at(YWbin).alpha_minus;
	beta = -1.0*GetCSPhiFitParameters().at(PTWbin).at(YWbin).beta_minus;
	gamma = GetCSPhiFitParameters().at(PTWbin).at(YWbin).gamma_minus;
      }
    }
    if(boson_type == "Z") {
      //it can only be pos charge per our initial definition of what lepton to look at...
      if(poscharge) {
	alpha = GetCSPhiZFitParameters().at(PTWbin).at(YWbin).alpha_plus;
	beta = -1.0*GetCSPhiZFitParameters().at(PTWbin).at(YWbin).beta_plus; //to avoid confusion, we keep the same fit function, so we correct it in the same way
	gamma = GetCSPhiZFitParameters().at(PTWbin).at(YWbin).gamma_plus;
      }
    }

    double curr_type_ratio = CSPhiBinFraction(alpha, beta, gamma, bin); //test for 0
    //std::cout << "curr_type_ratio = " << curr_type_ratio << std::endl;

    double corr_factor = norm_type_ratio/curr_type_ratio;

    return corr_factor;
  }

  double CSCosThetaBinFraction(const double & alpha, const double & beta, const double & gamma, const unsigned int & bin) {

    //the format i'm using for the fit function is as follows:
    //alpha + beta * (x) + gamma * (x*x) 

    //for all our plots, we have a defined bin width for the gen level cos(theta) CS plots
    double bin_width = 0.01;
    //bin 0 by our definition is the bin between -1.00 and -0.99 etc
    //subtract 1.0 below to go back to region cos(theta*) = (-1.0, 1.0)
    double bin_lowedge = double(bin)*bin_width - 1.0;

    //now make some easy to use variable names for the calculation below
    double a = bin_lowedge;
    double b = bin_lowedge + bin_width;

    //unlike the f_i case, the complication here arises that the x template can go negative. and the total integral over the range is then 0! This means
    //we must rearrange our fit to prevent this, so we have templates for (1+x) instead. 
    //Later, when we put these together from roofit, we can extract the A0 and A4 co-efficients with the appropriate errors.

    double bin_integral = CSCosThetaIntegralValue(a, b, alpha, beta, gamma);

    double total_integral = alpha*(8.0/3.0); //you get this factor 8/3 = 2+2/3  because only the integral over the 1 and x*x pieces survive [-1,1] - write down the fit function and satisfy yourself
    double fraction = bin_integral / total_integral;

    return fraction;

  }

  double CSCosThetaBinFractionTemplate(const unsigned int & norm_type, const unsigned int & bin) {

    //for all our plots, we have a defined bin width for the gen level cos(theta) CS plots
    double bin_width = 0.01;
    //bin 0 by our definition is the bin between -1.00 and -0.99 etc
    //subtract 1.0 below to go back to region cos(theta*) = (-1.0, 1.0)
    double bin_lowedge = double(bin)*bin_width - 1.0;

    //now make some easy to use variable names for the calculation below
    double a = bin_lowedge;
    double b = bin_lowedge + bin_width;

    double bin_integral = 0.0;
    //for the 3 different template cases, the total integral is 2, 2, 2/3 for the templates 1, 1+x and x*x, between [-1,1]
    if(norm_type == 0) bin_integral = (b-a);
    if(norm_type == 1) bin_integral = (b+(b*b/2.0)) - (a+(a*a/2.0));
    if(norm_type == 2) bin_integral = (b*b*b/3.0) - (a*a*a/3.0);
    //std::cout << "bin_integral = "<< bin_integral << std::endl;

    double total_integral = 0.0;
    if(norm_type == 0) total_integral = 2.0;
    if(norm_type == 1) total_integral = 2.0;
    if(norm_type == 2) total_integral = 2.0/3.0;
    //std::cout << "total_integral = "<< total_integral << std::endl;
    double fraction = bin_integral / total_integral;

    return fraction;

  }

  double CSCosThetaIntegralValue(const double & a, const double & b, const double & alpha, const double & beta, const double & gamma) {
    //below is what you get if you integrate by hand the three components and evaluate them between b and a
    double alpha_part = (b-a);
    double beta_part = (b*b/2.0) - (a*a/2.0); 
    double gamma_part = (b*b*b/3.0) - (a*a*a/3.0);
    double total_integral = (((alpha+(0.5*beta))*alpha_part) + (gamma*beta_part) + ((alpha-(1.5*beta))*gamma_part));
    return total_integral;
  }

  double CSCosThetaCorrFactor(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type, const TString & boson_type) {
    
    if(norm_type > 2) std::cout << "Why is norm_type greater than 2? There are only 3 polarisation modes!" << std::endl;
    if(boson_type != "Z") std::cout << "What boson are you trying to look at? This only works for the Z!" << std::endl;
    double alpha=0.0, beta=0.0, gamma=0.0;

    double norm_type_ratio = CSCosThetaBinFractionTemplate(norm_type, bin);
    //std::cout << "norm_type_ratio = " << norm_type_ratio << std::endl;

    //now here is where the lookup for the appropriate alpha,beta,gamma factors happens according to W Pt and Y bins
    //revise this quanta stuff as appropriate - the bins we are using are:
    //W Pt, 0-50, 50-100, 100+
    //W |Y|, 0-0.5, 0.5-1.0, 1.0-1.5, 1.5-2.0, 2.0-2.5, 2.5-3.0, 3.0+ 
    unsigned int PTWbin = 0;
    if(PTW <= 50.0) PTWbin = 0;
    if(PTW <= 100.0 && PTW > 50.0) PTWbin = 1;
    if(PTW > 100.0) PTWbin = 2;

    unsigned int YWbin = 0;
    if(fabs(YW) <= 0.5) YWbin=0;
    if(fabs(YW) <= 1.0 && fabs(YW) > 0.5) YWbin=1;
    if(fabs(YW) <= 1.5 && fabs(YW) > 1.0) YWbin=2;
    if(fabs(YW) <= 2.0 && fabs(YW) > 1.5) YWbin=3;
    if(fabs(YW) <= 2.5 && fabs(YW) > 2.0) YWbin=4;
    if(fabs(YW) <= 3.0 && fabs(YW) > 2.5) YWbin=5;
    if(fabs(YW) > 3.0) YWbin=6;

    if(boson_type == "Z") {
      //it can only be pos charge per our initial definition of what lepton to look at...
      if(poscharge) {
	alpha = GetCSCosThetaZFitParameters().at(PTWbin).at(YWbin).alpha_plus;
	beta = GetCSCosThetaZFitParameters().at(PTWbin).at(YWbin).beta_plus; 
	gamma = GetCSCosThetaZFitParameters().at(PTWbin).at(YWbin).gamma_plus;
      }
    }

    double curr_type_ratio = CSCosThetaBinFraction(alpha, beta, gamma, bin); //test for 0
    //std::cout << "curr_type_ratio = " << curr_type_ratio << std::endl;

    double corr_factor = norm_type_ratio/curr_type_ratio;

    return corr_factor;
  }

  MCCSFramePlots::MCCSFramePlots(const std::string & folderName,const std::string & VBoson) :
    mFolderName(folderName),
    mVBoson(VBoson) {}

  MCCSFramePlots::~MCCSFramePlots() {}

  void MCCSFramePlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
  }

  void MCCSFramePlots::BookHistos() {
    TH1::SetDefaultSumw2(kTRUE);
    MC_CSWMuonPlusPhi = new TH1D("MC_CSWMuonPlusPhi",";gen lepton+ #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonPlusPhi_A = new TH1D("MC_CSWMuonPlusPhi_A",";gen lepton+ #phi in CS-Frame reweightedA;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonPlusPhi_B = new TH1D("MC_CSWMuonPlusPhi_B",";gen lepton+ #phi in CS-Frame reweightedB;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonPlusPhi_C = new TH1D("MC_CSWMuonPlusPhi_C",";gen lepton+ #phi in CS-Frame reweightedC;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccPlusPhi = new TH1D("MC_CSWMuonAccPlusPhi",";gen_acceptance lepton+ #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccPlusPhi_A = new TH1D("MC_CSWMuonAccPlusPhi_A",";gen_acceptance lepton+ #phi in CS-Frame reweightedA;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccPlusPhi_B = new TH1D("MC_CSWMuonAccPlusPhi_B",";gen_acceptance lepton+ #phi in CS-Frame reweightedB;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccPlusPhi_C = new TH1D("MC_CSWMuonAccPlusPhi_C",";gen_acceptance lepton+ #phi in CS-Frame reweightedC;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonPlusPhi2 = new TH1D("MC_CSWMuonPlusPhi2",";gen lepton+ #phi in CS-Frame;Events / 10 pb^{-1}",700,-0.05,6.95);
    MC_CSWMuonMinusPhi = new TH1D("MC_CSWMuonMinusPhi",";gen lepton- #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonMinusPhi_A = new TH1D("MC_CSWMuonMinusPhi_A",";gen lepton- #phi in CS-Frame reweightedA;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonMinusPhi_B = new TH1D("MC_CSWMuonMinusPhi_B",";gen lepton- #phi in CS-Frame reweightedB;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonMinusPhi_C = new TH1D("MC_CSWMuonMinusPhi_C",";gen lepton- #phi in CS-Frame reweightedC;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccMinusPhi = new TH1D("MC_CSWMuonAccMinusPhi",";gen_acceptance lepton- #phi in CS-Frame;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccMinusPhi_A = new TH1D("MC_CSWMuonAccMinusPhi_A",";gen_acceptance lepton- #phi in CS-Frame reweightedA;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccMinusPhi_B = new TH1D("MC_CSWMuonAccMinusPhi_B",";gen_acceptance lepton- #phi in CS-Frame reweightedB;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonAccMinusPhi_C = new TH1D("MC_CSWMuonAccMinusPhi_C",";gen_acceptance lepton- #phi in CS-Frame reweightedC;Events / 10 pb^{-1}",700,-3.55,3.45);
    MC_CSWMuonMinusPhi2 = new TH1D("MC_CSWMuonMinusPhi2",";gen lepton- #phi in CS-Frame;Events / 10 pb^{-1}",700,-0.05,6.95);
    MC_CSWMuonPlusCosTheta = new TH1D("MC_CSWMuonPlusCosTheta",";gen lepton+ cos#theta in CS-Frame;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonPlusCosTheta_A = new TH1D("MC_CSWMuonPlusCosTheta_A",";gen lepton+ cos#theta in CS-Frame reweightedA;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonPlusCosTheta_B = new TH1D("MC_CSWMuonPlusCosTheta_B",";gen lepton+ cos#theta in CS-Frame reweightedB;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonPlusCosTheta_C = new TH1D("MC_CSWMuonPlusCosTheta_C",";gen lepton+ cos#theta in CS-Frame reweightedC;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonAccPlusCosTheta = new TH1D("MC_CSWMuonAccPlusCosTheta",";gen_acceptance lepton+ cos#theta in CS-Frame;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonAccPlusCosTheta_A = new TH1D("MC_CSWMuonAccPlusCosTheta_A",";gen_acceptance lepton+ cos#theta in CS-Frame reweightedA;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonAccPlusCosTheta_B = new TH1D("MC_CSWMuonAccPlusCosTheta_B",";gen_acceptance lepton+ cos#theta in CS-Frame reweightedB;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonAccPlusCosTheta_C = new TH1D("MC_CSWMuonAccPlusCosTheta_C",";gen_acceptance lepton+ cos#theta in CS-Frame reweightedC;Events / 10 pb^{-1}",300,-1.5,1.5);
    MC_CSWMuonMinusCosTheta = new TH1D("MC_CSWMuonMinusCosTheta",";gen lepton- cos#theta in CS-Frame;Events / 10 pb^{-1}",200,-1.05,0.95);

    MC_CSWA0Numerator = new TH1D("MC_CSWA0Numerator",";gen W P_{T} [GeV];A_{0} Numerator",1000,-0.5,999.5);
    MC_CSWA1Numerator = new TH1D("MC_CSWA1Numerator",";gen W P_{T} [GeV];A_{1} Numerator",1000,-0.5,999.5);
    MC_CSWA2Numerator = new TH1D("MC_CSWA2Numerator",";gen W P_{T} [GeV];A_{2} Numerator",1000,-0.5,999.5);
    MC_CSWA3Numerator = new TH1D("MC_CSWA3Numerator",";gen W P_{T} [GeV];A_{3} Numerator",1000,-0.5,999.5);
    MC_CSWA4Numerator = new TH1D("MC_CSWA4Numerator",";gen W P_{T} [GeV];A_{4} Numerator",1000,-0.5,999.5);

    MC_CSWPlusA0Numerator = new TH1D("MC_CSWPlusA0Numerator",";gen W^{+} P_{T} [GeV];A_{0} Numerator",1000,-0.5,999.5);
    MC_CSWPlusA1Numerator = new TH1D("MC_CSWPlusA1Numerator",";gen W^{+} P_{T} [GeV];A_{1} Numerator",1000,-0.5,999.5);
    MC_CSWPlusA2Numerator = new TH1D("MC_CSWPlusA2Numerator",";gen W^{+} P_{T} [GeV];A_{2} Numerator",1000,-0.5,999.5);
    MC_CSWPlusA3Numerator = new TH1D("MC_CSWPlusA3Numerator",";gen W^{+} P_{T} [GeV];A_{3} Numerator",1000,-0.5,999.5);
    MC_CSWPlusA4Numerator = new TH1D("MC_CSWPlusA4Numerator",";gen W^{+} P_{T} [GeV];A_{4} Numerator",1000,-0.5,999.5);

    MC_CSWMinusA0Numerator = new TH1D("MC_CSWMinusA0Numerator",";gen W^{-} P_{T} [GeV];A_{0} Numerator",1000,-0.5,999.5);
    MC_CSWMinusA1Numerator = new TH1D("MC_CSWMinusA1Numerator",";gen W^{-} P_{T} [GeV];A_{1} Numerator",1000,-0.5,999.5);
    MC_CSWMinusA2Numerator = new TH1D("MC_CSWMinusA2Numerator",";gen W^{-} P_{T} [GeV];A_{2} Numerator",1000,-0.5,999.5);
    MC_CSWMinusA3Numerator = new TH1D("MC_CSWMinusA3Numerator",";gen W^{-} P_{T} [GeV];A_{3} Numerator",1000,-0.5,999.5);
    MC_CSWMinusA4Numerator = new TH1D("MC_CSWMinusA4Numerator",";gen W^{-} P_{T} [GeV];A_{4} Numerator",1000,-0.5,999.5);

    MC_CSWPlusAiDenominator = new TH1D("MC_CSWPlusAiDenominator",";gen W^{+} P_{T} [GeV];A_{i} Denominator",1000,-0.5,999.5);
    MC_CSWMinusAiDenominator = new TH1D("MC_CSWMinusAiDenominator",";gen W^{-} P_{T} [GeV];A_{i} Denominator",1000,-0.5,999.5);
    MC_CSWAiDenominator = new TH1D("MC_CSWAiDenominator",";gen W P_{T} [GeV];A_{i} Denominator",1000,-0.5,999.5);

    MC_CSWPzSol1PhiDiff = new TH1D("MC_CSWPzSol1PhiDiff",";#phi_{true} - #phi_{Sol1};Events / 10 pb^{-1}",100,-5.5,4.5);
    MC_CSWPzSol2PhiDiff = new TH1D("MC_CSWPzSol2PhiDiff",";#phi_{true} - #phi_{Sol2};Events / 10 pb^{-1}",100,-5.5,4.5);
    MC_CSWPzDiff = new TH1D("MC_CSWPzDiff", ";#nu P_{z}^{true} - P_{z}^{formula}",100,-5.5,4.5);
    TH1::SetDefaultSumw2(kFALSE);
    MC_CSWM_WMT = new TH2D("MC_CSWM_WMT",";W mass; W transverse mass",100,49.5,99.5,100,49.5,99.5);
  }

  bool MCCSFramePlots::Process(Event::Data & ev) {
    //check that genW exists and decays to a muon/lepton
    GenMatrixBin myGenMatrixBin(&ev);

    if(TString(mVBoson) == "W") {forW = true;forZ = false;}
    if(TString(mVBoson) == "Z") {forW = false;forZ = true;}
    if(TString(mVBoson) != "Z" && TString(mVBoson) != "W") cout << "MCCSFramePlots: Error invalid Vector Boson choice!"<<endl;

    vector <Event::GenObject const *> theVBosons;
    Event::GenObject const * genLepton;
    Event::GenObject const * genLepton2;//for the other lepton from the Z-decay (so we can apply acceptance to it too!)
    Event::GenObject const * genLeptonNu;
    //the next statement is used so that we can change definitions in the future without affecting the code
    if(forW) {
      if(myGenMatrixBin.the_GenW.size()==0) return false;
      theVBosons = myGenMatrixBin.the_GenW;

      if(myGenMatrixBin.the_GenEli.size()) {
	genLepton = myGenMatrixBin.the_GenEli.at(0);
	genLeptonNu = myGenMatrixBin.the_GenEliNu.at(0);
      } else if(myGenMatrixBin.the_GenMuon.size()) {
	genLepton = myGenMatrixBin.the_GenMuon.at(0);
	genLeptonNu = myGenMatrixBin.the_GenMuonNu.at(0);
      } else if(myGenMatrixBin.the_GenTau.size()) {
	genLepton = myGenMatrixBin.the_GenTau.at(0);
	genLeptonNu = myGenMatrixBin.the_GenTauNu.at(0);
      } else {
	cout << "MCCSFramePlots: The W boson does not decay to a lepton" << endl;
	return false;
      }
    }
    if(forZ) {
      if(myGenMatrixBin.the_GenZ.size()==0) return false;
      theVBosons = myGenMatrixBin.the_GenZ;
      //in the Z case, genLepton should represent a single charge as it makes no difference which charge we choose...
      //a Z will decay to two leptons
      //here we make a decision to either store the positive charge lepton from the Z-decay (ID <0 is the antilepton and hence the positively charged one)
      //or the negative charge lepton from the Z-decay (ID >0 is the lepton and hence the negatively charged one)
      //remember, there should be no neutrino in this case
      //we store both muons so that we can apply acceptance to both
      //here we must also check that the Z decays to two leptons (not neutrinos, u-type quarks or d-type quarks etc)

      if(myGenMatrixBin.the_GenEli.size() == 2) {
	//std::cout << "found electron pair" << std::endl;
	if(myGenMatrixBin.the_GenEli.at(0)->GetID() < 0) {
	  genLepton = myGenMatrixBin.the_GenEli.at(0);
	  genLepton2 = myGenMatrixBin.the_GenEli.at(1);
	} else {
	  genLepton = myGenMatrixBin.the_GenEli.at(1);
	  genLepton2 = myGenMatrixBin.the_GenEli.at(0);
	}
      } else if(myGenMatrixBin.the_GenMuon.size() == 2) {
	//std::cout << "found muon pair" << std::endl;
	if(myGenMatrixBin.the_GenMuon.at(0)->GetID() < 0) {
	  genLepton = myGenMatrixBin.the_GenMuon.at(0);
	  genLepton2 = myGenMatrixBin.the_GenMuon.at(1);
	} else {
	  genLepton = myGenMatrixBin.the_GenMuon.at(1);
	  genLepton2 = myGenMatrixBin.the_GenMuon.at(0);
	}
      } else if(myGenMatrixBin.the_GenTau.size() == 2) {
	//std::cout << "found tau pair" << std::endl;
	if(myGenMatrixBin.the_GenTau.at(0)->GetID() < 0) {
	  genLepton = myGenMatrixBin.the_GenTau.at(0);
	  genLepton2 = myGenMatrixBin.the_GenTau.at(1);
	} else {
	  genLepton = myGenMatrixBin.the_GenTau.at(1);
	  genLepton2 = myGenMatrixBin.the_GenTau.at(0);
	}
      } else {
	return false;
	//cout << "MCCSFramePlots: Have we found a one legged Z?"<<endl;	
      }
    }


    TLorentzVector lepton;
    lepton = CSTransform( TLVConvert(genLepton), TLVConvert(theVBosons.at(0)));


    if(forW) {
      //of course the neutrino only makes sense in the W-boson decay...
      TLorentzVector neutrino;
      neutrino = CSTransform( TLVConvert(genLeptonNu), TLVConvert(theVBosons.at(0)));

      //to plot the transverse mass of the W (with the lepton,neutrino pair) vs the true W mass:
      double w_mtrans = sqrt(2.0*neutrino.Pt()*lepton.Pt()*(1.0 - cos(lepton.DeltaPhi(neutrino))));
      MC_CSWM_WMT->Fill(theVBosons.at(0)->M(), w_mtrans, ev.GetEventWeight());

      //work out the neutrino pz using the four-vector algebra. Do this first with the proper gen level W-boson mass
      //this is so we can check the effects of taking the positive and negative root have on phi - it should be independent...
      double constantA = (theVBosons.at(0)->M2()) + (theVBosons.at(0)->Perp2()) - (genLepton->Perp2()) - (genLeptonNu->Perp2()) - (genLepton->M2()) - (genLeptonNu->M2());
      double constantB = (constantA * constantA) - (4.0 * (genLepton->Perp2() + genLepton->M2()) * (genLeptonNu->Perp2() + genLeptonNu->M2()));
      double constantC = (2.0 * (genLepton->Perp2() + genLepton->M2())); //paper says 4.0, i think 2.0 - let's see... it's 2.0! hehe
      double constantD = ((constantA * genLepton->Pz()) / constantC);
      double constantE = ((genLepton->E() * sqrt(constantB)) / constantC);
      //these solutions are the pz of the neutrino:
      double pzsol1 = (constantD + constantE);
      double pzsol2 = (constantD - constantE);

      double diff;
      if(fabs(pzsol1 - genLeptonNu->Pz()) < fabs(pzsol2 - genLeptonNu->Pz())) {
	MC_CSWPzDiff->Fill(pzsol1 - genLeptonNu->Pz(), ev.GetEventWeight());
	diff = pzsol1 - genLeptonNu->Pz();
      }else{
	MC_CSWPzDiff->Fill(pzsol2 - genLeptonNu->Pz(), ev.GetEventWeight());
	diff = pzsol2 - genLeptonNu->Pz();
      }
      /*
      //some diagnostics in case things go wrong
      std::cout << "Diagnostics: " << std::endl;
      std::cout << "diff: " << diff << std::endl;
      std::cout << "discriminant = " << constantB << std::endl;
      std::cout << "constantA = " << constantA << std::endl;

      std::cout << "E_lepton = " << genLepton->E() << std::endl;
      std::cout << "pz_lepton = " << genLepton->Pz() << std::endl;
      std::cout << "pt_lepton = " << genLepton->Pt() << std::endl;
      std::cout << "mass_lepton = " << genLepton->M() << std::endl;

      std::cout << "E_neutrino = " << genLeptonNu->E() << std::endl;
      std::cout << "pz_neutrino = " << genLeptonNu->Pz() << std::endl;
      std::cout << "pt_neutrino = " << genLeptonNu->Pt() << std::endl;
      std::cout << "mass_neutrino = " << genLeptonNu->M() << std::endl;

      std::cout << "E_W = " << theVBosons.at(0)->E() << std::endl;
      std::cout << "pz_W = " << theVBosons.at(0)->Pz() << std::endl;
      std::cout << "pt_W = " << theVBosons.at(0)->Pt() << std::endl;
      std::cout << "mass_W = " << theVBosons.at(0)->M() << std::endl;

      std::cout << "Actual pz_neutrino: " << genLeptonNu->Pz() << std::endl;
      std::cout << "sanity check 1: lepton + lepton neutrino - W (Px,Py,Pz): ("
      << genLepton->Px() + genLeptonNu->Px() - theVBosons.at(0)->Px() << ", "
      << genLepton->Py() + genLeptonNu->Py() - theVBosons.at(0)->Py() << ", "
      << genLepton->Pz() + genLeptonNu->Pz() - theVBosons.at(0)->Pz() << ") " << std::endl;
      TLorentzVector tlv_lepton = TLVConvert(genLepton);
      TLorentzVector tlv_neutrino = TLVConvert(genLeptonNu);
      std::cout << "sanity check 2: (lepton + lepton neutrino)^2 : " << (tlv_lepton+tlv_neutrino).M() << std::endl;
      std::cout << "sanity check 3: 2* (lepton -dot- lepton neutrino) : " << 2*tlv_lepton.Dot(tlv_neutrino) << std::endl;
      std::cout << std::endl;
      */
      //need to correct for the pz of the lepton so that we get the pz of the W:
      pzsol1 += genLepton->Pz();
      pzsol2 += genLepton->Pz();

      //double pzsol1 = genLepton->Pz() + genLeptonNu->Pz(); //as a test of the method
      TLorentzVector wvector_pzsol1;
      TLorentzVector wvector_pzsol2;
      wvector_pzsol1.SetXYZM(theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), pzsol1, theVBosons.at(0)->M());
      wvector_pzsol2.SetXYZM(theVBosons.at(0)->Px(), theVBosons.at(0)->Py(), pzsol2, theVBosons.at(0)->M());
      TLorentzVector lepton_pzsol1 = CSTransform( TLVConvert(genLepton), wvector_pzsol1);
      TLorentzVector lepton_pzsol2 = CSTransform( TLVConvert(genLepton), wvector_pzsol2);
      MC_CSWPzSol1PhiDiff->Fill(lepton_pzsol1.Phi() - lepton.Phi(), ev.GetEventWeight());
      MC_CSWPzSol2PhiDiff->Fill(lepton_pzsol2.Phi() - lepton.Phi(), ev.GetEventWeight());
    }

    double adjusted_phi=0.0;
    //add 2Pi to the negative values of Phi to take it from [-pi,+pi] to [0,2pi]
    if(lepton.Phi()<0.0) adjusted_phi = ((2.0*TMath::Pi()) + lepton.Phi());
    else adjusted_phi = lepton.Phi();

    //in the MC numbering scheme, the positive id W is actually a W plus, but the positive id leptons will have negative charge
    //    if(theVBosons.at(0)->GetID() > 0) {
    if(genLepton->GetID() < 0) {

      MC_CSWMuonPlusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      MC_CSWMuonPlusPhi2->Fill(adjusted_phi, ev.GetEventWeight());
      MC_CSWMuonPlusCosTheta->Fill(lepton.CosTheta(), ev.GetEventWeight());
      //to see effects of acceptance, select leptons with pt>20 and fabs(eta) < 2.1
      if(forW) {
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) MC_CSWMuonAccPlusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      }
      if(forZ) {
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1 && genLepton2->Pt() > 20.0 && fabs(genLepton2->Eta()) < 2.1) {
	  MC_CSWMuonAccPlusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
	  MC_CSWMuonAccPlusCosTheta->Fill(lepton.CosTheta(), ev.GetEventWeight());
	}
      }
      int index = int( (lepton.Phi() + 3.15) / 0.01 );
      int index2 = int( (lepton.CosTheta() + 1.00) / 0.01 );

      if(forW) {
	MC_CSWMuonPlusPhi_A->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0, TString("W")));
	MC_CSWMuonPlusPhi_B->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1, TString("W")));
	MC_CSWMuonPlusPhi_C->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2, TString("W")));
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) {
	  MC_CSWMuonAccPlusPhi_A->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0, TString("W")));
	  MC_CSWMuonAccPlusPhi_B->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1, TString("W")));
	  MC_CSWMuonAccPlusPhi_C->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2, TString("W")));
	}
      }
      if(forZ) {//remember, only positive charge taken into account (by our choice)
	MC_CSWMuonPlusPhi_A->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0, TString("Z")));
	MC_CSWMuonPlusPhi_B->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1, TString("Z")));
	MC_CSWMuonPlusPhi_C->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2, TString("Z")));
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1 && genLepton2->Pt() > 20.0 && fabs(genLepton2->Eta()) < 2.1) {
	  MC_CSWMuonAccPlusPhi_A->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,0, TString("Z")));
	  MC_CSWMuonAccPlusPhi_B->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,1, TString("Z")));
	  MC_CSWMuonAccPlusPhi_C->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,true,2, TString("Z")));
	}
	MC_CSWMuonPlusCosTheta_A->Fill(lepton.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,0, TString("Z")));
	MC_CSWMuonPlusCosTheta_B->Fill(lepton.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,1, TString("Z")));
	MC_CSWMuonPlusCosTheta_C->Fill(lepton.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,2, TString("Z")));
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1 && genLepton2->Pt() > 20.0 && fabs(genLepton2->Eta()) < 2.1) {
	  MC_CSWMuonAccPlusCosTheta_A->Fill(lepton.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,0, TString("Z")));
	  MC_CSWMuonAccPlusCosTheta_B->Fill(lepton.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,1, TString("Z")));
	  MC_CSWMuonAccPlusCosTheta_C->Fill(lepton.CosTheta(), ev.GetEventWeight() * CSCosThetaCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index2,true,2, TString("Z")));	  
	}
      }
    } else {

      MC_CSWMuonMinusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      MC_CSWMuonMinusPhi2->Fill(adjusted_phi, ev.GetEventWeight());
      MC_CSWMuonMinusCosTheta->Fill(lepton.CosTheta(), ev.GetEventWeight());
      if(forW) {
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) MC_CSWMuonAccMinusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      }
      if(forZ) {
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1 && genLepton2->Pt() > 20.0 && fabs(genLepton2->Eta()) < 2.1) MC_CSWMuonAccMinusPhi->Fill(lepton.Phi(), ev.GetEventWeight());
      }

      if(forW) {
	int index = int( (lepton.Phi() + 3.15) / 0.01 );
	MC_CSWMuonMinusPhi_A->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0, TString("W")));
	MC_CSWMuonMinusPhi_B->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1, TString("W")));
	MC_CSWMuonMinusPhi_C->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2, TString("W")));
	if(genLepton->Pt() > 20.0 && fabs(genLepton->Eta()) < 2.1) {
	  MC_CSWMuonAccMinusPhi_A->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,0, TString("W")));
	  MC_CSWMuonAccMinusPhi_B->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,1, TString("W")));
	  MC_CSWMuonAccMinusPhi_C->Fill(lepton.Phi(), ev.GetEventWeight() * CSPhiCorrFactor(theVBosons.at(0)->Pt(), theVBosons.at(0)->Rapidity(),index,false,2, TString("W")));
	}
      }
    }

    //in these plots, we actually want the value of numerator/denominator, where in num and denom, there is a sum over all events
    //since we want them binned in Wpt, we fill the pt of the W with weight according to the contents of the sum
    //then afterward, you divide the two histograms...

    if(genLepton->GetID() > 0) { //i.e. negative charge
      MC_CSWMinusA4Numerator->Fill(theVBosons.at(0)->Pt(), lepton.CosTheta() *ev.GetEventWeight());
      MC_CSWMinusA3Numerator->Fill(theVBosons.at(0)->Pt(), cos(lepton.Phi()) * sin(lepton.Theta()) * ev.GetEventWeight());
      MC_CSWMinusA2Numerator->Fill(theVBosons.at(0)->Pt(), sin(lepton.Theta()) * sin(lepton.Theta()) * cos(2.0*lepton.Phi()) * ev.GetEventWeight());
      MC_CSWMinusA1Numerator->Fill(theVBosons.at(0)->Pt(), cos(lepton.Phi()) * sin(2.0*lepton.Theta()) * ev.GetEventWeight());
      MC_CSWMinusA0Numerator->Fill(theVBosons.at(0)->Pt(), 0.5*(1.0-3.0*lepton.CosTheta()*lepton.CosTheta()) * ev.GetEventWeight());
      MC_CSWMinusAiDenominator->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
    } else {
      MC_CSWPlusA4Numerator->Fill(theVBosons.at(0)->Pt(), lepton.CosTheta() * ev.GetEventWeight());
      MC_CSWPlusA3Numerator->Fill(theVBosons.at(0)->Pt(), cos(lepton.Phi()) * sin(lepton.Theta()) * ev.GetEventWeight());
      MC_CSWPlusA2Numerator->Fill(theVBosons.at(0)->Pt(), sin(lepton.Theta()) * sin(lepton.Theta()) * cos(2.0*lepton.Phi()) * ev.GetEventWeight());
      MC_CSWPlusA1Numerator->Fill(theVBosons.at(0)->Pt(), cos(lepton.Phi()) * sin(2.0*lepton.Theta()) * ev.GetEventWeight());
      MC_CSWPlusA0Numerator->Fill(theVBosons.at(0)->Pt(), 0.5*(1.0-3.0*lepton.CosTheta()*lepton.CosTheta()) * ev.GetEventWeight());
      MC_CSWPlusAiDenominator->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());
    }

    MC_CSWA4Numerator->Fill(theVBosons.at(0)->Pt(), lepton.CosTheta() * ev.GetEventWeight());
    MC_CSWA3Numerator->Fill(theVBosons.at(0)->Pt(), cos(lepton.Phi()) * sin(lepton.Theta()) * ev.GetEventWeight());
    MC_CSWA2Numerator->Fill(theVBosons.at(0)->Pt(), sin(lepton.Theta()) * sin(lepton.Theta()) * cos(2.0*lepton.Phi()) * ev.GetEventWeight());
    MC_CSWA1Numerator->Fill(theVBosons.at(0)->Pt(), cos(lepton.Phi()) * sin(2.0*lepton.Theta()) * ev.GetEventWeight());
    MC_CSWA0Numerator->Fill(theVBosons.at(0)->Pt(), 0.5*(1.0-3.0*lepton.CosTheta()*lepton.CosTheta()) * ev.GetEventWeight());
    MC_CSWAiDenominator->Fill(theVBosons.at(0)->Pt(), ev.GetEventWeight());


    return true;
  }

  std::ostream& MCCSFramePlots::Description(std::ostream &ostrm) {
    ostrm << "MC Collins-Soper Frame Plots";
    return ostrm;
  }

 
} // ~namespace Operation
