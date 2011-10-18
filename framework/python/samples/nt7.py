# NT7 Sample definition file
import setupSUSY
from icf.core import PSet
# MSuGra Signal Samples
lm0=PSet(
    Name="LM0",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM0_229_PATV5_NT7_whyntie.root",
    CrossSection=110.0,
    Format=("NT",7)
)

lm1=PSet(
    Name="LM1",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM1_229_PATV5_NT7_whyntie.root",
    CrossSection=16.06,
    Format=("NT",7)
)

lm2=PSet(
    Name="LM2",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM2_229_PATV5_NT7_whyntie.root",
    CrossSection=2.42,
    Format=("NT",7)
)

lm3=PSet(
    Name="LM3",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM3_229_PATV5_NT7_whyntie.root",
    CrossSection=11.69,
    Format=("NT",7)
)

lm4=PSet(
    Name="LM4",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM4_229_PATV5_NT7_whyntie.root",
    CrossSection=6.70,
    Format=("NT",7)
)

lm5=PSet(
    Name="LM5",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM5_229_PATV5_NT7_whyntie.root",
    CrossSection=1.94,
    Format=("NT",7)
)

lm6=PSet(
    Name="LM6",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM6_229_PATV5_NT7_whyntie.root",
    CrossSection=1.28,
    Format=("NT",7)
)

lm7=PSet(
    Name="LM7",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM7_229_PATV5_NT7_whyntie.root",
    CrossSection=2.90,
    Format=("NT",7)
)

lm8=PSet(
    Name="LM8",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM8_229_PATV5_NT7_whyntie.root",
    CrossSection=2.86,
    Format=("NT",7)
)

lm9=PSet(
    Name="LM9",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM9_229_PATV5_NT7_whyntie.root",
    CrossSection=11.58,
    Format=("NT",7)
)

lm10=PSet(
    Name="LM10",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM10_229_PATV5_NT7_whyntie.root",
    CrossSection=0.065,
    Format=("NT",7)
)

lm11=PSet(
    Name="LM11",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/mSuGra/LM11_229_PATV5_NT7_whyntie.root",
    CrossSection=3.24,
    Format=("NT",7)
)

# Vector boson BG samples
z_inv=PSet(
    Name="Z to Invisible",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/ZtoInv/ZtoInvMG_229_PATV5_NT7_whyntie.root",
    CrossSection=2000.0,
    Format=("NT",7)
)

w_jets_mad=PSet(
    Name="W+Jets Madgraph",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/WJetsMG/WJetsMG_229_PATV5_NT7_whyntie.root",
    CrossSection=40000.0,
    Format=("NT",7)
)

z_jets_mad=PSet(
    Name="Z+Jets Madgraph",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/ZJetsMG/ZJetsMG_229_PATV5_NT7whyntie.root",
    CrossSection=3700.0,
    Format=("NT",7)
)

photon_jets_100_200=PSet(
    Name="Photon+Jets 100 to 200",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/PhoJetMG/PhoJetMG_HT100to200_229_PATV5_NT7_whyntie.root",
    CrossSection=104000.0,
    Format=("NT",7)
)

photon_jets_200_inf=PSet(
    Name="Photon+Jets 200 to inf",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/PhoJetMG/PhoJetMG_HT200toInf_229_PATV5_NT7_whyntie.root",
    CrossSection=11000.0,
    Format=("NT",7)
)

ww=PSet(
    Name="WW",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/PhoJetMG/PhoJetMG_HT200toInf_229_PATV5_NT7_whyntie.root",
    CrossSection=44.8,
    Format=("NT",7)
)

zz=PSet(
    Name="ZZ",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/WWPyth6/WWPyth6_229_PATV5_NT7_whyntie.root",
    CrossSection=44.8,
    Format=("NT",7)
)

# QCD

qcd_mad_100_250=PSet(
    Name="QCD Madgraph 100 to 250",
    File="/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/QCDMG/QCD_MG_HT100to250_229_PATV5_NT7_whyntie.root",
    CrossSection=15000000.0,
    Format=("NT",7)
)

qcd_mad_250_500=PSet(
    Name="QCD Madgraph 250 to 500",
    File="/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD250to500_NT7.root",
    CrossSection=400000.0,
    Format=("NT",7)
)

qcd_mad_500_1000=PSet(
    Name="QCD Madgraph 500 to 1000",
    File="/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD500to1000_NT7.root",
    CrossSection=14000.0,
    Format=("NT",7)
)

qcd_mad_1000_inf=PSet(
    Name="QCD Madgraph 1000 to infinity",
    File="/castor/cern.ch/user/a/arlogb/NT7/QCD/MadQCD1000toInf_NT7.root",
    CrossSection=370.0,
    Format=("NT",7)
)

qcd_pt30=PSet(
    Name = "QCD Pythia Pt 30",
    File = "/castor/cern.ch/user/w/whyntie/susy/samples/fall08/NT7/QCDPyth6/QCD_Pyth6_pt30_229_PATV5_NT7_whyntie.root",
    CrossSection = 109057220.4,
    Format = ("NT",7)
)

qcd_pt80=PSet(
    Name = "QCD Pythia Pt 80",
    File = "/castor/cern.ch/user/z/zph04/NT7/QCD_Pythia_80.root",
    CrossSection = 1934639.6,
    Format = ("NT",7)
)
