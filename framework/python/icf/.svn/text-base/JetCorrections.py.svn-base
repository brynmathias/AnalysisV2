#!/usr/bin/env python

import commands

from core import PSet
YourSusyDir = commands.getoutput('echo $SUSY_WORKING_SW_DIR')
def CorrectionPset(CorrectionFile):
  if CorrectionFile == None : CorrectionFile = "ResidualJetEnergyCorrections.txt"
  CorFile=open(YourSusyDir+"/framework/python/icf/"+CorrectionFile,"r")
  Eta1 = []
  Eta2 = []
  Corr0 = []
  Corr1 = []
  Corr2 = []
  for aRow in CorFile :
    fields = aRow.split()
    Eta1.append(float(fields[0]))
    Eta2.append(float(fields[1]))
    Corr0.append(float(fields[5]))
    Corr1.append(float(fields[6]))
    Corr2.append(float(fields[7]))
  ps = PSet(
  EtaLow = Eta1,
  EtaHi = Eta2,
  Correction0 = Corr0,
  Correction1 = Corr1,
  Correction2 = Corr2
  )
  return ps
