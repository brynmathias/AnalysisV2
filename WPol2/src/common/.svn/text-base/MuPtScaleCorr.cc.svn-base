#include "MuPtScaleCorr.hh"
#include "iostream.h"
#include "Math/VectorUtil.h"
namespace Operation{


  double MCPtBinsCorrection(double pt, double eta, double phi, int charge){


    double ptmin=20;
    double ptmax=200;
    double etamax=2.1; 

    if (pt<ptmin || pt>ptmax || eta<-etamax || eta>etamax) return 0;


TProfile3D *ist;

    if (charge==1){

#include "mcptbinscorrectionfactorsplus.txt"

    }

    else if (charge==-1){

#include "mcptbinscorrectionfactorsminus.txt"

    }
    else return 0;


   double out = ist->GetBinContent(ist->FindBin(pt,eta,phi));

   delete ist;

   return out;

  }

  TLorentzVector MuPtScaleCorr(int charge, TLorentzVector v, bool doGen){
   cout << "Non supported outdated version of MuPtScaleCorr: You should not be reading it"<<endl;
   TLorentzVector null;
   return  null;
 }
  
  TLorentzVector MuPtScaleCorrIdealGen(int charge, TLorentzVector v, bool doGen, Event::Data* ev){


    // cout << "start"<<endl;
    // if (ev==NULL)  cout << "Bad "<<endl;
    // FOR DATA
    if ((ev)->GetIsData()){

double CS01;
double CS02;
double CA01;
double CA02;
double CAS1;
double CAS2;
double PHASE;
double CAE1;
double CAEB2; 
double CAEE2;

// 4_1_3_p2 DATA
//       CS01= 0;
//       CS02= 0;
//       CA01= 0;
//       CA02= -4.382e-03;
//       CAS1= 0;
//       CAS2= -6.795e-03;
//       PHASE= -8.890e-01;
//       CAE1= 0;
//       CAEB2= -3.131e-02;
//       CAEE2= -2.6560e-02;

// 4_2 DATA
       CS01= 0;
       CS02= 0;
       CA01= 0;
       CA02= -2.8052e-03;
       CAS1= 0;
       CAS2= -8.0415e-03;
       PHASE= -9.1734e-01;
       CAE1= 0;
       CAEB2= 3.5678e-04;
       CAEE2= 6.4624e-03;

       double pt=v.Pt();
       double eta=v.Eta();
       double phi=v.Phi();
       //remember: the correction is the inverse of the data obtained by fitlambda!!!
       // corrfunction:	
       // add here a function of complexity you like
       //double newpt = pt-pt*(CS01+CS02*pt/100+charge*(CA01+CA02*pt/100)+charge*(CAS1+CAS2*pt/100)*TMath::Sin(phi+PHASE)+charge*(CAE1+0.5*(CAEB2+CAEE2+TMath::Sign(CAEB2,0.5-TMath::Abs(eta))+TMath::Sign(CAEE2,TMath::Abs(eta)-0.5))*pt/100)*eta);
       TLorentzVector out(1,0,0,1);
       double newpt = pt+pt*pt/100.*0.01*charge+pt*pt/100.*0.01*charge*sin(phi-.5);//-eta*pt*pt/100.*0.01*charge ;  
      
       out.SetPtEtaPhiM(newpt,eta,phi,v.M());
       return out;
    }

    // FOR MC
   else{
     if(ev==NULL) cout << "WARING WPol2::MuPtScaleCorr will do nothing!!!"<<endl;

     // cout << "before crash"<<endl;
     bool matched =  false;
     TLorentzVector out(1,0,0,1);
     for (std::vector<Event::GenObject>::const_iterator j = ev->GenParticles().begin();  j != ev->GenParticles().end(); ++j) 
       {
	 if(fabs(j->GetID())==13)//&&j->Status(1)==1)
	   {
	     TLorentzVector gnn;
	     gnn.SetPtEtaPhiM(j->Pt(),j->Eta(),j->Phi(),j->M());
	     if ( fabs(ROOT::Math::VectorUtil::DeltaR(v,gnn)) < 0.1) {
	       out.SetPtEtaPhiM(gnn.Pt(),v.Eta(),v.Phi(),gnn.M());
	       matched = true;
	     }
	   }
       }


     if(matched)
       {
	 // 	 cout << "out.PT: "<< out.Pt()<<" in PT: "<< v.Pt()<<  endl;
	 return out;
       }
     else {
       out.SetPtEtaPhiM(0,v.Eta(),v.Phi(),0);
        return out;
     }
     return v;

     //



	 //   double newpt=pt+pt*pt*MCPtBinsCorrection(pt,eta,phi,charge);	  
   	  
   }
     /*
     cout <<"non suppotred method:MuPtScaleCorr "<<endl;

      double pt=v.Pt();
      double eta=v.Eta();
      double phi=v.Phi();
      
      double newpt=pt+pt*pt*MCPtBinsCorrection(pt,eta,phi,charge);
      TLorentzVector out(1,0,0,1);
      out.SetPtEtaPhiM(newpt,eta,phi,v.M());
      return out;
	 */
  }

}
