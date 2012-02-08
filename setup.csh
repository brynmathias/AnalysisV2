#!/bin/tcsh
echo
echo "================================"
echo " Setting up your environment..."
echo "================================"
#-----------------------------------------------------------------------------
# Set your ROOTSYS and PYTHONDIR here
setenv SUSY_WORKING_SW_DIR /vols/cms04/bm409/git/SMSScans
setenv ROOTSYS '/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/'
setenv MY_PYTHONPATH $SUSY_WORKING_SW_DIR/lib
setenv MY_LD_LIBRARY_PATH /usr/lib/python:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/libjpg/8b/lib:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/python/2.6.4-cms14/lib:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/boost/1.44.0-cms3/lib:/vols/grid/ui/3.2.5-0/d-cache/dcap/lib64:/vols/grid/ui/3.2.5-0/d-cache/dcap/lib:/vols/grid/ui/3.2.5-0/glite/lib:/vols/grid/ui/3.2.5-0/glite/lib64:/vols/grid/ui/3.2.5-0/globus/lib:/vols/grid/ui/3.2.5-0/lcg/lib:/vols/grid/ui/3.2.5-0/lcg/lib64:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/gcc/4.3.4/lib64:/vols/sl5_exp_software/cms/slc5_amd64_gcc434/external/xrootd/5.28.00d/lib:$SUSY_WORKING_SW_DIR/lib:$ROOTSYS/lib
#-----------------------------------------------------------------------------
#
#===============
# ROOTSYS setup
#===============
echo "-------------------------------------"
echo "ROOTSYS is " $ROOTSYS
echo "====================================="
#--------------------------------------------               

# Add ROOTSYS/bin to PATH
setenv PATH "${ROOTSYS}/bin:${PATH}"

# Set up LD_LIBRARY_PATH
setenv LD_LIBRARY_PATH $MY_LD_LIBRARY_PATH
echo "LD_LIBRARY_PATH is:" $LD_LIBRARY_PATH

# Set up PYTHONPATH
setenv PYTHONPATH $ROOTSYS/lib:$MY_PYTHONPATH
echo "PYTHONPATH is:" $PYTHONPATH

echo "====================================="
echo "Set-up complete."
echo "====================================="
