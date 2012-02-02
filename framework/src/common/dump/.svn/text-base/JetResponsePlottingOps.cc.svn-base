/*! \file MCOps.cc 
 * \brief Source code for Monte Carlo (truth) information-based operations.
 */
#include "JetResponsePlottingOps.hh"
#include "TMath.h"
#include "Math/VectorUtil.h"
#include "EventData.hh"
#include "Jet.hh"

namespace Operation {

 void  JetCorPlot::BookHistos() 
  {
    // Book histograms
    
    hg_ComJet_DeltaEvsE = new TH2D("comJet_deltaE_vs_E",";genJet E [Gev];recJet E/genJet E",200,0.,5000.,200,-1.,4.); hg_ComJet_DeltaEvsE->Sumw2();
    hg_ComJet_DeltaEtvsEt = new TH2D("comJet_deltaEt_vs_Et",";genJet Et [Gev];recJet Et/genJet Et",200,0.,5000.,200,-1.,4.); hg_ComJet_DeltaEtvsEt->Sumw2();
    hg_ComJet_DeltaPtvsPt = new TH2D("comJet_deltaPt_vs_Pt",";genJet Pt [Gev];recJet Pt/genJet Pt",200,0.,5000.,200,-1.,4.); hg_ComJet_DeltaPtvsPt->Sumw2();
    hg_ComJet_DeltaPtvsEta = new TH2D("comJet_deltaPt_vs_eta",";genJet Eta [rad];recJet Pt/genJet Pt",50,-5.,5.,200,-1.,4.); hg_ComJet_DeltaPtvsEta->Sumw2();


    hg_ComJetParton_DeltaEvsE = new TH2D("comJetParton_deltaE_vs_E",";parton E [Gev];recJet E/genJet E",200,0.,5000.,200,-1.,4.); hg_ComJetParton_DeltaEvsE->Sumw2();
    hg_ComJetParton_DeltaEtvsEt = new TH2D("comJetParton_deltaEt_vs_Et",";parton Et [Gev];recJet Et/parton Et",200,0.,5000.,200,-1.,4.); hg_ComJetParton_DeltaEtvsEt->Sumw2();
    hg_ComJetParton_DeltaPtvsPt = new TH2D("comJetParton_deltaPt_vs_Pt",";parton Pt [Gev];recJet Pt/parton Pt",200,0.,5000.,200,-1.,4.); hg_ComJetParton_DeltaPtvsPt->Sumw2();
    hg_ComJetParton_DeltaPtvsEta = new TH2D("comJetParton_deltaPt_vs_eta",";parton Eta [rad];recJet Pt/parton Pt",50,-5.,5.,200,-1.,4.); hg_ComJetParton_DeltaPtvsEta->Sumw2();
    
    hg_leadingJetRes = new TH1D("leadingJetRes",";1. jet (rec Pt - gen Pt)/ gen Pt;",100,-2.5,2.5);
    hg_Jet_DeltaPhivsEta = new TH2D("DeltaPhivsEta",";genJet Eta [rad];#Delta #phi",50,-5.,5.,40,0,TMath::Pi()/2);
    hg_Jet_DeltaPhivsPt = new TH2D("DeltaPhivsPt",";genJet Pt [rad];#Delta #phi",200,0.,5000.,40,0,TMath::Pi()/2);
    hg_leadJet_DeltaPhivsDeltaPhi = new TH2D("DeltaPhivsDeltaPhi",";#Delta Pt/Pt;#Delta #phi",200,-4.,4.,40,0,TMath::Pi()/2);

    hg_leadingJetRes_Parton = new TH1D("leadingJetRes_Parton",";1. jet (rec Pt - parton Pt)/ gen Pt;",100,-2.5,2.5);
    hg_Jet_DeltaPhivsEta_Parton = new TH2D("DeltaPhivsEta_Parton",";parton Eta [rad];#Delta #phi",50,-5.,5.,40,0,TMath::Pi()/2);
    hg_Jet_DeltaPhivsPt_Parton = new TH2D("DeltaPhivsPt_Parton",";parton Pt [rad];#Delta #phi",200,0.,5000.,40,0,TMath::Pi()/2);
    hg_leadJet_DeltaPhivsDeltaPhi_Parton = new TH2D("DeltaPhivsDeltaPhi_Parton",";#Delta Pt/Pt;#Delta #phi",200,-4.,4.,40,0,TMath::Pi()/2);

  }

