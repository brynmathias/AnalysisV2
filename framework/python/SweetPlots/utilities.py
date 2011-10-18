import sys
import copy

class PSet:
    _dict={}
    def __init__(self,**kwargs):
        self._dict={}
        for key in kwargs:
            if kwargs[key] is not None:
                self._dict[key]=kwargs[key]

    def __setattr__(self,name,value):
        if not name.startswith("_"):
           if not name in self._dict:
               print "WARNING: Binding variable in PSet ('%s') that is not in base definition." % name
               print "Note that this may well be an error in your script!"
           self._dict[name]=value
        else:
            self.__dict__[name]=value

    def _quiet_set(self,name,value):
        self._dict[name]=value

    def __getattr__(self,name):
        if name in self._dict:
            return self._dict[name]
        else:
            raise AttributeError

    def __contains__(self,item):
        return (item in self._dict)

    def _flatten(self):
        flat={}
        for (key,val) in self._dict.iteritems():
            if val.__class__.__name__== PSet.__name__:
                for (k,v) in val._flatten().iteritems():
                    flat[key+"."+k]=v
            else:
                flat[key]=val
        return flat

    def ps(self):
        pset=ParameterSet()
        for (k,v) in self._flatten().iteritems():
            if v.__class__.__name__=="float":
                pset.AddDouble(k,v)
            elif v.__class__.__name__=="int":
                pset.AddInt(k,v)
            elif v.__class__.__name__=="str":
                pset.AddString(k,v)
            elif v.__class__.__name__=="bool":
                pset.AddBool(k,v)
            elif getattr(v, '__iter__', False):
                # Iterable type
                if not my_any([isinstance(v,t) for t in types.vector_types]):
                    try:
                        v=types.iterable_to_icf_type(v)
                    except TypeError,e:
                        print "Variable %s : %s" % (k,e)
                        raise e
                if isinstance(v,ICF_StringVector):
                    pset.AddStringVector(k,v)
                elif isinstance(v,ICF_DoubleVector):
                    pset.AddDoubleVector(k,v)
                elif isinstance(v,ICF_IntVector):
                    pset.AddIntVector(k,v)
                elif isinstance(v,ICF_BoolVector):
                    pset.AddBoolVector(k,v)
        return pset

    def print_out(self):
        for (k,v) in  self._flatten().iteritems():
            print "%s = %s" % (k,v)

    def copy(self):
        return copy.deepcopy(self)

