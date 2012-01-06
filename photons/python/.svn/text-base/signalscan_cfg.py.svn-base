#!/usr/bin/env python

from golden_cff import *

from montecarlo.GGMSignalScan import GGMSignalScan

met = OP_PFMETCut(70.0)

signalScanPlots_trigger=OP_SignalScan("signalScan_trigger")
signalScanPlots_jets=OP_SignalScan("signalScan_jets")
signalScanPlots_leptonveto=OP_SignalScan("signalScan_leptonveto")
signalScanPlots_photon=OP_SignalScan("signalScan_photon")
signalScanPlots_ht=OP_SignalScan("signalScan_ht")
signalScanPlots_met=OP_SignalScan("signalScan_met")

# -----------------------------------------------------------------------------
# Cut flow

t=Tree("Main")
t.Attach(htCut250)
t.TAttach(htCut250,signalScanPlots_trigger)
t.TAttach(signalScanPlots_trigger,numComJets)
t.TAttach(numComJets,signalScanPlots_jets)
t.TAttach(signalScanPlots_jets,numComLeptons)
t.TAttach(numComLeptons,signalScanPlots_leptonveto)
t.TAttach(signalScanPlots_leptonveto,selectedPhotons)
t.TAttach(selectedPhotons,signalScanPlots_photon)
t.TAttach(signalScanPlots_photon,htCut)
t.TAttach(htCut,signalScanPlots_ht)
t.TAttach(signalScanPlots_ht,met)
t.TAttach(met,signalScanPlots_met)

# -----------------------------------------------------------------------------
# Definition of analyses

a=Analysis("Photon_70")
#a=Analysis("Photon_70_JEplus5pc")
#a=Analysis("Photon_70_JEminus5pc")
a.AddUserVar("SelectedPhotons",selected_photons)
a+=t

# -----------------------------------------------------------------------------
# Run analyses

a.Run("/home/hep/rjn04/SUSY2/photons/results/AK5PF",conf_ak5_pf,[GGMSignalScan])
