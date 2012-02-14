#include "Jet.hh"
#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "TRandom3.h"


#include "CommonOps.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"



namespace Event {


  /**
  Scale the jet P4 by "factor", with either a linear dependence on eta or not.
  JESUncert(0.,false)     means no scaling.
  JESUncert(0.1,false)    means +10%, independent of eta
  JESUncert(-0.1,false)   means -10%, independent of eta
  JESUncert(0.02,true)    means +2% per unit eta
  JESUncert(-0.02,true)   means -2% per unit eta
  */
class JESUncert : public Compute::ObjectFilter<Event::Jet> {

public:

  JESUncert( std::string direction )
    : direction_(direction)
  {
    mModifies = true;
  }
  ~JESUncert(){}

  bool Apply( Event::Jet* ob ) {
    if (!ob) { return true; }
    double scale = 1.;
    if(ob->Pt() >= 200.){
      scale = 1.01387 - (1.44026e-5)*ob->Pt() + (1.49385e-3)*sqrt(ob->Pt());
    }
    else{
      scale = 1.04877 + (1.68131e-4)*ob->Pt() - (3.55493e-3)*sqrt(ob->Pt());
    }
    if(strcmp("-ve",direction_.c_str()) == 0){
      ob->SetPxPyPzE(ob->Px()/scale, ob->Py()/scale, ob->Pz()/scale, ob->E()/scale);
    }else if(strcmp("+ve",direction_.c_str()) == 0){
      ob->SetPxPyPzE(ob->Px()*scale, ob->Py()*scale, ob->Pz()*scale, ob->E()*scale);
    }
      return true;
    }

    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "[JESUncert] scaling: " << direction_ << "direction";
      return ostrm;
    }

  private:
    std::string direction_;
  };

/**
Scale the jet P4 by by the correction factor given in python/icf/ResidualJetEnergyCorrections

**/
// From: http://cmslxr.fnal.gov/lxr/source/CondFormats/JetMETObjects/src/Utilities.cc?v=CMSSW_3_8_5#099
//------------------------------------------------------------------------
double quadraticInterpolation(double fZ, const double fX[3], const double fY[3])
{
  // Quadratic interpolation through the points (x[i],y[i]). First find the parabola that
  // is defined by the points and then calculate the y(z).
  double D[4],a[3];
  D[0] = fX[0]*fX[1]*(fX[0]-fX[1])+fX[1]*fX[2]*(fX[1]-fX[2])+fX[2]*fX[0]*(fX[2]-fX[0]);
  D[3] = fY[0]*(fX[1]-fX[2])+fY[1]*(fX[2]-fX[0])+fY[2]*(fX[0]-fX[1]);
  D[2] = fY[0]*(pow(fX[2],2)-pow(fX[1],2))+fY[1]*(pow(fX[0],2)-pow(fX[2],2))+fY[2]*(pow(fX[1],2)-pow(fX[0],2));
  D[1] = fY[0]*fX[1]*fX[2]*(fX[1]-fX[2])+fY[1]*fX[0]*fX[2]*(fX[2]-fX[0])+fY[2]*fX[0]*fX[1]*(fX[0]-fX[1]);
  if (D[0] != 0)
  {
    a[0] = D[1]/D[0];
    a[1] = D[2]/D[0];
    a[2] = D[3]/D[0];
  }
  else
  {
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;
  }
  double r = a[0]+fZ*(a[1]+fZ*a[2]);
  return r;
}

double ptFactor(int index, double pt, std::vector<double>& Corr0,std::vector<double>& Corr1,std::vector<double>& Corr2){
  return Corr0.at(index) - fabs(Corr1.at(index))*atan(log10( std::min( 1.0, pt / Corr2.at(index) ) ));
}




class JESCorrections : public Compute::ObjectFilter<Event::Jet> {

public:

  JESCorrections( const Utils::ParameterSet & ps , bool ApplyInterpolation)
    :
  EtaLow( ps.Get<std::vector<double> >("EtaLow") ),
    EtaHi( ps.Get<std::vector<double> >("EtaHi") ),
    Correction0_( ps.Get<std::vector<double> >("Correction0") ),
    Correction1_( ps.Get<std::vector<double> >("Correction1") ),
    Correction2_( ps.Get<std::vector<double> >("Correction2") ),
    ApplyInterpolation_(ApplyInterpolation)
  {
    mModifies = true;
  }
  ~JESCorrections(){}

