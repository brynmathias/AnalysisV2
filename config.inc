# The following line will change the ntuple type
NTUPLE_TYPE = _ICF_

ROOTSYS_INC=/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/include/
ROOTSYS_LIB=/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/lib/
ROOTSYS_BIN=/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/bin/

<<<<<<< HEAD
PYTHON_INC=/System/Library/Frameworks/Python.Framework/Versions/2.7/include/python2.7
PYTHON_LIB=-lpython2.7
=======
PYTHON_INC=/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6/
PYTHON_LIB=-lpython2.6
>>>>>>> 9eebf42edd6a04c30832477113669953b24fce4f

ROOT_EXTRA_LIBS=-lMathCore -lMathMore -lGenVector
BOOST_PYTHON_LIB=-lboost_python
INCDIR_EXTRA=-I/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/include/python2.6 -I/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/include
LINK_SEARCH_EXTRA=-L/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/lib -L/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/lib
PLATFORM=linux
