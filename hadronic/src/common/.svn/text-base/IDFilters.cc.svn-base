/*! \file IDFilters.cc
 * \brief Implementation of the hadronic ID filters.
 */

#include "IDFilters.hh"

#include "EventData.hh"

namespace Hadronic {
	//_______________________________________________________________
	//
	// Muon::IDFilter
	//
	Muon::IDFilter::IDFilter( const Utils::ParameterSet& ps)
	{
		mModifies = true;
		verbose_ = ps.Get<bool>("Verbose");
		//
		//identification
		loose_.requireTrackerMuon = ps.Get<bool>("LooseCuts.RequireTrackerMuon");
		loose_.requireGlobalMuon  = ps.Get<bool>("LooseCuts.RequireGlobalMuon");
		loose_.chiSquaredCut      = ps.Get<double>("LooseCuts.ChiSquaredCut");
		loose_.numChambersCut   = ps.Get<int>("LooseCuts.NumChambersCut");
		loose_.numGlobalHits      = ps.Get<int>("LooseCuts.NumGlobalHits");
		loose_.numTrackerHits     = ps.Get<int>("LooseCuts.NumTrackerHits");
		loose_.numPixelHits     = ps.Get<int>("LooseCuts.NumPixelHits");
		loose_.dxyCut             = ps.Get<double>("LooseCuts.DxyCut");
		//
		tight_.requireTrackerMuon = ps.Get<bool>("TightCuts.RequireTrackerMuon");
		tight_.requireGlobalMuon  = ps.Get<bool>("TightCuts.RequireGlobalMuon");
		tight_.chiSquaredCut      = ps.Get<double>("TightCuts.ChiSquaredCut");
		tight_.numChambersCut   = ps.Get<int>("TightCuts.NumChambersCut");
		tight_.numGlobalHits      = ps.Get<int>("TightCuts.NumGlobalHits");
		tight_.numTrackerHits     = ps.Get<int>("TightCuts.NumTrackerHits");
		tight_.numPixelHits     = ps.Get<int>("TightCuts.NumPixelHits");
		tight_.dxyCut             = ps.Get<double>("TightCuts.DxyCut");
	}
	Muon::IDFilter::~IDFilter() {}

	bool Muon::IDFilter::Apply( Event::Lepton* ob) {
		Int_t idx = ob->GetIndex();
		//if (ob->Pt() > 20.) {
		if (verbose_ || mEv->EventNumber() == 63248336) std::cout<<"[Muon::IDFilter]:"
			<<" pt="<<ob->Pt()<<", eta="<<ob->Eta()
			<<" combIso="<<ob->GetCombIsolation()
			<<" combIso(manual)="<<(ob->GetTrkIsolation() + ob->GetEcalIsolation() + ob->GetHcalIsolation())/ob->Pt()
			<<" isTracker="<<mEv->muonIsTrackerMuon()->at(idx)<<", isGlobal="<<mEv->muonIsGlobalMuon()->at(idx)
			<<" Chi2(norm)="<<mEv->muonGlobalTrackNormChi2()->at(idx)
			<<", GlobalValHits="<<mEv->muonGlobalTracknumberOfValidHits()->at(idx)<<" TrackerValHits="<<mEv->muonInnerTracknumberOfValidHits()->at(idx)
			<<", Dxy="<<mEv->muonGlobalTrackdxy()->at(idx);
		//}

		

		if (//is it tight?
				((tight_.requireTrackerMuon && mEv->muonIsTrackerMuon()->at(idx)) || (!(tight_.requireTrackerMuon))) &&
				((tight_.requireGlobalMuon  && mEv->muonIsGlobalMuon()->at(idx))  || (!(tight_.requireGlobalMuon)) ) &&
				(mEv->muonGlobalTrackNormChi2()->at(idx) < tight_.chiSquaredCut) &&
				(mEv->muonGlobalTracknumberOfValidHits()->at(idx) >= UInt_t(tight_.numGlobalHits)) &&
				(mEv->muonInnerTracknumberOfValidHits()->at(idx) > UInt_t(tight_.numTrackerHits))  &&
				(fabs(mEv->muonGlobalTrackdxy()->at(idx)) < tight_.dxyCut)
			 )
		{
			if(verbose_ || mEv->EventNumber() == 63248336) std::cout<<" Tight muon found!";
			ob->SetLooseId(true);
			ob->SetTightId(true);
		} else if ( //is it loose?
				((loose_.requireTrackerMuon && mEv->muonIsTrackerMuon()->at(idx)) || (!(loose_.requireTrackerMuon))) &&
				((loose_.requireGlobalMuon  && mEv->muonIsGlobalMuon()->at(idx))  || (!(loose_.requireGlobalMuon)) ) &&
				(mEv->muonGlobalTrackNormChi2()->at(idx) < loose_.chiSquaredCut) &&
				(mEv->muonGlobalTracknumberOfValidHits()->at(idx) >= UInt_t(loose_.numGlobalHits))  &&
				(mEv->muonInnerTracknumberOfValidHits()->at(idx)  >  UInt_t(loose_.numTrackerHits)) &&
				(fabs(mEv->muonGlobalTrackdxy()->at(idx)) < loose_.dxyCut)
			 )
		{
			if(verbose_ || mEv->EventNumber() == 63248336) std::cout<<" Loose muon found!";
			ob->SetLooseId(true);
			ob->SetTightId(false);
		}
		else { //not loose or tight
      ob->SetLooseId(false);
			ob->SetTightId(false);
		}//end of loose/tight ID checks.
		if (verbose_ || mEv->EventNumber() == 63248336) std::cout<<std::endl;
		return true;
	}

