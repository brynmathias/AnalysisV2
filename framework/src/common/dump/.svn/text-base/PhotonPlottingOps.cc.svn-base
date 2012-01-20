/*! \file PhoPlottingOps.cc
 * \brief Source code for the photonic analysis plotting operations.
 */
#include "PhotonPlottingOps.hh"
#include <sstream>
#include "TROOT.h"
#include "Photon.hh"
#include "GenObject.hh"

namespace Operation {

  //===========================================
  // Common photon analysis plotting operation 
  //===========================================
  void  PlotComPhotons::BookHistos()
  {
    BookHistArray(hg_multi_, "Multiplicity", ";Number of photons;Events / 100 pb^{-1}",num_photons_+1,-0.5,num_photons_+0.5,1,0,1,true);
    BookHistArray(hg_E_, "Et",  ";E / GeV;Photons per event / 100 pb^{-1}",600,-1000.,2000.,num_photons_+1,0,1,true);
    BookHistArray(hg_Et_, "E",  ";E_{T} / GeV;Photon per event / 100 pb^{-1}",600,-1000.,2000.,num_photons_+1,0,1,true);
    BookHistArray(hg_Pt_, "Pt",  ";p_{T} / GeV;Photons per event / 100 pb^{-1}",600,-1000.,2000.,num_photons_+1,0,1,true);
    BookHistArray(hg_eta_, "eta",  ";#eta;Photons per event / 100 pb^{-1}",120,-6.,6.,num_photons_+1,0,1,true);
    BookHistArray(hg_m_, "m",  ";m / GeV;Photons per event / 100 pb^{-1}",60,-10.,20.,num_photons_+1,0,1,true);        
    BookHistArray(hg_trkiso_, "trkiso",  ";Track Isolation / GeV;Photons per event / 100 pb^{-1}",60,0.,15.,num_photons_+1,0,1,true);
    BookHistArray(hg_ecaliso_, "ecaliso",  ";ECAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,num_photons_+1,0,1,true);
    BookHistArray(hg_hcaliso_, "hcaliso",  ";HCAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,num_photons_+1,0,1,true);
    BookHistArray(hg_alliso_, "alliso",  ";All Isolation / GeV;Photons per event / 100 pb^{-1}",100,0.,50.,num_photons_+1,0,1,true);
    BookHistArray(hg_id_, "ID",  ";ID;Photons per event / 100 pb^{-1}",4,-0.5,3.5,num_photons_+1,0,1,true);
    BookHistArray(hg_cc_, "CC",  ";Cross cleaned?;Photons per event / 100 pb^{-1}",2,-0.5,1.5,num_photons_+1,0,1,true);
    
    BookHistArray(hg_matched_, "matched", ";Matched or not;Photons per event / 100 pb^{-1}", 2, -0.5, 1.5, 1, 0, 1, true);
    
    BookHistArray(hg_matched_multi_, "matched_Multiplicity", ";Number of photons;Events / 100 pb^{-1}",num_photons_+1,-0.5,num_photons_+0.5,1,0,1,true);
    BookHistArray(hg_matched_E_, "matched_Et",  ";E / GeV;Photons per event / 100 pb^{-1}",600,-1000.,2000.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_Et_, "matched_E",  ";E_{T} / GeV;Photon per event / 100 pb^{-1}",600,-1000.,2000.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_Pt_, "matched_Pt",  ";p_{T} / GeV;Photons per event / 100 pb^{-1}",600,-1000.,2000.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_eta_, "matched_eta",  ";#eta;Photons per event / 100 pb^{-1}",120,-6.,6.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_m_, "matched_m",  ";m / GeV;Photons per event / 100 pb^{-1}",60,-10.,20.,num_photons_+1,0,1,true);        
    BookHistArray(hg_matched_trkiso_, "matched_trkiso",  ";Track Isolation / GeV;Photons per event / 100 pb^{-1}",60,0.,15.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_ecaliso_, "matched_ecaliso",  ";ECAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_hcaliso_, "matched_hcaliso",  ";HCAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_alliso_, "matched_alliso",  ";All Isolation / GeV;Photons per event / 100 pb^{-1}",100,0.,50.,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_id_, "matched_ID",  ";ID;Photons per event / 100 pb^{-1}",4,-0.5,3.5,num_photons_+1,0,1,true);
    BookHistArray(hg_matched_cc_, "matched_CC",  ";Cross cleaned?;Photons per event / 100 pb^{-1}",2,-0.5,1.5,num_photons_+1,0,1,true);
    
  } // end of BookHistos method
  
  
  bool PlotComPhotons::Process(Event::Data & ev) {
    // Fill your histograms...
    
    // Fill multiplicity histogram
    hg_multi_[0]->Fill( ev.PD_CommonPhotons().accepted.size(),
			ev.GetEventWeight() );
    
    UInt_t count = 0;
    UInt_t matchedcount = 0;
    // Loop through the common photons 
    for (std::vector<Event::Photon const *>::const_iterator cp = ev.PD_CommonPhotons().accepted.begin();
	 cp!= ev.PD_CommonPhotons().accepted.end();
	 ++cp) {

      count++;
      // Fill "all" (i.e. "0") histogram(s) first
      hg_E_[0]->Fill( (**cp).E(), ev.GetEventWeight() );
      hg_Et_[0]->Fill( (**cp).Et(), ev.GetEventWeight() );
      hg_Pt_[0]->Fill( (**cp).Pt(), ev.GetEventWeight() );
      hg_eta_[0]->Fill( (**cp).Eta(), ev.GetEventWeight() );
      hg_m_[0]->Fill( (**cp).M(), ev.GetEventWeight() );
      hg_trkiso_[0]->Fill( (**cp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_ecaliso_[0]->Fill( (**cp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_hcaliso_[0]->Fill( (**cp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_alliso_[0]->Fill( (**cp).GetAllIsolation(), ev.GetEventWeight() );
      hg_id_[0]->Fill( (**cp).GetIntID(), ev.GetEventWeight() );
      hg_cc_[0]->Fill( (**cp).WasItcc(), ev.GetEventWeight() );
      
      hg_matched_[0]->Fill( (**cp).WasItMatched(), ev.GetEventWeight() );
      
      // Check needed so we don't seg fault... ;-)
      if (count <= num_photons_) {
	hg_E_[count]->Fill( (**cp).E(), ev.GetEventWeight() );
	hg_Et_[count]->Fill( (**cp).Et(), ev.GetEventWeight() );
	hg_Pt_[count]->Fill( (**cp).Pt(), ev.GetEventWeight() );
	hg_eta_[count]->Fill( (**cp).Eta(), ev.GetEventWeight() );
	hg_m_[count]->Fill( (**cp).M(), ev.GetEventWeight() );
            
	hg_trkiso_[count]->Fill( (**cp).GetTrackIsolation(), ev.GetEventWeight() );
	hg_ecaliso_[count]->Fill( (**cp).GetEcalIsolation(), ev.GetEventWeight() );
	hg_hcaliso_[count]->Fill( (**cp).GetHcalIsolation(), ev.GetEventWeight() );
	hg_alliso_[count]->Fill( (**cp).GetAllIsolation(), ev.GetEventWeight() );
        
	hg_id_[count]->Fill( (**cp).GetIntID(), ev.GetEventWeight() );
	hg_cc_[count]->Fill( (**cp).WasItcc(), ev.GetEventWeight() );
      } // end of number of photons check
      
      if ( (**cp).WasItMatched() ) {
	matchedcount++;
	// Fill "all" (i.e. "0") histogram(s) first
	hg_matched_E_[0]->Fill( (**cp).E(), ev.GetEventWeight() );
	hg_matched_Et_[0]->Fill( (**cp).Et(), ev.GetEventWeight() );
	hg_matched_Pt_[0]->Fill( (**cp).Pt(), ev.GetEventWeight() );
	hg_matched_eta_[0]->Fill( (**cp).Eta(), ev.GetEventWeight() );
	hg_matched_m_[0]->Fill( (**cp).M(), ev.GetEventWeight() );
	hg_matched_trkiso_[0]->Fill( (**cp).GetTrackIsolation(), ev.GetEventWeight() );
	hg_matched_ecaliso_[0]->Fill( (**cp).GetEcalIsolation(), ev.GetEventWeight() );
	hg_matched_hcaliso_[0]->Fill( (**cp).GetHcalIsolation(), ev.GetEventWeight() );
	hg_matched_alliso_[0]->Fill( (**cp).GetAllIsolation(), ev.GetEventWeight() );
	hg_matched_id_[0]->Fill( (**cp).GetIntID(), ev.GetEventWeight() );
	hg_matched_cc_[0]->Fill( (**cp).WasItcc(), ev.GetEventWeight() );
        
	// Check needed so we don't seg fault... ;-)
	if (matchedcount <= num_photons_) {
	  hg_matched_E_[matchedcount]->Fill( (**cp).E(), ev.GetEventWeight() );
	  hg_matched_Et_[matchedcount]->Fill( (**cp).Et(), ev.GetEventWeight() );
	  hg_matched_Pt_[matchedcount]->Fill( (**cp).Pt(), ev.GetEventWeight() );
	  hg_matched_eta_[matchedcount]->Fill( (**cp).Eta(), ev.GetEventWeight() );
	  hg_matched_m_[matchedcount]->Fill( (**cp).M(), ev.GetEventWeight() );
          
	  hg_matched_trkiso_[matchedcount]->Fill( (**cp).GetTrackIsolation(), ev.GetEventWeight() );
	  hg_matched_ecaliso_[matchedcount]->Fill( (**cp).GetEcalIsolation(), ev.GetEventWeight() );
	  hg_matched_hcaliso_[matchedcount]->Fill( (**cp).GetHcalIsolation(), ev.GetEventWeight() );
	  hg_matched_alliso_[matchedcount]->Fill( (**cp).GetAllIsolation(), ev.GetEventWeight() );
          
	  hg_matched_id_[matchedcount]->Fill( (**cp).GetIntID(), ev.GetEventWeight() );
	  hg_matched_cc_[matchedcount]->Fill( (**cp).WasItcc(), ev.GetEventWeight() );
	} // end of number of photons check
      } // end of gen photon matched check
      
    } // end of loop over common photons
    
    // Fill the matched multiplicity histogram (need to count these manually)
    hg_matched_multi_[0]->Fill(matchedcount, ev.GetEventWeight() );
    
    return true; // Plotting operations always pass.
  }
  
  std::ostream& PlotComPhotons::Description(std::ostream &ostrm) {
    ostrm << "Common photon properties plots "
	  << "for first " << num_photons_ << " photons "
	  << "(folder " << foldername_ << ")";
    // Add any further documentation, param names etc. here.
    return ostrm;
  }
  //==================================================================
  
  //===========================================
  // Signal photon analysis plotting operation 
  //===========================================
  void PlotSigPhotons::BookHistos() {
    
    // Book the histograms - see Plotting.hh for BookHistArray documentation.
    //
    // Signal photons
    BookHistArray(hg_gen_multi_, "Gen_signal_Multiplicity", ";Number of photons;Events / 100 pb^{-1}",3,-0.5,2.5,1,0,1,true);
    BookHistArray(hg_gen_E_, "Gen_signal_Et",  ";E / GeV;Photons per event / 100 pb^{-1}",100,0.,2000.,3,0,1,true);
    BookHistArray(hg_gen_Et_, "Gen_signal_E",  ";E_{T} / GeV;Photon per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_gen_Pt_, "Gen_signal_Pt",  ";p_{T} / GeV;Photons per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_gen_eta_, "Gen_signal_eta",  ";#eta;Photons per event / 100 pb^{-1}",80,-4.,4.,3,0,1,true);
    BookHistArray(hg_gen_m_, "Gen_signal_m",  ";m / GeV;Photons per event / 100 pb^{-1}",60,-10.,20.,3,0,1,true);
    //
    // Preconfigured photons that are matched to signal photons
    BookHistArray(hg_mat_multi_, "Preconf_matched_signal_Multiplicity", ";Number of photons;Events / 100 pb^{-1}",3,-0.5,2.5,1,0,1,true);
    BookHistArray(hg_mat_E_, "Matched_Et",  ";E / GeV;Photons per event / 100 pb^{-1}",100,0.,2000.,3,0,1,true);
    BookHistArray(hg_mat_Et_, "Matched_E",  ";E_{T} / GeV;Photon per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_mat_Pt_, "Matched_Pt",  ";p_{T} / GeV;Photons per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_mat_eta_, "Matched_eta",  ";#eta;Photons per event / 100 pb^{-1}",80,-4.,4.,3,0,1,true);
    BookHistArray(hg_mat_m_, "Matched_m",  ";m / GeV;Photons per event / 100 pb^{-1}",60,-10.,20.,3,0,1,true);
    
    BookHistArray(hg_mat_trkiso_, "Matched_trkiso",  ";Track Isolation / GeV;Photons per event / 100 pb^{-1}",60,0.,15.,3,0,1,true);
    BookHistArray(hg_mat_ecaliso_, "Matched_ecaliso",  ";ECAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,3,0,1,true);
    BookHistArray(hg_mat_hcaliso_, "Matched_hcaliso",  ";HCAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,3,0,1,true);
    BookHistArray(hg_mat_alliso_, "Matched_alliso",  ";All Isolation / GeV;Photons per event / 100 pb^{-1}",100,0.,50.,3,0,1,true);
    
    BookHistArray(hg_mat_id_, "Matched_ID",  ";ID;Photons per event / 100 pb^{-1}",4,-0.5,3.5,3,0,1,true);
    BookHistArray(hg_mat_cc_, "Matched_CC",  ";Cross cleaned?;Photons per event / 100 pb^{-1}",2,-0.5,1.5,3,0,1,true);
    //
    // Common photons that are matched to signal photons
    BookHistArray(hg_commat_multi_, "Common_matched_signal_Multiplicity", ";Number of photons;Events / 100 pb^{-1}",3,-0.5,2.5,1,0,1,true);
    BookHistArray(hg_commat_E_, "ComMatched_Et",  ";E / GeV;Photons per event / 100 pb^{-1}",100,0.,2000.,3,0,1,true);
    BookHistArray(hg_commat_Et_, "ComMatched_E",  ";E_{T} / GeV;Photon per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_commat_Pt_, "ComMatched_Pt",  ";p_{T} / GeV;Photons per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_commat_eta_, "ComMatched_eta",  ";#eta;Photons per event / 100 pb^{-1}",80,-4.,4.,3,0,1,true);
    BookHistArray(hg_commat_m_, "ComMatched_m",  ";m / GeV;Photons per event / 100 pb^{-1}",60,-10.,20.,3,0,1,true);
    
    BookHistArray(hg_commat_trkiso_, "ComMatched_trkiso",  ";Track Isolation / GeV;Photons per event / 100 pb^{-1}",60,0.,15.,3,0,1,true);
    BookHistArray(hg_commat_ecaliso_, "ComMatched_ecaliso",  ";ECAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,3,0,1,true);
    BookHistArray(hg_commat_hcaliso_, "ComMatched_hcaliso",  ";HCAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,3,0,1,true);
    BookHistArray(hg_commat_alliso_, "ComMatched_alliso",  ";All Isolation / GeV;Photons per event / 100 pb^{-1}",100,0.,50.,3,0,1,true);
    
    BookHistArray(hg_commat_id_, "ComMatched_ID",  ";ID;Photons per event / 100 pb^{-1}",4,-0.5,3.5,3,0,1,true);
    BookHistArray(hg_commat_cc_, "ComMatched_CC",  ";Cross cleaned?;Photons per event / 100 pb^{-1}",2,-0.5,1.5,3,0,1,true);
    //
    // Good photons that are matched to signal photons
    BookHistArray(hg_gdmat_multi_, "Good_matched_signal_Multiplicity", ";Number of photons;Events / 100 pb^{-1}",3,-0.5,2.5,1,0,1,true);
    BookHistArray(hg_gdmat_E_, "GoodMatched_Et",  ";E / GeV;Photons per event / 100 pb^{-1}",100,0.,2000.,3,0,1,true);
    BookHistArray(hg_gdmat_Et_, "GoodMatched_E",  ";E_{T} / GeV;Photon per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_gdmat_Pt_, "GoodMatched_Pt",  ";p_{T} / GeV;Photons per event / 100 pb^{-1}",75,0.,1500.,3,0,1,true);
    BookHistArray(hg_gdmat_eta_, "GoodMatched_eta",  ";#eta;Photons per event / 100 pb^{-1}",80,-4.,4.,3,0,1,true);
    BookHistArray(hg_gdmat_m_, "GoodMatched_m",  ";m / GeV;Photons per event / 100 pb^{-1}",60,-10.,20.,3,0,1,true);
    
    BookHistArray(hg_gdmat_trkiso_, "GoodMatched_trkiso",  ";Track Isolation / GeV;Photons per event / 100 pb^{-1}",60,0.,15.,3,0,1,true);
    BookHistArray(hg_gdmat_ecaliso_, "GoodMatched_ecaliso",  ";ECAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,3,0,1,true);
    BookHistArray(hg_gdmat_hcaliso_, "GoodMatched_hcaliso",  ";HCAL Isolation / GeV;Photons per event / 100 pb^{-1}",80,0.,20.,3,0,1,true);
    BookHistArray(hg_gdmat_alliso_, "GoodMatched_alliso",  ";All Isolation / GeV;Photons per event / 100 pb^{-1}",100,0.,50.,3,0,1,true);
    
    BookHistArray(hg_gdmat_id_, "GoodMatched_ID",  ";ID;Photons per event / 100 pb^{-1}",4,-0.5,3.5,3,0,1,true);
    BookHistArray(hg_gdmat_cc_, "GoodMatched_CC",  ";Cross cleaned?;Photons per event / 100 pb^{-1}",2,-0.5,1.5,3,0,1,true);
    
  }

  bool PlotSigPhotons::Process(Event::Data & ev) {
    // Fill your histograms...
    
    UInt_t count = 0;
    // Loop over the gen signal photons
    for (std::vector<Event::GenObject const *>::const_iterator gsp = ev.PD_SignalGenPhotons().begin();
	 gsp!= ev.PD_SignalGenPhotons().end();
	 ++gsp) {

      count++;
      hg_gen_E_[0]->Fill( (**gsp).E(), ev.GetEventWeight() );
      hg_gen_E_[count]->Fill( (**gsp).E(), ev.GetEventWeight() );
      hg_gen_Et_[0]->Fill( (**gsp).Et(), ev.GetEventWeight() );
      hg_gen_Et_[count]->Fill( (**gsp).Et(), ev.GetEventWeight() );
      hg_gen_Pt_[0]->Fill( (**gsp).Pt(), ev.GetEventWeight() );
      hg_gen_Pt_[count]->Fill( (**gsp).Pt(), ev.GetEventWeight() );
      hg_gen_eta_[0]->Fill( (**gsp).Eta(), ev.GetEventWeight() );
      hg_gen_eta_[count]->Fill( (**gsp).Eta(), ev.GetEventWeight() );
      hg_gen_m_[0]->Fill( (**gsp).M(), ev.GetEventWeight() );
      hg_gen_m_[count]->Fill( (**gsp).M(), ev.GetEventWeight() );
    } // End of loop over gen signal photons
    hg_gen_multi_[0]->Fill( count, ev.GetEventWeight() ); // Fill multiplicity
    
    count = 0; // reset... d'oh!        
    // Loop through the preconfigured photons matched to signal photons
    for (std::vector<Event::Photon const *>::const_iterator pcp = ev.PD_MatchedSignalPreconfPhotons().begin();
	 pcp!= ev.PD_MatchedSignalPreconfPhotons().end(); ++pcp) {
      count++;
      hg_mat_E_[0]->Fill( (**pcp).E(), ev.GetEventWeight() );
      hg_mat_E_[count]->Fill( (**pcp).E(), ev.GetEventWeight() );
      hg_mat_Et_[0]->Fill( (**pcp).Et(), ev.GetEventWeight() );
      hg_mat_Et_[count]->Fill( (**pcp).Et(), ev.GetEventWeight() );
      hg_mat_Pt_[0]->Fill( (**pcp).Pt(), ev.GetEventWeight() );
      hg_mat_Pt_[count]->Fill( (**pcp).Pt(), ev.GetEventWeight() );
      hg_mat_eta_[0]->Fill( (**pcp).Eta(), ev.GetEventWeight() );
      hg_mat_eta_[count]->Fill( (**pcp).Eta(), ev.GetEventWeight() );
      hg_mat_m_[0]->Fill( (**pcp).M(), ev.GetEventWeight() );
      hg_mat_m_[count]->Fill( (**pcp).M(), ev.GetEventWeight() );
      
      hg_mat_trkiso_[0]->Fill( (**pcp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_mat_trkiso_[count]->Fill( (**pcp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_mat_ecaliso_[0]->Fill( (**pcp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_mat_ecaliso_[count]->Fill( (**pcp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_mat_hcaliso_[0]->Fill( (**pcp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_mat_hcaliso_[count]->Fill( (**pcp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_mat_alliso_[0]->Fill( (**pcp).GetAllIsolation(), ev.GetEventWeight() );
      hg_mat_alliso_[count]->Fill( (**pcp).GetAllIsolation(), ev.GetEventWeight() );
      
      hg_mat_id_[0]->Fill( (**pcp).GetIntID(), ev.GetEventWeight() );
      hg_mat_id_[count]->Fill( (**pcp).GetIntID(), ev.GetEventWeight() );
      hg_mat_cc_[0]->Fill( (**pcp).WasItcc(), ev.GetEventWeight() );
      hg_mat_cc_[count]->Fill( (**pcp).WasItcc(), ev.GetEventWeight() );
    } // end of loop over matched preconf photons
    hg_mat_multi_[0]->Fill( count, ev.GetEventWeight() ); // Fill multiplicity
    
    count = 0; // reset... d'oh!        
    // Loop over and plot the matched common photons
    for (std::vector<Event::Photon const *>::const_iterator pcp = ev.PD_MatchedSignalCommonPhotons().begin();
	 pcp!= ev.PD_MatchedSignalCommonPhotons().end();
	 ++pcp) {

      count++;
      hg_commat_E_[0]->Fill( (**pcp).E(), ev.GetEventWeight() );
      hg_commat_E_[count]->Fill( (**pcp).E(), ev.GetEventWeight() );
      hg_commat_Et_[0]->Fill( (**pcp).Et(), ev.GetEventWeight() );
      hg_commat_Et_[count]->Fill( (**pcp).Et(), ev.GetEventWeight() );
      hg_commat_Pt_[0]->Fill( (**pcp).Pt(), ev.GetEventWeight() );
      hg_commat_Pt_[count]->Fill( (**pcp).Pt(), ev.GetEventWeight() );
      hg_commat_eta_[0]->Fill( (**pcp).Eta(), ev.GetEventWeight() );
      hg_commat_eta_[count]->Fill( (**pcp).Eta(), ev.GetEventWeight() );
      hg_commat_m_[0]->Fill( (**pcp).M(), ev.GetEventWeight() );
      hg_commat_m_[count]->Fill( (**pcp).M(), ev.GetEventWeight() );
      
      hg_commat_trkiso_[0]->Fill( (**pcp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_commat_trkiso_[count]->Fill( (**pcp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_commat_ecaliso_[0]->Fill( (**pcp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_commat_ecaliso_[count]->Fill( (**pcp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_commat_hcaliso_[0]->Fill( (**pcp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_commat_hcaliso_[count]->Fill( (**pcp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_commat_alliso_[0]->Fill( (**pcp).GetAllIsolation(), ev.GetEventWeight() );
      hg_commat_alliso_[count]->Fill( (**pcp).GetAllIsolation(), ev.GetEventWeight() );
      
      hg_commat_id_[0]->Fill( (**pcp).GetIntID(), ev.GetEventWeight() );
      hg_commat_id_[count]->Fill( (**pcp).GetIntID(), ev.GetEventWeight() );
      hg_commat_cc_[0]->Fill( (**pcp).WasItcc(), ev.GetEventWeight() );
      hg_commat_cc_[count]->Fill( (**pcp).WasItcc(), ev.GetEventWeight() );
    } // end of loop over matched common photons
    hg_commat_multi_[0]->Fill( count, ev.GetEventWeight() ); // Fill multiplicity
    
    count = 0; // reset... d'oh!
    // Loop over and plot the matched good photons
    for (std::vector<Event::Photon const *>::const_iterator pcp = ev.PD_MatchedSignalGoodPhotons().begin();
	 pcp!= ev.PD_MatchedSignalGoodPhotons().end();
	 ++pcp) {

      count++;
      hg_gdmat_E_[0]->Fill( (**pcp).E(), ev.GetEventWeight() );
      hg_gdmat_E_[count]->Fill( (**pcp).E(), ev.GetEventWeight() );
      hg_gdmat_Et_[0]->Fill( (**pcp).Et(), ev.GetEventWeight() );
      hg_gdmat_Et_[count]->Fill( (**pcp).Et(), ev.GetEventWeight() );
      hg_gdmat_Pt_[0]->Fill( (**pcp).Pt(), ev.GetEventWeight() );
      hg_gdmat_Pt_[count]->Fill( (**pcp).Pt(), ev.GetEventWeight() );
      hg_gdmat_eta_[0]->Fill( (**pcp).Eta(), ev.GetEventWeight() );
      hg_gdmat_eta_[count]->Fill( (**pcp).Eta(), ev.GetEventWeight() );
      hg_gdmat_m_[0]->Fill( (**pcp).M(), ev.GetEventWeight() );
      hg_gdmat_m_[count]->Fill( (**pcp).M(), ev.GetEventWeight() );
      
      hg_gdmat_trkiso_[0]->Fill( (**pcp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_gdmat_trkiso_[count]->Fill( (**pcp).GetTrackIsolation(), ev.GetEventWeight() );
      hg_gdmat_ecaliso_[0]->Fill( (**pcp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_gdmat_ecaliso_[count]->Fill( (**pcp).GetEcalIsolation(), ev.GetEventWeight() );
      hg_gdmat_hcaliso_[0]->Fill( (**pcp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_gdmat_hcaliso_[count]->Fill( (**pcp).GetHcalIsolation(), ev.GetEventWeight() );
      hg_gdmat_alliso_[0]->Fill( (**pcp).GetAllIsolation(), ev.GetEventWeight() );
      hg_gdmat_alliso_[count]->Fill( (**pcp).GetAllIsolation(), ev.GetEventWeight() );
      
      hg_gdmat_id_[0]->Fill( (**pcp).GetIntID(), ev.GetEventWeight() );
      hg_gdmat_id_[count]->Fill( (**pcp).GetIntID(), ev.GetEventWeight() );
      hg_gdmat_cc_[0]->Fill( (**pcp).WasItcc(), ev.GetEventWeight() );
      hg_gdmat_cc_[count]->Fill( (**pcp).WasItcc(), ev.GetEventWeight() );
    } // end of loop over matched good photons
    hg_gdmat_multi_[0]->Fill( count, ev.GetEventWeight() ); // Fill multiplicity
    
    return true; // Plotting operations always pass.
  }
  
  std::ostream& PlotSigPhotons::Description(std::ostream &ostrm) {
    ostrm << "Signal photon properties plots "
	  << "(folder " << foldername_ << ") ";
    // Add any further documentation, param names etc. here.
    return ostrm;
  }
  //==================================================================
  
  //====================================
  // Good photon plotting operation
  //====================================
  void GoodPhoPlots::BookHistos() {
    // Book the histograms - see Plotting.hh for BookHistArray documentation.
    hg_gdpho_multi_ = new TH1D("Multiplicity",";Number of good objects;Events / 100 pb^{-1}", 11, -0.5,10.5);
    hg_gdphopho_multi_ = new TH1D("PhoMultiplicity",";Number of good photons;Events / 100 pb^{-1}", 11, -0.5,10.5);
    hg_gdphojet_multi_ = new TH1D("JetMultiplicity",";Number of good jets;Events / 100 pb^{-1}", 11, -0.5,10.5);
        
    hg_HT_ = new TH1D("HT", ";H_{T} / GeV;Events / 100 pb^{-1}",200,0.,2000.);
    hg_MHT_ = new TH1D("MHT", ";MH_{T} / GeV;Events / 100 pb^{-1}",200,0.,2000.);
    hg_MHToverHT_ = new TH1D("MHT_over_HT", ";MH_{T}/H_{T};Events / 100 pb^{-1}",200,0.,2.0);
    //BookHistArray(hg_HT_, "HT", ";H_{T} / GeV;Events / 100 pb^{-1}",200,0.,2000.,1,0,1,true);
    //BookHistArray(hg_MHT_, "MHT", ";MH_{T} / GeV;Events / 100 pb^{-1}",200,0.,2000.,1,0,1,true);
    //BookHistArray(hg_MHToverHT_, "MHT_over_HT", ";MH_{T}/H_{T};Events / 100 pb^{-1}",200,0.,1.,1,0,1,true);
    
  }
  
  bool GoodPhoPlots::Process(Event::Data & ev) {
    // Fill your histograms...
    
    // Multiplicity plots
    hg_gdphopho_multi_->Fill(ev.PD_GoodPhotons().size(), ev.GetEventWeight() );
    hg_gdphojet_multi_->Fill(ev.PD_GoodJets().size(), ev.GetEventWeight() );
    
    hg_HT_->Fill(ev.PD_GoodPhotonsHT(), ev.GetEventWeight() );
    hg_MHT_->Fill(ev.PD_GoodPhotonRecoil().Pt(), ev.GetEventWeight() );
    hg_MHToverHT_->Fill(ev.PD_GoodPhotonRecoil().Pt() / ev.PD_GoodPhotonsHT(), ev.GetEventWeight() );
    //hg_HT_[0]->Fill(ev.PD.GetGoodPhoHT(), ev.GetEventWeight() );
    //hg_MHT_[0]->Fill(ev.PD.GetGoodPhoMHT(), ev.GetEventWeight() );
    //hg_MHToverHT_[0]->Fill(ev.PD.GetGoodPhoMHT()/ev.PD.GetGoodPhoHT(), ev.GetEventWeight() );
    return true; // Plotting operations always pass.
  }
  
  std::ostream& GoodPhoPlots::Description(std::ostream &ostrm) {
    ostrm << "Plotting operation GoodPhoPlot";
    // Add any further documentation, param names etc. here.
    ostrm << "(Plots in folder " << foldername_ << "): ";
    return ostrm;
  }
  //==================================================================
  
  
  //====================================
  // Good photon kinematics plotting operation
  //====================================
  void GoodPhoKinPlots::BookHistos() {
    // Book the histograms - see Plotting.hh for BookHistArray documentation.
    hg_MT_ = new TH1D("MT", ";M_{T} / GeV;Events / 100 pb^{-1}",200,0.,2000.);
    hg_MinDHT_ = new TH1D("Min #Delta H_{T}", ";Min. #Delta H_{T} / GeV;Events / 100 pb^{-1}",200,0.,1000.);
    hg_AlphaT_ = new TH1D("#alpha_{T}", ";#alpha_{T};Events / 100 pb^{-1}",100,0.,2.0);
  }
  
  bool GoodPhoKinPlots::Process(Event::Data & ev) {
    // Fill your histograms...
    hg_MT_->Fill(ev.PD_GoodMT(), ev.GetEventWeight() );
    hg_MinDHT_->Fill(ev.PD_GoodMinDHT(), ev.GetEventWeight() );
    hg_AlphaT_->Fill(ev.PD_GoodAlphaT(), ev.GetEventWeight() );
    return true; // Plotting operations always pass.
  }
  
  std::ostream& GoodPhoKinPlots::Description(std::ostream &ostrm) {
    ostrm << "Plotting operation GoodPhoKinPlot";
    // Add any further documentation, param names etc. here.
    ostrm << "(Plots in folder " << foldername_ << "): ";
    return ostrm;
  }
  //==================================================================

} //~namespace Operation
