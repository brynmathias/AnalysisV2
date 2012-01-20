# Configuration file
import math
# SumLepPT (or PFMET bins)

#WARNING to you you awful noob!!! If you change this, emember to properly
#correct ewKN further down or things will be screwed!! Neither of us wants that
#to happen do we?
bins = [250, 350, 450]

useRealData = True
icfNEventsIn = 10000.
icfDefaultLumi = 100.
lumiError   = 0.045         # Relative error on luminosity estimate (for limit setting)
minXSToConsider = 0.0000001
minEffToConsider = 0.000001
lumiCorrection = 1.05
run_systematics = False
run4jets = False
includeSignalContamination = False
clsToys = 1000
expectedLimit = True

# Whether to do LP analysis
analysis = "lp"
# or pfmet
#analysis = "pfmet"

# Set the bin_name depending on analysis selected
# Used to locate correct histograms
if analysis == "lp": binName = "SumLepPT"
elif analysis == "pfmet" : binName = "PFMETCut"

selectAPoint = None
#selectAPoint = (80, 400)

# These are paths to various versions of the output ROOT files
# The zero entry corresponds to unscaled MC
# The others correspond to systematic variations
path = {
    "zero":"../resultsMC",
    "metup":"../resultsMC_metup",
    "metdown":"../resultsMC_metdown",
    "metup_flat" : "../resultsMC_metup_flat",
    "metdown_flat": "../resultsMC_metdown_flat",
    "metres":"../resultsMC_metres_conservative",
    "metres11":"../resultsMC_metres_11",
    "metres12":"../resultsMC_metres_12",
    "polup":"../resultsMC_polup",
    "poldown":"../resultsMC_poldown",
    "muscale":"../resultsMC_mupt",
    }

#if run_systematics: path = dict([(k,v+"_SYST") for k, v in path.iteritems()])
if run4jets:
    path = dict([(k,v.replace("resultsMC", "resultsMC_4jts")) for k, v in path.iteritems()])
    path = dict([(k,v.replace("resultsData", "resultsData_4jts")) for k, v in path.iteritems()])

# Name format of the histogram path
bin_fmt = "Counter_BSMGrid_%s%dsecondDcut500%s_scale1/%s"
#bin_fmt = "Counter_BSMGrid_%s%d%s_scale1/%s"
# Name of the counter histogram for SM MC
hname = "SM_Events"
hname_noweight = "SM_Events_noweight"
# Which susyScan to use
susyScan = "tanbeta10"
# use NLO signal xs for limit?
use_nloxs = True

processes = ["gg", "sb", "ss", "sg", "ll", "nn", "ng", "bb", "tb", "ns"]

pdfUncertainty = 0.1

run_sms = False

# Benchmark points to use in limits plotting
lmPoints = [
    ("LM0", 200, 160),
    ("LM1", 60, 250),
    ("LM2", 185, 350),
    ("LM3", 330,240),
    ("LM4", 210, 285),
  #  ("LM5", 230,    360),

    ("LM6", 85, 400)
    ]

# Defines systematics to be included in limit setting
systs = {
    "signal": ["jec", "metres", "lep"],
    "bg_only" : ["Wtt", "pol"]
    }

# List of systematics
fields =          [             "name",   "title",                      "signal", "background"]
systInfo =  {
    "jec" :    dict(zip(fields, ["jec",    "JES Uncertainty",            True,    True])),
    "jec_flat" :    dict(zip(fields, ["jec_flat",    "JES Uncertainty (Flat 5\%)",            True,    True])),

    "metres" : dict(zip(fields, ["metres", "MET Resolution Uncertainty", True,    True])),
    "metres11" : dict(zip(fields, ["metres11", "MET Resolution Uncertainty (11\%)", True,    True])),
    "metres12" : dict(zip(fields, ["metres12", "MET Resolution Uncertainty (12\%)", True,    True])),
    "lep"    : dict(zip(fields, ["lep",    "Lepton pT Scale",            True,    True])),
    "pol"    : dict(zip(fields, ["pol",    "W Polarisation",             False,   True])),
    "ttpol"  : dict(zip(fields, ["ttpol",  "tt Polarisation",            False,   True])),
    "Wtt"    : dict(zip(fields, ["Wtt",    "W/tt Ratio",                 False,   True])),
    "MCStats" : dict(zip(fields, ["MCStats", "MC Statistics",            False,   True])),
    "pcdfunc" : dict(zip(fields, ["pdfunc", "PDF Uncertainty",            True, False]))
}

plusMinus = {"OneSigma" : 1.0}

