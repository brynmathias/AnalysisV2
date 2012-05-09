#!/usr/bin/env python

from ROOT import TH2D,TFile


infile = open("../../textfiles/combined_cross_section_msugra_m0_m12_10_0_1.txt")

d = {
  "m0":[],
  "m12":[],
  "ng":[],
  "ns":[],
  "nn":[],
  "ll":[],
  "sb":[],
  "ss":[],
  "tb":[],
  "bb":[],
  "gg":[],
  "sg":[],
  
}

for f in infile.readlines():

  a = f.split("|")
  if a[1] == " Interactions ":continue
  # print append
  b = a[1].split(",")
  b[1] = b[1].replace("m0 = ","")
  b[1] = b[1].replace(" m12 = ",",")
  b[1] = b[1].replace(" ","")
  d["m0"].append(int(b[1].split(",")[0]))
  d["m12"].append(int(b[1].split(",")[1]))
  d["ng"].append(a[2])
  d["ns"].append(a[3])
  d["nn"].append(a[4])
  d["ll"].append(a[5])
  d["sb"].append(a[6])
  d["ss"].append(a[7])
  d["tb"].append(a[8])
  d["bb"].append(a[9])
  d["gg"].append(a[10])
  d["sg"].append(a[11])



# print min(d["m0"]),max(d["m0"]),min(d["m12"]),max(d["m12"]),d["m12"][1]-d["m12"][0]


xsecFile = TFile("./NLOCrossSections.root",'RECREATE')
hists = []
for subProcess in ["ng","ns","nn","ll","sb","ss","tb","bb","gg","sg"]:
  for num,vary in enumerate(["_central","_scaleUp","_scaleDown"]):
    hist = TH2D( subProcess+"%s"%(vary),"%s;m0;m12"%(subProcess+vary),150,0.,3000.,50,0.,1000.)
    for xsec,m0,m12 in zip(d[subProcess],d["m0"],d["m12"]):
      xsec = xsec.split(",")
       # print xsec[num],bin
      bin = hist.FindBin(m0,m12)
      # if float(xsec[num].replace(" ","")) < 1E-10: print bin, float(xsec[num].replace(" ",""))
      # if m0 == 1510:#if float(xsec[num].replace(" ","")) > 0.:
      hist.SetBinContent(bin,float(xsec[num].replace(" ","")))
      # else:hist.SetBinContent(bin,0.)
    hists.append(hist)

xsecFile.cd()
xsecFile.Write()
xsecFile.Close()