/*! \file LeptonicData.cc
 * \brief Source code for the EventStuff::LeptonicData event data container.
 */

#include "LeptonData.hh"

#include "EventData.hh"
#include "Lepton.hh"
#include "KinSuite.hh"
#include "Math/GenVector/VectorUtil.h"

using ROOT::Math::VectorUtil::DeltaR;
#include "Utils.hh"

namespace Compute {
  namespace Lepton {


  // JJ - updated to const reference to avoid copying data
  CommonElectrons::CommonElectrons(const Event::Data & ev) :
      Compute::Variable<CommonElectrons_Data, CommonElectrons>(ev),
      XClean(Utils::GetConfig<bool>("Common.ApplyXCleaning") &&
              Utils::GetConfig<bool>("XCleaning.ElectronJet")),
      applyXClean(Utils::GetConfig<bool>("Common.ApplyXCleaning")),
      mEtCut(Utils::GetConfig<double>("Common.Electrons.PtCut")),
      mEtaCut(Utils::GetConfig<double>("Common.Electrons.EtaCut")),
      mTrkIsoCut(Utils::GetConfig<double> ("Common.Electrons.TrkIsoCut")),
      mCombIsoCut(Utils::GetConfig<double>("Common.Electrons.CombIsoCut")),
      mTightID(Utils::GetConfig<bool>("Common.Electrons.TightID")),
      mApplyID(Utils::GetConfig<bool>("Common.Electrons.ApplyID")),
      mRequireLooseForOdd(Utils::GetConfig<bool>("Common.Electrons.RequireLooseForOdd"))
  {
  }

    void CommonElectrons::_Update() const {
      mData.accepted.clear();
			mData.odd.clear();
      mData.killed.clear();
      mData.hasOdd = false;

      if(XClean){
        for(std::vector<Event::Lepton const*>::const_iterator iele
                = mEv.CC().Electrons.begin();
            iele!=mEv.CC().Electrons.end();
            ++iele){
          if(!*iele) continue;
          ProcessElectron(*iele);
        }
      }
      else{
        if(electron_proc.Enabled()){
           if(electron_proc.Modifies()){
             for(std::vector<Event::Lepton*>::iterator ii=mAltered.begin();
                 ii!=mAltered.end();++ii){
               mPool.free(*ii);
             }
             mAltered.clear();
             for(std::vector<Event::Lepton>::const_iterator
                     iele=mEv.LD_Electrons().begin();
                 iele!=mEv.LD_Electrons().end();
                 ++iele){
               Event::Lepton ele(*iele);
               Event::Lepton* mele=&ele;
               if(electron_proc.Apply(&ele)){
                 mele = mPool.construct(ele);
                 mAltered.push_back(mele);
                ProcessElectron(mele);
	       }
             }
           }
           else{
             for (std::vector<Event::Lepton>::const_iterator
                     iele= mEv.LD_Electrons().begin();
                 iele != mEv.LD_Electrons().end();
                 ++iele) {
              if(electron_proc.Apply(&*iele)) ProcessElectron(&*iele);
            }
          }
        }
        else{
          for(std::vector<Event::Lepton>::const_iterator
                  iele=mEv.LD_Electrons().begin();
              iele!=mEv.LD_Electrons().end();
              ++iele){
            ProcessElectron(&*iele);
          }
        }
      }
      // Sort electrons in pt
      sort(mData.accepted.begin(), mData.accepted.end(), KinSuite::PCompare);
      sort(mData.odd.begin(),      mData.odd.end(),      KinSuite::PCompare);
      sort(mData.killed.begin(),   mData.killed.end(),   KinSuite::PCompare);
    }

