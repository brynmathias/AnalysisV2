#!/usr/bin/env python

from golden_cff import *

#from data.EG_Run2010A_Sep17ReReco_v2 import EG_Run2010A_Sep17ReReco_v2
#from data.Photon_Run2010B_PromptReco_v2 import Photon_Run2010B_PromptReco_v2
#from data.Photon_22_10_2010_375 import Photon_22_10_2010_375
#from data.Photon_26_10_2010_378 import Photon_26_10_2010_378
#from data.Photon_Run2010B_PromptReco_v2_291010 import Photon_Run2010B_PromptReco_v2_291010
#from data.Photon_05_11_2010_405 import Photon_05_11_2010_405
#from data.Photon_onefile import Photon_onefile
from data.Photon_Run2010B_Nov4ReReco_v1 import Photon_Run2010B_Nov4ReReco_v1

#Photon = [EG_Run2010A_Sep17ReReco_v2, Photon_Run2010B_PromptReco_v2, Photon_22_10_2010_375, Photon_26_10_2010_378, Photon_Run2010B_PromptReco_v2_291010, Photon_05_11_2010_405]

trigger_pset = PSet(
    Verbose = False,
    Triggers = [
        "HLT_Photon30_L1R",
        "HLT_Photon30_Cleaned_L1R",
        "HLT_Photon30_L1R_8E29",
        "HLT_Photon30_Isol_EBOnly_Cleaned_L1R_V1",
        ]
)
trigger = OP_MultiTrigger(trigger_pset.ps())
#trigger = OP_TriggerCut("HLT_Photon30_Cleaned_L1R")
tcMETCut = OP_tcMETCut(30.)
spike_study = OP_SpikePlots("SpikePlots")
dump = OP_Dump()
spikeSelector = OP_SpikeSelector()
event_display = OP_EventDisplay("Event Displays", "all")

# -----------------------------------------------------------------------------
# Cut flow

t=Tree("Main")
t.Attach(NoiseFilt)
t.TAttach(NoiseFilt,selection)
t.TAttach(selection,trigger)
t.TAttach(trigger,numComPhotons)
#t.TAttach(trigger,spikeFilter)
#t.TAttach(spikeFilter,numComPhotons)
t.TAttach(numComPhotons,tcMETCut)
#t.TAttach(spikeFilter,onePhotons)
#t.TAttach(onePhotons,tcMETCut)
t.TAttach(tcMETCut,spike_study)
#t.TAttach(spike_study,spikeSelector)
#t.TAttach(spikeSelector,event_display)

# -----------------------------------------------------------------------------
# Definition of analyses

a=Analysis("Spikes")
#a.AddUserVar("SelectedPhotons",selected_photons)
a+=t

# -----------------------------------------------------------------------------
# Run analyses

a.Run("/home/hep/rjn04/SUSY2/photons/results/AK5Calo",conf_ak5_calo,[Photon_Run2010B_Nov4ReReco_v1])
#a.Run("/home/hep/rjn04/SUSY2/photons/results/AK5Calo",conf_ak5_calo,Photon)
#a.Run("/home/hep/rjn04/SUSY2/photons/results/AK5Calo",conf_ak5_calo,[Photon_onefile])
