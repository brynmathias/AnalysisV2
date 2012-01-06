#include <boost/python.hpp>

#include "BkgdManager.hh"


using namespace boost::python;

BOOST_PYTHON_MODULE(libStatSuite) {

 
 
  
  class_<Operation::BkgdManager>("BkgdManager")
      .def("ReadIn",&Operation::BkgdManager::ReadIn)
      .def("Run",&Operation::BkgdManager::Run);

}
