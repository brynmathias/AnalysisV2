/*! \file HadronicTriggerOps.cc
 * \brief Implementation of the hadronic trigger operations.
 */
#include "HadronicTriggerOps.hh"

#include "EventData.hh"

namespace Operation {

  DataTriggerOp::DataTriggerOp(const Utils::ParameterSet& ps)
  // :
  //folderName_(folderName_)
  {
    verb_ = ps.Get<bool>("Verbose");
    triggers_ = ps.Get<std::vector<std::string> >("Triggers");      
  }

  void DataTriggerOp::Start(Event::Data& ev) { 
    //initDir(ev.OutputFile(),folderName_.c_str());
    //BookHistos();
    if (verb_) {
      std::cout << "[DataTriggerOp]: We're looking for: ";
      for (std::vector<std::string>::const_iterator it = triggers_.begin();it!=triggers_.end();++it) std::cout<<(*it)<<" ";
      std::cout<<std::endl;
    }
  }

  bool DataTriggerOp::Process(Event::Data& ev) {
    if (verb_) std::cout<<"[HadronicTriggerOp]: Starting process..."<<std::endl;

    if (verb_) {//list the triggers present in the event...
      std::cout << "[DataTriggerOp]: Triggers present in the event:"<<std::endl;
      std::map<std::string,bool>::const_iterator trig = ev.hlt()->begin();
      std::map<std::string,int>::const_iterator prescale = ev.hlt_prescaled()->begin();
      for (;trig!=ev.hlt()->end(); ++trig, ++prescale) {
        std::cout << "--->"<<trig->first<<", "<<trig->second<<": "<<prescale->first<<", prescale = "<<prescale->second<<std::endl;
      }
      std::cout<<std::endl<<std::endl;
    }//

    std::vector<std::string>::const_iterator it = triggers_.begin();
    for (; it!=triggers_.end(); ++it) {
      //find the trigger entry in the hlt map
      std::map<std::string, bool>::const_iterator trig = ev.hlt()->find(*it);
      //find the trigger prescale value in the hlt_prescale map
      std::map<std::string, int>::const_iterator prescale = ev.hlt_prescaled()->find(*it);
      //
      //now check that the trigger is present AND that it is prescaled
      if (
           (trig!=ev.hlt()->end()                && trig->second)          //(trigger present AND triggered)
           &&                                                              //AND
           (prescale!=ev.hlt_prescaled()->end()  && prescale->second == 1) //(trigger present AND unprescaled)
         )
      {
        if (verb_) {
          std::cout<<"[DataTriggerOp]: TRIGGER PASSED!!!!"<<std::endl;
          std::cout<<"---* "<<trig->first<<" ("<<prescale->first<<"): "<<trig->second<<", prescale = "<<prescale->second<<std::endl;
        }
        return true; //we have a winner!
      }
    }//end of loop over triggers provided in the operation parameter set "Triggers" vector.
    if (verb_) std::cout<<"[DataTriggerOp]: TRIGGER FAILED :-("<<std::endl;
    return false; //if we make it to here, no unscaled triggers found, event fails :-(
  }//end of DataTriggerOp Process method.

  std::ostream& DataTriggerOp::Description(std::ostream& ostrm) {
    ostrm << "DataTriggerOp";
    return ostrm;
  }


  MCTriggerOp::MCTriggerOp(const Utils::ParameterSet& ps)
  // :
  //folderName_(folderName_)
  {
    verb_ = ps.Get<bool>("Verbose");
    jetPt_ = ps.Get<double>("JetPtCut"); 
    htCut_ = ps.Get<double>("HTCut");      
  }

  void MCTriggerOp::BookHistos() {
  }

  void MCTriggerOp::Start(Event::Data& ev) { 
    //initDir(ev.OutputFile(),folderName_.c_str());
    //BookHistos();
    if (verb_) {
      std::cout << "[MCTriggerOp]: We're looking for: ";
      //for (std::vector<std::string>::const_iterator it = triggers_.begin();it!=triggers_.end();++it) std::cout<<(*it)<<" ";
      std::cout<<std::endl;
    }
  }

