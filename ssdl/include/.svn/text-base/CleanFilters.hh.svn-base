#include "Utils.hh"
#include "Math/VectorUtil.h"
#include "KinSuite.hh"
#include "Types.hh"
using namespace std;
using namespace Event;
namespace SSDL {

  //TauJetDRFilter
  class TauJetDrFilter : public Compute::ObjectFilter<Event::Jet>{
    
  public:
  TauJetDrFilter(double drCut):
    mDRCut(drCut) {
    mModifies=false;}
    
    ~TauJetDrFilter(){}

    bool Apply(const Event::Jet* ob){
      
      bool goodjet=true;
      for (std::vector<const Event::Lepton *>::const_iterator itau = mEv->LD_CommonTaus().accepted.begin();
	   itau != mEv->LD_CommonTaus().accepted.end();
	   ++itau) {
	if (!goodjet) continue;
	if (KS_DeltaR(**itau, *ob)<mDRCut)  goodjet=false;
      }
      
      return goodjet;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(tau-jet) Cut > "<< mDRCut;
      return ostrm;
    }
    
  private:
    double mDRCut;
  };
  
  //MuonElectronDrFilter
  class MuonElectronDrFilter : public Compute::ObjectFilter<Event::Lepton>{
    
  public:
    MuonElectronDrFilter(double drCut):
      mDRCut(drCut) {
      mModifies=false;}
    
  ~MuonElectronDrFilter(){}
    
    bool Apply(const Event::Lepton* ob){
      
      bool goodelec=true;
      for (std::vector<const Event::Lepton *>::const_iterator imu = mEv->LD_CommonMuons().accepted.begin();
	   imu != mEv->LD_CommonMuons().accepted.end();
	   	   ++imu) {
	if (!goodelec) continue;
	if (KS_DeltaR(**imu, *ob)<mDRCut)  goodelec=false;
      }
      
      return goodelec;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(muon - electron) Cut > "<< mDRCut;
      return ostrm;
    }
    
  private:
    double mDRCut;
  };
  
  
  //MuonTauDrFilter
  class MuonTauDrFilter : public Compute::ObjectFilter<Event::Lepton>{
    
  public:
    MuonTauDrFilter(double drCut):
      mDRCut(drCut) {
      mModifies=false;}
    
    ~MuonTauDrFilter(){}
    
    bool Apply(const Event::Lepton* ob){
      
      bool goodtau=true;
      for (std::vector<const Event::Lepton *>::const_iterator imu = mEv->LD_CommonMuons().accepted.begin();
	   imu != mEv->LD_CommonMuons().accepted.end();
	   ++imu) {
	if (!goodtau) continue;
	if (KS_DeltaR(**imu, *ob)<mDRCut)  goodtau=false;
      }      
      return goodtau;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(tau-jet) Cut > "<< mDRCut;
      return ostrm;
    }
    
  private:
    double mDRCut;
  };

  //ElectronTauDrFilter
  class ElectronTauDrFilter : public Compute::ObjectFilter<Event::Lepton>{
    
  public:
    ElectronTauDrFilter(double drCut):
      mDRCut(drCut) {
      mModifies=false;}
    
    ~ElectronTauDrFilter(){}
    
    bool Apply(const Event::Lepton* ob){
      
      bool goodtau=true;
      for (std::vector<const Event::Lepton *>::const_iterator iel = mEv->LD_CommonElectrons().accepted.begin();
	   iel != mEv->LD_CommonElectrons().accepted.end();
	   ++iel) {
	if (!goodtau) continue;
	if (KS_DeltaR(**iel, *ob)<mDRCut)  goodtau=false;
      }      
      return goodtau;
    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(tau-jet) Cut > "<< mDRCut;
      return ostrm;
    }
    
  private:
    double mDRCut;
  };


  //ElectronJetDrFilter
  class ElectronJetDrFilter : public Compute::ObjectFilter<Event::Jet>{

  public:
    ElectronJetDrFilter(double drCut):
      mDRCut(drCut){
      mModifies = false;}

    ~ElectronJetDrFilter(){}

