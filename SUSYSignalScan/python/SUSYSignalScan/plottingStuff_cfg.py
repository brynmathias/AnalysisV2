#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libSUSYSignalScan import *
from icf.core import PSet
from copy import deepcopy
from SUSYSignalScan.utils import *
from hadronic.commonIncludes import *
def isCmssm(model) : return ("tanB" in model)
def isSms(model) :   return (model in ["T1", "T2","T2bb","T2tt"])

import os
susydir = os.environ['SUSY_WORKING_SW_DIR'] + '/'
# processes, kfactors = readKFactors("..//textfiles/scale_xsection_nlo2.0_tanssdat10.txt")
# ps = kfactorsToPSet(processes, kfactors)

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
    xBins = 200,
    xLow = 0.,
    xHigh = 2000.,
    yBins =80,
    yLow =0.,
    yHigh =800.,
    zBins =1,
    zLow =0.,
    zHigh =1000.,
    Modulo = 1,
    verbose = False,
    NLO = None
    )

sms_pset = PSet(
    DirectoryName = "mSuGraScan",
    xBins = 150,
    xLow = 0.,
    xHigh = 1500.,
    yBins =150,
    yLow =0.,
    yHigh =1500.,
    zBins =1,
    zLow =0.,
    zHigh =1000.,
    verbose = False,
    MChiCut = -1.
    )


def tripleScale(model = "", cutTree = None, cut = None, label = "") :
  out = []
  for scale in ["1.0",]:#"2.0","0.5","1.0"] :
    scale2 = scale.replace(".","")
    if scale2[-1]=="0" : scale2 = scale2[:-1]
    pset = deepcopy(msugra_pset)
    mSUGRAFile = susydir + "SUSYSignalScan/textfiles/scale_xsection_nlo%s_m0_m12_%s_1v1.txt"%(scale, model.replace("tanB","") )
    processes, kfactors = readKFactors(mSUGRAFile)
    ps = kfactorsToPSet(processes, kfactors)
    pset._quiet_set("NLO", ps)
    pset.DirectoryName = "mSuGraScan_%s_scale%s"%(label, scale2)
    op = OP_mSuGraPlottingOps(pset.ps())
    out.append(op)
    out.append(ps)
    if cut is not None:
      cutTree.TAttach(cut, op)
    else:
      cutTree.Attach(op)
  return out

def smsOps(model = "", cutTree = None, cut = None, label = "",MChiCut = -1) :
  out = []
  pset2 = deepcopy(sms_pset)
  pset2.DirectoryName = "smsScan_%s"%label
  pset2.xBins = 44
  pset2.xLow = 100.
  pset2.xHigh = 1200.
  pset2.yBins = 44
  pset2.yLow = 50.
  pset2.yHigh = 1150.
  if MChiCut != -1:
    print MChiCut
    pset2.MChiCut = MChiCut
  op2 = OP_smsPlottingOps(pset2.ps())
  out.append(op2)
  cutTree.TAttach(cut, op2)

  return out

def addBinnedStuff(model = "", cutTree = None, cut = None, htBins = [],label2 = None,extra = None) :
  out = []
  for lower,upper in zip(htBins, htBins[1:]+[None]) :
    lowerCut = eval("RECO_CommonHTCut(%d)"%lower)
    out.append(lowerCut)
    cutTree.TAttach(cut, lowerCut)
    if upper :
      upperCut = eval("RECO_CommonHTLessThanCut(%d)"%upper)
      out.append(upperCut)
      cutTree.TAttach(lowerCut, upperCut)

    if isCmssm(model) :
      someOps = tripleScale(model = model, cutTree = cutTree,
                            cut = upperCut if upper else lowerCut,
                            label = label2+"%d%s"%(lower, "_%d"%upper if upper else ""))
    elif isSms(model) :
      someOps = smsOps(model = model, cutTree = cutTree,
                       cut = upperCut if upper else lowerCut,
                       label = label2+"%d%s"%(lower, "_%d"%upper if upper else ""),MChiCut = extra)
    else :
      someOps = None

    out.append(someOps)
  return out
