#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet
from copy import deepcopy
from hadronic.commonIncludes import *

def isCmssm(model) : return ("tanB" in model)
def isSms(model) :   return (model in ["T1", "T2"])



mu_id = PSet(
   MuID = "Tight",
   MinPt = 20.,
   MaxEta = 2.1,
   MaxIsolation = 0.1,
   DRMuJet = 0.3,
   MaxGlbTrkDxy = 0.02,
   MinGlbTrkNumOfValidHits = 11,
   SegMatch2GlbMu = 1,
   PixelHitsOnInrTrk = 1,
   MaxInrTrkDz = 1..
   doJetLoop = False
   )



isr_pset = PSet(
    DirectoryName = "isr_unc",
    ISRFile = "T1_weights.root",
    ISRDir = "T1_weight",
    xBins = 12,
    xLow =400.,
    xHigh =1000.,
    yBins =34,
    yLow =100.,
    yHigh =950.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    verbose = False,
    )

msugra_pset = PSet(
    DirectoryName = "mSuGraScan",
    xBins = 100,
    xLow = 0.,
    xHigh = 1000.,
    yBins =50,
    yLow =0.,
    yHigh =500.,
    zBins =40,
    zLow =0.,
    zHigh =1000.,
    mSUGRAFile = "",#"msugraTanbeta3_05down.txt",
    verbose = False,
    )

def tripleScale(model = "", cutTree = None, cut = None, label = "") :
  out = []
  for scale in ["2.0","0.5","1.0"] :
    scale2 = scale.replace(".","")
    if scale2[-1]=="0" : scale2 = scale2[:-1]

    pset = deepcopy(msugra_pset)
    pset.mSUGRAFile = "hadronic/scale_xsection_nlo%s_%s.txt"%(scale, model.replace("B","dat"))
    pset.DirectoryName = "mSuGraScan_%s_scale%s"%(label, scale2)
    op = OP_mSuGraPlottingOps(pset.ps())
    out.append(op)
    cutTree.TAttach(cut, op)
  return out

def smsOps(model = "", cutTree = None, cut = None, label = "") :
  out = []

  pset = deepcopy(isr_pset)
  pset.ISRFile = "hadronic/%s_weights.root"%model
  pset.ISRDir = "%s_weight"%model
  pset.DirectoryName += "_%s"%label

  op = OP_ISRPlottingOps(pset.ps())
  out.append(op)
  cutTree.TAttach(cut, op)

  pset2 = deepcopy(msugra_pset)
  pset2.DirectoryName = "smsScan_%s"%label
  pset2.xBins = 12
  pset2.xLow = 400.
  pset2.xHigh = 1000.
  pset2.yBins = 34
  pset2.yLow = 100.
  pset2.yHigh = 950.

  op2 = OP_mSuGraPlottingOps(pset2.ps())
  out.append(op2)
  cutTree.TAttach(cut, op2)

  return out

def addBinnedStuff(model = "", cutTree = None, cut = None, htBins = []) :
  out = []
  for lower,upper in zip(htBins, htBins[1:]+[None]) :

    lowerCut = eval("ht%d"%lower)
    cutTree.TAttach(cut, lowerCut)
    if upper :
      upperCut = eval("htLess%d"%upper)
      cutTree.TAttach(lowerCut, upperCut)

    if isCmssm(model) :
      someOps = tripleScale(model = model, cutTree = cutTree,
                            cut = upperCut if upper else lowerCut,
                            label = "%d%s"%(lower, "_%d"%upper if upper else ""))
    elif isSms(model) :
      someOps = smsOps(model = model, cutTree = cutTree,
                       cut = upperCut if upper else lowerCut,
                       label = "%d%s"%(lower, "_%d"%upper if upper else ""))
    else :
      someOps = None

    out.append(someOps)
  return out
