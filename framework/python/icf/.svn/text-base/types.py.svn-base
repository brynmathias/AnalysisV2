from libFrameworkSUSY import *

def iterable_homogeneous(iterable):
    first_class_name=None
    for i in iterable:
        if first_class_name is None:
            first_class_name=i.__class__.__name__
        else:
            if i.__class__.__name__ != first_class_name:
                raise TypeError("Iterable contains various types: %s and %s" % (first_class_name,
                                                                                i.__class__.__name__))


def StringVector(iterable):
    i=ICF_StringVector()
    i.extend(list(iterable))
    return i

def DoubleVector(iterable):
    i=ICF_DoubleVector()
    i.extend(list(iterable))
    return i

def IntVector(iterable):
    i=ICF_IntVector()
    i.extend(list(iterable))
    return i

def UIntVector(iterable):
    i = ICF_UIntVector()
    i.extend(list(iterable))
    return i

def LongIntVector(iterable):
    i=ICF_LongIntVector()
    i.extend(list(iterable))
    return i

def BoolVector(iterable):
    i=ICF_BoolVector()
    i.extend(list(iterable))
    return i

vector_types=[ICF_StringVector, ICF_DoubleVector, ICF_IntVector, ICF_UIntVector, ICF_LongIntVector, ICF_BoolVector]

def iterable_to_icf_type(iterable):
    l=list(iterable)
    if len(l)==0:
        raise IndexError("Cannot infer iterable type from empty sequence")
    else:
        if l[0].__class__.__name__=="str":
            return StringVector(iterable)
        elif l[0].__class__.__name__ in ["int", "long"]:
            try:
                return IntVector(iterable)
            except OverflowError:
                print "[WARNING] Iterable in PSet overflows C int type. Converting to long instead."
                print "[WARNING] NOTE: This may not be what you want to happen! Either:"
                print "\tb) You do want to use a long type -> ensure your C++ accepts long."
                print "\t\tTo supress this message, use LongIntVector explicitly from icf.types."
                print "\ta) You want to use an usigned int instead -> use UIntVector from icf.types"
                print "\tc) You are sure you want to use a signed integer type"
                print "\t\t-> Check your PSet for errors since one of the values is too large."
                try: return LongIntVector(iterable) # If a C int is too small, try long
                except OverflowError: raise Exception("List contains value that cannot be represented by an integer type on your machine.")
        elif l[0].__class__.__name__=="float":
            return DoubleVector(iterable)
        elif l[0].__class__.__name__=="bool":
            return BoolVector(iterable)
        else:
            raise TypeError("Unsupported iterable type: %s" % l[0].__class__.__name__)
