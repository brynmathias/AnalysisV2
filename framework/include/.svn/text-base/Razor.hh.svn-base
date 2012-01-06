#ifndef hadronic_include_Razor_hh
#define hadronic_include_Razor_hh

#include <algorithm>
#include <cmath>
#include <functional>
#include <numeric>
#include <vector>



struct Razor {


  // -----------------------------------------------------------------------------
  //
  template<class LorentzV>
  double operator()( const std::vector<LorentzV const *>& p4, 
		     std::vector<bool>& pseudo_jet1,
		     LorentzV pfMET,
		     bool calc_MR = true ) const {  
    
    if ( p4.size() == 0 ) { return 0; }
    
    std::vector<double> e;  
    std::vector<double> px;  
    std::vector<double> py;  
    std::vector<double> pz;  
    pseudo_jet1.clear();
    
    transform( p4.begin(), p4.end(), back_inserter(e), std::mem_fun(&LorentzV::Et) );
    transform( p4.begin(), p4.end(), back_inserter(px), std::mem_fun(&LorentzV::Px) );
    transform( p4.begin(), p4.end(), back_inserter(py), std::mem_fun(&LorentzV::Py) );
    transform( p4.begin(), p4.end(), back_inserter(pz), std::mem_fun(&LorentzV::Pz) );

    double met_px = pfMET.Px();
    double met_py = pfMET.Py();
    double met_pt = pfMET.Pt();

    return value( e, px, py, pz, pseudo_jet1, met_px, met_py, met_pt, calc_MR );

  }


  // -----------------------------------------------------------------------------
  //
  template<class LorentzV>
  double operator()( const std::vector<LorentzV>& p4, 
		     std::vector<bool>& pseudo_jet1,
		     LorentzV pfMET,
		     bool calc_MR = true ) const {  
    
    if ( p4.size() == 0 ) { return 0; }
    
    std::vector<double> e;  
    std::vector<double> px;  
    std::vector<double> py;  
    std::vector<double> pz;  

    transform( p4.begin(), p4.end(), back_inserter(e), std::mem_fun_ref(&LorentzV::Et) );
    transform( p4.begin(), p4.end(), back_inserter(px), std::mem_fun_ref(&LorentzV::Px) );
    transform( p4.begin(), p4.end(), back_inserter(py), std::mem_fun_ref(&LorentzV::Py) );
    transform( p4.begin(), p4.end(), back_inserter(pz), std::mem_fun_ref(&LorentzV::Pz) );

    double met_px = pfMET.Px();
    double met_py = pfMET.Py();
    double met_pt = pfMET.Pt();

    return value( e, px, py, pz, pseudo_jet1, met_px, met_py, met_pt, calc_MR );
    
  }

  // -----------------------------------------------------------------------------
  //
  static double value( const std::vector<double>& e,
		       const std::vector<double>& px,
		       const std::vector<double>& py,
		       const std::vector<double>& pz,
		       std::vector<bool>& pseudo_jet1,
		       double met_px,
		       double met_py,
		       double met_pt,
		       bool calc_MR,
		       bool list = true ) {

    // Clear pseudo-jet container
    pseudo_jet1.clear();
    
    // Momentum sums 
    const double sum_e = accumulate( e.begin(), e.end(), 0. );
    const double sum_px = accumulate( px.begin(), px.end(), 0. );
    const double sum_py = accumulate( py.begin(), py.end(), 0. );
    const double sum_pz = accumulate( pz.begin(), pz.end(), 0. );
    
    // Find the minimum InvMass for two mega-jets
    double min_inv_mass = -1.;

    // construct the mega-jets
    TLorentzVector megajet1;
    TLorentzVector megajet2;

    for ( unsigned i=0; i < unsigned(1<<(e.size()-1)); i++ ) { //@@ iterate through different combinations

      double tmp_e_1  = 0.; double tmp_e_2  = 0.;
      double tmp_px_1 = 0.; double tmp_px_2 = 0.;
      double tmp_py_1 = 0.; double tmp_py_2 = 0.;
      double tmp_pz_1 = 0.; double tmp_pz_2 = 0.;

      double tmp_inv_mass = -999.;

      std::vector<bool> jet; 

      for ( unsigned j=0; j < e.size(); j++ ) { //@@ iterate through jets

	if ( (int(i>>j)&1) ) {
	  tmp_e_1  += ( e[j] );
	  tmp_px_1 += ( px[j] );
	  tmp_py_1 += ( px[j] );
	  tmp_pz_1 += ( px[j] );
	} 
	else {
	  tmp_e_2  += ( e[j] );
	  tmp_px_2 += ( px[j] );
	  tmp_py_2 += ( px[j] );
	  tmp_pz_2 += ( px[j] );
	}


	if ( list ) { jet.push_back( (int(i>>j)&1) == 0 ); } 
      }

      // construct the "tmp" mega-jets
      TLorentzVector tmp_megajet1;
      TLorentzVector tmp_megajet2;

      tmp_megajet1.SetPxPyPzE(tmp_px_1,tmp_py_1,tmp_pz_1,tmp_e_1);
      tmp_megajet2.SetPxPyPzE(tmp_px_2,tmp_py_2,tmp_pz_2,tmp_e_2);

      tmp_inv_mass = sqrt( pow(tmp_megajet1.M(),2) + pow(tmp_megajet2.M(),2) );

      if ( (tmp_inv_mass < min_inv_mass || min_inv_mass < 0. ) ) {
	min_inv_mass = tmp_inv_mass;

	megajet1.SetPxPyPzE(tmp_megajet1.Px(),tmp_megajet1.Py(),tmp_megajet1.Pz(),tmp_megajet1.E());
	megajet2.SetPxPyPzE(tmp_megajet2.Px(),tmp_megajet2.Py(),tmp_megajet2.Pz(),tmp_megajet2.E());

	/*
	if ( list && jet.size() == e.size() ) {
	  pseudo_jet1.resize(jet.size());
	  std::copy( jet.begin(), jet.end(), pseudo_jet1.begin() );
	}
	*/
      }
    }
    //    if ( min_inv_mass < 0. ) { return 0.; }
   
    double result = -999.;

    if (calc_MR) {
      // calculate M^{R}
      result = sqrt( pow((megajet1.E()+megajet2.E()),2) + pow((megajet1.Pz()+megajet2.Pz()),2) );
    }
    else {
      // calculate M^{R}_{T}
      result = sqrt( 0.5*( 
			  met_pt*( megajet1.Pt()+megajet2.Pt() )
			  - ( (met_px*(megajet1.Px()+megajet2.Px())) + (met_py*(megajet1.Py()+megajet2.Py())) )   
			  ) );
    }
    
    // Razor
    return result;


  }
  
  // -----------------------------------------------------------------------------
  //
  static double value( const std::vector<double>& e,
		       const std::vector<double>& px,
		       const std::vector<double>& py,
		       const std::vector<double>& pz
		       ) {
    std::vector<bool> pseudo_jet1;
    double met_px, met_py, met_pt;
    bool calc_MR;
    return value( e, px, py, pz, pseudo_jet1, met_px, met_py, met_pt, calc_MR, false );
  }
  
};

#endif // hadronic_include_Razor_hh
