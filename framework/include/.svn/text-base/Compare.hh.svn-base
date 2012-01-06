/*! \file Compare.hh
 * \brief Header file for the comparison template
 */

#ifndef COMPARE_HH
#define COMPARE_HH

#include <string>

/*! \brief Namespace for all Operation-related code.
 * 
 */
namespace Operation {

  enum COMPARISON_TYPE {
    EQ = 0,
    NEQ,
    GT,
    LT,
    GTEQ,
    LTEQ
  };

  template<typename T>
  class _Compare {
  public:
    virtual ~_Compare() {;}
    virtual bool operator() (const T & a, const T & b) = 0;
    virtual const std::string type() = 0;
  };
  
  // enum COMPARISON_TYPE
  template<typename T, COMPARISON_TYPE X>
  class Compare : public _Compare<T> {
  public:
    virtual ~Compare() {;}
    bool operator() (const T & a, const T & b);
    const std::string type();
  };
  
} // ~ namespace Operation

#endif //~COMPARE_HH
