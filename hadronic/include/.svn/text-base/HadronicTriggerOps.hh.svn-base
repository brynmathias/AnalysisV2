/*! \file Tools.hh
 * \brief Header file for the hadronic trigger operations.
 */
#ifndef Hadronic_Trigger_Ops_hh
#define Hadronic_Trigger_Ops_hh

#include "Utils.hh"
#include "Types.hh"
#include "EventData.hh"
#include "PlottingBase.hh"

class TH1D;
class TH2D;

#include <fstream>

namespace Operation {

  /*! \brief
   */
  class DataTriggerOp : public _Base {
   public:
    DataTriggerOp(const Utils::ParameterSet& ps);
    // :
    //folderName_(folderName)
    //{}
    ~DataTriggerOp() {}
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
   private:
    //void BookHistos();
	//	std::string folderName_; //!< Name of the folder where the histogram will be placed.
	//	TH1F * hg_c_; //!< Counter histogram
    bool verb_; //!< Verbose operation
    std::vector<std::string> triggers_; //!< Vector of triggers to look for.
	};//end of class DataTriggerOp


  /*! \brief
   */
  class MCTriggerOp : public PlottingBase {
   public:
    MCTriggerOp(const Utils::ParameterSet& ps);
    // :
    //folderName_(folderName)
    //{}
    ~MCTriggerOp() {}
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
   private:
    void BookHistos();
	std::string folderName_; //!< Name of the folder where the histogram will be placed.
	//	TH1F * hg_c_; //!< Counter histogram
    bool verb_; //!< Verbose operation
    //std::vector<std::string> triggers_; //!< Vector of triggers to look for.
    double jetPt_; //!< Min pt for jet to count
    double htCut_; //!< HT cut
	};//end of class DataTriggerOp

  /*! \brief
   */
  class BabyVertexPlot : public PlottingBase {
   public:
    BabyVertexPlot(const Utils::ParameterSet& ps);
    // :
    //folderName_(folderName)
    //{}
    ~BabyVertexPlot() {}
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
   private:
    void BookHistos();
	std::string folderName_; //!< Name of the folder where the histogram will be placed.
	//	TH1F * hg_c_; //!< Counter histogram
    //bool verb_; //!< Verbose operation
    //std::vector<std::string> triggers_; //!< Vector of triggers to look for.
    //double jetPt_; //!< Min pt for jet to count
    //double htCut_; //!< HT cut
    TH1D * hg_goodVertices_;
    TH1D * hg_vx1_goodJetMultiplicity_;
    TH1D * hg_vx1_babyJetMultiplicity_;
    TH1D * hg_vx2plus_goodJetMultiplicity_;
    TH1D * hg_vx2plus_babyJetMultiplicity_;

    TH2D * hg_goodVertices_babyjets_;
  };//end of class

}//end of namespace Operation


#endif
