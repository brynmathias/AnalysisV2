/*! \file KinSuite.cc
 * \brief Source code for the Kinematic Suite of helper functions.
 */

#include "KinSuite.hh"
#include "AlphaT.hh"
#include "Combinations.hh"
#include "Jet.hh"
#include "Photon.hh"
#include "GenObject.hh"
#include <Math/VectorUtil.h>
#include "mt2_bisect.hh"

using namespace Combinations;

namespace KinSuite {

  bool Compare(const LorentzV & o1, const LorentzV & o2)  {
    return o1.Pt() > o2.Pt();
  }

  bool PCompare(const LorentzV * o1, const LorentzV * o2)  {
    return o1->Pt() > o2->Pt();
  }

}

namespace Event {
  LorentzV KS_4VecSum(const std::vector<LorentzV> & objects) {
    LorentzV sum = LorentzV(0.,0.,0.,0.);
    for (std::vector<LorentzV>::const_iterator o=objects.begin();o!=objects.end();++o) { sum+=(*o); }
    return sum;
  }

  LorentzV KS_Recoil(const std::vector<LorentzV> & objects) {
    LorentzV s = KS_4VecSum(objects);
    s.SetPxPyPzE(-s.Px(), -s.Py(), -s.Pz(), s.E());
    return s;
  }

  Double_t KS_RecoilPt(const std::vector<LorentzV> & objects) {
    return KS_Recoil(objects).Pt();
  }

  Double_t KS_SumET(const std::vector<LorentzV> & objects) {
    Double_t sEt = 0;
    for (std::vector<LorentzV>::const_iterator o=objects.begin();o!=objects.end();++o) { sEt+=o->Et(); }
    return sEt;
  }

  Double_t KS_M(const std::vector<LorentzV> & objects) { return KS_4VecSum( objects ).M(); }

  Double_t KS_MT(const std::vector<LorentzV> & objects) {
    Double_t sEt = 0, sPx = 0, sPy = 0;
    for (std::vector<LorentzV>::const_iterator o=objects.begin();o!=objects.end();++o) { sEt+=o->Et();sPx+=o->Px();sPy+=o->Py(); }
    Double_t MTsq = sEt*sEt - sPx*sPx - sPy*sPy;
    return MTsq >= 0. ? sqrt(MTsq) : -sqrt(-MTsq);
  }

  Double_t KS_MT(const std::vector<Event::Jet const *> & objects) {
    Double_t sEt = 0, sPx = 0, sPy = 0;
    for (std::vector<Event::Jet const *>::const_iterator o = objects.begin();
     o != objects.end();
     ++o) {
      sEt += (*o)->Et();
      sPx += (*o)->Px();
      sPy += (*o)->Py();
    }
    Double_t MTsq = sEt*sEt - sPx*sPx - sPy*sPy;
    return MTsq >= 0. ? sqrt(MTsq) : -sqrt(-MTsq);
  }

  Double_t KS_MinDPhi(const std::vector<LorentzV> & objects) {
    // Find the recoil vector to test against
    LorentzV recoil = KS_Recoil(objects);
    return KS_MinDPhi( const_cast<LorentzV &> (recoil), objects );
  }

  Double_t KS_MinDPhi(const LorentzV & recoil, const std::vector<LorentzV> & objects) {
    Double_t min = 10.;
    for (std::vector<LorentzV>::const_iterator o=objects.begin();o!=objects.end();++o) {
      Double_t testmin = fabs(ROOT::Math::VectorUtil::DeltaPhi(*o,recoil));
      if (testmin < min) min = testmin;
    }
    return min;
  }

    Double_t KS_MinBiasDPhi(const std::vector<LorentzV> & objects) {
        // Find the recoil vector to test against
        LorentzV recoil = KS_Recoil(objects);
        return KS_MinBiasDPhi( const_cast<LorentzV &> (recoil), objects );
    }

    Double_t KS_MinBiasDPhi(const LorentzV & recoil, const std::vector<LorentzV> & objects) {
        LorentzV biRec = recoil;
        Double_t min = 10.;
        for (std::vector<LorentzV>::const_iterator o=objects.begin();o!=objects.end();++o) {
            biRec+=(*o); // Add the test object from the recoil (which is effectively subtracting it)
            Double_t testmin = fabs(ROOT::Math::VectorUtil::DeltaPhi(*o,biRec));
            if (testmin < min) min = testmin;
            biRec-=(*o); // Reset the recoil.
        }
        return min;
    }

