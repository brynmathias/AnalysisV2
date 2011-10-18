/*! \file SmearSuite.hh
 * \brief Header file for smearing Lorentz vectors.
 */

#ifndef SmearSuite_hh
#define SmearSuite_hh

#include <TMath.h>
#include <TLorentzVector.h>
#include <TH1F.h>
#include <TF1.h>
#include <cstdlib>
//lets see if it stays here
#include <TRandom.h>

using namespace std;

namespace Event {

   /*! \brief Gaussian smearing of the pt of the lorentz vectors given as input with a certain smearing factor
     * @param objects [in] Lorentz Vector and smearFactor
     * @return nothing
     */

  //implement gaussian jet p smearing
  void smearPt(TLorentzVector & lorVec,float smearFactor);

   /*! \brief Gaussian + Non-Gaussian response adding with a certain normalization
     * factor. Assumes that the two histograms have the same range and bin numbers
     * @param objects [in] normalization, Gaussian histogram, and Non-Gaussain histogram
     * @return response histogram
     */

  //implement gaussian+non-gaussian response adding
  TH1F* makeResponseFunction(float nonGaussianNormalization, TH1F* gaussianPart, TH1F* nonGaussianPart);

   /*! \brief Gaussian + Non-Gaussian smearing of the pt of the lorentz vectors given as input with a response function
     * @param objects [in] Lorentz Vector and response function histogram
     * @return nothing
     */

  //implement gaussian+non-gaussian jet p smearing
  void smearPtFunction(TLorentzVector & lorVec, TH1F* responseFunc);

    /*! \brief  Gaussian smearing of the phi of the lorentz vectors given as input with a certain smearing factor
     * @param objects [in] Lorentz Vector and smearFactor
     * @return nothing
     */

  void smearPhi(TLorentzVector & lorVec, float smearFactor);

  void scalePt(TLorentzVector & lorVec, float scaleFactor, float etaMin, float etaMax);

} // ~namespace Event

#endif // ~SmearSuite.hh











