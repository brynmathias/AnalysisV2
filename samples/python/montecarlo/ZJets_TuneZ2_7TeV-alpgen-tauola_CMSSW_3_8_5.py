from icf.core import PSet

# Z{0,1,2,3,4,5}Jets_TuneZ2_7TeV-alpgen-tauola samples
# CMSSW 3_8_5
# datasets: /Z3Jets_ptZ-0to100_TuneZ2_7TeV-alpgen-tauola/Fall10-START38_V12-v1/GEN-SIM-RECO and friends
# susycaf  V14-01-04
# addpkg PhysicsTools/Configuration V00-08-05
# addpkg CommonTools/RecoAlgos CMSSW_3_8_5
# addpkg ElectroWeakAnalysis/WENu V00-02-01
# addpkg RecoEgamma/ElectronIdentification V00-03-13
# cvs up -r V00-02-15 CommonTools/RecoAlgos/plugins/HBHENoiseFilterResultProducer.cc
# cvs up -r V00-02-15 CommonTools/RecoAlgos/python/HBHENoiseFilterResultProducer_cfi.py
# cvs up -r V00-02-15 CommonTools/RecoAlgos/BuildFile
# cvs co -r V02-3_6_0 -d MyAnalysis/IsolationTools/ UserCode/emanuele/MyAnalysis/IsolationTools/ 

# only the most important ones are listed here; for other (smaller) channels, see database

Z0Jets_TuneZ2_7TeV_alpgen_tauola=PSet(
Name="Z0Jets_TuneZ2_7TeV_alpgen_tauola",
File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_46_1_Gg1.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_33_1_PYA.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_71_1_zMV.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_1_1_Dac.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_14_1_Fl5.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_43_1_ZOs.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_30_1_URf.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_60_1_BIM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_7_1_qa4.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_35_1_zn9.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_34_1_kjW.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_10_1_AIM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_12_1_NEl.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_50_1_oX7.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_64_1_iL2.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_69_1_tLC.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_47_1_aj3.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_9_1_PlO.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_48_1_IwC.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_37_1_CYg.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_31_1_RkM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_2_1_VMo.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_42_1_Kav.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_68_1_9Xe.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_73_1_I96.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_6_1_BlH.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_53_1_ekq.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_28_1_7KC.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_54_1_CB5.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_39_1_SA3.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_58_1_Dvh.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_25_1_eUQ.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_44_1_o4N.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_11_1_NNP.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_62_1_6LA.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_52_1_CBc.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_27_1_qsi.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_24_1_BMu.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_51_1_qPa.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_23_1_zMv.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_36_1_GSN.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_19_1_OSp.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_63_1_8tN.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_8_1_nmF.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_22_1_14k.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_40_1_gwN.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_17_1_sZI.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_13_1_9jP.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_41_1_f7L.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_21_1_rcG.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_4_1_qle.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_16_1_6Wi.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_66_1_O6R.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_59_1_pZi.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_55_1_glq.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_15_1_9lv.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_70_1_evZ.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_56_1_Jzn.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_20_1_qXq.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_61_1_DF0.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_5_1_kv8.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_32_1_Oc7.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_38_1_AIg.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_49_1_22U.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_18_1_oTt.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_65_1_bUp.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_29_1_EDM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_72_1_o3T.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_3_1_k13.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_45_1_JDC.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_74_1_Tqh.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_57_1_6xt.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_26_1_Nqs.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_19_45_11/SusyCAF_Tree_67_1_6jS.root"
],
CrossSection=1929.0, #I guess it's LO, for 100/pb.
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)

Z1Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola=PSet(
Name="Z1Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola",
File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_4_1_Cs3.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_3_1_b4c.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_2_1_5EJ.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_6_1_Bny.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_11_1_YCJ.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_9_1_doF.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_10_1_M94.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_17_1_1Uq.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_8_1_06J.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_15_1_MLY.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_12_1_5CD.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_13_1_yoU.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_16_1_LUM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_18_1_YAz.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_14_1_oLL.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_1_1_JJT.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_5_1_x1U.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_7_1_wy8.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_42_47/SusyCAF_Tree_19_1_2Xd.root"
],
CrossSection=380.8, #I guess it's LO, for 100/pb.
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)

Z2Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola=PSet(
Name="Z2Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola",
File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_3_1_LVN.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_8_1_EAM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_6_1_dBq.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_2_1_m7V.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_5_1_KLF.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_1_1_AA1.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_9_1_xyk.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_4_1_VDD.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_46_11/SusyCAF_Tree_7_1_6vS.root"
],
CrossSection=103.5, #I guess it's LO, for 100/pb.
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)


