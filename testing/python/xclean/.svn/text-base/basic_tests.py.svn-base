#!/usr/bin/env python
import setupSUSY
import unittest
from xcleanlib import *
from config import xclean

mu_pt_lt=xclean.Muons.PtCut-1
mu_eta_lt=xclean.Muons.EtaCut-1
mu_pt_gt=xclean.Muons.PtCut+1
mu_eta_gt=xclean.Muons.EtaCut+1
mu_tiso_any=10
mu_eiso_any=10
mu_hiso_any=10
mu_tiso=xclean.Muons.TrkIsoCut-1
el_tiso=xclean.Electrons.TrkIsoCut-1
dr_cone=0.5
jet_et_lt=xclean.Jets.EtCut-1
jet_et_gt=xclean.Jets.EtCut+1
jet_eta_lt=xclean.Jets.EtaCut-1
jet_eta_gt=xclean.Jets.EtaCut+1

class TestBasic(unittest.TestCase):
    def assertVecEqual(self,v1,v2):
        self.assertEqual(v1.Px(),v2.Px())
        self.assertEqual(v1.Py(),v2.Py())
        self.assertEqual(v1.Pz(),v2.Pz())
        self.assertEqual(v1.E(),v2.E())

    def testOneJetOneMuon(self):
        """ One Muon, one jet."""
        cc=XClean(xclean)
        cc.AddJet(50,2,1,60,0.9)
        cc.AddMuon(10,2.1,1.1,20,1,10,10,10,True,False)
        jet_plus_muon=lorentz_add(cc.jets[0][1],cc.muons[0][1])
        cc.Clean()
        self.assertEqual(cc.muons[0][0],"FAIL")
        self.assertEqual(cc.jets[0][1].Px(),jet_plus_muon.Px())
        self.assertEqual(cc.jets[0][1].Py(),jet_plus_muon.Py())
        self.assertEqual(cc.jets[0][1].Pz(),jet_plus_muon.Pz())
        self.assertEqual(cc.jets[0][1].E(),jet_plus_muon.E())

    def testOneJetOneMuonOutsideDR(self):
        """ One jet and one muon outside deltaR cone """
        cc=XClean(xclean)
        cc.AddJet(50,2,1,60,0.9)
        cc.AddMuon(50,2+dr_cone,1,20,1,10,10,10,True,False)
        cc.Clean()
        self.assertEqual(cc.muons[0][0],"PASS")
        self.assertEqual(cc.jets[0][0],"PASS")

    def testOneJetOneIsoMuon(self):
        """ One jet and one isolated muon within cone """
        cc=XClean(xclean)
        cc.AddJet(50,2,1,60,0.9)
        cc.AddMuon(10,2.1,1.1,20,1,mu_tiso,10,10,True,False)
        cc.Clean()
        self.assertEqual(cc.muons[0][0],"PASS")

    def testOneIsoEleOneNonisoMuonOneJet(self):
        """ One isolated electron, one non-isolated muon and one jet"""
        cc=XClean(xclean)
        cc.AddJet(50,2,1,60,0.9)
        cc.AddMuon(10,2.1,1.1,20,1,10,10,10,True,False)
        cc.AddElectron(10,1.9,1.1,20,1,el_tiso,10,10,True,False)
        cc.Clean()
        self.assertEqual(cc.electrons[0][0],"PASS")
        self.assertEqual(cc.jets[0][0],"FAIL")
        self.assertEqual(cc.muons[0][0],"FAIL")

    def testOneIsoEleOneNonIsoEleOneJet(self):
        """ One isolated and one non-isolated electron within dr cone of jet"""
        cc=XClean(xclean)
        cc.AddJet(50,2,1,60,0.9)
        cc.AddElectron(10,2.1,1.1,20,1,10,10,10,True,False)
        cc.AddElectron(10,1.9,1.1,20,1,el_tiso,10,10,True,False)
        cc.Clean()
        self.assertEqual(cc.jets[0][0],"FAIL")
        self.assertEqual(cc.electrons[0][0],"FAIL")
        self.assertEqual(cc.electrons[1][0],"PASS")

    def testTwoJetsTwoNonIsoMuons(self):
        """ Two jets and two non-iso muons within cones"""
        cc=XClean(xclean)
        cc.AddJet(50,2,1,60,0.9)
        cc.AddMuon(10,2.1,1.1,20,1,10,10,10,True,False)
        jet1_plus_muon=lorentz_add(cc.jets[0][1],cc.muons[0][1])
        e=ptetaphiet_to_e(10,4,2,20)
        cc.AddJet(10,4,2,e,0.9)
        cc.AddMuon(10,4.1,2,e,1,10,10,10,True,False)
        jet2_plus_muon=lorentz_add(cc.jets[1][1],cc.muons[1][1])
        cc.Clean()
        self.assertEqual(cc.jets[0][0],"PASS")
        self.assertEqual(cc.jets[1][0],"PASS")
        self.assertEqual(cc.muons[0][0],"FAIL")
        self.assertEqual(cc.muons[1][0],"FAIL")
        self.assertVecEqual(cc.jets[0][1],jet1_plus_muon)
        self.assertVecEqual(cc.jets[1][1],jet2_plus_muon)

    def testJetAcceptanceEt(self):
        """Jet acceptance cuts - Et """
        cc=XClean(xclean)
        e=ptetaphiet_to_e(10,jet_eta_lt,2,jet_et_gt)
        cc.AddJet(10,
                  jet_eta_lt,
                  2,e,
                  0.9
                  )
        e=ptetaphiet_to_e(10,jet_eta_lt,2,jet_et_lt)
        cc.AddJet(10,jet_eta_lt,2,e,
                  0.9,)
        cc.Clean()
        self.assertEqual(cc.jets[0][0],"PASS")
        self.assertEqual(cc.jets[1][0],"CUT")

    def testMuonAcceptance(self):
        """Muon acceptance cuts"""
        cc=XClean(xclean)
        # Muon in Eta but outside Pt
        cc.AddMuon(mu_pt_lt,
                   mu_eta_lt,
                   2,
                   1,
                   1,
                   mu_tiso_any,mu_eiso_any,mu_hiso_any,
                   True,False)
        # Muon in Pt but outside Eta
        cc.AddMuon(mu_pt_gt,mu_eta_gt,
                   2,1,
                   1,
                   mu_tiso_any,mu_eiso_any,mu_hiso_any,
                   True,False)
        # Muon inside both Pt and Eta
        cc.AddMuon(mu_pt_gt,mu_eta_lt,
                   2,1,
                   1,
                   mu_tiso_any,mu_eiso_any,mu_hiso_any,
                   True,False)
        # Muon outside both Pt and Eta
        cc.AddMuon(mu_pt_lt,mu_eta_gt,
                   2,1,
                   1,
                   mu_tiso_any,mu_eiso_any,mu_hiso_any,
                   True,False)
        # Muon inside both but !loose id
        cc.AddMuon(mu_pt_gt,mu_eta_lt,
                   2,1,
                   1,
                   mu_tiso_any,mu_eiso_any,mu_hiso_any,
                   False,False)
        cc.Clean()
        self.assertEqual(cc.muons[0][0],"CUT")
        self.assertEqual(cc.muons[1][0],"CUT")
        self.assertEqual(cc.muons[2][0],"PASS")
        self.assertEqual(cc.muons[3][0],"CUT")
        self.assertEqual(cc.muons[4][0],"CUT")

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestBasic)
    unittest.TextTestRunner(verbosity=2).run(suite)
