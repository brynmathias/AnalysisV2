#include "DeadECALDR.hh"

struct DrCellLVec{
  double Dr;
  unsigned int nCells;
  DrCellLVec(double Dr_,const unsigned int& nCells_)

    : Dr(Dr_), nCells(nCells_) {}
};

struct sort_by_Dr
{
  bool operator () (const DrCellLVec& lhs , const DrCellLVec& rhs) // replace YourStruct
  {
    return lhs.Dr < rhs.Dr;
  }
};


double DeadECALDR( Event::Data& ev,float jetphi,float jeteta, unsigned int nBad){
  // We no longer want to only look to see if the jet falls into an area with 1 bad cell above some configureable threshold.
  // Instead we want to look if the jet has more than some configureable number of dead cells with in dR 0.3
  double DRmin = 100;
  TLorentzVector testjetVec(0,0,0,0);
  TLorentzVector testVec(0,0,0,0);
  int idx = 0;
  unsigned int nBadCells = 0;
  testjetVec.SetPtEtaPhiE(100,jeteta,jetphi,100);
  std::vector< DrCellLVec > DrList;

  // First loop calculates DR and stores the number of bad cells
  for(std::vector<PolarLorentzV>::const_iterator ii=ev.ecalDeadTowerTrigPrimP4()->begin();ii!=ev.ecalDeadTowerTrigPrimP4()->end();++ii,++idx){
    testVec.SetPtEtaPhiE(100,(*ii).Eta(),(*ii).Phi(),100);
    DrCellLVec EventInfo( fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec)) , ev.ecalDeadTowerNBadXtals()->at(idx) );
    DrList.push_back(  EventInfo );
  }

  //Sort the container
  std::sort(DrList.begin(),DrList.end(),sort_by_Dr());

  // Sum up all the dead Cells with in 0.3 of jet
  for( unsigned int entry = 0; entry < DrList.size(); entry++){
    if( DrList[entry].Dr > 0.3 ) break;
    nBadCells += DrList[entry].nCells;
  }

  // Loop though the sorted list
  for( unsigned int test = 0; test < DrList.size(); test++){
    // std::cout << "Looking though the vector of sorted DeadEcal Region Info, Dr is " << DrList[test].Dr << " Number of bad Cells is " << DrList[test].nCells << " The Total BadCells is "<< nBadCells <<std::endl;
    // Iff the total number of dead cells is > Cut, check the dR to all cells with in 0.3 dR  and find the min.
    if( DrList[test].Dr < 0.3  && nBadCells > nBad){
      if(DrList[test].Dr < DRmin) DRmin = DrList[test].Dr;
    }
  }
  // cout << " The Min DeadEcalDR is " << DRmin << endl;
  return DRmin;
}

double NoisyECALRecHitDR( Event::Data& ev,float jetphi,float jeteta, int status){

  double DRmin = 100;
  TLorentzVector testjetVec(0,0,0,0);
  TLorentzVector testVec(0,0,0,0);
  int idx = 0;

  testjetVec.SetPtEtaPhiE(100,jeteta,jetphi,100);

  for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Eb()->begin();ii!=ev.rechitCaloP4Eb()->end();++ii,++idx){
    if(ev.rechitCaloSeverityLevelEb()->at(idx) > status && (*ii).Et() > 20){
      testVec.SetPtEtaPhiE(100,(*ii).Eta(),(*ii).Phi(),100);
      float DR = fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec));
      if(DR < DRmin) DRmin = DR;

    }
  }
  idx = 0;
  for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Ee()->begin();ii!=ev.rechitCaloP4Ee()->end();++ii,++idx){
    if(ev.rechitCaloSeverityLevelEe()->at(idx) > status && (*ii).Et() > 20){

      testVec.SetPtEtaPhiE(100,(*ii).Eta(),(*ii).Phi(),100);
      float DR = fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec));
      if(DR < DRmin) DRmin = DR;

    }
  }


  return DRmin;


}


double NoisyHCALRecHitDR( Event::Data& ev,float jetphi,float jeteta, int status){

  double DRmin = 100;
  TLorentzVector testjetVec(0,0,0,0);
  TLorentzVector testVec(0,0,0,0);
  int idx = 0;

  testjetVec.SetPtEtaPhiE(100,jeteta,jetphi,100);

  for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Hbhe()->begin();ii!=ev.rechitCaloP4Hbhe()->end();++ii,++idx){
    if(ev.rechitCaloSeverityLevelHbhe()->at(idx) > status && (*ii).Et() > 20){
      testVec.SetPtEtaPhiE(100,(*ii).Eta(),(*ii).Phi(),100);
      float DR = fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec));
      if(DR < DRmin) DRmin = DR;

    }
  }
  idx = 0;
  for(std::vector<PolarLorentzV>::const_iterator ii=ev.rechitCaloP4Hf()->begin();ii!=ev.rechitCaloP4Hf()->end();++ii,++idx){
    if(ev.rechitCaloSeverityLevelHf()->at(idx) > status && (*ii).Et() > 20){

      testVec.SetPtEtaPhiE(100,(*ii).Eta(),(*ii).Phi(),100);
      float DR = fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec));
      if(DR < DRmin) DRmin = DR;

    }
  }


  return DRmin;


}


Double_t DeadECALDR_File(TString deadECALfile,float jetphi,float jeteta, int nBad){
  // cout << " hi ho " << deadECALfile << endl;
  TLorentzVector testjetVec(0,0,0,0);
  double DRmin = 100;
  testjetVec.SetPtEtaPhiE(100,jeteta,jetphi,100);

  //cout << " in dead ecal " << endl;
  ifstream myfile(deadECALfile);
  if(!myfile.good()) cout << "file is not there " << endl;
  if(myfile.is_open()){

    while(!myfile.eof()){

      float phi,eta;
      int iEta,iPhi,nBadCells;
      myfile>>eta;
      myfile>>phi;
      myfile>>iEta;
      myfile>>iPhi;
      myfile>>nBadCells;
      // cout <<eta<< " "<< phi<<endl;
      if(nBadCells >= nBad){
        TLorentzVector testVec(0,0,0,0);
        testVec.SetPtEtaPhiE(100,eta,phi,100);
        float DR = fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec));
        if(DR < DRmin) DRmin = DR;
      }
    }

    myfile.close();
  }
  return DRmin;

}

