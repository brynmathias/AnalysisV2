#include <boost/python.hpp>
#include "TFile.h"
#include "TopSusySelection.hh"
#include "QCDSelection.hh"
#include "JetTriggerSelection.hh"
#include "Utils.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libTopSusy) {
  class_<TopSusy::TopSusySelector,    bases<Operation::_Base> >("TopSusySelector",    init<const std::string&, Utils::ParameterSet&>());
  class_<TopSusy::QCDSelector,        bases<Operation::_Base> >("QCDSelector",        init<const std::string&, Utils::ParameterSet&>());
  class_<TopSusy::JetTriggerSelector, bases<Operation::_Base> >("JetTriggerSelector", init<const std::string&, Utils::ParameterSet&>());
}
