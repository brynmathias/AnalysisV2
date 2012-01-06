// A Custom Cross-cleaning class

#include "CustomCC.hh"
#include "Lepton.hh"
#include "Jet.hh"
#include "EventData.hh"
#include <Math/VectorUtil.h>
#include "Utils.hh"

namespace Compute{
CustomCC::CustomCC(const Event::Data & ev)
    : Compute::Variable<CustomCC_Data,CustomCC>(ev),
      mApplyCC(Utils::GetConfig<bool>("Common.ApplyXCleaning")),
      mResolveConflicts(Utils::GetConfig<bool>("XCleaning.ResolveConflicts")),
      xc(Utils::GetConfig<bool>("XCleaning.MuonJet"),
         Utils::GetConfig<double>("XCleaning.Muons.TrkIsoCut"),
         Utils::GetConfig<double>("XCleaning.Muons.CombIsoCut"),
         Utils::GetConfig<bool>("XCleaning.Muons.ModifyJetEnergy"),
				 Utils::GetConfig<double>("XCleaning.Muons.MuonJetDeltaR"),       // TW added to make configurable.
				 Utils::GetConfig<double>("XCleaning.Muons.MuonIsoTypePtCutoff"), // TW added to make configurable.
         Utils::GetConfig<bool>("XCleaning.Muons.RequireLooseIdForInitialFilter"),   // TW added to make configurable.
         Utils::GetConfig<bool>("XCleaning.ElectronJet"),
         Utils::GetConfig<double>("XCleaning.Electrons.TrkIsoCut"),
         Utils::GetConfig<double>("XCleaning.Electrons.CombIsoCut"),
         Utils::GetConfig<double>("XCleaning.Electrons.ElectronJetDeltaR"),       // TW added to make configurable.
         Utils::GetConfig<double>("XCleaning.Electrons.ElectronIsoTypePtCutoff"), // TW added to make configurable.
         Utils::GetConfig<bool>("XCleaning.Electrons.ElectronLooseIdRequired"),   // TW added to make configurable.
         Utils::GetConfig<bool>("XCleaning.Electrons.ElectronTightIdRequired"),   // TW added to make configurable.
         Utils::GetConfig<bool>("XCleaning.Electrons.RequireLooseIdForInitialFilter"),   // TW added to make configurable.
         Utils::GetConfig<bool>("XCleaning.PhotonJet"),
         Utils::GetConfig<double>("XCleaning.Photons.TrkIsoCut"),
         Utils::GetConfig<double>("XCleaning.Photons.CaloIsoCut"),
         Utils::GetConfig<int>("XCleaning.Photons.IDReq"),
         Utils::GetConfig<bool>("XCleaning.Photons.UseID"),
         Utils::GetConfig<double>("XCleaning.Photons.PhotonJetDeltaR"),           // TW added to make configurable.
         Utils::GetConfig<double>("XCleaning.Photons.PhotonIsoTypePtCutoff"),           // TW added to make configurable.
         mData.Jets,
         mData.Muons,
         mData.Electrons,
   mData.Photons,
   Utils::GetConfig<bool>("XCleaning.Verbose")),
      jet_cut(Utils::GetConfig<double>("XCleaning.Jets.PtCut"),
              Utils::GetConfig<double>("XCleaning.Jets.EtaCut")),
      //muon_cut(Utils::GetConfig<double>("XCleaning.Muons.PtCut"),   // TW - old version
      //         Utils::GetConfig<double>("XCleaning.Muons.EtaCut")), // TW - old version
      muon_cut(Utils::GetConfig<double>("XCleaning.Muons.PtCut"),
               Utils::GetConfig<double>("XCleaning.Muons.EtaCut"),
							 Utils::GetConfig<bool>("XCleaning.Muons.RequireLooseIdForInitialFilter")), // TW - added
      //electron_cut(Utils::GetConfig<double>("XCleaning.Electrons.PtCut"),  // TW - old version
      //            Utils::GetConfig<double>("XCleaning.Electrons.EtaCut")), // TW - old version
      electron_cut(Utils::GetConfig<double>("XCleaning.Electrons.PtCut"),
                   Utils::GetConfig<double>("XCleaning.Electrons.EtaCut"),
                   Utils::GetConfig<bool>("XCleaning.Electrons.RequireLooseIdForInitialFilter")), // TW - added
      photon_cut(Utils::GetConfig<double>("XCleaning.Photons.EtCut"),
                 Utils::GetConfig<double>("XCleaning.Photons.EtaEBMaxCut"),
                 Utils::GetConfig<double>("XCleaning.Photons.EtaEEMinCut"),
                 Utils::GetConfig<double>("XCleaning.Photons.EtaEEMaxCut")),
      verbose_( Utils::GetConfig<bool>("XCleaning.Verbose") )
{}

void CustomCC::_Update() const{
  xc.Reset();
  mData.Jets.Clear();
  mData.Muons.Clear();
  mData.Electrons.Clear();
  mData.Photons.Clear();

  // Jets
  if(jet_pre_proc.Modifies()){
    for(std::vector<Event::Jet>::const_iterator ij=mEv.JD_Jets().begin();
        ij!=mEv.JD_Jets().end();
        ++ij){
      Event::Jet *jet;
      std::vector<const Event::Jet*>::iterator ijc=mData.Jets.AddClone(&*ij,&jet);
      if(!jet_pre_proc.Apply(jet) || !jet_cut(jet)) *ijc=0;
    }
  }
  else{
    for(std::vector<Event::Jet>::const_iterator ij=mEv.JD_Jets().begin();
        ij!=mEv.JD_Jets().end();
        ++ij){
      if(!jet_pre_proc.Apply(&*ij) || !jet_cut(&*ij)) mData.Jets.Add(0);
      else mData.Jets.Add(&*ij);
    }
  }

  // Muons
  if(muon_pre_proc.Modifies()){
    for(std::vector<Event::Lepton>::const_iterator ij=mEv.LD_Muons().begin();
        ij!=mEv.LD_Muons().end();
        ++ij){
      Event::Lepton* muon;
      std::vector<const Event::Lepton*>::iterator ijc=mData.Muons.AddClone(&*ij,&muon);
      if(!muon_pre_proc.Apply(muon) || !muon_cut(muon)) *ijc=0;
    }
  }
  else{
      for(std::vector<Event::Lepton>::const_iterator ij=mEv.LD_Muons().begin();
        ij!=mEv.LD_Muons().end();
        ++ij){
        if(!muon_pre_proc.Apply(&*ij) || !muon_cut(&*ij)) mData.Muons.Add(0);
        else mData.Muons.Add(&*ij);
      }
  }

  // Electrons
  if(electron_pre_proc.Modifies()){
    for(std::vector<Event::Lepton>::const_iterator ij=mEv.LD_Electrons().begin();
        ij!=mEv.LD_Electrons().end();
        ++ij){
      Event::Lepton* electron;
      std::vector<const Event::Lepton*>::iterator ijc=mData.Electrons.AddClone(&*ij,&electron);
      if(!electron_pre_proc.Apply(electron) || !electron_cut(electron)) *ijc=0;
    }
  }
  else{
      for(std::vector<Event::Lepton>::const_iterator ij=mEv.LD_Electrons().begin();
        ij!=mEv.LD_Electrons().end();
        ++ij){
        if(!electron_pre_proc.Apply(&*ij) || !electron_cut(&*ij)) mData.Electrons.Add(0);
        else mData.Electrons.Add(&*ij);
      }
  }

  // Photons
  if(photon_pre_proc.Modifies()){
    for(std::vector<Event::Photon>::const_iterator ij=mEv.PD_Photons().begin();
        ij!=mEv.PD_Photons().end();
        ++ij){
      Event::Photon* photon;
      std::vector<const Event::Photon*>::iterator ijc=mData.Photons.AddClone(&*ij,&photon);
      if(!photon_pre_proc.Apply(photon) || !photon_cut(photon)) *ijc=0;
    }
  }
  else{
      for(std::vector<Event::Photon>::const_iterator ij=mEv.PD_Photons().begin();
        ij!=mEv.PD_Photons().end();
        ++ij){
        if(!photon_pre_proc.Apply(&*ij) || !photon_cut(&*ij)) mData.Photons.Add(0);
        else mData.Photons.Add(&*ij);
      }
  }

  xc.Clean();
  if(mResolveConflicts)  xc.Resolve();
  xc.Execute();

  if(mApplyCC){
    if(jet_post_proc.Enabled()){
      if(jet_post_proc.Modifies()){
        for(std::vector<const Event::Jet*>::iterator ij = mData.Jets.begin();
            ij!=mData.Jets.end();
            ++ij){
          if(!*ij) continue;
          Event::Jet* jet=mData.Jets.Clone(ij);
          if(!jet_post_proc.Apply(jet)) *ij=0;
        }
      }
      else{
        for(std::vector<const Event::Jet*>::iterator ij=mData.Jets.begin();
            ij!=mData.Jets.end();
            ++ij){
          if(!*ij) continue;
          if(!jet_post_proc.Apply(*ij)) *ij=0;
        }
      }
    }

    if(muon_post_proc.Enabled()){
      if(muon_post_proc.Modifies()){
        for(std::vector<const Event::Lepton*>::iterator ij = mData.Muons.begin();
            ij!=mData.Muons.end();
            ++ij){
          if(!*ij) continue;
          Event::Lepton* muon=mData.Muons.Clone(ij);
          if(!muon_post_proc.Apply(muon)) *ij=0;
        }
      }
      else{
        for(std::vector<const Event::Lepton*>::iterator ij=mData.Muons.begin();
            ij!=mData.Muons.end();
            ++ij){
          if(!*ij) continue;
          if(!muon_post_proc.Apply(*ij)) *ij=0;
        }
      }
    }

    if(electron_post_proc.Enabled()){
      if(electron_post_proc.Modifies()){
        for(std::vector<const Event::Lepton*>::iterator ij = mData.Electrons.begin();
            ij!=mData.Electrons.end();
            ++ij){
          if(!*ij) continue;
          Event::Lepton* electron=mData.Electrons.Clone(ij);
          if(!electron_post_proc.Apply(electron)) *ij=0;
        }
      }
      else{
        for(std::vector<const Event::Lepton*>::iterator ij=mData.Electrons.begin();
            ij!=mData.Electrons.end();
            ++ij){
          if(!*ij) continue;
          if(!electron_post_proc.Apply(*ij)) *ij=0;
        }
      }
    }

    if(photon_post_proc.Enabled()){
      if(photon_post_proc.Modifies()){
        for(std::vector<const Event::Photon*>::iterator ij = mData.Photons.begin();
            ij!=mData.Photons.end();
            ++ij){
          if(!*ij) continue;
          Event::Photon* photon=mData.Photons.Clone(ij);
          if(!photon_post_proc.Apply(photon)) *ij=0;
        }
      }
      else{
        for(std::vector<const Event::Photon*>::iterator ij=mData.Photons.begin();
            ij!=mData.Photons.end();
            ++ij){
          if(!*ij) continue;
          if(!photon_post_proc.Apply(*ij)) *ij=0;
        }
      }
    }

  }

  // Copy KillMap
  xc.KillMap( mData.KillMap );

}
}
