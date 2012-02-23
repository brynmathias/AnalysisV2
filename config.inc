# The following line will change the ntuple type
NTUPLE_TYPE = _ICF_

ROOTSYS_INC=$(ROOTSYS)/include
ROOTSYS_LIB=$(ROOTSYS)/lib
ROOTSYS_BIN=$(ROOTSYS)/bin

PYTHON_INC=/System/Library/Frameworks/Python.Framework/Versions/2.7/include/python2.7
PYTHON_LIB=-lpython2.7

ROOT_EXTRA_LIBS=-lMathCore -lMathMore -lGenVector
BOOST_PYTHON_LIB=-lboost_python-mt
INCDIR_EXTRA=-I/opt/local/include
LINK_SEARCH_EXTRA=-L/opt/local/lib
PLATFORM=__APPLE__
