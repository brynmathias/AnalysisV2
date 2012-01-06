/*! \file HadPlottingOps.cc
 * \brief Source code for the hadronic analysis plotting operations.
 */
#include "HadronicPlottingOps.hh"
#include <iostream>
#include "EventData.hh"
#include "Jet.hh"

namespace Operation {

  //================================
  // Good Jet Plotting Operation
  //================================
  void GoodHadPlots::BookHistos() {} 
  
  bool GoodHadPlots::Process(Event::Data & ev) {
    // Fill the histograms
    return true; // Check for fails above, return false to fail operation.
  }
  
  std::ostream& GoodHadPlots::Description(std::ostream &ostrm) {
    ostrm << "GoodHadPlots plots made here "<<endl;;
    return ostrm;
  }
    
  //====================================
  // PAT (preconf) JET PLOTTING OPERATION
  //====================================
  void PatJetPlots::BookHistos() {
    // Book the histograms - see Plotting.hh for BookHistArray documentation.
    BookHistArray(hg_multi_, "Multiplicity", ";Number of common jets;",numjets_+1,-0.5,numjets_+0.5,1,0,1,true);
    BookHistArray(hg_E_, "E", ";E / GeV;",600,-1000.,2000.,numjets_+1,0,1,true);
    BookHistArray(hg_Et_, "Et", ";E_{T} / GeV;",600,-1000.,2000.,numjets_+1,0,1,true);
    BookHistArray(hg_Pt_, "Pt",  ";p_{T} / GeV;",600,-1000.,2000.,numjets_+1,0,1,true);
    BookHistArray(hg_eta_, "eta",  ";#eta;",120,-6.,6.,numjets_+1,0,1,true);
    BookHistArray(hg_m_, "m",  ";m / GeV;",600,-1000.,2000.,numjets_+1,0,1,true);        
    BookHistArray(hg_emfrac_, "emfrac", ";F_{EM};",75,-0.5,3.0,numjets_+1,0,1,true);        
    
    BookHistArray(hg_Et_emfrac_, "Et_vs_emfrac", ";E_{T} / GeV;F_{EM}",600,-1000.,2000.,110,0.,1.1,numjets_+1,0,1,true);
    BookHistArray(hg_eta_emfrac_, "eta_vs_emfrac", ";#eta;F_{EM}",120,-6.,6.,110,0.,1.1,numjets_+1,0,1,true);
    
    BookHistArray(hg_emfail_E_, "emfail_E", ";E / GeV;",600,-1000.,2000.,numjets_+1,0,1,true);
    BookHistArray(hg_emfail_Et_, "emfail_Et", ";E_{T} / GeV;",600,-1000.,2000.,numjets_+1,0,1,true);
  }

  bool PatJetPlots::Process(Event::Data & ev) {
    // Fill your histograms...
    
    // Fill multiplicity histogram
    hg_multi_[0]->Fill( ev.JD_Jets().size(), ev.GetEventWeight() );
    
    UInt_t count = 0;
    // Loop through the common photons 
    for (std::vector<Event::Jet>::const_iterator cj = ev.JD_Jets().begin();
	 cj!= ev.JD_Jets().end();
	 ++cj) {
      count++;
      // Fill "all" (i.e. "0") histogram(s) first
      hg_E_[0]->Fill( (*cj).E(), ev.GetEventWeight() );
      hg_Et_[0]->Fill( (*cj).Et(), ev.GetEventWeight() );
      hg_Pt_[0]->Fill( (*cj).Pt(), ev.GetEventWeight() );
      hg_eta_[0]->Fill( (*cj).Eta(), ev.GetEventWeight() );
      hg_m_[0]->Fill( (*cj).M(), ev.GetEventWeight() );
      hg_emfrac_[0]->Fill( (*cj).GetEmFrac(), ev.GetEventWeight() );
      hg_Et_emfrac_[0]->Fill( (*cj).E(), (*cj).GetEmFrac(), ev.GetEventWeight() );
      hg_eta_emfrac_[0]->Fill( (*cj).Eta(), (*cj).GetEmFrac(), ev.GetEventWeight() );
      
      // If the jet fails the EM frac cut, plot it...
      if ( cj->GetEmFrac() > ev.com_jet_emfrac_cut_ ) {
	hg_emfail_E_[0]->Fill( (*cj).E(), ev.GetEventWeight() );
	hg_emfail_Et_[0]->Fill( (*cj).Et(), ev.GetEventWeight() );
      }
      
      // Check needed so we don't seg fault... ;-)
      if (count <= numjets_) {
	hg_E_[count]->Fill( (*cj).E(), ev.GetEventWeight() );
	hg_Et_[count]->Fill( (*cj).Et(), ev.GetEventWeight() );
	hg_Pt_[count]->Fill( (*cj).Pt(), ev.GetEventWeight() );
	hg_eta_[count]->Fill( (*cj).Eta(), ev.GetEventWeight() );
	hg_m_[count]->Fill( (*cj).M(), ev.GetEventWeight() );
	hg_emfrac_[count]->Fill( (*cj).GetEmFrac(), ev.GetEventWeight() );
	hg_Et_emfrac_[count]->Fill( (*cj).E(), (*cj).GetEmFrac(), ev.GetEventWeight() );
	hg_eta_emfrac_[count]->Fill( (*cj).Eta(), (*cj).GetEmFrac(), ev.GetEventWeight() );
        
      } // end of number of jets check
      
    } // end of loop over common jets
    
    return true; // Plotting operations always pass.
  }
  
  std::ostream& PatJetPlots::Description(std::ostream &ostrm) {
    ostrm << "Pat (preconf) jet plots ";
    // Add any further documentation, param names etc. here.
    ostrm << "for up to " << numjets_ << " jets ";
    ostrm << "(Plots in folder " << foldername_ << "): ";
    return ostrm;
  }
  //==================================================================
  
} //~namespace Operation
