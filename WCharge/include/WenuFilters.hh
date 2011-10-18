#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
#include "JetData.hh"
#include "LeptonData.hh"
#include "Jet.hh"
#include "Lepton.hh"
using namespace std;
using namespace Event;
namespace WCharge {

  //Remove Jets that clash with good electrons Filter
  class JetEleDrFilter : public Compute::ObjectFilter<Event::Jet>{
    
  public:
  JetEleDrFilter(double drCut):
    mDRCut(drCut) {
    mModifies=false;}
    
    ~JetEleDrFilter(){}

    bool Apply(const Event::Jet* ob){
      bool goodjet=true;
      for (std::vector<const Event::Lepton *>::const_iterator iel = mEv->LD_CommonElectrons().accepted.begin();
	         iel != mEv->LD_CommonElectrons().accepted.end();
	         ++iel) {
	      if (!goodjet) continue;
      	if (KS_DeltaR(**iel, *ob)<mDRCut)  goodjet=false;
      }
      return goodjet;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(ele-jet) Cut > "<< mDRCut;
      return ostrm;
    }
    
  private:
    double mDRCut;
  };

  //Remove electrons that clash with good jets
  class EleJetDrFilter : public Compute::ObjectFilter<Event::Lepton>{
    
  public:
    EleJetDrFilter(double drCut):
      mDRCut(drCut) {
      mModifies=false;}
    
    ~EleJetDrFilter(){}
    
    bool Apply(const Event::Lepton* ob){
      bool goodelec=true;
      for (std::vector<const Event::Jet *>::const_iterator ijet = mEv->JD_CommonJets().accepted.begin();
	        ijet != mEv->JD_CommonJets().accepted.end();
	        ++ijet) {
	    if (!goodelec) continue;
	      if (KS_DeltaR(**ijet, *ob)<mDRCut)  goodelec=false;
      }
      
      return goodelec;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(ele-jet) Cut > "<< mDRCut;
      return ostrm;
    }
    
  private:
    double mDRCut;
  };
}
