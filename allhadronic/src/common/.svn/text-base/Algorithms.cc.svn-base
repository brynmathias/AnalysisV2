#include "Algorithms.hh"
#include "Math/VectorUtil.h"
#include <fstream>
#include <sstream>

/*
  - pthat
  - mht cleaning
  - aT/HT scatter, different binning?
  - truth!!
*/

using namespace allhadronic;

// -----------------------------------------------------------------------------
//
Algorithms::Algorithms( const Utils::ParameterSet& ps ) :
  // Binning
  useMeff_(false),
  nbins_(0),
  low_(0.),
  high_(0.),
  bins_(),
  pt1Bins_(),
  pt2Bins_(),
  pt3Bins_(),
  scale_(true),
  // Analysis cuts
  pt1_(0.),
  pt2_(0.),
  pt3_(0.),
  maxLeadingJetEta_(0.),
  minVertexSumPtOverHt_(0.),
  maxBaby_(0.),
  minBabyJetPt_(0.),
  useFile_(false),
  deadEcalFile_(""),
  nBadCells_(0),
  maxBiasDeltaPhi_(0.),
  maxDrToDeadEcalRegion_(0.),
  // Misc
  norm_(2.)
{
  
  // Binning
  if ( ps.Contains("Algorithms.UseMeff") ) { useMeff_ = ps.Get<bool>("Algorithms.UseMeff"); }
  nbins_ = ps.Get<int>("Algorithms.Nbins"); 
  low_ = ps.Get<double>("Algorithms.Low"); 
  high_ = ps.Get<double>("Algorithms.High"); 
  if ( ps.Contains("Algorithms.Scale") ) { scale_ = ps.Get<bool>("Algorithms.Scale"); }

  // Analysis cuts
  pt1_ = ps.Get<double>("Algorithms.MinJetPt1");
  pt2_ = ps.Get<double>("Algorithms.MinJetPt2");
  pt3_ = ps.Get<double>("Algorithms.MinJetPt3");
  maxLeadingJetEta_ = ps.Get<double>("Algorithms.MaxLeadingJetEta");
  minVertexSumPtOverHt_ = ps.Get<double>("Algorithms.MinVertexSumPtOverHt");
  maxBaby_ = ps.Get<double>("Algorithms.MaxBaby");
  minBabyJetPt_ = ps.Get<double>("Algorithms.MinBabyJetPt");
  useFile_ = ps.Get<bool>("Algorithms.UseFile");
  deadEcalFile_ = ps.Get<std::string>("Algorithms.DeadEcalFile");
  nBadCells_ = ps.Get<int>("Algorithms.nBadCells");
  maxBiasDeltaPhi_ = ps.Get<double>("Algorithms.MaxBiasDeltaPhi");
  maxDrToDeadEcalRegion_ = ps.Get<double>("Algorithms.MaxDrToDeadEcalRegion");
  
  // Override binning if defined
  if ( ps.Contains("HtBins") ) {
    bins_ = ps.Get< std::vector<double> >("HtBins"); 
    if ( !bins_.empty() ) {
      nbins_ = bins_.size() - 1;
      low_ = bins_.front();
      high_ = bins_.back();
    }
  }
  
  // HT (or Meff) bins
  if ( bins_.empty() ) {
    for ( int ii = 0; ii < nbins_; ++ii ) { 
      double width = ( high_ - low_ ) / nbins_;
      bins_.push_back(low_+width*ii);
    }
    bins_.push_back(high_);
  }

  // Override binning if defined
  if ( ps.Contains("Algorithms.Pt1Bins") ) { pt1Bins_ = ps.Get< std::vector<double> >("Algorithms.Pt1Bins"); }
  if ( ps.Contains("Algorithms.Pt2Bins") ) { pt2Bins_ = ps.Get< std::vector<double> >("Algorithms.Pt2Bins"); }
  if ( ps.Contains("Algorithms.Pt3Bins") ) { pt3Bins_ = ps.Get< std::vector<double> >("Algorithms.Pt3Bins"); }
    
  if ( pt1Bins_.empty() || 
       pt2Bins_.empty() || 
       pt3Bins_.empty() ) {
  
    if ( !useMeff_ ) {

      // pT thresholds that scale with HT
      double meff_default = bins_.back() + pt3_;
      double x3_default = ( norm_ * pt3_ ) / meff_default; 
      double x3_factor = ( norm_ - x3_default ) / x3_default;
      //std::vector<double>::const_iterator i = bins_.begin();
      //std::vector<double>::const_iterator j = bins_.end();
      //for ( ; i != j; ++i ) {
      for ( unsigned int i = 0; i < nbins_; ++i ) {
	//double ht = *i;
	double ht = bins_[i];
	double pt3 = ht / x3_factor;
	double meff = pt3 + ht;
	double pt1 = pt1_ * meff / meff_default;
	double pt2 = pt2_ * meff / meff_default;
	pt1Bins_.push_back( scale_ ? pt1 : pt1_ );
	pt2Bins_.push_back( scale_ ? pt2 : pt2_ );
	pt3Bins_.push_back( scale_ ? pt3 : pt3_ );
      }

    } else {

      // pT thresholds that scale with Meff
      std::vector<double>::const_iterator i = bins_.begin();
      std::vector<double>::const_iterator j = bins_.end();
      for ( ; i != j; ++i ) {
	double meff = *i;
	double pt1 = pt1_ * meff / bins_.front();
	double pt2 = pt2_ * meff / bins_.front();
	double pt3 = pt3_ * meff / bins_.front();
	pt1Bins_.push_back( scale_ ? pt1 : pt1_ );
	pt2Bins_.push_back( scale_ ? pt2 : pt2_ );
	pt3Bins_.push_back( scale_ ? pt3 : pt3_ );
      }
    
    }

  }

  if ( true ) {
    std::stringstream ss;
    ss << "[Algorithms::Algorithms]" << std::endl
       << " Thresholds scaled according to HT bins:" << std::endl
       << " --------------------------------------------------------" << std::endl
       << " |  HT  |    (pT1,pT2,pT3) | Meff |          (x1,x2,x3) |" << std::endl
       << " --------------------------------------------------------" << std::endl;
    for ( uint ii = 0; ii < nbins_; ++ii ) {
      double ht = bins_[ii];
      double pt1 = pt1Bins_[ii];
      double pt2 = pt2Bins_[ii];
      double pt3 = pt3Bins_[ii];
      double meff = bins_[ii] + pt3Bins_[ii];
      ss << " | " << std::setw(4) << std::setprecision(3) << ht
	 << " | (" << std::setw(4) << std::setprecision(3) << pt1
	 << "," << std::setw(4) << std::setprecision(3) << pt2
	 << "," << std::setw(4) << std::setprecision(3) << pt3
	 << ") | " << std::setw(4) << std::setprecision(3) << meff
	 << " | (" << std::setw(5) << std::setprecision(3) << (norm_*pt1/meff)
	 << "," << std::setw(5) << std::setprecision(3) << (norm_*pt2/meff) 
	 << "," << std::setw(5) << std::setprecision(3) << (norm_*pt3/meff) 
	 << ") |" << std::endl;
    }
    ss << " --------------------------------------------------------" << std::endl;
    ss << std::fixed << std::setprecision(8);
    std::cout << ss.str() << std::endl;
  }
  
}