  bool MCTriggerOp::Process(Event::Data& ev) {
    if (verb_) std::cout<<"[MCTriggerOp]: Starting process..."<<std::endl;

    //get the IC5 secondary jet collection...
    if (verb_) std::cout<<"Secondary jet pts: ";
    double ht = 0.;
    std::vector<Event::Jet>::const_iterator j2it = ev.JD_SecJets().begin();
    for (; j2it!=ev.JD_SecJets().end(); ++j2it) {
        if (verb_) std::cout<<j2it->Pt()<<" ";
        if (j2it->Et()>jetPt_) ht += j2it->Et(); //trigger HLT uses ET of jets?
    }
    if (verb_) std::cout<<std::endl;
    if (verb_) {
      std::cout<<"HT(jets>"<<jetPt_<<"GeV) = "<<ht<<": ";
      ht>htCut_ ? std::cout<<"PASSES!" : std::cout<<"FAILS!";
      std::cout<<std::endl;
    }
    return (ht>htCut_);
  }//end of MCTriggerOp Process method.

  std::ostream& MCTriggerOp::Description(std::ostream& ostrm) {
    ostrm << "MCTriggerOp (uncorrected IC5 jets(pt>"<<jetPt_<<"GeV) HT>"<<htCut_<<")";
    return ostrm;
  }




  BabyVertexPlot::BabyVertexPlot(const Utils::ParameterSet& ps)
  // :
  //folderName_(folderName_)
  {
    folderName_ = ps.Get<std::string>("FolderName");
  }

  void BabyVertexPlot::BookHistos() {
    hg_goodVertices_ = new TH1D("goodVertices","",6,0.,6.);

    hg_vx1_goodJetMultiplicity_ = new TH1D("vx1_goodJetMultiplicity","",10,0.,10.);
    hg_vx1_babyJetMultiplicity_ = new TH1D("vx1_babyJetMultiplicity","",10,0.,10.);
    hg_vx2plus_goodJetMultiplicity_ = new TH1D("vx2plus_goodJetMultiplicity","",10,0.,10.);
    hg_vx2plus_babyJetMultiplicity_ = new TH1D("vx2plus_babyJetMultiplicity","",10,0.,10.);

    hg_goodVertices_babyjets_ = new TH2D("goodVertices_vs_babyJets","",10,0.,10.,15,0.,15.);

  }

  void BabyVertexPlot::Start(Event::Data& ev) { 
    initDir(ev.OutputFile(),folderName_.c_str());
    BookHistos();
  }

  bool BabyVertexPlot::Process(Event::Data& ev) {
    //count number of good vertices in the event (separation??)
    UInt_t numGoodVertices = 0;
    for( int i = 0; i<ev.GetVertexSize(); i++) {
      if (
          !ev.GetvertexIsFake(i) &&
          fabs(ev.GetvertexPosition(i).Z()) < 24.0 &&
          ev.GetvertexNdof(i)> 4 &&
          ev.GetvertexPosition(i).Rho() < 2.0
         ) 
      {
        numGoodVertices++;
      }
    } //end of loop over vertices.

    //determine good jet multiplicity
    UInt_t goodJetMultiplicity = ev.JD_CommonJets().accepted.size();

    //determine babyjet multiplicity
    UInt_t babyJetMultiplicity = ev.JD_CommonJets().baby.size();

    hg_goodVertices_babyjets_->Fill(numGoodVertices,babyJetMultiplicity,ev.GetEventWeight());

    if (numGoodVertices==1) {
      hg_vx1_goodJetMultiplicity_->Fill(goodJetMultiplicity, ev.GetEventWeight());
      hg_vx1_babyJetMultiplicity_->Fill(babyJetMultiplicity, ev.GetEventWeight());
    }
    else if (numGoodVertices>=2) {
      hg_vx2plus_goodJetMultiplicity_->Fill(goodJetMultiplicity, ev.GetEventWeight());
      hg_vx2plus_babyJetMultiplicity_->Fill(babyJetMultiplicity, ev.GetEventWeight());
    }

    return true;
  }//end of BabyVertexPlot Process method.

  std::ostream& BabyVertexPlot::Description(std::ostream& ostrm) {
    ostrm << "BabyVertexPlot";
    return ostrm;
  }

}
