#ifndef PHOTONCOMPUTE_HH
#define PHOTONCOMPUTE_HH
#include "Compute_User.hh"
#include "EventData.hh"
#include <vector>

//namespace Photon{

class SelectedPhotons : public Compute::User<std::vector<Event::Photon const *>, SelectedPhotons>
{
 public:
  SelectedPhotons(const Utils::ParameterSet & ps);
  ~SelectedPhotons(){}
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
 private:
  double mEt;
  double mEtaEBMax;
  double mEtaEEMin;
  double mEtaEEMax;
  double mIDReq;
};

class SelectedJets : public Compute::User<std::vector<Event::Jet const *>, SelectedJets>
{
 public:
  SelectedJets(const Utils::ParameterSet & ps);
  ~SelectedJets(){}
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
 private:
  double mEt;
  double mDeltaR;
};

class MHT : public Compute::Variable<LorentzV, MHT>
{
 public:
  MHT(const Event::Data & ev);
  ~MHT(){}
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
};

class HT : public Compute::Variable<double, HT>
{
 public:
  HT(const Event::Data & ev);
  ~HT(){}
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
};

class Status1GenPhotons : public Compute::User<std::vector<Event::GenObject>, Status1GenPhotons>
{
 public:
  Status1GenPhotons();
  ~Status1GenPhotons(){
  }
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
};

class Status3GenPhotons : public Compute::User<std::vector<Event::GenObject>, Status3GenPhotons>
{
 public:
  Status3GenPhotons();
  ~Status3GenPhotons(){
  }
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
};

class MatchedStatus1Photons : public Compute::User<std::vector<Event::Photon const *>, MatchedStatus1Photons>
{
 public:
  MatchedStatus1Photons(double, double);
  ~MatchedStatus1Photons(){
  }
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
 private:
  const double mEtCut;
  const double mEtaCut;
};

class MatchedStatus3Photons : public Compute::User<std::vector<Event::Photon const *>, MatchedStatus3Photons>
{
 public:
  MatchedStatus3Photons(double, double);
  ~MatchedStatus3Photons(){
  }
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
 private:
  const double mEtCut;
  const double mEtaCut;
};

class UnmatchedPhotons : public Compute::User<std::vector<Event::Photon const *>, UnmatchedPhotons>
{
 public:
  UnmatchedPhotons(double, double);
  ~UnmatchedPhotons(){
  }
  void _Update() const;
  std::ostream & Description(std::ostream & ostrm);
 private:
  const double mEtCut;
  const double mEtaCut;
};

//}

#endif
