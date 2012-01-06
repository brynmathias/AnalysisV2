#include "BkgFromFlip.hh"
#include "KinSuite.hh"
#include "GenObject.hh"
//#include "Gen.hh"
#include <fstream>
#include "stdlib.h"
using namespace Event;
namespace SSDL {

  BkgFromFlip::BkgFromFlip(const std::string & folderName,
			       Utils::ParameterSet &pset
			       ):
    mFolderName(folderName)
  {
    mhtCut=pset.Get<double>("SSMHTCut");
    htCut=pset.Get<double>("SSHTCut");
    leptonCut=pset.Get<double>("LeptonCut");

    mcAnal =bool(pset.Get<double>("McAnal"));

    bin11=pset.Get<double>("pt1eta1");
    bin12=pset.Get<double>("pt1eta2");
    bin13=pset.Get<double>("pt1eta3");
    bin21=pset.Get<double>("pt2eta1");
    bin22=pset.Get<double>("pt2eta2");
    bin23=pset.Get<double>("pt2eta3");
    bin31=pset.Get<double>("pt3eta1");
    bin32=pset.Get<double>("pt3eta2");
    bin33=pset.Get<double>("pt3eta3");
    bin41=pset.Get<double>("pt4eta1");
    bin42=pset.Get<double>("pt4eta2");
    bin43=pset.Get<double>("pt4eta3");
    bin51=pset.Get<double>("pt5eta1");
    bin52=pset.Get<double>("pt5eta2");
    bin53=pset.Get<double>("pt5eta3");

  }

  void BkgFromFlip::Start(Event::Data & ev) {
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();

  }
  BkgFromFlip::~BkgFromFlip() {

  }

  void  BkgFromFlip::BookHistos() {
    histOSDLDE = new TH1D("OppositeSignDoubleLeptonDoubleElectron","",2,0,2);
    histOSDLSE = new TH1D("OppositeSignDoubleLeptonSingleElectron","",2,0,2);
    histSSDLDE_weight = new TH1D("SameSignDoubleLeptonDoubleElectronWeight","",2,0,2);
    histSSDLSE_weight = new TH1D("SameSignDoubleLeptonSingleElectronWeight","",2,0,2);
   }

  bool BkgFromFlip::Process(Event::Data & ev) {
 
 
    float HT=ev.CommonHT();
    // float MHT=ev.CommonMHT().Pt();
    //try the selection with PFMET
    float MHT=ev.PFMET().Pt();
    
    w=ev.GetEventWeight();

    std::vector<const Lepton *> AllLeptons;

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonMuons().accepted.begin();
 	lep!=ev.LD_CommonMuons().accepted.end();++lep){
      AllLeptons.push_back(*lep);
    }

    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonElectrons().accepted.begin();
	lep!=ev.LD_CommonElectrons().accepted.end();++lep){
      if (fabs((**lep).Eta())>2.4) continue;
      AllLeptons.push_back(*lep);
    }

    //    for(vector<Lepton const *>::const_iterator lep=ev.LD_CommonTaus().accepted.begin();
    //   	lep!=ev.LD_CommonTaus().accepted.end();++lep){
    //      AllLeptons.push_back(*lep);
    //    }
    
    //    sort((AllLeptons).begin(), (AllLeptons).end(), compareLepPt);
    uint NLEPTONS=AllLeptons.size();

    int chProd=-1;
    if (AllLeptons.size()>1)
      chProd=int(AllLeptons[0]->GetCharge()*AllLeptons[1]->GetCharge());

    
    vector<bool> CUTS;

    //CUT LIST
    CUTS.push_back((NLEPTONS>leptonCut));
    //IN THIS PARTICULAR FILE WE ARE LOOKING FOR OPPOSITE SIGN LEPTONS 
    CUTS.push_back((chProd<0));
    CUTS.push_back((HT>htCut));
    CUTS.push_back(MHT>mhtCut);

    bool DECISION=true;

    for (uint i=0; i<CUTS.size();i++)
      DECISION= (DECISION&&CUTS[i]);

    //////////////////
    if (DECISION){
      uint first=0,second=0;
      float pt1=0,pt2=0;
      bool firstel=false,secondel =false;
      for(uint i=0; i<NLEPTONS; i++){
	if(AllLeptons[i]->Pt() > pt1){
	  pt1 = AllLeptons[i]->Pt();
	  first = i;
	}
	if(AllLeptons[i]->Pt() > pt2 && AllLeptons[i]->Pt() < pt1){
	  pt2 = AllLeptons[i]->Pt();
	  second = i;
	}
      }
      
      if(AllLeptons[first]->GetType()==1)
	firstel=true;
      if(AllLeptons[second]->GetType()==1)
	secondel=true;
      double wpf = 0;
      double wps = 0;
      if(firstel && secondel){
	///////////opdlel
	wpf = Weight(AllLeptons[first]->Pt(),AllLeptons[first]->Eta());
	wps = Weight(AllLeptons[second]->Pt(),AllLeptons[second]->Eta());
	histOSDLDE->Fill(1,w);
	histSSDLDE_weight->Fill(1,w*(wps+wpf-wps*wpf));
      }
      else if( firstel || secondel){
	///////opdlsel
	wpf = Weight(AllLeptons[first]->Pt(),AllLeptons[first]->Eta());
	wps = Weight(AllLeptons[second]->Pt(),AllLeptons[second]->Eta());
	histOSDLSE->Fill(1,w);
	histSSDLSE_weight->Fill(1,w*(wpf+wps));
      }
    }
    ///////////////////////

    return DECISION;
  } // end of Process method

  std::ostream& BkgFromFlip::Description(std::ostream &ostrm) {
    ostrm << "BkgFromFlip plots made here: (histograms in ";
    ostrm << mFolderName << ")";
    return ostrm;
  }

  double BkgFromFlip::Weight(double pt, double eta){
    int ptbin=0,etabin;
    double out = 0, w=0;
    if(pt >= 5 && pt < 10)
      ptbin = 1;
    else if(pt >= 10 && pt < 20)
      ptbin = 2;
    else if(pt >= 20 && pt < 40)
      ptbin = 3;
    else if(pt >= 40 && pt < 70)
      ptbin = 4;
    else if(pt >= 70)
      ptbin = 5;
    if(fabs(eta) < 0.8 )
      etabin = 1;
    else if(fabs(eta) >= 0.8 && fabs(eta) < 1.6)
      etabin = 2;
    else if(fabs(eta) >= 1.6 && fabs(eta) < 2.4)
      etabin = 3;

    if(ptbin == 1 && etabin == 1)
      out = bin11;
    else if(ptbin == 1 && etabin == 2)
      out = bin12;
    else if(ptbin == 1 && etabin == 3)
      out = bin13;
    else if(ptbin == 2 && etabin == 1)
      out = bin22;
    else if(ptbin == 2 && etabin == 2)
      out = bin22;
    else if(ptbin == 2 && etabin == 3)
      out = bin23;
    else if(ptbin == 3 && etabin == 1)
      out = bin31;
    else if(ptbin == 3 && etabin == 2)
      out = bin32;
    else if(ptbin == 3 && etabin == 3)
      out = bin33;
    else if(ptbin == 4 && etabin == 1)
      out = bin41;
    else if(ptbin == 4 && etabin == 2)
      out = bin42;
    else if(ptbin == 4 && etabin == 3)
      out = bin43;
    else if(ptbin == 5 && etabin == 1)
      out = bin51;
    else if(ptbin == 5 && etabin == 2)
      out = bin52;
    else if(ptbin == 5 && etabin == 3)
      out = bin53;
    w=out/(1-out);
    return out;
  }
}












