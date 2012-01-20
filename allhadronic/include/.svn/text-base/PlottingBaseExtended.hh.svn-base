#ifndef allhadronic_include_PlottingBaseExtended_hh
#define allhadronic_include_PlottingBaseExtended_hh

#include "EventData.hh"
#include "PlottingBase.hh"
#include "Utility.hh"
#include "Utils.hh"
#include <ostream>

namespace allhadronic {
  
  /**
     Class that extends functionality of PlottingBase
  */
  class PlottingBaseExtended : public PlottingBase {
    
  public:

    typedef std::vector<TH1D*> vTH1D; // njets
    typedef std::vector<vTH1D> vvTH1D; // variable (eg, HT, aT)
    typedef std::vector<vvTH1D> vvvTH1D; // 2nd variable (eg, aT, HT)
    typedef std::vector<TH2D*> vTH2D;
    typedef std::vector<vTH2D> vvTH2D;
    
    PlottingBaseExtended( const Utils::ParameterSet& );
    virtual ~PlottingBaseExtended();
    
    void Start( Event::Data& );
    bool Process( Event::Data& );
    void BookHistos(); //@@ requires implementation in derived class!
    
    std::ostream& Description( std::ostream& ss );

    void book( vvTH1D& histogram_array,
	       const std::string& histogram_name, 
	       const std::string& xaxis_title, 
	       uint xbins,
	       double xlow, 
	       double xhigh,
	       uint jet_multiplicity,
	       const std::string& variable_name, 
	       const std::vector<double>& variable );

    void fill( vTH1D&, 
	       double value, 
	       double weight,
	       uint jet_multiplicity, 
	       double at_value, 
	       double at_cut );

  }; 

}

#endif // allhadronic_include_PlottingBaseExtended_hh

