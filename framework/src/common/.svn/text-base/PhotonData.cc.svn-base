/*! \file PhotonicData.cc
 * \brief Source code for the EventStuff::PhotonicData event data container.
 */

#include "PhotonData.hh"
#include "Utils.hh"
#include "EventData.hh"
#include "Photon.hh"
#include "GenObject.hh"
#include "KinSuite.hh"
#include <stdexcept>

namespace Compute {
  namespace Photon {

    CommonPhotons::CommonPhotons(const Event::Data & ev) :
      Compute::Variable<CommonPhotons_Data, CommonPhotons>(ev),
      XClean(Utils::GetConfig<bool>("Common.ApplyXCleaning") &&
	     Utils::GetConfig<bool>("XCleaning.PhotonJet")),
      applyXClean(Utils::GetConfig<bool>("Common.ApplyXCleaning")),
      mEtCut(Utils::GetConfig<double>("Common.Photons.EtCut")),
      mEtaEBMaxCut(Utils::GetConfig<double>("Common.Photons.EtaEBMaxCut")),
      mEtaEEMinCut(Utils::GetConfig<double>("Common.Photons.EtaEEMinCut")),
      mEtaEEMaxCut(Utils::GetConfig<double>("Common.Photons.EtaEEMaxCut")),
      mEcalIsoCut(Utils::GetConfig<double>("Common.Photons.EcalIsoCut")),
      mEcalIsoRel(Utils::GetConfig<double>("Common.Photons.EcalIsoRel")),
      mHcalIsoCut(Utils::GetConfig<double>("Common.Photons.HcalIsoCut")),
      mHcalIsoRel(Utils::GetConfig<double>("Common.Photons.HcalIsoRel")),
      mTrackIsoCut(Utils::GetConfig<double>("Common.Photons.TrackIsoCut")),
      mTrackIsoRel(Utils::GetConfig<double>("Common.Photons.TrackIsoRel")),
      mHadOverEmCut(Utils::GetConfig<double>("Common.Photons.HadOverEmCut")),
      mR9Cut(Utils::GetConfig<double>("Common.Photons.R9Cut")),
      mSigIhIhEBCut(Utils::GetConfig<double>("Common.Photons.SigIhIhEBCut")),
      mSigIhIhEECut(Utils::GetConfig<double>("Common.Photons.SigIhIhEECut")),
      mIDReq(Utils::GetConfig<int>("Common.Photons.IDReq")),
      mUseID(Utils::GetConfig<bool>("Common.Photons.UseID")),
      mRequireLooseForOdd(Utils::GetConfig<bool>("Common.Photons.RequireLooseForOdd"))
    {}

    void CommonPhotons::_Update() const {
      mData.accepted.clear();
      mData.odd.clear();
      mData.killed.clear();
      mData.hasOdd = false;

      if(XClean){
        for(std::vector<Event::Photon const*>::const_iterator ipho
                = mEv.CC().Photons.begin();
            ipho!=mEv.CC().Photons.end();
            ++ipho){
	  if(!*ipho) continue;
          ProcessPhoton(*ipho);
        }
      }
      else{
        if(photon_proc.Enabled()){
           if(photon_proc.Modifies()){
             for(std::vector<Event::Photon*>::iterator ii=mAltered.begin();
                 ii!=mAltered.end();++ii){
               mPool.free(*ii);
             }
             mAltered.clear();
             for(std::vector<Event::Photon>::const_iterator
                     iphot=mEv.PD_Photons().begin();
                 iphot!=mEv.PD_Photons().end();
                 ++iphot){
               Event::Photon phot(*iphot);
               Event::Photon* mphot=&phot;
               if(photon_proc.Apply(&phot)){
                 mphot = mPool.construct(phot);
                 mAltered.push_back(mphot);
               	 ProcessPhoton(mphot);
               }
             }
          }
          else{
            for (std::vector<Event::Photon>::const_iterator
                     ipho= mEv.PD_Photons().begin();
                 ipho != mEv.PD_Photons().end();
                 ++ipho) {
              if(photon_proc.Apply(&*ipho)) ProcessPhoton(&*ipho);
            }
          }
        }
        else{
         for(std::vector<Event::Photon>::const_iterator
                   ipho=mEv.PD_Photons().begin();
               ipho!=mEv.PD_Photons().end();
               ++ipho){
             ProcessPhoton(&*ipho);
           }
        }
      }
      // Sort photons in pt
      sort(mData.accepted.begin(), mData.accepted.end(), KinSuite::PCompare);
      sort(mData.odd.begin(),      mData.odd.end(),      KinSuite::PCompare);
      sort(mData.killed.begin(),   mData.killed.end(),   KinSuite::PCompare);
    }

  } //~namespace Photon
} //~namespace Compute
