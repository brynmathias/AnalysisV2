from icf.core import PSet


PhotonJet_AllPtBins_7TeV_Pythia=PSet(
Name="PhotonJet_AllPtBins_7TeV_Pythia",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt15.root",
"/vols/cms02/rnandi/PhotonJet_Pt30.root",
"/vols/cms02/rnandi/PhotonJet_Pt80.root",
"/vols/cms02/rnandi/PhotonJet_Pt170.root",
"/vols/cms02/rnandi/PhotonJet_Pt300.root",
"/vols/cms02/rnandi/PhotonJet_Pt470.root",
"/vols/cms02/rnandi/PhotonJet_Pt800.root",
"/vols/cms02/rnandi/PhotonJet_Pt1400.root",
),
Weights = PSet(
    CrossSection = [ 1.922e+05, 2.007e+04, 5.565e+02, 2.437e+01, 1.636e+00, 1.360e-01, 3.477e-03, 1.286e-05 ],#, 4.035e-09, 1.779e-14 ],
    Events       = [ 1223390,   1026794,   1187711,   939400,    1024266,   1091179,   1065640,   1291025   ],#, 1093562,   1189440   ],
    PtBin        = [ 15.,       30.,       80.,       170.,      300.,      470.,      800.,      1400.     ],#, 2200.,     3000.     ],
  )
)

PhotonJet_Pt15_7TeV_Pythia=PSet(
Name="PhotonJet_Pt15_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt15.root",
),
Weights=PSet(
    CrossSection=1.922e+05,
    Events=1223390,
    PtBin=15.,
    )
)

PhotonJet_Pt30_7TeV_Pythia=PSet(
Name="PhotonJet_Pt30_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt30.root",
),
Weights=PSet(
    CrossSection=2.007e+04,
    Events=1026794,
    PtBin=30.,
    )
)

PhotonJet_Pt80_7TeV_Pythia=PSet(
Name="PhotonJet_Pt80_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt80.root",
),
Weights=PSet(
    CrossSection=5.565e+02,
    Events=1187711,
    PtBin=80.,
    )
)

PhotonJet_Pt170_7TeV_Pythia=PSet(
Name="PhotonJet_Pt170_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt170.root",
),
Weights=PSet(
    CrossSection=2.437e+01,
    Events=939400,
    PtBin=170.,
    )
)

PhotonJet_Pt300_7TeV_Pythia=PSet(
Name="PhotonJet_Pt300_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt300.root",
),
Weights=PSet(
    CrossSection=1.636e+00,
    Events=1024266,
    PtBin=300.,
    )
)

PhotonJet_Pt470_7TeV_Pythia=PSet(
Name="PhotonJet_Pt470_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt470.root",
),
Weights=PSet(
    CrossSection=1.360e-01,
    Events=1091179,
    PtBin=470.,
    )
)

PhotonJet_Pt800_7TeV_Pythia=PSet(
Name="PhotonJet_Pt800_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt800.root",
),
Weights=PSet(
    CrossSection=3.477e-03,
    Events=1065640,
    PtBin=800.,
    )
)

PhotonJet_Pt1400_7TeV_Pythia=PSet(
Name="PhotonJet_Pt1400_7TeV_Pythia6",
Format=("ICF",2),
File=(
"/vols/cms02/rnandi/PhotonJet_Pt1400.root",
),
Weights=PSet(
    CrossSection=1.286e-05,
    Events=1291025,
    PtBin=1400.,
    )
)