  UInt_t KS_MinDEt_MaxN() { return nmax; }

  Double_t KS_MinDEt(const std::vector<LorentzV> & objects, std::vector<UInt_t> * lista, std::vector<UInt_t> * listb) {
    // Find the combination with the lowest DEt
    UInt_t n = objects.size();
    if (n==0) return 0;
    if (n==1) return objects[0].Et();
    //if (n>nmax) { //cout << "KS_MinDEt: n too big!" << endl; return -987654321.0; }
    //}
    if (lista!=0 && listb!=0) { lista->clear(); listb->clear(); }

    double mindiff = 1000000000., diff = 0.;

    // Strip indices from the relevant combination set
    std::vector<UInt_t> la; //!< Temporary list a for calculating best combo
    std::vector<UInt_t> lb; //!< Temporary list b for calculating best combo

    for (UInt_t r=0; r<rmax[n]; r++) {
      for (UInt_t j=0; j<jmax[n]; j++) {

    // populate list a
    for (UInt_t ia=0; ia<(n-1); ia++) {
      if ((n==2) && (la2[r][j][ia]!=-1) ) la.push_back( la2[r][j][ia] );
      if ((n==3) && (la3[r][j][ia]!=-1) ) la.push_back( la3[r][j][ia] );
      if ((n==4) && (la4[r][j][ia]!=-1) ) la.push_back( la4[r][j][ia] );
      if ((n==5) && (la5[r][j][ia]!=-1) ) la.push_back( la5[r][j][ia] );
      if ((n==6) && (la6[r][j][ia]!=-1) ) la.push_back( la6[r][j][ia] );
      //if (lista[ia] < 0) { lista.pop_back(); break; }
    }

    // populate list b
    for (UInt_t ib=0; ib<(n-1); ib++) {
      if ((n==2) && (lb2[r][j][ib]!=-1) ) lb.push_back( lb2[r][j][ib] );
      if ((n==3) && (lb3[r][j][ib]!=-1) ) lb.push_back( lb3[r][j][ib] );
      if ((n==4) && (lb4[r][j][ib]!=-1) ) lb.push_back( lb4[r][j][ib] );
      if ((n==5) && (lb5[r][j][ib]!=-1) ) lb.push_back( lb5[r][j][ib] );
      if ((n==6) && (lb6[r][j][ib]!=-1) ) lb.push_back( lb6[r][j][ib] );
      //if (listb[ib] < 0) { listb.pop_back(); break; }
    }

    if ( la.size()==0 || lb.size()==0 ) break;

    Double_t aEt = 0., bEt = 0.;
    for (std::vector<UInt_t>::iterator ia=la.begin();ia!=la.end();++ia) {
      //cout << (*ia) << " ";
      aEt += objects[ (*ia) ].Et();
    }
    //cout << ", ";
    for (std::vector<UInt_t>::iterator ib=lb.begin();ib!=lb.end();++ib) {
      bEt += objects[ (*ib) ].Et();
      //cout << (*ib) << " ";
    }
    //cout << endl;
    diff = fabs(aEt - bEt);
    //cout << "Difference in Et is " << diff << endl;
    if (diff < mindiff) {
      mindiff = diff;
      if (lista!=0 && listb!=0) { *lista = la; *listb = lb; }
    }
    la.clear(); lb.clear();
      } // end of permutation list loop
    } // end of combination list loop

    return mindiff;
  }

