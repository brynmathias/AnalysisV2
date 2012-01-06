//in the hh file:
#include "PlottingBase.hh"
#include "TTree.h"
#include "EventData.hh"
namespace WPol{
 class EventNoDump : public PlottingBase {
  public:
    // Standard Operation methods.
   EventNoDump(const std::string & folderName, std::string TreeName);
    ~EventNoDump(); //!< Destructor.
   //std::ofstream ostrm("event.txt");
   void Start(Event::Data & ev);
   bool Process(Event::Data & ev); //!< Processes the event, returning true if it passes the operation.

    std::ostream& Description(std::ostream& ostrm); //!< Describes the operation, for analysis output to terminal/log file.
    void  BookHistos();
   // std::iostream ostrm;

  private:
 
   std::string mFolderName;
   std::string mTreeName;
   // Histograms
   
   TTree * mTree; 
   int LS;
   int Run;
   int Event;
   int Mhit;
   float ElectronDCot;
   float GetElectronDist;
   float EEdPhi;
   float EEdEta;
   float EBdPhi;
   float EBdEta;
   float Eta;
   float Pt;
   float Ptraw;
   float Phi;
   int Charge;
   float PFMETPT;
   float PFMETPhi;
   float WPT;
   float WPhi;
   float LP;
   float LPraw;
   float WPTraw;
   float WPhiraw;
   int VertexNo;


  }; // ~
}

