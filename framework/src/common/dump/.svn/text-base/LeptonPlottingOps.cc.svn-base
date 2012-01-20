/*! \file LeptonPlottingOps.cc
 * \brief Source code for the leptonic analysis plotting operations.
 */
#include "LeptonPlottingOps.hh"

#include "EventData.hh"
#include "Lepton.hh"

namespace Operation {

  //========================================
  // Lepton counting histogrammer operation
  //========================================
  //
  void LeptonCountPlot::BookHistos()  
  {
    // Initialise the histograms.
    hg_NumCommonElectrons = new TH1D("hg_NumCommonElectrons",";Number of common electrons;events/fb^{-1}",10,0.,10.);
    hg_NumCommonElectrons->Sumw2();

  } // end of LeptonCountPlot constructor.

  bool LeptonCountPlot::Process(Event::Data & ev) {
    // Fill the histogram(s).
    hg_NumCommonElectrons->Fill(ev.LD_CommonElectrons().accepted.size(),
				ev.GetEventWeight()); 
    return true; // Check for fails above, return false to fail operation.
  }

  std::ostream& LeptonCountPlot::Description(std::ostream &ostrm) {
    ostrm << "LeptonCountPlot made here"<<endl;  
    return ostrm;
  }


  SingleLepPlots::SingleLepPlots(const std::string & folderName) :
    mFolderName(folderName) {}
  SingleLepPlots::~SingleLepPlots() {}

  void SingleLepPlots::Start(Event::Data & ev) {
    initDir(ev.OutputFile(),mFolderName.c_str());
    BookHistos();
  }