// -----------------------------------------------------------------------------
//
void Algorithms::reco( const Event::Data& ev, Vars& reco, int njets, int bin ) {

  bool inclusive_ = true; //@@ configurable??
  
  // Retrieve COMMON jets from ntuple
  const std::vector<Event::Jet const*>* common_jets = &(ev.JD_CommonJets().accepted);
  
  if ( bin < 0 ) {
    
    // Bin to be used
    bin_ = -1;
    
    // Loop through HT (or Meff) bins 
    for ( int ibin = 0; ibin < nbins_; ++ibin ) {
      bin = (nbins_-1) - ibin; //@@ direction?
      
      // Initialise
      reco.clear();
      
      // Loop through COMMON jets
      std::vector<Event::Jet const*>::const_iterator i = common_jets->begin();
      std::vector<Event::Jet const*>::const_iterator j = common_jets->end();
      for ( ; i != j; ++i ) {
	if ( (*i)->Pt() > pt3Bins_[bin] ) { reco.push_back(**i); }
      }
      reco.update();
      
      // Define the bin in which the event falls
      double ht_lower = bins_[bin];
      double ht_upper = ( (nbins_-bin) != 1 ? bins_[bin+1] : 10000. );
      if ( inclusive_ ) { if ( reco.ht() > ht_lower ) { bin_ = bin; return; } }
      else { if ( reco.ht() > ht_lower && reco.ht() < ht_upper ) { bin_ = bin; return; } }
      
    }

  } else if ( bin < nbins_ ) {
    
    // Initialise
    reco.clear();
    
    // Loop through COMMON jets
    std::vector<Event::Jet const*>::const_iterator i = common_jets->begin();
    std::vector<Event::Jet const*>::const_iterator j = common_jets->end();
    for ( ; i != j; ++i ) {
      if ( (*i)->Pt() > pt3Bins_[bin] ) { 
	reco.push_back(**i); 
	if ( njets > 0 && reco.njets() >= njets ) { break; }
      }
    }
    reco.update();
    
  } else { std::cout << "[Algorithms::reco] Invalid bin: " << bin << std::endl; }
  
}