    bool Apply(const Event::Jet* ob){
      
      bool goodjet=true;
      for (std::vector<const Event::Lepton *>::const_iterator iel = mEv->LD_CommonElectrons().accepted.begin();
	   iel != mEv->LD_CommonElectrons().accepted.end();
	   iel++){
	if (!goodjet) continue;
	if (KS_DeltaR(**iel, *ob)<mDRCut) goodjet=false;
      }
      return goodjet;
    }

    std::ostream & Description(std::ostream & ostrm){
      ostrm << "CUston DR(jet - electron) cut > " << mDRCut;
      return ostrm;
    }

  private:
    double mDRCut;
  };



 class MuonJetDrFilter : public Compute::ObjectFilter<Event::Jet>{

  public:
    MuonJetDrFilter(double drCut):
      mDRCut(drCut){
      mModifies = false;}

    ~MuonJetDrFilter(){}

    bool Apply(const Event::Jet* ob){
      
      bool goodjet=true;
      for (std::vector<const Event::Lepton *>::const_iterator imu = mEv->LD_CommonMuons().accepted.begin();
	   imu != mEv->LD_CommonMuons().accepted.end();
	   imu++){
	if (!goodjet) continue;
	if (KS_DeltaR(**imu, *ob)<mDRCut) goodjet=false;
      }
      return goodjet;
    }

   std::ostream & Description(std::ostream & ostrm){
      ostrm << "Custom DR(jet - muon) cut > " << mDRCut;
      return ostrm;
    }

  private:
    double mDRCut;
  };


  //Corrected D0 Filter

  class LeptonD0Filter : public Compute::ObjectFilter<Event::Lepton>{
  public:
    LeptonD0Filter(double d0Cut, double X, double Y):
      mD0Cut(d0Cut),
      mX(X),
      mY(Y){
      mModifies=false;}
    
    ~LeptonD0Filter(){}
    
    bool Apply(const Event::Lepton* ob){
 			  
      float d0=(ob->GetType()==2) ? mEv->GetMuonCombD0(ob->GetIndex()) : 
 	mEv->GetElectronD0(ob->GetIndex());

      double corrD0 = fabs(d0 - mX*sin(ob->Phi())+mY*cos(ob->Phi()));
      return (corrD0 < mD0Cut);

    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "D0 Cut  "<< mD0Cut;
      return ostrm;
    }
    
  private:
    double mD0Cut;
    double mX;
    double mY;
  };

class LeptonD0FilterVertex : public Compute::ObjectFilter<Event::Lepton>{
  public:
    LeptonD0FilterVertex(double d0Cut):
      mD0Cut(d0Cut)
      {
      mModifies=false;}
    
    ~LeptonD0FilterVertex(){}
    
    bool Apply(const Event::Lepton* ob){
 			  
      float d0=(ob->GetType()==2) ? mEv->GetMuonCombD0(ob->GetIndex()) : 
 	mEv->GetElectronD0(ob->GetIndex());

      ICF_XYZPoint position;
      if(mEv->GetVertexSize()==0){
	position=mEv->GetBeamSpotPosition();//if we can't find a vertex we use the beamspot (we should probably reject events with no vertex though)
	  }

      else if (mEv->GetVertexSize()>1){//if there are more than one vertices, we take the one with most associated tracks
	int vertexNtrks=-1;
	int best_vertex=-1;
	for (int i=0; i<mEv->GetVertexSize(); i++){
	  int ntrks = mEv->GetvertexNtrks(i);
	  if (ntrks>vertexNtrks){
	    vertexNtrks=ntrks;
	    best_vertex=i;
	  }
	}
	position=mEv->GetvertexPosition(best_vertex);
      }
      else{//otherwise take the only vertex available
	position=mEv->GetvertexPosition(0);
      }

      double corrD0 = fabs(d0 - position.X()*sin(ob->Phi())+position.Y()*cos(ob->Phi()));
      return (corrD0 < mD0Cut);

    }
    
    std::ostream & Description(std::ostream & ostrm){
      ostrm << "D0 Cut  "<< mD0Cut;
      return ostrm;
    }
    
  private:
    double mD0Cut;
  };
}
