#!/usr/bin/env python

# AGB - 07/06/2011 - BkgEvaluation.

import ROOT as R
import math as m
import copy as c

R.gROOT.SetStyle("Plain")
R.gStyle.SetOptStat(0)
R.gStyle.SetOptTitle(1)

HT = ''
hhh = ''
conf = ''
isData = False
rebX = 5
rebY = 5
minP = 0.0001
maxP = 14
Log = True
addLM0 = False
totbin = 3


obs = R.TH1F("obs","obs",6,0,6)
pre = R.TH1F("pre","pre",6,0,6)

channels = ["e-e","#mu-#mu",'#tau-#tau','e-#mu','e-#tau','#mu-#tau']
for i,label in enumerate(channels):
    obs.GetXaxis().SetBinLabel(i+1,label)
    pre.GetXaxis().SetBinLabel(i+1,label)


pre.SetMinimum(minP)
pre.SetMaximum(maxP)

files = {'mudata': R.TFile("Sel_MuHad_Run2011A_PromptReco_v1v2_all.root"), 'eledata' : R.TFile("Sel_ElectronHad_Run2011A_PromptReco_v1v2_all.root"), 'htdata' : R.TFile("Sel_HT_Run2011_promptReco_DCS.root"), 'tauxdata' :  R.TFile("Sel_TauPlusX_Run2011A_PromptReco_v1v2_all.root")}


Sel = 'Selection' + HT
Taunorm = 'TAUNORM' + HT
TauFR = 'TAUFR'

histGoodElFakeTau=files['eledata'].Get(Taunorm+'El').Get('hGoodElFakeTau')
histGoodMuFakeTau=files['mudata'].Get(Taunorm+'Mu').Get('hGoodMuFakeTau')
histGoodTauFakeTau=files['tauxdata'].Get(Taunorm+'Tau').Get('hGoodTauFakeTau')
TauNormHists = [histGoodElFakeTau, histGoodMuFakeTau, histGoodTauFakeTau]

for hist in TauNormHists:
    hist.RebinX(rebX)
    hist.RebinY(rebY)

histIDtau = files['htdata'].Get(TauFR + '/h_IDTau_EtaPt') #this is another way of getting the histogram in a directory dir/hist
histRecotau = files['htdata'].Get(TauFR + '/h_RecoTau_EtaPt')
histIDtau.RebinX(rebX)
histIDtau.RebinY(rebY)
histRecotau.RebinX(rebX)
histRecotau.RebinY(rebY)


mxX = histIDtau.GetNbinsX()
mxY = histIDtau.GetNbinsY()
xmin = histIDtau.GetXaxis().GetXmin()
xmax = histIDtau.GetXaxis().GetXmax()
ymin = histIDtau.GetYaxis().GetXmin()
ymax = histIDtau.GetYaxis().GetXmax()
etawidth = histIDtau.GetXaxis().GetBinWidth(1)
ptwidth = histIDtau.GetYaxis().GetBinWidth(1)

#Some new clone histograms

tau_den = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
tau_num = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
tau_fr = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)

ge_fe = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
fe_fm = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
ge_ft = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
gm_fe = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
gm_fm = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
gm_ft = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)
gt_ft = R.TH2D("","",mxX,xmin,xmax,mxY,ymin,ymax)


