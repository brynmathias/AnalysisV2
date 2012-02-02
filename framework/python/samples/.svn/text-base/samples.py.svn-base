from icf.core import PSet

# -----------------------------------------------------------------------------
# QCD Pythia

path_qcd_pythia_merged="/castor/cern.ch/user/b/bainbrid/7TeV/V00-08-04-XX/"

qcd_pythia_merged=PSet(
    Name="QCD_Pythia_Merged",
    Format=("ICF",2),
    File=path_qcd_pythia_merged+"QCDPythia_7TeV_V00-08-04-XX.root",
    Weights = PSet(
    CrossSection = [ 8.762e+08, 6.041e+07, 9.238e+05, 2.547e+04, 1.256e+03, 8.798e+01, 2.186e+00, 1.122e-02 ],
    Events       = [ 6246300,   5228992,   3203440,   3132800,   3274202,   2143390,   2143921,   1184123   ],
    PtBin        = [ 15.,       30.,       80.,       170.,      300.,      470.,      800.,      1400.     ],
    ),
)

path_qcd_pythia="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/"

qcd_pythia_15=PSet(
    Name="QCD_Pythia_15",
    File=path_qcd_pythia+"QCDJets_Pythia_15.root",
    CrossSection=8.762e+08,
    Format=("ICF",2),
)

qcd_pythia_30=PSet(
    Name="QCD_Pythia_30",
    File=path_qcd_pythia+"QCDJets_Pythia_30.root",
    CrossSection=6.041e+07,
    Format=("ICF",2),
)

qcd_pythia_80=PSet(
    Name="QCD_Pythia_80",
    File=path_qcd_pythia+"QCDJets_Pythia_80.root", 
    CrossSection=9.238e+05,
    Format=("ICF",2),
)

qcd_pythia_170=PSet(
    Name="QCD_Pythia_170",
    File=path_qcd_pythia+"QCDJets_Pythia_170.root",
    CrossSection=2.547e+04,
    Format=("ICF",2),
)

qcd_pythia_300=PSet(
    Name="QCD_Pythia_300",
    File=path_qcd_pythia+"QCDJets_Pythia_300.root",
    CrossSection=1.256e+03,
    Format=("ICF",2),
)

qcd_pythia_470=PSet(
    Name="QCD_Pythia_470",
    File=path_qcd_pythia+"QCDJets_Pythia_470.root",
    CrossSection=8.798e+01,
    Format=("ICF",2),
)

qcd_pythia_800=PSet(
    Name="QCD_Pythia_800",
    File=path_qcd_pythia+"QCDJets_Pythia_800.root",
    CrossSection=2.186e+00,
    Format=("ICF",2),
)

qcd_pythia_1400=PSet(
    Name="QCD_Pythia_1400",
    File=path_qcd_pythia+"QCDJets_Pythia_1400.root",
    CrossSection=1.122e-02,
    Format=("ICF",2),
)

qcd_pythia_all=PSet(
    Name="QCD_Pythia_All",
    Format=("ICF",2),
    File=[ qcd_pythia_15.File,
           qcd_pythia_30.File,
           qcd_pythia_80.File,
           qcd_pythia_170.File,
           qcd_pythia_300.File,
           qcd_pythia_470.File,
           qcd_pythia_800.File,
           qcd_pythia_1400.File ],
    Weights = PSet(
    CrossSection = [ 8.762e+08, 6.041e+07, 9.238e+05, 2.547e+04, 1.256e+03, 8.798e+01, 2.186e+00, 1.122e-02 ],
    Events       = [ 6246300,   5228992,   3203440,   3132800,   3274202,   2143390,   2143921,   1184123   ],
    PtBin        = [ 15.,       30.,       80.,       170.,      300.,      470.,      800.,      1400.     ],
    ),
)

qcd_pythia=[
    qcd_pythia_15,
    qcd_pythia_30,
    qcd_pythia_80,
    qcd_pythia_170,
    qcd_pythia_300,
    qcd_pythia_470,
    qcd_pythia_800,
    qcd_pythia_1400
]

# -----------------------------------------------------------------------------
# QCD EM Enriched

QCD_EMenriched_20to30=PSet(
    Name="QCD_EMenriched_20to30",
    File="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/QCD_EMenriched_20to30.root",
    CrossSection=171915.0,
    Format=("ICF",2)
)

QCD_EMenriched_30to80=PSet(
    Name="QCD_EMenriched_30to80",
    File="/castor/cern.ch/user/z/zph04/7TeV/QCD_EMenriched_30to80_upto620.root",
    CrossSection=349870.0,
    Format=("ICF",2)
)

QCD_EMenriched_80to170=PSet(
    Name="QCD_EMenriched_80to170",
    File="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/QCD_EMenriched_80to170.root",
    CrossSection=13408.8,
    Format=("ICF",2)
)

# -----------------------------------------------------------------------------
# QCD BCtoE 