	std::ostream & Muon::IDFilter::Description(std::ostream & ostrm) {
	  ostrm << "[Muon::IDFilter]: ";
	  return ostrm;
	}

	//________________________________________________________________
	//
	// Electron::IDFilter
	//
	Electron::IDFilter::IDFilter( const Utils::ParameterSet& ps ) {
		mModifies = true;
		verbose_ = ps.Get<bool>("Verbose");
		useCmbIso_ = ps.Get<bool>("UseCombinedIsolation");
		//
		//isolation
		loose_.trkIso.b        = ps.Get<double>("LooseCuts.TrkIso.B");
		loose_.trkIso.e        = ps.Get<double>("LooseCuts.TrkIso.E");
		loose_.eclIso.b        = ps.Get<double>("LooseCuts.EclIso.B");
		loose_.eclIso.e        = ps.Get<double>("LooseCuts.EclIso.E");
		loose_.hclIso.b        = ps.Get<double>("LooseCuts.HclIso.B");
		loose_.hclIso.e        = ps.Get<double>("LooseCuts.HclIso.E");
		loose_.cmbIso.b        = ps.Get<double>("LooseCuts.CmbIso.B");
		loose_.cmbIso.e        = ps.Get<double>("LooseCuts.CmbIso.E");
		//
		tight_.trkIso.b        = ps.Get<double>("TightCuts.TrkIso.B");
		tight_.trkIso.e        = ps.Get<double>("TightCuts.TrkIso.E");
		tight_.eclIso.b        = ps.Get<double>("TightCuts.EclIso.B");
		tight_.eclIso.e        = ps.Get<double>("TightCuts.EclIso.E");
		tight_.hclIso.b        = ps.Get<double>("TightCuts.HclIso.B");
		tight_.hclIso.e        = ps.Get<double>("TightCuts.HclIso.E");
		tight_.cmbIso.b        = ps.Get<double>("TightCuts.CmbIso.B");
		tight_.cmbIso.e        = ps.Get<double>("TightCuts.CmbIso.E");
		//
		//conversion rejection
		loose_.convNumHits.b   = ps.Get<int>("LooseCuts.ConversionNumHits.B");
		loose_.convNumHits.e   = ps.Get<int>("LooseCuts.ConversionNumHits.E");
		loose_.convDcot.b      = ps.Get<double>("LooseCuts.ConversionDcot.B");
		loose_.convDcot.e      = ps.Get<double>("LooseCuts.ConversionDcot.E");
		loose_.convDist.b      = ps.Get<double>("LooseCuts.ConversionDist.B");
		loose_.convDist.e      = ps.Get<double>("LooseCuts.ConversionDist.E");
		//
		tight_.convNumHits.b   = ps.Get<int>("TightCuts.ConversionNumHits.B");
		tight_.convNumHits.e   = ps.Get<int>("TightCuts.ConversionNumHits.E");
		tight_.convDcot.b      = ps.Get<double>("TightCuts.ConversionDcot.B");
		tight_.convDcot.e      = ps.Get<double>("TightCuts.ConversionDcot.E");
		tight_.convDist.b      = ps.Get<double>("TightCuts.ConversionDist.B");
		tight_.convDist.e      = ps.Get<double>("TightCuts.ConversionDist.E");
		//
		//id
	  loose_.sigmaIEtaIEta.b = ps.Get<double>("LooseCuts.SigmaIEtaIEtaCut.B");
		loose_.sigmaIEtaIEta.e = ps.Get<double>("LooseCuts.SigmaIEtaIEtaCut.E");
		loose_.deltaPhiAtVtx.b = ps.Get<double>("LooseCuts.DeltaPhiAtVertexCut.B");
		loose_.deltaPhiAtVtx.e = ps.Get<double>("LooseCuts.DeltaPhiAtVertexCut.E");
		loose_.deltaEtaAtVtx.b = ps.Get<double>("LooseCuts.DeltaEtaAtVertexCut.B");
		loose_.deltaEtaAtVtx.e = ps.Get<double>("LooseCuts.DeltaEtaAtVertexCut.E");
		loose_.hcalOverEcal.b  = ps.Get<double>("LooseCuts.HcalOverEcalCut.B");
		loose_.hcalOverEcal.e  = ps.Get<double>("LooseCuts.HcalOverEcalCut.E");
		//
	  tight_.sigmaIEtaIEta.b = ps.Get<double>("TightCuts.SigmaIEtaIEtaCut.B");
		tight_.sigmaIEtaIEta.e = ps.Get<double>("TightCuts.SigmaIEtaIEtaCut.E");
		tight_.deltaPhiAtVtx.b = ps.Get<double>("TightCuts.DeltaPhiAtVertexCut.B");
		tight_.deltaPhiAtVtx.e = ps.Get<double>("TightCuts.DeltaPhiAtVertexCut.E");
		tight_.deltaEtaAtVtx.b = ps.Get<double>("TightCuts.DeltaEtaAtVertexCut.B");
		tight_.deltaEtaAtVtx.e = ps.Get<double>("TightCuts.DeltaEtaAtVertexCut.E");
		tight_.hcalOverEcal.b  = ps.Get<double>("TightCuts.HcalOverEcalCut.B");
		tight_.hcalOverEcal.e  = ps.Get<double>("TightCuts.HcalOverEcalCut.E");
	}
	Electron::IDFilter::~IDFilter() {}

