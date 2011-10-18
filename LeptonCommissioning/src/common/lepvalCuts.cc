#include "lepvalCuts.hh"

namespace lepval{

  LepValHT_Cut::LepValHT_Cut(double htcut) :
    _htcut(htcut){}

  LepValHT_Cut::~LepValHT_Cut(){}

  bool LepValHT_Cut::Process(Event::Data& ev){
    bool cutpassed = false;
    cutpassed = ev.CommonHT()>=_htcut;
    //   map<std::string,bool> trigmap = (*ev.hlt());
//     for(map<std::string,bool>::const_iterator it = trigmap.begin(); it!=trigmap.end(); ++it){

//       std::cout << it->first << std::endl;
//     }
    return cutpassed;
  }

  std::ostream& LepValHT_Cut::Description(std::ostream& ostrm){
    ostrm<<"Lepton validation HT cut >= " << _htcut <<" GeV"<<std::endl;
    return ostrm;
  }
}