  void SingleLepPlots::BookHistos() {

    he_calogen = new TH2D("e_calogen","",100,0.,1000.,500,-100.,100.);
    he_recoilgen = new TH2D("e_recoilgen","",100,0.,1000.,500,-100.,100.);
    hm_calogen = new TH2D("m_calogen","",100,0.,1000.,500,-100.,100.);
    hm_recoilgen = new TH2D("m_recoilgen","",100,0.,1000.,500,-100.,100.);

    hg_ComLepRecoil = new TH1D("hg_ComLepRecoil","Events/100pb^{-1}",100,0.,1000.);
    hg_ComEleRecoil = new TH1D("hg_ComEleRecoil","Events/100pb^{-1}",100,0.,1000.);
    hg_ComMuRecoil = new TH1D("hg_ComMuRecoil","Events/100pb^{-1}",100,0.,1000.);

    hg_ComEleCalo = new TH1D("hg_ComEleCalo","Events/100pb^{-1}",100,0.,1000.);
    hg_ComMuCalo = new TH1D("hg_ComMuCalo","Events/100pb^{-1}",100,0.,1000.);
    hg_ComEleccCalo = new TH1D("hg_ComEleccCalo","Events/100pb^{-1}",100,0.,1000.);
    hg_ComMuccCalo = new TH1D("hg_ComMuccCalo","Events/100pb^{-1}",100,0.,1000.);

    hg_ComLepMult = new TH1D("hg_ComLepMult","",10,-0.5,9.5);
    hg_ComEleMult = new TH1D("hg_ComEleMult","",10,-0.5,9.5); 
    hg_ComMuMult = new TH1D("hg_ComMuMult","",10,-0.5,9.5); 

    hg_NComJet = new TH1D("hg_NComJet","",15,-0.5,14.5); 
    he_NComJet = new TH1D("he_NComJet","",15,-0.5,14.5); 
    hmu_NComJet = new TH1D("hmu_NComJet","",15,-0.5,14.5); 

    he_ComMHT = new TH1D("he_ComMHT","",200,0.,2000.); 
    he_ComHT = new TH1D("he_ComHT","",200,0.,2000.); 

    // Electron channel
    hg_GdElectronRecoilMET_MT = new TH1D("hg_GdElectronRecoil_MT","",250,0.,500.);
    hg_GdElectronRecoilMET_dPhi = new TH1D("hg_GdElectronRecoil_dPhi","",80,0.,3.14159);
    hg_GdElectronRecoilMET_dPhi2 = new TH1D("hg_GdElectronRecoil_dPhi2","",80,0.,3.14159);
    hg_GdElectron_PT = new TH1D("hg_GdElectron_PT","",100,0.,1.);
    hg_GdElectron_PT2 = new TH1D("hg_GdElectron_PT2","",100,0.,1.);

    hg_GdElectron_cor1 = new TH2D("hg_GdElectron_cor1","",250,0.,500.,100,0.,1000.);// hg_GdElectron_cor1->Sumw2();
    hg_GdElectron_cor2 = new TH2D("hg_GdElectron_cor2","",100,0.,1000.,80,0.,3.14159);// hg_GdElectron_cor2->Sumw2();
    hg_GdElectron_cor3 = new TH2D("hg_GdElectron_cor3","",250,0.,500.,80,0.,3.14159);// hg_GdElectron_cor3->Sumw2();
    hg_GdElectron_cor4 = new TH2D("hg_GdElectron_cor4","",250,0.,500.,100,0.,1000.);// hg_GdElectron_cor4->Sumw2();

    he_MTHT = new TH2D("he_MTHT","",250,0.,500.,200,0.,2000.);
    he_MTMHT = new TH2D("he_MTMHT","",250,0.,500.,200,0.,2000.);
    he_MTHTMHT = new TH2D("he_MTHTMHT","",250,0.,500.,400,0.,4000.);
    he_MTSumET = new TH2D("he_MTSumET","",250,0.,500.,400,0.,4000.);
    he_MTMeff = new TH2D("he_MTMeff","",250,0.,500.,400,0.,4000.);

    // Muon channel
    hmu_ComMHT = new TH1D("hmu_ComMHT","",200,0.,2000.); 
    hmu_ComHT = new TH1D("hmu_ComHT","",200,0.,2000.);

    hg_GdMuonRecoilMET_MT = new TH1D("hg_GdMuonRecoil_MT","",250,0.,500.);
    hg_GdMuonRecoilMET_dPhi = new TH1D("hg_GdMuonRecoil_dPhi","",80,0.,3.1459); 
    hg_GdMuonRecoilMET_dPhi2 = new TH1D("hg_GdMuonRecoil_dPhi2","",80,0.,3.1459); 
    hg_GdMuon_PT = new TH1D("hg_GdMuon_PT","",200,-0.005,1.995);
    hg_GdMuon_PT2 = new TH1D("hg_GdMuon_PT2","",100,0.,1.);

    hg_GdMuon_cor1 = new TH2D("hg_GdMuon_cor1","",250,0.,500.,100,0.,1000.); //hg_GdMuon_cor1->Sumw2();
    hg_GdMuon_cor2 = new TH2D("hg_GdMuon_cor2","",100,0.,1000.,80,0.,3.14159); //hg_GdMuon_cor2->Sumw2();
    hg_GdMuon_cor3 = new TH2D("hg_GdMuon_cor3","",250,0.,500.,80,0.,3.14159); //hg_GdMuon_cor3->Sumw2();
    hg_GdMuon_cor4 = new TH2D("hg_GdMuon_cor4","",250,0.,500.,100,0.,1000.); //hg_GdMuon_cor4->Sumw2();
    hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht = new TH2D("hg_GdMuon_deltaphi_muon-commht_vs_muonpt-divided-commht","",500,-0.005,4.995,80,0.,3.14159);
    hg_GdMuon_deltaphi_muon_commht = new TH1D("hg_GdMuon_deltaphi_muon_commht","",80,0.,3.14159);
    hg_GdMuon_ratio_muonpt_commht = new TH1D("hg_GdMuon_ratio_muonpt_commht","",500,-0.005,4.995);
    hg_GdMuonpt = new TH1D("hg_GdMuonpt","",1000,-0.5,999.5);

    hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_2jet = new TH2D("hg_GdMuon_deltaphi_muon-commht_vs_muonpt-divided-commht_2jet","",500,-0.005,4.995,80,0.,3.14159);
    hg_GdMuon_deltaphi_muon_commht_2jet = new TH1D("hg_GdMuon_deltaphi_muon_commht_2jet","",80,0.,3.14159);
    hg_GdMuon_ratio_muonpt_commht_2jet = new TH1D("hg_GdMuon_ratio_muonpt_commht_2jet","",500,-0.005,4.995);
    hg_GdMuonpt_2jet = new TH1D("hg_GdMuonpt_2jet","",1000,-0.5,999.5);

    hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_3jet = new TH2D("hg_GdMuon_deltaphi_muon-commht_vs_muonpt-divided-commht_3jet","",500,-0.005,4.995,80,0.,3.14159);
    hg_GdMuon_deltaphi_muon_commht_3jet = new TH1D("hg_GdMuon_deltaphi_muon_commht_3jet","",80,0.,3.14159);
    hg_GdMuon_ratio_muonpt_commht_3jet = new TH1D("hg_GdMuon_ratio_muonpt_commht_3jet","",500,-0.005,4.995);
    hg_GdMuonpt_3jet = new TH1D("hg_GdMuonpt_3jet","",1000,-0.5,999.5);

    hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_4jet = new TH2D("hg_GdMuon_deltaphi_muon-commht_vs_muonpt-divided-commht_4jet","",500,-0.005,4.995,80,0.,3.14159);
    hg_GdMuon_deltaphi_muon_commht_4jet = new TH1D("hg_GdMuon_deltaphi_muon_commht_4jet","",80,0.,3.14159);
    hg_GdMuon_ratio_muonpt_commht_4jet = new TH1D("hg_GdMuon_ratio_muonpt_commht_4jet","",500,-0.005,4.995);
    hg_GdMuonpt_4jet = new TH1D("hg_GdMuonpt_4jet","",1000,-0.5,999.5);

    hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_5jet = new TH2D("hg_GdMuon_deltaphi_muon-commht_vs_muonpt-divided-commht_5jet","",500,-0.005,4.995,80,0.,3.14159);
    hg_GdMuon_deltaphi_muon_commht_5jet = new TH1D("hg_GdMuon_deltaphi_muon_commht_5jet","",80,0.,3.14159);
    hg_GdMuon_ratio_muonpt_commht_5jet = new TH1D("hg_GdMuon_ratio_muonpt_commht_5jet","",500,-0.005,4.995);
    hg_GdMuonpt_5jet = new TH1D("hg_GdMuonpt_5jet","",1000,-0.5,999.5);

    hm_MTHT = new TH2D("hm_MTHT","",250,0.,500.,200,0.,2000.);
    hm_MTMHT = new TH2D("hm_MTMHT","",250,0.,500.,200,0.,2000.);
    hm_MTHTMHT = new TH2D("hm_MTHTMHT","",250,0.,500.,400,0.,4000.);
    hm_MTSumET = new TH2D("hm_MTSumET","",250,0.,500.,400,0.,4000.);
    hm_MTMeff = new TH2D("hm_MTMeff","",250,0.,500.,400,0.,4000.);

  } // SingleLepPlots

