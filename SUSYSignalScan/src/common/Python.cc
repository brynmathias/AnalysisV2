#include <boost/python.hpp>
#include "Ops.hh"
#include "mSuGraPlottingOps.hh"
#include "SUSYSignalScanFilters.hh"
// #include "PdfPlottingOps.hh"

using namespace boost::python;

BOOST_PYTHON_MODULE(libSUSYSignalScan) {

  class_<Operation::mSuGraPlottingOps, bases<Operation::_Base> >( "OP_mSuGraPlottingOps",
                    init<const Utils::ParameterSet&>() );
  class_<Operation::SMPlottingOps, bases<Operation::_Base> >( "OP_SMPlottingOps",
                    init<const Utils::ParameterSet&>() );

  class_<SUSYSignalScan::SignalScanLOCrossSectionWeighting,   bases<Compute::ObjectFilter<double> > >("SignalScanLOCrossSectionWeighting",   init<const Utils::ParameterSet &>());


  // class_<Operation::PdfPlottingOps, bases<Operation::_Base> >( "OP_PdfPlottingOps",
    // init<const Utils::ParameterSet&> () );
 }
