#include "ControlPlottingOps.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include <sstream>
#include <string>
#include <iomanip>

#include "JetData.hh"
#include "CommonOps.hh"


using namespace Operation;

// -----------------------------------------------------------------------------
//
ControlPlottingOps::ControlPlottingOps(const Utils::ParameterSet& ps) :
  dirName_( ps.Get<std::string>("DirName") ),
  mFolderName_(ps.Get<std::string>("FolderName"))
{}

// -----------------------------------------------------------------------------
ControlPlottingOps::~ControlPlottingOps() {}

// -----------------------------------------------------------------------------
//
void ControlPlottingOps::Start( Event::Data& ev ) {
  TDirectory * headDir = returnDir(ev.OutputFile(),dirName_.c_str());
  initDir( headDir, mFolderName_.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void ControlPlottingOps::BookHistos() {
  TH1::SetDefaultSumw2(kTRUE);

  hNTotVertices = new TH1D("Total_Vertices", ";N (vertices);", 25, 0., 25.);
  hNVertices = new TH1D("NVertices", ";N (vertices);", 25, 0., 25.);
  hMT = new TH1D("MT",";M_{T} [GeV];",2000,0.,2000.);
  hAlphaT_Lep = new TH1D("aT_L",";#alpha_{T}^{leptonic};",1000, 0., 10.);
  hAlphaT_Had = new TH1D("aT_H",";#alpha_{T}^{hadronic};",5000, 0., 10.);
  hNJet = new TH1D("nJet",";N(jets);",20,-0.5,19.5);
  hHT = new TH1D("HT",";H_{T} [GeV];",2000,0.,2000.);
  hHTlep = new TH1D("HTlep",";H_{T}^{leptonic} [GeV];",1000,0.,2000.);

  hCaloMET = new TH1D("MET_c","Calo MET [GeV]",1000, 0., 1000.);
    hMHT = new TH1D("MHT","MHT [GeV]",2000.,0.,2000.);
    hLepPhi = new TH1D("MuPhi",";#phi;",64,-TMath::Pi(),TMath::Pi());
    hLepPt = new TH1D("MuPt",";P_{T} [GeV];",2000,10.,2010.);
    hLepEta = new TH1D("MuEta",";#eta ;",48,-3,3);
    hLepDR = new TH1D("MuDR",";#Delta R;",500,0,2*TMath::Pi()); 
    hMeff = new TH1D("Meff",";Meff [GeV];events",2000,0,2000);
    hLepTrIso  = new TH1D("MuTrIso",";Trk Iso;",2000,0,2.0);
    hLepEIso = new TH1D("MuEIso",";E Iso;",2000,0,2.0);
    hLepHIso = new TH1D("MuHIso","H Iso;",2000,0,2.0);
    hLepCIso =  new TH1D("MuCso",";All Iso;",2000,0,2.0);
     hMuiVHits = new TH1D("MuiVHits",";no Inner Track valid Hits;",50,0,50);
    hMugVHits = new TH1D("MugVHits",";no Global Track valid Hits;",100,0,100);
    hMuC2glob =  new TH1D("MuChi2glob",";norm chi2 global fit;",50,0,10);
    hMuC2tr =  new TH1D("MuChi2inner",";norm chi2 global fit;",50,0,10);
    hMuBD0  = new TH1D("MuBD0",";BS D_{0} cm;",5000,0,0.05);
    hMuVD0 = new TH1D("MuVD0",";VT D_{0} cm;",5000,0,0.05);
    hMuVD0sig = new TH1D("MuVD0Sig",";VT D_{0} #sigma;",500,0,50);
    hMuVDZ = new TH1D("MuVDZ",";V #Delta Z cm;",5000,-10.,10.);
    hMTTrkIso =  new TH2D("MTTrkIso",";M_{T} [GeV];TrkIso",500,0,1000,100,0,10);
    hMuPtHT =  new TH2D("MuPtHT",";p_{T}^{#mu} [GeV];HT [GeV]",1000,0.,1000.,2000,0.,2000.);
    hHTminDR =  new TH2D("HTminDR",";H_{T} [GeV];DR(muon,jet)",2000,0.,2000.,500,0.,2*TMath::Pi());


  
}
// -----------------------------------------------------------------------------
//
bool ControlPlottingOps::Process( Event::Data& ev ) {
  std::vector <Event::Lepton const *> theLepton;

  bool isMu= false;
  bool isLep=false;
  if (ev.LD_CommonMuons().accepted.size() + ev.LD_CommonElectrons().accepted.size() != 0){
    isLep=true;
  if(ev.LD_CommonMuons().accepted.size()>0&&ev.LD_CommonElectrons().accepted.size()==0)
    {
      theLepton = ev.LD_CommonMuons().accepted;
      isMu = true;
    }  

  if(ev.LD_CommonMuons().accepted.size()==0&&ev.LD_CommonElectrons().accepted.size()>0)
    {
      theLepton = ev.LD_CommonElectrons().accepted;
    }  

  if(ev.LD_CommonMuons().accepted.size()>0&&ev.LD_CommonElectrons().accepted.size()>0)
    {
      cout << "WARNING: ttWPlottingOps has common muon AND Electron, it does not know what to plot!!!"<<endl;
       return true;
     }
  //if (theLepton.size()==0)
    // {
      //cout << "  ttWPlottingOps does require at least one lepton: plots not filled "<<endl;
      //return true;
      //  }
  }
  //else {cout << "hadronic only being plotted" << endl;}



  // Event weight
  Double_t weight = ev.GetEventWeight();
  std::vector<Event::Jet const *> jets = ev.JD_CommonJets().accepted;
  UInt_t nj = jets.size();
  
  LorentzV mht = ev.CommonRecoilMET();
  Double_t aThad = ev.HadronicAlphaT();
  Double_t aTlep = ev.LeptonicAlphaT();
  Double_t Meff = ev.CommonHT() + ev.PFMET().Pt();
  
 hNJet->Fill(nj,weight);
 hAlphaT_Had->Fill(aThad,weight);
 hMHT->Fill(mht.Pt(),weight);
 hHT->Fill(ev.CommonHT(),weight);
  hMeff->Fill(Meff,weight);

  int nVertex = 0;
  for(std::vector<float>::const_iterator vtx = ev.vertexSumPt()->begin();vtx != ev.vertexSumPt()->end();++vtx){
    if(!ev.vertexIsFake()->at( vtx-ev.vertexSumPt()->begin()) &&
      fabs((ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Z()) < 24.0 &&
      ev.vertexNdof()->at( vtx-ev.vertexSumPt()->begin() ) > 4 &&
       (ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Rho() < 2.0 ){  nVertex++; }
  }
  hNVertices->Fill(nVertex,weight);

  int nTotVertex = 0;
  for(std::vector<float>::const_iterator vtx = ev.vertexSumPt()->begin();vtx != ev.vertexSumPt()->end();++vtx){ nTotVertex++; }
 
  hNTotVertices->Fill(nTotVertex,weight);


  if (isLep){
  float minDeltaR = 2*TMath::Pi();
  for ( unsigned int i=0; i< ev.JD_CommonJets().accepted.size(); i++ )
    {
      float aminDeltaR = fabs(ROOT::Math::VectorUtil::DeltaR (*(ev.JD_CommonJets().accepted.at(i)),*(theLepton.at(0))));
      if(aminDeltaR<minDeltaR)minDeltaR=aminDeltaR;
    }

  Double_t htlep = ev.CommonHT() + theLepton.at(0)->Pt();
  Double_t aMT =  sqrt(2.0 * ev.PFMET().Pt() * (theLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theLepton.at(0)), ev.PFMET() ) )));
  hLepPhi->Fill(theLepton.at(0)->Phi(),weight);
  hLepPt->Fill(theLepton.at(0)->Pt(),weight);
  hLepEta->Fill(theLepton.at(0)->Eta(),weight);
  hMuPtHT->Fill(theLepton.at(0)->Pt(),ev.CommonHT(),weight);

  hLepDR->Fill(minDeltaR,weight);
  hHTminDR->Fill(ev.CommonHT(),minDeltaR,weight);
  hMT->Fill(aMT,weight);
 
  hAlphaT_Lep->Fill(aTlep,weight);
 
  hHTlep->Fill(htlep,weight);

   hLepTrIso->Fill(((theLepton.at(0))->GetTrkIsolation())/((theLepton.at(0))->Pt()),weight);
   hLepEIso->Fill(((theLepton.at(0))->GetEcalIsolation())/((theLepton.at(0))->Et()),weight);
   hLepHIso->Fill(((theLepton.at(0))->GetHcalIsolation())/((theLepton.at(0))->Et()),weight);
   hLepCIso->Fill((theLepton.at(0))->GetCombIsolation(),weight);
   hMTTrkIso->Fill(aMT,(theLepton.at(0))->GetTrkIsolation(),weight); 

   if(isMu){
    UInt_t iM  = (theLepton.at(0))->GetIndex();
    hMuBD0->Fill( fabs(ev.GetMuonInnerTrackDxyBS(iM)),weight);
    hMuVD0->Fill(fabs(ev.GetMuonInnerTrackDxy(iM)),weight);
    hMuVD0sig->Fill(fabs(ev.GetMuonInnerTrackDxy(iM)/ev.GetMuonInnerTrackDxyError(iM)),weight);
    hMuVDZ->Fill(ev.GetMuonInnerTrackDz(iM),weight);
    hMugVHits->Fill(ev.GetMuonGlobalTracknumberOfValidHits(iM),weight);
    hMuiVHits->Fill(ev.GetMuonInnerTracknumberOfValidHits(iM),weight);
    hMuC2glob->Fill(ev.muonGlobalTrackNormChi2()->at(iM),weight);
    hMuC2tr->Fill(ev.muonInnerTrackNormChi2()->at(iM),weight);

  }
  }


  return true;
}
std::ostream& ControlPlottingOps::Description( std::ostream& ostrm ) {
  ostrm << "Muon Control plots ";
  return ostrm;
}
VertexOp::VertexOp(const std::string & folderName) :
  mFolderName(folderName)
{}

// -----------------------------------------------------------------------------
VertexOp::~VertexOp() {}

// -----------------------------------------------------------------------------
//
void VertexOp::Start( Event::Data& ev ) {
  initDir( ev.OutputFile(), mFolderName.c_str() );
  BookHistos();
}

// -----------------------------------------------------------------------------
//
void VertexOp::BookHistos() {
  TH1::SetDefaultSumw2(kTRUE);

  hNVertices = new TH1D("NVertices", ";N (vertices);", 24, 0., 24.);
  h_recon_NVertices = new TH1D("NVertices_Reco", ";N (vertices);", 24, 0., 24.);


}
// -----------------------------------------------------------------------------
//
bool VertexOp::Process( Event::Data& ev ) {


 Double_t weight = ev.GetEventWeight();
  int nVertex = ev.GetVertexSize();
 int nVertex_r = 0;
  for(std::vector<float>::const_iterator vtx = ev.vertexSumPt()->begin();vtx != ev.vertexSumPt()->end();++vtx){
    if(!ev.vertexIsFake()->at( vtx-ev.vertexSumPt()->begin()) &&
      fabs((ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Z()) < 24.0 &&
      ev.vertexNdof()->at( vtx-ev.vertexSumPt()->begin() ) > 4 &&
       (ev.vertexPosition()->at( vtx-ev.vertexSumPt()->begin())).Rho() < 2.0 ){  nVertex_r++; }
  }
  hNVertices->Fill(nVertex,weight);
  h_recon_NVertices->Fill(nVertex_r,weight);


  return true;
}
std::ostream& VertexOp::Description( std::ostream& ostrm ) {
  ostrm << "NVertex plots ";
  return ostrm;
}



