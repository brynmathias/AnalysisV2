from icf.core import PSet


defaultBkgdConfig= PSet(
    Cuts=PSet(
    signalLow=1.,
    signalUp=-1.,
    bkgdLow=0.,
    bkgdUp=-1.,
    nBinVar1=3,
    rebinX=1,
    HTcut_First=250.,
    HTcut_FirstUp=400.,
    HTcut_Second=400.,
    ),
    # Controls which bits of the ntuple will be used by the code
    Samples=PSet(
    plotName="somewhere",
    outputDir="somewhere",
    Signal="nothing",
    mSuGra="nothing",
    Data="nothing",
    Background=PSet(
    ttbar="",
    Zinv="",
    Zjets="",
    Wjets="",
    QCD="",
    )
    ),
    mSuGraSettings = PSet(
    mSuGraDir = "mSuGraScan_350", #HT > 350
    mSuGraHist = "m0_m12_0", #_0 all jet Mult. _1 2 jet events _2 >2 jet events
    tanBeta = 3,
    nbins_x = 80,
    min_x = 0,
    max_x = 4000,
    binsize_x = 50,
    nbins_y = 25,
    min_y = 100,
    max_y = 600,
    binsize_y = 20,
    ),
    Significance=PSet(
    mSuGraDir = "mSuGraScan_njet_350",
    mSuGraHist = "m0_m12",
    outputPlotName = "ProfilePlot",
    CutAndCountOrRatio = "Ratio", #Ratio or CutAndCount
    method = "Profile",
    testFactor = 1.,#dangerous only for funny tests only change if you know what you are doing!
    lumi=10,
    useRealData=1,
    exclusion_significance=0.95,#95%CL
    precision=0.02,
    integration_upperLimit=1000000000,
    uncertainty_qcd=1,
    uncertainty_ewk=0.5,
    rhonomSigma=1.,
    ),
    Graphics=PSet(
    drawLegend=0,
    y_axis_title="",
    x_axis_title="",
    upperLimit=4.E-3,
    lineStyleB=22,
    lineStyleSuB=24,
    )
)