// -----------------------------------------------------------------------------
//
void Algorithms::baby( const Event::Data& ev, Vars& baby, int njets ) {
  
  if ( bin_ < 0 ) { return; } 
  
  // Retrieve COMMON jets from ntuple
  const std::vector<Event::Jet const*>* common_jets = &(ev.JD_CommonJets().accepted);
  
  // Initialise
  baby.clear();
  
  // Loop through BABY jets
  std::vector<Event::Jet const*>::const_iterator i = common_jets->begin();
  std::vector<Event::Jet const*>::const_iterator j = common_jets->end();
  for ( ; i != j; ++i ) {
    if ( (*i)->Pt() < pt3Bins_[bin_] && (*i)->Pt() > 10. ) { 
      baby.push_back(**i); 
      if ( njets > 0 && baby.njets() >= njets ) { break; }
    }
  }
  baby.update();
  
}

// -----------------------------------------------------------------------------
//
void Algorithms::raw( const Event::Data& ev, Vars& raw ) {

  if ( bin_ < 0 ) { return; } 

  // Retrieve RAW jets from ntuple
  const std::vector<LorentzV>* raw_jets = ev.jetP4();

  // Initialise
  raw.clear();
  
  // Loop through RAW jets
  std::vector<LorentzV>::const_iterator i = raw_jets->begin();
  std::vector<LorentzV>::const_iterator j = raw_jets->end();
  for ( ; i != j; ++i ) {
    if ( i->Pt() > (10./50.) * pt3Bins_[bin_] && fabs(i->Eta()) < 3. ) {
      raw.push_back(*i); 
    }
  }
  raw.update();
  
}

// -----------------------------------------------------------------------------
//
bool Algorithms::noOddJets( const Event::Data& ev ) {
  
  if ( bin_ < 0 ) { return false; } 
  
  // Retrieve ODD jets from ntuple
  const std::vector<Event::Jet const*>* odd_jets = &(ev.JD_CommonJets().odd);
  
  // Identify odd jet
  std::vector<Event::Jet const*>::const_iterator i = odd_jets->begin();
  std::vector<Event::Jet const*>::const_iterator j = odd_jets->end();
  for ( ; i != j; ++i ) {
    if ( (*i)->Pt() >= pt3Bins_[bin_] ) { return false; }
  }
  
  return true;
  
}

// -----------------------------------------------------------------------------
//
bool Algorithms::noBadMuonInJet( const Event::Data& ev, const Vars& vars ) {
  
  std::vector<Event::Lepton>::const_iterator i = ev.LD_Muons().begin();
  std::vector<Event::Lepton>::const_iterator j = ev.LD_Muons().end();
  for ( ; i != j; ++i ) {
    
    // Only consider muons with pT > 10 GeV
    if( i->Pt() < 10. ) { continue; }

    // Find matches with jets where muon pT > jet pT
    bool found_match = false;
    std::vector<LorentzV>::const_iterator ii = vars.jets().begin();
    std::vector<LorentzV>::const_iterator jj = vars.jets().end();
    for ( ; ii != jj; ++ii ) {
      if ( fabs( ROOT::Math::VectorUtil::DeltaR(*ii,*i) ) < 0.5 ) {
	if ( i->Pt() > 0.5 * ii->Pt() ) { return false; }
	found_match = true;
      }
    }
    
    // Check if match was cross-cleaned away or not
    if ( found_match ) { return false; }
    
  }
  
  return true;
  
}

// -----------------------------------------------------------------------------
//
bool Algorithms::vertexSumPtOverHt( const Event::Data& ev, const Vars& vars ) {
  
  if( !ev.vertexSumPt.enabled() ) { return true; }
  
  double vertex_pt = 0.;
  std::vector<floatle>::const_iterator ivtx = ev.vertexSumPt()->begin();
  std::vector<floatle>::const_iterator jvtx = ev.vertexSumPt()->end();
  for ( ; ivtx != jvtx; ++ivtx ) { 
    int pos = static_cast<int>( ivtx - ev.vertexSumPt()->begin() );
    if( !ev.vertexIsFake()->at( pos ) && 
	ev.vertexNdof()->at( pos ) > 4 &&
	fabs( ev.vertexPosition()->at( pos ).Z() ) < 24.0 && 
	ev.vertexPosition()->at( pos ).Rho() < 2.0 ) { vertex_pt += *ivtx; }
  }
  
  return ( vars.ht() > 0. ? vertex_pt / vars.ht() : minVertexSumPtOverHt_+1. ) > minVertexSumPtOverHt_;
  
}

