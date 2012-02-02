#include "lepvalTrigger.hh"

namespace lepval{

  LepValTrigger::LepValTrigger(const std::string& triggername) :
  mTriggername(triggername){}
  LepValTrigger::~LepValTrigger(){}

  bool LepValTrigger::Process(Event::Data& ev){
    bool trigpassed = false;
    // trigpassed = (map<std::string,bool>(*ev.hlt()))[mTriggername]; THIS RETURNS TRUE IF THE TRIGGERNAME IS WRONG OR DOESN'T EXIST - better to use find

    trigpassed = (ev.hlt()->find(mTriggername)->second);
    
//     for (std::map<std::string,bool>::const_iterator it = (*ev.hlt()).begin(); it != (*ev.hlt()).end(); ++it){

//        std::cout<<it->first<<"  "<<it->second<<std::endl;

    
//     }

    return trigpassed;
}

  std::ostream& LepValTrigger::Description(std::ostream& ostrm){

    ostrm<<"Lepton validation trigger is "<< mTriggername << std::endl;
    return ostrm;
}

}
