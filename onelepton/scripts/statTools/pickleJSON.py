#!/usr/bin/env python
import json, cPickle, sys, os.path

if __name__ == "__main__":
    json_name = (sys.argv[1])
    print "Loading JSON file..."
    jdict = json.load(open(json_name))
    pickle_name = "".join(json_name.split(".")[:-1])+".pkl"
    if os.path.exists(pickle_name):
        print "Output file %s exists" % pickle_name
        sys.exit(1)
    print "Dumping pickle file..."
    p = cPickle.Pickler(open(pickle_name,"wb"))
    p.fast = True
    p.dump(jdict)