// -----------------------------------------------------------------------------
//
bool Algorithms::mhtOverMet( const Event::Data& ev, const Vars& vars ) {
  return ( met(ev).Pt() > 0. ? vars.mht().Pt() / met(ev).Pt() : maxBaby_-1. ) < maxBaby_;
}

// -----------------------------------------------------------------------------
//
bool Algorithms::mhtOverMet( const Event::Data& ev, const Vars& vars, double signal_region ) {
  return ( met(ev).Pt() > 0. ? vars.mht().Pt() / met(ev).Pt() : maxBaby_-1. ) < maxBaby_;
}

// -----------------------------------------------------------------------------
//
bool Algorithms::mhtOverMeff( const Event::Data& ev, const Vars& vars ) {
  return ( vars.meff() > 0. ? ( vars.mht().Pt() - met(ev).Pt() ) / vars.meff() : maxBaby_-1. ) < maxBaby_;
}

// -----------------------------------------------------------------------------
//
bool Algorithms::mhtOverSqrtMeff( const Event::Data& ev, const Vars& vars ) {
  return ( vars.meff() > 0. ? ( vars.mht().Pt() - met(ev).Pt() ) / sqrt( vars.meff() ) : maxBaby_-1. ) < maxBaby_;
}

// -----------------------------------------------------------------------------
//
void Algorithms::print( std::stringstream& ss ) const {
  std::string scale = ( useMeff_ ? "Meff" : "HT  " );
  ss << "[Algorithms::print]" 
     << " Jet pT thresholds scaled according to "
     << scale 
     << " bins:" << std::endl
     << " ---------------------------------------------------" << std::endl
     << " |  " << scale << "    |    (pT1,pT2,pT3) |          (x1,x2,x3) |" << std::endl
     << " ---------------------------------------------------" << std::endl;
  for ( int ii = 0; ii < nbins_; ++ii ) {
    double pt1 = pt1Bins_[ii];
    double pt2 = pt2Bins_[ii];
    double pt3 = pt3Bins_[ii];
    double meff = ( useMeff_ ? bins_[ii] : bins_[ii] + pt3Bins_[ii] );
    ss << " | " << std::setw(4) << std::setprecision(3) << bins_[ii]
       << " | (" << std::setw(4) << std::setprecision(3) << pt1
       << "," << std::setw(4) << std::setprecision(3) << pt2
       << "," << std::setw(4) << std::setprecision(3) << pt3
       << " | (" << std::setw(5) << std::setprecision(3) << (norm_*pt1/meff)
       << "," << std::setw(5) << std::setprecision(3) << (norm_*pt2/meff) 
       << "," << std::setw(5) << std::setprecision(3) << (norm_*pt3/meff) 
       << ") |" << std::endl;
  }
  ss << " ---------------------------------------------------" << std::endl;
  ss << std::fixed << std::setprecision(8);
}

// -----------------------------------------------------------------------------
//
bool Algorithms::hltHtAlphaT( const Event::Data& ev, 
			      double et_cut, 
			      double eta_cut, 
			      double ht_cut, 
			      double at_cut ) {
  
  // Retrieve input jets
  const std::vector<Event::Jet> jets = ev.JD_Jets();
  
  // Some initialization
  int njets = 0;
  double ht = 0.;
  double dht = 0.;
  double mhx = 0.;
  double mhy = 0.;
  
  // Loop through jets
  for ( unsigned int i = 0; i < jets.size(); ++i ) {
    
    // Construct jet object
    LorentzV jet( jets[i] );
    
    // Extract jet ET
    double et = jet.E() / cosh(jet.Eta() ); //@@ assume massless jet
    
    // Check jet is within acceptance
    if ( et < et_cut || fabs(jet.Eta()) > eta_cut ) { continue; }
    
    // Etiables used in AlphaT calculation
    njets++;
    ht += et;
    dht += ( njets < 2 ? et : -1.* et ); //@@ only use for njets < 4
    mhx -= et * cos( jet.Phi() );
    mhy -= et * sin( jet.Phi() );
    
    // Reject monojet events
    if ( njets < 2 ) { continue; }
    
    // Calc MHT and AlphaT 
    double mht = sqrt( mhx*mhx + mhy*mhy );
    double aT = 0.;
    if ( njets == 2 || njets == 3 ) {
      aT = ( ht - fabs(dht) ) / ( 2. * sqrt( ( ht*ht ) - ( mht*mht ) ) );
    } else if ( njets > 3 ) {
      aT = 1. / ( 2. * sqrt( ( 1. - ( (mht/ht) * (mht/ht) ) ) ) );
    }
    
    // Check if above HT and AlphaT thresholds
    if ( ( ht >= ht_cut ) && ( aT >= at_cut ) ) { return true; } 
    
  }
  
  return false;

}  

