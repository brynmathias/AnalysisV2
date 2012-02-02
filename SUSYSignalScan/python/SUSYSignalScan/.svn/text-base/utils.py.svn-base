import setupSUSY

def readLOXS(fname):
    """ Read LO cross-sections from file and return list of dictionaries"""

    # Parse field named 'name' with value 'v' using type constructor typec
    def readfield(name, v, typec):
        typenames = {float : "float", int : "int"}
        try: return typec(v)
        except ValueError: raise ValueError("Error reading %s from xsection file. Value '%r' is not of type %s." %(name, v, typenames[typec]))

    # Check array length matches expected or else error
    def checkLength(arr, length):
        if len(arr) != length:
            print arr
            raise IOError("Error reading xsection file. Found %d fields, expected %d." % (len(arr), length))


    out = []
    with open(fname) as xsfile:
        for line in xsfile:
            fields = line.split()
            checkLength(fields, 2)
            # fields[1] is the LO cross-section, fields[0] contains everything
            # else
            pfields = fields[0].split(".")[0].split("_") + [fields[1]]
            checkLength(pfields, 7)
            point = {}
            # Parse all the fields into dictionary as float values
            for idx, field in enumerate(["m0", "m1/2", "tanbeta", "A0", "sign(mu)", "loxs"]):
                f= pfields[idx+1]
                if f[0] == "m":  f = "-"+f[1:]
                point[field] = readfield(field, f, float)
            out.append(point)
    return out

def readKFactors(fname):
    """ Parse k-factors text file in fname and return list of dictionaries (one
    dictionary for each point). No attempt at type conversion is made
    (i.e. everything is a stripped string)"""
    header = None
    records = []
    for line in open(fname):
        # The format is fairly WTF. Basically everything is separated with
        # |. The first field contains a load of parameters (m0, m1/2 etc). These
        # are key=value pairs separated by commas.

        # First get the fields split by pipes
        fields = line.split('|')
        # Dictionary to store output for this (m0, m1/2...) point
        pdict = {}
        # The first line contains a list of all the processes. Save this for
        # later and skip the line.
        if header is None:
            header = [f.strip().rstrip() for f in fields[1:-1]]
            continue

        # The first field contains comma-separated list of params
        point_fields = fields[1].split(",")

        # The scale= parameter has parentheses around it. If we find this split
        # the parenthetical bit off as a separate field
        if "(" in point_fields[0]:
            pfield = point_fields[0]
            bracket = pfield[pfield.find("(")+1:pfield.find(")")]
            point_fields[0] = pfield[pfield.find(")")+1:]
            point_fields.append(bracket)

        # Loop through remaining parameters treating them as key=value pairs
        for pfield in point_fields:
            keyval = pfield.split("=")
            if len(keyval) == 2:
                pdict[keyval[0].strip().rstrip()] = keyval[1].strip().rstrip()
        # Parse the remaining | separated fields out and store them keyed by the
        # process name.
        for idx, f in enumerate(fields[2:-1]):
            pdict[header[idx+1]] = f.strip().rstrip()
        records.append(pdict)
    # Return process names and points
    return header[1:], records

def xsToPSet(xs):
    """ Take LO cross-sections from readLOXS above and produce PSet for
    compatibility with SignalScanLOCrossSectionWeighting filter"""
    from icf.core import PSet
    return PSet(
        M0 = map(lambda x : x["m0"], xs),
        M12 = map(lambda x : x["m1/2"], xs),
        tanbeta = map(lambda x: x["tanbeta"], xs),
        loxs = map(lambda x : x["loxs"], xs)
        )

def kfactorsToPSet(processes, kfactors):
    """ Take process-dependent cross-sections from readKFactors above and
    produce PSet compatible with mSuGraPlottingOps"""
    from icf.core import PSet
    procs = dict([(k, []) for k in processes])
    ps = PSet(
        M0 = [],
        M12 = [],
        **procs)
    for rec in kfactors:
        ps.M0 += [float(rec["m0"])]
        ps.M12 += [float(rec["m1/2"])]
        for p in processes:
            getattr(ps, p).append(float(rec[p]))
    return ps



if __name__ == "__main__":
    # Example code for reading kfactors
    processes, kfactors = readKFactors("../../textfiles/scale_xsection_nlo1.0_tanssdat10.txt")
    ps = kfactorsToPSet(processes, kfactors)
    print "Found %d kfactor points" % len(ps.M0)

    # Example code for reading cross-sections
    xs = readLOXS("../../textfiles/goodModelNames_10_0_1.txt")
    ps = xsToPSet(xs)
    print "Found %d cross-sections" % len(ps.M0)

    # Example code for creating the weight filter
    try:
        from libSUSYSignalScan import SignalScanLOCrossSectionWeighting
        weight = SignalScanLOCrossSectionWeighting(ps.ps())
    except ImportError:
        print "Can't find module!"
        print "Build SUSYSignalScan package"

