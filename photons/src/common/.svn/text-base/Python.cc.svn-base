#include <boost/python.hpp>
#include "PhotonPlottingOps.hh"
#include "PhotonOps.hh"
#include "PhotonCompute.hh"
#include "IDFilters.hh"
#include "Filters.hh"
#include "Dump.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libPhotons) {

  class_<Photon::IDFilter,bases<Compute::ObjectFilter<Event::Photon> > >("Photon_IDFilter", init<const Utils::ParameterSet&>());

  class_<Operation::StandardPlots,bases<Operation::_Base> >("OP_StandardPlots", init<const Utils::ParameterSet&>());

  class_<SelectedPhotons,bases<Compute::UserBase> >("SelectedPhotons", init<const Utils::ParameterSet &>());

  class_<SelectedJets,bases<Compute::UserBase> >("SelectedJets", init<const Utils::ParameterSet &>());

  class_<Status1GenPhotons,bases<Compute::UserBase> >("Status1GenPhotons");

  class_<Status3GenPhotons,bases<Compute::UserBase> >("Status3GenPhotons");

  class_<MatchedStatus1Photons,bases<Compute::UserBase> >("MatchedStatus1Photons", init<double,double>());

  class_<MatchedStatus3Photons,bases<Compute::UserBase> >("MatchedStatus3Photons", init<double,double>());

  class_<Operation::EfficiencyPlots, bases<Operation::_Base> >( "OP_EfficiencyPlots",
                    init<const std::string &, const std::string &>() );

  class_<Operation::PhotonPlots, bases<Operation::_Base> >( "OP_PhotonPlots",
                    init<const std::string &, UInt_t>() );

  class_<Operation::GenPtHatPlots, bases<Operation::_Base> >( "OP_GenPtHatPlots",
                    init<const std::string &>());

  class_<Operation::NumSelectedPhotons,bases<Operation::_Base> >("OP_NumSelectedPhotons",
                    init<const std::string &, UInt_t>());

  class_<Operation::NumSelectedJets,bases<Operation::_Base> >("OP_NumSelectedJets",
                    init<const std::string &, UInt_t>());

  class_<Operation::Dump,bases<Operation::_Base> >( "OP_Dump" );

  class_<Operation::HtPlot,bases<Operation::_Base> >( "OP_HtPlot",
                    init<const std::string &>());

  class_<Operation::TriggerPlots,bases<Operation::_Base> >( "OP_TriggerPlots",
                    init<const std::string &>());

  class_<Operation::SpikeSelector,bases<Operation::_Base> >( "OP_SpikeSelector" );

  class_<Operation::PrescaleFilter,bases<Operation::_Base> >( "OP_PrescaleFilter",
                    init<const std::string &, const int>() );

  class_<Operation::SpikePlots,bases<Operation::_Base> >( "OP_SpikePlots",
                    init<const std::string &>());

  //class_<Operation::StandardPlots, bases<Operation::_Base> >("OP_StandardPlots",
  //               init<const Utils::ParameterSet &>());

  class_<Operation::SignalScan,bases<Operation::_Base> >( "OP_SignalScan",
                    init<const std::string &>());

  class_<Operation::EBDeadTT,bases<Operation::_Base> >( "OP_EBDeadTT",
                    init<const std::string &>());

  class_<Operation::DeadTTCut,bases<Operation::_Base> >( "OP_DeadTTCut" );

  class_<Operation::SignalFilter,bases<Operation::_Base> >( "OP_SignalFilter",
                    init<const int,const int>());

 class_<Operation::PhotonPtCut, bases<Operation::_Base> >("OP_PhotonPtCut",
                    init<float>());

 class_<Operation::Categorize, bases<Operation::_Base> >("OP_Categorize", init<const int>());

 class_<Operation::Category, bases<Operation::_Base> >("OP_Category", init<const int>());

}
