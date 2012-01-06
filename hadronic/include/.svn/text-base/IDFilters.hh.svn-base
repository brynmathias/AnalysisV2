/*! \file IDFilters.hh
 * \brief Header file for the 
 */
#ifndef Hadronic_IDFilters_hh
#define Hadronic_IDFilters_hh

#include "Lepton.hh"
#include "Photon.hh"
#include "Utils.hh"

namespace Hadronic {
	  
	namespace Muon {
		struct CutSet {
			//id variables
			bool requireTrackerMuon;
			bool requireGlobalMuon;
			double chiSquaredCut;
			int numChambersCut; // 38 ntuples...
			int numGlobalHits;
			int numTrackerHits;
			int numPixelHits; // 38 ntuples...
			double dxyCut;
		};
		class IDFilter : public Compute::ObjectFilter<Event::Lepton> {
		 public:
			 IDFilter(const Utils::ParameterSet& ps);
		  ~IDFilter();
		  bool Apply( Event::Lepton* );
		  std::ostream & Description( std::ostream& );
		 private:
			bool verbose_;
			CutSet loose_;
			CutSet tight_;
		};//end of class Muon::IDFilter
	}//end of namespace Muon


	namespace Electron {
		template <class T>
		struct CutValue {
			T b; //!< Barrel value.
			T e; //!< Endcap value.
		};
		struct CutSet {
			//isolation
			CutValue<double> trkIso;
			CutValue<double> eclIso;
			CutValue<double> hclIso;
			CutValue<double> cmbIso;
			//conversion rejection
			CutValue<int>    convNumHits;
			CutValue<double> convDcot;
			CutValue<double> convDist;
			//id variables
			CutValue<double> sigmaIEtaIEta; //!< Shower shape variable.
			CutValue<double> deltaPhiAtVtx; //!< Spatial matching between track and supercluster - Delta phi.
			CutValue<double> deltaEtaAtVtx; //!< Spatial matching between track and supercluster - Delta eta.
			CutValue<double> hcalOverEcal;  //!< Hadronic energy found within 0.15 of ECAL cluster over ECAL energy.
		};

		/*! \brief Allows the (RA1) user to set "Loose" and "Tight" ID according to custom variables.
		 *
		 * @author Tom Whyntie
		 * @date October 2010
		 * @version 1.0
		 *
		 * The idea is to implement a custom ID scheme (for example, the Vector Boson Task Force
		 * electron ID) quickly and without interfering with the rest of the framework.
		 * This filter class, when applied before cross-cleaning, changes the ID based
		 * on the cut variables defined above and the values supplied in the PSet
		 * provided in the constructor.
		 *
		 * To use, create an ElectronFilter like this:
		 * > from ra1objectid.vbtfElectronId_cff import * #default POG values
     * > electronIDfilter = Electron_IDFilter(vbtfelectronidps.ps())
		 * then add it to your analysis like so:
		 * > def addCutFlowData(a) :
     * > a.AddElectronFilter("PreCC",electronIDfilter)
     * > a+=cutTreeData #or whatever...
	 	 */
		class IDFilter : public Compute::ObjectFilter<Event::Lepton> {
	 	 public:
	  	IDFilter(const Utils::ParameterSet& ps);
	  	~IDFilter();
	  	bool Apply( Event::Lepton* );
	  	std::ostream & Description( std::ostream& );
	 	 private:
			bool verbose_; //!< cout statements
			bool useCmbIso_;

			CutSet loose_; //!< Loose cut set.
			CutSet tight_; //!< Tight cut set.
		};//end of class Electron::IDFilter
	}//end of namespace Electron


	namespace Photon {
		template <class T>
		struct CutValue {
			T b; //!< Barrel value.
			T e; //!< Endcap value.
		};
		struct CutSet {
			//isolation
			CutValue<double> trkIsoC; //!< Track isolation constant cut value ("C" on straight line plot).
			CutValue<double> trkIsoB; //!< Track isolation pT dependent cut value ("B" on straight line plot).
			CutValue<double> eclIsoC;
			CutValue<double> eclIsoB;
			CutValue<double> hclIsoC;
			CutValue<double> hclIsoB;
			//id variables
			CutValue<double> sigmaIEtaIEta;  //!< Shower shape variable.
			CutValue<double> hcalOverEcal;   //!< Hadronic energy found within 0.15 of ECAL cluster over ECAL energy.
			bool requireNoPixelSeed;           //!< Implements the track veto.
		 
		};

		/*! \brief Allows the (RA1) user to set "Loose" and "Tight" ID according to custom variables.
		 *
		 * @author Tom Whyntie
		 * @date October 2010
		 * @version 1.0
		 *
		 * The idea is to implement a custom ID scheme (for example, the RA3
		 * photon ID) quickly and without interfering with the rest of the framework.
		 * This filter class, when applied before cross-cleaning, changes the ID based
		 * on the cut variables defined above and the values supplied in the PSet
		 * provided in the constructor.
		 *
		 * To use, create an PhotonFilter like this:
		 * > from ra1objectid.ra3PhotonId_cff import * #default RA3 values
     * > photonIDfilter = Photon_IDFilter(ra3photonidps.ps())
		 * then add it to your analysis like so:
		 * > def addCutFlowData(a) :
     * > a.AddPhotonFilter("PreCC",photonIDfilter)
     * > a+=cutTreeData #or whatever...
	 	 */
		class IDFilter : public Compute::ObjectFilter<Event::Photon> {
	 	 public:
	  	IDFilter(const Utils::ParameterSet& ps);
	  	~IDFilter();
	  	bool Apply( Event::Photon* );
	  	std::ostream & Description( std::ostream& );
	 	 private:
			bool verbose_; //!< cout statements

			CutSet loose_; //!< Loose cut set.
			CutSet tight_; //!< Tight cut set.
		};//end of class Photon::IDFilter
	}//end of namespace Photon
	  
}//end of namespace Hadronic

#endif