QCD_BCtoE_20to30=PSet(
    Name="QCD_BCtoE_20to30",
    File="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/QCD_BCtoE_20to30.root",
    CrossSection=10833.0,
    Format=("ICF",2)
)

QCD_BCtoE_30to80=PSet(
    Name="QCD_BCtoE_30to80",
    File="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/QCD_BCtoE_30to80.root",
    CrossSection=13876.2,
    Format=("ICF",2)
)

QCD_BCtoE_80to170=PSet(
    Name="QCD_BCtoE_80to170",
    File="/castor/cern.ch/user/z/zph04/7TeV/V00-08-04-04/QCD_BCtoE_80to170.root",
    CrossSection=942.24,
    Format=("ICF",2)
)

# -----------------------------------------------------------------------------
# VV or Vg 

WW=PSet(
    Name="WW",
    File="/castor/cern.ch/user/p/pioppi/susy/7TeV/V00-08-04-XX/SusyCAF_WW.root",
    CrossSection=28.0,
    Format=("ICF",2)
)

WZ=PSet(
    Name="WZ",
    File="/castor/cern.ch/user/p/pioppi/susy/7TeV/V00-08-04-XX/SusyCAF_WZ.root",
    CrossSection=10.5,
    Format=("ICF",2)
)

Wg=PSet(
    Name="Wg",
    File="/castor/cern.ch/user/p/pioppi/susy/7TeV/V00-08-04-XX/SusyCAF_Wg.root",
    CrossSection=23.2,
    Format=("ICF",2)
)

ZZ=PSet(
    Name="ZZ",
    File="/castor/cern.ch/user/p/pioppi/susy/7TeV/V00-08-04-XX/SusyCAF_ZZ.root",
    CrossSection=4.3,
    Format=("ICF",2)
)

Zg=PSet(
    Name="Zg",
    File="/castor/cern.ch/user/p/pioppi/susy/7TeV/V00-08-04-XX/SusyCAF_Zg.root",
    CrossSection=7.3,
    Format=("ICF",2)
)

# -----------------------------------------------------------------------------
# Photon+Jets Pythia

#path_photonjet_pythia_merged="/castor/cern.ch/user/r/rnandi/7TeV/V00-08-04-04/"

path_photonjet_pythia="/castor/cern.ch/user/r/rnandi/7TeV/V00-08-04-04/"

photonjet_pythia_15=PSet(
    Name="PhotonJet_Pt15",
    File=path_photonjet_pythia+"PhotonJet_Pt15.root",
    CrossSection=1.922e+05, 
    Format=("ICF",2),
)

photonjet_pythia_30=PSet(
    Name="PhotonJet_Pt30",
    File=path_photonjet_pythia+"PhotonJet_Pt30.root",
    CrossSection=2.007e+04,
    Format=("ICF",2),
)

photonjet_pythia_80=PSet(
    Name="PhotonJet_Pt80",
    File=path_photonjet_pythia+"PhotonJet_Pt80.root",
    CrossSection=5.565e+02,
    Format=("ICF",2),
)

photonjet_pythia_170=PSet(
    Name="PhotonJet_Pt170",
    File=path_photonjet_pythia+"PhotonJet_Pt170.root",
    CrossSection=2.437e+01,
    Format=("ICF",2),
)

photonjet_pythia_300=PSet(
    Name="PhotonJet_Pt300",
    File=path_photonjet_pythia+"PhotonJet_Pt300.root",
    CrossSection=1.636e+00,
    Format=("ICF",2),
)

photonjet_pythia_470=PSet(
    Name="PhotonJet_Pt470",
    File=path_photonjet_pythia+"PhotonJet_Pt470.root",
    CrossSection=1.360e-01,
    Format=("ICF",2),
)

photonjet_pythia_800=PSet(
    Name="PhotonJet_Pt800",
    File=path_photonjet_pythia+"PhotonJet_Pt800.root",
    CrossSection=3.477e-03,
    Format=("ICF",2),
)

photonjet_pythia_1400=PSet(
    Name="PhotonJet_Pt1400",
    File=path_photonjet_pythia+"PhotonJet_Pt1400.root",
    CrossSection=1.286e-05,
    Format=("ICF",2),
)

photonjet_pythia_2200=PSet(
    Name="PhotonJet_Pt2200",
    File=path_photonjet_pythia+"PhotonJet_Pt2200.root",
    CrossSection=4.035e-09,
    Format=("ICF",2),
)

photonjet_pythia_3000=PSet(
    Name="PhotonJet_Pt3000",
    File=path_photonjet_pythia+"PhotonJet_Pt3000.root",
    CrossSection=1.779e-14,
    Format=("ICF",2),
)

