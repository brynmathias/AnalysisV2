from icf.core import PSet


skim_muha_rere=PSet(
	Name="skim_muha_rere",
	Format=("ICF",3),
	File=[
    "/vols/cms01/mstoye/OnelepANSkimsMuon/data_rere.root"
    ],
	Weight=1.0,
)
skim_muha_prom=PSet(
	Name="skim_muha_prom",
	Format=("ICF",3),
	File=[
    "/vols/cms01/mstoye/OnelepANSkimsMuon/data_promt.root"
    ],
	Weight=1.0,
)

wslim =PSet(
	Name="wslim",
	Format=("ICF",3),
	File=[
    "/vols/cms01/mstoye/OnelepANSkimsMuon/w.root"
    ],
	
	CrossSection=31314.,
        Events = 47008773,
)

ttslim =PSet(
	Name="ttslim",
	Format=("ICF",3),
	File=[
    "/vols/cms01/mstoye/OnelepANSkimsMuon/tt.root"
    ],
     	CrossSection=157.5,
        Events = 3701947,
)

zslim =PSet(
	Name="zslim",
	Format=("ICF",3),
	File=[
    "/vols/cms01/mstoye/OnelepANSkimsMuon/z.root"
    ],
        CrossSection=3048., ## NNLO
        Events = 2329439,
)



allskims = [skim_muha_rere,skim_muha_prom]
#allskimMC = [wslim,ttslim]
allskimMC = [zslim,wslim,ttslim]