  bool SingleLepPlots::Process(Event::Data & ev) {

    // Fill the histograms
    hg_ComLepRecoil->Fill(ev.CommonRecoilMET().Pt(), ev.GetEventWeight());
    hg_ComLepMult->Fill((ev.LD_CommonElectrons().accepted.size()+ev.LD_CommonMuons().accepted.size()), ev.GetEventWeight());
    hg_ComEleMult->Fill(ev.LD_CommonElectrons().accepted.size(), ev.GetEventWeight());
    hg_ComMuMult->Fill(ev.LD_CommonMuons().accepted.size(), ev.GetEventWeight());

    // Jet muplitiplicity
    hg_NComJet->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());

      // 1-lepton mode SUSY variables
    double caloMET = ev.CaloMET().Pt();
    double recoilMET = ev.CommonRecoilMET().Pt();
    double genMET = ev.MC_SingleLepMET().Pt();

    if (ev.LD_GoodElectrons().size()>0) { // electron channel

      he_calogen->Fill(genMET, (genMET-caloMET), ev.GetEventWeight());
      he_recoilgen->Fill(genMET, (genMET-recoilMET), ev.GetEventWeight());
      
      // Analysis plots
      he_NComJet->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());
      
      // hg_EleRecoil->Fill(ev.RecoilMET.Pt(), ev.GetEventWeight());
      hg_ComEleRecoil->Fill(ev.CommonRecoilMET().Pt(), ev.GetEventWeight());
      hg_ComEleCalo->Fill(ev.CaloMET().Pt(), ev.GetEventWeight());
      hg_ComEleccCalo->Fill(ev.CCCaloMET().Pt(), ev.GetEventWeight());

