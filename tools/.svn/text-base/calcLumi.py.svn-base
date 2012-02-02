#!/usr/bin/env python
import json
import sys
import os.path
from optparse import OptionParser

if __name__ == "__main__":
    parse = OptionParser(usage="%prog INPUT_FILE [LUMI_INFO_FILE]")
    (opts, args) = parse.parse_args()
    infile = args[0]
    if not os.path.exists(infile):
        print "Input file '%s' not found" % infile
        sys.exit(1)
    if len(args) == 1:
        lumifile = args[0].replace(".json",".lumiinfo.json")
        if not os.path.exists(lumifile):
            print "Couldn't guess lumi_info file name. Please specify"
            sys.exit(1)
    else:
        lumifile = args[1]

    j = json.load(open(lumifile, "r"))
    if "lumi_info" not in j:
        print "File %s doesn't contain lumi_info" % lumifile
        sys.exit(1)
    lumi_info = j["lumi_info"]

    json = json.load(open(infile, "r"))
    delivered = 0
    recorded = 0
    for run, lumis in json.iteritems():
        for a, b in lumis:
            for ls in range(a, b+1):
                lss = str(ls)
                if run in lumi_info and lss in lumi_info[run]:
                    delivered += lumi_info[run][lss]["delivered"]
                    recorded += lumi_info[run][lss]["recorded"]
                else:
                    print "Run: %s, LS: %d not found" % (run, ls)
    print "{0:<10} : {1:<10} pb^-1".format("DELIVERED", delivered/1000000)
    print "{0:<10} : {1:<10} pb^-1".format("RECORDED", recorded/1000000)


