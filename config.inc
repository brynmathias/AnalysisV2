# The following line will change the ntuple type
NTUPLE_TYPE = _ICF_

ROOTSYS_INC=$(ROOTSYS)/include
ROOTSYS_LIB=$(ROOTSYS)/lib
ROOTSYS_BIN=$(ROOTSYS)/bin

<<<<<<< HEAD
PYTHON_INC=/System/Library/Frameworks/Python.Framework/Versions/2.7/include/python2.7
PYTHON_LIB=-lpython2.7
=======
<<<<<<< HEAD
PYTHON_INC=/System/Library/Frameworks/Python.Framework/Versions/2.7/include/python2.7
PYTHON_LIB=-lpython2.7
=======
PYTHON_INC=/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6/
PYTHON_LIB=-lpython2.6
>>>>>>> 9eebf42edd6a04c30832477113669953b24fce4f
>>>>>>> 6ae7b4b51e89f07b27889c761f3039fa4118bdaa

ROOT_EXTRA_LIBS=-lMathCore -lMathMore -lGenVector
BOOST_PYTHON_LIB=-lboost_python-mt
INCDIR_EXTRA=-I/opt/local/include
LINK_SEARCH_EXTRA=-L/opt/local/lib
PLATFORM=__APPLE__
