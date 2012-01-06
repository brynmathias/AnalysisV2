#include <Math/PxPyPzE4D.h>
#include <Math/PxPyPzM4D.h>
#include <Math/LorentzVector.h>
#include <iostream>
#include <sstream>
#include <cmath>

typedef ROOT::Math::LorentzVector< ROOT::Math::PxPyPzE4D<double> > PxPyPzE;
typedef ROOT::Math::LorentzVector< ROOT::Math::PxPyPzM4D<double> > PxPyPzM;

void massive() {

  for ( int i = 0; i < 2; ++i ) { 

    double p = 30;
    double m = 5;

    PxPyPzM j1(p*sin(4.*atan(1.)*2./3.),p*cos(4.*atan(1.)*2./3.),0.,i==0?m:0.);
    PxPyPzM j2(p*sin(4.*atan(1.)*4./3.),p*cos(4.*atan(1.)*4./3.),0.,i==0?m:0.);
  
    double ht = j1.Et() + j2.Et();
    double mht = (j1 + j2).Pt();
    double dht = j1.Et() - j2.Et();
    double at = (0.5*(ht-dht))/sqrt(ht*ht-mht*mht);

    std::cout << (i==0?"[massive] ":"[massless] ")
	      << std::endl
	      << " M: " << j1.M()
	      << " Px: " << j1.Px()
	      << " Py: " << j1.Py()
	      << " Pz: " << j1.Pz()
	      << " P: " << j1.P()
	      << " E: " << j1.E()
	      << " PT: " << j1.Pt()
	      << " ET: " << j1.Et()
	      << std::endl
	      << " M: " << j2.M()
	      << " Px: " << j2.Px()
	      << " Py: " << j2.Py()
	      << " Pz: " << j2.Pz()
	      << " P: " << j2.P()
	      << " E: " << j2.E()
	      << " PT: " << j2.Pt()
	      << " ET: " << j2.Et()
	      << std::endl
	      << " ht: " << ht
	      << " dht: " << dht
	      << " mht: " << mht
	      << " at: " << at
	      << std::endl;

  }

}




