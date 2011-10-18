from icf.core import PSet


defaultBkgdConfig= PSet(
    Cuts=PSet(
    signalLow=1.,
    signalUp=-1.,
    bkgdLow=0.,
    bkgdUp=-1.,
    nBinVar1=3,
    rebinX=1,
    ),
    # Controls which bits of the ntuple will be used by the code
    Samples=PSet(
    plotName="somewhere",
    outputDir="somewhere",
    Signal="nothing",
    Background=PSet(
    Zinv="nothing",
    Zjets="nothing",
    Wjets="nothing",
    QCD="nothing",
    )
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


