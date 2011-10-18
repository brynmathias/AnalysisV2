#!/usr/bin/env python
import glob
import sys
import subprocess
import os.path
import shutil
from optparse import OptionParser
import os

def hadd(outfile, infiles, force=False):
    try:
        args = ["hadd"]
        if force: args.append("-f")
        args.append(outfile)
        args.extend(infiles)
        subprocess.check_call(args)
    except subprocess.CalledProcessError:
        print "Hadd failed"

def check_gaps(numbers):
    if len(numbers) <= 1: return True
    numbers.sort()
    for i, n in enumerate(numbers[1:]):
        if n != numbers[i] + 1:
            return False
    return True

if __name__ == "__main__":
    parse = OptionParser()
    parse.add_option("-l", "--lonely",
                     action="store_true", default = False,
                     help="Move lonely files")
    parse.add_option("-f", "--force",
                     action="store_true", default = False,
                     help="Don't prompt for overwrites.")
    parse.add_option("-c", "--cleanup",
                     action="store_true", default = False,
                     help="Cleanup files")
    (opts, args) = parse.parse_args()
    if len(args) < 1:
        print "Too few arguments"
        sys.exit(1)
    for d in args:
        print "Processing dir %s" % d
        flist = glob.glob("%s/*.root" % d)
        fmap = {}
        ignored = {}
        for f in flist:
            try:
                n = int(f.split("_")[-1].split(".")[0])
                fname = f[:f.rfind("_")]+".root"
                if fname in fmap:
                    fmap[fname].append((n, f))
                else:
                    fmap[fname] = [(n, f)]
            except ValueError:
                pass

        print "Schedule"
        print "-"*80
        for k, v in fmap.iteritems():
            if len(v) > 1:
                print "HADD %d files\n\t-> %s" % (len(v), k)
                if not check_gaps([x[0] for x in v]):
                    print "GAPS"
            elif len(v) == 1 and opts.lonely:
                print "COPY %s\n\t-> %s" % (v[0][1], k)
            if opts.cleanup:
                print "DELETE %d files" % len(v)
        print

        if raw_input("proceed? ") == "y":
            for k, v in fmap.iteritems():
                if len(v) == 1:
                    if not os.path.exists(k) or (opts.force or raw_input("Overwrite '%s'? " % k) == "y"):
                        print "\n>> copy %s %s\n" % (k, v[0][1])
                        shutil.copy(v[0][1], k)
                else:
                    force = os.path.exists(k)
                    if os.path.exists(k) and not (opts.force or raw_input("Overwrite '%s'? " % k) == "y"): continue
                    print "\n>> hadd %s\n" % k
                    hadd(k, [x[1] for x in v], force)
                if opts.cleanup:
                    for infile in v:
                        print ">> rm %s" % infile[1]
                        os.unlink(infile[1])