  JetCorPlot::~JetCorPlot() {

 
  // The profile histograms

    // To be improved !!! At this point , only a rough closure test to the correction function applied to the Jets :
    // The response distributions are fitted in bins of ET/eta with a simple
    // Gaussian (not really taking into account the tails in the distributions ) 
  
    cout <<" in destructor of JetCorPlot JetResponsePlottingOps::JetCorPlot "<<endl;
    cout <<" The TFile is still used which is dangerous, because the main might have deleted the File already "<<endl;
    cout <<" If you get a seg failt right after this message check where the TFile for the plots is deleted closed or something like this "<<endl;
    cout <<" (afterburners should be in a seperate macro, I did not design it like that, just ported it) "<<endl;
 
    hg_ComJet_DeltaPtvsPt->FitSlicesY();
    hg_ComJet_DeltaPtvsEta->FitSlicesY();
    hg_ComJetParton_DeltaPtvsPt->FitSlicesY();
    hg_ComJetParton_DeltaPtvsEta->FitSlicesY();
    // the_TFile->ls();

    TDirectory* adir = ( TDirectory*)the_TFile->Get(the_filename.c_str());
    // cout << the_filename <<endl;
    // adir->ls();
    // cout <<" in destructor "<<endl;
   // Average response vs genJet ET
    mean = (TH1D*)adir->Get("comJet_deltaPt_vs_E");
    mean->GetXaxis()->SetRangeUser(30.,1000.);
    mean->GetYaxis()->SetRangeUser(0.,2.5);
    mean->GetXaxis()->SetTitle("p_{T}^{GenJet}");
    mean->GetYaxis()->SetTitle("< p_{T}^{RECO} / p_{T}^{GEN} >");
    //  cout <<" in destructor 1"<<endl;
   // Average response vs genJet ETA
    mean_vs_eta = (TH1D*)adir->Get("comJet_deltaPt_vs_eta");
    mean_vs_eta->GetXaxis()->SetRangeUser(-5.,5.);
    mean_vs_eta->GetYaxis()->SetRangeUser(0.,2.5);
    mean_vs_eta->GetXaxis()->SetTitle("#eta^{GenJet}");
    mean_vs_eta->GetYaxis()->SetTitle("< p_{T}^{RECO} / p_{T}^{GEN} >");

    // Resolution
    res = (TH1D*)adir->Get("comJet_deltaPt_vs_E");
    res->GetXaxis()->SetRangeUser(30.,1000.);
    res->GetYaxis()->SetRangeUser(0.,1.);
    res->GetXaxis()->SetTitle("p_{T}^{GenJet}");
    res->GetYaxis()->SetTitle("#sigma (< p_{T}^{RECO} / p_{T}^{GEN} >)");

 
  }

  bool JetCorPlot::Process(Event::Data & ev) {
    // Fill the histogram(s).

    for (std::vector<Event::Jet const *>::const_iterator par = ev.JD_CommonJets().accepted.begin();
	 par != ev.JD_CommonJets().accepted.end();
	 ++par) {
        
      UInt_t id = (*par)->GetIndex();
        
        
        TLorentzVector GenJet(ev.GenJetpx()[id],
			      ev.GenJetpy()[id],
			      ev.GenJetpz()[id],
			      ev.GenJetE()[id]);

        TLorentzVector GenParton(ev.JetPartonPx()[id],
				 ev.JetPartonPy()[id],
				 ev.JetPartonPz()[id],
				 ev.JetPartonE()[id]);
        
        double jetE = (*par)->E();
        double jetET = (*par)->Et();
        double jetPT = (*par)->Pt();
        
        double genET = GenJet.Et();
        double genPT = GenJet.Pt();
        double genETA = GenJet.Eta();
        double genE = GenJet.E();
        
        double parET = GenParton.Et();
        double parPT = GenParton.Pt();
        double parETA = GenParton.Eta();
        double parE = GenParton.E();

        //   if ( !par->WasItcc() ) { continue; } // a hidden cut BAD STYLE !!!!!!!!
      
    
        if (genPT>0.) {

	  if(par == ev.JD_CommonJets().accepted.begin()){
	    hg_leadingJetRes->Fill((jetPT-genPT)/genPT, ev.GetEventWeight());
              
           }
           // If Jet was matched with a GenJet
           hg_ComJet_DeltaPtvsEta->Fill( genETA, (jetPT/genPT), ev.GetEventWeight());
           hg_ComJet_DeltaPtvsPt->Fill( genPT, (jetPT/genPT), ev.GetEventWeight()); 
           hg_ComJet_DeltaEtvsEt->Fill( genET, (jetET/genET), ev.GetEventWeight()); 
           hg_ComJet_DeltaEvsE->Fill( genE, (jetE/genE), ev.GetEventWeight()); 
           
      

           float dPhiAbs = fabs(ROOT::Math::VectorUtil::DeltaPhi(GenJet,**par));
           
           hg_Jet_DeltaPhivsEta->Fill( genETA ,dPhiAbs, ev.GetEventWeight()); 
           hg_Jet_DeltaPhivsPt->Fill( genPT ,dPhiAbs, ev.GetEventWeight()); 
           hg_leadJet_DeltaPhivsDeltaPhi ->Fill( (jetET-genET)/genET,dPhiAbs, ev.GetEventWeight());
           
        } 
        
        if(ev.JetPartonE()[id] > 0){
           //  if(parPT > 1300) cout << " what happened ?" << ev.ND.GetPartonJetE(id) << " parE " << parE << endl;
	  if(par == ev.JD_CommonJets().accepted.begin())hg_leadingJetRes_Parton->Fill((jetPT-parPT)/parPT, ev.GetEventWeight());
           
           hg_ComJetParton_DeltaPtvsEta->Fill( parETA, (jetPT/parPT), ev.GetEventWeight());
           hg_ComJetParton_DeltaPtvsPt->Fill( parPT, (jetPT/parPT), ev.GetEventWeight()); 
           hg_ComJetParton_DeltaEtvsEt->Fill( parET, (jetET/parET), ev.GetEventWeight()); 
           hg_ComJetParton_DeltaEvsE->Fill( parE, (jetE/parE), ev.GetEventWeight()); 
           
           float dPhiAbsPart = fabs(ROOT::Math::VectorUtil::DeltaPhi(GenParton,**par));
           
           hg_Jet_DeltaPhivsEta_Parton->Fill( parETA ,dPhiAbsPart, ev.GetEventWeight()); 
           hg_Jet_DeltaPhivsPt_Parton->Fill( parPT ,dPhiAbsPart, ev.GetEventWeight()); 
           hg_leadJet_DeltaPhivsDeltaPhi_Parton ->Fill( (jetET-parET)/parET,dPhiAbsPart, ev.GetEventWeight());
        }
        
      
     }
     
     return true; // Check for fails above, return false to fail operation.
  }

    std::ostream& JetCorPlot::Description(std::ostream &ostrm) {
    ostrm << "JetCorPlot made histograms";
    return ostrm;
  }

} //~namespace Operation
