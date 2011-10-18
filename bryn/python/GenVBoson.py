#!/usr/bin/env python

# -----------------------------------------------------------------------------
# Includes

from golden_cff import *

from wjets import *

from zjets import *

from Zinv import *

from PhotonJet import *

GenVBosons = OP_GenVBosons("GenVBoson",150.)
GenVBosons200 = OP_GenVBosons("GenVBoson200",200.)
ComJetPlots = OP_ComJetPlots("Jets",5)
# -----------------------------------------------------------------------------
# Cut flow

def addCutFlow(a) :
    a+=GenVBosons
    a+=GenVBosons200
# -----------------------------------------------------------------------------
# Definition of analyses

anal_ic5_calo=Analysis("IC5Calo")
addCutFlow(anal_ic5_calo)

# -----------------------------------------------------------------------------
# Run analyses
#anal_ic5_calo.Run("results",conf_ic5_calo,[Wenu])

#anal_ic5_calo.Run("results",conf_ic5_calo,[Zinvisible_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[wjets_madgraph])
#anal_ic5_calo.Run("results",conf_ic5_calo,[Zinvisible_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[pjets_madgraph_40])
anal_ic5_calo.Run("results",conf_ic5_calo,[pjets_madgraph_200])
anal_ic5_calo.Run("results",conf_ic5_calo,[pjets_madgraph_100_200])
anal_ic5_calo.Run("results",conf_ic5_calo,[Wenu])
#anal_ic5_calo.Run("results",conf_ic5_calo,[qcd_pythia_merged])
#anal_ic5_calo.Run("results",conf_ic5_calo,[wjets_madgraph])
#anal_ic5_calo.Run("results",conf_ic5_calo,[w_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[z_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[ttbar_jets])
#anal_ic5_calo.Run("results",conf_ic5_calo,[z_inv])


