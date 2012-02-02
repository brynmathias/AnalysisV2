#include "Functions.hh"
//originally written Jad Marrouche, Sep 2009 onwards
namespace Operation {

  TLorentzVector TLVConvert(const LorentzV * particle) {
    TLorentzVector TLVparticle(particle->Px(), particle->Py(), particle->Pz(), particle->E());
    return TLVparticle;
  }

  //====================================
  // Boost Calculation Function
  //====================================

  jSolutionsW FindBoost(const TLorentzVector jMuon, const double jVWPx, const double jVWPy,
                        const double jVWPz, const bool cheat, const bool approximate,
                        const double jVWM) {
  //jSolutionsW FindBoost(const LorentzV & jMuonV, const double & jVWPx, const double & jVWPy, const double & jVWPz, const bool & cheat=true, const bool & approximate=true, const double & jVWM=80.4) {
    //by having the function in this form, you can slot various combinations for the (px,py,pz) components
    //the cheat variable allows you to choose if you want sol1/sol2 or rightsol/wrongsol - for this you need to pass jVWPz of the real W
    //the approximate variable allows you to choose if you want the approximation using mw=80.4, or the true generator boost back to the W rest frame - must supply jVWM
    //the cheat variable is redundant if the approximate variable is set to false

    //you can follow this calculation if you start from the four-vector argument P_W = P_Mu + P_MuNu and rearrange so P_MuNu is on its own.
    //then square both sides, taking mass_neutrino = 0. Also the dot product of two threevectors is p1xp2x+p1yp2y+p1zp2z and not p1 p2 cos(theta_12)
    //since theta_12 relies on knowing the pz components...


    //To change from TLorentzVector to ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > the following mod must be made to preserve the code below
    //TLorentzVector jMuon(jMuonV.x(),jMuonV.y(),jMuonV.z(),jMuonV.t());

    jSolutionsW results;
    TLorentzVector jRestMu, jTemp4V;
    TVector3 jTempBV;
    double CosThetaStarSol1, CosThetaStarSol2;

    if(approximate) {
      double jVWPt2 = ((jVWPx * jVWPx) + (jVWPy * jVWPy)); //this is the Pt squared
      double delta = ((80.4*80.4)+(0.106*0.106))/2.0 + (jVWPx * jMuon.Px()) + (jVWPy * jMuon.Py());
      double alpha = (jMuon.E() * jMuon.E()) - (jMuon.Pz() * jMuon.Pz());
      double beta = -2.0 * delta * jMuon.Pz();
      double gamma = (jMuon.E() * jMuon.E()) * (jVWPt2 + (80.4*80.4)) - (delta * delta);
      double discarg = (beta*beta) - (4*alpha*gamma);

      if(discarg > 0) {
	double discriminant = sqrt(discarg);
	double sol1 = (-1.0*beta + discriminant) / (2*alpha);
	double sol2 = (-1.0*beta - discriminant) / (2*alpha);

	results.realSolutions = true; //since the discriminant is >0, we get real solutions

	jRestMu = jMuon;
	jTemp4V.SetXYZM(jVWPx,jVWPy,sol1,80.4);
	jTempBV = jTemp4V.BoostVector();
	jRestMu.Boost(-jTempBV);
	CosThetaStarSol1 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jTemp4V));

	jRestMu = jMuon;
	jTemp4V.SetXYZM(jVWPx,jVWPy,sol2,80.4);
	jTempBV = jTemp4V.BoostVector();
	jRestMu.Boost(-jTempBV);
	CosThetaStarSol2 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jTemp4V));

	if(cheat) {
	  if(fabs(sol1 - jVWPz) < fabs(sol2 - jVWPz)) {
	    results.rightSol = CosThetaStarSol1;
	    results.wrongSol = CosThetaStarSol2;
	  } else {
	    results.rightSol = CosThetaStarSol2;
	    results.wrongSol = CosThetaStarSol1;
	  }
	  results.sol1 = 0.0;
	  results.sol2 = 0.0;
	  return results;
	} else {
	  results.rightSol = 0.0;
	  results.wrongSol = 0.0;
	  results.sol1 = CosThetaStarSol1;
	  results.sol2 = CosThetaStarSol2;
	  return results;
	}
      } else {
	results.realSolutions = false;
	results.rightSol = 0.0;
	results.wrongSol = 0.0;
	results.sol1 = 0.0;
	results.sol2 = 0.0;
	return results;
      }
    } else {
      jRestMu = jMuon;
      jTemp4V.SetXYZM(jVWPx,jVWPy,jVWPz,jVWM);
      jTempBV = jTemp4V.BoostVector();
      jRestMu.Boost(-jTempBV);
      CosThetaStarSol1 = cos(ROOT::Math::VectorUtil::Angle(jRestMu,jTemp4V));

      results.realSolutions = true;
      results.rightSol = CosThetaStarSol1;
      results.wrongSol = 0.0;
      results.sol1 = 0.0;
      results.sol2 = 0.0;
      return results;
    }

  }

  //====================================
  // Reweighting implementation
  //====================================

  //to get the 100% left handed case etc, reweight acording to the factors in the methods below (see the standalone macro for how this is filled)

  std::vector< std::vector<jFitParameters> > & GetFitParameters() {
    static std::vector< std::vector<jFitParameters> > binned_fit_params = init_fit_params();
    return binned_fit_params;
  }

  std::vector< std::vector<jFitParameters> > & GetWeightFitParameters(const unsigned int & phase_space) {
    //convention: 1 = 50-inf, 2 = 100-inf, 3 = 50-75, 4 = 75-100
    if(phase_space == 1) {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight50toinf = init_fit_params_weight50toinf();
      return binned_fit_params_weight50toinf;
    } else if(phase_space == 2) {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight100toinf = init_fit_params_weight100toinf();
      return binned_fit_params_weight100toinf;
    } else if(phase_space == 3) {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight50to75 = init_fit_params_weight50to75();
      return binned_fit_params_weight50to75;
    } else if(phase_space == 4) {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight75to100 = init_fit_params_weight75to100();
      return binned_fit_params_weight75to100;
    } else {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight50toinf = init_fit_params_weight50toinf();
      std::cout << "Defaulting to 50toinf reweighting factors. The phase_space you chose was: " << phase_space << std::endl;
    }
  }

  std::vector< std::vector<jFitParameters> > & GetWeightFitParametersZ(const unsigned int & phase_space) {
    //convention: 1 = 50-inf, 2 = 100-inf, 3 = 50-75, 4 = 75-100
    if(phase_space == 1) {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight50toinf = init_fit_params_weight50toinfZ();
      return binned_fit_params_weight50toinf;
    } else {
      static std::vector< std::vector<jFitParameters> > binned_fit_params_weight50toinf = init_fit_params_weight50toinfZ();
      std::cout << "Defaulting to 50toinf reweighting factors. The phase_space you chose was: " << phase_space << std::endl;
    }
  }

  std::vector< std::vector<jAiFitParameters> > & GetAiFitParameters(const unsigned int & phase_space) {
    if(phase_space == 0) {
      static std::vector< std::vector<jAiFitParameters> > binned_ai_fit_params = init_ai_fit_params();
      return binned_ai_fit_params;
    } else if (phase_space == 1) {
      static std::vector< std::vector<jAiFitParameters> > binned_ai_fit_params_mcreco50 = mcreco50_ai_fit_params();
      return binned_ai_fit_params_mcreco50;
    } else {
      std::cout << "Unknown phase space parameters selected - defaulting to full gen level (PT,Y) space..." << std::endl;
      static std::vector< std::vector<jAiFitParameters> > binned_ai_fit_params = init_ai_fit_params();
      return binned_ai_fit_params;
    }
  }

  std::vector< std::vector<jAiFitParameters> > & GetAiFitParametersZ(const unsigned int & phase_space) {
    if (phase_space == 1) {
      static std::vector< std::vector<jAiFitParameters> > binned_ai_fit_params_mcreco50Z = mcreco50_ai_fit_paramsZ();
      return binned_ai_fit_params_mcreco50Z;
    } else {
      std::cout << "Unknown phase space parameters selected - defaulting to 50-inf reco level (PT,Y) space..." << std::endl;
      static std::vector< std::vector<jAiFitParameters> > binned_ai_fit_params_mcreco50Z = mcreco50_ai_fit_paramsZ();
      return binned_ai_fit_params_mcreco50Z;
    }
  }

  std::vector< std::vector<jFitParameters> > & GetZFitParameters() {
    static std::vector< std::vector<jFitParameters> > binned_fit_paramsZ = init_fit_paramsZ();
    return binned_fit_paramsZ;
  }

  double BinFraction(const double & alpha, const double & beta, const double & gamma, const unsigned int & bin) {
    //the format i'm using for the fit function is as follows:
    //alpha * (1-x)^2 +
    //beta * (1+x)^2 +
    //gamma * (1-x^2)

    //for all our plots, we have a defined bin width for the gen level cos(theta*) plots
    double bin_width = 0.01;
    //bin 0 by our definition is the bin between -1.00 and -0.99 etc
    //subtract 1.0 below to go back to region cos(theta*) = (-1.0, 1.0)
    double bin_lowedge = double(bin)*bin_width - 1.0;

    //now make some easy to use variable names for the calculation below
    double a = bin_lowedge;
    double b = bin_lowedge + bin_width;

    double bin_integral = IntegralValue(a,b, alpha, beta, gamma);
    //std::cout << "bin_integral = "<< bin_integral << std::endl;
    double total_integral = IntegralValue(-1.0,1.0, alpha, beta, gamma); //test for 0
    //std::cout << "total_integral = "<< total_integral << std::endl;
    double fraction = bin_integral / total_integral;

    return fraction;

  }

  double IntegralValue(const double & a, const double & b, const double & alpha, const double & beta, const double & gamma) {
    //below is what you get if you integrate by hand the three components and evaluate them between b and a
    double alpha_part = 1.0/4.0 * ((b-a) - ((b*b)-(a*a)) + ((1.0/3.0)*((b*b*b) - (a*a*a))));
    double beta_part = 1.0/4.0 * ((b-a) + ((b*b)-(a*a)) + ((1.0/3.0)*((b*b*b) - (a*a*a))));
    double gamma_part = 1.0/2.0 * ((b-a) - (1.0/3.0)*((b*b*b) - (a*a*a)));
    double total_integral = ((alpha*alpha_part) + (beta*beta_part) + (gamma*gamma_part));
    return total_integral;
  }

  double CorrFactor(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type) {
    //a comment about what happens here - we would like to return the ratio of the bin content to the total integral between the actual
    //value in that (Pt,Y) bin, and the reweighted value (i.e. what you would get if it followed a pure distribution)

    if(norm_type > 2) std::cout << "Why is norm_type greater than 2? There are only 3 polarisation modes!" << std::endl;
    double alpha=0.0, beta=0.0, gamma=0.0;
    //initialise the (alpha,beta,gamma) parameters for the different scenarios - namely charge(-,+) with norm_type (LH=0, RH=1, LO=2)
    if(poscharge) {
      if(norm_type == 0) {alpha=1.0;beta=0.0;gamma=0.0;}
      if(norm_type == 1) {alpha=0.0;beta=1.0;gamma=0.0;}
      if(norm_type == 2) {alpha=0.0;beta=0.0;gamma=1.0;}
    }else{
      if(norm_type == 0) {alpha=0.0;beta=1.0;gamma=0.0;}
      if(norm_type == 1) {alpha=1.0;beta=0.0;gamma=0.0;}
      if(norm_type == 2) {alpha=0.0;beta=0.0;gamma=1.0;}
    }

    double norm_type_ratio = BinFraction(alpha, beta, gamma, bin);
    //std::cout << "norm_type_ratio = " << norm_type_ratio << std::endl;

    //now here is where the lookup for the appropriate alpha,beta,gamma factors happens according to W Pt and Y bins

    if(poscharge) {
      alpha = GetFitParameters().at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_plus;
      beta = GetFitParameters().at(GetPTbin(PTW)).at(GetYbin(YW)).beta_plus;
      gamma = GetFitParameters().at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_plus;
    }else{
      alpha = GetFitParameters().at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_minus;
      beta = GetFitParameters().at(GetPTbin(PTW)).at(GetYbin(YW)).beta_minus;
      gamma = GetFitParameters().at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_minus;
    }
    double curr_type_ratio = BinFraction(alpha, beta, gamma, bin); //test for 0
    //std::cout << "curr_type_ratio = " << curr_type_ratio << std::endl;

    double corr_factor = norm_type_ratio/curr_type_ratio;

    return corr_factor;
  }

  double CorrFactorWeight(const double & PTW, const double & YW, const bool & poscharge, const unsigned int & norm_type, const unsigned int & phase_space) {
    //this extra correction factor essentially is used to weight the correction factor above by the number of LH,RH,LO bosons in a particular bin
    //it's basically the result of Number of LH,RH,LO bosons in this (PT,Y) bin divided by the average over all (PT,Y) bins (which is what we really want to measure)
    //without this factor, the reweighting method gives equal weight to all bins i.e. fL(PtW, YW) is flat - we know this is not true!

    //the Number of e.g. LeftHanded bosons is given by total number of bosons in the bin * fL. The fit function we use to extract the 3 fit parameters
    //for the curves is [0]*(1/4(1-x)^2) + [1]*(1/4(1+x)^2) + [2]*(1/2(1-x^2)). If you do the maths, you find that the integral i.e. total N in that bin
    //is equal to 2/3([0]+[1]+[2]). you can find fL by [0]/([0]+[1]+[2]). So N*fL = 2/3[0].
    //The correction factor we want is fL in a bin divided by the average fL over all bins.
    //fL in a bin is NL/N = [0] / [0]+[1]+[2].
    //fL averaged over all bins is sum[0] / sum([0]+[1]+[2]) (not the same as sum ([0]/[0]+[1]+[2]) !!)

    //the convention of the phase_space is:
    //0 = ignore
    //1 = 50-inf
    //2 = 100-inf
    //3 = 50-75
    //4 = 75-100

    if(phase_space == 0) {
      //std::cout<<"INFO: phase_space == 0"<<std::endl;
      return 1.0;
    }
    double numbosons_bin=0.0, allbosons_bin=0.0, numbosons_total=0.0, allbosons_total=0.0;

    //to prevent looking up the values (which will be the same for a given phase_space/norm_type/charge)
    // static double lut_numbosons_total_pos[3];
    // static double lut_numbosons_total_neg[3];
    // static double lut_allbosons_total_pos;
    // static double lut_allbosons_total_neg;
    // static bool init_done=false;

    double corr_factor=0.0;

    if(poscharge) {
      if(norm_type == 0) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_plus;
      if(norm_type == 1) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_plus;
      if(norm_type == 2) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_plus;
      allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_plus;
      allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_plus;
      allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_plus;
    }else{
      if(norm_type == 1) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_minus; //remember that LH/RH definition flips with charge
      if(norm_type == 0) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_minus;
      if(norm_type == 2) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_minus;
      allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_minus;
      allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_minus;
      allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_minus;
    }

    for(unsigned int i=0; i<3; i++) {
      for(unsigned int j=0; j<7; j++) {
	if(poscharge) {
	  if(norm_type == 0) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).alpha_plus;
	  if(norm_type == 1) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).beta_plus;
	  if(norm_type == 2) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).gamma_plus;
	  allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).alpha_plus;
	  allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).beta_plus;
	  allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).gamma_plus;
	}else{
	  if(norm_type == 1) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).alpha_minus;
	  if(norm_type == 0) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).beta_minus;
	  if(norm_type == 2) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).gamma_minus;
	  allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).alpha_minus;
	  allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).beta_minus;
	  allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).gamma_minus;
	}
      }
    }

    //to be used with the static stuff defined above - doesn't currently work for different phase spaces...
