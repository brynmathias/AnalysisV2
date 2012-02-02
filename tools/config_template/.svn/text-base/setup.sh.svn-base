#!/bin/bash
echo
echo "================================"
echo " Setting up your environment..."
echo "================================"
#-----------------------------------------------------------------------------
# Set your ROOTSYS and PYTHONDIR here
export SUSY_WORKING_SW_DIR=TMP_BASE_DIR
MY_ROOTSYS='TMP_ROOT_SYS'
MY_PYTHONPATH=$SUSY_WORKING_SW_DIR/lib
MY_LD_LIBRARY_PATH=$MY_ROOTSYS/lib:TMP_LD_PATH_EXTRA:$SUSY_WORKING_SW_DIR/lib
TMP_PYTHON_ENV
#-----------------------------------------------------------------------------
#
#===============
# ROOTSYS setup
#===============
#if [ -z $ROOTSYS ]; then
#    echo "No ROOTSYS defined!"
export ROOTSYS=$MY_ROOTSYS
#else
#    echo "ROOTSYS already defined."
#fi
echo "-------------------------------------"
echo "ROOTSYS is " $ROOTSYS
echo "====================================="
#--------------------------------------------
#
#=================
# PYTHONDIR setup
#=================
#if [ -z $PYTHONDIR ]; then
#    echo "No PYTHONDIR defined!"
#    export PYTHONDIR=$MY_PYTHONDIR
#else
#    echo "PYTHONDIR already defined."
#fi
#echo "-------------------------------------"
#echo "PYTHONDIR is " $PYTHONDIR
#echo "====================================="
#--------------------------------------------
#
#
# Set up PATH
#=============
# Check PATH for /root/bin, add it if it isn't there
#----------------------------------------------------
#PATH_HAS_ROOT=$(echo $PATH | grep /root/bin)
#if [ -z $PATH_HAS_ROOT ]; then
    #echo "PATH does not have /root/bin."
    export PATH=$ROOTSYS/bin:$PATH
#else
#    echo "PATH already has a /root/bin"
#fi
# Check PATH for /Python/<version>/bin
#PATH_HAS_PYTHON=$(echo $PATH | grep /Python/2.5.4/slc4_amd64_gcc34/bin)
#if [ -z $PATH_HAS_PYTHON ]; then
#    echo "PATH does not have /Python/2.5.4/slc4_amd64_gcc34/bin"
#    export PATH=$PYTHONDIR/bin:$PATH
#else
#    echo "PATH already has a /Python/2.5.4/slc4_amd64_gcc34/bin"
#fi
#echo "-------------------------------------"
#echo "PATH is: " $PATH
#echo "====================================="
#echo
#

# Set up LD_LIBRARY_PATH
export TMP_LDPATH_VAR=$MY_LD_LIBRARY_PATH
echo "TMP_LDPATH_VAR is:" $LD_LIBRARY_PATH

# Set up PYTHONPATH
export PYTHONPATH=$ROOTSYS/lib:$MY_PYTHONPATH
echo "PYTHONPATH is:" $PYTHONPATH

#echo "Generating fresh documentation with doxygen"
#doxygen Doxy_config

echo "====================================="
echo "Set-up complete."
echo "====================================="
echo
