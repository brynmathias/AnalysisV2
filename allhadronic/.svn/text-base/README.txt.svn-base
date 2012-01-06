

4)

Tag RB110427
===========
svn co svn+ssh://bainbrid@svn.cern.ch/reps/icfsusy/tags/RB110427/AnalysisV2 SUSY2

Synchronisation exercise with Ted to obtain same yields in 250 (19
events), 300 (7 events) and 350 (6 events) HT bins from 2011 data
(17/pb certified). 

3)

Tags RB110106_1 and RB110420
===========
svn co svn+ssh://bainbrid@svn.cern.ch/reps/icfsusy/tags/RB110106_1/AnalysisV2 SUSY2
svn co svn+ssh://bainbrid@svn.cern.ch/reps/icfsusy/tags/RB110420/AnalysisV2 SUSY2

These tags are used to validate the switch from the branch RB110106,
used for the 2010 paper, to the trunk. 

Tag RB110106_1 is based on the branch and uses hadronic/python/qcdBkgdEst_orig_cfg.py
Tag RB110420 is based on the trunk and uses both: hadronic/python/qcdBkgdEst_orig_cfg.py
                                                  allhadronic/python/original_cfg.py

REQUIRED: change _ICF_ to _ICF2_ in config.inc before sourcing setup.sh

The three configs allow to cross-check the port from the branch to the
trunk. They all give identical results for both data (2010,35/pb) and
MC (QCD Madgraph), with the following caveats/conditions:
- no residual JECs are used (due to diff method b/w trunk and branch)
- 2<nJets<10
- nbadcells=0
- cleaning cuts used in the denom
- usual 2010 event selection, incl. aT cut of 0.55

Gives the following yields in HT bins: 
      250<HT<300    43
      300<HT<350     9
      >350	    14

2)

Branch RB110325
===========
svn co svn+ssh://bainbrid@svn.cern.ch/reps/icfsusy/branches/RB110325/AnalysisV2 SUSY2

Contains first implementation of new, cleaner code base in allhadronic/.
Contains validation against the existing code in the MAIN branch of hadronic/. 
Python scripts used are original_cfg.py (2010) and validation_cfg.py (new). 
Validated using 100k events from LM1 MC. 

1)

Branch RB110106
===========
svn co svn+ssh://bainbrid@svn.cern.ch/reps/icfsusy/branches/RB110106/AnalysisV2 SUSY2

Contains analysis code and scripts for 2010 paper, all found in hadronic/.
Plus some additional changes since concerning the Moriond PAS and AN.

Gives the following yields in HT bins: 
      250<HT<300    33
      300<HT<350    11
      >350	    14
