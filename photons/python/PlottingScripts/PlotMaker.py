from samples import * 
from histos import *
from SweetPlots.plotter import DoPlotting

#samples = [QCD_Madgraph_Selected, GJets_Madgraph_Selected, Madgraph_Selected, Data]
#out_folder = "plots/DataMC-Madgraph/" 
#samples = [QCD_Pythia6_Selected, G_Pythia6_Selected, Pythia6_Selected, Data]
#out_folder = "plots/DataMC-Pythia6/" 
#samples = [Madgraph_Control, Madgraph_Selected]
#out_folder = "plots/SeleAnti-Madgraph/"
#samples = [Pythia6_Control, Pythia6_Selected]
#out_folder = "plots/SeleAnti-Pythia6/"
#samples = [QCD_Madgraph_Selected, GJets_Madgraph_Selected]
#out_folder = "plots/FakePrompt-Madgraph/"
samples = [QCD_Pythia6_Selected, G_Pythia6_Selected]
out_folder = "plots/FakePrompt-Pythia6/"
#samples = [QCD_Pythia6_Selected, G_Pythia6_Selected_Reweighted]
#out_folder = "plots/FakePrompt-Pythia6-Reweighted/"
#samples = [Data_Control, Data_Selected]
#out_folder = "plots/SeleAnti-Data/" 
histograms = [
  BiasedDeltaPhi_1, BiasedDeltaPhi_2, BiasedDeltaPhi_3, BiasedDeltaPhi_all,
  HT_1, HT_2, HT_3, HT_all,
  MHT_1, MHT_2, MHT_3, MHT_all,
  Meff_1, Meff_2, Meff_3, Meff_all,
  MHToverHT_1, MHToverHT_2, MHToverHT_3, MHToverHT_all,
  pfMET_1, pfMET_2, pfMET_3, pfMET_all,
  tcMET_1, tcMET_2, tcMET_3, tcMET_all,
  ak5CaloMET_1, ak5CaloMET_2, ak5CaloMET_3, ak5CaloMET_all,
  PhotonPt_1, PhotonPt_2, PhotonPt_3, PhotonPt_all,
  PhotonEta_1, PhotonEta_2, PhotonEta_3, PhotonEta_all,
  PhotonEcalIso_1, PhotonEcalIso_2, PhotonEcalIso_3, PhotonEcalIso_all,
  PhotonHcalIso_1, PhotonHcalIso_2, PhotonHcalIso_3, PhotonHcalIso_all,
  PhotonTrackIso_1, PhotonTrackIso_2, PhotonTrackIso_3, PhotonTrackIso_all,
  PhotonHoverE_1, PhotonHoverE_2, PhotonHoverE_3, PhotonHoverE_all,
  PhotonR9_1, PhotonR9_2, PhotonR9_3, PhotonR9_all,
  PhotonSigmaIetaIeta_1, PhotonSigmaIetaIeta_2, PhotonSigmaIetaIeta_3, PhotonSigmaIetaIeta_all,
  PhotonHasPixelSeed_1, PhotonHasPixelSeed_2, PhotonHasPixelSeed_3, PhotonHasPixelSeed_all,
  #PhotonMETdPhi_1, PhotonMETdPhi_2, PhotonMETdPhi_3, PhotonMETdPhi_all,
  Jet1Pt_1, Jet1Pt_2, Jet1Pt_3, Jet1Pt_all,
  Jet1Eta_1, Jet1Eta_2, Jet1Eta_3, Jet1Eta_all,
  Jet1EmFrac_1, Jet1EmFrac_2, Jet1EmFrac_3, Jet1EmFrac_all,
  Jet2Pt_1, Jet2Pt_2, Jet2Pt_3, Jet2Pt_all,
  Jet2Eta_1, Jet2Eta_2, Jet2Eta_3, Jet2Eta_all,
  Jet2EmFrac_1, Jet2EmFrac_2, Jet2EmFrac_3, Jet2EmFrac_all
]
files_folder = "../../results/Calo_ra3tight_geq3jets_"
formats = [".png",".eps"]
DoPlotting([samples, histograms, files_folder, out_folder, formats])