  Double_t KS_MinDEt(const std::vector<Event::Photon const *> & objects,
             std::vector<UInt_t> * lista,
             std::vector<UInt_t> * listb) {
    // Find the combination with the lowest DEt
    UInt_t n = objects.size();
    if (n==0) return 0;
    if (n==1) return objects[0]->Et();
    //if (n>nmax) { //cout << "KS_MinDEt: n too big!" << endl; return -987654321.0; }
    //}
    if (lista!=0 && listb!=0) { lista->clear(); listb->clear(); }

    double mindiff = 1000000000., diff = 0.;

    // Strip indices from the relevant combination set
    std::vector<UInt_t> la; //!< Temporary list a for calculating best combo
    std::vector<UInt_t> lb; //!< Temporary list b for calculating best combo

    for (UInt_t r=0; r<rmax[n]; r++) {
      for (UInt_t j=0; j<jmax[n]; j++) {

    // populate list a
    for (UInt_t ia=0; ia<(n-1); ia++) {
      if ((n==2) && (la2[r][j][ia]!=-1) ) la.push_back( la2[r][j][ia] );
      if ((n==3) && (la3[r][j][ia]!=-1) ) la.push_back( la3[r][j][ia] );
      if ((n==4) && (la4[r][j][ia]!=-1) ) la.push_back( la4[r][j][ia] );
      if ((n==5) && (la5[r][j][ia]!=-1) ) la.push_back( la5[r][j][ia] );
      if ((n==6) && (la6[r][j][ia]!=-1) ) la.push_back( la6[r][j][ia] );
      //if (lista[ia] < 0) { lista.pop_back(); break; }
    }

    // populate list b
    for (UInt_t ib=0; ib<(n-1); ib++) {
      if ((n==2) && (lb2[r][j][ib]!=-1) ) lb.push_back( lb2[r][j][ib] );
      if ((n==3) && (lb3[r][j][ib]!=-1) ) lb.push_back( lb3[r][j][ib] );
      if ((n==4) && (lb4[r][j][ib]!=-1) ) lb.push_back( lb4[r][j][ib] );
      if ((n==5) && (lb5[r][j][ib]!=-1) ) lb.push_back( lb5[r][j][ib] );
      if ((n==6) && (lb6[r][j][ib]!=-1) ) lb.push_back( lb6[r][j][ib] );
      //if (listb[ib] < 0) { listb.pop_back(); break; }
    }

    if ( la.size()==0 || lb.size()==0 ) break;

    Double_t aEt = 0., bEt = 0.;
    for (std::vector<UInt_t>::iterator ia=la.begin();ia!=la.end();++ia) {
      //cout << (*ia) << " ";
      aEt += objects[ (*ia) ]->Et();
    }
    //cout << ", ";
    for (std::vector<UInt_t>::iterator ib=lb.begin();ib!=lb.end();++ib) {
      bEt += objects[ (*ib) ]->Et();
      //cout << (*ib) << " ";
    }
    //cout << endl;
    diff = fabs(aEt - bEt);
    //cout << "Difference in Et is " << diff << endl;
    if (diff < mindiff) {
      mindiff = diff;
      if (lista!=0 && listb!=0) { *lista = la; *listb = lb; }
    }
    la.clear(); lb.clear();
      } // end of permutation list loop
    } // end of combination list loop

    return mindiff;
  }