// // -----------------------------------------------------------------------------
// //
// void Algorithms::triggersVsPrescales( const Event::Data& ev, 
// 				      Triggers& trigs, 
// 				      const Names& filters ) {
  
//   // Check if trigger container is valid
//   if ( !ev.hltHandleValid() ) {
//     std::cout << "[Trigger::triggers] Invalid handle to HLT trigger bits!" << std::endl;
//     return;
//   }
  
//   // Retrieve info from event
//   double weight = 1.;//ev.GetEventWeight();
//   const TriggerMap* triggers = ev.hlt();
//   const PrescaleMap* prescales = ev.hlt_prescaled();

//   // Loop through trigger map
//   TriggerMap::const_iterator itrigger = triggers->begin(); 
//   TriggerMap::const_iterator jtrigger = triggers->end();
//   for ( ; itrigger != jtrigger; ++itrigger ) {

//     // Check if trigger fired
//     if ( !itrigger->second ) { continue; }
    
//     // Filter triggers based on names and/or filters
//     if ( !filter.empty() ) {
//       Names::const_iterator iname = names.begin();
//       Names::const_iterator jname = names.end();
//       for ( ; iname != jname; ++iname ) {
// 	if ( Algorithm::compare( iname->c_str(), itrigger->c_str() ) ) { break; }
//       }
//       // If no match, continue to next trigger in map
//       if ( iname == jname ) { continue; }
//     }
    
//     // Find corresponding prescale
//     PrescaleMap::const_iterator iprescale = prescales->find(itrigger->first);
//     if ( iprescale != prescales->end() ) { 
      
//       Triggers::const_iterator iter = trigs.find(itrigger->first);
//       if ( iter == trigs.end() ) {
// 	// If trigger name not found
// 	trigs[itrigger->first][iprescale->second] = weight;
//       } else {
// 	if ( iter->second.find(iprescale->second) == iter->second.end() ) {
// 	  // If trigger name found but prescale not found
// 	  trigs[itrigger->first][iprescale->second] = weight;
// 	} else {
// 	  // If both trigger name and prescale found
// 	  trigs[itrigger->first][iprescale->second] += weight;
// 	}
//       }

//     }
//   }

// } 

// -----------------------------------------------------------------------------
//
void Algorithms::triggers( const Event::Data& ev, 
			   Triggers& trigs, 
			   int yaxis ) {
  Names null;
  triggers(ev,null,trigs,yaxis);
}

// -----------------------------------------------------------------------------
//
void Algorithms::triggers( const Event::Data& ev, 
			   const Names& names,
			   Triggers& trigs, 
			   int yaxis ) {
  
  // Check if trigger container is valid
  if ( !ev.hltHandleValid() ) {
    std::cout << "[Trigger::triggers] Invalid handle to HLT trigger bits!" << std::endl;
    return;
  }
    
  // Retrieve info from event
  const TriggerMap* triggers = ev.hlt();
  const PrescaleMap* prescales = ev.hlt_prescaled();
  
  // Y-axis info ( 0=Prescales, 1=RunNumber(z=Nevents), 2=RunNumber(z=Prescales) ... )
  int yval = 0;
  if ( yaxis == 1 || yaxis == 2 ) { yval = ev.GetRunNumber(); }
  
  // Loop through trigger map
  TriggerMap::const_iterator itrigger = triggers->begin(); 
  TriggerMap::const_iterator jtrigger = triggers->end();
  for ( ; itrigger != jtrigger; ++itrigger ) {
    
    // Check if trigger fired
    if ( !itrigger->second ) { continue; }
    
    // Filter triggers based on names and/or filters
    Names::const_iterator iname = names.begin();
    Names::const_iterator jname = names.end();
    for ( ; iname != jname; ++iname ) {
      if ( Algorithms::compare( iname->c_str(), itrigger->first.c_str() ) ) { break; }
    }
    // If no match, continue to next trigger in map
    if ( iname == jname ) { continue; }

    // Find corresponding prescale
    PrescaleMap::const_iterator iprescale = prescales->find(itrigger->first);
    if ( iprescale != prescales->end() ) { 
      
      // Prescale
      if ( yaxis == 0 ) { yval = iprescale->second; }
      
      // Construct string encoding trigger and its prescale
      std::stringstream trigger; 
      if      ( yaxis == 0 || yaxis == 2 ) { trigger << itrigger->first; }
      else if ( yaxis == 1 ) { trigger << itrigger->first << "_" << iprescale->second; }

      double weight = 1.;
      if ( yaxis == 2 ) { weight = iprescale->second; }
      
      Triggers::const_iterator iter = trigs.find(trigger.str());
      if ( iter == trigs.end() ) {
	// If trigger name not found
	trigs[trigger.str()][yval] = weight;
      } else {
	if ( iter->second.find(yval) == iter->second.end() ) {
	  // If trigger name found but prescale not found
	  trigs[trigger.str()][yval] = weight;
	} else {
	  // If both trigger name and prescale found
	  if ( yaxis != 2 ) trigs[trigger.str()][yval] += weight;
	  //else if ( weight < trigs[trigger.str()][yval] ) trigs[trigger.str()][yval] = weight; //@@ lowest prescale
	  else if ( weight > trigs[trigger.str()][yval] ) trigs[trigger.str()][yval] = weight; //@@ highest prescale
	}
      }

    }
  }

} 

