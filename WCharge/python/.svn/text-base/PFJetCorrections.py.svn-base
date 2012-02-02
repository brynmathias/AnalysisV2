#!/usr/bin/env python

import commands

from icf.core import PSet
YourSusyDir = commands.getoutput('echo $SUSY_WORKING_SW_DIR')
def CorrectionPset():
  CorFile=open(YourSusyDir+"/WCharge/python/Spring10DataV2_L2L3Residual_AK5PF.txt","r")
  Eta1 = []
  Eta2 = []
  Corr = []
  for aRow in CorFile :
    rows = aRow.split()
    for coloum in rows :
      Eta1.append(float(rows[0]))
      Eta2.append(float(rows[1]))
      Corr.append(float(rows[5]))
  ps = PSet(
  EtaLow = Eta1,
  EtaHi = Eta2,
  Correction = Corr
  )
  return ps
