#!/usr/bin/env python
from xcleanlib import *
import random
from config import xclean
import timeit

class XCleanPerfHammer:
    def __init__(self,ps):
        self.xc=XClean(ps)

    def hammer(self):
        for i in range(100):
            self.xc.AddJet(self.random_jet_pt(),
                           self.random_eta(),
                           self.random_phi(),
                           self.random_e(),
                           self.random_emfrac())
        for i in range(100):
            self.xc.AddMuon(self.random_lep_pt(),
                            self.random_eta(),
                            self.random_phi(),
                            self.random_e(),
                            self.random_charge(),
                            self.random_iso(),
                            self.random_iso(),
                            self.random_iso(),
                            self.random_looseid(),
                            self.random_tightid())
            self.xc.AddElectron(self.random_lep_pt(),
                                self.random_eta(),
                                self.random_phi(),
                                self.random_e(),
                                self.random_charge(),
                                self.random_iso(),
                                self.random_iso(),
                                self.random_iso(),
                                self.random_looseid(),
                                self.random_tightid())
        self.xc.Clean()
        self.xc.Clear()

    def random_jet_pt(self):
        return random.uniform(5,200)
    def random_lep_pt(self):
        return random.uniform(5,100)
    def random_eta(self):
        return random.uniform(0,10)
    def random_phi(self):
        return random.uniform(0,8)
    def random_e(self):
        return random.uniform(5,100)
    def random_iso(self):
        return random.uniform(0,10)
    def random_emfrac(self):
        return random.uniform(0.5,1.0)
    def random_looseid(self):
        if random.random()<0.9:
            return True
        return False
    def random_tightid(self):
        if random.random()>0.5:
            return True
        return False
    def random_charge(self):
        return random.choice([-1,+1])
if __name__ == "__main__":
    hammer=XCleanPerfHammer(xclean)
    t=timeit.Timer(hammer.hammer)
    print t.timeit(500)