// -----------------------------------------------------------------------------
//
void Algorithms::triggers( const Event::Data& ev, 
			   const std::string& filter ) {
  
  // Check if trigger container is valid
  if ( !ev.hltHandleValid() ) {
    std::cout << "[Trigger::triggers] Invalid handle to HLT trigger bits!" << std::endl;
    return;
  }
  
  // Retrieve trigger and prescale info from event
  const TriggerMap* triggers = ev.hlt();
  const PrescaleMap* prescales = ev.hlt_prescaled();
  
  // Print trigger table and prescale
  std::stringstream ss;
  ss << "[Trigger::triggers]"
     << " Found " << triggers->size() 
     << " triggers and " << prescales->size() << " prescales:"
     << std::endl;

  int index = 0;
  for ( TriggerMap::const_iterator ii = triggers->begin(); ii != triggers->end(); ++ii ) {
    PrescaleMap::const_iterator iter = prescales->find(ii->first);
    if ( iter != prescales->end() ) { 
      if ( iter->second > 1 ) {
	ss << " trigger #" << index << " called \"" << ii->first << "\" is prescaled by a factor " << iter->second << std::endl;
      } else {
	ss << " trigger #" << index << " called \"" << ii->first << "\" (is unprescaled)" << std::endl;
      }
    } else {
      ss << " No prescale found for trigger #" << index << " called \"" << ii->first << "\"!" << std::endl;
    }
    index++;
  }
  std::cout << ss.str();

} 

// -----------------------------------------------------------------------------
//
int Algorithms::triggers( const Event::Data& ev, 
			  const Names& filters ) {
  Names null;
  return triggers(ev,filters,null);
}

// -----------------------------------------------------------------------------
//
int Algorithms::triggers( const Event::Data& ev, 
			  const Names& filters, 
			  Names& fired ) {
  Vars null;
  return triggers(ev,null,filters,fired,-1);
}

// -----------------------------------------------------------------------------
//
int Algorithms::triggers( const Event::Data& ev, 
			  const Vars& reco,
			  const Names& filters, 
			  double at_threshold ) {
  Names null;
  return triggers(ev,reco,filters,null,at_threshold);
}