	bool Electron::IDFilter::Apply( Event::Lepton* ob) {
		Int_t idx = ob->GetIndex();
		//
		if (verbose_) 
			std::cout<<"[Electron::IDFilter]: "
		 <<" pt="<<ob->Pt()<<" eta="<<ob->Eta()<<" "
		 <<" trkIso="<<ob->GetTrkIsolation()<<" eclIso="<<ob->GetEcalIsolation()<<" hclIso="<<ob->GetHcalIsolation()
		 <<" cmbIso="<<ob->GetCombIsolation()
		 <<" DCot="<<mEv->GetElectronDCot(idx)<<" Dist="<<mEv->GetElectronDist(idx)
		 <<" sigmaIEIE="<<mEv->GetElectronSigmaIetaIeta(idx)
		 <<" DphiIn="<<mEv->GetElectronDeltaPhiAtVtx(idx)<<" DEtaIn="<<mEv->GetElectronDeltaEtaAtVtx(idx)
		 <<" HoverE="<<mEv->GetElectronHoE(idx);
		
	
		//barrel/endcap transition electrons or outside tracker acceptance - not loose or tight
		if ((fabs(ob->Eta())>2.5) || ((1.4442 < fabs(ob->Eta()))&&(fabs(ob->Eta())<1.566))) {
			ob->SetLooseId(false);
			ob->SetTightId(false);
			if(verbose_) std::cout<<" electron in transition region or out of range! "<<std::endl;
			return true;
		}
		//leaves only barrel or endcap electrons
		bool isB = (fabs(ob->Eta()) < 1.4442);
		double Et = ob->Et();

		//
		//
		if (//tight ID check - brace yourself...
				//isolation
				( useCmbIso_ ? 
				  ( isB ? (ob->GetCombIsolation()  < tight_.cmbIso.b) : (ob->GetCombIsolation()    < tight_.cmbIso.e) )
					:
			   (
				  ( isB ? (ob->GetTrkIsolation()/Et  < tight_.trkIso.b) : (ob->GetTrkIsolation()/Et  < tight_.trkIso.e) ) &&
			    ( isB ? (ob->GetEcalIsolation()/Et < tight_.eclIso.b) : (ob->GetEcalIsolation()/Et < tight_.eclIso.e) ) &&
			    ( isB ? (ob->GetHcalIsolation()/Et < tight_.hclIso.b) : (ob->GetHcalIsolation()/Et < tight_.hclIso.e) )
				 )
			  ) &&
				//conversion rejection
			 //( isB ? () : () ) && //for number of missing hits, when implemented...
			 ( isB ? (fabs(mEv->GetElectronDCot(idx)) > tight_.convDcot.b) : (fabs(mEv->GetElectronDCot(idx)) > tight_.convDcot.e) ) &&
			 ( isB ? (fabs(mEv->GetElectronDist(idx)) > tight_.convDist.b) : (fabs(mEv->GetElectronDist(idx)) > tight_.convDist.e) ) &&
				//id variables
			 ( isB ? (mEv->GetElectronSigmaIetaIeta(idx) < tight_.sigmaIEtaIEta.b) : (mEv->GetElectronSigmaIetaIeta(idx) < tight_.sigmaIEtaIEta.e) ) &&
			 ( isB ? (mEv->GetElectronDeltaPhiAtVtx(idx) < tight_.deltaPhiAtVtx.b) : (mEv->GetElectronDeltaPhiAtVtx(idx) < tight_.deltaPhiAtVtx.e) ) &&
			 ( isB ? (mEv->GetElectronDeltaEtaAtVtx(idx) < tight_.deltaEtaAtVtx.b) : (mEv->GetElectronDeltaEtaAtVtx(idx) < tight_.deltaEtaAtVtx.e) ) &&
			 ( isB ? (mEv->GetElectronHoE(idx) < tight_.hcalOverEcal.b) : (mEv->GetElectronHoE(idx) < tight_.hcalOverEcal.e) )                       
			 )
		{
		  if(verbose_)std::cout<<" Tight electron! ";
            ob->SetLooseId(true); //cuts are all cumulative for loose/tight, so we save computing power...
			ob->SetTightId(true);
		  }//end of tight ID check
		  else if //loose ID check - brace yourself...
			(
				//isolation
			 ( useCmbIso_ ? 
				 ( isB ? (ob->GetCombIsolation()  < loose_.cmbIso.b) : (ob->GetCombIsolation()    < loose_.cmbIso.e) )
				 :
				 (
			    ( isB ? (ob->GetTrkIsolation()/Et  < loose_.trkIso.b) : (ob->GetTrkIsolation()/Et  < loose_.trkIso.e) ) &&
			    ( isB ? (ob->GetEcalIsolation()/Et < loose_.eclIso.b) : (ob->GetEcalIsolation()/Et < loose_.eclIso.e) ) &&
			    ( isB ? (ob->GetHcalIsolation()/Et < loose_.hclIso.b) : (ob->GetHcalIsolation()/Et < loose_.hclIso.e) )
				 )
			 ) &&
				//conversion rejection
			 //( isB ? () : () ) && //for number of missing hits, when implemented...
			 ( isB ? (fabs(mEv->GetElectronDCot(idx)) > loose_.convDcot.b) : (fabs(mEv->GetElectronDCot(idx)) > loose_.convDcot.e) ) &&
			 ( isB ? (fabs(mEv->GetElectronDist(idx)) > loose_.convDist.b) : (fabs(mEv->GetElectronDist(idx)) > loose_.convDist.e) ) &&
				//id variables
			 ( isB ? (mEv->GetElectronSigmaIetaIeta(idx) < loose_.sigmaIEtaIEta.b) : (mEv->GetElectronSigmaIetaIeta(idx) < loose_.sigmaIEtaIEta.e) ) &&
			 ( isB ? (mEv->GetElectronDeltaPhiAtVtx(idx) < loose_.deltaPhiAtVtx.b) : (mEv->GetElectronDeltaPhiAtVtx(idx) < loose_.deltaPhiAtVtx.e) ) &&
			 ( isB ? (mEv->GetElectronDeltaEtaAtVtx(idx) < loose_.deltaEtaAtVtx.b) : (mEv->GetElectronDeltaEtaAtVtx(idx) < loose_.deltaEtaAtVtx.e) ) &&
			 ( isB ? (mEv->GetElectronHoE(idx)           < loose_.hcalOverEcal.b)  : (mEv->GetElectronHoE(idx)           < loose_.hcalOverEcal.e)  )
			)
		{
			if(verbose_)std::cout<<" Loose electron! ";
      ob->SetLooseId(true);
			ob->SetTightId(false);
		}//end of loose ID check
		else {
      ob->SetLooseId(false);
			ob->SetTightId(false);
		}

		if(verbose_ || mEv->EventNumber() == 63248336)std::cout<<std::endl;
		return true;
	}//end of IDFilter Apply method.

