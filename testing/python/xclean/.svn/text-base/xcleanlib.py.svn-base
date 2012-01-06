from libxcleantest import *
import math
from ROOT import *

def lorentz_add(a,b):
    return TLorentzVector(a.Px()+b.Px(),
                          a.Py()+b.Py(),
                          a.Pz()+b.Pz(),
                          a.E()+b.E())
def deltar(a,b):
    return ((a.Eta()-b.Eta())**2 + (a.Phi()-b.Phi())**2)**0.5

def ptetaphiet_to_e(pt,eta,phi,et):
    return (et/pt)*( (pt*math.cos(phi))**2 +
                     (pt*math.sin(phi))**2 +
                     (pt*math.sinh(eta))**2 )**0.5

class XClean:
    def __init__(self,ps):
        self.jets=[]
        self.electrons=[]
        self.muons=[]
        self.photons=[]
        self.jet_idx=0
        self.muon_idx=0
        self.electron_idx=0
        self.jet_filter=JetFilter(ps.Jets.EtCut,ps.Jets.EtaCut)
        self.muon_filter=LeptonFilter(ps.Muons.PtCut,ps.Muons.EtaCut)
        self.electron_filter=LeptonFilter(ps.Electrons.PtCut,
                                          ps.Electrons.EtaCut)
        self.photon_filter=PhotonFilter(ps.Photons.EtCut,
                                        ps.Photons.EtaCut)
        self.ps=ps.copy()
        # Initialise the CloneVectors
        self.ccjets=JetVector()
        self.ccmuons=LeptonVector()
        self.ccelectrons=LeptonVector()
        self.ccphotons=PhotonVector()

    @staticmethod
    def PtEtaPhiEtoXYZT(pt,eta,phi,e):
        return (abs(pt)*math.cos(phi),
                abs(pt)*math.sin(phi),
                abs(pt)*math.sinh(eta),
                e)

    def AddJet(self,pt,eta,phi,e,emfrac):
        (x,y,z,t)=self.PtEtaPhiEtoXYZT(pt,eta,phi,e)
        j=Jet(x,y,z,t,emfrac,self.jet_idx)
        self.jets.append(("UNPROCESSED",j))
        self.jet_idx+=1

    def AddMuon(self,pt,eta,phi,e,charge,trkiso,ecaliso,hcaliso,loose_id,
                tight_id):
        (x,y,z,t)=self.PtEtaPhiEtoXYZT(pt,eta,phi,e)
        mu=Lepton(x,y,z,t,charge,trkiso,ecaliso,hcaliso,loose_id,
                  tight_id,2,self.muon_idx)
        self.muons.append(("UNPROCESSED",mu))
        self.muon_idx+=1

    def AddElectron(self,pt,eta,phi,e,charge,trkiso,ecaliso,hcaliso,loose_id,
                    tight_id):
        (x,y,z,t)=self.PtEtaPhiEtoXYZT(pt,eta,phi,e)
        el=Lepton(x,y,z,t,charge,trkiso,ecaliso,hcaliso,loose_id,
                  tight_id,1,self.electron_idx)
        self.electrons.append(("UNPROCESSED",el))
        self.electron_idx+=1

    def Clean(self,Prefilter=True,Resolve=True,Execute=True):
        # prefilter
        if Prefilter:
            # pre filter jets
            i=0
            for (state,j) in self.jets:
                if self.jet_filter.Filter(j):
                    self.ccjets.append(j)
                else:
                    self.ccjets.append(None)
                    self.jets[i]=("CUT",j)
                i+=1
            # pre flter muons
            i=0
            for (state,mu) in self.muons:
                if self.muon_filter.Filter(mu):
                    self.ccmuons.append(mu)
                else:
                    self.ccmuons.append(None)
                    self.muons[i]=("CUT",mu)
                i+=1
            # pre filter electrons
            i=0
            for (state,el) in self.electrons:
                if self.electron_filter.Filter(el):
                    self.ccelectrons.append(el)
                else:
                    self.ccelectrons.append(None)
                    self.electrons[i]=("CUT",el)
                i+=1
        xc=CrossCleaner(self.ps.MuonJet,
                        self.ps.Muons.TrkIsoCut,
                        self.ps.Muons.CombIsoCut,
                        self.ps.ElectronJet,
                        self.ps.Electrons.TrkIsoCut,
                        self.ps.Electrons.CombIsoCut,
                        self.ps.PhotonJet,
                        self.ps.Photons.IDReq,
                        self.ccjets,
                        self.ccmuons,
                        self.ccelectrons,
                        self.ccphotons,
                        self.ps.Verbose)
        xc.Clean()
        if Resolve:
            xc.Resolve()
        if Execute:
            xc.Execute()
        for i in range(len(self.ccjets)):
            j=self.ccjets[i]
            if j is not None:
                self.jets[i]=("PASS",j)
            else:
                if self.jets[i][0]=="CUT":
                    continue
                else:
                    self.jets[i]=("FAIL",self.jets[i][1])

        for i in range(len(self.ccmuons)):
            mu=self.ccmuons[i]
            if mu is not None:
                self.muons[i]=("PASS",mu)
            else:
                if self.muons[i][0]=="CUT":
                    continue
                else:
                    self.muons[i]=("FAIL",self.muons[i][1])

        for i in range(len(self.ccelectrons)):
            el=self.ccelectrons[i]
            if el is not None:
                self.electrons[i]=("PASS",el)
            else:
                if self.electrons[i][0]=="CUT":
                    continue
                else:
                    self.electrons[i]=("FAIL",self.electrons[i][1])
        #xc.Clear()
    def Clear(self):
        self.jets=[]
        self.muons=[]
        self.electrons=[]
        self.photons=[]
        self.ccjets.Clear()
        self.ccmuons.Clear()
        self.ccelectrons.Clear()
        self.ccphotons.Clear()
        self.electron_idx=0
        self.muon_idx=0
        self.jet_idx=0
