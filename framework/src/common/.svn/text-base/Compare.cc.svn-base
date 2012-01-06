/*! \file Compare.cc
 * \brief Comparison tool, precompiled for various types
 */

#include "Compare.hh"
#include <TVector3.h>

namespace Operation {

  template<> bool Compare<unsigned int, EQ>::operator() (const unsigned int & a, const unsigned int & b) { return (a == b); }
  template<> bool Compare<unsigned int, NEQ>::operator() (const unsigned int & a, const unsigned int & b) { return (a != b); }
  template<> bool Compare<unsigned int, LT>::operator() (const unsigned int & a, const unsigned int & b) { return (a < b); }
  template<> bool Compare<unsigned int, GT>::operator() (const unsigned int & a, const unsigned int & b) { return (a > b); }
  template<> bool Compare<unsigned int, LTEQ>::operator() (const unsigned int & a, const unsigned int & b) { return (a <= b); }
  template<> bool Compare<unsigned int, GTEQ>::operator() (const unsigned int & a, const unsigned int & b) { return (a >= b); }

  template<> const std::string Compare<unsigned int, EQ>::type() { return "unsigned int ="; }
  template<> const std::string Compare<unsigned int, NEQ>::type() { return "unsigned int !="; }
  template<> const std::string Compare<unsigned int, LT>::type() { return "unsigned int <"; }
  template<> const std::string Compare<unsigned int, GT>::type() { return "unsigned int >"; }
  template<> const std::string Compare<unsigned int, LTEQ>::type() { return "unsigned int <="; }
  template<> const std::string Compare<unsigned int, GTEQ>::type() { return "unsigned int >="; }

  template<> bool Compare<int, EQ>::operator() (const int & a, const int & b) { return (a == b); }
  template<> bool Compare<int, NEQ>::operator() (const int & a, const int & b) { return (a != b); }
  template<> bool Compare<int, LT>::operator() (const int & a, const int & b) { return (a < b); }
  template<> bool Compare<int, GT>::operator() (const int & a, const int & b) { return (a > b); }
  template<> bool Compare<int, LTEQ>::operator() (const int & a, const int & b) { return (a <= b); }
  template<> bool Compare<int, GTEQ>::operator() (const int & a, const int & b) { return (a >= b); }

  template<> const std::string Compare<int, EQ>::type() { return "int ="; }
  template<> const std::string Compare<int, NEQ>::type() { return "int !="; }
  template<> const std::string Compare<int, LT>::type() { return "int <"; }
  template<> const std::string Compare<int, GT>::type() { return "int >"; }
  template<> const std::string Compare<int, LTEQ>::type() { return "int <="; }
  template<> const std::string Compare<int, GTEQ>::type() { return "int >="; }

  template<> bool Compare<float, EQ>::operator() (const float & a, const float & b) { return (a == b); }
  template<> bool Compare<float, NEQ>::operator() (const float & a, const float & b) { return (a != b); }
  template<> bool Compare<float, LT>::operator() (const float & a, const float & b) { return (a < b); }
  template<> bool Compare<float, GT>::operator() (const float & a, const float & b) { return (a > b); }
  template<> bool Compare<float, LTEQ>::operator() (const float & a, const float & b) { return (a <= b); }
  template<> bool Compare<float, GTEQ>::operator() (const float & a, const float & b) { return (a >= b); }

  template<> const std::string Compare<float, EQ>::type() { return "float ="; }
  template<> const std::string Compare<float, NEQ>::type() { return "float !="; }
  template<> const std::string Compare<float, LT>::type() { return "float <"; }
  template<> const std::string Compare<float, GT>::type() { return "float >"; }
  template<> const std::string Compare<float, LTEQ>::type() { return "float <="; }
  template<> const std::string Compare<float, GTEQ>::type() { return "float >="; }

  template<> bool Compare<double, EQ>::operator() (const double & a, const double & b) { return (a == b); }
  template<> bool Compare<double, NEQ>::operator() (const double & a, const double & b) { return (a != b); }
  template<> bool Compare<double, LT>::operator() (const double & a, const double & b) { return (a < b); }
  template<> bool Compare<double, GT>::operator() (const double & a, const double & b) { return (a > b); }
  template<> bool Compare<double, LTEQ>::operator() (const double & a, const double & b) { return (a <= b); }
  template<> bool Compare<double, GTEQ>::operator() (const double & a, const double & b) { return (a >= b); }

  template<> const std::string Compare<double, EQ>::type() { return "double ="; }
  template<> const std::string Compare<double, NEQ>::type() { return "double !="; }
  template<> const std::string Compare<double, LT>::type() { return "double <"; }
  template<> const std::string Compare<double, GT>::type() { return "double >"; }
  template<> const std::string Compare<double, LTEQ>::type() { return "double <="; }
  template<> const std::string Compare<double, GTEQ>::type() { return "double >="; }

} // ~namespace Operation
