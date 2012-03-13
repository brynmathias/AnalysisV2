#!/usr/bin/env python
# -*- coding: utf-8 -*-
from asymConfig import *
from copy import deepcopy


##User defined Variables
bData = True#False? True?
bRecoil = False

DEBUG = False#True

default_Asym.do_Recoil = bRecoil
default_Asym.do_TP = bData

# Create the analysis
a = Analysis("Templates")

# Create a Tree called Main
tree = Tree("Main")

Analysis_List = []
syst_values = ["1.05","1.10","1.15","1.20","1.25"]

# Nominal
Default_Asym=AsymTemplateHistos("nominal",default_Asym.ps())
Analysis_List.append(Default_Asym)


# W systematics
syst_recoil_up = deepcopy(default_Asym)
syst_recoil_down = deepcopy(default_Asym)

syst_recoil_up.rec_fluc = 1
syst_recoil_down.rec_fluc = -1

Syst_Recoil_Up=AsymTemplateHistos("recoil_up",syst_recoil_up.ps())
Syst_Recoil_Down=AsymTemplateHistos("recoil_down",syst_recoil_down.ps())

Analysis_List.append(Syst_Recoil_Up)
Analysis_List.append(Syst_Recoil_Down)

# QCD Systematics
for syst in syst_values :
  syst_dphi = deepcopy(default_Asym)
  syst_deta = deepcopy(default_Asym)
  syst_detaphi = deepcopy(default_Asym)

  syst_dphi.lep_AntiDPhi_eb *= eval(syst)
  syst_dphi.lep_AntiDPhi_ee *= eval(syst)

  syst_deta.lep_AntiDEta_eb *= eval(syst)
  syst_deta.lep_AntiDEta_ee *= eval(syst)
  
  syst_detaphi.lep_AntiDPhi_eb *= eval(syst)
  syst_detaphi.lep_AntiDPhi_ee *= eval(syst)
  syst_detaphi.lep_AntiDEta_eb *= eval(syst)
  syst_detaphi.lep_AntiDEta_ee *= eval(syst)

  Syst_Dphi=AsymTemplateHistos("qcd_dphi_"+str(syst),syst_dphi.ps())
  Syst_Deta=AsymTemplateHistos("qcd_deta_"+str(syst),syst_deta.ps())
  Syst_Detaphi=AsymTemplateHistos("qcd_detaphi_"+str(syst),syst_detaphi.ps())

  Analysis_List.append(Syst_Dphi)
  Analysis_List.append(Syst_Deta)
  Analysis_List.append(Syst_Detaphi)

ZeroMuons = OP_NumComMuons("==", 0)

# Set up CUT flow
a += tree
if bData :
  Trigg_Sel = OP_MultiTrigger(triggers_sel.ps())
  jsonfil=JSONFilter("Cert_160404-167151_7TeV",json_to_pset("/vols/cms03/mjarvis/SUSYv2/WCharge/scripts/json_folder/Cert_160404-166967_7TeV_May10ReRecoPlusPromptReco_840pb.json"))
  json_output=JSONOutput("filtered")
  tree.Attach(jsonfil)
  tree.TAttach(jsonfil,json_output)
  tree.TAttach(json_output,Trigg_Sel)
  tree.TAttach(Trigg_Sel,ZeroMuons)
else :
  tree.Attach(ZeroMuons)
  
for Analysis in Analysis_List:
  tree.TAttach(ZeroMuons,Analysis)

if bData :
  samples = data_samples
elif bRecoil :
  samples = recoil_samples 
else :
  samples = background_samples 

if DEBUG : 
    samples = samples[0:1]
    samples[0].File = samples[0].File[0:1]
print samples
a.Run(".", conf, samples)
