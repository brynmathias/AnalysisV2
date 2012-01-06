#ifndef ONELEPTON_SYSTEMATICS_HH
#define ONELEPTON_SYSTEMATICS_HH

#include "PlottingBase.hh"
#include "TH2D.h"
#include "TH3D.h"
#include "Types.hh"
#include "Utils.hh"

namespace OneLepton{

class SystematicsPlots : public PlottingBase{
 public:
  SystematicsPlots(const std::string & foldername, const Utils::ParameterSet & ps);
  ~SystematicsPlots();
  void Start(Event::Data & ev);
  void BookHistos(){}
  bool Process(Event::Data & ev);
  void Polarisation(Event::Data & ev);
  void METResolution(Event::Data & ev);
  std::ostream & Description(std::ostream & ostrm);
 private:
  TH2D* MC_RECO_pfMETRes_genMHT;
  TH3D* MC_WPt_Y_CosThetaStarPlus;
  TH3D* MC_WPt_Y_CosThetaStarMinus;
  std::string folder_name_;
  bool polarisation_;
  bool resolution_;
  std::string lepton_;
  enum LeptonType {
    ELECTRON,
    MUON
  } lepton_type_;

};

}
#endif
