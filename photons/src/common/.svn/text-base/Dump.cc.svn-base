#include "Dump.hh"
#include "Photon.hh"
#include "Jet.hh"
#include "EventData.hh"
#include "Math/VectorUtil.h"


namespace Operation {

Dump::Dump(){}

Dump::~Dump(){}

bool Dump::Process( Event::Data& ev )
{
    //std::cout << "Run Number: " << ev.RunNumber() << "; Lumi Section: " << ev.LumiSection() << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    std::cout << "Event Number: " << ev.EventNumber() << std::endl;
    std::cout << "Run Number: " << ev.RunNumber() << std::endl;
    std::cout << "Lumi Section: " << ev.LumiSection() << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    std::cout << "HT = " << ev.CommonHT() << std::endl;
    std::cout << "MHT = " << ev.CommonMHT().Pt() << std::endl;
    std::cout << "MET = " << ev.PFMET() << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    //ev.PrintStableVisRec();
    //ev.PrintStableVisAllRec();
    std::cout << "HLT size = " << ev.hlt()->size() << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    for(std::map<std::string,bool>::const_iterator it =ev.hlt()->begin();
       it!=ev.hlt()->end(); ++it){
      int prescale = ev.hlt_prescaled()->find(it->first)->second;
      std::cout << it->first << " = " << it->second << "(" << prescale << ")" << std::endl;
    }
/*
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
    std::cout << "CrossSection = " << ev.SusyCrossSection() << std::endl;
    std::cout << "mChi0 = " << ev.MChi0() << std::endl;
    std::cout << "mSquark = " << ev.MSquark() << std::endl;
    std::cout << "mGluino = " << ev.MGluino() << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++"<<std::endl;
*/
/*
    std::cout << ev.rechitCaloP4Eb()->size() << std::endl;
    for (std::vector<LorentzV>::const_iterator  it = ev.rechitCaloP4Eb()->begin(); it != ev.rechitCaloP4Eb()->end(); ++it)
    {
      //if (ROOT::Math::VectorUtil::DeltaR( **(ev.PD_CommonPhotons().accepted.begin()), *it ) < 0.4)
      //{
        std::cout << "RecHit pt = " << it->Pt() << std::endl;
        std::cout << "RecHit eta = " << it->Eta() << std::endl;
        std::cout << "RecHit phi = " << it->Phi() << std::endl;
        std::cout << "RecHit time = " << ev.rechitCaloTimeEb()->at(it - ev.rechitCaloP4Eb()->begin()) << std::endl;
        std::cout << "RecHit severity = " << ev.rechitCaloSeverityLevelEb()->at(it - ev.rechitCaloP4Eb()->begin()) << std::endl;
      //}
    }
*/
    return true;
}

std::ostream& Dump::Description( std::ostream& ostrm )
{
    ostrm << "Dump Event Contents";
    return ostrm; 
}

}