	std::ostream & Electron::IDFilter::Description(std::ostream & ostrm) {
	  ostrm << "[Electron::IDFilter]: ";
	  return ostrm;
	}
	
	//________________________________________________________________
	//
	// Photon::IDFilter
	//
	Photon::IDFilter::IDFilter( const Utils::ParameterSet& ps ) {
		mModifies = true;
		verbose_ = ps.Get<bool>("Verbose");
		//
		//isolation
		loose_.trkIsoC.b        = ps.Get<double>("LooseCuts.TrkIsoC.B");
		loose_.trkIsoC.e        = ps.Get<double>("LooseCuts.TrkIsoC.E");
		loose_.eclIsoC.b        = ps.Get<double>("LooseCuts.EclIsoC.B");
		loose_.eclIsoC.e        = ps.Get<double>("LooseCuts.EclIsoC.E");
		loose_.hclIsoC.b        = ps.Get<double>("LooseCuts.HclIsoC.B");
		loose_.hclIsoC.e        = ps.Get<double>("LooseCuts.HclIsoC.E");
		//
		tight_.trkIsoC.b        = ps.Get<double>("TightCuts.TrkIsoC.B");
		tight_.trkIsoC.e        = ps.Get<double>("TightCuts.TrkIsoC.E");
		tight_.eclIsoC.b        = ps.Get<double>("TightCuts.EclIsoC.B");
		tight_.eclIsoC.e        = ps.Get<double>("TightCuts.EclIsoC.E");
		tight_.hclIsoC.b        = ps.Get<double>("TightCuts.HclIsoC.B");
		tight_.hclIsoC.e        = ps.Get<double>("TightCuts.HclIsoC.E");
		//
		loose_.trkIsoB.b        = ps.Get<double>("LooseCuts.TrkIsoB.B");
		loose_.trkIsoB.e        = ps.Get<double>("LooseCuts.TrkIsoB.E");
		loose_.eclIsoB.b        = ps.Get<double>("LooseCuts.EclIsoB.B");
		loose_.eclIsoB.e        = ps.Get<double>("LooseCuts.EclIsoB.E");
		loose_.hclIsoB.b        = ps.Get<double>("LooseCuts.HclIsoB.B");
		loose_.hclIsoB.e        = ps.Get<double>("LooseCuts.HclIsoB.E");
		//
		tight_.trkIsoB.b        = ps.Get<double>("TightCuts.TrkIsoB.B");
		tight_.trkIsoB.e        = ps.Get<double>("TightCuts.TrkIsoB.E");
		tight_.eclIsoB.b        = ps.Get<double>("TightCuts.EclIsoB.B");
		tight_.eclIsoB.e        = ps.Get<double>("TightCuts.EclIsoB.E");
		tight_.hclIsoB.b        = ps.Get<double>("TightCuts.HclIsoB.B");
		tight_.hclIsoB.e        = ps.Get<double>("TightCuts.HclIsoB.E");
		//
		//
		//id
	  loose_.sigmaIEtaIEta.b = ps.Get<double>("LooseCuts.SigmaIEtaIEtaCut.B");
		loose_.sigmaIEtaIEta.e = ps.Get<double>("LooseCuts.SigmaIEtaIEtaCut.E");
		loose_.hcalOverEcal.b  = ps.Get<double>("LooseCuts.HcalOverEcalCut.B");
		loose_.hcalOverEcal.e  = ps.Get<double>("LooseCuts.HcalOverEcalCut.E");
		loose_.requireNoPixelSeed = ps.Get<bool>("LooseCuts.RequireNoPixelSeed");
		//
	  tight_.sigmaIEtaIEta.b = ps.Get<double>("TightCuts.SigmaIEtaIEtaCut.B");
		tight_.sigmaIEtaIEta.e = ps.Get<double>("TightCuts.SigmaIEtaIEtaCut.E");
		tight_.hcalOverEcal.b  = ps.Get<double>("TightCuts.HcalOverEcalCut.B");
		tight_.hcalOverEcal.e  = ps.Get<double>("TightCuts.HcalOverEcalCut.E");
		tight_.requireNoPixelSeed = ps.Get<bool>("TightCuts.RequireNoPixelSeed");
	}
	Photon::IDFilter::~IDFilter() {}

