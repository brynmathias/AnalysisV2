import ROOT as r
import os.path
import sys
import random

def setup_root():
    """Setup ROOT ready to do the fitting"""
    r.gSystem.Load('libRooFit')
    r.gROOT.ProcessLine(".L RooW.cxx+")
    r.gSystem.Load("RooW_cxx.so")
    r.gROOT.ProcessLine(".L tdrstyle.C")
    r.gROOT.SetBatch(r.kTRUE)
    r.setTDRStyle()
    r.tdrStyle.SetPadRightMargin(0.06)#tweak
    # r.RooRandom.randomGenerator().SetSeed(random.randint(0, 10000))
    r.RooRandom.randomGenerator().SetSeed(4192)
    # r.RooRandom.randomGenerator().SetSeed(1599)

def rebin(n, *items):
    """Rebin either a dict or a list of histograms"""
    for d in items:
        if getattr(d, "iteritems", None):
            for k, v in d.iteritems():
                v.Rebin(n)
        elif getattr(d, "__iter__", None):
            for i in d:
                i.Rebin(n)
        else:
            raise ValueError("Can't Rebin type")

def scale(s, *items):
    """Scale either a dict or a list of histograms"""
    for d in items:
        if getattr(d, "iteritems", None):
            for k, v in d.iteritems():
                v.Scale(s)
        elif getattr(d, "__iter__", None):
            for i in d:
                i.Scale(s)
        else:
            raise ValueError("Can't scale type")

def ensure_dir(path):
    """Ensure a given directory exists"""
    if not os.path.exists(os.path.dirname(path)):
            os.makedirs(os.path.dirname(path))

def intr(hist, x1, x2, quanta=0.001):
    """Return integral of hist in range x1->x2"""
 #   print "==="
    low = hist.GetXaxis().GetBinLowEdge(hist.GetXaxis().FindBin(x1+quanta))
    high = (hist.GetXaxis().GetBinLowEdge(hist.GetXaxis().FindBin(x2-quanta))+
            hist.GetXaxis().GetBinWidth(hist.GetXaxis().FindBin(x2-quanta)))
  #  print "%.5f => %.5f" % (low, high)
#    print hist.GetXaxis().FindBin(x2-quanta).GetBinLowEdge()
    return hist.Integral(hist.FindBin(x1+quanta), hist.FindBin(x2-quanta))
