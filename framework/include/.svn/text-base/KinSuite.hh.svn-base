/*! \file KinSuite.hh
 * \brief Header file for the Kinematic Suite of helper functions.
 */

#ifndef KinSuite_hh
#define KinSuite_hh

#include <vector>
#include <iostream>

#include <TROOT.h>
#include "Types.hh"
using namespace std;

namespace Event {
  // Forward declarations
  class GenObject;
  class Photon;
  class Jet;
}

namespace KinSuite {
  bool Compare(const LorentzV & o1, const LorentzV & o2);
  bool PCompare(const LorentzV * o1, const LorentzV * o2);
}

namespace Event {

  /*! \brief Calculates the azimuthal $\Delta \phi$ angle between the supplied vector
   * and the Common Object Recoil MET.
   *
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   * @param [in] vec1
   * @return The azimuthal $\Delta \phi$ angle between vec1 and the event's common object Recoil MET
   */
  float KS_comRecoilMetdPhi(LorentzV* vec1);

  /*! \brief Returns the %\Delta \phi$ angle between the supplied vector and the event's common
   * object recoil MET \emph{with the supplied vector's contribution removed}.
   * \author Markus Stoye
   * \date February 2009
   * \version 1.0
   * @param [in] vec1 Pointer to vector under consideration.
   * @return The biased $\Delta \phi$.
   */
  float KS_biasedComRecoilMetdPhi(LorentzV* vec1);

  /*! \brief Returns the 4-vector sum of the vector of LVs supplied.
   * @param objects [in] Vector of Lorentz Vectors representating physics objects.
   * @return A LorentzV 4-vector sum of the physics objects supplied.
   */
  LorentzV KS_4VecSum(const std::vector<LorentzV> & objects);

  /*! \brief Returns the 4-vector recoil (E +ve, \vec{p} -ve) of the LVs supplied.
   * @param objects [in] Vector of Lorentz Vectors representating physics objects.
   * @return The recoil 4-vector (E +ve, \vec{p} -ve)
   */
  LorentzV KS_Recoil(const std::vector<LorentzV> & objects);

  /*! \brief Returns the transverse magnitude of the recoil momentum (i.e. Pt).
   *
   * Note that this is the same as the 4VecSum transverse momentum magnitude ;)
   * @param objects [in] Vector of Lorentz Vectors representating physics objects.
   * @return The transverse magnitude of the recoil momentum.
   */
  Double_t KS_RecoilPt(const std::vector<LorentzV> & objects);

  /*! \brief Calculates the sum of the transverse energies of the vector of LVs.
   *
   * Don't forget that this is different to the Et of the sum of the vectors ;)
   * @param objects [in] Vector of Lorentz Vectors representating physics objects.
   * @return The sum of the Et of the objects.
   */
  Double_t KS_SumET(const std::vector<LorentzV> & objects);

  Double_t KS_M(const std::vector<LorentzV> & objects);

  /*! \brief Calculates the transverse mass of a vector of LVs.
   * @param objects [in] Vector of Lorentz Vectors representing physics objects.
   * @return The transverse mass of the objects.
   */
  Double_t KS_MT(const std::vector<LorentzV> & objects);
  Double_t KS_MT(const std::vector<Event::Jet const *> & objects);

  /*! \brief Calculates the "traditional" min. $\Delta \phi (p_i, \slash{p}_n)$ for the supplied objects.
   * @param objects [in] Vector of Lorentz Vectors representing physics objects.
   * @return The minimum DPhi between the object_i and the objects' recoil.
   */
  Double_t KS_MinDPhi(const std::vector<LorentzV> & objects);

  /*! \brief Calculates the "traditional" min. $\Delta \phi (p_i, \slash{p}_n)$ for the supplied objects.
   * @param recoil [in] Pre-calculated recoil vector for the V of LVs.
   * @param objects [in] Vector of Lorentz Vectors representing physics objects.
   * @return The minimum DPhi between the object_i and the objects' recoil.
   */
  Double_t KS_MinDPhi(const LorentzV & recoil, const std::vector<LorentzV> & objects);

