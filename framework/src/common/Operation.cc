/*! \file Operation.cc
 * \brief Source code for the Operation::_base operation.
 */

#include "Operation.hh"

#include <iostream>

namespace Operation {

  //=====================================
  // Operation Base class implementation
  //=====================================
  _Base::_Base() {}
  _Base::~_Base() {}

  void _Base::Start(Event::Data & ev) {}
  void _Base::End(Event::Data & ev) {}

  // Just definition of the operator
  std::ostream& operator << (std::ostream& ostrm, _Base& m) {
    return m.Description(ostrm);
  }

} // ~namespace Operation


