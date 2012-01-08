import setupSUSY

from icf.core import PSet

import libFrameworkSUSY as fwk
import libWPol as wpol
import libOneLepton as one

from systematics import loadMETResolutionBins, loadPolarisationReweightingFactors

def metScaleSystematic(a, shiftdir, lepton):
    """ Apply the pfmet scale systematic as a MET filter.
    a : analysis object
    shiftdir : True (False) for upwards (downwards) shift
    lepton : 'Muon' or 'Electron'
    """
    pfmet_jecunc = PSet(
        #the location of the JECUncertainty txt file
        jecuncfile = "GR_R_42_V19_AK5PF_Uncertainty.txt",
        jecuncfileresidual = "/vols/cms01/mstoye/SVNtestKill/SUSYv2/onelepton/scripts/GR_R_42_V19_AK5PF_L2L3Residual.txt",
        #either Muon or Electron
        lepton = lepton,
        #the jet threshold to consider for the JEC Uncertainties
        pfjetthresh = 10.0,
        #the percentage/100 to shift the unclustered energy by
        unclusteredshift = 0.05,
        #whether or not to apply the shift upwards (True) or downwards (False)
        shiftup = shiftdir
        )
    pfmetjecunc = wpol.pfMETJECUnc(pfmet_jecunc.ps())
    a.AddMETFilter("pfMET", pfmetjecunc)
    return pfmetjecunc

def metScaleSystematicJets(a, shiftdir):
    myJESCorrectionsFromFile = one.JESCorrectionsFromFile(shiftdir,"GR_R_42_V19_AK5PF_Uncertainty.txt")
    a.AddJetFilter("PreCC",myJESCorrectionsFromFile)
    return myJESCorrectionsFromFile

def metScaleSystematicFlat(a, lepton, shiftdir):
    shift = {True:1.05, False:0.95}[shiftdir]
    filt = one.pfMETScale(lepton, shift)
    a.AddMETFilter("pfMET", filt)
    return filt
def JESjetsFlat(a, shiftdir):
    jetshift = {True:5., False:-5.}[shiftdir]
    filtJets = fwk.JESCorrectionsTrivial(jetshift)
    a.AddJetFilter("PreCC",filtJets)
    return filtJets

def metResolutionSystematic(a, lepton, smear = 0.01):
    # the results from the fits: (see root_macros/METResolutionFits_binned.C)
    if lepton == "Muon":
        res_ps = loadMETResolutionBins(
            "/vols/cms03/as1604/ra4/onelepton/scripts/systTools/METResolution.txt")
    elif lepton == "Electron":
        raise ValueError("Electron factors not made yet!")
    else: raise ValueError("Invalid lepton type: %s" % lepton)

    res_ps._quiet_set("Smear", smear)
    res_ps._quiet_set("Lepton", lepton)
    met_res_filter = one.pfMETResSmear(res_ps.ps())
    a.AddMETFilter("pfMET", met_res_filter)
    return met_res_filter

def metResolutionSystematicNaive(a, lepton, smear_long, smear_trans):
    met_res_filter = one.METResSmearNaive(lepton, smear_long, smear_trans)
    a.AddMETFilter("pfMET", met_res_filter)
    return met_res_filter