      // HT & MHT distributions
      he_ComMHT->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
      he_ComHT->Fill(ev.CommonHT(), ev.GetEventWeight());

      double eMT=ev.MT(ev.LD_GoodElectrons()[0],&(ev.CommonRecoilMET()));

      hg_GdElectronRecoilMET_MT->Fill(eMT, ev.GetEventWeight()); // MT (lep, MET)
      hg_GdElectronRecoilMET_dPhi->Fill(ev.comRecoilMetdPhi(ev.LD_GoodElectrons()[0]),
					ev.GetEventWeight()); // DPHI (lep, MET)
      hg_GdElectronRecoilMET_dPhi2->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_GoodElectrons()[0],
										ev.CommonMHT())), 
					 ev.GetEventWeight()); 
      hg_GdElectron_PT->Fill( (ev.LD_GoodElectrons()[0]->Pt()/ev.CommonMHT().Pt()), ev.GetEventWeight());
      hg_GdElectron_PT2->Fill( (ev.LD_GoodElectrons()[0]->Pt()/ev.CommonRecoilMET().Pt()), ev.GetEventWeight());

      hg_GdElectron_cor1->Fill(eMT, ev.CommonMHT().Pt(), ev.GetEventWeight());
      hg_GdElectron_cor4->Fill(eMT, ev.CommonRecoilMET().Pt(), 
			       ev.GetEventWeight());
      hg_GdElectron_cor2->Fill(ev.CommonRecoilMET().Pt(), 
			       fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_GoodElectrons()[0],ev.CommonMHT())), 
			       ev.GetEventWeight());
      hg_GdElectron_cor3->Fill(eMT, 
			       fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_GoodElectrons()[0],ev.CommonMHT())), 
			       ev.GetEventWeight());

      he_MTHT->Fill(eMT, ev.CommonHT(), ev.GetEventWeight());
      he_MTMHT->Fill(eMT, ev.CommonMHT().Pt(), ev.GetEventWeight());
      he_MTHTMHT->Fill(eMT, (ev.CommonHT() + ev.CommonMHT().Pt()), ev.GetEventWeight());
      he_MTSumET->Fill(eMT, ev.CommonSumEt(), ev.GetEventWeight());
      he_MTMeff->Fill(eMT, (ev.CommonSumEt()+ev.CommonRecoilMET().Pt()), ev.GetEventWeight());
    }
    if (ev.LD_CommonMuons().accepted.size()>0) { // muon channel

      hm_calogen->Fill(genMET, (genMET-caloMET), ev.GetEventWeight());
      hm_recoilgen->Fill(genMET, (genMET-recoilMET), ev.GetEventWeight());

      hmu_NComJet->Fill(ev.JD_CommonJets().accepted.size(), ev.GetEventWeight());

      // hg_MuRecoil->Fill(ev.RecoilMET.Pt(), ev.GetEventWeight());
      hg_ComMuRecoil->Fill(ev.CommonRecoilMET().Pt(), ev.GetEventWeight());
      hg_ComMuCalo->Fill(ev.CaloMET().Pt(), ev.GetEventWeight());
      hg_ComMuccCalo->Fill(ev.CCCaloMET().Pt(), ev.GetEventWeight());

      // HT & MHT distributions
      hmu_ComMHT->Fill(ev.CommonMHT().Pt(), ev.GetEventWeight());
      hmu_ComHT->Fill(ev.CommonHT(), ev.GetEventWeight());

      double mMT = ev.MT(ev.LD_CommonMuons().accepted[0],&(ev.CommonRecoilMET()));

      hg_GdMuonRecoilMET_MT->Fill(mMT, ev.GetEventWeight()); // MT (lep, MET)
      hg_GdMuonRecoilMET_dPhi->Fill(ev.comRecoilMetdPhi(ev.LD_CommonMuons().accepted[0]), ev.GetEventWeight());// DPHI (lep, MET)
      hg_GdMuonRecoilMET_dPhi2->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), 
				     ev.GetEventWeight()); 
      hg_GdMuon_PT->Fill( (ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt()), ev.GetEventWeight());
      hg_GdMuon_PT2->Fill( (ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonRecoilMET().Pt()), ev.GetEventWeight());

      hg_GdMuon_cor1->Fill(mMT, ev.CommonMHT().Pt(), ev.GetEventWeight());
      hg_GdMuon_cor4->Fill(mMT, ev.CommonRecoilMET().Pt(), ev.GetEventWeight());
      hg_GdMuon_cor2->Fill(ev.CommonRecoilMET().Pt(), 
			   fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());
      hg_GdMuon_cor3->Fill(mMT,fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());

      if(ev.CommonMHT().Pt() > 0) {
	hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());
	hg_GdMuon_deltaphi_muon_commht->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())),ev.GetEventWeight());	
	hg_GdMuon_ratio_muonpt_commht->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),ev.GetEventWeight());
      }
      hg_GdMuonpt->Fill(ev.LD_CommonMuons().accepted[0]->Pt(),ev.GetEventWeight());

      if(ev.JD_CommonJets().accepted.size() == 2){
	if(ev.CommonMHT().Pt() > 0){
	  hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_2jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());
	  hg_GdMuon_deltaphi_muon_commht_2jet->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())),ev.GetEventWeight());	
	  hg_GdMuon_ratio_muonpt_commht_2jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),ev.GetEventWeight());
	}
	hg_GdMuonpt_2jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt(),ev.GetEventWeight());
      }
      
      if(ev.JD_CommonJets().accepted.size() == 3){
	if(ev.CommonMHT().Pt() > 0){
	  hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_3jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());
	  hg_GdMuon_deltaphi_muon_commht_3jet->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())),ev.GetEventWeight());	
	  hg_GdMuon_ratio_muonpt_commht_3jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),ev.GetEventWeight());
	}
	hg_GdMuonpt_3jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt(),ev.GetEventWeight());
      }
      
      if(ev.JD_CommonJets().accepted.size() == 4){
	if(ev.CommonMHT().Pt() > 0){
	  hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_4jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());
	  hg_GdMuon_deltaphi_muon_commht_4jet->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())),ev.GetEventWeight());	
	  hg_GdMuon_ratio_muonpt_commht_4jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),ev.GetEventWeight());
	}
	hg_GdMuonpt_4jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt(),ev.GetEventWeight());
      }
      
      if(ev.JD_CommonJets().accepted.size() == 5){
	if(ev.CommonMHT().Pt() > 0) {
	  hg_GdMuon_deltaphi_muon_commht_vs_muonpt_divided_commht_5jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())), ev.GetEventWeight());
	  hg_GdMuon_deltaphi_muon_commht_5jet->Fill(fabs(ROOT::Math::VectorUtil::DeltaPhi( *ev.LD_CommonMuons().accepted[0],ev.CommonMHT())),ev.GetEventWeight());	
	  hg_GdMuon_ratio_muonpt_commht_5jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt()/ev.CommonMHT().Pt(),ev.GetEventWeight());
	}
	hg_GdMuonpt_5jet->Fill(ev.LD_CommonMuons().accepted[0]->Pt(),
			       ev.GetEventWeight());
      }

      hm_MTHT->Fill(mMT,ev.CommonHT(),ev.GetEventWeight());
      hm_MTMHT->Fill(mMT, ev.CommonMHT().Pt(),ev.GetEventWeight());
      hm_MTHTMHT->Fill(mMT, (ev.CommonHT()+ev.CommonMHT().Pt()), ev.GetEventWeight());
      hm_MTSumET->Fill(mMT, ev.CommonSumEt(), ev.GetEventWeight());
      hm_MTMeff->Fill(mMT, (ev.CommonSumEt()+ev.CommonRecoilMET().Pt()), ev.GetEventWeight());
    }

    return true; // Check for fails above, return false to fail operation.
  }

  std::ostream& SingleLepPlots::Description(std::ostream &ostrm) {
    ostrm << "SingleLepPlot plots made here ";
    return ostrm;
  }
}