  unsigned int index( double eta, bool &ok ){
    for(unsigned int i = 0; i < EtaLow.size(); i++){
      if(eta >= EtaLow[i] && eta <= EtaHi[i]){
        ok = true;
        return i;
      }
    }
    ok = false;
    return 0;
  }

  bool Apply( Event::Jet* ob ) {
    if (!ob) { return true; }
    if(!ApplyInterpolation_){
      for(unsigned int i = 0; i < EtaLow.size(); i++){
        if(ob->Eta() >= EtaLow[i] && ob->Eta() <= EtaHi[i]){
          ob->SetPxPyPzE(Correction0_[i] * ob->Px(),
                         Correction0_[i] * ob->Py(),
                         Correction0_[i] * ob->Pz(),
                         Correction0_[i] * ob->E());
        }
      }
      return true;
    }

    if(ApplyInterpolation_){
      double fX[3];
      double fY[3];
      bool ok;
      unsigned int idx = index(ob->Eta(), ok);
      if(!ok){return true;}
      if(idx == 0 || idx == (EtaLow.size()-1)){ (*ob) *= ptFactor(idx, ob->Pt(), Correction0_, Correction1_, Correction2_ ); }
      else {
        for(int i = 0; i < 3; i++){
          fX[i]=(EtaLow[i+idx-1]+EtaHi[i+idx-1])/2.;
          fY[i]= ptFactor(idx+i-1, ob->Pt(), Correction0_, Correction1_, Correction2_ );
        }
      // printf( "%5.2lf %lf\n",ob->Eta() , quadraticInterpolation(ob->Pt(),fX,fY)  );
      // printf( "%5.2lf %g\n",ob->Eta() , ptFactor(idx, ob->Pt(), Correction0_, Correction1_, Correction2_ )  );
      // cout << "Uncorrected Jet " ;
          // printf( "%5.2lf %g \n",ob->Eta(), ob->Pt() );
          // cout << " Correction factor for jet is: " << quadraticInterpolation(ob->Eta(),fX,fY) << endl;
        (*ob) *= quadraticInterpolation(ob->Eta(),fX,fY);
      // cout << "  Corrected Jet ";
          // printf( "%5.2lf %g \n",ob->Eta(), ob->Pt() );

      }
    }
  return true;
  }


  void Test(double pt){

    double etaValues[34] = {-5.0,-4.5,-4.2,-3.9,-3.6,-3.3,-3.0,-2.7,-2.4,-2.1,-1.8,-1.5,-1.3,-1.1,-0.9,-0.6,-0.3,0.0,0.3,0.6,0.9,1.1,1.3,1.5,1.8,2.1,2.4,2.7,3.0,3.3,3.6,3.9,4.2,4.5};
    Event::Jet Jet(1.0, 0.0, 0.0, 1.0,  0.5,  0,true,false,  Event::Jet::RAW,false,  1, 1, 1 );
    for(int i = 0; i < 34; i++){
      double eta = etaValues[i]+.133;
      Jet.SetPxPyPzE(1., 0., sinh(eta), cosh(eta));
    // Jet.SetPtEtaPhiE(pt, eta, 0 , 1.5*pt);
    // Jet.SetPt(pts);
    // printf( "%5.2f %5.2f %g\n", eta ,Jet.Eta(), Jet.Pt() );
      Apply(&Jet);
    // cout << "Corrections have been applied, The Jet has been corrected to:";
    // printf( "%5.2lf %g \n",Jet.Eta(), Jet.Pt() );
    }
  }



  std::ostream & Description(std::ostream & ostrm) {
    ostrm << "Residual Jet Energy Corrections are applied";
    return ostrm;
  }

private:

  std::vector<double> EtaLow;
  std::vector<double> EtaHi;
  std::vector<double> Correction0_;
  std::vector<double> Correction1_;
  std::vector<double> Correction2_;
  bool  ApplyInterpolation_;
};

//Smear the corrected jets by some user defined value

class JetSmear : public Compute::ObjectFilter<Event::Jet>
{
public:
  //JetSmear( Smear width, Lowest energy jets can be smeared to, pt low of jets to smear, pt high of jets to smear, etaLow of jets to smear, etaHigh of jets to smear)
  JetSmear (double factor, double floor, double ptLow, double ptHigh, double etaLow, double etaHigh, bool parameterized):
  gaussWidth_( factor ),
    floor_(floor),
    ptLow_(ptLow),
    ptHigh_(ptHigh),
    etaLow_(etaLow),
    etaHigh_(etaHigh),
    parameterized_(parameterized)

