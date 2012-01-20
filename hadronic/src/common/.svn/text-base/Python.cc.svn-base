#include <boost/python.hpp>
#include "HadronicOps.hh"
#include "HadronicPlottingOps.hh"
#include "BrynPlottingOps.hh"
#include "TanjaCCControlPlots.hh"
#include "BkgdEstPlottingOps.hh"
#include "ISRPlottingOps.hh"
#include "PdfPlottingOps.hh"
#include "EWKbkgClassesPlotOps.hh"
#include "JetMetPasPlottingOps.hh"
#include "HadronicCommonPlots.hh"
#include "IDFilters.hh"
#include "HadronicTools.hh"
#include "DiagnosticOps.hh"
#include "HadronicTriggerOps.hh"
#include "QcdBkgdEst.hh"
#include "examplePlotOps.hh"
#include "hadFilters.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libHadronic) {

    class_<Event::AddJetEnergy, bases<Compute::ObjectFilter<Event::Jet> > >("JetAddition", init<float>());

  class_<Operation::examplePlotOps, bases<Operation::_Base> >( "OP_examplePlots",
                                                                 init<const Utils::ParameterSet&>() );

  class_<Operation::gensignalProcessID, bases<Operation::_Base> >( "gensignalProcessID",  init<int,int,int,int>() );

  class_<Operation::genProcess, bases<Operation::_Base> >( "genProcess",  init<const std::string &>() );

  class_<Operation::HadronicHT_SecondJetCut, bases<Operation::_Base> >( "OP_JetCut_HTCut",  init<float,float>() );
  class_<Operation::HadronicAlphaT, bases<Operation::_Base> >( "HadronicAlphaT",  init<float>() );

  class_<Operation::HadronicCut, bases<Operation::_Base> >( "HadronicCut",  init<float>() );

  class_<Operation::HadronicPlottingOps, bases<Operation::_Base> >( "HadronicPlottingOps",
                    init<const Utils::ParameterSet&>() );

class_<Operation::EWKbkgClassesPlotOps, bases<Operation::_Base> >( "OP_EWKbkgClassesPlotOps",
                     init<const std::string &>() );
class_<Operation::PlotPhotons, bases<Operation::_Base> >( "OP_PlotPhotons",
                     init<const std::string &>() );

 class_<Operation::BrynPlottingOps, bases<Operation::_Base> >( "BrynPlottingOps",
                init<const Utils::ParameterSet&>() );

  class_<Operation::TanjaCCControlPlots, bases<Operation::_Base> >( "OP_TanjaCCControlPlots",
                    init<const Utils::ParameterSet&>() );

  class_<Operation::BkgdEstPlottingOps, bases<Operation::_Base> >( "OP_BkgdEstPlottingOps",
                    init<const Utils::ParameterSet&>() );



  class_<Operation::ISRPlottingOps, bases<Operation::_Base> >( "OP_ISRPlottingOps",
                    init<const Utils::ParameterSet&>() );



  class_<Operation::HadronicCommonPlots, bases<Operation::_Base> >( "HadronicCommonPlots",
                   init<const Utils::ParameterSet&>());


  class_<Operation::JetMetPasPlottingOps, bases<Operation::_Base> >( "JetMetPasPlottingOps",
                    init<const Utils::ParameterSet&>() );


  class_<Operation::UnCorrCut, bases<Operation::_Base> >("OP_UnCorLeadJetCut",init<float>() );



  class_<Operation::DeadECALCut, bases<Operation::_Base> >("OP_DeadECALCut",init<float,float,float,float,unsigned int,bool,string>() );

  class_<Operation::ReversedPFMET, bases<Operation::_Base> >("OP_ReversedPFMET",init<float>() );

  class_<Operation::PFMET, bases<Operation::_Base> >("OP_PFMET",init<float>() );

  class_<Operation::MHToverMET, bases<Operation::_Base> >("OP_MHToverMET",init<float,float>() );

  class_<Operation::MHToverPFMET, bases<Operation::_Base> >("OP_MHToverPFMET",init<float>() );

  class_<Operation::sumRecHitPtCut, bases<Operation::_Base> >("OP_SumRecHitPtCut",init<float>() );



  class_<Operation::MHTovHT, bases<Operation::_Base> >("OP_MHTovHT",init<float>() );

  class_<Operation::BabyMHT, bases<Operation::_Base> >("OP_BabyMHT",init<float>() );

  class_<Operation::ReversedBabyMHT, bases<Operation::_Base> >("OP_ReversedBabyMHT",init<float>() );

  class_<Operation::BabyMHTovHT, bases<Operation::_Base> >("OP_BabyMHTovHT",init<float>() );

  //class_<Operation::LowPtBiasedDphi, bases<Operation::_Base> >("OP_LowPtBiasedDphi",init<float>() );

  class_<Operation::MHTPFMETDiffOvMeffCut,bases<Operation::_Base> >("OP_MHTPFMETDiffOvMeff",init<float>() );

  //TW custom ID filters
  //
  class_<Hadronic::Muon::IDFilter,     bases<Compute::ObjectFilter<Event::Lepton> > >("Muon_IDFilter",     init<const Utils::ParameterSet&>());
  class_<Hadronic::Electron::IDFilter, bases<Compute::ObjectFilter<Event::Lepton> > >("Electron_IDFilter", init<const Utils::ParameterSet&>());
  class_<Hadronic::Photon::IDFilter,   bases<Compute::ObjectFilter<Event::Photon> > >("Photon_IDFilter",   init<const Utils::ParameterSet&>());

  // Tools
  class_<Operation::CountOp, bases<Operation::_Base> >( "OP_Count", init<const std::string &>() );
  class_<Operation::EventIdOp, bases<Operation::_Base> >( "OP_EventId", init<const std::string &>() );
  //class_<Operation::PFDiagnosticSlideMaker, bases<Operation::_Base> >( "OP_PFDiagnosticSlideMaker", init<const std::string &>() );
  class_<Operation::PFDiagnosticSlideMaker, bases<Operation::_Base> >( "OP_PFDiagnosticSlideMaker",
    init<const Utils::ParameterSet &, const Utils::ParameterSet &, const Utils::ParameterSet &>() );


  // Custom trigger operations
  class_<Operation::DataTriggerOp, bases<Operation::_Base> >("OP_HadronicDataTrigger", init<const Utils::ParameterSet&>());
  class_<Operation::MCTriggerOp,   bases<Operation::_Base> >("OP_HadronicMCTrigger",   init<const Utils::ParameterSet&>());

  // QCD background estimation
  class_<Operation::QcdBkgdEst, bases<Operation::_Base> >( "QcdBkgdEst",
                                                           init<const Utils::ParameterSet&>() );


// No primary verticies
class_<Operation::NPvs,
      bases<Operation::_Base> >("OP_NumVerticies", init<const std::string &,
                                UInt_t>());

class_<Operation::VertexPtOverHT, bases<Operation::_Base> >("OP_SumVertexPtOverHT",init<float>() );
class_<Operation::TriggerMHT_Emu, bases<Operation::_Base> >("OP_TriggerMHT_Emu",init<float,float>() );
class_<Operation::TriggerHT_Emu, bases<Operation::_Base> >("OP_TriggerHT_Emu",init<float,float>() );

class_<Operation::confiurableOddJet, bases<Operation::_Base> >("OP_ConfigurableOddJetVeto",init<float>() );


}
