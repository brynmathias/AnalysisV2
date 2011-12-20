from icf.core import PSet
import glob

zjets_madgraph_vols=PSet(
Name="zjets_madgraph_vols",
CrossSection=3048.0, #normalised to 1/pb (7TeV) = 24.0
Events=1084921,
Format=("ICF",2),
File= glob.glob("/vols/cms02/jm1103/ZJetsMadgraphJune2010/ZJets_madgraph_june2010_*.root"),
)

zjets_madgraph=PSet(
Name="zjets_madgraph",
File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_1.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_5.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_6.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_8.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_9.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_10.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_07_05_22_43_20//ZJets_madgraph_june2010_11.root"],
CrossSection=3048.0, #normalised to 1/pb (7TeV) = 24.0
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)


#Z+jets madgraph sample, re-ntuplised with newest muon ID
zjets_madgraph_newmuonid=PSet(
Name="zjets_madgraph_newmuonid",
File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_29_1_Fo8.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_50_1_SMD.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_45_2_pkH.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_37_1_4Am.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_47_1_WeK.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_13_1_0Fv.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_6_1_b5L.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_25_1_PZM.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_8_1_0JN.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_36_1_TS2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_48_1_TVf.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_52_1_2Z8.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_41_1_Idp.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_4_1_Ov8.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_10_1_pHl.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_26_1_cJD.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_7_1_AF0.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_19_1_T0z.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_28_1_P5C.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_38_1_LAE.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_31_1_Qy3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_40_1_mjQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_42_1_HG7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_20_1_Ht5.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_14_1_Tjt.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_30_1_KTe.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_23_1_hfl.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_18_1_BQI.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_11_1_XHP.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_17_1_MJR.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_24_1_N7m.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_12_1_dO6.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_51_1_8T6.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_39_1_qxJ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_49_1_zre.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_54_1_s5t.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_33_1_bAw.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_44_1_x2u.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_16_1_XIy.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_32_1_74l.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_53_1_CiS.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_27_1_Xf3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_43_1_4dE.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_2_1_bWg.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_15_1_R5f.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_1_1_5RZ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_34_1_sRC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_3_1_0Py.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_46_1_81T.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_5_1_J4Y.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_22_1_d43.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_21_1_27k.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_9_1_ZeO.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_35_1_iYk.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/peruzzi/ICF/automated/2011_01_25_16_21_35/SusyCAF_Tree_55_1_ZG3.root"
],
CrossSection=3048.0, #normalised to 1/pb (7TeV) = 24.0
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)