  /*! \brief Calculates the "biased" min. $\Delta \phi (p_i, \slash{p}_n+p_i)$ for the supplied objects.
   * @param objects [in] Vector of Lorentz Vectors representing physics objects.
   * @return The minimum biased DPhi between the object_i and the objects' recoil.
   */
  Double_t KS_MinBiasDPhi(const std::vector<LorentzV> & objects);

  /*! \brief Calculates the "biased" min. $\Delta \phi (p_i, \slash{p}_n+p_i)$ for the supplied objects.
   * @param recoil [in] Pre-calculated recoil vector for the V of LVs.
   * @param objects [in] Vector of Lorentz Vectors representing physics objects.
   * @return The minimum biased DPhi between the object_i and the objects' recoil.
   */
  Double_t KS_MinBiasDPhi(const LorentzV & recoil, const std::vector<LorentzV> & objects);

  UInt_t KS_MinDEt_MaxN(); //!< Returns the maximum number of objects that the code can handle.

  /*! \brief
   */
  Double_t KS_MinDEt(const std::vector<LorentzV> & objects, std::vector<UInt_t> * lista = NULL, std::vector<UInt_t> * listb = NULL);
  Double_t KS_MinDEt(const std::vector<Event::Photon const *> & objects, std::vector<UInt_t> * lista = NULL, std::vector<UInt_t> * listb = NULL);
  Double_t KS_MinDEt(const std::vector<Event::Jet const *> & objects, std::vector<UInt_t> * lista = NULL, std::vector<UInt_t> * listb = NULL);

  /*! \brief
   */
  Double_t KS_AlphaT(const std::vector<LorentzV> & objects);

  /*! \brief Print out object kinematic information
   * @param object [in] Lorentz Vector.
   * @param option [in] Print option: 0=>E,Et,eta,phi,m...
   * \todo Make a version that simply outputs to a stream, rather than cout?
   */
  void KS_PrintLV(const LorentzV & lv, UInt_t option);

  /*! \brief Print out kinematic information from a vector of objects.
   * @param objects [in] Vector of Lorentz Vectors.
   * @param option [in] Print option: 0=>E,Et,eta,phi,m...
   */
  void KS_PrintLV(const std::vector<LorentzV> & objects, UInt_t option = 0);

  /*! \brief Calculates $\Delta R$ between two lorentz vectors.
   * @param lv1 [in] Lorentz Vector 1.
     * @param lv2 [in] Lorentz Vector 2.
     * @return the $\Delta R$ between the two lorentz vectors.
     */
  Double_t KS_DeltaR(const LorentzV & lv1, const LorentzV & lv2);

  /*! \brief Calculates $\Delta R$ between two lorentz vectors.
   * @param lv1 [in] Lorentz Vector 1.
   * @param lv2 [in] Lorentz Vector 2.
   * @return the $\Delta R$ between the two lorentz vectors.
   */
  Double_t KS_DeltaR(const LorentzV * lv1, const LorentzV * lv2);

  /*! \brief Finds the index of the LV with the smallest $\Delta R$ between test LV and a VLV.
   * @param tlv [in] Test Lorentz Vector.
   * @param vlv [in] Vector of Lorentz Vectors in which to search.
   * @return The index (within the VLV) of the LV with the smallest $\Delta R$.
   */
  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<LorentzV> & vlv);
  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<Event::GenObject const *> & vlv);
  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<Event::Photon> & vlv);
  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<Event::Photon const *> & vlv);
  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<Event::Jet const *> & vlv);

  //UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<LorentzV const &> & vlv);

  UInt_t KS_FindDeltaRMinIndex(const LorentzV * tlv, const std::vector<LorentzV const *> & vlv);

/** \breif Calcultes MT2 using the bisection method from the Oxford Stansverse mass libary
 *  for method see mt2_bisect.hh
**/
    Double_t MT2(const std::vector<LorentzV> & objects);


} // ~namespace Event

#endif // ~KinSuite_hh
