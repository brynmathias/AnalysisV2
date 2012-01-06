/*! \file MCPlottingOps.cc
 * \brief Source code for the Monte Carlo-based plotting operations.
 */
#include "MCPlottingOps.hh"
#include "GenObject.hh"
#include <sstream>
#include <iostream>

namespace Operation {

    //====================================
    // PLOTTING OPERATION PROFORMA 
    //====================================
    // Constructor
  void  GenObjPlotByID::BookHistos() {
    std::cout << "Booking histograms for the GenObjPlotByID" << std::endl;
    if (anti_) pdgId_ = abs(pdgId_); // Safety check - if we're including anti-particles, -ve sign irrelevant.
    
    BookHistArray(hg_multiplicity_, "Multiplicity", ";Number in event;Events / 100 pb^{-1}",
		  numObj_+1,-0.5,numObj_+0.5,1,0,1,true);
    
    BookHistArray(hg_E_,"E",";Energy / GeV;", 150, -1000., 2000., numObj_+1, 0, 1, true);
    BookHistArray(hg_Et_,"Et",";E_{T} / GeV;", 150, -1000., 2000., numObj_+1, 0, 1, true);
    BookHistArray(hg_Pt_,"Pt",";p_{T} / GeV;", 150, -1000., 2000., numObj_+1, 0, 1, true);
    BookHistArray(hg_eta_,"eta",";#eta;", 120, -6., 6., numObj_+1, 0, 1, true);
    BookHistArray(hg_m_, "m", ";m / GeV;", 150, -1000., 2000., numObj_+1, 0, 1, true);
  }
  
  bool GenObjPlotByID::Process(Event::Data & ev) {
    // Fill your histograms...
    
    
    UInt_t num = 0; // Counter for the particles of the required ID.
    
    // Loop over the gen objects
    for (std::vector<Event::GenObject>::const_iterator i = ev.GenParticles().begin(); i!=ev.GenParticles().end(); ++i) {
      Int_t myId = i->GetID();
      if (anti_) myId = abs(myId); // If we're including antiparticles, lose the negative sign.        
      if (myId == pdgId_) { // If we have a match
	// Plot the nth histogram?
	num++;
	if (num <= numObj_) { // if we're below the maximum number of objects to plot...
	  hg_E_[num]->Fill( i->E(), ev.GetEventWeight() );
	  hg_Et_[num]->Fill( i->Et(), ev.GetEventWeight() );
	  hg_Pt_[num]->Fill( i->Pt(), ev.GetEventWeight() );
	  hg_eta_[num]->Fill( i->Eta(), ev.GetEventWeight() );
	  hg_m_[num]->Fill( i->M(), ev.GetEventWeight() );
	}
      } // end of PDG ID check
    } // end of loop over the event's 
    
    hg_multiplicity_[0]->Fill( num, ev.GetEventWeight() );
    
    
    return true; // Plotting operations always pass.
  }

  std::ostream& GenObjPlotByID::Description(std::ostream &ostrm) {
    ostrm << "Plotting operation "
	  << " (folder " << foldername_ << ") ";
    // Add any further documentation, param names etc. here.
    ostrm << "GenObjPlotByID, PDG ID=" << pdgId_ << ", anti?=" << anti_ << " ";
    
    return ostrm;
  }
  //==================================================================

} //~namespace Operation
