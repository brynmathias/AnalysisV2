from icf.core import PSet


ele_ptThres_vbtf80 = PSet(
    Name = "highpt_VBTF80",
    D0max = 0.02,
    # =====  VBTF80 =========
    HoverE = PSet(
        Barrel = 0.04,
        Endcap = 99999.
        ),
    DeltaPhi = PSet(
        Barrel = 0.06,
        Endcap = 0.03
        ),
    DeltaEta = PSet(
        Barrel = 0.004,
        Endcap = 0.007
        ),
    SigmaIEtaIEta = PSet(
        Barrel = 0.01,
        Endcap = 0.03
        ),
    #=========================
    ConversionsExtra = PSet(
        DCot = 0.02,
        Dist = 0.02,
        MissingHits = 0
       ),
    
    Isolation = PSet(
       IsoCombSR=0.15,#modified from 0.1   
    ),
  )




muonCuts = PSet(
    NumValidTrackerHits = 10,
    NumValidStandAloneHits = 0,#AGB 21/10/10 - adding this for ssdl. May not be part of official vbtf..
    GlobalNormChi2 = 10.,
    Isolation = PSet(
        IsoCombSR = 0.15,
    ),    
    dxyclosestzvertex = 0.02,    
)