photonjet_pythia_all=PSet(
    Name="PhotonJet_Pythia_All",
    Format=("ICF",2),
    File=[ photonjet_pythia_15.File,
           photonjet_pythia_30.File,
           photonjet_pythia_80.File,
           photonjet_pythia_170.File,
           photonjet_pythia_300.File,
           photonjet_pythia_470.File,
           photonjet_pythia_800.File,
           photonjet_pythia_1400.File,
           photonjet_pythia_2200.File,
           photonjet_pythia_3000.File ],
    Weights = PSet(
    CrossSection = [ 1.922e+05, 2.007e+04, 5.565e+02, 2.437e+01, 1.636e+00, 1.360e-01, 3.477e-03, 1.286e-05, 4.035e-09, 1.779e-14 ],
    Events       = [ 1224470,   1040987,   1160027,   1111320,   1033582,   1092104,   1071680,   1214590,   1102715,   1186200   ],
    PtBin        = [ 15.,       30.,       80.,       170.,      300.,      470.,      800.,      1400.,     2200.,     3000.     ],
    ),
)

photonjet_pythia=[
    photonjet_pythia_15,
    photonjet_pythia_30,
    photonjet_pythia_80,
    photonjet_pythia_170,
    photonjet_pythia_300,
    photonjet_pythia_470,
    photonjet_pythia_800,
    photonjet_pythia_1400,
    photonjet_pythia_2200,
    photonjet_pythia_3000
]

# -----------------------------------------------------------------------------
# V+Jets

path_v_jets="/castor/cern.ch/user/j/jad/ICFNtuples7TeV_take2/"

w_jets=PSet(
    Name="WJets",
    File=path_v_jets+"WJets-madgraph_ICFv2.root",
    CrossSection=24170.,
    Format=("ICF",2),
)

z_jets=PSet(
    Name="ZJets",
    File=path_v_jets+"ZJets-madgraph_ICFv2.root",
    CrossSection=2400.,
    Format=("ICF",2),
)

ttbar_jets=PSet(
    Name="TTbarJets",
    File=path_v_jets+"TTbarJets-madgraph_ICFv2.root",
    CrossSection=95.,
    Format=("ICF",2),
)

path_z_inv="/castor/cern.ch/user/b/bainbrid/7TeV/V00-08-04-XX/"

z_inv=PSet(
    Name="Zinv",
    File=path_z_inv+"Zinv_7TeV_V00-08-04-XX.root",
    CrossSection=4500.,
    Format=("ICF",2),
)

# -----------------------------------------------------------------------------
# LMx

path_lmx="/castor/cern.ch/user/a/arlogb/7TeV/V00-08-04-04_Ntuples/LMx/"

lm0=PSet(
    Name="LM0",
    File=path_lmx+"LM0_7TeV_V00-08-04-04.root",
    CrossSection=38.93,
    Format=("ICF",2),
)

lm1=PSet(
    Name="LM1",
    File=path_lmx+"LM1_7TeV_V00-08-04-04.root",
    CrossSection=4.888,
    Format=("ICF",2),
)

lm2=PSet(
    Name="LM2",
    File=path_lmx+"LM2_7TeV_V00-08-04-04.root",
    CrossSection=0.6027,
    Format=("ICF",2),
)

lm3=PSet(
    Name="LM3",
    File=path_lmx+"LM3_7TeV_V00-08-04-04.root",
    CrossSection=3.438,
    Format=("ICF",2),
)

lm4=PSet(
    Name="LM4",
    File=path_lmx+"LM4_7TeV_V00-08-04-04.root",
    CrossSection=1.879,
    Format=("ICF",2),
)

lm5=PSet(
    Name="LM5",
    File=path_lmx+"LM5_7TeV_V00-08-04-04.root",
    CrossSection=0.4734,
    Format=("ICF",2),
)

lm6=PSet(
    Name="LM6",
    File=path_lmx+"LM6_7TeV_V00-08-04-04.root",
    CrossSection=0.3104,
    Format=("ICF",2),
)

lm7=PSet(
    Name="LM7",
    File=path_lmx+"LM7_7TeV_V00-08-04-04.root",
    CrossSection=1.209,
    Format=("ICF",2),
)

lm8=PSet(
    Name="LM8",
    File=path_lmx+"LM8_7TeV_V00-08-04-04.root",
    CrossSection=0.7300,
    Format=("ICF",2),
)

lm9=PSet(
    Name="LM9",
    File=path_lmx+"LM9_7TeV_V00-08-04-04.root",
    CrossSection=7.134,
    Format=("ICF",2),
)

lm10=PSet(
    Name="LM10",
    File=path_lmx+"LM10_7TeV_V00-08-04-04.root",
    CrossSection=0.04778,
    Format=("ICF",2),
)

lm11=PSet(
    Name="LM11",
    File=path_lmx+"LM11_7TeV_V00-08-04-04.root",
    CrossSection=0.8236,
    Format=("ICF",2),
)

lm12=PSet(
    Name="LM12",
    File=path_lmx+"LM12_7TeV_V00-08-04-04.root",
    CrossSection=4.414,
    Format=("ICF",2),
)

lm13=PSet(
    Name="LM13",
    File=path_lmx+"LM13_7TeV_V00-08-04-04.root",
    CrossSection=6.899,
    Format=("ICF",2),
)
