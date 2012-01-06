#ifndef allhadronic_include_Algorithms_hh
#define allhadronic_include_Algorithms_hh

#include "EventData.hh"
#include "Types.hh"
#include "Utility.hh"
#include "Utils.hh"
#include "Vars.hh"
#include <sstream>
#include <string>
#include <vector>
#include <map>

namespace allhadronic {
  
  /**
     Class defining analysis method (binning, selection, etc...)
  */
  class Algorithms {

  public:
    
    Algorithms( const Utils::ParameterSet& );
    void print( std::stringstream& ) const;

    // Binning

    bool useMeff() const;
    uint nbins() const; 
    double low() const; 
    double high() const; 
    const std::vector<double>& bins() const; 
    const std::vector<double>& pt1Bins() const; 
    const std::vector<double>& pt2Bins() const; 
    const std::vector<double>& pt3Bins() const; 
    bool scale() const;
    int bin() const;

    // Jets
    
    double pt1() const;
    double pt2() const;
    double pt3() const;

    // Event variables
    
    LorentzV met( const Event::Data& ev );
    void reco( const Event::Data& ev, Vars& reco, int njets = -1, int bin = -1 );
    void baby( const Event::Data& ev, Vars& baby, int njets = -1 );
    void raw( const Event::Data& ev, Vars& raw );
    
    // Jet selection

    bool jetMultiplicity( const Vars& vars );
    bool leadingJetPt( const Vars& vars );
    bool leadingJetEta( const Vars& vars );
    bool secondJetPt( const Vars& vars );

    // Odd objects
    
    bool noOddJets( const Event::Data& ev );
    bool noBadMuonInJet( const Event::Data& ev, const Vars& vars );

    // Cleaning cuts
    
    bool mhtOverMet( const Event::Data& ev, const Vars& vars );
    bool mhtOverMet( const Event::Data& ev, const Vars& vars, double signal_region );
    bool mhtOverMeff( const Event::Data& ev, const Vars& vars );
    bool mhtOverSqrtMeff( const Event::Data& ev, const Vars& vars );
    bool noOverlapWithDeadEcal( const Event::Data& ev, const Vars& reco, const Vars& baby );
    bool vertexSumPtOverHt( const Event::Data& ev, const Vars& vars );
    
    // Trigger

    typedef std::vector<std::string> Names;
    typedef std::map<std::string,bool> TriggerMap;
    typedef std::map<std::string,int> PrescaleMap;
    typedef std::map<int,float> Prescales;
    typedef std::map<std::string,Prescales> Triggers;
    
    bool hltHtAlphaT( const Event::Data& ev, double et, double eta, double ht, double at );

    // Construct map of counters for triggers vs their prescales
    //void triggersVsPrescales( const Event::Data& ev, Triggers&, const std::string& filter = "" );

    // Construct map of counters for triggers (and their prescales) vs run number
    void triggers( const Event::Data& ev, 
		   const Names& filters, 
		   Triggers&, 
		   int yaxis = 1 );
    void triggers( const Event::Data& ev, 
		   Triggers&, 
		   int yaxis = 1 );
    
    // Print summary of triggers and their prescales
    void triggers( const Event::Data& ev, const std::string& filter = "" );

    // Logic to determine whether to use trigger that fired when filling histos
    int triggers( const Event::Data& ev, 
		  const Vars& reco, 
		  const Names& filters,
		  Names& fired,
		  double at_threshold );
    int triggers( const Event::Data& ev, 
		  const Vars& reco, 
		  const Names& filters,
		  double at_threshold );
    int triggers( const Event::Data& ev, 
		  const Names& filters,
		  Names& fired );
    int triggers( const Event::Data& ev, 
		  const Names& filters );
    
    // Algo to compare regexp to string (returns >0 if match)
    static int compare( const char* wild, const char* string );
    
    // Trigger names that match filters
    //void triggers( const Event::Data& ev, const Names& filters, const Names& triggers );
    
  private:
    
    double DeadECALDR( const Event::Data&, float, float, int );
    double DeadECALDR_File( const std::string&, float, float, int );

  private:

    // Binning
    bool useMeff_;
    int nbins_; 
    double low_; 
    double high_; 
    std::vector<double> bins_; 
    std::vector<double> pt1Bins_; 
    std::vector<double> pt2Bins_; 
    std::vector<double> pt3Bins_; 
    bool scale_;
    int bin_;
    
    // Analysis cuts
    double pt1_;
    double pt2_;
    double pt3_;
    double maxLeadingJetEta_;
    double minVertexSumPtOverHt_;
    double maxBaby_;
    double minBabyJetPt_;
    bool useFile_;
    std::string deadEcalFile_;
    int nBadCells_;
    double maxBiasDeltaPhi_;
    double maxDrToDeadEcalRegion_;
    
    // Misc
    bool norm_;

  };
  
  // ---------- Inline methods ---------- 

  inline bool Algorithms::useMeff() const { return useMeff_; }
  inline uint Algorithms::nbins() const { return nbins_; } 
  inline double Algorithms::low() const { return low_; } 
  inline double Algorithms::high() const { return high_; } 
  inline const std::vector<double>& Algorithms::bins() const { return bins_; } 
  inline const std::vector<double>& Algorithms::pt1Bins() const { return pt1Bins_; } 
  inline const std::vector<double>& Algorithms::pt2Bins() const { return pt2Bins_; } 
  inline const std::vector<double>& Algorithms::pt3Bins() const { return pt3Bins_; } 
  inline bool Algorithms::scale() const { return scale_; }
  inline int Algorithms::bin() const { return bin_; }
  inline double Algorithms::pt1() const { return pt1_; }
  inline double Algorithms::pt2() const { return pt2_; }
  inline double Algorithms::pt3() const { return pt3_; }
  
  inline LorentzV Algorithms::met( const Event::Data& ev ) {
    if ( ev.isPFJet ) { return ev.PFMET(); }
    else { return *(ev.metP4caloTypeII()); }
  }

  inline bool Algorithms::jetMultiplicity( const Vars& vars ) {
    return ( vars.njets() >= 2 );
  }

  inline bool Algorithms::leadingJetPt( const Vars& vars ) {
    return ( ( vars.njets() > 0 ) && ( vars.jets()[0].Pt() > pt1Bins_[bin_] ) );
  }
  
  inline bool Algorithms::leadingJetEta( const Vars& vars ) {
    return ( ( vars.njets() > 0 ) && ( fabs(vars.jets()[0].Eta()) < maxLeadingJetEta_ ) );
  }
  
  inline bool Algorithms::secondJetPt( const Vars& vars ) {
    return ( ( vars.njets() > 1 ) && ( vars.jets()[1].Pt() > pt2Bins_[bin_] ) );
  }
  
}

#endif // allhadronic_include_Algorithms_hh
