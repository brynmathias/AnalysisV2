#include "NLOTools.hh"
#include "AlphaT.hh"
#include "CommonOps.hh"
#include "EventData.hh"
#include "GenMatrixBin.hh"
#include "Jet.hh"
#include "KinSuite.hh"
#include "Lepton.hh"
#include "Math/VectorUtil.h"
#include "Photon.hh"
#include "TH1D.h"
#include "TH2D.h"
#include "Types.hh"
#include <sstream>
#include <string>
#include <iomanip>

#include <strstream>
#include <iostream>
#include <fstream>


#include "JetData.hh"
#include "CommonOps.hh"


using namespace Operation;


double NLO::ISRProducer(Event::Data& ev){

  // double x = 0;

  LorentzV newPart(0.,0.,0.,0.);

  // cout << " new  " << endl;
  for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();  j != ev.GenParticles().end(); ++j) {


    if((fabs((*j).GetMotherID()) == 21 || fabs((*j).GetMotherID()) <=6 ) && (*j).GetStatus() == 3 ){


      if( (fabs((*j).GetID()) >= 1000001 && fabs((*j).GetID()) <= 1000045) ||
    (fabs((*j).GetID()) >= 2000001 && fabs((*j).GetID()) <= 2000016) ||
    fabs((*j).GetID()) == 1000021 ){


  newPart = newPart+(*j);
  //  cout << " id " << (*j).GetID() << " status " << (*j).GetStatus() << " single pt " << (*j).Pt() << endl;

      }
    }

  }
  // cout << " newpart " << newPart.Pt() << endl;
  return newPart.Pt();
}


NLO::SUSYProcess NLO::GetProcess(Event::Data& ev){

  bool verbose = false;

  int squarks = 0;
  int antisquarks = 0;
  int gluinos = 0;
  int sleptons = 0;
  int neutralinos = 0;
  int charginos = 0;
  int sbottoms = 0;
  int stops = 0;


  SUSYProcess process = NotFound;

  for (std::vector<Event::GenObject>::const_iterator j = ev.GenParticles().begin();  j != ev.GenParticles().end(); ++j) {


    if(fabs((*j).GetMotherID()) == 21 || fabs((*j).GetMotherID()) <=6  ){

      //select squarks
      if( ((*j).GetID() >= 1000001 && (*j).GetID() <= 1000004) ||
      ((*j).GetID() >= 2000001 && (*j).GetID() <= 2000004) ){
        squarks++;
      }
      //select antisquarks
      if( ((*j).GetID() <= -1000001 && (*j).GetID() >= -1000004) ||
      ((*j).GetID() <= -2000001 && (*j).GetID() >= -2000004) ){
        antisquarks++;
      }
      if( fabs((*j).GetID()) == 1000005 || fabs((*j).GetID()) == 2000005)sbottoms++;
      if( fabs((*j).GetID()) == 1000006 || fabs((*j).GetID()) == 2000006)stops++;


      //select gluinos
      if( fabs((*j).GetID()) == 1000021 )gluinos++;

      //select sleptons
      if( (fabs((*j).GetID()) >= 1000011 && fabs((*j).GetID()) <= 1000016) ||
        (fabs((*j).GetID()) >= 2000011 && fabs((*j).GetID()) <= 2000016))sleptons++;
      //select neutralinos
      if( fabs((*j).GetID()) == 1000022 || fabs((*j).GetID()) == 1000023 ||  fabs((*j).GetID()) == 1000025 || fabs((*j).GetID()) == 1000035 ||  fabs((*j).GetID()) == 1000045  )neutralinos++;

      if( fabs((*j).GetID()) == 1000024 || fabs((*j).GetID()) == 1000037  )charginos++;

    }
  }





  if((neutralinos + charginos) == 1 && gluinos == 1) process = ng;
  if((neutralinos + charginos) == 1 && (squarks + antisquarks) == 1) process = ns;
  if(neutralinos + charginos == 2) process = nn;
  if(sleptons == 2) process = ll;
  if(squarks ==1 && antisquarks == 1) process = sb;
  if(squarks == 2) process = ss;
  if(stops == 2 ) process = tb;
  if(sbottoms == 2) process = bb;
  if(gluinos == 2) process = gg;
  if(squarks + antisquarks + sbottoms + stops == 1 && gluinos == 1) process = sg;
  if (process == NotFound) verbose = true;
  if(verbose) cout << " Process = "  <<  process << endl;
 if(verbose == true)cout << " neutralinos " << neutralinos << "\n charginos " << charginos << "\n gluinos " << gluinos << "\n squarks " << squarks << "\n antisquarks " << antisquarks << "\n sleptons " << sleptons << "\n stops " << stops << "\n sbottoms " << sbottoms << endl;
  return process;
}



