#ifndef GEN_MATRIX_HH
#define GEN_MATRIX_HH

#include <set>
#include "GenObject.hh"
#include "Compute_Variable.hh"

namespace Compute{
namespace Gen{

class GenMatrixData{
 public:
  void fillFrom(const std::vector<Event::GenObject> & genv){
    std::vector<Event::GenObject>::const_iterator gen;
    // Build a set of all mothers
    for(gen = genv.begin(); gen != genv.end(); ++gen){
      if(gen->GetStatus() == 3 && gen->GetMother() != -1)
        mother_ids_.insert(gen->GetMother());
    }

    for(gen = genv.begin(); gen != genv.end(); ++gen){
      fill(*gen);
    }
  }

  void clear(){
    electrons_.clear();
    electron_nus_.clear();
    muons_.clear();
    muon_nus_.clear();
    taus_.clear();
    tau_nus_.clear();
    tops_.clear();
    ws_.clear();
    zs_.clear();
    mother_ids_.clear();
  }


  bool hasMuon() const { return muons_.size(); }
  const Event::GenObject* muon() const{
    assert(muons_.size());
    return muons_[0];
  }

  bool hasMuonNu() const { return muon_nus_.size(); }
  const Event::GenObject* muonNu() const{
    assert(muon_nus_.size());
    return muon_nus_[0];
  }

  bool hasElectron() const { return electrons_.size(); }
  const Event::GenObject* electron() const{
    assert(electrons_.size());
    return electrons_[0];
  }

  bool hasElectronNu() const { return electron_nus_.size(); }
  const Event::GenObject* electronNu() const{
    assert(electron_nus_.size());
    return electron_nus_[0];
  }

  bool hasTau() const{ return taus_.size(); }
  const Event::GenObject* tau() const{
    assert(taus_.size());
    return taus_[0];
  }

  bool hasTauNu() const{ return tau_nus_.size(); }
  const Event::GenObject* tauNu() const{
    assert(tau_nus_.size());
    return tau_nus_[0];
  }

  bool hasTop() const{ return tops_.size(); }
  const Event::GenObject* top() const{
    assert(tops_.size());
    return tops_[0];
  }

  bool hasW() const{ return ws_.size(); }
  const Event::GenObject* w() const{
    assert(ws_.size());
    return ws_[0];
  }

  bool isMother(const Event::GenObject & gen){
    return (mother_ids_.find(gen.GetIndex()) != mother_ids_.end());
  }
 private:

  void fill(const Event::GenObject & gen){
    if(gen.GetStatus() != 3) return;
    unsigned int pid = abs(gen.GetID());
    if(pid == 24) ws_.push_back(&gen);
    else if(pid == 23) zs_.push_back(&gen);
    else if(pid == 6) tops_.push_back(&gen);
    else{
      if(isMother(gen)) return;
      switch(pid){
        case 11: electrons_.push_back(&gen);
          break;
        case 12: electron_nus_.push_back(&gen);
          break;
        case 13: muons_.push_back(&gen);
          break;
        case 14: muon_nus_.push_back(&gen);
          break;
        case 15: taus_.push_back(&gen);
          break;
        case 16: tau_nus_.push_back(&gen);
          break;
      }
    }
  }

  std::vector<const Event::GenObject*> muons_;
  std::vector<const Event::GenObject*> electrons_;
  std::vector<const Event::GenObject*> taus_;
  std::vector<const Event::GenObject*> muon_nus_;
  std::vector<const Event::GenObject*> electron_nus_;
  std::vector<const Event::GenObject*> tau_nus_;
  std::vector<const Event::GenObject*> tops_;
  std::vector<const Event::GenObject*> ws_;
  std::vector<const Event::GenObject*> zs_;
  std::set<unsigned int> mother_ids_;
};

class GenMatrix : public Compute::Variable<GenMatrixData, GenMatrix>{
 public:
  GenMatrix(const Event::Data & ev);
  void _Update() const;
};

}
}
#endif




