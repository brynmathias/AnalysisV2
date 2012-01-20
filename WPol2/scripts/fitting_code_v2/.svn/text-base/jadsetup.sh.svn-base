#!/bin/bash

echo
echo "================================"
echo " Setting up your environment..."
echo "================================"
#-----------------------------------------------------------------------------
# Set your ROOTSYS and PYTHONDIR here
MY_ROOTSYS='/afs/cern.ch/sw/lcg/app/releases/ROOT/5.27.06/slc4_amd64_gcc34/root'
MY_LD_LIBRARY_PATH=$MY_ROOTSYS/lib

export ROOTSYS=$MY_ROOTSYS

echo "-------------------------------------"
echo "ROOTSYS is " $ROOTSYS
echo "====================================="

export PATH=$ROOTSYS/bin:$PATH
export PATH=/afs/cern.ch/sw/packages/external/Python/2.6.5/slc4_amd64_gcc34/bin:$PATH

# Set up LD_LIBRARY_PATH
export LD_LIBRARY_PATH=$MY_LD_LIBRARY_PATH
export LD_LIBRARY_PATH=/afs/cern.ch/sw/packages/external/Python/2.6.5/slc4_amd64_gcc34/lib:$LD_LIBRARY_PATH
echo "LD_LIBRARY_PATH is:" $LD_LIBRARY_PATH

# Set up PYTHONPATH
export PYTHONPATH=$ROOTSYS/lib
echo "PYTHONPATH is:" $PYTHONPATH

echo "====================================="
echo "Set-up complete."
echo "====================================="
echo
