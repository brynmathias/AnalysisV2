#!/usr/bin/bash
voms-proxy-init -voms cms -hours 130
source ../../setup.sh


./Data.py -b -n25
./McJESminus.py -b -n50
./McJESplus.py -b -n50
./McNoSmear.py -b -n50
./McSmeared.py -b -n50

./Data37.py -b -n25
./McJESminus37.py -b -n50
./McJESplus37.py -b -n50
./McNoSmear37.py -b -n50
./McSmeared37.py -b -n50

./Data43.py -b -n25
./McJESminus43.py -b -n50
./McJESplus43.py -b -n50
./McNoSmear43.py -b -n50
./McSmeared43.py -b -n50
# ./Data.py -l
# ./McJESetaPlus.py -l
# ./McJESetaMinus.py -l
# ./McJESminus.py -l
# ./McJESplus.py -l
# ./McNoSmear.py -l
# ./McSmeared.py -l
