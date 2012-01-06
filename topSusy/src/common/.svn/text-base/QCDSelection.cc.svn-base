#include <fstream>
#include "QCDSelection.hh"
#include "TopSusySelection.hh"
bool comparePt(TLorentzVector v1, TLorentzVector v2) {
  return v1.Pt() > v2.Pt();
}
bool compareLepPt(lepton l1, lepton l2) {
  return (l1.vector).Pt() > (l2.vector).Pt();
}
namespace TopSusy {

  QCDSelector::QCDSelector(const std::string&   folderName,
                                   Utils::ParameterSet& pSet) :
                                   folderName_(folderName) {
    minNElecs        = pSet.Get<int>   ("MinNElecs");
    minNMuons        = pSet.Get<int>   ("MinNMuons");
    minNJets         = pSet.Get<int>   ("MinNJets");
    minNHits         = pSet.Get<int>   ("MinNHits");
    minHt            = pSet.Get<double>("MinHt");
    minMht           = pSet.Get<double>("MinMht");
    minElecEt        = pSet.Get<double>("MinElecEt");
    minMuonPt        = pSet.Get<double>("MinMuonPt");
    minJetPt         = pSet.Get<double>("MinJetPt");
    maxElecAbsEta    = pSet.Get<double>("MaxElecAbsEta");
    maxMuonAbsEta    = pSet.Get<double>("MaxMuonAbsEta");
    maxJetAbsEta     = pSet.Get<double>("MaxJetAbsEta");
    maxCorrD0        = pSet.Get<double>("MaxCorrD0");
    maxElecRelIso    = pSet.Get<double>("MaxElecRelIso");
    maxElecTkIso     = pSet.Get<double>("MaxElecTkIso");
    maxMuonRelIso    = pSet.Get<double>("MaxMuonRelIso");
    maxNormChi2      = pSet.Get<double>("MaxNormChi2");
    minJetElecDeltaR = pSet.Get<double>("MinJetElecDeltaR");

    
    applyLeptonVeto   = pSet.Get<bool>  ("ApplyVeto");
    minSecondLeptonPt = pSet.Get<double>("MinSecondLeptonPt"); 
    maxNElecs         = pSet.Get<int>   ("MaxNElecs");
    maxNMuons         = pSet.Get<int>   ("MaxNMuons");
    maxNJets          = pSet.Get<int>   ("MaxNJets");
    maxHt             = pSet.Get<double>("MaxHt");
    maxMht            = pSet.Get<double>("MaxMht");
    minCorrD0         = pSet.Get<double>("MinCorrD0");
    invertedId        = pSet.Get<bool>("InvertedId");
    minDeltaphi       = pSet.Get<double>("MinDeltaPhi");
    maxDeltaphi       = pSet.Get<double>("MaxDeltaPhi");    
  }

  QCDSelector::~QCDSelector() {}
  
  void QCDSelector::BookHistos() {
    BookHistArray(h_el_tkisol,"h_el_tkisol","",100,0,50,10,0,1,false);
    BookHistArray(h_el_ecalisol,"h_el_ecalisol","",100,0,50,10,0,1,false);
    BookHistArray(h_el_hcalisol,"h_el_hcalisol","",100,0,50,10,0,1,false);
    BookHistArray(h_el_combisol,"h_el_combisol","",100,0,50,10,0,1,false);
    BookHistArray(h_el_relcombisol,"h_el_relcombisol","",100,0,2.,10,0,1,false);
    BookHistArray(h_mu_tkisol,"h_mu_tkisol","",100,0,50,10,0,1,false);
    BookHistArray(h_mu_ecalisol,"h_mu_ecalisol","",100,0,50,10,0,1,false);
    BookHistArray(h_mu_hcalisol,"h_mu_hcalisol","",100,0,50,10,0,1,false);
    BookHistArray(h_mu_combisol,"h_mu_combisol","",100,0,50,10,0,1,false);
    BookHistArray(h_mu_relcombisol,"h_mu_relcombisol","",100,0,2.,10,0,1,false);

    h_mu_pt      = new TH1D("h_mu_pt"  ,"h_mu_pt"  ,100,0,100);
    h_el_pt      = new TH1D("h_el_pt"  ,"h_el_pt"  ,100,0,100);
    h_el_Wt      = new TH1D("h_el_Wt"  ,"h_el_Wt"  ,100,0,1000);
    h_mu_Wt      = new TH1D("h_mu_Wt"  ,"h_mu_Wt"  ,100,0,1000);
    h_el_Dphi    = new TH1D("h_el_Dphi","h_el_Dphi"  ,70,3.5,3.5);
    h_mu_Dphi    = new TH1D("h_mu_Dphi","h_mu_Dphi"  ,70,-3.5,3.5);
  }