def reweightVertices(a):
    """ Apply the vertex reweighting factors for MC
    a : analysis object
    """
    vertex_reweight = fwk.VertexReweighting(
        PSet(

        ## Spring11 Re-Weighting factors
        #        VertexWeights = [0.000, 0.114, 0.403, 0.866, 1.302, 1.351,
        #                         1.314, 1.279, 1.063, 1.027, 0.977, 1.015,
        #                         1.080, 0.945, 1.127, 1.420, 1.253, 1.207,
        #                         4.618, 1.358, 0.000, 0.000, 0.000, 0.000,
        #                         0.000, 0.000, 0.000, 0.000, 0.000, 0.000,
        #                         0.000, 0.000, 0.000, 0.000, 0.000]
        
        ## Pre-LP Vertex Re-Weigting factors
        #        VertexWeights = [0.0, 0.169, 0.511, 1.276, 1.688, 1.564,
        #        1.715, 1.135, 1.042, 0.476, 0.469, 0.385,
        #        0.359, 0.37, 0.502, 0.489, 0.0, 0.0, 0.0, 0.0]
        
        ##  Re-Weightiung factors
        #        VertexWeights = [0.000, 0.074, 0.424, 0.869, 1.295, 1.477,
        #                         1.457, 1.377, 1.376, 1.206, 1.075, 1.304,
        #                         1.061, 0.896, 0.968, 0.926, 0.752, 1.223,
        #                         0.000, 0.000]

        ## Full 2011 data Re-Weightiung factors
        #        VertexWeights = [0.000, 0.057, 0.358, 0.723, 1.041, 1.232,
        #                         1.337, 1.356, 1.365, 1.410, 1.483, 1.541,
        #                         1.643, 1.876, 1.872, 2.241, 2.860, 2.806,
        #                         3.186, 5.018, 2.389, 4.460, 0.000, 0.000,
        #                         0.000, 0.000, 0.000, 0.000, 0.000, 0.000,
        #                         0.000, 0.000, 0.000, 0.000, 0.000]

        ## Fall11 MC sample Re-Weighting factors using the full 2011 dataset
        VertexWeights = [0.000, 0.495, 0.867, 1.159, 1.348, 1.375,
                         1.371, 1.276, 1.177, 1.033, 0.877, 0.697,
                         0.531, 0.399, 0.285, 0.234, 0.158, 0.111,
                         0.074, 0.074, 0.034, 0.061, 0.000, 0.000,
                         0.000, 0.000, 0.000, 0.000, 0.000, 0.000,
                         0.000, 0.000, 0.000, 0.000, 0.000]
        
        ).ps()
        )
    a.AddWeightFilter("Weight", vertex_reweight)
    return vertex_reweight

def polarisationReweighting(a, lepton, shift = 0.15, debug=False,plus_only=False):
    """ Apply polarisation reweighting factors for MC """
    ps = loadPolarisationReweightingFactors(
        "systTools/reweightFactors.txt"
        )
    ps._quiet_set("Lepton", lepton)
    ps._quiet_set("fLmfRShift", shift)
    ps._quiet_set("Debug", debug)
    ps._quiet_set("Charge_plus", plus_only)
    polfilter = one.PolarisationReweighting(ps.ps())
    a.AddWeightFilter("Weight", polfilter)
    return polfilter

def muPtScaleSystematic(a, gen=False):
    """ Apply muon pT Scale systematic from wpol code """
    pt_scale = one.MuPtScaleFilter(gen)
    a.AddMuonFilter("PreCC", pt_scale)
    pfmet_pt_scalePSet = PSet(
        Lepton = "Muon",
        Gen = gen
        ).ps()
    pfmet_pt_scale = one.pfMETLeptonScale(pfmet_pt_scalePSet)
    a.AddMETFilter("pfMET",pfmet_pt_scale)
    return (pt_scale, pfmet_pt_scale)

def elPtScaleSystematic(a, gen = False, shiftVal = 0.01, shiftDir = True):
    """ Apply muon pT Scale systematic from wpol code """
    pt_scale = one.ElPtScaleFilter(shiftVal, shiftDir)
    a.AddElectronFilter("PreCC", pt_scale)
    pfmet_pt_scalePSet = PSet(
        Lepton = "Electron",
        Gen = gen ,
        ElPtScaleValue = shiftVal,
        ElPtScaleDirection = shiftDir
        ).ps()
    pfmet_pt_scale = one.pfMETLeptonScale(pfmet_pt_scalePSet)
    a.AddMETFilter("pfMET",pfmet_pt_scale)
    return (pt_scale, pfmet_pt_scale)

def ttpolarisationReweighting(a, lepton, shift):
    ttpolfilter = one.TTPolarisationReweighting(lepton, shift)
    a.AddWeightFilter("Weight", ttpolfilter)
    return ttpolfilter


