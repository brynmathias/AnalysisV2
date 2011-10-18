#ifndef _Structures_HH_
#define _Structures_HH_


namespace Operation {

  struct jSolutionsW {
    bool realSolutions; //true implies real solutions, false implies complex ones
    double rightSol;
    double wrongSol;
    double sol1;
    double sol2;
  };

  struct jFitParameters {
    double alpha_plus;
    double alpha_minus;
    double beta_plus;
    double beta_minus;
    double gamma_plus;
    double gamma_minus;
  };

  struct jAiFitParameters {
    double pA0;
    double pA1;
    double pA2;
    double pA3;
    double pA4;
    double mA0;
    double mA1;
    double mA2;
    double mA3;
    double mA4;
  };

 

} // ~namespace Operation
#endif