  void QCDSelector::Start(Event::Data& data) {
    initDir(data.OutputFile(), folderName_.c_str());
    BookHistos();

    std::cout << "Folder name: " << folderName_ << std::endl;
  }

  bool QCDSelector::Process(Event::Data& data) {
    double                      elecMetDeltaPhi;
    TLorentzVector              mhtVector;
    std::vector<bool>           cuts;
    std::vector<TLorentzVector> jets;
    std::vector<lepton>         elecs, muons, vetoelecs, vetomuons ;

    passesCuts  = true;
    cuts.clear();
    eventWeight = data.GetEventWeight();
    ht          = 0.0;
    met         = data.CaloMET().Et();
    wMt         = -9.9;
    m3          = -9.9;
    elec1Et     = -9.9;
    jet1Pt      = -9.9;
    elec1Eta    = -9.9;

    mhtVector.SetPxPyPzE(0.0, 0.0, 0.0, 0.0);
	
    float minelpt=(applyLeptonVeto) ? minSecondLeptonPt : minElecEt;

    //ELECTRON SELECTION

    for (uint i = 0; i < data.LD_Electrons().size(); i++) {
      double corrD0 = getCorrD0(data.GetElecD0(i), data.LD_Electrons()[i].Phi());
      double relIso = (data.LD_Electrons()[i].GetTrkIsolation()   +
                       data.LD_Electrons()[i].GetEcalIsolation()  +
                       data.LD_Electrons()[i].GetHcalIsolation()) /
                       data.LD_Electrons()[i].Et();

      bool ElecId=(invertedId) ? (data.LD_Electrons()      [i].GetTightId() == false ) : 
	                         (data.LD_Electrons()      [i].GetTightId() == true  ) ;
    
      TLorentzVector vec;

      vec.SetPxPyPzE(data.LD_Electrons()[i].Px(),
                     data.LD_Electrons()[i].Py(),
                     data.LD_Electrons()[i].Pz(),
                     data.LD_Electrons()[i].E());
      bool goodIsolation=(vec.Pt()>30.) ?  (relIso  <  maxElecRelIso) :
	(data.LD_Electrons()[i].GetTrkIsolation()< maxElecTkIso);

      if (ElecId            &&
          data.LD_Electrons()      [i].Et()         >  minelpt            &&
          (fabs(data.LD_Electrons()[i].Eta())       <  MAX_BARREL_ABS_ETA ||
          (fabs(data.LD_Electrons()[i].Eta())       >  MIN_ENDCAP_ABS_ETA &&
          fabs(data.LD_Electrons() [i].Eta())       <  maxElecAbsEta))    &&
	  (goodIsolation)    &&
	  corrD0                                    >  minCorrD0          &&
          corrD0                                    <  maxCorrD0    )       {
	
	if (vec.Pt()>minElecEt){
	  elecs.push_back(lepton(data.LD_Electrons()[i].GetCharge(), vec));
	  ht        += vec.Pt();
	  mhtVector += -(vec);
	}
	else  vetoelecs.push_back(lepton(data.LD_Electrons()[i].GetCharge(), vec));
      }
    }

   //MUON SELECTION
    float minmupt=(applyLeptonVeto) ? minSecondLeptonPt : minMuonPt;
    for (uint i = 0; i < data.LD_Muons().size(); i++) {
      double corrD0 = getCorrD0(data.GetMuonCombD0(i), data.LD_Muons()[i].Phi());

      double relIso = (data.LD_Muons()[i].GetTrkIsolation()   +
                       data.LD_Muons()[i].GetEcalIsolation()  +
                       data.LD_Muons()[i].GetHcalIsolation()) /
                       data.LD_Muons()[i].Pt();  

      TLorentzVector vec;

      vec.SetPxPyPzE(data.LD_Muons()[i].Px(),
                     data.LD_Muons()[i].Py(),
                     data.LD_Muons()[i].Pz(),
                     data.LD_Muons()[i].E());

      if (data.LD_Muons()     [i].GetTightId() == true          &&
          data.GetMuonTrkValidHits       (i)   >= minNHits      &&
          data.LD_Muons()     [i].Pt()         >  minmupt       &&
          fabs(data.LD_Muons()[i].Eta())       <  maxMuonAbsEta &&
	  corrD0                               <  maxCorrD0     &&
          relIso                               <  maxMuonRelIso &&
          data.GetMuonGlobalTrackNormChi2(i)   <  maxNormChi2) {
	if(vec.Pt()>minMuonPt){
	  muons.push_back(lepton(data.LD_Muons()[i].GetCharge(), vec));
	  ht        += vec.Pt();
	  mhtVector += -(vec);
	}
	else vetomuons.push_back(lepton(data.LD_Muons()[i].GetCharge(), vec));
      }
    }


    //JET SELECTION

    for (uint i = 0; i < data.JD_Jets().size(); i++) {
      bool passesJetElecDeltaR = true;

      TLorentzVector vec;

      vec.SetPxPyPzE(data.JD_Jets()[i].Px(),
                     data.JD_Jets()[i].Py(),
                     data.JD_Jets()[i].Pz(),
                     data.JD_Jets()[i].E());

      for (uint j = 0; j < elecs.size(); j++) {
        double jetElecDeltaPhi = getDeltaPhi(vec.Phi(), ((elecs.at(j)).vector).Phi());

        double jetElecDeltaR = sqrt((vec.Eta() - ((elecs.at(j)).vector).Eta()) *
                                    (vec.Eta() - ((elecs.at(j)).vector).Eta()) +
                                     jetElecDeltaPhi                           *
                                     jetElecDeltaPhi);

        passesJetElecDeltaR = passesJetElecDeltaR && jetElecDeltaR > minJetElecDeltaR;
      }

      if (vec.Pt()        > minJetPt     &&
          fabs(vec.Eta()) < maxJetAbsEta &&
          passesJetElecDeltaR) {
        jets.push_back(vec);

        ht        += vec.Pt();
        mhtVector += -(vec);
      }
    }

    sort(elecs.begin(), elecs.end(), compareLepPt);
    sort(muons.begin(), muons.end(), compareLepPt);
    sort(jets.begin(),  jets.end(),  comparePt);

    nElecs = elecs.size();
    nMuons = muons.size();
    nJets  = jets.size();

    mht = mhtVector.Pt();

    if (minNElecs == 2 && elecs.size() >= 2)
      chargeProd = (elecs.at(0)).charge * (elecs.at(1)).charge;
    else if (minNElecs == 1 && minNMuons == 1 && elecs.size() >= 1 && muons.size() >= 1)
      chargeProd = (elecs.at(0)).charge * (muons.at(0)).charge;
    else if (minNMuons == 2 && muons.size() >= 2)
      chargeProd = (muons.at(0)).charge * (muons.at(1)).charge;

    if (elecs.size() >= 1) {
      elecMetDeltaPhi = getDeltaPhi(((elecs.at(0)).vector).Phi(), data.CaloMET().Phi());

      wMt = sqrt(2 * ((elecs.at(0)).vector).Et() * met * (1 - cos(elecMetDeltaPhi)));

      elec1Et  = ((elecs.at(0)).vector).Et();
      elec1Eta = ((elecs.at(0)).vector).Eta();
    }

    if (jets.size() >= 3) {
      double jetSumPt        = 0.0;
      double highestJetSumPt = 0.0;

      for (uint i = 0; i < jets.size() - 2; i++) {
        for (uint j = i + 1; j < jets.size() - 1; j++) {
          for (uint k = j + 1; k < jets.size(); k++) {
            jetSumPt = (jets.at(i) + jets.at(j) + jets.at(k)).Pt();

            if (jetSumPt > highestJetSumPt) {
              highestJetSumPt = jetSumPt;
              m3              = (jets.at(i) + jets.at(j) + jets.at(k)).M();
            }
          }
        }
      }
    }

    if (jets.size() >= 1)
      jet1Pt = (jets.at(0)).Pt();
    float dfi=0.;
    if (nElecs>0) dfi=fabs(mhtVector.DeltaPhi(elecs[0].vector));
      
    
    cuts.push_back(nElecs >= minNElecs); 
    cuts.push_back(nElecs <= maxNElecs); 
    cuts.push_back(nMuons >= minNMuons);
    cuts.push_back(nMuons <= maxNMuons);
    cuts.push_back(nJets  >= minNJets);
    cuts.push_back(nJets  <= maxNJets);
    cuts.push_back(ht > minHt);
    cuts.push_back(mht > minMht);
    cuts.push_back(ht < maxHt);
    cuts.push_back(mht < maxMht);
    if (applyLeptonVeto){
      cuts.push_back(vetoelecs.size()==0);
      cuts.push_back(vetomuons.size()==0);   
    }
    cuts.push_back(dfi>=minDeltaphi);
    cuts.push_back(dfi<=maxDeltaphi);   

//     // For SUSY

//     cuts.push_back(ht > minHt && mht > minMht);
//     cuts.push_back(chargeProd == 1.0);

    for (uint i = 0; i < cuts.size(); i++) {
      passesCuts = passesCuts && cuts.at(i);

    }
    if (passesCuts){
      //ISOLATION PLOTS FOR ELECTRON
      for (uint iiee=0; iiee< elecs.size();iiee++){
	for (uint iel=0; iel< data.LD_Electrons().size();iel++){
	  if (fabs(data.LD_Electrons()[iel].Px()-elecs[iiee].vector.Px())<0.001){
	   
	    h_el_ecalisol[0]->Fill(data.LD_Electrons()[iel].GetEcalIsolation(),eventWeight);
	    h_el_hcalisol[0]->Fill(data.LD_Electrons()[iel].GetHcalIsolation(),eventWeight);
	    h_el_combisol[0]->Fill(data.LD_Electrons()[iel].GetTrkIsolation()+
				data.LD_Electrons()[iel].GetEcalIsolation()  +
				data.LD_Electrons()[iel].GetHcalIsolation(),eventWeight);
	    if(elecs[iiee].vector.Pt()>30.)
	      h_el_relcombisol[0]->Fill((data.LD_Electrons()[iel].GetTrkIsolation()+
					 data.LD_Electrons()[iel].GetEcalIsolation()  +
					 data.LD_Electrons()[iel].GetHcalIsolation())/data.LD_Electrons()[iel].Pt(),eventWeight);
	    else  h_el_tkisol[0]->Fill(data.LD_Electrons()[iel].GetTrkIsolation(),eventWeight);
	    int ipt=-1;
	    float pptt=elecs[iiee].vector.Pt();
	    if (pptt<5.)ipt=1; if (pptt>5. && pptt<10.) ipt=2; if (pptt>10. && pptt<15.) ipt=3;
	    if (pptt>15. && pptt<20)ipt=4; if (pptt>20. && pptt<25.) ipt=5; if (pptt>25. && pptt<30.) ipt=6;
	    if (pptt>30. && pptt<40.)ipt=7; if (pptt>40. && pptt<60.) ipt=8; if (pptt>60.) ipt=9;
	    h_el_tkisol[ipt]->Fill(data.LD_Electrons()[iel].GetTrkIsolation(),eventWeight);
	    h_el_ecalisol[ipt]->Fill(data.LD_Electrons()[iel].GetEcalIsolation(),eventWeight);
	    h_el_hcalisol[ipt]->Fill(data.LD_Electrons()[iel].GetHcalIsolation(),eventWeight);
	    h_el_combisol[ipt]->Fill(data.LD_Electrons()[iel].GetTrkIsolation()+
				     data.LD_Electrons()[iel].GetEcalIsolation()  +
				     data.LD_Electrons()[iel].GetHcalIsolation(),eventWeight);
	    h_el_relcombisol[ipt]->Fill((data.LD_Electrons()[iel].GetTrkIsolation()+
					 data.LD_Electrons()[iel].GetEcalIsolation()  +
					 data.LD_Electrons()[iel].GetHcalIsolation())/data.LD_Electrons()[iel].Pt(),eventWeight);
	    h_el_pt->Fill(pptt,eventWeight);
	    TLorentzVector W=mhtVector+elecs[iiee].vector;
	    h_el_Wt->Fill(W.Mt(),eventWeight);
	    h_el_Dphi->Fill(mhtVector.DeltaPhi(elecs[iiee].vector),eventWeight);
	  }
	}
      }
      //ISOLATION PLOTS FOR MUON
      for (uint iimm=0; iimm< muons.size();iimm++){
	for (uint imu=0; imu< data.LD_Muons().size();imu++){
	  if (fabs(data.LD_Muons()[imu].Px()-muons[iimm].vector.Px())<0.001){
	    h_mu_tkisol[0]->Fill(data.LD_Muons()[imu].GetTrkIsolation(),eventWeight);
	    h_mu_ecalisol[0]->Fill(data.LD_Muons()[imu].GetEcalIsolation(),eventWeight);
	    h_mu_hcalisol[0]->Fill(data.LD_Muons()[imu].GetHcalIsolation(),eventWeight);
	    h_mu_combisol[0]->Fill(data.LD_Muons()[imu].GetTrkIsolation()+
				data.LD_Muons()[imu].GetEcalIsolation()  +
				data.LD_Muons()[imu].GetHcalIsolation(),eventWeight);
	    h_mu_relcombisol[0]->Fill((data.LD_Muons()[imu].GetTrkIsolation()+
				       data.LD_Muons()[imu].GetEcalIsolation()  +
				       data.LD_Muons()[imu].GetHcalIsolation())/data.LD_Muons()[imu].Pt(),eventWeight);
	    
	    int ipt=-1;
	    float pptt=muons[iimm].vector.Pt();
	    if (pptt<5.)ipt=1; if (pptt>5. && pptt<10.) ipt=2; if (pptt>10. && pptt<15.) ipt=3;
	    if (pptt>15. && pptt<20)ipt=4; if (pptt>20. && pptt<25.) ipt=5; if (pptt>25. && pptt<30.) ipt=6;
	    if (pptt>30. && pptt<40.)ipt=7; if (pptt>40. && pptt<60.) ipt=8; if (pptt>60.) ipt=9;
	    h_mu_tkisol[ipt]->Fill(data.LD_Muons()[imu].GetTrkIsolation(),eventWeight);
	    h_mu_ecalisol[ipt]->Fill(data.LD_Muons()[imu].GetEcalIsolation(),eventWeight);
	    h_mu_hcalisol[ipt]->Fill(data.LD_Muons()[imu].GetHcalIsolation(),eventWeight);
	    h_mu_combisol[ipt]->Fill(data.LD_Muons()[imu].GetTrkIsolation()+
				     data.LD_Muons()[imu].GetEcalIsolation()  +
				     data.LD_Muons()[imu].GetHcalIsolation(),eventWeight);
	    h_mu_relcombisol[ipt]->Fill((data.LD_Muons()[imu].GetTrkIsolation()+
					 data.LD_Muons()[imu].GetEcalIsolation()  +
					 data.LD_Muons()[imu].GetHcalIsolation())/data.LD_Muons()[imu].Pt(),eventWeight);
	    h_mu_pt->Fill(pptt,eventWeight);
	  }
	}
      }
    }

    
    return passesCuts;
  }

  std::ostream& QCDSelector::Description(std::ostream& ostrm) {
    ostrm << "Selects top/SUSY events";

    return ostrm;
  }

  double QCDSelector::getCorrD0(double d0, double phi) {
    return d0 - BEAM_SPOT_X * sin(phi) + BEAM_SPOT_Y * cos(phi);
  }

  double QCDSelector::getDeltaPhi(double phi1, double phi2) {
    if (phi1 - phi2 > PI)
      return fabs(phi1 - phi2 - 2 * PI);

    if (phi1 - phi2 < -1 * PI)
      return fabs(phi1 - phi2 + 2 * PI);

    return fabs(phi1 - phi2);
  }
}
