#!/usr/bin/env python
import setupSUSY
import unittest
from xcleanlib import *
from config import xclean
from libxcleantest import *
import random

class TestCloneVector(unittest.TestCase):
    def testcloneAll(self):
        """ Clone 100 jets, alter their Px and check"""
        jets=[]
        for i in range(100):
            jets.append(Jet(50,2,1,60,0.9,i))
        clone_jets=JetVector()
        for j in jets:
            clone_jets.append(j)
        for i in range(len(clone_jets)):
            self.assertEqual(clone_jets[i].Pt(),jets[i].Pt())
            self.assertEqual(clone_jets[i].Eta(),jets[i].Eta())
            self.assertEqual(clone_jets[i].Phi(),jets[i].Phi())
            self.assertEqual(clone_jets[i].E(),jets[i].E())
        for i in range(len(clone_jets)):
            j=clone_jets.Clone(i)
            j.SetPx(100)
            self.assertNotEqual(j.Px(),jets[i].Px())
            self.assertEqual(j.Px(),100)
        for i in range(len(clone_jets)):
            j=clone_jets[i]
            self.assertEqual(j.Px(),100)

    def testCloneSome(self):
        """ Clone 100 jets, alter the Pz of 30 at random and check"""
        jets=[]
        for i in range(100):
            jets.append(Jet(50,2,1,60,0.9,i))
        clone_jets=JetVector()
        for i in range(len(jets)):
            clone_jets.append(jets[i])
        rand_ints=[random.randint(0,len(jets)-1) for i in range(30)]
        for r in rand_ints:
            j=clone_jets.Clone(r)
            j.SetPz(35)
        for i in range(len(jets)):
            if i in rand_ints:
                self.assertEqual(clone_jets[i].Pz(),35)
                self.assertNotEqual(jets[i].Pz(),35)
            else:
                self.assertEqual(clone_jets[i].Pz(),jets[i].Pz())
                self.assertNotEqual(clone_jets[i].Pz(),35)

    def testRandomJetsCloneSome(self):
        """ Clone 1000 random jets, clone, change E of random 300."""
        jets=[]
        for i in range(1000):
            jets.append(Jet(random.uniform(0,100),
                        random.uniform(-5,5),
                        random.uniform(0,8),
                        random.uniform(0,100),
                        random.uniform(0,1),
                        i))
        cjets=JetVector()
        for i in range(len(jets)):
            cjets.append(jets[i])
        # Test that changing original jet after the clone will
        # update the uncloned jet
        i=0
        for j in jets:
            j.SetE(random.uniform(0,200))
            self.assertEqual(cjets[i].E(),j.E())
            i+=1
        # Now pick 300 jets at random, clone them and alter the E
        # Check that original jet E is unchanged and that cloned
        # jet E is properly updated
        rand_ints=[random.randint(0,len(jets)-1) for i in range(300)]
        for r in rand_ints:
            e=jets[r].E()
            j=cjets.Clone(r)
            rand_e=random.uniform(0,300)
            j.SetE(rand_e)
            self.assertEqual(j.E(),rand_e)
            self.assertEqual(cjets[r].E(),rand_e)
            self.assertEqual(jets[r].E(),e)

if __name__ == '__main__':
    suite = unittest.TestLoader().loadTestsFromTestCase(TestCloneVector)
    unittest.TextTestRunner(verbosity=2).run(suite)
