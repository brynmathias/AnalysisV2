#include "Zplots.hh"
#include "ThrustStuff.hh"
#include "GenObject.hh"
#include "GenMatrixBin.hh"
#include "Math/VectorUtil.h"

using namespace Operation;


Zplots::Zplots(const std::string & folderName) :
  mFolderName(folderName)
{}

Zplots::~Zplots() {}

void Zplots::Start(Event::Data & ev) {
  initDir(ev.OutputFile(), mFolderName.c_str());
  BookHistos();
}

void Zplots::BookHistos() {
  TH1::SetDefaultSumw2(kTRUE);
   
  LP_pos = new TH1D("LP_pos",";L_{P}[+];",400,-2.,2.);
  LP_neg = new TH1D("LP_neg",";L_{P}[-];",400,-2.,2.);
  LP_tot = new TH1D("LP_tot",";L_{P}(lep);",400,-2.,2.);
  
  Mass2DP = new TH2D("Mass2Dplus",";PT(#mu^{+});Mass",40,0,1000,100,0,600);
  Mass2DM = new TH2D("Mass2Dminus",";PT(#mu^{-});Mass",40,0,1000,100,0,600);
  MassP  = new TH1D("MassP",";Mass[+];",100,0,600);
  MassM  = new TH1D("MassM",";Mass[-];",100,0,600);
  Mass100P   = new TH1D("Mass100P",";Mass[+];",100,0,600);
  Mass100M  = new TH1D("Mass100M",";Mass[-];",100,0,600);

  MTM  = new TH1D("MTM",";M_{T}^{-};",100,0,600);
  MTP  = new TH1D("MTP",";M_{T}^{+};",100,0,600);
  MTF = new TH1D("MTF",";M_{T}^{st};",100,0,600);
  MTS = new TH1D("MTS",";M_{T}^{nd};",100,0,600);
  MTL  = new TH1D("MTL",";M_{T}(#mus);",100,0,600);


  EtaPhiP= new TH2D("EtaPhiP",";#phi;#eta",6,-TMath::Pi(),TMath::Pi(),6,-2.1,2.1);
  EtaPhiM    = new TH2D("EtaPhiM",";#phi;#eta",6,-TMath::Pi(),TMath::Pi(),6,-2.1,2.1);
}




bool Zplots::Process(Event::Data & ev) {

  
  // check if there is a muon or electron
  
  std::vector <Event::Lepton const *> theRECOLepton;
  bool isMu = false;

  if ( (ev.LD_CommonMuons().accepted.size()>0) && (ev.LD_CommonElectrons().accepted.size()==0) ) {
    theRECOLepton = ev.LD_CommonMuons().accepted;
    isMu = true;
  }
  



  LorentzV Zvec = *(theRECOLepton.at(0)) + *(theRECOLepton.at(1));

  LorentzV ZF = ev.PFMET()+ * (theRECOLepton.at(1)) ;
  double aMTF =  sqrt(2.0 * ZF.Pt() * (theRECOLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), ZF ) )));
  LorentzV ZS = ev.PFMET()+ * (theRECOLepton.at(0)) ;
  double aMTS =  sqrt(2.0 * ZS.Pt() * (theRECOLepton.at(1))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(1)), ZS ) )));
  double aMTL =  sqrt(2.0 * (theRECOLepton.at(1))->Pt()  * (theRECOLepton.at(0))->Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(*(theRECOLepton.at(0)), *(theRECOLepton.at(1)) ) )));
  
 
  MTF->Fill(aMTF,ev.GetEventWeight());
  MTS->Fill(aMTS,ev.GetEventWeight());
  MTL->Fill(aMTL,ev.GetEventWeight());




  
  if (theRECOLepton.at(0)->GetCharge()>0)
    {
      Mass2DP->Fill(theRECOLepton.at(0)->Pt(),Zvec.M(),ev.GetEventWeight());
      if(theRECOLepton.at(0)->Pt()>50&&theRECOLepton.at(0)->Pt()<150)    MassP->Fill(Zvec.M(),ev.GetEventWeight());
      if(theRECOLepton.at(0)->Pt()>150)         Mass100P->Fill(Zvec.M(),ev.GetEventWeight());
      if(Zvec.M()>200) EtaPhiP->Fill(theRECOLepton.at(0)->Phi(),theRECOLepton.at(0)->Eta());    
    }

  else{
    Mass2DM->Fill(theRECOLepton.at(0)->Pt(),Zvec.M(),ev.GetEventWeight());
    if(theRECOLepton.at(0)->Pt()>50&&theRECOLepton.at(0)->Pt()<150)    MassM->Fill(Zvec.M(),ev.GetEventWeight());
    if(theRECOLepton.at(0)->Pt()>150)         Mass100M->Fill(Zvec.M(),ev.GetEventWeight());
    if(Zvec.M()>200) EtaPhiM->Fill(theRECOLepton.at(1)->Phi(),theRECOLepton.at(0)->Eta());
  }


 

  if(theRECOLepton.at(0)->GetCharge()==theRECOLepton.at(1)->GetCharge()) return true;

  LorentzV Pvec;
  if(theRECOLepton.at(0)->GetCharge()>0)
    {
       Pvec = * (theRECOLepton.at(0));
    }
 if(theRECOLepton.at(1)->GetCharge()>0)
    {
      Pvec = * (theRECOLepton.at(1));
    }

 double LPlep = ((Pvec.Px() * Zvec.Px()) + (Pvec.Py() * Zvec.Py())) / (Zvec.Pt() * Zvec.Pt());

 // cout << LPlep <<Pvec.Px()<<" "<< Zvec.Px()<<  endl;
 if(theRECOLepton.at(0)->Pt() + theRECOLepton.at(1)->Pt()>150) LP_tot->Fill(LPlep,ev.GetEventWeight());



 LorentzV Mvec;
 if(theRECOLepton.at(0)->GetCharge()<0)
   {
     Mvec = * (theRECOLepton.at(0));
   }
 if(theRECOLepton.at(1)->GetCharge()<0)
   {
     Mvec = * (theRECOLepton.at(1));
   }
		      
		      
 LorentzV NP = ev.PFMET()+ Mvec  ;
 double aMTP =  sqrt(2.0 * NP.Pt() * Pvec.Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi(Pvec, NP ) )));
 LorentzV pfMET = ev.PFMET() + *(theRECOLepton.at(0)) + *(theRECOLepton.at(1));

 double LPP = (Pvec.Px() * pfMET.Px()) + (Pvec.Py() * pfMET.Py()) / (pfMET.Pt() * pfMET.Pt());
 MTP->Fill(aMTP,ev.GetEventWeight());
 if(theRECOLepton.at(0)->Pt() + theRECOLepton.at(1)->Pt()>150) LP_pos->Fill(LPP,ev.GetEventWeight());

 LorentzV NM = ev.PFMET()+ Pvec  ;

  double aMTM =  sqrt(2.0 * NM.Pt() * Mvec.Pt() * (1.0 - cos(ROOT::Math::VectorUtil::DeltaPhi( Mvec, NM ) )));
  MTM->Fill(aMTM,ev.GetEventWeight());
  double LPM = (Mvec.Px() * pfMET.Px()) + (Mvec.Py() * pfMET.Py()) / (pfMET.Pt() * pfMET.Pt());
 if(theRECOLepton.at(0)->Pt() + theRECOLepton.at(1)->Pt()>150)  LP_neg->Fill(LPM,ev.GetEventWeight());


  return true;
}


std::ostream& Zplots::Description(std::ostream &ostrm) {
  ostrm << "Zplots: " ;
  return ostrm;
}
