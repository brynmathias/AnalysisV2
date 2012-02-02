#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <stdexcept>

#include "TMatrix.h"
#include "TVector.h"
#include "TH1D.h"
#include "TH2D.h"

/* BinResult
 *
 * BinResult represents the residual (predicted - observed) and associated
 * statistical and systematic errors for a single bin.
 *
 */
class BinResult{
 public:
  BinResult(double predicted, double observed):
      predicted_(predicted),
      observed_(observed){}

  ~BinResult(){}

  void addUncertainty(std::string name, double value, bool systematic=false){
    if(systematic) syst_errors_.push_back(make_pair(name, value));
    else stat_errors_.push_back(make_pair(name, value));
  }

  double residual(){
    return fabs(observed_ - predicted_);
  }

  double predicted(){ return predicted_; }
  double observed(){ return observed_; }

  double totalError(){
    return sqrt(pow(totalStatError(), 2) + pow(totalSystError(), 2));
  }

  double totalStatError(){
    double err = 0;
    error_vector::const_iterator it;
    for(it = stat_errors_.begin(); it != stat_errors_.end(); ++it){
      err += pow(it->second, 2);
    }
    return sqrt(err);
  }

  double totalSystError(){
    double err = 0;
    error_vector::const_iterator it;
    for(it = syst_errors_.begin(); it != syst_errors_.end(); ++it){
      err += pow(it->second, 2);
    }
    return sqrt(err);
  }

  double significance(){
    return residual()/totalError();
  }

  typedef std::vector<std::pair<std::string, double> > error_vector;

  const error_vector & statErrors(){ return stat_errors_; }
  const error_vector & systErrors(){ return syst_errors_; }

  std::string statErrorName(int idx){ return stat_errors_.at(idx).first;}
  double statErrorValue(int idx){ return stat_errors_.at(idx).second;}
  double statErrorValue(std::string name){
    for(error_vector::const_iterator it = stat_errors_.begin();
        it != stat_errors_.end(); ++it){
      if(it->first == name) return it->second;
    }
    throw std::invalid_argument("Stat. Error not found: " + name);
  }
  int nStatErrors(){ return stat_errors_.size(); }

  std::string systErrorName(int idx){ return syst_errors_.at(idx).first;}
  double systErrorValue(int idx){ return syst_errors_.at(idx).second;}
  double systErrorValue(std::string name){
    for(error_vector::const_iterator it = syst_errors_.begin();
        it != syst_errors_.end(); ++it){
      if(it->first == name) return it->second;
    }
    throw std::invalid_argument("Syst. Error not found: " + name);
  }

  int nSystErrors(){ return syst_errors_.size(); }

 private:
  double predicted_;
  double observed_;
  error_vector stat_errors_;
  error_vector syst_errors_;
};

/* BinData
 *
 * BinData represents the numbers from MC and data for a single bin. This would
 * change if a different method was used to make the prediction.
 */
struct BinData{
  double data_signal;
  double data_control;
  double mc_signal;
  double mc_control;

  BinData(TH1D* h_data_signal, TH1D* h_data_control,
          TH1D* h_mc_signal, TH1D* h_mc_control):
      data_signal(h_data_signal->GetBinContent(1)),
      data_control(h_data_control->GetBinContent(1)),
      mc_signal(h_mc_signal->GetBinContent(1)),
      mc_control(h_mc_control->GetBinContent(1))
  {}

  double R(){ return mc_signal/mc_control; }
  double predict(){ return R()*data_control; }
  double observed(){ return data_signal; }
  double control(){ return data_control; }
  double mcSignal(){ return mc_signal; }
  double mcControl(){ return mc_control; }
};


// Take a BinData and make a prediction to give a BinResult Also handles the
// statistical uncertainties.
BinResult createBin(BinData data){
  BinResult r(data.predict(), data.data_signal);
  r.addUncertainty("stat", sqrt(data.predict()));
  r.addUncertainty("stat_control", data.R()*sqrt(data.data_control));
  return r;
}

// Add a systematic contribution to BinResult
void addSystematic(std::string name, BinResult & bin,
                   BinData zero, BinData up, BinData down){
  double syst_R = std::max(fabs(up.R() - zero.R()),
                           fabs(down.R() - zero.R()));
  bin.addUncertainty(name, syst_R*zero.data_control, true);
}

