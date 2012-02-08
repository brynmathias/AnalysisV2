#!/bin/tcsh
echo
echo "================================"
echo " Setting up your environment..."
echo "================================"
#-----------------------------------------------------------------------------
# Set your ROOTSYS and PYTHONDIR here
<<<<<<< HEAD
setenv SUSY_WORKING_SW_DIR $HOME/github/SignalScanUpgrade
setenv ROOTSYS '/opt/root'
=======
setenv SUSY_WORKING_SW_DIR /vols/cms04/bm409/git/SMSScans
setenv ROOTSYS '/vols/sl5_exp_software/cms/slc5_amd64_gcc434/lcg/root/5.27.06b-cms14/'
>>>>>>> 61ef08ff9148dfd972c8cf942c47095f2717ce47
setenv MY_PYTHONPATH $SUSY_WORKING_SW_DIR/lib
setenv MY_LD_LIBRARY_PATH /usr/lib/python::$SUSY_WORKING_SW_DIR/lib:$ROOTSYS/lib
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