	bool Photon::IDFilter::Apply( Event::Photon* ob) {
		Int_t idx = ob->GetIndex();
		//
		if (verbose_) std::cout<<"[Photon::IDFilter]: eta="<<ob->Eta()<<" ";
		//leaves only barrel or endcap electrons
		bool isB = (fabs(ob->Eta()) < 1.4442);
		//
		if (//tight ID check - brace yourself...
				//isolation
			 ( isB ? (mEv->photonTrkSumPtHollowConeDR04()->at(idx)  < (tight_.trkIsoC.b + ((tight_.trkIsoB.b)*(ob->Et())))) :
				       (mEv->photonTrkSumPtHollowConeDR04()->at(idx)  < (tight_.trkIsoC.e + ((tight_.trkIsoB.e)*(ob->Et())))) ) &&
			 ( isB ? (mEv->photonEcalRecHitSumEtConeDR04()->at(idx) < (tight_.eclIsoC.b + ((tight_.eclIsoB.b)*(ob->Et())))) : 
				       (mEv->photonEcalRecHitSumEtConeDR04()->at(idx) < (tight_.eclIsoC.e + ((tight_.eclIsoB.e)*(ob->Et())))) ) &&
			 ( isB ? (mEv->photonHcalDepth1TowSumEtConeDR04()->at(idx) < (tight_.hclIsoC.b + ((tight_.hclIsoB.b)*(ob->Et())))) : 
				       (mEv->photonHcalDepth1TowSumEtConeDR04()->at(idx) < (tight_.hclIsoC.e + ((tight_.hclIsoB.e)*(ob->Et())))) ) &&
				//id variables
			 ( isB ? (mEv->photonSigmaIetaIeta()->at(idx)  < tight_.sigmaIEtaIEta.b) : (mEv->photonSigmaIetaIeta()->at(idx)  < tight_.sigmaIEtaIEta.e) ) &&
			 ( isB ? (mEv->photonHadronicOverEm()->at(idx) < tight_.hcalOverEcal.b)  : (mEv->photonHadronicOverEm()->at(idx) < tight_.hcalOverEcal.e) ) &&
			 ( (tight_.requireNoPixelSeed && !(mEv->photonHasPixelSeed()->at(idx))) || !(tight_.requireNoPixelSeed) ) //pixel seed requirement added
			 )
		{
		  UInt_t pixel;
		 
		  
		    if(verbose_){
		    std::cout <<" Tight Photon! " << endl;
		    std::cout <<" pt="<<ob->Pt()<<" eta="<<ob->Eta()<<" "
		 <<" trkIso="<<mEv->photonTrkSumPtHollowConeDR04()->at(idx)<<" eclIso="<<mEv->photonEcalRecHitSumEtConeDR04()->at(idx)
		 <<" hclIso="<<mEv->photonHcalDepth1TowSumEtConeDR04()->at(idx)
		 <<" H/E"<<mEv->photonHadronicOverEm()->at(idx) 
		 <<" sigmaIEIE="<<mEv->photonSigmaIetaIeta()->at(idx)<<endl;

		    std::cout<<" Tight Photon! ";

		      }
      ob->SetLooseId(true); //cuts are all cumulative for loose/tight, so we save computing power...
			ob->SetTightId(true);
		}//end of tight ID check
		else if //loose ID check - brace yourself...
			(
				//isolation
			 ( isB ? (mEv->photonTrkSumPtHollowConeDR04()->at(idx)  < (loose_.trkIsoC.b + ((loose_.trkIsoB.b)*(ob->Et())))) :
				       (mEv->photonTrkSumPtHollowConeDR04()->at(idx)  < (loose_.trkIsoC.e + ((loose_.trkIsoB.e)*(ob->Et())))) ) &&
			 ( isB ? (mEv->photonEcalRecHitSumEtConeDR04()->at(idx) < (loose_.eclIsoC.b + ((loose_.eclIsoB.b)*(ob->Et())))) : 
				       (mEv->photonEcalRecHitSumEtConeDR04()->at(idx) < (loose_.eclIsoC.e + ((loose_.eclIsoB.e)*(ob->Et())))) ) &&
			 ( isB ? (mEv->photonHcalDepth1TowSumEtConeDR04()->at(idx) < (loose_.hclIsoC.b + ((loose_.hclIsoB.b)*(ob->Et())))) : 
				       (mEv->photonHcalDepth1TowSumEtConeDR04()->at(idx) < (loose_.hclIsoC.e + ((loose_.hclIsoB.e)*(ob->Et())))) ) &&
				//id variables
			 ( isB ? (mEv->photonSigmaIetaIeta()->at(idx)  < loose_.sigmaIEtaIEta.b) : (mEv->photonSigmaIetaIeta()->at(idx)  < loose_.sigmaIEtaIEta.e) ) &&
			 ( isB ? (mEv->photonHadronicOverEm()->at(idx) < loose_.hcalOverEcal.b)  : (mEv->photonHadronicOverEm()->at(idx) < loose_.hcalOverEcal.e) ) &&
			 ( (loose_.requireNoPixelSeed && !(mEv->photonHasPixelSeed()->at(idx))) || !(loose_.requireNoPixelSeed) ) //pixel seed requirement added
			)
		{
			if(verbose_ || mEv->EventNumber() == 63248336)std::cout<<" Loose Photon! ";
      ob->SetLooseId(true);
			ob->SetTightId(false);
		}//end of loose ID check
		else {
      ob->SetLooseId(false);
			ob->SetTightId(false);
		}

		if(verbose_) std::cout<<std::endl;
		return true;
	}//end of IDFilter Apply method.

	std::ostream & Photon::IDFilter::Description(std::ostream & ostrm) {
	  ostrm << "[Photon::IDFilter]: ";
	  return ostrm;
	}
}//end of namespace Hadronic
