# The following line will change the ntuple type
NTUPLE_TYPE = _ICF_

ROOTSYS_INC=/vols/sl5_exp_software/cms/slc5_amd64_gcc462/lcg/root/5.32.00-cms5/include/
ROOTSYS_LIB=/vols/sl5_exp_software/cms/slc5_amd64_gcc462/lcg/root/5.32.00-cms5/lib/
ROOTSYS_BIN=/vols/sl5_exp_software/cms/slc5_amd64_gcc462/lcg/root/5.32.00-cms5/bin/

PYTHON_INC=/vols/sl5_exp_software/cms/slc5_amd64_gcc462/external/python/2.6.4/include/python2.6/
PYTHON_LIB=-lpython2.6

ROOT_EXTRA_LIBS=-lMathCore -lMathMore -lGenVector
BOOST_PYTHON_LIB=-lboost_python
INCDIR_EXTRA=-I/vols/sl5_exp_software/cms/slc5_amd64_gcc462/external/python/2.6.4/include/python2.6 -I/vols/sl5_exp_software/cms/slc5_amd64_gcc462/external/boost/1.47.0/include
LINK_SEARCH_EXTRA=-L/vols/sl5_exp_software/cms/slc5_amd64_gcc462/external/python/2.6.4/lib -L/vols/sl5_exp_software/cms/slc5_amd64_gcc462/external/boost/1.47.0/lib
PLATFORM=linux