Z3Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola=PSet(
Name="Z3Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola",
File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_16_44_19/SusyCAF_Tree_1_1_kJ8.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_16_44_19/SusyCAF_Tree_5_1_Y8Y.root"
],
CrossSection=22.89, #I guess it's LO, for 100/pb.
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)

Z4Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola=PSet(
    Name="Z4Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola",
    File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_51_40/SusyCAF_Tree_4_1_OAP.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_51_40/SusyCAF_Tree_2_1_3RT.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_51_40/SusyCAF_Tree_1_1_Ve0.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_51_40/SusyCAF_Tree_3_1_nAU.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_51_40/SusyCAF_Tree_5_1_qdW.root"
    ],
    CrossSection=4.61, #I guess it's LO, for 100/pb.
    Format=("ICF",2),
    FirstEntry=0,
    LastEntry=0
    )

Z5Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola=PSet(
        Name="Z5Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola",
            File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_54_18/SusyCAF_Tree_3_1_bD9.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_54_18/SusyCAF_Tree_1_1_MKo.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_54_18/SusyCAF_Tree_4_1_DYM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_54_18/SusyCAF_Tree_2_1_Udn.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_15_21_54_18/SusyCAF_Tree_5_1_AuU.root"
        ],
            CrossSection=1.13, #I guess it's LO, for 100/pb.
            Format=("ICF",2),
            FirstEntry=0,
            LastEntry=0
            )


Z1Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola=PSet(
Name="Z1Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola",
File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_12_1_mWb.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_14_1_sl2.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_1_1_Dtx.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_5_1_xCI.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_2_1_OWM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_7_1_aGt.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_4_1_UkA.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_3_1_IAK.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_9_1_fpB.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_10_1_sK0.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_13_1_YEw.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_15_1_nwj.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_11_1_VAJ.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_6_1_JcE.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_16_1_7o0.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_28_03/SusyCAF_Tree_8_1_jbu.root"
],
CrossSection=8.72, #I guess it's LO, for 100/pb.
Format=("ICF",2),
FirstEntry=0,
LastEntry=0
)

Z2Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola=PSet(
    Name="Z2Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola",
    File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_16_49_00/SusyCAF_Tree_4_1_8ZV.root"
    ],
    CrossSection=8.53, #I guess it's LO, for 100/pb.
    Format=("ICF",2),
    FirstEntry=0,
    LastEntry=0
    )

Z3Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola=PSet(
        Name="Z3Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola",
            File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_40_49/SusyCAF_Tree_3_1_arc.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_40_49/SusyCAF_Tree_2_1_Jwg.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_40_49/SusyCAF_Tree_4_1_e4V.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_40_49/SusyCAF_Tree_5_1_rvM.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_40_49/SusyCAF_Tree_1_1_lBI.root"
        ],
            CrossSection=3.95, #I guess it's LO, for 100/pb.
            Format=("ICF",2),
            FirstEntry=0,
            LastEntry=0
            )

Z4Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola=PSet(
        Name="Z4Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola",
            File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_43_32/SusyCAF_Tree_1_1_qUJ.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_43_32/SusyCAF_Tree_3_1_XLC.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_43_32/SusyCAF_Tree_2_1_KPR.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_43_32/SusyCAF_Tree_5_1_hrB.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_43_32/SusyCAF_Tree_4_1_IVa.root"
        ],
            CrossSection=1.29, #I guess it's LO, for 100/pb.
            Format=("ICF",2),
            FirstEntry=0,
            LastEntry=0
            )

Z5Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola=PSet(
        Name="Z5Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola",
            File=[
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_46_23/SusyCAF_Tree_2_1_7KI.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_46_23/SusyCAF_Tree_3_1_UYP.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_46_23/SusyCAF_Tree_1_1_Q1F.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_46_23/SusyCAF_Tree_5_1_vAP.root",
"root://gfe02.grid.hep.ph.ic.ac.uk/store/user/peruzzi/ICF/automated/2011_02_16_01_46_23/SusyCAF_Tree_4_1_dAU.root"
        ],
            CrossSection=0.47, #I guess it's LO, for 100/pb.
            Format=("ICF",2),
            FirstEntry=0,
            LastEntry=0
            )


#=PSet(
#Name="",
#File=[
#],
#CrossSection=, #I guess it's LO, for 100/pb.
#Format=("ICF",2),
#FirstEntry=0,
#LastEntry=0
#)


zjets_alpgen_38=[Z0Jets_TuneZ2_7TeV_alpgen_tauola,Z1Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola,Z2Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola,Z3Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola,Z4Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola,Z5Jets_ptZ_0to100_TuneZ2_7TeV_alpgen_tauola,Z1Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola,Z2Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola,Z3Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola,Z4Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola,Z5Jets_ptZ_100to300_TuneZ2_7TeV_alpgen_tauola]