  {
    mModifies = true;
  }

  ~JetSmear () {}

  bool Apply( Event::Jet* ob ) {
    if (!ob) { return true; }
    double factorSmear;
    if(parameterized_){
      SmearFactor.SetSeed(0);
      if( fabs(ob->Eta()) < 1.4 ){
        factorSmear = SmearFactor.Gaus(1, (0.245 - 0.1135*log10( ob->Pt() ) + .0041*sqrt(ob->Pt()) ) );
        // cout << "Barrel: " << (0.245 - 0.1135*log10( ob->Pt() ) + .0041*sqrt(ob->Pt()) )<< endl;
        if(ob->Pt() > 500.){ factorSmear = SmearFactor.Gaus( 1, 0.03 ); }
      }
      if( fabs(ob->Eta()) >= 1.4 && fabs(ob->Eta()) <= 3){
        factorSmear = SmearFactor.Gaus(1, ( 0.305 - 0.1477*log10( ob->Pt() ) + 0.006*sqrt(ob->Pt()) ) );
        // cout << "EndCap: " << ( 0.305 - 0.1477*log10( ob->Pt() ) + 0.006*sqrt(ob->Pt()) )  << endl;
        if(ob->Pt() > 500.){ factorSmear = SmearFactor.Gaus( 1, 0.04 ); }
      }

      if(factorSmear <= 0.0){ factorSmear = 1.;}
      // cout << "Jet Pt: "<< ob->Pt() << " is smeared by a factor of " << factorSmear << endl;
      *ob *= factorSmear;
      return true;
    }






    if(!parameterized_){
      double pt = ob->Pt();
      if(fabs(ob->Eta() ) > etaLow_ && fabs(ob->Eta()) < etaHigh_){
        if(ob->Pt() > ptLow_ && ob->Pt() < ptHigh_){
          factorSmear = SmearFactor.Gaus(1, gaussWidth_ );
          if(factorSmear < 0.0){ factorSmear = 0.0001;}
          *ob *= factorSmear;

          if(ob->Pt() <  floor_){
            *ob /= factorSmear;
            *ob /= ( pt  / floor_ );
          }
        }
      }
      return true;
    }
    return true;
  }

  std::ostream & Description(std::ostream & ostrm) {
    ostrm << "Jets have been smeared by a gaussian with width " << gaussWidth_ << " * the Jet Pt";
    return ostrm;
  }


private:
    /* data */
  double gaussWidth_;
  TRandom3 SmearFactor;
  double threshold_;
  double floor_;
  double ptLow_;
  double ptHigh_;
  double etaLow_;
  double etaHigh_;
  bool parameterized_;


}; // end the jet smear class

class VertexReweighting : public Compute::ObjectFilter<double> {

public:
  VertexReweighting(const Utils::ParameterSet & ps):
      weights_(ps.Get<std::vector<double> >("VertexWeights"))
  {
    mModifies = true;
  }

  ~VertexReweighting(){}

  bool Apply( double* weight ) {

   unsigned nvertices = mEv->GetVertexSize();
    if(nvertices >= weights_.size()) nvertices = weights_.size();
    *weight *= weights_[nvertices-1];
    return true;
  }

    std::ostream & Description(std::ostream & ostrm) {
      return ostrm;
    }

 private:
  std::vector<double> weights_;

  };


class GoodVertexReweighting : public Compute::ObjectFilter<double> {

public:
  GoodVertexReweighting(const Utils::ParameterSet & ps):
      weights_(ps.Get<std::vector<double> >("GoodVertexWeights"))
  {
    mModifies = true;
  }
  ~GoodVertexReweighting(){}