  Double_t KS_MinDEt(const std::vector<Event::Jet const *> & objects,
             std::vector<UInt_t> * lista,
             std::vector<UInt_t> * listb) {
    // Find the combination with the lowest DEt
    UInt_t n = objects.size();
    if (n==0) return 0;
    if (n==1) return objects[0]->Et();
    //if (n>nmax) { //cout << "KS_MinDEt: n too big!" << endl; return -987654321.0; }
    //}
    if (lista!=0 && listb!=0) { lista->clear(); listb->clear(); }

    double mindiff = 1000000000., diff = 0.;

    // Strip indices from the relevant combination set
    std::vector<UInt_t> la; //!< Temporary list a for calculating best combo
    std::vector<UInt_t> lb; //!< Temporary list b for calculating best combo

    for (UInt_t r=0; r<rmax[n]; r++) {
      for (UInt_t j=0; j<jmax[n]; j++) {

    // populate list a
    for (UInt_t ia=0; ia<(n-1); ia++) {
      if ((n==2) && (la2[r][j][ia]!=-1) ) la.push_back( la2[r][j][ia] );
      if ((n==3) && (la3[r][j][ia]!=-1) ) la.push_back( la3[r][j][ia] );
      if ((n==4) && (la4[r][j][ia]!=-1) ) la.push_back( la4[r][j][ia] );
      if ((n==5) && (la5[r][j][ia]!=-1) ) la.push_back( la5[r][j][ia] );
      if ((n==6) && (la6[r][j][ia]!=-1) ) la.push_back( la6[r][j][ia] );
      //if (lista[ia] < 0) { lista.pop_back(); break; }
    }

    // populate list b
    for (UInt_t ib=0; ib<(n-1); ib++) {
      if ((n==2) && (lb2[r][j][ib]!=-1) ) lb.push_back( lb2[r][j][ib] );
      if ((n==3) && (lb3[r][j][ib]!=-1) ) lb.push_back( lb3[r][j][ib] );
      if ((n==4) && (lb4[r][j][ib]!=-1) ) lb.push_back( lb4[r][j][ib] );
      if ((n==5) && (lb5[r][j][ib]!=-1) ) lb.push_back( lb5[r][j][ib] );
      if ((n==6) && (lb6[r][j][ib]!=-1) ) lb.push_back( lb6[r][j][ib] );
      //if (listb[ib] < 0) { listb.pop_back(); break; }
    }

    if ( la.size()==0 || lb.size()==0 ) break;

    Double_t aEt = 0., bEt = 0.;
    for (std::vector<UInt_t>::iterator ia=la.begin();ia!=la.end();++ia) {
      //cout << (*ia) << " ";
      aEt += objects[ (*ia) ]->Et();
    }
    //cout << ", ";
    for (std::vector<UInt_t>::iterator ib=lb.begin();ib!=lb.end();++ib) {
      bEt += objects[ (*ib) ]->Et();
      //cout << (*ib) << " ";
    }
    //cout << endl;
    diff = fabs(aEt - bEt);
    //cout << "Difference in Et is " << diff << endl;
    if (diff < mindiff) {
      mindiff = diff;
      if (lista!=0 && listb!=0) { *lista = la; *listb = lb; }
    }
    la.clear(); lb.clear();
      } // end of permutation list loop
    } // end of combination list loop

    return mindiff;
  }

  Double_t KS_AlphaT(const std::vector<LorentzV> & objects) {
    std::vector<bool> pseudo;
    double alpha_t = AlphaT()( objects, pseudo, false );
    if ( pseudo.size() != objects.size() ) { abort(); }
    return alpha_t;
  }

  void KS_PrintLV(const LorentzV & lv, UInt_t option = 0) {
    if (option==0) { cout << "E,Et,Pt,eta,phi,m: "  <<lv.E()<<", "<< lv.Et()<<", "<< lv.Pt()<<", "<<lv.Eta()<<", "<<lv.Phi()<<", "<< lv.M() <<endl; }
    if (option==1) { cout << "E,Et,Pt,px,py,pz,m: " <<lv.E()<<", "<< lv.Et()<<", "<< lv.Pt()<<", "<<lv.Px() <<", "<<lv.Py() <<", "<< lv.Pz()<<","<<lv.M()<<endl; }
  }

  void KS_PrintLV(const std::vector<LorentzV> & objects, UInt_t option) {
    // Loop over the objects and print them out to the standard output.
    for (std::vector<LorentzV>::const_iterator ilv = objects.begin(); ilv!=objects.end(); ++ilv) KS_PrintLV(*ilv, option);
  }

  Double_t KS_DeltaR(const LorentzV & lv1, const LorentzV & lv2) {
    Double_t Deta = lv1.Eta() - lv2.Eta();
    Double_t Dphi = ROOT::Math::VectorUtil::DeltaPhi(lv1,lv2);
    //std::cout << "Deta, Dphi: " << Deta << ", " << Dphi << std::endl;
    return sqrt(Deta*Deta + Dphi*Dphi);
  }

