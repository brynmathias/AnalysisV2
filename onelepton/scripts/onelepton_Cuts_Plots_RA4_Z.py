import setupSUSY
from libFrameworkSUSY import *
from libOneLepton import *
from copy import deepcopy
import libWPol as wpol
import libHadronic as had


from icf.core import PSet, Analysis, susyDir
from icf.utils import json_to_pset
#from onelepton_settings import *

from onelepton_dataRA4_sync_settings import *
from onelepton.filters import reweightVertices
from onelepton.utils import getDeadECALList


json = JSONFilter("Cert_160404-165542",
                  json_to_pset("%s/onelepton/json/Json_Latest.txt" % susyDir()))

# lepton specific cuts
TwoMu      = OP_NumComMuons("==",2)
selection = OP_GoodEventSelection()
skim_ps=PSet(
    SkimName = "myskim",
    DropBranches = False,
    Branches = [
        " keep * "
        ]
)
skim = SkimOp(skim_ps.ps())
ZPlots = OP_Zplots("jdt")

# Create analysis cut tree


def setupMuonPreselection(MET, name, mode, less_than_3jets=False):
    a = Analysis(name)
    filters = []
    tree = Tree("Main")
    a += tree
    ## Add jet iD
    pfJetId = PFJetIDLoose()
    a.AddJetFilter("PreCC",pfJetId)
    filters += [pfJetId]

    # Add muon ID
    customMuID = CustomVBTFMuID(Mus.ps())
    a.AddMuonFilter("PreCC", customMuID)
    filters += [customMuID]

    # Muon-jet DR cut
    #    mu_jet_dr = MuonJetDRFilter(0.1, Mus.ps())
    mu_jet_dr = MuonJetDRFilterRA4Sync(0.1, Mus.ps())
    a.AddJetFilter("PreCC", mu_jet_dr)
    filters += [mu_jet_dr]

    # Add electron ID
    #    eleID = LooseEleId()
    eleID = CustomEleIdRA4Sync(Els_Sig.ps())
    a.AddElectronFilter("PreCC", eleID)
    filters += [eleID]

    # Electron-jet DR cut
    el_jet_dr = EleJetDRFilter(0.3)
#    el_jet_dr = EleJetDRFilterRA4Sync(0.3, Els_Sig.ps())
    a.AddJetFilter("PreCC", el_jet_dr)
    filters += [el_jet_dr]

    # this replaces typeI and uncorrected PFMET
    if MET == "typeI":
        met_typeI_filter = pfMETtopfMETtypeI()
        a.AddMETFilter("pfMET",met_typeI_filter)
        filters += [met_typeI_filter]


    # the residual JetCorrections are different from PF and Calo, so be careful
    # when adding them.
    if mode == "data39":
        JetCorrections = JESCorrections( corPset.ps() ,0)
        a.AddJetFilter("PreCC",JetCorrections)
        filters += [JetCorrections]
    # 311 MC needs to be reweighted accoring to vertex multiplicity
    # see onelepton/python/onelepton/filters.py
    if mode == "MC311" or mode == "MC42ttw_Z41" or mode == "MC42QCD" or mode == "MCskims":
        vert = reweightVertices(a)
        filters += [vert]



    tree.Attach(selection)
    tree.TAttach(selection,TwoMu)
    tree.TAttach( TwoMu,  ZPlots)
    
    return (a, tree, filters)