    CommonMuons::CommonMuons(const Event::Data & ev) :
        Compute::Variable<CommonMuons_Data, CommonMuons>(ev),
        mEtCut(Utils::GetConfig<double>("Common.Muons.PtCut")),
        mEtaCut(Utils::GetConfig<double>("Common.Muons.EtaCut")),
        mTrkIsoCut(Utils::GetConfig<double>("Common.Muons.TrkIsoCut")),
        mCombIsoCut(Utils::GetConfig<double>("Common.Muons.CombIsoCut")),
        mTightID(Utils::GetConfig<bool>("Common.Muons.TightID")),
        mApplyID(Utils::GetConfig<bool>("Common.Muons.ApplyID")),
        mRequireLooseForOdd(Utils::GetConfig<bool>("Common.Muons.RequireLooseForOdd")),
	applyXClean(Utils::GetConfig<bool>("Common.ApplyXCleaning")),
        XClean(Utils::GetConfig<bool>("Common.ApplyXCleaning") &&
                Utils::GetConfig<bool>("XCleaning.MuonJet"))

    {}



    void CommonMuons::_Update() const {
      mData.accepted.clear();
			mData.odd.clear();
      mData.killed.clear();
      mData.hasOdd = false;

      if(XClean){
        for (std::vector<Event::Lepton const*>::const_iterator imu = mEv.CC().Muons.begin();
             imu != mEv.CC().Muons.end();
             ++imu) {
          if(!*imu) continue;
          ProcessMuon(*imu);
        }
      }
      else{
        if(muon_proc.Enabled()){
           if(muon_proc.Modifies()){
             for(std::vector<Event::Lepton*>::iterator ii=mAltered.begin();
                 ii!=mAltered.end();++ii){
               mPool.free(*ii);
             }
             mAltered.clear();
             for(std::vector<Event::Lepton>::const_iterator
                     imu=mEv.LD_Muons().begin();
                 imu!=mEv.LD_Muons().end();
                 ++imu){
               Event::Lepton mu(*imu);
               Event::Lepton* mmu=&mu;
               if(muon_proc.Apply(&mu)){
                 mmu = mPool.construct(mu);
                 mAltered.push_back(mmu);
                 ProcessMuon(mmu);
	       }
             }
          }
          else{
            for (std::vector<Event::Lepton>::const_iterator
                     imu= mEv.LD_Muons().begin();
                 imu != mEv.LD_Muons().end();
                 ++imu) {
              if(muon_proc.Apply(&*imu)) ProcessMuon(&*imu);
            }
          }
        }
        else{
         for(std::vector<Event::Lepton>::const_iterator
                  imu=mEv.LD_Muons().begin();
              imu!=mEv.LD_Muons().end();
              ++imu){
            ProcessMuon(&*imu);
          }
        }
      }
      //Sort muons in PT
      sort(mData.accepted.begin(), mData.accepted.end(), KinSuite::PCompare);
      sort(mData.odd.begin(),      mData.odd.end(),      KinSuite::PCompare);
      sort(mData.killed.begin(),   mData.killed.end(),   KinSuite::PCompare);
    }