class Muon:
    name = "muon"
    # Integrated luminosity to use for limit setting/systs
    lumi = 3800.0 #1082.0*lumiCorrection
    # Trigger efficiency
    triggerEfficiency = 0.91
    # background MC to use in pseudo-data
    bkgSamples = ["w", "tt", "z"]
    # signal MC to use in pseudo-data
    sigSamples = []
    # MC PseudoData
    pseudoDataSamples = bkgSamples + sigSamples
    realDataSamples = ["data42x"]

    if useRealData:
        dataSamples = realDataSamples
        mcLumi = None
    else:
        dataSamples = pseudoDataSamples
        mcLumi = lumi
    # These give the paths for each MC sample according to their short name
    # The %s will be replaced with a base directory from the dictionary above
    files = {
        "w" : "%s/Muons_WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14.root",
        "tt" : "%s/Muons_TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14.root",
        "z" : "%s/Muons_DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14.root",
        # "lm1" : "%s/Muons_LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
        # "lm3" : "%s/Muons_LM3_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
        # "lm6" : "%s/Muons_LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
        "tanbeta10" : "%s/Muons_mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1.root",
        "sms" : "%s/../resultsSMS/Muons_SMS_T3w_x_0p25to0p75_Mgluino_100to1200_mLSP_50to1150_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v2_V15_03_18_scan_T3w.root",
        #"sms" : "%s/../resultsSMS/Muons_SMS_T2tt_Mstop_225to1200_mLSP_50to1025_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v1_V15_03_18_scan_T2tt.root",
        "data42x" : "%s/../resultsData/Muons_data.root"
        }

    if run_systematics:
        del files["tanbeta10"]
        del files["data42x"]
        # files["w"] =  "%s/Muons_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_v15_03_13.root"

    includeSignalSysts = [
#        "jec",
#        "metres",
#        "pdfunc"
    ]

    includeBackgroundSysts = [
        "jec",
        "metres",
        "Wtt",
        "pol",
        "lep",
#        "ttpol"
    ]

    # Constants used in limit-setting
    bkgPrediction = None
    ctrlChannel = None
    ttPolarisationUncertainty = [0.05, 0.05, 0.05, 0.05][1:]

class Electron:
    name = "electron"
    # Integrated luminosity to use for limit setting/systs
    lumi = 4000.0 #1079.0*lumiCorrection
    # Trigger efficiency
    triggerEfficiency = 0.96

    # background MC to use in pseudo-data
    bkgSamples = ["w", "tt", "z"]
    # signal MC to use in pseudo-data
    sigSamples = []
    # MC PseudoData
    pseudoDataSamples = bkgSamples + sigSamples
    realDataSamples = ["data42x"]

    if useRealData:
        dataSamples = realDataSamples
        mcLumi = None
    else:
        dataSamples = pseudoDataSamples
        mcLumi = lumi


    # These give the paths for each MC sample according to their short name
    # The %s will be replaced with a base directory from the dictionary above
    files = {
        #        "w" : "%s/Electrons_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1.root",
#        "w" : "%s/Electrons_WJetsToLNu_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_v15_03_13.root",
        "w" : "%s/Electrons_WJetsToLNu_300_HT_inf_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14.root",
        "tt" : "%s/Electrons_TTJets_TuneZ2_7TeV_madgraph_tauola_Summer11_PU_S4_START42_V11_v1_V15_03_14.root",
        "z" : "%s/Electrons_DYJetsToLL_TuneZ2_M_50_7TeV_madgraph_tauola_Spring11_PU_S1_START311_V1G1_v1.root",
        # "lm1" : "%s/Electrons_LM1_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
        # "lm3" : "%s/Electrons_LM3_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
        # "lm6" : "%s/Electrons_LM6_SUSY_sftsht_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1.root",
        #        "tanbeta10" : "%s/Electrons_PhysicsProcesses_mSUGRA_tanbeta10Fall10v1.root",
        "tanbeta10" : "%s/Electrons_mSUGRA_m0_20to2000_m12_20to760_tanb_10andA0_0_7TeV_Pythia6Z_Summer11_PU_S4_START42_V11_FastSim_v1.root",
        "data42x" : "%s/../resultsData/Electrons_data.root",
	"sms" :	"%s/Electrons_SMS_T2tt_Mstop_225to1200_mLSP_50to1025_7TeV_Pythia6Z_Summer11_PU_START42_V11_FastSim_v1_V15_03_18_scan_T2tt.root"

        }

    if run_systematics:
        del files["tanbeta10"]
        del files["data42x"]

    includeSignalSysts = [
#       "jec",
#       "metres",
#       "pdfunc"
    ]

    includeBackgroundSysts = [
        "jec",
        "metres",
        "Wtt",
        "pol",
#        "ttpol"
    ]

    # Old numbers without residual corrections applied
    # ewkN   = [292, 94, 21, 11]
    # ewkErr = [23,  12, 5,  4 ]
#    ewkN   = [329.4, 117.6, 25.9, 12.4][1:]
    ewkN = [329.4, 117, 28.9, 12.5][1:]
    #    ewkErr = [22.7,  11.6, 5.8,  3.8 ]
    ewkErrStat = [0.05, 0.09, 0.16, 0.24][1:]
    ewkErrMCStat = [0.09, 0.16, 0.25, 0.32][1:]
    ewkRelErr = [math.sqrt(a**2 + b**2) for a, b in zip(ewkErrStat, ewkErrMCStat)]
    ewkErr = [err*N for err, N in zip(ewkN, ewkRelErr)]
    ctrlChannel = Muon

    bkgPrediction = "QCDFit"


    # if not useRealData: bkgPrediction = None
    # else: bkgPrediction = "QCDFit" # "OtherChannel", None
    ttPolarisationUncertainty = [0.05, 0.05, 0.05, 0.05][1:]

channels = [Muon] #, Electron]






