#!/usr/bin/env python
import subprocess as sub
import sys
import json
from optparse import OptionParser
import os

cmds_setup ="""
source /home/hep/dbauer/cms_setup.sh
mkdir ICF_LUMI
cd ICF_LUMI
cmsrel %(cmssw)s
cd %(cmssw)s/src/
cvs co -r V02-01-03 RecoLuminosity/LumiDB
cd RecoLuminosity/LumiDB
scramv1 b
cmsenv
cd scripts
"""

cmds_run = """
source /home/hep/dbauer/cms_setup.sh
cd ICF_LUMI/%(cmssw)s/src/
cmsenv
cd -
./ICF_LUMI/%(cmssw)s/src/RecoLuminosity/LumiDB/scripts/lumiCalc.py -i %(json_file)s %(command)s
"""

if __name__ == "__main__":
    parse = OptionParser(usage = "%prog [OPTIONS] JSON_FILE")
    parse.add_option("-u", "--username",
                     action="store", type="string", default = os.environ["USER"],
                     help="Username @CERN.CH for kinit")
    parse.add_option("-c", "--cmssw-version",
                     action="store", type="string", default = "CMSSW_4_1_2",
                     help="CMSSW Version for lumiCalc script")
    parse.add_option("-r", "--refresh-env",
                     action="store_true", default = False,
                     help="Reinitialise if directory already exists")
    parse.add_option("-o", "--output-file",
                      action="store", type="string",
                      default=None, help="Output file path (default: <input>.lumiinfo.json)")
    parse.add_option("-s", '--summary',
                     action='store_true', default = False,
                     help='Get lumi summary')
    (opts, args) = parse.parse_args()
    fname = args[0]
    cmd_opts = {"cmssw":opts.cmssw_version,
                "json_file":fname}
    dir_exists = os.path.exists("ICF_LUMI/%(cmssw)s/src/RecoLuminosity/LumiDB/scripts" % cmd_opts)
    if opts.summary:
        cmd_opts["command"] = "overview"
    else:
        cmd_opts["command"] = "lumibyls"
    if not dir_exists or opts.refresh_env:
        if opts.refresh_env:
            shutil.rmtree("ICF_LUMI/%(cmssw)s" % cmd_opts)
        try:
            sub.check_call(["kinit", "%s@CERN.CH" % opts.username])
            sub.check_call(cmds_setup % cmd_opts,
                           shell=True)
        except sub.CalledProcessError,e:
            print "Error setting up environment"
            print "Perhaps AFS username != IC username? Supply -u option."
            sys.exit(1)
    print "Fetching lumi info..."
    if opts.summary:
        p = sub.Popen(cmds_run % cmd_opts, shell=True)
        p.wait()
        sys.exit(0)
    p = sub.Popen(cmds_run % cmd_opts, shell=True, stdout=sub.PIPE)
    (out, err) = p.communicate()
    print "Done."

    info = {}
    for l in out.split("\n"):
        if len(l) and l[0] == "|":
            fields_ = l.split("|")
            fields = []
            for f in fields_:
                s = f.strip().rstrip()
                if len(s): fields.append(s)
            print fields
            if len(fields) != 4: continue
            try:
                run = int(fields[0])
                ls = int(fields[1])
                delivered = float(fields[2])
                recorded = float(fields[3])
                if not run in info:
                    info[run] = {}
                info[run][ls] = {"delivered":delivered, "recorded":recorded}

            except ValueError:
                continue
    print "Writing to JSON file: %(json_file)s" % cmd_opts
    with open(fname.replace(".json",".lumiinfo.json"), "w") as j:
        json.dump({"lumi_info":info}, j, indent=1)

