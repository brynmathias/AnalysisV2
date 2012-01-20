#!/usr/bin/env python
"""Run over lumiTree for a given PSet and output JSON"""

import setupSUSY
from icf.core import PSet
import ROOT as r
import json
import data.Run2011.HT_Run2011A_PromptReco_v1 as HT
import sys
from optparse import OptionParser

def compress(json):
    """ Translate lumis to lumiranges e.g. [1, 2, 3, 5, 6] -> [[1,3],[5,6]]"""
    cjson = {}
    for run, lumis in json.iteritems():
        slumis = sorted(lumis)
        ranges = []
        start = slumis[0]
        for a, b in zip(slumis, slumis[1:]):
            if b != a+1 and b != a:
                ranges.append([start, a])
                start = b
        ranges.append([start, b])
        cjson[run] = ranges
    return cjson


def scan_for_psets(fname):
    """Scan the specified python file for pset instances with required attributes.
    Requires new-style PSet class"""
    g = {}
    l = {}
    psets = []
    execfile(fname, g, l)
    for k, v in l.iteritems():
        if v.__class__.__name__ == "PSet":
            if getattr(v, "File", None) and getattr(v, "Name", None):
                psets.append(v)
    return psets

if __name__ == "__main__":
    parse = OptionParser(usage="%prog PSETFILE")
    parse.add_option("-o", "--output-file",
                     action="store", type="string",
                     default=None, help="Output file path (default: <pset_name>.json)")
    parse.add_option("-p", "--path-out",
                     action="store", type="string",
                     default=None, help="Output directory for json files")

    (opts, args) = parse.parse_args()

    if len(args) < 1:
        parse.print_usage()
        sys.exit(1)

    psets = scan_for_psets(args[0])
    print "PSets found:"
    print "="*80
    for idx, p in enumerate(psets):
        print "[%d] %s with %d files" % (idx, p.Name, len(p.File))
    print "="*80
    idx = int(raw_input("pset: "))
    if idx >= len(psets):
        print "Invalid selection"
        sys.exit(0)
    pset = psets[idx]
    if raw_input("Scan pset %s for lumi info?" % pset.Name) != "y":
        sys.exit(0)
    ch = r.TChain("lumiTree/tree")
    for f in pset.File:
        ch.Add(f)
    print "Running..."
    runs = {}
    for i in range(ch.GetEntries()):
        if i % 100: print "Entry %d" % i
        ch.GetEntry(i)
        run = getattr(ch, "run")
        if not run in runs:
            runs[run] = []
        lumi = getattr(ch, "lumiSection")
        if not lumi in runs[run]:
            runs[run].append(lumi)
        else:
            print "(%d, %d) seems to be duplicated" % (run, lumi)
    print "Finished running over %d entries" % ch.GetEntries()
    if opts.output_file is None and opts.path_out is None:
        outname = "%s.json" % pset.Name
    elif opts.output_file is not None and opts.path_out is None:
        outname = opts.output_file
    elif opts.output_file is None and opts.path_out is not None:
        if opts.path_out[-1]!='/':
            opts.path_out.append('/')
        outname = opts.path_out + "%s.json" % pset.Name
    elif opts.output_file is not None and opts_path_out is not None:
        if opts.path_out[-1]!='/':
            opts.path_out.append('/')
        outname = opts.path_out + opts.output_file
    with open(outname,"w") as f:
        json.dump(compress(runs), f, indent = 2)
    print "JSON dumped to file: %s" % outname