/* CombinedResult
 *
 * Combines several BinResult predictions into a single covariance matrix or
 * chi2 value. Accounts for correlations in the systematics.
 */
class CombinedResult{
 public: CombinedResult(){}

  void addBin(BinResult * bin){
    // If we already have a bin, check the error structures match
    if(bins_.size() > 0){
      // Same number of stat and syst error terms
      if(bin->statErrors().size() != bins_[0]->statErrors().size() ||
         bin->systErrors().size() != bins_[0]->systErrors().size())
        throw std::invalid_argument("Different error structure in bins. Cannot combine.");

      // Same list of stat errors
      for(BinResult::error_vector::const_iterator err = bin->statErrors().begin();
          err != bin->statErrors().end(); ++ err){
        int idx = err - bin->statErrors().begin();
        if(err->first != bins_[0]->statErrors().at(idx).first){
          throw std::invalid_argument("Different error structure in bins: "
                                      + err->first + " vs " +
                                      bins_[0]->statErrors().at(idx).first);
        }
      }
      // Same list of syst errors
      for(BinResult::error_vector::const_iterator err = bin->systErrors().begin();
          err != bin->systErrors().end(); ++ err){
        int idx = err - bin->systErrors().begin();
        if(err->first != bins_[0]->systErrors().at(idx).first){
          throw std::invalid_argument("Different error structure in bins: "
                                      + err->first + " vs " +
                                      bins_[0]->systErrors().at(idx).first);
        }
      }
    }
    bins_.push_back(bin);
  }

  TMatrix getCovarianceMatrix(){
    int nbins = bins_.size();

    // Statistical covariance matrix
    TMatrix cov_stat(nbins, nbins);

    // Loop over bins, adding statistical errors per bin
    std::vector<BinResult*>::iterator bin;
    for(bin = bins_.begin(); bin != bins_.end(); ++bin){
      int idx = bin - bins_.begin();
      // Zero matrix element
      cov_stat(idx, idx) = 0;

      // Add in quadrature sum of individual statistical errors per bin
      BinResult::error_vector::const_iterator err;
      for(err = (*bin)->statErrors().begin();
          err != (*bin)->statErrors().end(); ++err){
        cov_stat(idx, idx) += pow(err->second, 2);
      }
    }

    // Total systematic covariance matrix
    TMatrix cov_syst(nbins, nbins);

    // Loop over individual systematics contributions
    BinResult::error_vector::const_iterator syst;
    for(syst = bins_[0]->systErrors().begin();
        syst != bins_[0]->systErrors().end();
        ++syst){
      int syst_idx = syst - bins_[0]->systErrors().begin();
      // Partial systematic matrix for this term only
      TMatrix cov_syst_i(nbins, nbins);
      // Fill matrix diagonal with systematics
      for(bin = bins_.begin(); bin != bins_.end(); ++bin){
        int idx = bin - bins_.begin();
        cov_syst_i(idx, idx) = (*bin)->systErrors().at(syst_idx).second;
      }

      // Fill off-diagonal terms assuming 100% correlation between bins
      for(int i = 0 ; i < nbins ; ++i){
        for(int j = 0 ; j < nbins ; ++j){
          if(i == j) continue;
          cov_syst_i(i, j) = (bins_[i]->systErrors().at(syst_idx).second *
                              bins_[j]->systErrors().at(syst_idx).second);
        }
      }
      // Sum into total syst covariance matrix
      cov_syst += cov_syst_i;
    }
    // Total covariance matrix is Stat + Syst
    return cov_stat + cov_syst;
  }

  TVector getResiduals(){
     TVector res(bins_.size());

    // Build vector of residuals (predicted - observed)
    std::vector<BinResult*>::const_iterator bin;
    for(bin = bins_.begin(); bin != bins_.end(); ++bin){
      res(bin - bins_.begin()) = (*bin)->residual();
    }
    return res;
  }

  double getChi2(){
    TMatrix cov = getCovarianceMatrix();
    TVector res = getResiduals();

    // Multiply by inverse of covariance matrix
    TVector res_x_cov = res;
    res_x_cov *= cov.Invert();

    // Return chi^2
    return res_x_cov*res;
  }

 private:
  std::vector<BinResult*> bins_;
};





