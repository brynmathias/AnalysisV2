/*! \file JetData.cc
 * \brief Source code for the Compute::Jet data.
 */

#include "JetData.hh"

#include "Jet.hh"
#include "EventData.hh"
#include "SmearSuite.hh"
#include "KinSuite.hh"

#include "Utils.hh"
namespace Compute {
  namespace Jet {

    CommonJets::CommonJets(const Event::Data & ev) :
      Compute::Variable<CommonJets_Data, CommonJets>(ev),
      applyXClean(Utils::GetConfig<bool>("Common.ApplyXCleaning")),
			XClean(Utils::GetConfig<bool>("Common.ApplyXCleaning") &&
            (Utils::GetConfig<bool>("XCleaning.MuonJet") ||
             Utils::GetConfig<bool>("XCleaning.ElectronJet") ||
             Utils::GetConfig<bool>("XCleaning.PhotonJet"))),
      mPtCut(Utils::GetConfig<double>("Common.Jets.PtCut")),
      mEtaCut(Utils::GetConfig<double>("Common.Jets.EtaCut")),
		  mTightID(Utils::GetConfig<bool>("Common.Jets.TightID")),
		  mApplyID(Utils::GetConfig<bool>("Common.Jets.ApplyID"))
		{ }

    void CommonJets::_Update() const {
      mData.accepted.clear();
      mData.odd.clear();             //TW added - clear the odd jets collection.
      mData.hasOdd = false;

      mData.killed.clear();
      mData.killed_10_30.clear();
      mData.killed_30_50.clear();
      mData.baby.clear();
      mData.baby_10_30.clear();
      mData.baby_30_50.clear();
      mData.killedHT = LorentzV(0,0,0,0);
      mData.killedHT_10_30 = LorentzV(0,0,0,0);
      mData.killedHT_30_50 = LorentzV(0,0,0,0);
      mData.babyHT = LorentzV(0,0,0,0);
      mData.babyHT_10_30 = LorentzV(0,0,0,0);
      mData.babyHT_30_50 = LorentzV(0,0,0,0);

      if(XClean){
         for(std::vector<const Event::Jet*>::const_iterator
                 iJ=mEv.CC().Jets.begin();
             iJ!=mEv.CC().Jets.end();
             ++iJ){
           if(!*iJ) continue;
           ProcessJet(*iJ);
         }
      }
      else{
         if(jet_proc.Enabled()){
           if(jet_proc.Modifies()){
             for(std::vector<Event::Jet*>::iterator ii=mAltered.begin();
                 ii!=mAltered.end();++ii){
               mPool.free(*ii);
             }
             mAltered.clear();
             for(std::vector<Event::Jet>::const_iterator
                     ijet=mEv.JD_Jets().begin();
                 ijet!=mEv.JD_Jets().end();
                 ++ijet){
               Event::Jet jet(*ijet);
               Event::Jet* mjet=&jet;
               if(jet_proc.Apply(&jet)){
                 mjet = mPool.construct(jet);
                 mAltered.push_back(mjet);
                 ProcessJet(mjet);
               }
             }
          }
          else{
            for (std::vector<Event::Jet>::const_iterator
                     ijet= mEv.JD_Jets().begin();
                 ijet != mEv.JD_Jets().end();
                 ++ijet) {
              if(jet_proc.Apply(&*ijet)) ProcessJet(&*ijet);
            }
          }
        }
        else{
         for(std::vector<Event::Jet>::const_iterator
                  ijet=mEv.JD_Jets().begin();
              ijet!=mEv.JD_Jets().end();
              ++ijet){
            ProcessJet(&*ijet);
          }
        }
      }
      // Sort the common jet collections in PT
      sort(mData.accepted.begin(),     mData.accepted.end(),     KinSuite::PCompare);
      sort(mData.odd.begin(),          mData.odd.end(),          KinSuite::PCompare);
      sort(mData.killed.begin(),       mData.killed.end(),       KinSuite::PCompare);
      sort(mData.killed_10_30.begin(), mData.killed_10_30.end(), KinSuite::PCompare);
      sort(mData.killed_30_50.begin(), mData.killed_30_50.end(), KinSuite::PCompare);
      sort(mData.baby.begin(),         mData.baby.end(),         KinSuite::PCompare);
      sort(mData.baby_10_30.begin(),   mData.baby_10_30.end(),   KinSuite::PCompare);
      sort(mData.baby_30_50.begin(),   mData.baby_30_50.end(),   KinSuite::PCompare);
    }

    EMJets::EMJets(const Event::Data & ev) :
        Compute::Variable<std::vector<Event::Jet const *>, EMJets>(ev),
        mComEMFracCut("Common.Jets.EMFracCut")
    {}

    void EMJets::_Update() const {
      mData.clear();
      for ( std::vector<Event::Jet>::const_iterator j = mEv.JD_Jets().begin();
      j != mEv.JD_Jets().end();
      ++j) {
  // If the preconf jet fails the EM cut, add it to the EM jet vector
  if (j->GetEmFrac() > mComEMFracCut) {
    mData.push_back(&*j);
  }
      }
    }

  } //~namespace Jet
} //~namespace Compute