//     if(!init_done) {
//       init_done=true; //to prevent entering this loop again - what about different phase_spaces...
//       std::cout << "Initialising the number of bosons for phase space: " << phase_space << std::endl;
//       for(unsigned int i=0; i<3; i++) {
// 	for(unsigned int j=0; j<7; j++) {

// 	  lut_numbosons_total_pos[0] += GetWeightFitParameters(phase_space).at(i).at(j).alpha_plus;
// 	  lut_numbosons_total_pos[1] += GetWeightFitParameters(phase_space).at(i).at(j).beta_plus;
// 	  lut_numbosons_total_pos[2] += GetWeightFitParameters(phase_space).at(i).at(j).gamma_plus;
// 	  lut_allbosons_total_pos += GetWeightFitParameters(phase_space).at(i).at(j).alpha_plus;
// 	  lut_allbosons_total_pos += GetWeightFitParameters(phase_space).at(i).at(j).beta_plus;
// 	  lut_allbosons_total_pos += GetWeightFitParameters(phase_space).at(i).at(j).gamma_plus;

// 	  lut_numbosons_total_neg[1] += GetWeightFitParameters(phase_space).at(i).at(j).alpha_minus;
// 	  lut_numbosons_total_neg[0] += GetWeightFitParameters(phase_space).at(i).at(j).beta_minus;
// 	  lut_numbosons_total_neg[2] += GetWeightFitParameters(phase_space).at(i).at(j).gamma_minus;
// 	  lut_allbosons_total_neg += GetWeightFitParameters(phase_space).at(i).at(j).alpha_minus;
// 	  lut_allbosons_total_neg += GetWeightFitParameters(phase_space).at(i).at(j).beta_minus;
// 	  lut_allbosons_total_neg += GetWeightFitParameters(phase_space).at(i).at(j).gamma_minus;
// 	}
//       }
//     } else {

