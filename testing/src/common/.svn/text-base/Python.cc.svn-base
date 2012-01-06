#include <boost/python.hpp>
#include "CrossClean.hh"
#include "Utils.hh"
#include "Jet.hh"
#include "Lepton.hh"
#include "Photon.hh"
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
using namespace boost::python;

typedef Compute::CloneVector<Event::Jet> CloneVector_Jet;
typedef Compute::CloneVector<Event::Lepton> CloneVector_Lepton;
typedef Compute::CloneVector<Event::Photon> CloneVector_Photon;

BOOST_PYTHON_MODULE(libxcleantest) {
  class_<Compute::CrossCleaner>("CrossCleaner",
                                init<bool,double,double,
                                bool,double,double,
                                bool,int,
                                CloneVector_Jet &, CloneVector_Lepton &,
                                CloneVector_Lepton &,CloneVector_Photon &,bool>())
      .def("Reset",&Compute::CrossCleaner::Reset)
      .def("Clean",&Compute::CrossCleaner::Clean)
      .def("Resolve",&Compute::CrossCleaner::Resolve)
      .def("Execute",&Compute::CrossCleaner::Execute);
  class_<CloneVector_Jet,boost::noncopyable>("JetVector")
      .def(vector_indexing_suite<CloneVector_Jet>())
      .def("Add",&CloneVector_Jet::Add)
      .def("Clone",&CloneVector_Jet::CloneI,return_value_policy<reference_existing_object>())
      .def("Clear",&CloneVector_Jet::Clear);
  class_<CloneVector_Lepton,boost::noncopyable>("LeptonVector")
      .def(vector_indexing_suite<CloneVector_Lepton>())
      .def("Add",&CloneVector_Lepton::Add)
      .def("Clear",&CloneVector_Lepton::Clear);
  class_<CloneVector_Photon,boost::noncopyable>("PhotonVector")
      .def(vector_indexing_suite<CloneVector_Photon>())
      .def("Add",&CloneVector_Photon::Add)
      .def("Clear",&CloneVector_Photon::Clear);
  class_<Event::Jet>("Jet",init<double,double,double,double,double,int>())
      .def("GetEmFraction",&Event::Jet::GetEmFrac)
      .def("Eta",&Event::Jet::Eta)
      .def("Phi",&Event::Jet::Phi)
      .def("Et",&Event::Jet::Et)
      .def("Pt",&Event::Jet::Pt)
      .def("Px",&Event::Jet::Px)
      .def("Py",&Event::Jet::Py)
      .def("Pz",&Event::Jet::Pz)
      .def("E",&Event::Jet::E)
      .def("SetPx",&Event::Jet::SetPx)
      .def("SetPy",&Event::Jet::SetPy)
      .def("SetPz",&Event::Jet::SetPz)
      .def("SetE",&Event::Jet::SetE);
  class_<Event::Lepton>("Lepton",init<double,double,double,double,double,double,double,double, bool, bool,int,int>())
      .def("Eta",&Event::Lepton::Eta)
      .def("Phi",&Event::Lepton::Phi)
      .def("Et",&Event::Lepton::Et)
      .def("Pt",&Event::Lepton::Pt)
      .def("Px",&Event::Lepton::Px)
      .def("Py",&Event::Lepton::Py)
      .def("Pz",&Event::Lepton::Pz)
      .def("E",&Event::Lepton::E)
      .def("SetPx",&Event::Lepton::SetPx)
      .def("SetPy",&Event::Lepton::SetPy)
      .def("SetPz",&Event::Lepton::SetPz)
      .def("SetE",&Event::Lepton::SetE);

  class_<Compute::LeptonFilter>("LeptonFilter",init<double,double>())
      .def("Filter",&Compute::LeptonFilter::operator());

   class_<Compute::JetFilter>("JetFilter",init<double,double>())
       .def("Filter",&Compute::JetFilter::operator());

   class_<Compute::PhotonFilter>("PhotonFilter",init<double,double>())
       .def("Filter",&Compute::PhotonFilter::operator());
 }
