#ifndef ThrustStuff_hh
#define ThrustStuff_hh

#include <vector>
#include <iostream>
#include <TROOT.h>
#include <TLorentzVector.h>
#include <Math/LorentzVector.h>
#include "Jet.hh"

#include "Compute_Variable.hh"
#include <cstdlib>
// Forward declarations
//class TLorentzVector;
#include "Types.hh"

namespace Event{class Data;}
class ThrustStuff
{

public:
  //  ThrustStuff(const std::vector<TLorentzVector> & objects);
  ThrustStuff();
  ThrustStuff(const std::vector<LorentzV> & objects);
  LorentzV ThrustDirection;
  LorentzV Pjet1; // Pseudojet 1
  LorentzV Pjet2; // Pseudojet 2
  float HTjet1;   // HT of Pseudojet 1
  float HTjet2;   // HT of Pseudojet 2
  float MTjet1;   // MT of Pseudojet 1
  float MTjet2;   // MT of Pseudojet 2
  float pjetDphi; // Delta Phi between pseudojets
  float HTFmax;   //HT along thrust axis
  float HTFmin;   //HT orthogonal thrust axis
  float MHTFmax;  //MHT along thrust axis
  float MHTFmin;  //MHT orthogonal thrust axis
};

class ThrustStuffVar : public Compute::Variable<ThrustStuff,ThrustStuffVar>
{
public:
  ThrustStuffVar(const Event::Data & ev);
  void _Update() const;
};

#endif 
