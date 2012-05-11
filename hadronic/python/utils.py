#!/usr/bin/env python
import setupSUSY

def readBtagWeight(fname):

    """ Read Btag efficiency fro file and return list of dictionaries"""
    # Parse field named 'name' with value 'v' using type constructor typec
    def readfield(name, v, typec):
        typenames = {float : "float", int : "int"}
        try: return typec(v)
        except ValueError: raise ValueError("Error reading %s from Btag Efficiency file. Value '%r' is not of type %s." %(name, v, typenames[typec]))

    # Check array length matches expected or else error
    def checkLength(arr, length):
        if len(arr) != length:
            print arr
            raise IOError("Error reading Btag Efficiency file. Found %d fields, expected %d." % (len(arr), length))

    out = []
    with open(fname) as xsfile:
      for line in xsfile:
          fields = line.split()
          checkLength(fields, 2)
          #fields[0] contains the GenPt and Eta, fields[1]  The Pt_Eta Efficiency
          pfields = fields[0].split("_",1)[1].split("_") + [fields[1]] 
          checkLength(pfields,3)
          point = {}
          # Parse all the fields into dictionary as float values
          for idx, field in enumerate(["GenPt","GenEta","Pt_Eta_Eff"]):
            f = pfields[idx]
            point[field] = readfield(field,f,float)
          out.append(point)
    return out       


  
def EffToPSet(xs):
    """ Take Btag Efficiency from readBtagweight above and produce PSet for
    compatibility with BtagEfficiencyReweight filter"""
    from icf.core import PSet
    return PSet(
        GenPt = map(lambda x : x["GenPt"], xs),
        GenEta = map(lambda x : x["GenEta"], xs),
        Pt_Eta_Eff = map(lambda x : x["Pt_Eta_Eff"], xs)
        )


if __name__ == "__main__":
    # Example code for reading cross-sections
    xs = readBtagWeight("./Btag_Efficiency_Test.txt")
    ps = EffToPSet(xs)
    for i in range(0,len(ps.GenPt)):
      print "Found GenPt %f GenEta %f Pt_Eta Eff %f" % (ps.GenPt[i],ps.GenEta[i],ps.Pt_Eta_Eff[i])
