#ifndef GENMATRIXBIN_HH
#define GENMATRIXBIN_HH
#include <vector>
#include "EventData.hh"
#include "GenObject.hh"

class GenMatrixBin{

public:
  GenMatrixBin(); //default constructor
  GenMatrixBin(Event::Data * ev);
  bool hasDaughter(Event::Data * ev,int index);
  bool idSelecHad(Event::GenObject const * gen, float et, float eta);
  bool idSelecPhot(Event::GenObject const * gen, float et, float eta);
  bool idSelecMuon(Event::GenObject const * gen, float et, float eta);
  bool idSelecEli(Event::GenObject const * gen, float et, float eta);
  bool idSelecTau(Event::GenObject const * gen, float et, float eta);
  bool idSelecMuonNu(Event::GenObject const * gen, float et, float eta);
  bool idSelecEliNu(Event::GenObject const * gen, float et, float eta);
  bool idSelecTauNu(Event::GenObject const * gen, float et, float eta);

  vector <Event::GenObject const *> the_GenJets;
  vector <Event::GenObject const *> the_GenEli;
  vector <Event::GenObject const *> the_GenTau;
  vector <Event::GenObject const *> the_GenMuon;
  vector <Event::GenObject const *> the_GenPhot;
  vector <Event::GenObject const *> the_GenTop;
  vector <Event::GenObject const *> the_GenW;
  vector <Event::GenObject const *> the_GenZ;
  vector <Event::GenObject const *> the_GenMuonNu;
  vector <Event::GenObject const *> the_GenTauNu;
  vector <Event::GenObject const *> the_GenEliNu;
  vector <Event::GenObject const *> the_GenMuonExtra;
  vector <Event::GenObject const *> the_GenElectronExtra;

  int nTauMuon;
  int nTauEli;
  int nTauHad;
  //float the_GenNeutral;
  void PrintStableVis();

};
#endif
