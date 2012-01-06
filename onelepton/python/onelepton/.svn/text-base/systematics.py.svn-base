import setupSUSY
from icf.core import PSet

def loadMETResolutionBins(fname, debug=True):
    " Read MET Resolution bins from text file fname and return PSet "
    f = open(fname, "r")
    genmht_bins = []
    resolutions = []
    for line in f:
        line = line.split("#")[0]
        try:
            fields = [float(f.strip().rstrip()) for f in line.split(",")]
        except ValueError:
            continue
        assert(len(fields) == 2)
        genmht_bins.append(fields[0])
        resolutions.append(fields[1])
    opset = PSet(
        GenMHTBins = genmht_bins,
        ResolutionFactors = resolutions
        )
    if debug:
        print
        print "MET Resolution Filter"
        print "="*80
        print "File: %s" % fname
        for genmht_bin, resolution in zip(genmht_bins, resolutions):
            print "{0:<10.1f} {1:<10.5f}".format(genmht_bin, resolution)
        print "="*80
        print
    return opset

def loadPolarisationReweightingFactors(fname, debug=True):
    " Read reweighting factors from text file fname and return PSet "
    f = open(fname, "r")
    factors = []
    for line in f:
        line = line.split("#")[0]
        try:
            fields = [float(f.strip().rstrip()) for f in line.split(",")]
        except ValueError:
            continue
        assert(len(fields) == 8)
        factors.append(fields)
    if debug:
        print
        print "W Polarisation Reweightin Factors"
        print "="*80
        print "File: %s" % fname
        fmt_str = " ".join(["{%d:<10s}" % i for i in range(8)])
        print fmt_str.format("ptw", "y", "alpha+", "beta+", "gamma+", "alpha-", "beta-", "gamma-")
        for factor in factors:
            fmt_str = "{0:<10.0f} {1:<10.1f}" + " ".join(["{%d:<10.5f}" % i for i in range(2, 8)])
            print fmt_str.format(*factor)
    return PSet(
        PTBins = list(set([f[0] for f in factors])),
        YBins = list(set([f[1] for f in factors])),
        AlphaPlus = [f[2] for f in factors],
        BetaPlus = [f[3] for f in factors],
        GammaPlus = [f[4] for f in factors],
        AlphaMinus = [f[5] for f in factors],
        BetaMinus = [f[6] for f in factors],
        GammaMinus = [f[7] for f in factors]
        )




