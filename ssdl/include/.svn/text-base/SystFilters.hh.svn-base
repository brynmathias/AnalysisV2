#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
#include "Types.hh"
using namespace std;
using namespace Event;
namespace SSDL {

  class pfMetUncer : public Compute::ObjectFilter<LorentzV>{

  public:
    pfMetUncer(double scale, bool addLeps, bool addTaus):
      _scale(scale),
      _addLeps(addLeps),
      _addTaus(addTaus)
    {
      mModifies=true;}

    ~pfMetUncer(){}

    bool Apply(LorentzV* ob){
      if (!ob) {return true;}

      double scale=1.+_scale;
      
      if (_addLeps){
	for (std::vector<const Event::Lepton *>::const_iterator el = mEv->LD_CommonElectrons().accepted.begin();
	     el != mEv->LD_CommonElectrons().accepted.end();
	     ++el){
	  (*ob) = (*ob) + (**el);
	}
	for (std::vector<const Event::Lepton *>::const_iterator mu = mEv->LD_CommonMuons().accepted.begin();
	     mu != mEv->LD_CommonMuons().accepted.end();
	     ++mu){
	  (*ob) = (*ob) + (**mu);
	}
	
	if(_addTaus){
	  for (std::vector<const Event::Lepton *>::const_iterator tau = mEv->LD_CommonTaus().accepted.begin();
	       tau != mEv->LD_CommonTaus().accepted.end();
	       ++tau){
	    (*ob) = (*ob) + (**tau);
	  }
	}
      }
      
      ob->SetPxPyPzE(ob->Px()*scale, ob->Py()*scale, ob->Pz()*scale, ob->E()*scale);
      
      if (_addLeps){
	for (std::vector<const Event::Lepton *>::const_iterator el = mEv->LD_CommonElectrons().accepted.begin();
	     el != mEv->LD_CommonElectrons().accepted.end();
	     ++el){
	  (*ob) = (*ob) - (**el);
	}
	for (std::vector<const Event::Lepton *>::const_iterator mu = mEv->LD_CommonMuons().accepted.begin();
	     mu != mEv->LD_CommonMuons().accepted.end();
	     ++mu){
	  (*ob) = (*ob) - (**mu);
	}
	
	if(_addTaus){
	  for (std::vector<const Event::Lepton *>::const_iterator tau = mEv->LD_CommonTaus().accepted.begin();
	       tau != mEv->LD_CommonTaus().accepted.end();
	       ++tau){
	    (*ob) = (*ob) - (**tau);
	  }
	}
      }	
      
      return true;

    }
    
    
    std::ostream & Description(std::ostream & ostrm) {
      ostrm << "[METUncer] Scale factor: " << _scale;
      return ostrm;
    }
    
  private:
    double _scale;
    bool _addLeps;
    bool _addTaus;
  };

  class MetUncerJES : public Compute::ObjectFilter<LorentzV>{
    //this class modifies the MET from the modified jets by recalculating MHT
    //and adjusting accordingly. AGB - 21/12/2010
  public:
    MetUncerJES()
      
    {
      mModifies=true;
    }
    
    bool Apply(LorentzV* ob){
      if (!ob) {return true;}
      _ptcut=(Utils::GetConfig<double>("Common.Jets.PtCut"));
      _etacut=(Utils::GetConfig<double>("Common.Jets.EtaCut"));
      _applyID=(Utils::GetConfig<bool>("Common.Jets.ApplyID"));
      _tightID=(Utils::GetConfig<bool>("Common.Jets.TightID"));

      LorentzV rawMHT;
      rawMHT.SetPxPyPzE(0.,0.,0.,0.);
      LorentzV newpfmet;
      newpfmet.SetPxPyPzE(0.,0.,0.,0.);
      
      for (std::vector<Event::Jet>::const_iterator j = mEv->JD_Jets().begin();
      	   j != mEv->JD_Jets().end(); ++j){
	
      	//apply common cuts etc.
      	if(fabs(j->Pt())<_ptcut || fabs(j->Eta())>_etacut) continue;
      	if(_applyID && !(j->GetLooseId())) continue;
      	if(_tightID && !(j->GetTightId())) continue;

      	//now calculate MHT which will correspond to basic MHT (ie no JES)
      	rawMHT-=(*j);
      }
      
      //take the correction to MHT (a vector) as preJES MHT - Common (post JES) MHT
      LorentzV corrMHT = mEv->CommonMHT() - rawMHT;
      //add this correction to pfmet to determine new pfmet
      newpfmet = (*ob)+corrMHT;

      //modify the MET passed to the filter 

      ob->SetPxPyPzE(newpfmet.Px(), newpfmet.Py(), newpfmet.Pz(), newpfmet.E());

      return true;
      
    }

 std::ostream & Description(std::ostream & ostrm) {
      ostrm << "MET uncertainty taken according to JES";
      return ostrm;
    }
    
  private:
    double _ptcut;
    double _etacut;
    bool _applyID;
    bool _tightID;
    
  };



}

