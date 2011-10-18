from icf.core import PSet

# -----------------------------------------------------------------------------
# LMx

#path_lmx="/castor/cern.ch/user/a/arlogb/7TeV/V00-08-04-04_Ntuples/LMx/"
path_lmx="/nfs/data6/trommers/ICFNtuple/"


mSuGraScanTANB10=PSet(
    Name="mSuGraScanTANB10",
    File=path_lmx+"mSuGra_TanB10/SusyCAF_Tree_TANB10.root",
   # File=path_lmx+"LM0_7TeV_V00-08-04-04.root",
  #  File=path_lmx+"SusyCAF_Tree_67_1.root",
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


# -----------------------------------------------------------------------------
# QCD Pythia
path_qcd_pythia_merged="/nfs/data6/trommers/ICFNtuple/"
#path_v_jets="/castor/cern.ch/user/j/jad/ICFNtuples7TeV_take2/"
#path_qcd_pythia_merged="/castor/cern.ch/user/b/bainbrid/7TeV/V00-08-04-XX/"

qcd_pythia_merged=PSet(
    Name="QCD_Pythia_Merged",
    Format=("ICF",2),
    File=path_qcd_pythia_merged+"QCDPythia_7TeV_V00-08-04-XX_Skim.root",
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
# V+Jets

path_v_jets="/nfs/data6/trommers/ICFNtuple/"
#path_v_jets="/castor/cern.ch/user/j/jad/ICFNtuples7TeV_take2/"

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

path_z_inv="/nfs/data6/trommers/ICFNtuple/"

z_inv=PSet(
    Name="Zinv",
    File=path_z_inv+"Zinv_7TeV_V00-08-04-XX.root",
    CrossSection=4500.,
    Format=("ICF",2),
    )
