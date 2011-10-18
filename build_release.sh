#!/bin/bash

NUM_CORES=5

source setup.sh
make -C framework -f Release -j${NUM_CORES} clean
make -C framework -f Release -j${NUM_CORES}
make -C test -f Release -j${NUM_CORES} clean
make -C test -f Release -j${NUM_CORES}