    CommonTaus::CommonTaus(const Event::Data & ev) :
      Compute::Variable<CommonTaus_Data, CommonTaus>(ev),
      XClean(Utils::GetConfig<bool>("Common.ApplyXCleaning") &&
      	     Utils::GetConfig<bool>("XCleaning.TauJet")),
      applyXClean(Utils::GetConfig<bool>("Common.ApplyXCleaning")),
      mEtCut(Utils::GetConfig<double>("Common.Taus.PtCut")),
      mEtaCut(Utils::GetConfig<double>("Common.Taus.EtaCut")),
      mTauElecClean(Utils::GetConfig<bool>("Common.Taus.ElecClean")),
      mTauMuonClean(Utils::GetConfig<bool>("Common.Taus.MuonClean")),
      mTauJetClean(Utils::GetConfig<bool>("Common.Taus.JetClean")),
      mTightID(Utils::GetConfig<bool>("Common.Taus.TightID")),
      mApplyID(Utils::GetConfig<bool>("Common.Taus.ApplyID"))
    {}
    void CommonTaus::_Update() const {
      mData.accepted.clear();
      mData.killed.clear();
      mData.hasOdd = false;

      if(tau_proc.Enabled()){
	if(tau_proc.Modifies()){
	  for(std::vector<Event::Lepton*>::iterator ii=mAltered.begin();
	      ii!=mAltered.end();++ii){
	    mPool.free(*ii);
	  }
	  mAltered.clear();
	  for(std::vector<Event::Lepton>::const_iterator
		itau=mEv.LD_Taus().begin();
	      itau!=mEv.LD_Taus().end();
	      ++itau){
	    Event::Lepton tau(*itau);
	    Event::Lepton* mtau=&tau;
	    if(tau_proc.Apply(&tau)){
	      mtau = mPool.construct(tau);
	      mAltered.push_back(mtau);
      	      ProcessTau(mtau);
            }
	  }
	}
	else{
	  for (std::vector<Event::Lepton>::const_iterator
		 itau= mEv.LD_Taus().begin();
	       itau != mEv.LD_Taus().end();
	       ++itau) {
	    if(tau_proc.Apply(&*itau)) ProcessTau(&*itau);
	  }
	}
      }
      else{
	for(std::vector<Event::Lepton>::const_iterator
	      itau=mEv.LD_Taus().begin();
	    itau!=mEv.LD_Taus().end();
	    ++itau){
	  ProcessTau(&*itau);
	}
      }
      // }
      //Sort taus in PT
      sort(mData.accepted.begin(),
	   mData.accepted.end(),
	   KinSuite::PCompare);
      sort(mData.killed.begin(),
	   mData.killed.end(),
	   KinSuite::PCompare);
    }




  
//     GoodElectrons::GoodElectrons(const Event::Data & ev) :
//       Compute::Variable<std::vector<Event::Lepton const *>, GoodElectrons>(ev) {}

//     void GoodElectrons::_Update() const {
//       mData.clear();
//       // Fill the good electron container from the common electrons that
//       // meet the good electron criteria.
//       for (std::vector<Event::Lepton const *>::const_iterator e = mEv.LD_CommonElectrons().accepted.begin() ;
// 	   e != mEv.LD_CommonElectrons().accepted.end() ;
// 	   ++e) {
// 	if ( (**e).GetTightId() ) {
// 	  mData.push_back(*e); // add the common electron to the good set.
// 	} // end of good electron criteria check.
//       } // end of loop over common electrons
//     }

//     GoodMuons::GoodMuons(const Event::Data & ev) :
//       Compute::Variable<std::vector<Event::Lepton const *>, GoodMuons>(ev) {}

//     void GoodMuons::_Update() const {
//       mData.clear();
//       // Fill the good electron container from the common electrons that
//       // meet the good electron criteria.
//       for (std::vector<Event::Lepton const *>::const_iterator e = mEv.LD_CommonMuons().accepted.begin() ;
// 	   e != mEv.LD_CommonMuons().accepted.end() ;
// 	   ++e) {
// 	if ( (**e).GetTightId() ) {
// 	  mData.push_back(*e); // add the common electron to the good set.
// 	} // end of good electron criteria check.
//       } // end of loop over common electrons
//     }

//     GoodLepRecoil::GoodLepRecoil(const Event::Data & ev) :
//       Compute::Variable<Double_t, GoodLepRecoil>(ev) {}

//     void GoodLepRecoil::_Update() const {
//       mData = 0.;
//       for (std::vector<Event::Lepton const *>::const_iterator e = mEv.LD_GoodElectrons().begin() ;
// 	   e!= mEv.LD_GoodElectrons().end() ;
// 	   ++e) {
// 	mData += (**e).Et();
//       } // end of loop over good electrons
//       for (std::vector<Event::Lepton const *>::const_iterator mu = mEv.LD_GoodMuons().begin() ;
// 	   mu != mEv.LD_GoodMuons().end() ;
// 	   ++mu) {
// 	mData += (**mu).Et();
//       } // end of loop over good muons
//     }

  } //~namespace Lepton
} //~namespace Compute
