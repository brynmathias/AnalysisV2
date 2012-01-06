/*! \file EventData.hh
 * \brief Header file for the Event::Data class.
 */
#ifndef EventData_hh
#define EventData_hh

#include "Ntuple.hh"

using namespace std;

#include <vector>
#include <string>
#include <map>
#include <TH1F.h>
#include <TFile.h>

// Computables
#include "JetData.hh"
#include "Compute_Helpers.hh"
#include "LeptonData.hh"
#include "PhotonData.hh"
#include "MCData.hh"
#include "GenData.hh"

#include "Types.hh"
#include "ICF_NtupleData.hh"

#include "Compute_User.hh"
#include "CustomCC.hh"
#include "ThrustStuff.hh"
/**
 * \brief The namespace for everything relating to event data.
 */
namespace Event {



  /*! \brief A wrapper and container class for SUSY ntuple analysis data.
   *
   * \author John Jones
   * \date May 2009
   * \version 2
   *
   * \todo Finish support for photons (i.e. fill common object vector etc.).
   */
class Data : public ND_CLASS {

  public:

    /*! \brief Constructor.
     * @param ntupleData Reference to the event's raw ntuple data.
     * @param weightCorr == -1 to disable
     */
  Data(const Utils::ParameterSet & sample,
       std::map<std::string,Compute::UserBase*> & user_vars,
       std::vector<std::pair<std::string,Compute::ObjectFilter<Event::Lepton>*> >
       & muon_filters,
       std::vector<std::pair<std::string,Compute::ObjectFilter<Event::Lepton>*> >
       & electron_filters,
       std::vector<std::pair<std::string,Compute::ObjectFilter<Event::Lepton>*> >
       & tau_filters,
       std::vector<std::pair<std::string,Compute::ObjectFilter<Event::Photon>*> >
       & photon_filters,
       std::vector<std::pair<std::string,Compute::ObjectFilter<Event::Jet>*> >
       & jet_filters,
       std::vector<std::pair<std::string, Compute::ObjectFilter<ICF_LorentzV>*> > & met_filters,
       Compute::EventWeight::FilterList weight_filters
       );
    /*! \brief Destructor.
     */
    ~Data();

  public:
    // Public access to event data
    //=============================
    //
    // General event data
    //--------------------
    Double_t GetRawEventWeight(); //!< Returns the raw (ntuple) weight of the event.


  void  PrintGen();// Prints out Gen Info collection
  void  PrintGenLeptons();// Prints out GenLeptons Info collection
  float GetR1(LorentzV aMET);
  float GetR2(LorentzV aMET);
  // return index of Genobjet that matches LorentzV in R and has id:id
  int GetMatch(LorentzV aParticle, int id, float R);


  public:

  template<class UserVarType>
  UserVarType & Get(const std::string name){
    if(mUserVars.find(name)!=mUserVars.end())
      return *dynamic_cast<UserVarType*>(mUserVars[name]);
    else
      throw std::invalid_argument("User variable '"+name+"' not found");
  }

    // Get the output TFile
    TFile *OutputFile() const;


 private:
  std::map<std::string,Compute::UserBase*> mUserVars;
  int mCategory;
 public:
  Compute::EventWeight GetEventWeight;
  Compute::WeightProducer WeightProducer;
 public:
  Compute::CustomCC CC;