// -----------------------------------------------------------------------------
//
int Algorithms::triggers( const Event::Data& ev, 
			  const Vars& reco,
			  const Names& filters, 
			  Names& fired, 
			  double at_threshold ) {
  
  // No triggers specified
  if ( filters.empty() ) { return -1; }
  
  // Check if trigger container is valid
  if ( !ev.hltHandleValid() ) {
    std::cout << "[Trigger::triggers] Invalid handle to HLT trigger bits!" << std::endl;
    return -1;
  }
  
  // Prescale value
  int prescale = -1; 
  fired.clear();
  
  // Iterate through filters
  Names::const_iterator ifilter = filters.begin();
  Names::const_iterator jfilter = filters.end();
  for ( ; ifilter != jfilter; ++ifilter ) {
    
    // Iterate through trigger map
    const TriggerMap* triggers = ev.hlt();
    TriggerMap::const_iterator itrigger = triggers->begin();
    TriggerMap::const_iterator jtrigger = triggers->end();
    for ( ; itrigger != jtrigger; ++itrigger ) {
      
      // Check if trigger passes the filter 
      if ( !Algorithms::compare( ifilter->c_str(), itrigger->first.c_str() ) ) { continue; }
      //else { std::cout << " Match b/w " << *ifilter << " and " << itrigger->first << std::endl; }
      
      // Find prescale
      const PrescaleMap* prescales = ev.hlt_prescaled();
      std::map<std::string,int>::const_iterator iprescale = prescales->find(itrigger->first);
      if ( iprescale == prescales->end() ) { 
	continue; 
      }
      
      // Check if trigger fired
      if ( !itrigger->second ) { continue; }
    
      // Extract HT value
      double trigger_ht = -1.;
      size_t pos = itrigger->first.find("HLT_HT");
      std::string substr = itrigger->first.substr(6,3);
      if ( pos != std::string::npos ) { trigger_ht = 1.*atoi( substr.c_str() ); }
      
      // HT signal trigger names have >12 characters and two additional "_" characters
      bool signal_trigger = 
	( itrigger->first.size() > 12 ) && ( itrigger->first.substr(12).find("_") != std::string::npos );
      
      // HT monitor trigger names comprise exactly 12 characters
      bool monitor_trigger = ( itrigger->first.size() == 12 );
      
      // Use only HT monitor (signal) triggers for left (right) side; use unprescaled HT monitor triggers always
      bool use_trigger = ( ( at_threshold < 0. ) || 
			   ( signal_trigger  && ( reco.at() > at_threshold ) ) || 
			   ( monitor_trigger && ( reco.at() < at_threshold ) ) ); //||
      // ( monitor_trigger && iprescale->second == 1 ) );
      
      // HT offset to guarantee plateau
      double offset = 1.e-3;
      
      // Store lowest prescale of triggers that fire
      if ( use_trigger ) {
	if ( at_threshold < 0. ) fired.push_back(itrigger->first);
	if ( ( bins_[bin_] + offset ) > trigger_ht ) { 
	  if ( at_threshold >= 0. ) fired.push_back(itrigger->first);
	  if ( prescale < 0 || iprescale->second < prescale ) { 
	    prescale = iprescale->second; 
	  }
	}
      }

    }
  }
  
  return prescale;
  
} 

//-----------------------------------------------------------------------------
//
int Algorithms::compare( const char* wild, const char* string ) {
  
  const char *cp = NULL, *mp = NULL;
  
  while ((*string) && (*wild != '*')) {
    if ((*wild != *string) && (*wild != '?')) {
      return 0;
    }
    wild++;
    string++;
  }
  
  while (*string) {
    if (*wild == '*') {
      if (!*++wild) {
        return 1;
      }
      mp = wild;
      cp = string+1;
    } else if ((*wild == *string) || (*wild == '?')) {
      wild++;
      string++;
    } else {
      wild = mp;
      string = cp++;
    }
  }
  
  while (*wild == '*') {
    wild++;
  }
  return !*wild;

}

