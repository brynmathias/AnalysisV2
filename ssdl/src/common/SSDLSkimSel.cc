#include "SSDLSkimSel.hh"


namespace SSDL{

  SSDLSkimSel::SSDLSkimSel(const Utils::ParameterSet & ps1,const Utils::ParameterSet & ps2,const Utils::ParameterSet & ps2pat,const Utils::ParameterSet & ps3):
    elid(ps1),
    muidpf(ps2),
    muidpat(ps2pat),
    tauid(ps3){}

  SSDLSkimSel::~SSDLSkimSel(){

  }
    
  void SSDLSkimSel::Start(Event::Data & ev){

    elid.Init(ev);
    muidpf.Init(ev);
    muidpat.Init(ev);
    tauid.Init(ev);
    ele=0;
    mu=0;
    tau=0;
  }

  bool SSDLSkimSel::Process(Event::Data & ev){

    for (std::vector<Event::Lepton>::const_iterator el = ev.LD_Electrons().begin(); el!=ev.LD_Electrons().end(); ++el){
      if(!el->Pt()>4){continue;}
      else{
	ele+=ev.LD_Electrons().size();
	mu+=ev.LD_Muons().size()+ev.LD_SecMuons().size();
	tau+=ev.LD_Taus().size();
	return true;
      }
    }

    for (std::vector<Event::Lepton>::const_iterator mu1 = ev.LD_Muons().begin(); mu1!=ev.LD_Muons().end(); ++mu1){
      if(!mu1->Pt()>4){continue;}
      if(!mu1->GetLooseId()){continue;}
      else{
	ele+=ev.LD_Electrons().size();
	mu+=ev.LD_Muons().size()+ev.LD_SecMuons().size();
	tau+=ev.LD_Taus().size();
    	return true;
    	  }
    }

     for (std::vector<Event::Lepton>::const_iterator mu2 = ev.LD_SecMuons().begin(); mu2!=ev.LD_SecMuons().end(); ++mu2){
       if(!mu2->Pt()>4){continue;}
       if(!mu2->GetLooseId()){continue;}
      else{
	ele+=ev.LD_Electrons().size();
	mu+=ev.LD_Muons().size()+ev.LD_SecMuons().size();
	tau+=ev.LD_Taus().size();
    	return true;
    	  }
    }

for (std::vector<Event::Lepton>::const_iterator t = ev.LD_Taus().begin(); t!=ev.LD_Taus().end(); ++t){
  if(!t->Pt()>4){continue;}
      else{
	ele+=ev.LD_Electrons().size();
	mu+=ev.LD_Muons().size()+ev.LD_SecMuons().size();
	tau+=ev.LD_Taus().size();
	return true;
	  }
    }

     return false;
  }


std::ostream & SSDLSkimSel::Description(std::ostream & ostrm){
    ostrm << "SSDL skim selection" << std::endl;
    return ostrm;
  }
      
  
}
