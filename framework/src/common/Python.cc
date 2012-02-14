/*! \file Python.cc
 * \brief Instantiation of boost python interfaces for this library
 */

//#include "LeptonOps.hh"
#include "CommonOps.hh"
#include "CommonPlottingOps.hh"
//#include "FillABCDMethod.hh"
//#include "HadronicOps.hh"
//#include "LeptonPlottingOps.hh"
#include "MCOps.hh"
//#include "MCPlottingOps.hh"
#include "Filters.hh"
#include "EventDisplay.hh"

#include "Manager.hh"
#include "Utils.hh"

// Python wrapper
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(libFrameworkSUSY) {

  // Mappings (thin wrappers)
  void (Operation::Manager::*add1)(Operation::_Base &) = &Operation::Manager::Add;
  void (Operation::Manager::*add2)(Operation::Tree &) = &Operation::Manager::Add;
  class_<Operation::Manager>("Manager")
      .def("Add",add1) // Add operation
      .def("Add",add2) // Add tree
      .def("Run",&Operation::Manager::Run) // Run the analysis
      .def("AddUserVar",&Operation::Manager::AddUserVar)
      .def("AddJetFilter",&Operation::Manager::AddJetFilter)
      .def("AddMuonFilter",&Operation::Manager::AddMuonFilter)
      .def("AddElectronFilter",&Operation::Manager::AddElectronFilter)
      .def("AddPhotonFilter",&Operation::Manager::AddPhotonFilter) //TW added 23/10/2010
      .def("AddTauFilter",&Operation::Manager::AddTauFilter)
      .def("AddMETFilter", &Operation::Manager::AddMETFilter)
      .def("AddWeightFilter", &Operation::Manager::AddWeightFilter)
      .def("GetNtupleFormat",&Operation::Manager::GetNtupleFormat)
      .def("GetNtupleVersion",&Operation::Manager::GetNtupleVersion)
      .def("FilterNtuple",&Operation::Manager::FilterNtuple)
      ;
  class_<Operation::Tree>("Tree", init<const std::string &>())
    .def("Attach",&Operation::Tree::Attach)
    .def("TAttach",&Operation::Tree::TAttach)
    .def("FAttach",&Operation::Tree::FAttach)
    ;

  // Very important - declare the operation base class as virtual (non-creatable)
  // Otherwise this code won't work with python...
  class_<Operation::_Base, boost::noncopyable>("OP__Base", no_init)
    ;

  class_<Compute::UserBase, boost::noncopyable>("UserBase", no_init)
      ;

  class_<GenericLeptons, bases<Compute::UserBase>, boost::noncopyable>("GenericLeptons", no_init);
  class_<GenericGenObjects, bases<Compute::UserBase>, boost::noncopyable>("GenericGenObjects", no_init);
  class_<Compute::ObjectFilter<Event::Lepton>,
      boost::noncopyable >("LeptonFilter",no_init)
      ;
  class_<Compute::ObjectFilter<Event::Jet>,
      boost::noncopyable >("JetFilter",no_init)
      ;
  //TW added for photon filter 23/10/2010
  class_<Compute::ObjectFilter<Event::Photon>, boost::noncopyable >("PhotonFilter",no_init);

  class_<Compute::ObjectFilter<ICF_LorentzV>,
      boost::noncopyable >("LorentzFilter",no_init)
      ;
  class_<Compute::ObjectFilter<double>, boost::noncopyable >("DoubleFilter",no_init);

  class_<Utils::ParameterSet>("ParameterSet")
      .def("AddDouble",&Utils::ParameterSet::AddDouble)
      .def("AddBool",&Utils::ParameterSet::AddBool)
      .def("AddString",&Utils::ParameterSet::AddString)
      .def("AddInt",&Utils::ParameterSet::AddInt)
      .def("AddStringVector",&Utils::ParameterSet::AddStringVector)
      .def("AddDoubleVector",&Utils::ParameterSet::AddDoubleVector)
      .def("AddIntVector",&Utils::ParameterSet::AddIntVector)
      .def("AddUIntVector",&Utils::ParameterSet::AddUIntVector)

      .def("AddLongIntVector", &Utils::ParameterSet::AddLongIntVector)
      .def("AddBoolVector",&Utils::ParameterSet::AddBoolVector)
      ;

  class_<std::vector<string> >("ICF_StringVector")
      .def(vector_indexing_suite<std::vector<string> >());

  class_<std::vector<double> >("ICF_DoubleVector")
      .def(vector_indexing_suite<std::vector<double> >());

  class_<std::vector<int> >("ICF_IntVector")
      .def(vector_indexing_suite<std::vector<int> >());

  class_<std::vector<unsigned int> >("ICF_UIntVector")
      .def(vector_indexing_suite<std::vector<unsigned int> >());

  class_<std::vector<long> >("ICF_LongIntVector")
      .def(vector_indexing_suite<std::vector<long> >());

  class_<std::vector<bool> >("ICF_BoolVector")
      .def(vector_indexing_suite<std::vector<bool> >());

  ///////////////////////////////////////////////////
  // Operation declarations
  ///////////////////////////////////////////////////
class_<Operation::UnPrescaled, bases<Operation::_Base> >("OP_UnPrescaled",
                                                          init<const std::string &>());
#ifdef _ICF_
  class_<Operation::TriggerCut, bases<Operation::_Base> >("OP_TriggerCut",
                                                          init<const std::string &>());
#endif
#ifdef _NT7_
  class_<Operation::TriggerCut, bases<Operation::_Base> >("OP_TriggerCut",
                                                        init<int>());
#endif

  class_<Operation::TwoTriggerCut, bases<Operation::_Base> >("OP_TwoTriggerCut",
                   init<const std::string &,const std::string &>());

  class_<Operation::TwoTriggerAndCut, bases<Operation::_Base> >("OP_TwoTriggerAndCut",
                   init<const std::string &,const std::string &>());

  class_<Operation::MultiTrigger, bases<Operation::_Base> >("OP_MultiTrigger",
                                                       init<const Utils::ParameterSet &>());

  class_<Operation::TriggersExist, bases<Operation::_Base> >("OP_TriggersExist",
                                                       init<const Utils::ParameterSet &>());

  class_<Operation::Mix2Triggers, bases<Operation::_Base> >("Mix2Triggers",init<int,const std::string &,const std::string &>());
  class_<Operation::Mix3Triggers, bases<Operation::_Base> >("Mix3Triggers",init<int,int,const std::string &,const std::string &,const std::string &>());

  class_<Operation::ThreeTriggerCut, bases<Operation::_Base> >("OP_ThreeTriggerCut",
                   init<const std::string &,const std::string &,const std::string &>());

  class_<Operation::PrintGenParticleInfo,
      bases<Operation::_Base> >("MC_PrintGenParticleInfo",init<const char *>());

  class_<Operation::CutOnUnCorLeadJetPt,bases<Operation::_Base> >("OP_CutOnUnCorLeadJetPt",init<float>());

  class_<Operation::OddElectron, bases<Operation::_Base> >("OP_OddElectron");
  class_<Operation::OddPhoton, bases<Operation::_Base> >("OP_OddPhoton");
  class_<Operation::OddJet, bases<Operation::_Base> >("OP_OddJet");
  class_<Operation::OddMuon, bases<Operation::_Base> >("OP_OddMuon");

 class_<Operation::missedTrCut, bases<Operation::_Base> >("OP_missedTrCut",init<float>());

  class_<Operation::NumComLeptons,
      bases<Operation::_Base> >("OP_NumComLeptons", init<const std::string &,
                                UInt_t>());
  class_<Operation::NumComMuons,
      bases<Operation::_Base> >("OP_NumComMuons", init<const std::string &,
                                UInt_t>());
  class_<Operation::NumComElectrons, bases<Operation::_Base> >("OP_NumComElectrons",
                     init<const std::string &,
                     UInt_t>());

  class_<Operation::NumComTaus, bases<Operation::_Base> >("OP_NumComTaus",
                     init<const std::string &,
                     UInt_t>());

  class_<Operation::NumComPhotons,
      bases<Operation::_Base> >("OP_NumComPhotons",init<const std::string &,
                                UInt_t>());
  class_<Operation::NumComJets,
      bases<Operation::_Base> >("OP_NumComJets", init<const std::string &,
                                UInt_t>());

  class_<Operation::NumCommonBtagJets, bases<Operation::_Base> >("OP_NumCommonBtagJets",
                     init<const std::string &,
                     UInt_t,float>());

  class_<Operation::badMuonInJet, bases<Operation::_Base> >("OP_BadMuonInJet");
  class_<Operation::PhotkilledJet, bases<Operation::_Base> >("OP_PhotonKilledJet");

  class_<Operation::CommonMHTCut, bases<Operation::_Base> >("OP_CommonMHTCut",
              init<float>());

  class_<Operation::secondJetEtCut, bases<Operation::_Base> >("OP_SecondJetEtCut",
                    init<float>());

 class_<Operation::PhotonJetDRCut, bases<Operation::_Base> >("OP_PhotonJetDRCut",
              init<float>());

 //class_<Operation::PhotonPtCut, bases<Operation::_Base> >("OP_PhotonPtCut",
 //                   init<float>());


  class_<Operation::firstJetetaCut, bases<Operation::_Base> >("OP_FirstJetEta",
                 init<float>());

  class_<Operation::RecoilMHTCut,bases<Operation::_Base> >("OP_RecoilMHTCut",init<float>());

  class_<Operation::HTCut, bases<Operation::_Base> >("RECO_CommonHTCut",
                 init<float>());

  class_<Operation::HTLessThanCut, bases<Operation::_Base> >("RECO_CommonHTLessThanCut",
                init<float>());

  class_<Operation::firstJetPtCut, bases<Operation::_Base> >("OP_FirstJetPtCut",
                init<float>());

  class_<Operation::SumETCut, bases<Operation::_Base> >("OP_CommonSumETCut",
                 init<float>());

  class_<Operation::SumETCutMax, bases<Operation::_Base> >("OP_CommonSumETCutMax",
                 init<float>());

  class_<Operation::biasedDPhiCut, bases<Operation::_Base> >("OP_biasedDPhiCut",
                   init<float>());

  class_<Operation::RecoilMET_ov_SumETCut, bases<Operation::_Base> >("OP_RecoilMET_ov_SumETCut",
                     init<float>());

  class_<Operation::AK5CaloMETCut, bases<Operation::_Base> >("OP_AK5CaloMETCut",
                     init<float>());

  class_<Operation::MeffCut,bases<Operation::_Base> >("OP_MeffCut",init<float>());


  class_<Operation::CommonAlphaTCut, bases<Operation::_Base> >("OP_CommonAlphaTCut",
                     init<float>());
  class_<Operation::alpha_tCut, bases<Operation::_Base> >("OP_HadAlphaTCut",
                     init<float>());
  class_<Operation::alpha_tCut_Less, bases<Operation::_Base> >("OP_HadAlphaTCutLess",
                     init<float>());
  class_<Operation::missedHTcut, bases<Operation::_Base> >("OP_MissedHTCut",
                 init<float>());

 class_<Operation::JetMETMinDPhiCut, bases<Operation::_Base> >("OP_JetMETMinDPhiCut",
                 init<float>());

 class_<Operation::Jet1JDphiMETCut, bases<Operation::_Base> >("OP_Jet1JDphiMETCut",
                     init<float>());
  class_<Operation::Jet2JDphiMETCut, bases<Operation::_Base> >("OP_Jet2JDphiMETCutCut",
                 init<float>());
  class_<Operation::Jet3JDphiMETCut, bases<Operation::_Base> >("OP_Jet3JDphiMETCutCut",
                 init<float>());

  class_<Operation::caloMETCut,bases<Operation::_Base> >("OP_caloMETCut",init<float>());

  class_<Operation::tcMETCut,bases<Operation::_Base> >("OP_tcMETCut",init<float>());

#ifdef _ICF_
  class_<Operation::PFMETCut,bases<Operation::_Base> >("OP_PFMETCut",init<float>());
#endif

  /*
  class_<Operation::dphi_muon_commht, bases<Operation::_Base> >("OP_dphi_muon_commht",
                init<float,
                float>());
  class_<Operation::ratio_muon_commht, bases<Operation::_Base> >("OP_ratio_muon_commht",
                 init<float>());
  class_<Operation::CallABCDMethod, bases<Operation::_Base> >("OP_CallABCDMethod",
                     init<const std::string &>());
  */
  class_<Operation::ObjCountPlots, bases<Operation::_Base> >("OP_ObjCountPlots",
                   init<const std::string &,
                   UInt_t>());
  class_<Operation::ObjKinPlots, bases<Operation::_Base> >("OP_ObjKinPlots",
                 init<const std::string &,
                 UInt_t,
                 UInt_t>());
  class_<Operation::kinSuiteComPlot, bases<Operation::_Base> >("OP_KinSuiteComPlot",
                     init<const std::string &,
                     int,
                     int>());
  class_<Operation::CommonPlots, bases<Operation::_Base> >("OP_CommonPlots",
                 init<const std::string &>());
  class_<Operation::ComSearchMatrix, bases<Operation::_Base> >("OP_ComSearchMatrix",
                     init<const std::string &,
                     UInt_t,
                     UInt_t,
                     UInt_t>());
  class_<Operation::ComJetPlots, bases<Operation::_Base> >("OP_ComJetPlots",
                 init<const std::string &,
                 UInt_t>());
  class_<Operation::ComPhoPlots, bases<Operation::_Base> >("OP_ComPhoPlots",
                 init<const std::string &,
                 UInt_t>());
  //class_<Operation::StandardPlots, bases<Operation::_Base> >("OP_StandardPlots",
  //               init<const Utils::ParameterSet &>());
  //class_<Operation::MetPlots, bases<Operation::_Base> >("OP_MetPlots",
  //               init<const Utils::ParameterSet &>());
  class_<Operation::SkimOp,
    bases<Operation::_Base> >("SkimOp", init<const Utils::ParameterSet &>());
  class_<Operation::RA2TrackingFailureFilterCut, bases<Operation::_Base> >("OP_RA2TrackingFailureFilterCut");
  class_<Operation::RA2ecaldeadcellfilterflagCut, bases<Operation::_Base> >("OP_RA2ecaldeadcellfilterflagCut");
    class_<Operation::NoiseFilter, bases<Operation::_Base> >("OP_HadronicHBHEnoiseFilter");
    class_<Operation::beamHaloCSCTightHaloId, bases<Operation::_Base> >("OP_beamHaloCSCTightHaloId");
    class_<Operation::MonsterFilter, bases<Operation::_Base> >("OP_MonsterFilter");
    class_<Operation::GoodEventSelection, bases<Operation::_Base> >("OP_GoodEventSelection");
    class_<Operation::EcalSpikeCleaner, bases<Operation::_Base> >("OP_EcalSpikeCleaner");
    class_<Event::JESUncert, bases<Compute::ObjectFilter<Event::Jet> > >("JESUncert", init<const std::string>());
    class_<Event::VertexReweighting,   bases<Compute::ObjectFilter<double> > >("VertexReweighting",   init<const Utils::ParameterSet &>());
    class_<Event::GoodVertexReweighting,   bases<Compute::ObjectFilter<double> > >("GoodVertexReweighting",   init<const Utils::ParameterSet &>());
    class_<Event::PreScaleReweighting,   bases<Compute::ObjectFilter<double> > >("PreScaleReweighting",   init<const Utils::ParameterSet &>());
                                                                                //scale factor, eta, use parameterisation
    class_<Event::JESCorrections, bases<Compute::ObjectFilter<Event::Jet> > >("JESCorrections",  init<const Utils::ParameterSet &, bool>() )
      .def("Test",&Event::JESCorrections::Test);
    // class_<Event::JetSmear, bases<Compute::ObjectFilter<Event::Jet> > >("JetSmear",  init<const float>() );
  class_<Event::JESCorrectionsTrivial, bases<Compute::ObjectFilter<Event::Jet> > >("JESCorrectionsTrivial", init<float>());
    class_<Event::JetSmear, bases<Compute::ObjectFilter<Event::Jet> > >("JetSmear", init<float, float, float, float, float, float, bool>());
                                                                             // Gaussian width, floor energy, ptlow, ptHigh, etaLow, etaHigh

    class_<Operation::EventDisplay, bases<Operation::_Base> >("OP_EventDisplay",  init<const std::string &, const std::string &>() );

    class_<Operation::BtagResponse, bases<Operation::_Base> >("OP_Btag",init<float,int,int>());

    class_<Operation::EventNoDump, bases<Operation::_Base> >("OP_EventNoDump",  init<const std::string &,const std::string &>());

    class_<Operation::JSONFilter, bases<Operation::_Base> >("JSONFilter", init<const std::string & , const Utils::ParameterSet &>());
    class_<Operation::EventSelector, bases<Operation::_Base> >("EventSelector", init<const Utils::ParameterSet &>());
    class_<Operation::JSONOutput, bases<Operation::_Base> >("JSONOutput", init<const std::string &>());

  /*
  class_<Operation::SingleLepPlots, bases<Operation::_Base> >("OP_SingleLepPlots",
                    init<const std::string &>());

  // Expanded to include property references
  class_<Operation::NumGdLepCut, bases<Operation::_Base> >("OP_NumGdLepCut")
    .add_property("Type",
      &Operation::NumGdLepCut::GetType,
      &Operation::NumGdLepCut::SetType)
    .add_property("Comparison",
      &Operation::NumGdLepCut::GetComparison,
      &Operation::NumGdLepCut::SetComparison)
    .add_property("Number",
      &Operation::NumGdLepCut::GetNumber,
      &Operation::NumGdLepCut::SetNumber)
    ;
  */
}