    // Computable variables - cached
    Compute::RecoilMET RecoilMET;
    Compute::ObjSum ObjSum;
    Compute::SumEt SumEt;
    Compute::CommonHT CommonHT;
    Compute::CommonMHT CommonMHT;
    Compute::CommonMT CommonMT;
    Compute::CommonMinDPhi CommonMinDPhi;
    Compute::CommonMinBiasDPhi CommonMinBiasDPhi;
    Compute::JetMinDPhi JetMinDPhi;
    Compute::JetMinBiasDPhi JetMinBiasDPhi;
    Compute::JetMETMinDPhi JetMETMinDPhi;
    Compute::CommonMinDEt CommonMinDEt;
    Compute::CommonAlphaT CommonAlphaT;
    Compute::LeptonicAlphaT LeptonicAlphaT;
    Compute::HadronicAlphaT HadronicAlphaT;
    Compute::CommonMT2 CommonMT2;
    Compute::CommonRecoilMET CommonRecoilMET;
    Compute::CommonObjectSum CommonObjectSum;
    Compute::CommonRecoil CommonRecoil;
    Compute::CommonSumEt CommonSumEt;
    Compute::CommonRecoilMETJetDPhi CommonRecoilMETJetDPhi;
    Compute::BiasedCommonRecoilMETJetDPhi BiasedCommonRecoilMETJetDPhi;
    Compute::LowPtBiasedCommonRecoilMETJetDPhi LowPtBiasedCommonRecoilMETJetDPhi;
    Compute::CommonObjects CommonObjects;
    Compute::LeptonicObjects LeptonicObjects;
    Compute::HadronicObjects HadronicObjects;
    Compute::CommonJetsAndElectrons CommonJetsAndElectrons;
    Compute::CommonMeff CommonMeff;
    ThrustStuffVar CommonThrustStuff;
    Compute::M3 M3;
    Compute::Razor_MR Razor_MR;
    Compute::Razor_MRt Razor_MRt;
    Compute::Lepton::CommonElectrons LD_CommonElectrons; //!< Vector of commonly-defined electrons.
    Compute::Lepton::CommonMuons LD_CommonMuons; //!< Vector of commonly-defined muons.
    Compute::Lepton::CommonTaus LD_CommonTaus; //!< Vector of commonly-defined muons.

    // Photon data

  Compute::Photon::CommonPhotons PD_CommonPhotons;


  Compute::MC::GenLeptons MC_GenLeptons;
  Compute::MC::SSFinalState MC_SSFinalState;
  Compute::MC::TheLeptons MC_TheLeptons;
  Compute::MC::TheIsolatedLeptons MC_TheIsolatedLeptons;


    // Jet data

    Compute::Jet::CommonJets JD_CommonJets;
    Compute::Jet::EMJets JD_EMJets;

  Compute::Gen::GenMatrix GenMatrix;
 private:
  std::vector<std::pair<std::string,
                        Compute::ObjectFilter<ICF_LorentzV> *> > mMETFilters;
    // Generator level particle data
  public:
    // Public access to preconfigured objects
    //const std::vector<Jet> & GetPreconfJets(); //!< Get a const reference to the preconfigured jets.
    //const std::vector<Photon> & GetPreconfPhotons(); //!< Get a const reference to the preconfigured photons.

    //
    // Kinematic data
    //----------------
    /*! \brief Returns the jet momentum x component.
     *
     * The following types of jets available at present:
     * <ul>
     *   <li>"": The raw, uncorrected PAT jets.</li>
     *   <li>"cc": The cross-cleaned jets.</li>
     * </ul>
     * \param [in] index Index of the jet in the ntuple.
     * \param [in] jettype The type of jet you want to access the px of.
     * \return The x component of the jet of the specified jet type in the ntuple.
     *
     * \todo Add access to all possible jet types stored in the ntuple.
     * \todo Apply Jet Plus Track-corrections to jets if requested.
     *//*
    Double_t GetJetPx(UInt_t index, const Event::Jet::Correction corr_type) const; //!< Jet momentum x component.
    Double_t GetJetPy(UInt_t index, const Event::Jet::Correction corr_type) const; //!< Jet momentum y component.
    Double_t GetJetPz(UInt_t index, const Event::Jet::Correction corr_type) const; //!< Jet momentum z component.
    Double_t GetJetE(UInt_t index, const Event::Jet::Correction corr_type)  const; //!< Jet energy.
    Double_t GetJetEta(UInt_t index, const Event::Jet::Correction corr_type) const; //!< Jet eta.
       */
  private:
    // Cached config values

    // Jets
    std::string mJetType; //!< The type of jet correction used in the analysis run. // DEPRECATE
    //

