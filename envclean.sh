#!/bin/bash
if [ -z $ROOTSYS ]; then
    echo "No ROOTSYS defined. Doing nothing."
else
    echo "Current ROOTSYS: $ROOTSYS"
    echo "Clearing ROOTSYS variable..."
    unset ROOTSYS
    echo "DONE"
fi