def muonSystematics(a, mode):
    """ Setup all of the muon systematics according to a mode string.
    If None is specified, no systematics are added."""
    filters = []

    if mode is None:
        return
    elif mode == "metup":
        filters += [metScaleSystematic(a, True, "Muon")]
        filters += [metScaleSystematicJets(a, True)]
    elif mode == "metdown":
        filters += [metScaleSystematic(a, False, "Muon")]
        filters += [metScaleSystematicJets(a, False)]
    elif mode == "metup_flat":
        filters += [metScaleSystematicFlat(a, "Muon", True)]
        filters += [JESjetsFlat(a, True)]
    elif mode == "metdown_flat":
        filters += [metScaleSystematicFlat(a,"Muon", False)]
        filters += [JESjetsFlat(a,False)]

    elif mode == "metres_conservative":
        filters += [metResolutionSystematicNaive(a, "Muon", 0.075, 0.0375)]
    elif mode == "metres_11":
        filters += [metResolutionSystematicNaive(a, "Muon", 0.046, 0.023)]
    elif mode == "metres_12":
        filters += [metResolutionSystematicNaive(a, "Muon", 0.066, 0.033)]
    elif mode == "metres":
        filters += [metResolutionSystematic(a, "Muon", 0.01)]
    elif mode == "polup":
        filters += [polarisationReweighting(a, "Muon", 0.10, False,False)]
    elif mode == "poldown":
        filters += [polarisationReweighting(a, "Muon", -0.10, False,False)]
    elif mode == "polup_plus":
        filters += [polarisationReweighting(a, "Muon", 0.05, False,True)]
    elif mode == "poldown_plus":
        filters += [polarisationReweighting(a, "Muon", -0.05, False,True)]
    elif mode == "ttpolup":
        filters += [ttpolarisationReweighting(a, "Muon", 0.05)]
    elif mode == "ttpoldown":
        filters += [ttpolarisationReweighting(a, "Muon", -0.05)]
    elif mode == "mupt":
        filters += [muPtScaleSystematic(a)]
    else: raise ValueError("Invalid systematics mode: %s" % mode)

    return filters

def electronSystematics(a, mode):
    """ Setup all of the electron systematics according to a mode string.
    If None is specified, no systematics are added."""
    filters = []

    if mode is None:
        return
    elif mode == "metup":
        filters += [metScaleSystematic(a, True, "Electron")]
    elif mode == "metdown":
        filters += [metScaleSystematic(a, False, "Electron")]
    elif mode == "metup_flat":
        filters += [metScaleSystematicFlat(a, "Electron", True)]
        filters += [JESjetsFlat(a, True)]
    elif mode == "metdown_flat":
        filters += [metScaleSystematicFlat(a, "Electron", False)]
        filters += [JESjetsFlat(a,False)]
    elif mode == "metres_conservative":
        filters += [metResolutionSystematicNaive(a, "Electron", 0.075, 0.0375)]
    elif mode == "metres_11":
        filters += [metResolutionSystematicNaive(a, "Electron", 0.046, 0.023)]
    elif mode == "metres_12":
        filters += [metResolutionSystematicNaive(a, "Electron", 0.066, 0.033)]
    elif mode == "metres":
        filters += [metResolutionSystematic(a, "Electron", 0.01)]
    elif mode == "polup":
        filters += [polarisationReweighting(a, "Electron", 0.10, False,False)]
    elif mode == "poldown":
        filters += [polarisationReweighting(a, "Electron", -0.10, False,False)]
    elif mode == "polup_plus":
        filters += [polarisationReweighting(a, "Electron", 0.05, False,True)]
    elif mode == "poldown_plus":
        filters += [polarisationReweighting(a, "Electron", -0.05, False,True)]
    elif mode == "ttpolup":
        filters += [ttpolarisationReweighting(a, "Electron", 0.05)]
    elif mode == "ttpoldown":
        filters += [ttpolarisationReweighting(a, "Electron", -0.05)]
    elif mode == "elpt_up":
        filters += [elPtScaleSystematic(a, False, 0.01, True)]
    elif mode == "elpt_down":
        filters += [elPtScaleSystematic(a, False, 0.01, False)]
    else: raise ValueError("Invalid systematics mode: %s" % mode)

    return filters