    string smearJetResponseFuntionFileName;
    double smearJetNonGaussNorm;
    TFile* smearResponseFile;
    TH1F* gaussianRespHist;
    TH1F* nonGaussianRespHist;

    // Output file for data storage
    TFile *mOutputFile;


  public:
    // Kinematic Suite variable access and calculation.
    //    TLorentzVector ComRecoilMET; //!< $\sum{ - \vec{p_T} }$ of all common objects. DEPRECATE
    Double_t ComSumEt;           //!< $\sum{ E_T }$ of all common objects.         DEPRECATE


    //void CalculateComHTMHT(vector<TLorentzVector*>); // MOVE

    // JJ - revised functions
    Double_t hadAlpha_t() const;

  public:
    //=============================================================
    //             Data global helper functions
    //=============================================================
    // This section is for methods that will be used by any object
    // in the event, or indeed any operation that has access to
    // the event data. They do not store any values themselves.
    //
 /*! \brief Calculates LP of two supplied Lorentz Vectors.
     * \author Markus Stoye
     * \date April 2011
     * @param [in] vec1 Pointer to vector 1.
     * @param [in] vec2 Pointer to vector 2.
     * @return The transverse mass of the two vectors.
     * \todo Overload the function to take a std::vector of Lorentz Vectors, perhaps?
     */

    float LP(LorentzV const * vecLepton, LorentzV const* vecWboson) const;


   /*! \brief Calculates the transverse mass of two supplied Lorentz Vectors.
     * \author Markus Stoye
     * \date February 2009
     * @param [in] vec1 Pointer to vector 1.
     * @param [in] vec2 Pointer to vector 2.
     * @return The transverse mass of the two vectors.
     * \todo Overload the function to take a std::vector of Lorentz Vectors, perhaps?
     */
    float MT(LorentzV const * vec1, LorentzV const* vec2) const;

    /*! \brief Calculates the azimuthal $\Delta \phi$ angle between the supplied vector
     * and the Common Object Recoil MET.
     *
     * \author Markus Stoye
     * \date February 2009
     * \version 1.0
     * @param [in] vec1
     * @return The azimuthal $\Delta \phi$ angle between vec1 and the event's common object Recoil MET
     */
    float comRecoilMetdPhi(LorentzV const * vec1) const;

    /*! \brief Returns the %\Delta \phi$ angle between the supplied vector and the event's common
     * object recoil MET \emph{with the supplied vector's contribution removed}.
     * \author Markus Stoye
     * \date February 2009
     * \version 1.0
     * @param [in] vec1 Pointer to vector under consideration.
     * @return The biased $\Delta \phi$.
     */
  float biasedComRecoilMetdPhi(LorentzV const* vec1) const;

  float lowPtbiasedComRecoilMetdPhi(LorentzV const* vec1) const;

    // cos theta star alike varible
    float MScosThetaStar2Part(LorentzV const * vec1,LorentzV const * vec2) const; // leading jet cos theta star (hot in pt balanced)
    float cosThetaStar2Part(LorentzV const * vec1, LorentzV const * vec2) const; // textbook cos theta star

    // check if there is a leptonic W OR Z decay
    int  GenWtoTau();
    int  GenWtoMuon();
    int  GenWtoElectron();
    //    TLorenzVector SumOfVector()

    // checks if there is a overlap to a jet within dr and dEt
    bool  OverlapsJet(LorentzV * vec1, float dR, float dEt);
  float ComJetOverlap(LorentzV * vec1);

    // Lepton MC matching
    int leptonMatch(const LorentzV *vec, int type);
    //, float mo_DRmax, float mo_dPtbyPtmax);
    int leptonType(int imatch);
    //TLorentzVector *theLepton, int ltype);

    // prints out the object collections
    void PrintStableVisRec();
    void PrintStableVisAllRec();

    int GetCategory() { return mCategory; }
    void SetCategory(int cat) { mCategory = cat; }
    
  }; // end of class Data

} // end of namespace Event

#endif //~EventData_hh
