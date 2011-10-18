/*! \file DiagnosticOps.hh
 * \brief Header file for the hadronic diagnostic operations.
 */
#ifndef Diagnostic_Ops_hh
#define Diagnostic_Ops_hh

#include "Utils.hh"
#include "Types.hh"
#include "EventData.hh"
#include "PlottingBase.hh"

class TH1D;
class TH2D;

#include <vector>
#include <sstream>
#include <fstream>

namespace Operation {


  /*! \brief
     */
  class PFDiagnosticSlideMaker : public PlottingBase {
   public:
    //PFDiagnosticSlideMaker(const std::string & textFileName) : textFileName_(textFileName) {}
    PFDiagnosticSlideMaker(const Utils::ParameterSet & ps, const Utils::ParameterSet & priCorrPs, const Utils::ParameterSet & terCorrPs);
		// : textFileName_(textFileName) {}
    ~PFDiagnosticSlideMaker();// {}
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
   private:
    void BookHistos();

		std::string slidesStart();
		std::string slidesEnd();

    std::string textFileName_; //!<
		std::vector<std::string> triggers_; //!< Triggers to look for in the event.
		Utils::ParameterSet priJetCorrectionsPs_;
		std::vector<double> priLowEta_;
		std::vector<double> priHighEta_;
		std::vector<double> priCorrFactor_;
		Utils::ParameterSet terJetCorrectionsPs_;
		std::vector<double> terLowEta_;
		std::vector<double> terHighEta_;
		std::vector<double> terCorrFactor_;
  };//end of class CountOp
  

}//end of Operation namespace

#endif
