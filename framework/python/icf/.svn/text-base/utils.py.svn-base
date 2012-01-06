import os.path

def local_ntuple(arr,path,error=False):
    for i in arr:
        tmp=i.File.split("/")
        if not path[-1:] == "/":
            path+="/"
        newpath = path + tmp[len(tmp)-1]
        if os.path.exists(newpath):
            print "Using local version of %s" % i.Name
            i._quiet_set("File",path+tmp[len(tmp) - 1])
        else:
            if error:
                raise NameError("Cannot file local file: %s" % newpath)

def reweight(arr,val):
     print "Weighting to %d pb^-1" % val
     for i in arr:
         i._quiet_set("Reweight",val)

def switch_ntuple(arr, map_fname, error=False):
    import csv
    mapf = csv.reader(open(map_fname), delimiter=',', quotechar='|')
    for s in arr:
        path=None
        for row in mapf:
            if row[0] == s.Name:
                path=row[1]
                break
        if path is None:
            if error: raise ValueError("Entry not found in %s for %s" % (map_fname, s.Name))
        else:
            if os.path.exists(path):
                   s._quiet_set("File",path)
            else:
                if error: raise ValueError("File %s does not exist" % path)


def json_to_pset(fname, debug=False):
    """ Takes an input json file and converts to a PSet suitable for use in analysis code."""
    try:
        import json as j
    except ImportError:
        print "json_to_pset: JSON module not found. python >= 2.6 required."
        sys.exit(1)
    import core as c
    import sys

    def expand_lumis(lumis):
        return sum([range(l[0], l[1]+1) for l in lumis], [])

    def pretty_lumis(lumis):
        return ", ".join(["%d-%d" % (l[0], l[1]) for l in lumis])

    def check_lumis(lumis):
        try:
            return (all([len(l)==2 for l in lumis]) and
                    all([l[1] >= l[0] for l in lumis]))
        except:
            return False

    with open(fname, "r") as f:
        try:
            json_dict = j.load(f)
        except ValueError:
            print "json_to_pset: Malformed JSON file: %s" % fname
            sys.exit(1)

        p = c.PSet()
        run_list = []
        debug_str = []
        for run, lumis in json_dict.iteritems():
            if not check_lumis(lumis):
                print "json_to_pset: Invalid JSON format in file: %s" % fname
                sys.exit(1)
            debug_str.append("Run %s : %s" % (run, pretty_lumis(lumis)))
            p._quiet_set(run.encode("ascii", "ignore"), expand_lumis(lumis))
            run_list.append(run.encode("ascii", "ignore"))
        p._quiet_set("runs", run_list)
        if debug:
            print ">"*80
            print "JSON Filter: %s" % fname
            print ">"*80
            print "\n".join(debug_str)
            print ">"*80
        return p.ps()

def autoname(path, create_dirs=True, time_fmt = "%Y%m%d_%H_%M_%S", **kwargs):
    import time, os
    args = kwargs
    if time_fmt:
        args["time"] = time.strftime(time_fmt)
    path = path % args
    if create_dirs:
        try: os.makedirs(path)
        except: pass
    print "[autoname] %s" % path
    return path





