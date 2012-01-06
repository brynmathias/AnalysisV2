// Custom Cross-cleaning class
// Currently only performs muon-jet cross-cleaning

#ifndef CustomCC_hh
#define CustomCC_hh


#include "Types.hh"
#include "Compute_Variable.hh"
#include <vector>
#include "Jet.hh"
#include "Lepton.hh"
#include "Photon.hh"
#include "CrossClean.hh"
#include "Utils.hh"

namespace Compute{
struct CustomCC_Data{
  CloneVector<Event::Jet> Jets;
  CloneVector<Event::Lepton> Muons;
  CloneVector<Event::Lepton> Electrons;
  CloneVector<Event::Photon> Photons;
  std::vector<KillOp> KillMap;
};

class CustomCC : public Compute::Variable<CustomCC_Data,CustomCC>{
 public:
  CustomCC(const Event::Data & ev);
  void _Update() const;
 private:
  bool mApplyCC;
  bool mResolveConflicts;
 public:
  mutable CrossCleaner xc;
  mutable ObjectProcessor<Event::Jet> jet_pre_proc;
  mutable ObjectProcessor<Event::Jet> jet_post_proc;
  mutable ObjectProcessor<Event::Lepton> muon_pre_proc;
  mutable ObjectProcessor<Event::Lepton> muon_post_proc;
  mutable ObjectProcessor<Event::Lepton> electron_pre_proc;
  mutable ObjectProcessor<Event::Lepton> electron_post_proc;
  mutable ObjectProcessor<Event::Lepton> tau_pre_proc;
  mutable ObjectProcessor<Event::Lepton> tau_post_proc;
  mutable ObjectProcessor<Event::Photon> photon_pre_proc;
  mutable ObjectProcessor<Event::Photon> photon_post_proc;
 private:
  JetFilter jet_cut;
  LeptonFilter muon_cut;
  LeptonFilter electron_cut;
  PhotonFilter photon_cut;
  bool verbose_;
};
}
#endif
