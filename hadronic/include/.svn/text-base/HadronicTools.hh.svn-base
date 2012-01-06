/*! \file Tools.hh
 * \brief Header file for the hadronic tool operations.
 */
#ifndef Hadronic_Tools_hh
#define Hadronic_Tools_hh

#include "Utils.hh"
#include "Types.hh"
#include "EventData.hh"
#include "PlottingBase.hh"

class TH1D;
class TH2D;

#include <fstream>

namespace Operation {

	/*! \brief Simple operation for counting events passing a cut, for later retrival
	 */
  class CountOp : public PlottingBase {
   public:
    CountOp(const std::string & folderName) : folderName_(folderName) {}
    ~CountOp() {}
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
   private:
    void BookHistos();
		std::string folderName_; //!< Name of the folder where the histogram will be placed.
		TH1F * hg_c_; //!< Counter histogram
	};//end of class CountOp

  //inline CountOp(const std::string & folderName) : folderName_(folderName_) {}
	//inline CountOp::~CountOp() {}
	inline void CountOp::Start(Event::Data& ev) { initDir(ev.OutputFile(),folderName_.c_str()); BookHistos(); }
	inline void CountOp::BookHistos() { hg_c_ = new TH1F("count","",1,0.,1.); hg_c_->Sumw2(); }
	inline bool CountOp::Process(Event::Data& ev) { hg_c_->Fill(0.5, ev.GetEventWeight()); return true;}
	inline std::ostream& CountOp::Description(std::ostream& ostrm) {ostrm << "CountOp ("<<folderName_<<") ";	return ostrm;}

  /*! \brief
     */
  class EventIdOp : public PlottingBase {
   public:
    EventIdOp(const std::string & textFileName) : textFileName_(textFileName) {}
    ~EventIdOp() {}
    void Start( Event::Data& );
    bool Process( Event::Data& );
    std::ostream& Description( std::ostream& );
   private:
    void BookHistos();
    std::string textFileName_; //!<
  };//end of class CountOp
  
  inline void EventIdOp::Start(Event::Data& ev) { std::ofstream ostrm(textFileName_.c_str(),fstream::trunc); } //initDir(ev.OutputFile(),folderName_.c_str()); BookHistos(); }
  inline void EventIdOp::BookHistos() {;} // hg_c_ = new TH1D("count","",1,0.,1.); hg_c_->Sumw2(); }
  inline bool EventIdOp::Process(Event::Data& ev) {
    std::ofstream ostrm(textFileName_.c_str(),fstream::app);
    ostrm<<ev.RunNumber()<<", "<<ev.LumiSection()<<", "<<ev.EventNumber()<<std::endl;
    ostrm.close();
    return true;
  }
  inline std::ostream& EventIdOp::Description(std::ostream& ostrm) {ostrm << "EventIdOp ("<<textFileName_<<") ";  return ostrm;}


}//end of namespace Operation

#endif
