#!/usr/bin/env python
import setupSUSY
import samples.QCD_EMBCE_PSet as qcd

# Procedure:
# ==========================
# 0. Get a grid environment and run voms-proxy-init --voms cms
# 1. Edit this file to choose pset and source and dest path (see below)
# 2. Do ./mkfiletransfer.py > fts1.txt (or call it whatever you want)
# 3. Do glite-transfer-submit -s https://lcgfts.gridpp.rl.ac.uk:8443/glite-data-transfer-fts/services/FileTransfer -f fts1.txt
#    This will return a guid (<GUID>)
# 4. Run glite-transfer-status -s https://lcgfts.gridpp.rl.ac.uk:8443/glite-data-transfer-fts/services/FileTransfer <GUID>
# 5. To get verbose status do: glite-transfer-status -lv -s https://lcgfts.gridpp.rl.ac.uk:8443/glite-data-transfer-fts/services/FileTransfer <GUID>

# Configuration:
# ==========================
# This is the pset whose files you wish to copy
ps = qcd.em_20_30
# This is the source path. Leave as is for CASTOR.
source = "srm://srm-cms.cern.ch/srm/managerv2?SFN="
# This is the target path. Currently set to IC DCACHE. Change!
target = "srm://gfe02.grid.hep.ph.ic.ac.uk/srm/managerv2?SFN=/pnfs/hep.ph.ic.ac.uk/data/cms/store/user/"

def filename(s):
    return s.split("/")[-1]

if __name__ == "__main__":
    files_to_transfer = [f for f in ps.File]
    template="%s%s %s%s"
    for f1 in files_to_transfer:
        s = template % (source, f1, target, filename(f1))
	print s    