//       if(poscharge) {
// 	if(norm_type == 0) numbosons_total = lut_numbosons_total_pos[0];
// 	if(norm_type == 1) numbosons_total = lut_numbosons_total_pos[1];
// 	if(norm_type == 2) numbosons_total = lut_numbosons_total_pos[2];
// 	allbosons_total=lut_allbosons_total_pos;
//       }else{
// 	if(norm_type == 1) numbosons_total = lut_numbosons_total_neg[1];
// 	if(norm_type == 0) numbosons_total = lut_numbosons_total_neg[0];
// 	if(norm_type == 2) numbosons_total = lut_numbosons_total_neg[2];
// 	allbosons_total = lut_allbosons_total_neg;
//       }
//     }

    if(allbosons_bin == 0.0 || allbosons_total == 0.0) corr_factor = 0.0; //to prevent divide by zero errors
    else corr_factor = (numbosons_bin / allbosons_bin) / (numbosons_total / allbosons_total); //i.e. fL in bin divided by <fL> all bins etc
    return corr_factor;
  }

  unsigned int GetPTbin(const double & PTW) {
    //W Pt, 0-50, 50-100, 100+
    unsigned int PTWbin = 0;
    if(PTW <= 50.0) PTWbin = 0;
    if(PTW <= 100.0 && PTW > 50.0) PTWbin = 1;
    if(PTW > 100.0) PTWbin = 2;

    return PTWbin;
  }

  unsigned int GetYbin(const double & YW) {
    //W |Y|, 0-0.5, 0.5-1.0, 1.0-1.5, 1.5-2.0, 2.0-2.5, 2.5-3.0, 3.0+
    unsigned int YWbin = 0;
    if(fabs(YW) <= 0.5) YWbin=0;
    if(fabs(YW) <= 1.0 && fabs(YW) > 0.5) YWbin=1;
    if(fabs(YW) <= 1.5 && fabs(YW) > 1.0) YWbin=2;
    if(fabs(YW) <= 2.0 && fabs(YW) > 1.5) YWbin=3;
    if(fabs(YW) <= 2.5 && fabs(YW) > 2.0) YWbin=4;
    if(fabs(YW) <= 3.0 && fabs(YW) > 2.5) YWbin=5;
    if(fabs(YW) > 3.0) YWbin=6;

    return YWbin;
  }

 double CorrFactorWeightZ(const double & PTW, const double & YW, const bool & poscharge, const unsigned int & norm_type, const unsigned int & phase_space) {
    //this extra correction factor essentially is used to weight the correction factor above by the number of LH,RH,LO bosons in a particular bin
    //it's basically the result of Number of LH,RH,LO bosons in this (PT,Y) bin divided by the average over all (PT,Y) bins (which is what we really want to measure)
    //without this factor, the reweighting method gives equal weight to all bins i.e. fL(PtW, YW) is flat - we know this is not true!

    //the Number of e.g. LeftHanded bosons is given by total number of bosons in the bin * fL. The fit function we use to extract the 3 fit parameters
    //for the curves is [0]*(1/4(1-x)^2) + [1]*(1/4(1+x)^2) + [2]*(1/2(1-x^2)). If you do the maths, you find that the integral i.e. total N in that bin
    //is equal to 2/3([0]+[1]+[2]). you can find fL by [0]/([0]+[1]+[2]). So N*fL = 2/3[0].
    //The correction factor we want is fL in a bin divided by the average fL over all bins.
    //fL in a bin is NL/N = [0] / [0]+[1]+[2].
    //fL averaged over all bins is sum[0] / sum([0]+[1]+[2]) (not the same as sum ([0]/[0]+[1]+[2]) !!)

    //the convention of the phase_space is:
    //0 = ignore
    //1 = 50-inf
    //2 = 100-inf
    //3 = 50-75
    //4 = 75-100

   if(!poscharge) {std::cout << "What?!? Negative charge lepton CorrFactorWeightZ ???" << std::endl; return 1.0;}

    if(phase_space == 0) {
      //std::cout<<"INFO: phase_space == 0"<<std::endl;
      return 1.0;
    }
    double numbosons_bin=0.0, allbosons_bin=0.0, numbosons_total=0.0, allbosons_total=0.0;

    double corr_factor=0.0;

    if(poscharge) {
      if(norm_type == 0) numbosons_bin = GetWeightFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_plus;
      if(norm_type == 1) numbosons_bin = GetWeightFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_plus;
      if(norm_type == 2) numbosons_bin = GetWeightFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_plus;
      allbosons_bin += GetWeightFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_plus;
      allbosons_bin += GetWeightFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_plus;
      allbosons_bin += GetWeightFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_plus;
    }else{
      // if(norm_type == 1) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_minus; //remember that LH/RH definition flips with charge
      // if(norm_type == 0) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_minus;
      // if(norm_type == 2) numbosons_bin = GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_minus;
      // allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).alpha_minus;
      // allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).beta_minus;
      // allbosons_bin += GetWeightFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).gamma_minus;
    }

    for(unsigned int i=0; i<3; i++) {
      for(unsigned int j=0; j<7; j++) {
	if(poscharge) {
	  if(norm_type == 0) numbosons_total += GetWeightFitParametersZ(phase_space).at(i).at(j).alpha_plus;
	  if(norm_type == 1) numbosons_total += GetWeightFitParametersZ(phase_space).at(i).at(j).beta_plus;
	  if(norm_type == 2) numbosons_total += GetWeightFitParametersZ(phase_space).at(i).at(j).gamma_plus;
	  allbosons_total += GetWeightFitParametersZ(phase_space).at(i).at(j).alpha_plus;
	  allbosons_total += GetWeightFitParametersZ(phase_space).at(i).at(j).beta_plus;
	  allbosons_total += GetWeightFitParametersZ(phase_space).at(i).at(j).gamma_plus;
	}else{
	  // if(norm_type == 1) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).alpha_minus;
	  // if(norm_type == 0) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).beta_minus;
	  // if(norm_type == 2) numbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).gamma_minus;
	  // allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).alpha_minus;
	  // allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).beta_minus;
	  // allbosons_total += GetWeightFitParameters(phase_space).at(i).at(j).gamma_minus;
	}
      }
    }

    if(allbosons_bin == 0.0 || allbosons_total == 0.0) corr_factor = 0.0; //to prevent divide by zero errors
    else corr_factor = (numbosons_bin / allbosons_bin) / (numbosons_total / allbosons_total); //i.e. fL in bin divided by <fL> all bins etc
    return corr_factor;
  }


  //Since the Ai Reweighting is done relative to the initial values in each bin, the reweighting strategy is different to that employed for the generation of the fi templates, where it is 100% in each bin
  //What is still required however, is the actual value given the mcreco50 cut (which changes the PT(W), Y(W) phase space - which is the only thing that affects the Ais) in order to scale relative to
  double AiCorrFactor(const double & PTW, const double & YW, const double & costhetastar, const double & phistar, const bool & poscharge, const unsigned int & scale_ai, const double & scale_factor, const unsigned int & phase_space, const bool & relative) {

    //basically, this function gives the event a weight according to a modified value of a particular Ai
    //this is done by taking the value of the AiFunction (essentially the differential cross-section) at some point rather than some bin (statistics) in the [cos(theta),phi] space
    //this is the only difference to the cos(theta*) reweighting.
    //The ratio is new(bin)/new(all) / old(bin)/old(all). This causes cancellations of constant terms
    //The value of new(all) = old(all) = 16pi/3 i.e. independent of Ai
    //There is an option to choose relative or absolute reweighting i.e. Ai += Ai or Ai *= Ai
    //There is also the choice of the gen level or reco level phase space (currently only mcreco50)
    //phase_space = 0 is the gen level
    //phase_space = 1 is mcreco50

    double A0=0.0, A1=0.0, A2=0.0, A3=0.0, A4=0.0;
    if(poscharge) {
      A0 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA0;
      A1 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA1;
      A2 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA2;
      A3 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA3;
      A4 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA4;
    } else {
      A0 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA0;
      A1 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA1;
      A2 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA2;
      A3 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA3;
      A4 = GetAiFitParameters(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA4;
    }

    double current_value = AiFunction(costhetastar, phistar, A0, A1, A2, A3, A4);

    if(relative) {
      if(scale_ai == 0) A0 *= scale_factor;
      if(scale_ai == 1) A1 *= scale_factor;
      if(scale_ai == 2) A2 *= scale_factor;
      if(scale_ai == 3) A3 *= scale_factor;
      if(scale_ai == 4) A4 *= scale_factor;
    } else {
      if(scale_ai == 0) A0 += scale_factor;
      if(scale_ai == 1) A1 += scale_factor;
      if(scale_ai == 2) A2 += scale_factor;
      if(scale_ai == 3) A3 += scale_factor;
      if(scale_ai == 4) A4 += scale_factor;
    }

    double rescaled_value = AiFunction(costhetastar, phistar, A0, A1, A2, A3, A4);

    return (rescaled_value/current_value);
  }

 double AiCorrFactorZ(const double & PTW, const double & YW, const double & costhetastar, const double & phistar, const bool & poscharge, const unsigned int & scale_ai, const double & scale_factor, const unsigned int & phase_space, const bool & relative) {

    //basically, this function gives the event a weight according to a modified value of a particular Ai
    //this is done by taking the value of the AiFunction (essentially the differential cross-section) at some point rather than some bin (statistics) in the [cos(theta),phi] space
    //this is the only difference to the cos(theta*) reweighting.
    //The ratio is new(bin)/new(all) / old(bin)/old(all). This causes cancellations of constant terms
    //The value of new(all) = old(all) = 16pi/3 i.e. independent of Ai
    //There is an option to choose relative or absolute reweighting i.e. Ai += Ai or Ai *= Ai
    //There is also the choice of the gen level or reco level phase space (currently only mcreco50)
    //phase_space = 0 is the gen level
    //phase_space = 1 is mcreco50

    double A0=0.0, A1=0.0, A2=0.0, A3=0.0, A4=0.0;
    if(poscharge) {
      A0 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA0;
      A1 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA1;
      A2 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA2;
      A3 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA3;
      A4 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).pA4;
    } else {
      std::cout << "Calling Z Ai corr factor for minus charge! Error!" << std::endl;
      return 0;
      // A0 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA0;
      // A1 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA1;
      // A2 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA2;
      // A3 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA3;
      // A4 = GetAiFitParametersZ(phase_space).at(GetPTbin(PTW)).at(GetYbin(YW)).mA4;
    }

    double current_value = AiFunction(costhetastar, phistar, A0, A1, A2, A3, A4);

    if(relative) {
      if(scale_ai == 0) A0 *= scale_factor;
      if(scale_ai == 1) A1 *= scale_factor;
      if(scale_ai == 2) A2 *= scale_factor;
      if(scale_ai == 3) A3 *= scale_factor;
      if(scale_ai == 4) A4 *= scale_factor;
    } else {
      if(scale_ai == 0) A0 += scale_factor;
      if(scale_ai == 1) A1 += scale_factor;
      if(scale_ai == 2) A2 += scale_factor;
      if(scale_ai == 3) A3 += scale_factor;
      if(scale_ai == 4) A4 += scale_factor;
    }

    double rescaled_value = AiFunction(costhetastar, phistar, A0, A1, A2, A3, A4);

    return (rescaled_value/current_value);
  }



  double AiFunction(const double & costhetastar, const double & phistar, const double & A0, const double & A1, const double & A2, const double & A3, const double & A4) {

    //this is the explicit evaluation of the cross-section in terms of the Ai vector at some [cos(theta*), phi*]
    //there is no need to worry about normalisation because it cancels out.
    double part00 = 1.0 + (costhetastar*costhetastar);
    double part0 = 0.5*(1.0 - (3.0*costhetastar*costhetastar));
    double part1 = 2.0*costhetastar*TMath::Sqrt(1.0 - (costhetastar*costhetastar))*TMath::Cos(phistar);
    double part2 = 0.5*(1.0 - (costhetastar*costhetastar))*TMath::Cos(2.0*phistar);
    double part3 = TMath::Sqrt(1.0 - (costhetastar*costhetastar))*TMath::Cos(phistar);
    double part4 = costhetastar;

    double total = part00 + A0*part0 + A1*part1 + A2*part2 + A3*part3 + A4*part4;
    return total;
  }

  double CorrFactorZ(const double & PTW, const double & YW, const unsigned int & bin, const bool & poscharge, const unsigned int & norm_type) {
    //a comment about what happens here - we would like to return the ratio of the bin content to the total integral between the actual
    //value in that (Pt,Y) bin, and the reweighted value (i.e. what you would get if it followed a pure distribution)

    if(norm_type > 2) std::cout << "Why is norm_type greater than 2? There are only 3 polarisation modes!" << std::endl;
    if(!poscharge) std::cout << "Why have you chosen the negative charged lepton from the Z-decay?" << std::endl;
    double alpha=0.0, beta=0.0, gamma=0.0;
    //initialise the (alpha,beta,gamma) parameters for the different scenarios - namely charge(-,+) with norm_type (LH=0, RH=1, LO=2)
    if(poscharge) {
      if(norm_type == 0) {alpha=1.0;beta=0.0;gamma=0.0;}
      if(norm_type == 1) {alpha=0.0;beta=1.0;gamma=0.0;}
      if(norm_type == 2) {alpha=0.0;beta=0.0;gamma=1.0;}
    }

    double norm_type_ratio = BinFraction(alpha, beta, gamma, bin);
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

    if(poscharge) {
      alpha = GetZFitParameters().at(PTWbin).at(YWbin).alpha_plus;
      beta = GetZFitParameters().at(PTWbin).at(YWbin).beta_plus;
      gamma = GetZFitParameters().at(PTWbin).at(YWbin).gamma_plus;
    }
    double curr_type_ratio = BinFraction(alpha, beta, gamma, bin); //test for 0
    //std::cout << "curr_type_ratio = " << curr_type_ratio << std::endl;

    double corr_factor = norm_type_ratio/curr_type_ratio;

    return corr_factor;
  }


  double GetVertexReweighting(int numVertices) {
    double factors[] = {1.56627, 1.098, 0.891746, 0.783242, 0.864583, 0.723386, 0.812342, 0.759226, 1.23993, 0.260883, 0.0}; //see root_macros/vertex_reweighting.C for details
    int numVert = 0;
    if(numVertices >=11) numVert = 10;
    else numVert = numVertices - 1; //to match the indices of the above array
    return factors[numVert];
  }

  double GetVertexReweightingElectron(int numVertices) {
    double factors[] = {1.64917, 1.07035, 0.861513
                        ,0.820111, 0.789897
                        ,0.812765, 0.606498
                        ,0.85954 ,0.958555
                        ,0.447677,1.29329
                        ,0};

    int numVert = 0;
    if(numVertices >=12) numVert = 11;
    else numVert = numVertices - 1;
    return factors[numVert];
  }

} // ~namespace Operation