for i in range(1, mxX+1):
    for j in range(1, mxY+1):
        taunum = [0,0] #carry the number and the error together
        tauden = [0,0]
        geft = [0,0]
        gmft = [0,0]
        gtft = [0,0]

        #Tau sum
        
        tauden[0] += histRecotau.GetBinContent(i,j) - histIDtau.GetBinContent(i,j)
        tauden[1] += histRecotau.GetBinContent(i,j) - histIDtau.GetBinContent(i,j)
        taunum[0] += histIDtau.GetBinContent(i,j)
        taunum[1] += histIDtau.GetBinContent(i,j)

        
        #Normalisation

        geft[0] += histGoodElFakeTau.GetBinContent(i,j)
        gmft[0] += histGoodMuFakeTau.GetBinContent(i,j)
        gmft[1] += histGoodMuFakeTau.GetBinContent(i,j)
        gtft[0] += histGoodTauFakeTau.GetBinContent(i,j)
        gtft[1] += histGoodTauFakeTau.GetBinContent(i,j)


        #Fill histograms for rate

        tau_den.SetBinContent(i,j,tauden[0])
        tau_den.SetBinError(i,j,m.sqrt(tauden[1]))
        tau_num.SetBinContent(i,j,taunum[0])
        tau_num.SetBinError(i,j,m.sqrt(taunum[1]))

        # print "i, j " + str(taunum) + " " + str(tauden)
        # print "eee " + str(geft) + "  " + str(gmft)

        ge_ft.SetBinContent(i,j,geft[0])
        ge_ft.SetBinError(i,j,m.sqrt(geft[1]))
        gm_ft.SetBinContent(i,j,gmft[0])
        gm_ft.SetBinError(i,j,m.sqrt(gmft[1]))
        gt_ft.SetBinContent(i,j,gtft[0])
        gt_ft.SetBinContent(i,j,m.sqrt(gtft[1]))


# SELECTION


tt = [0,0]
et = [0,0]
mt = [0,0]

histSeltau = files['tauxdata'].Get(Sel + 'Tau/h_RECSTATE')
histSelel = files['eledata'].Get(Sel + 'El/h_RECSTATE')
histSelmu = files['mudata'].Get(Sel + 'Mu/h_RECSTATE')

tt[0] += histSeltau.GetBinContent(3)
tt[1] += histSeltau.GetBinContent(3)
et[0] += histSelel.GetBinContent(5)
et[1] += histSelel.GetBinContent(5)
mt[0] += histSelmu.GetBinContent(6)
mt[1] += histSelmu.GetBinContent(6)


obs.SetBinContent(3,tt[0])
obs.SetBinError(3,m.sqrt(tt[1]))
obs.SetBinContent(5,et[0])
obs.SetBinError(5,m.sqrt(et[1]))
obs.SetBinContent(6,mt[0])
obs.SetBinError(6,m.sqrt(mt[1]))

# Fake Rate plots

tau_fr.Divide(tau_num,tau_den)


bkg = [0,0]
tot = 0

bkgEl = [0,0]
bkgMu = [0,0]
bkgTau = [0,0]


for i in range (1, mxX + 1):
    for j in range (1, mxY+1):
        fr = tau_fr.GetBinContent(i,j)
        NormEl = ge_ft.GetBinContent(i,j)

        if (fr>0 and NormEl > 0):
            relErrFR = tau_fr.GetBinError(i,j)/tau_fr.GetBinContent(i,j)
            relErrNorm = ge_ft.GetBinError(i,j)/ge_ft.GetBinContent(i,j)
            sqRelErr = relErrFR*relErrFR + relErrNorm*relErrNorm
            num = fr*NormEl
            bkgEl[0] += num
            bkgEl[1] += (num*num*sqRelErr)

        NormMu = gm_ft.GetBinContent(i,j)

        if (fr > 0 and NormMu > 0):
            relErrFR = tau_fr.GetBinError(i,j)/tau_fr.GetBinContent(i,j)
            relErrNorm = gm_ft.GetBinError(i,j)/gm_ft.GetBinContent(i,j)
            sqRelErr = (relErrFR*relErrFR) + (relErrNorm*relErrNorm)
            num = fr * NormMu

            bkgMu[0] += num
            bkgMu[1] += (num*num*sqRelErr)


        NormTau = gt_ft.GetBinContent(i,j)

        if (fr > 0 and NormTau > 0):
            relErrFR = tau_fr.GetBinError(i,j)/tau_fr.GetBinContent(i,j)
            relErrNorm = gt_ft.GetBinError(i,j)/gt_ft.GetBinContent(i,j)
            sqRelErr = relErrFR*relErrFR + relErrNorm*relErrNorm
            num = fr * NormTau

            bkgTau[0] += num
            bkgTau[1] += num*num*sqRelErr


