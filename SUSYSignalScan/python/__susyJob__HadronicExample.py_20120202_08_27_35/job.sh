#!/bin/sh
source /vols/cms03/bm409/git/SignalScan/setup.sh
cd /vols/cms03/bm409/git/SignalScan/SUSYSignalScan/python
./HadronicExample.py -j __susyJob__HadronicExample.py_20120202_08_27_35/job.json -J ${SGE_TASK_ID} -S __susyJob__HadronicExample.py_20120202_08_27_35/status/${SGE_TASK_ID}