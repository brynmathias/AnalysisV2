#include "lepvalYields.hh"

using namespace Event;
namespace lepval {
  //================================
  // Good Jet Trigger Operation
  //================================
  //
  lepvalYields::lepvalYields(const std::string & folderName,  Utils::ParameterSet &pset):
    mFolderName(folderName){
    triggerBits_.clear();
   
    
    
    for (int i=1;i<11;i++){
      char htn[20];
      sprintf(htn,"%s%d","TriggerBits.bit",i);
      if (pset.Get<string>(htn)==""){
	continue;
      }
      
      triggerBits_.push_back(pset.Get<string>(htn));
   
    }
    
    
  } // end of SSDLTrigger constructor.
  
  
  void lepvalYields::Start(Event::Data & ev) {
    
    initDir(ev.OutputFile(), mFolderName.c_str());
    BookHistos();
    
  }
  
  
  lepvalYields::~lepvalYields() {}
  
  bool lepvalYields::Process(Event::Data & ev) {
    std::map<int, int> trig_prescales;//need to be careful to match these to the PSet TriggerBit list
    trig_prescales[0]=1;
    trig_prescales[1]=1;
    trig_prescales[2]=1;
    trig_prescales[3]=1;
    trig_prescales[4]=1;
    trig_prescales[5]=20;
    trig_prescales[6]=500;
    trig_prescales[7]=1000;
    trig_prescales[8]=100;
    trig_prescales[9]=1;
    
//     trig_prescales[0]=1;
//     trig_prescales[1]=1;
//     trig_prescales[2]=1;
//     trig_prescales[3]=1;
//     trig_prescales[4]=500;
//     trig_prescales[5]=1000;
//     trig_prescales[6]=100;
//     trig_prescales[7]=1;

    //double HTCut[4]={80.,100.,120.,150.};
    for (std::vector<std::string>::const_iterator it=triggerBits_.begin(); it!=triggerBits_.end(); ++it){
      //  std::cout<<*it<<std::endl;
      
      if((ev.hlt()->find(*it)->second)){
	TriggerYields->Fill((it-triggerBits_.begin()), ev.GetEventWeight()/trig_prescales[it-triggerBits_.begin()]);
	
	if(ev.CommonHT()>=80.){
	  TriggerYields_wHtCut80->Fill((it-triggerBits_.begin()), ev.GetEventWeight()/trig_prescales[it-triggerBits_.begin()]);
	}
	if(ev.CommonHT()>=100.){
	  TriggerYields_wHtCut100->Fill((it-triggerBits_.begin()), ev.GetEventWeight()/trig_prescales[it-triggerBits_.begin()]);
	}
	if(ev.CommonHT()>=120.){
	  TriggerYields_wHtCut120->Fill((it-triggerBits_.begin()), ev.GetEventWeight()/trig_prescales[it-triggerBits_.begin()]);
	}
	if(ev.CommonHT()>=150.){
	  TriggerYields_wHtCut150->Fill((it-triggerBits_.begin()), ev.GetEventWeight()/trig_prescales[it-triggerBits_.begin()]);
	}
      }      
    }
      //sanity check
    TriggerYields->Fill(11, ev.GetEventWeight());
    TriggerYields_wHtCut80->Fill(11, ev.GetEventWeight());
    TriggerYields_wHtCut100->Fill(11, ev.GetEventWeight());
    TriggerYields_wHtCut120->Fill(11, ev.GetEventWeight());
    TriggerYields_wHtCut150->Fill(11, ev.GetEventWeight());
    
      
      
      
      
      return true;
    }
    //////////////////////////////
    void  lepvalYields::BookHistos(){
    
    TriggerYields = new TH1D("TriggerYields", "TriggerYields", 12, -0.5, 11.5);
    TriggerYields_wHtCut80 = new TH1D("TriggerYields_Ht80", "TriggerYields_Ht80", 12, -0.5,11.5);
    TriggerYields_wHtCut100 = new TH1D("TriggerYields_Ht100", "TriggerYields_Ht100", 12, -0.5, 11.5);
    TriggerYields_wHtCut120 = new TH1D("TriggerYields_Ht120", "TriggerYields_Ht120", 12, -0.5, 11.5);
    TriggerYields_wHtCut150 = new TH1D("TriggerYields_Ht150", "TriggerYields_Ht150", 12, -0.5, 11.5);
    }
  ///////////////////////////////
  std::ostream& lepvalYields::Description(std::ostream &ostrm) {
    ostrm << "lepval trigger and cut yields"<<std::endl;
    return ostrm;
  }
  } //~namespace lepval
  
  
