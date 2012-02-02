import setupSUSY
import sys
from icf.core import PSet
from icf.types import UIntVector

# This is clever code! ;-)

# Basically we want to load another Python file and monkey patch the modules it
# uses so that it calls our multiEventFilter function below. This allows us to
# easily introspect the list of runs/lumis/events that it creates without having
# to do any weird parsing of the file.

#This fakes an empty package for the sys.modules monkeypatch below.
class FakePackage: pass
# This fakes the module the package is trying to import
class FakeModule:
    def __init__(*args, **kwargs):
        pass
    # The monkeypatched class. We simply create a PSet for feeding the
    # run/ls/event numbers input by the package into our own code
    class multiEventFilter(object):
        @staticmethod
        def clone(EventList=None):
            return PSet(
                Runs = UIntVector([int(x.split(":")[0]) for x in EventList]),
                Lumisections = UIntVector([int(x.split(":")[1]) for x in EventList]),
                Events = UIntVector([int(x.split(":")[2]) for x in EventList])
                )

# Is the specified object a Pset with the required fields (i.e. created by the
# above monkey-patched class)
def isEventList(c):
    return (c.__class__.__name__ == "PSet" and all([getattr(c, x, False) for x in ["Runs", "Lumisections", "Events"]]))

# Import the specified python code, patching the module namespace so that it
# finds the monkey-patch above
def getDeadECALList(pyfile):
    sys.modules["Sandbox"] = FakePackage()
    sys.modules["Sandbox"].Skims = FakePackage()
    sys.modules["Sandbox.Skims"] = FakePackage()
    sys.modules["Sandbox.Skims"].multiEventFilter_cfi = FakeModule()
    sys.modules["Sandbox.Skims.multiEventFilter_cfi"] = FakeModule()
    import imp
    x = imp.load_source("deadECALList", pyfile)
    psets = [ps for k, ps in x.__dict__.iteritems() if isEventList(ps)]
    return psets[0]