  Double_t KS_DeltaR(const LorentzV * lv1, const LorentzV * lv2) {
    Double_t Deta = lv1->Eta() - lv2->Eta();
    Double_t Dphi = ROOT::Math::VectorUtil::DeltaPhi(*lv1,*lv2);
    //std::cout << "Deta, Dphi: " << Deta << ", " << Dphi << std::endl;
    return sqrt(Deta*Deta + Dphi*Dphi);
  }

  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv, const std::vector<LorentzV> & vlv) {
    Double_t mindr = 1000.;
    UInt_t index = 0, count = 0;
    // Loop over input vector of Lorentz Vectors
    for (std::vector<LorentzV>::const_iterator lv = vlv.begin(); lv!=vlv.end(); ++lv) {
      Double_t curdr = KS_DeltaR(tlv, *lv);
      if (curdr <= mindr) { mindr = curdr; index = count; }
      count++;
    } // end of loop over vlv
    return index;
  } // end of KS_FindDeltaRMinIndex

  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv,
                   const std::vector<Event::Photon> & vlv) {
    Double_t mindr = 1000.;
    UInt_t index = 0, count = 0;
    // Loop over input vector of Lorentz Vectors
    for (std::vector<Event::Photon>::const_iterator lv = vlv.begin(); lv!=vlv.end(); ++lv) {
      Double_t curdr = KS_DeltaR(tlv, *lv);
      if (curdr <= mindr) { mindr = curdr; index = count; }
      count++;
    } // end of loop over vlv
    return index;
  } // end of KS_FindDeltaRMinIndex

  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv,
                   const std::vector<Event::GenObject const *> & vlv) {
    Double_t mindr = 1000.;
    UInt_t index = 0, count = 0;
    // Loop over input vector of Lorentz Vectors
    for (std::vector<Event::GenObject const *>::const_iterator lv = vlv.begin(); lv!=vlv.end(); ++lv) {
      Double_t curdr = KS_DeltaR(tlv, **lv);
      if (curdr <= mindr) { mindr = curdr; index = count; }
      count++;
    } // end of loop over vlv
    return index;
  } // end of KS_FindDeltaRMinIndex

  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv,
                   const std::vector<Event::Photon const *> & vlv) {
    Double_t mindr = 1000.;
    UInt_t index = 0, count = 0;
    // Loop over input vector of Lorentz Vectors
    for (std::vector<Event::Photon const *>::const_iterator lv = vlv.begin(); lv!=vlv.end(); ++lv) {
      Double_t curdr = KS_DeltaR(tlv, **lv);
      if (curdr <= mindr) { mindr = curdr; index = count; }
      count++;
    } // end of loop over vlv
    return index;
  } // end of KS_FindDeltaRMinIndex

  UInt_t KS_FindDeltaRMinIndex(const LorentzV & tlv,
                   const std::vector<Event::Jet const *> & vlv) {
    Double_t mindr = 1000.;
    UInt_t index = 0, count = 0;
    // Loop over input vector of Lorentz Vectors
    for (std::vector<Event::Jet const *>::const_iterator lv = vlv.begin(); lv!=vlv.end(); ++lv) {
      Double_t curdr = KS_DeltaR(tlv, **lv);
      if (curdr <= mindr) { mindr = curdr; index = count; }
      count++;
    } // end of loop over vlv
    return index;
  } // end of KS_FindDeltaRMinIndex

  UInt_t KS_FindDeltaRMinIndex(const LorentzV * tlv,
                   const std::vector<LorentzV const *> & vlv) {
    Double_t mindr = 1000.;
    UInt_t index = 0, count = 0;
    // Loop over input vector of Lorentz Vectors
    for (std::vector<LorentzV const *>::const_iterator lv = vlv.begin(); lv!=vlv.end(); ++lv) {
      //LorentzV mylv = **lv;
      Double_t curdr = KS_DeltaR(*tlv, **lv);
      if (curdr <= mindr) { mindr = curdr; index = count; }
      count++;
    } // end of loop over vlv
    return index;
  } // end of KS_FindDeltaRMinIndex


  Double_t MT2(const std::vector<LorentzV> & objects)
    {
        mt2_bisect::mt2 mt2_event;

        double pa[3]; // px py m of jet 1
        double pb[3]; // px py m of jet 2
        double pm[3];
        double mn = 0.; //set the mass of the neutrilino/neutrino for top events
        //jet1
        pa[0] = objects[0].Px();
        pa[1] = objects[0].Py();
        pa[2] =  0.0;//KS_MT(objects[0]);
        //jet2
        pb[0] = objects[1].Px();
        pb[1] = objects[1].Py();
        pb[2] = 0.0;//KS_MT(objects[1]);
        //Missing Pt
        pm[1]= (KS_Recoil(objects)).Px();
        pm[2]= (KS_Recoil(objects)).Py();
        //Set Values of neutrilino momentum (this doesnt seam right here, !!!Look into this!!!)
        mt2_event.set_momenta(pa,pb,pm);
        mt2_event.set_mn(mn);

        return mt2_event.get_mt2();
    }



} // ~namespace EventStuff