  bool Apply(double *weight) {
    unsigned nVertex = 0;
    for(std::vector<float>::const_iterator vtx= mEv->vertexSumPt()->begin();vtx != mEv->vertexSumPt()->end();++vtx){
      if(!mEv->vertexIsFake()->at( vtx-mEv->vertexSumPt()->begin()) &&
        fabs((mEv->vertexPosition()->at( vtx-mEv->vertexSumPt()->begin())).Z()) < 24.0 &&
        mEv->vertexNdof()->at( vtx-mEv->vertexSumPt()->begin() ) > 4 &&
        (mEv->vertexPosition()->at( vtx-mEv->vertexSumPt()->begin())).Rho() < 2.0 ){  nVertex++; }} 
     
    //unsigned nvertices = mEv->GetVertexSize();
    if(nVertex >= weights_.size()) nVertex = weights_.size();
    *weight *= weights_[nVertex];
    return true;
  }

    std::ostream & Description(std::ostream & ostrm) {
      return ostrm;
    }

 private:
  std::vector<double> weights_;

  };





class PreScaleReweighting : public Compute::ObjectFilter<double>
{
public:
  PreScaleReweighting (const Utils::ParameterSet & ps):
    triggers_(ps.Get<std::vector<std::string> >("Triggers")),
    verb_(ps.Get<bool> ("Verbose"))
    {
      mModifies = true;
    }
 ~PreScaleReweighting(){}
  bool Apply( double* weight){
    //loop though triggers to find the lowest presecale
    int preScaleVal = 99999;
            if(verb_){
              std::cout << "New Event" << std::endl;
            }
        std::vector<std::string>::const_iterator it = triggers_.begin();
        std::vector<std::string>::const_iterator ite = triggers_.end();
        for( ; it != ite; ++it){
              if( it->at(it->size()-1) != '*'){
          std::map<std::string, bool>::const_iterator trig = mEv->hlt()->find(*it);
          std::map<std::string, int>::const_iterator prescale = mEv->hlt_prescaled()->find(*it);
          if( (trig != mEv->hlt()->end() && trig->second) && (prescale != mEv->hlt_prescaled()->end() && prescale->second < preScaleVal) ) {
            preScaleVal = prescale->second ;
            if(verb_){
              std::cout << "Trigger " << (*it) << " Has a prescale of " << prescale->second << " " << std::endl;
            }
          }
        }else{
      size_t found;
    // now loop though the map and test the string part -- slow!
      std::map<std::string, bool>::const_iterator itrig = mEv->hlt()->begin();
      std::map<std::string, bool>::const_iterator jtrig = mEv->hlt()->end();
      std::map<std::string, int>::const_iterator ipre = mEv->hlt_prescaled()->begin();
      for( ; itrig != jtrig; ++itrig ){
        if(itrig->second){
          std::string str = *it;
          str = str.substr(0, str.size() - 1 );
          // cout <<*it<< " compare with " << itrig->first << endl;
          found = itrig->first.find(str);
          if(found =! string::npos){ preScaleVal = ipre->second; }
          }
        ipre++;
        }
      }
    }
        if(verb_){
          cout << " The lowest prescale in the event is " << preScaleVal << std::endl;
          if(preScaleVal == 99999) {
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
            cout << "Triggers that exist in the event:" <<endl;
              for(std::map<std::string,bool>::const_iterator it2 = mEv->hlt()->begin();
              it2!= mEv->hlt()->end(); ++it2){
                if( it2->second ) std::cout << it2->first << std::endl;
            }
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
          }
        }
    //if(preScaleVal = 999){preScaleVal=0;}
    *weight *= preScaleVal;
    return true;
  }

  std::ostream & Description(std::ostream & ostrm){
    ostrm << "Reweighted events to reflect the lowest pre-scale in event";
    return ostrm;
  }

private:
  std::vector<std::string> triggers_;
  bool verb_;
};



class JESCorrectionsTrivial : public Compute::ObjectFilter<Event::Jet> {

public:

  JESCorrectionsTrivial(float corScale)

  {
    mModifies = true;
    corScale_ =corScale;
  }

  ~JESCorrectionsTrivial(){} 

  bool Apply( Event::Jet* ob ) {
    if (!ob) { return true; }
    // cout << " trulala"<<endl;
    float corfactor = 1.+corScale_/100.;
    ob->SetPxPyPzE(corfactor * ob->Px(),
                         corfactor * ob->Py(),
                         corfactor * ob->Pz(),
                         corfactor * ob->E());
        
  return true;
  }


  std::ostream & Description(std::ostream & ostrm) {
    ostrm << "Jet Energy Corrections scalled by:" <<corScale_<< "%"<<endl; 
    return ostrm;
  }

private:
  float  corScale_ ;

};
}
