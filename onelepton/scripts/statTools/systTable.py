#!/usr/bin/env python

""" This script steers the systematics calculations and outputs a LaTeX
table. The actual calculations are performed in the C++ files predict.C
"""

import ROOT as r
import math
import os.path
from LatexTable import Table
from config import path, bin_fmt, bins, systInfo, Muon, Electron
import utils
import math

if __name__ == "__main__":
    r.gROOT.LoadMacro("predict.C+")
    channel = Muon
    ctrl_channel = None
    # Load MC pseudo-data in bins
    data = utils.getZeroMC(channel, ctrl_channel)
    # This also calculates statistical uncertainties
    results = utils.makePredictions(data)

    # Get the scaled/smeared systematic variations
    systs = utils.getLiterallyAllSystematicsBkg(channel, ctrl_channel)

    # Loop through systematics and calculate systematic uncertainty
    for name, scaled in systs:
        utils.addSystematic(name, data, results, scaled)
        print name

    # LaTeX table
    l = Table()
    cols = [("value", "Bin", "l")] + [("bin%d" % i, utils.formatBin(i), "c") for i in range(len(bins))]

    l.defineColumns(cols)

    def fields(f):
        return dict([("bin%d" % idx, f(idx)) for idx in range(len(bins))])

    l.addRowFields(value = "Events Predicted", **fields(lambda idx : "%.1f" % results[idx].predicted()))
    l.addRowFields(value = "Events Observed", **fields(lambda idx : "%.1f" % results[idx].observed()))
    l.addRowFields(value = "$N_{\\textrm{signal}}/N_{\\textrm{control}}$", **fields(lambda idx : "%.2f" % data[idx].R()))
    l.addHLine()
    l.addRowFields(value = "Statistical Uncertainty (\%)",
                   **fields(lambda idx : "%.2f" % (results[idx].statErrorValue(0)*100/results[idx].predicted())))
    l.addHLine()
    l.addRowFields(value = "Systematic Uncertainty (\%)", **fields(
        lambda idx : "%.2f" % (math.sqrt(results[idx].totalSystError()**2 +
                            results[idx].statErrorValue("stat_control")**2)*100/results[idx].predicted())))
    l.addRowFields(value = "\\hspace{0.5cm}Control Region Stat. (\%)",
                   **fields(lambda idx : "%.2f" % (results[idx].statErrorValue("stat_control")*100/results[idx].predicted())))

    # For each systematic, display percentage uncertainty on predicted number of events
    for name, scaled in systs:
        l.addRowFields(value = "\\hspace{0.5cm}%s (\%%)" % systInfo[name]["title"],
                       **fields(lambda idx : "%.2f" % (results[idx].systErrorValue(name)*100/results[idx].predicted())))
    l.addRowFields(value = "\\hspace{0.5cm}PDF Uncertainty (\%)")

    combined = r.CombinedResult()
    for res in results:
        combined.addBin(res)

    # row = l.getDefaultRow()
    # row["bin"] = "Combined"
    # row["sig"] = "%.1f" % combined.getChi2()
    # l.addRow(row)

    # Render table
    print l.render()

    # combined.getResiduals().Print()

    # combined.getCovarianceMatrix().Print()
    # print combined.getChi2()
    # print math.sqrt(2)*r.TMath.ErfInverse(1 - r.TMath.Prob(combined.getChi2(), len(bin_data)))