print
print
print "Channel E-Tau"
print "Predicted: " + str(bkgEl[0]) + " +/- " + str(m.sqrt(bkgEl[1]))
print "Observed: " + str(obs.GetBinContent(5)) + " +/- " + str(obs.GetBinError(5))
print "Channel Mu-Tau"
print "Predicted: " + str(bkgMu[0]) + " +/- " + str(m.sqrt(bkgMu[1]))
print "Observed: " + str(obs.GetBinContent(6)) + " +/- " + str(obs.GetBinError(6))


pre.SetBinContent(5,bkgEl[0])
pre.SetBinError(5, m.sqrt(bkgEl[1]))
pre.SetBinContent(6, bkgMu[0])
pre.SetBinError(6, m.sqrt(bkgMu[1]))


bkgtautau = 0
bkgtautauplus = 0
bkgtautauminus = 0
totEv = [0,0]

tree = files['tauxdata'].Get(Taunorm + "Tau").Get("theTree")
# tree.SetBranchAddress("weight", weight, b_weight)


entries = tree.GetEntriesFast()

print entries

for i in range(0,entries):
    tree.GetEntry(i)
    weight = c.deepcopy(getattr(tree, "weight"))
    eta1 = c.deepcopy(getattr(tree, "eta1"))
    pt1 = c.deepcopy(getattr(tree, "pt1"))
    eta2 = c.deepcopy(getattr(tree, "eta2"))
    pt2 = c.deepcopy(getattr(tree, "pt2"))

    ie1 = int(m.fabs(eta1)/etawidth) + 1
    if (ie1 > tau_fr.GetNbinsX()):
        ie1 = tau_fr.GetNbinsX()
    ie2 = int(m.fabs(eta2)/etawidth) + 1
    if (ie2 > tau_fr.GetNbinsX()):
        ie2 = tau_fr.GetNbinsX()
    ip1 = int(pt1/ptwidth) + 1
    if (ip1 > tau_fr.GetNbinsY()):
        ip1 = tau_fr.GetNbinsY()
    ip2 = int(pt2/ptwidth) + 1
    if (ip2 > tau_fr.GetNbinsY()):
        ip2 = tau_fr.GetNbinsY()

    totEv[1] += weight*weight
    totEv[0] += weight
    print totEv[0]
    bkgtautau += weight*tau_fr.GetBinContent(ie1,ip1)*tau_fr.GetBinContent(ie2, ip2)
    bkgtautauplus += weight*(tau_fr.GetBinContent(ie1,ip1)+tau_fr.GetBinError(ie1,ip1))*\
                     (tau_fr.GetBinContent(ie2,ip2) + tau_fr.GetBinError(ie2,ip2))
    bkgtautauminus += weight*(tau_fr.GetBinContent(ie1,ip1) - tau_fr.GetBinError(ie1,ip1))*\
                      (tau_fr.GetBinContent(ie2,ip2) - tau_fr.GetBinError(ie2,ip2))


errDiff = m.fabs(bkgtautauplus - bkgtautau)
if (errDiff < m.fabs(bkgtautauminus - bkgtautau)):
    errDiff = m.fabs(bkgtautauminus - bkgtautau)

print totEv

errPP = (m.sqrt(totEv[1])/totEv[0])*bkgtautau
totErr = m.sqrt(errDiff*errDiff + errPP*errPP)



print "Channel Tau-Tau"
print "Predicted: " + str(bkgtautau) + " +/- " + str(totErr)
print "Observed: " + str(obs.GetBinContent(3)) + " +/- " + str(obs.GetBinError(3))

pre.SetBinContent(3,bkgtautau)
pre.SetBinError(3,totErr)


c1 = R.TCanvas("c1","c1",100,100,900,900)
leg = R.TLegend(0.8,0.8,0.9,0.9)
pre.SetTitle(HT)
pre.GetYaxis().SetTitle("Events per channel")

obs.SetMarkerStyle(21)
pre.SetMarkerColor(2)
pre.SetLineColor(2)
pre.SetMarkerStyle(23)

pre.Draw("pe")
obs.Draw("pesame")
leg.AddEntry(obs,"Observed","p")
leg.AddEntry(pre,"Expected","p")
leg.Draw()





            

print
print
print 'Hit ENTER to exit'
raw_input()
