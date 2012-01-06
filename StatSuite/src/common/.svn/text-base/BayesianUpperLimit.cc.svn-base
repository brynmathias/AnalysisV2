#include "BayesianUpperLimit.hh"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TRandom.h"
//#include <boost/math/special_functions/gamma.hpp>

#include "Math/DistFunc.h"
#include "Math/Math.h"
#include "Math/SpecFuncMathCore.h"
#include "Math/ProbFuncMathCore.h"
#include <TCanvas.h>



using namespace ROOT::Math;
#include <cmath>
#include "Math/IParamFunction.h"



/**
 *  Original code from John Conway, November 2004.
 *  Ported to C++ and developed further by
 *  Wolfgang Waltenberger May 2010.
 */

using namespace std;

namespace Conway{
  double factorial ( int n )
  {
    double root2pi=2.506628;
    if ( n < 9 )
    {
      static double fact[10]={1.,1.,2.,6.,24.,120.,720.,5040.,40320.,362880. };
      return fact[n];
    }
    if ( n < 0 )
    {
      return 1.;
    }
    double x=n;
    return root2pi*sqrt(x)*pow(x,n)*exp(-x)*(1.+1./12./x );
  }
}


double BayesianLikelihood ( int nev, double sac, double xbg, double sbg, double xev )
{
  double xxbg=xbg;
  double ssbg=sbg;
  double ssac = sac;
  double xxev=xev;
  // double ssev = xxev * ssac;

  double xint=0.;

  int nmax=2000;
  for ( int i=0; i< nmax  ; i++ )
  {
    double yybg=-1.;
    double yyev=-1.;
    while ( (yybg < 0.) || (yyev < 0.) )
    {
      double a=gRandom->Gaus();
      double b=gRandom->Gaus();
      yybg = xxbg + a * ssbg;
      yyev = xxev * ( 1. + b * ssac );
    }

    double yyex=yybg + yyev;

    // For numerical stability, we split up nev in two,
    // if nev is large.
    int nev1=nev;
    int nev2=0;
    if ( nev > 100 )
    {
      nev1=nev/2;
      nev2=nev-nev1;
    }
    // double xxxr = pow(yyex,nev1) * exp(-yyex) / factorial(nev) * pow(yyex,nev2);
    //  double xxx = exp (  nev * log ( yyex ) - yyex - boost::math::lgamma<long>(nev+1 ) );

    double xxx = exp (  nev * log ( yyex ) - yyex - TMath::LnGamma(nev+1 ) );

    // cout << "xxx=" << xxx << " xxx1=" << exp (xxx1) << endl;
    if ( !isfinite(xxx) ) cout << "[blike] xxx=" << xxx 
                               << " yyex=" << yyex << " nev=" << nev
			       << ", nev!=" << Conway::factorial(nev) << endl;
    xint +=xxx;
  }

  return xint/double(nmax);
}

double BayesianUpperLimit ( int nev, double sac, double xbg, double sbg, 
              double cl, double prec, double smax )
{
  if (smax < 1e-5 ) smax = 10. * nev;
  /*
  cout << "[bayes] nev=" << nev << " sac=" << sac << " xbg=" << xbg
       << " sbg=" << sbg << " cl=" << cl << " prec=" << prec 
       << " smax=" << smax << endl; */
  double xevmax = smax;
  double dxev = prec;
  double bsum=0.;
  double xev=dxev/2.;
  double blist[10000];
  double xlist[10000];

  int nlist =0;
  while (true)
  {
    double xlike = BayesianLikelihood ( nev,sac,xbg,sbg,xev);
    if ( (!isfinite(xlike)) || isnan(xlike) ) 
    {
      if ( nlist==0 )
      {
        cout << "[BayesianUpperLimit] first likelihood is nan/inf! return -1!" << endl;
        return -1.;
      }
      cout << endl;
      cout << "(D=" << nev << ", s=" << xev << ", l=" << xlike << endl;
      exit(0);
    }
    xlist[nlist]=xev;
    blist[nlist]=xlike;
    bsum+=xlike;
    cout << "(D=" << nev << ", s=" << xev << ", l=" << xlike << ")\033[1A" << endl;
    xev+=dxev;
    if ( blist[nlist]/blist[0] < 1e-6 ) break;
    if ( xev > xevmax ) break;
    nlist++;
  }
  cout << endl;

  int icl=0;
  double bint=0.;
  double bcl=0.;
  for ( int i=0; i<nlist ; i++ )
  {
    if ( ( bint < cl * bsum ) && ( (bint+blist[i])>cl*bsum) )
    {
      icl=i;
      bcl=bint;
    }
    bint+=blist[i];
  }
  
  double plim=xlist[icl]+( xlist[icl+1]-xlist[icl] ) * (cl*bsum-bcl)/blist[icl+1];
  return plim;
}