//-----------------------------------------------------------------------------
//
/*
void Algorithms::triggers( const Event::Data& ev, const Names& filters, const Names& triggers ) {

  // Check if trigger container is valid
  if ( !ev.hltHandleValid() ) {
    std::cout << "[Trigger::triggers] Invalid handle to HLT trigger bits!" << std::endl;
    return;
  }

  // Retrieve trigger and prescale info from event
  if ( !names.empty() ) {
    std::vector<std::string>::const_iterator iname = names.begin();
    std::vector<std::string>::const_iterator jname = names.end();
    for ( ; iname != jname; ++iname ) {
      
      // Find trigger 
      std::map<std::string,bool>::const_iterator itrigger = triggers->find(*iname); 
      if ( itrigger == triggers->end() ) { 
	continue; 
      }
      
      // Find prescale
      const PrescaleMap* prescales = ev.hlt_prescaled();
      std::map<std::string,int>::const_iterator iprescale = prescales->find(itrigger->first);
      if ( iprescale == prescales->end() ) { 
	continue; 
      }
  
  triggers.clear();
  if ( !filters.empty() ) {
    Names::const_iterator ii = filters.begin();
    Names::const_iterator jj = filters.begin();
    for ( ; ii != jj; ++ii ) {
      if ( Algorithms::compare( ii->c_str(),  ) )
	}
  } else {
    
  }

  
}
*/



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// Tanja's dead ECAL code
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
//
bool Algorithms::noOverlapWithDeadEcal( const Event::Data& ev,
					const Vars& reco,
					const Vars& baby ) {
  
  double biasedDPhi = 100;

  float deadECALDR = 10;

  LorentzV loweredMHT = reco.mht();//met(ev);
  for(std::vector<LorentzV>::const_iterator iM = baby.jets().begin();iM != baby.jets().end();++iM){
    if( (iM)->Pt() > minBabyJetPt_)
      loweredMHT -= (*iM);
  }

  for( std::vector<LorentzV>::const_iterator i = reco.jets().begin();
       i != reco.jets().end();
       ++i ){

    float newBiasDPhi = fabs(ROOT::Math::VectorUtil::DeltaPhi(*i,loweredMHT + (*i))) ;

    if(newBiasDPhi < biasedDPhi){
      biasedDPhi = newBiasDPhi;
      if (useFile_) { deadECALDR = DeadECALDR_File(deadEcalFile_,(i)->Phi(),(i)->Eta(),nBadCells_); }
      else {
	try{deadECALDR = DeadECALDR( ev,(i)->Phi(),(i)->Eta(),nBadCells_);}
	catch(...){
	  deadECALDR = DeadECALDR_File(deadEcalFile_,(i)->Phi(),(i)->Eta(),nBadCells_);
        }
      }
    }
  }

  for( std::vector<LorentzV>::const_iterator iI = baby.jets().begin(); iI != baby.jets().end();
       ++iI) {
    if((iI)->Pt() > minBabyJetPt_){
      float newBiasDPhi_2 = fabs(ROOT::Math::VectorUtil::DeltaPhi(*iI, loweredMHT + (*iI) )) ;
      if(newBiasDPhi_2 < biasedDPhi){
	biasedDPhi = newBiasDPhi_2;
	if (useFile_) { deadECALDR = DeadECALDR_File(deadEcalFile_,(iI)->Phi(),(iI)->Eta(),nBadCells_); }
	else {
	  try{deadECALDR = DeadECALDR(ev,(iI)->Phi(),(iI)->Eta(),nBadCells_);}
	  catch(...){
	    deadECALDR = DeadECALDR_File(deadEcalFile_,(iI)->Phi(),(iI)->Eta(),nBadCells_);
	  } 
	} 
      }
    }
  }
  
  if( biasedDPhi < maxBiasDeltaPhi_ ){
    if(deadECALDR < maxDrToDeadEcalRegion_)return false;
  }
  
  return true;
  
}

// -----------------------------------------------------------------------------
//
double Algorithms::DeadECALDR( const Event::Data& ev,float jetphi,float jeteta, int nBad){
  double DRmin = 100;
  TLorentzVector testjetVec(0,0,0,0);
  TLorentzVector testVec(0,0,0,0);
  int idx = 0;
 
  testjetVec.SetPtEtaPhiE(100,jeteta,jetphi,100);
  for(std::vector<PolarLorentzV>::const_iterator ii=ev.ecalDeadTowerTrigPrimP4()->begin();ii!=ev.ecalDeadTowerTrigPrimP4()->end();++ii,++idx){
    if((int)ev.ecalDeadTowerNBadXtals()->at(idx) >= nBad){//hard coded I know
      testVec.SetPtEtaPhiE(100,(*ii).Eta(),(*ii).Phi(),100);
      float DR = fabs(ROOT::Math::VectorUtil::DeltaR(*ii,testjetVec));
      if(DR < DRmin) DRmin = DR;
    }
    
  }

  return DRmin;
}

//-----------------------------------------------------------------------------
//
double Algorithms::DeadECALDR_File( const std::string& deadECALfile,float jetphi,float jeteta, int nBad){
  // cout << " hi ho " << deadECALfile << endl;
  TLorentzVector testjetVec(0,0,0,0);
  double DRmin = 100;
  testjetVec.SetPtEtaPhiE(100,jeteta,jetphi,100);

  //cout << " in dead ecal " << endl;
  ifstream myfile(deadECALfile.c_str());
  if(!myfile.good()) cout << "File is not there " << endl;
  if(myfile.is_open()){

    while(!myfile.eof()){

      float phi,eta;
      int iEta,iPhi,nBadCells;
      myfile>>eta;
      myfile>>phi;
      myfile>>iEta;
      myfile>>iPhi;
      myfile>>nBadCells;
      // cout <<eta<< " "<< phi<<endl;
      if(nBadCells >= nBad){
	TLorentzVector testVec(0,0,0,0);
	testVec.SetPtEtaPhiE(100,eta,phi,100);
	float DR = fabs(ROOT::Math::VectorUtil::DeltaR(testVec,testjetVec));
	if(DR < DRmin) DRmin = DR;
      }
    }
   
    myfile.close();
  } 
  return DRmin;

} 

