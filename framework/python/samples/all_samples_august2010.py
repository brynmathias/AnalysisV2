from icf.core import PSet

IntLumi=10.

##########################################################
# QCD Pythia

qcd_pythia_pt15=PSet(
    Name="QCD_Pythia_Pt15",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_06_24_18_00_11/SusyCAF_Tree_21_1_N09.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_33_1_ZPZ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_25_1_8vh.root",
#"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_35_1_5rE.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_1_1_nB2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_12_1_TUQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_29_1_biH.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_58_2_x3A.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_7_2_53U.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_31_2_qnC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_50_1_2F7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_8_3_b0x.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_39_1_Ry4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_28_1_pDp.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_53_1_y0G.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_15_3_mt9.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_62_3_Yne.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_35_2_Jih.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_14_2_C0e.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_11_2_48f.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_59_2_XJt.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_38_2_lZo.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_26_2_j8w.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_3_3_1O4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_60_2_lxn.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_36_2_DXc.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_52_2_lGu.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_5_1_o64.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_44_1_s6b.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_46_1_1cU.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_47_1_D45.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_42_1_xzz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_61_2_15C.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_4_2_Fc4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_17_2_5tB.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_20_1_gXv.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_7_1_xTz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_2_1_97I.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_57_1_dUY.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_19_1_LwN.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_34_1_qeE.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_32_1_pfY.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_23_1_Kqq.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_30_1_tCy.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_56_1_Xui.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_43_1_p37.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_41_1_3qO.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_6_1_pRx.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_13_1_8mn.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_27_1_qeL.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_10_1_1hm.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_16_1_2ks.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_54_1_SYl.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_48_1_fn3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_40_1_9Fq.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_45_1_bDH.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_22_1_4v1.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_24_1_QDp.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_37_1_jYa.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_51_1_E10.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_18_1_eOB.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_63_1_Z6I.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_55_1_0ue.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_49_1_Yep.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user//gouskos//ICF/automated/2010_06_24_18_00_11//SusyCAF_Tree_9_1_qcn.root"
    ],
    CrossSection=8.762e+08,
    Reweight=IntLumi,
    Format=("ICF",2),
)

qcd_pythia_pt30=PSet(
    Name="QCD_Pythia_Pt30",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_10_2_iHk.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_11_2_EHT.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_12_2_DAz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_13_2_Q6S.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_14_2_XfM.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_15_2_LZw.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_16_2_3GD.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_17_2_oLz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_18_2_aj1.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_19_2_Ppt.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_1_2_mRT.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_20_3_g6Y.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_21_1_8ko.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_22_0_pql.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_23_0_tYz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_24_0_nxz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_25_0_U1V.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_26_0_Ieb.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_27_0_mf7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_28_0_z44.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_29_0_inC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_2_2_Ybk.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_30_0_U2o.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_31_0_lYM.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_32_0_Zy3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_33_2_zDO.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_34_2_Tdw.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_35_2_LDh.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_36_2_loW.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_37_2_rps.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_38_2_TEs.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_39_3_y4C.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_3_2_4gQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_40_2_RBx.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_41_1_5H2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_42_2_0ZU.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_43_2_R1M.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_44_2_dQq.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_46_2_VGq.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_48_1_i3Q.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_49_2_rwL.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_4_2_lgu.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_50_2_Wqg.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_51_2_ebS.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_52_2_6sV.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_53_3_XbN.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_54_1_Cue.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_5_2_zCh.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_6_2_56i.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_7_2_YwW.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_8_2_lmH.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos//ICF/automated/2010_06_24_18_09_51//SusyCAF_Tree_9_2_ANH.root"
    ],
    CrossSection=6.041e+07,
    Reweight=IntLumi,
    Format=("ICF",2),
)

qcd_pythia_pt80=PSet(
    Name="QCD_Pythia_Pt80",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_10_1_52b.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_11_1_M7G.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_12_1_7qM.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_13_1_a7q.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_14_1_B5y.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_15_3_03b.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_16_3_P4j.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_17_3_HEy.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_1_3_7c7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_20_1_C5G.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_21_1_1ti.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_22_4_anj.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_23_4_WJC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_24_1_QjG.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_26_1_pGm.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_27_3_JW4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_29_2_UbN.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_2_2_HSl.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_31_2_BaH.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_34_1_YoT.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_35_3_KAi.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_36_1_a4Z.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_3_4_eGg.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_5_1_7dI.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_00_55_17//SusyCAF_Tree_7_4_fW1.root"
    ],
    CrossSection=9.238e+5,
    Reweight=IntLumi,
    Format=("ICF",2)
)

qcd_pythia_pt170=PSet(
    Name="QCD_Pythia_Pt170",
    File= [
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_10_2_41z.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_11_2_etY.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_12_2_DXO.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_1_2_hBp.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_13_2_AiX.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_14_2_zLL.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_15_5_a5u.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_16_2_HGP.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_17_2_Ptd.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_18_2_2JA.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_19_4_tez.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_20_2_lcp.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_21_2_bT6.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_22_4_93W.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_2_2_5dh.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_23_4_nDQ.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_24_2_iZG.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_25_4_HiB.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_26_2_JgS.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_27_4_8pQ.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_28_3_CDO.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_29_4_ozu.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_30_2_ttD.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_31_4_g6N.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_32_2_5Sm.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_33_2_HXh.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_3_4_Yjw.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_4_2_ZUi.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_5_2_rea.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_6_4_AwH.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_7_3_Erv.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_8_4_mH5.root",
    "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_06_01_33_23//SusyCAF_Tree_9_2_HSv.root"
    ],
    CrossSection=25470.,
    Reweight=IntLumi,
    Format=("ICF",2)
)

qcd_pythia_pt300=PSet(
    Name="QCD_Pythia_Pt300",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_10_1_8qT.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_11_1_ZWo.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_12_1_lmN.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_13_1_vAo.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_15_1_57I.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_16_1_myh.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_17_1_75j.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_18_1_kja.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_19_1_OGt.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_1_1_HKo.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_20_1_Owg.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_21_1_ChW.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_22_1_c5C.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_23_1_NwX.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_24_1_NXQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_25_1_ED8.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_26_1_4iW.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_27_1_jDH.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_28_1_yso.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_2_1_rm1.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_30_1_TxN.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_31_1_zrc.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_32_1_Aix.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_33_1_yOT.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_34_1_dlg.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_35_1_KY5.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_36_1_B4o.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_3_1_eqq.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_4_1_7ww.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_5_1_NOD.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_6_1_bGQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_7_1_0nQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_8_1_iHF.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_09_19_13_09//SusyCAF_Tree_9_1_2W6.root"
    ],
    CrossSection=1256.,
    Reweight=IntLumi,
    Format=("ICF",2)
)

qcd_pythia_pt470=PSet(
    Name="QCD_Pythia_Pt470",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_10_1_wU8.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_11_1_o9t.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_12_1_Uuy.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_13_1_A6P.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_14_1_qnz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_15_1_CvP.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_16_1_R0M.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_17_1_lPJ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_18_1_Hw6.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_19_1_SK4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_1_1_9gm.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_20_1_vl7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_21_1_8om.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_22_1_3zx.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_23_1_NdC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_24_1_HU2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_2_1_Q9D.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_3_1_qPy.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_4_1_DOC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_5_1_WdP.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_6_1_gpJ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_7_1_WeK.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_8_1_e3F.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_22_06//SusyCAF_Tree_9_1_hbr.root"
    ],
    CrossSection=87.98,
    Reweight=IntLumi,
    Format=("ICF",2)
)

qcd_pythia_pt800=PSet(
    Name="QCD_Pythia_Pt800",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_10_1_aDW.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_11_2_XEs.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_12_2_Stw.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_13_1_3pW.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_14_1_QO2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_15_1_zJR.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_16_1_w34.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_17_2_3M2.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_18_1_NKw.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_19_1_9LD.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_1_1_BJZ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_20_1_8ko.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_21_1_Pqh.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_22_1_kvC.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_2_1_3JV.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_3_1_Tf4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_4_1_2vA.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_5_1_Gtz.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_6_2_HMV.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_7_1_mHc.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_8_1_7xw.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_37_56//SusyCAF_Tree_9_1_dFz.root"
    ],
    CrossSection=2.186,
    Reweight=IntLumi,
    Format=("ICF",2)
)

qcd_pythia_pt1400=PSet(
    Name="QCD_Pythia_Pt1400",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_10_1_IFQ.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_11_1_eBf.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_12_1_R5r.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_13_1_mFL.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_1_1_YC5.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_2_1_Fea.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_3_1_jgc.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_4_1_zrh.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_5_1_rv9.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_6_1_2d3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_7_1_5Dv.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_8_1_Zr7.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/gouskos/ICF/automated/2010_07_10_04_47_48//SusyCAF_Tree_9_1_Qjk.root"
    ],
    CrossSection=0.01122,
    Reweight=IntLumi,
    Format=("ICF",2)
)

big_list_qcd_all = []
for file in qcd_pythia_pt15.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt30.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt80.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt170.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt300.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt470.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt800.File:
  big_list_qcd_all.append(file)
for file in qcd_pythia_pt1400.File:
  big_list_qcd_all.append(file)

qcd_pythia_all=PSet(
    Name="QCD_Pythia_All",
    Format=("ICF",2),
    File=big_list_qcd_all,
    Weights=PSet(
    CrossSection = [ 8.762e+08, 6.041e+07, 9.238e+05, 2.547e+04, 1.256e+03, 8.798e+01, 2.186e+00, 1.122e-02 ],
    Events       = [ 6246300,   5228992,   3203440,   3132800,   3274202,   2143390,   2143921,   1184123   ],
    PtBin        = [ 15.,       30.,       80.,       170.,      300.,      470.,      800.,      1400.     ],
    ),
    Reweight=IntLumi,
)

##########################################################
# Photon + Jet Pythia

photonjet_pythia_15=PSet(
    Name="PhotonJet_Pt15",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt15.root"],
    CrossSection=1.922e+05, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

photonjet_pythia_30=PSet(
    Name="PhotonJet_Pt30",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt30.root"],
    CrossSection=2.007e+04,
    Reweight=IntLumi,
    Format=("ICF",2),
)

dcap_path = "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/as1604/ICF/automated"

photonjet_pythia_80=PSet(
    Name="PhotonJet_Pt80",
    File = ["%s/2010_07_19_20_23_49/SusyCAF_Tree_%d_1.root" % (dcap_path, i) for i in [1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14] ],
    CrossSection=5.565e+02,
    Reweight=IntLumi,
    Format=("ICF", 2)
)

photonjet_pythia_170=PSet(
    Name="PhotonJet_Pt170",
    File=["%s/2010_07_19_20_38_39/SusyCAF_Tree_%d_1.root" % (dcap_path, i) for i in [1, 2, 3, 4, 5, 6, 10, 13] ] +
    ["%s/2010_07_19_20_38_39/SusyCAF_Tree_%d_2.root" % (dcap_path, i)
for i in [8] ] +
    ["%s/2010_07_19_20_38_39/SusyCAF_Tree_%d_3.root" % (dcap_path, i)
for i in [7, 12] ],
    CrossSection=2.437e+01,
    Reweight=IntLumi,
    Format=("ICF", 2)
)

photonjet_pythia_300=PSet(
    Name="PhotonJet_Pt300",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt300.root"],
    CrossSection=1.636e+00,
    Reweight=IntLumi,
    Format=("ICF",2),
)

photonjet_pythia_470=PSet(
    Name="PhotonJet_Pt470",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt470.root"],
    CrossSection=1.360e-01,
    Reweight=IntLumi,
    Format=("ICF",2),
)

photonjet_pythia_800=PSet(
    Name="PhotonJet_Pt800",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt800.root"],
    CrossSection=3.477e-03,
    Reweight=IntLumi,
    Format=("ICF",2),
)

photonjet_pythia_1400=PSet(
    Name="PhotonJet_Pt1400",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt1400.root"],
    CrossSection=1.286e-05,
    Reweight=IntLumi,
    Format=("ICF",2),
)

photonjet_pythia_2200=PSet(
    Name="PhotonJet_Pt2200",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt2200.root"],
    CrossSection=4.035e-09,
    Reweight=IntLumi,
    Format=("ICF",2),
)

photonjet_pythia_3000=PSet(
    Name="PhotonJet_Pt3000",
    File=["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/PhotonJet_Pt3000.root"],
    CrossSection=1.779e-14,
    Reweight=IntLumi,
    Format=("ICF",2),
)

big_list_photonjet_all = []
for file in photonjet_pythia_15.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_30.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_80.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_170.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_300.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_470.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_800.File:
  big_list_photonjet_all.append(file)
for file in photonjet_pythia_1400.File:
  big_list_photonjet_all.append(file)

photonjet_pythia_all=PSet(
    Name="PhotonJet_Pythia_All",
    Format=("ICF",2),
    File=big_list_photonjet_all,
    Weights=PSet(
    CrossSection = [ 1.922e+05, 2.007e+04, 5.565e+02, 2.437e+01, 1.636e+00, 1.360e-01, 3.477e-03, 1.286e-05 ],#, 4.035e-09, 1.779e-14 ],
    Events       = [ 1223390,   1024266,   1000000,   1000000,   1024266,   1091179,   1065640,   1291025   ],#, 1093562,   1189440   ],
    PtBin        = [ 15.,       30.,       80.,       170.,      300.,      470.,      800.,      1400.     ],#, 2200.,     3000.     ],
    ),
    Reweight=IntLumi,
)

### NOTE: THERE IS A PROBLEM WITH THE PHOTON + JET PYTHIA Pt2200 AND Pt3000 SAMPLES. IT IS THOUGHT TO BE DUE TO A BUG IN GEANT. ###

###########################################################
# W + Jets Madgraph

w_jets=PSet(
    Name="WJets-madgraph",
    File= [
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_51_5.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_76_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_47_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_73_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_62_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_39_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_63_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_20_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_92_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_64_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_57_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_85_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_83_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_3_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_69_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_5_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_25_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_12_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_9_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_37_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_90_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_44_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_34_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_86_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_72_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_36_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_87_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_66_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_33_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_26_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_14_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_2_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_43_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_67_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_78_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_99_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_22_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_84_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_59_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_82_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_68_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_58_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_95_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_93_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_35_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_80_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_94_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_31_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_29_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_10_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_97_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_100_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_65_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_48_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_19_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_4_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_77_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_24_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_88_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_98_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_55_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_60_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_32_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_50_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_8_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_89_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_7_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_21_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_101_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_13_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_46_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_61_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_11_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_79_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_41_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_53_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_15_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_71_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_40_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_91_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_18_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_74_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_81_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_30_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_102_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_49_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_45_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_23_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_17_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_16_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_96_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_70_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_6_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_52_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_1_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_103_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_104_4.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_28_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_27_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_54_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_42_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_38_3.root",
"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/jad/ICF/automated//2010_06_18_22_33_23/SusyCAF_Tree_75_3.root"],
    CrossSection=24170.0,
    Reweight=IntLumi,
    Format=("ICF",2),
)

###########################################################
# Z + Jets Madgraph

z_jets=PSet(
    Name="ZJets-madgraph",
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
    CrossSection=2400.0,
    Reweight=IntLumi,
    Format=("ICF",2),
)

###########################################################
# Z->inv + Jets Madgraph

z_inv=PSet(
    Name="Zinvisible_jets",
    File= ["root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_10_3.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_11_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_4_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_17_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_15_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_6_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_16_3.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_21_3.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_13_3.root",
       #  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_14_3.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_9_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_20_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_8_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_12_2.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_18_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_19_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_1_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_5_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_7_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_2_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_3_1.root",
         "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/zph04/ICF/automated/2010_07_14_11_52_58/SusyCAF_Tree_22_1.root"
    ],
    CrossSection=4500.,
    Reweight=IntLumi,
    Format=("ICF",2)
)

###########################################################
# ttbar Madgraph (V11 tag)

ttbar_jets=PSet(
    Name="ttbarTauola",
  #  File=["/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_10_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_11_2.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_12_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_13_2.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_14_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_15_2.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_16_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_1_2.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_2_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_3_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_4_2.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_5_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_6_2.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_7_3.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_8_1.root",
  #  "/castor/cern.ch/user/m/mstoye//ICF/automated/2010_06_29_11_52_22/SusyCAF_Tree_9_2.root"],

    File=["/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_10_1.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_11_2.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_12_1.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_13_2.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_14_1.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_15_2.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_16_1.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_1_2.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_2_1.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_3_1.root",
   # "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_4_2.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_5_1.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_6_2.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_7_3.root",
    "/vols/cms01/mstoye/ttTauola_madgraph_V11tag/SusyCAF_Tree_8_1.root"
      ],
    CrossSection=95.,
    Reweight=IntLumi,
    Format=("ICF",2),
)

###########################################################
# DiPhoton Box

DiPhotonBox_10to25=PSet(
    Name="DiPhotonBox_Pt10to25",
    File=[  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_15_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_28_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_27_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_47_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_40_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_18_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_17_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_14_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_22_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_21_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_23_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_29_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_35_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_32_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_52_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_33_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_50_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_36_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_51_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_39_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_44_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_41_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_49_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_19_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_7_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_46_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_31_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_54_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_16_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_12_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_5_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_10_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_43_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_38_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_11_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_25_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_42_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_55_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_13_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_37_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_20_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_26_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_48_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_24_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_30_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_45_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_53_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_34_1.root"  ],
    CrossSection=358.2,
    Reweight=IntLumi,
    Format=("ICF",2),
)

DiPhotonBox_25to250=PSet(
    Name="DiPhotonBox_Pt25to250",
    File=[  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_41_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_38_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_19_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_40_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_36_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_12_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_46_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_5_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_43_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_51_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_17_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_10_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_52_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_18_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_7_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_22_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_56_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_25_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_37_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_11_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_32_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_15_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_30_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_48_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_47_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_31_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_20_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_45_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_49_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_13_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_53_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_16_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_39_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_29_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_14_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_50_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_21_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_44_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_27_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_23_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_24_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_34_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_26_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_42_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_33_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_28_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_35_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_54_1.root"  ],
    CrossSection=12.37,
    Reweight=IntLumi,
    Format=("ICF",2),
)

DiPhotonBox_250toInf=PSet(
    Name="DiPhotonBox_Pt250toInf",
    File=[  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_14_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_21_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_16_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_17_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_18_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_22_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_10_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_7_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_19_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_20_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_13_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_11_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_5_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_12_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_15_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBox_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root"  ],
    CrossSection=2.08e-04,
    Reweight=IntLumi,
    Format=("ICF",2),
)

###########################################################
# DiPhoton Born

DiPhotonBorn_10to25=PSet(
    Name="DiPhotonBorn_Pt10to25",
    File=[  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_11_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_46_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_29_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_51_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_5_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_23_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_18_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_19_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_26_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_48_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_7_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_15_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_44_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_16_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_52_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_36_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_45_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_28_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_53_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_43_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_21_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_35_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_31_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            #"root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_34_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_40_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_30_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_38_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_50_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_22_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_27_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_24_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_54_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_49_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_14_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_12_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_41_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_47_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_32_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_10_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_17_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_20_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_33_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_42_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_25_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_39_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_37_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt10to25.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_13_1.root"  ],
    CrossSection=236.4,
    Reweight=IntLumi,
    Format=("ICF",2),
)

DiPhotonBorn_25to250=PSet(
    Name="DiPhotonBorn_Pt25to250",
    File=[  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_23_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_38_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_48_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_35_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_32_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_75_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_5_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_34_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_29_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_22_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_52_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_76_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_7_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_51_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_70_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_36_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_58_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_56_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_21_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_14_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_24_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_57_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_41_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_60_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_15_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_13_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_11_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_27_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_37_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_47_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_46_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_66_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_33_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_18_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_63_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_64_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_31_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_61_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_12_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_49_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_73_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_72_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_44_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_55_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_16_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_20_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_62_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_25_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_71_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_26_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_67_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_59_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_54_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_30_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_43_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_65_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_68_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_40_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_39_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_28_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_69_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_45_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_42_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_10_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_50_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_74_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_53_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_19_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt25to250.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_17_1.root"  ],
    CrossSection=22.37,
    Reweight=IntLumi,
    Format=("ICF",2),
)

DiPhotonBorn_250toInf=PSet(
    Name="DiPhotonBorn_Pt250toInf",
    File=[  "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_13_2.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_22_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_2_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_10_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_3_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_9_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_20_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_1_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_18_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_19_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_5_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_8_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_7_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_15_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_12_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_16_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_4_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_11_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_6_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_17_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_21_1.root",
            "root://xrootd.grid.hep.ph.ic.ac.uk//store/user/rnandi/ICF/automated/2010_07_16_17_53_40/DiPhotonBorn_Pt250toInf.Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/SusyCAF_Tree_14_1.root"  ],
    CrossSection=8.072e-03,
    Reweight=IntLumi,
    Format=("ICF",2),
)

# -----------------------------------------------------------------------------
# LMx

#path1="/store/user/bainbrid/ICF/automated/2010_07_12_17_52_54/"
#path2="/store/user/bainbrid/ICF/automated/2010_07_16_12_54_00/"
path="root://xrootd.grid.hep.ph.ic.ac.uk//store/user/bainbrid/ICF/automated/"
name="Spring10-START3X_V26_S09-v1.GEN-SIM-RECO/"

LM0=PSet(
    Name="LM0",
    File=[
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_1_2.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_2_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_3_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_4_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_5_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_6_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_7_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_8_1.root",
        path+"2010_07_16_12_54_00/"+"LM0"+name+"SusyCAF_Tree_9_1.root",
        ],
    CrossSection=38.93, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM1=PSet(
    Name="LM1",
    File=[
        path+"2010_07_12_17_52_54/"+"LM1"+name+"SusyCAF_Tree_1_1.root",
        path+"2010_07_12_17_52_54/"+"LM1"+name+"SusyCAF_Tree_2_1.root",
        path+"2010_07_12_17_52_54/"+"LM1"+name+"SusyCAF_Tree_3_1.root",
        ],
    CrossSection=4.888, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM2=PSet(
    Name="LM2",
    File=[
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_6_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_3_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_2_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_4_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_5_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_1_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_7_1.root",
        path+"2010_07_16_12_54_00/"+"LM2"+name+"SusyCAF_Tree_8_1.root",
        ],
    CrossSection=0.6027, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM3=PSet(
    Name="LM3",
    File=[
        path+"2010_07_12_17_52_54/"+"LM3"+name+"SusyCAF_Tree_1_3.root",
        path+"2010_07_12_17_52_54/"+"LM3"+name+"SusyCAF_Tree_2_3.root",
        path+"2010_07_12_17_52_54/"+"LM3"+name+"SusyCAF_Tree_3_1.root",
        ],
    CrossSection=3.438, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM4=PSet(
    Name="LM4",
    File=[
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_7_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_4_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_6_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_3_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_2_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_10_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_5_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_9_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_1_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_8_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_11_1.root",
        ],
    CrossSection=1.879, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM5=PSet(
    Name="LM5",
    File=[
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_10_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_4_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_6_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_5_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_2_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_7_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_1_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_8_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_3_1.root",
        path+"2010_07_16_12_54_00/"+"LM4"+name+"SusyCAF_Tree_9_1.root",
        ],
    CrossSection=0.4734, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM6=PSet(
    Name="LM6",
    File=[path+"2010_07_16_12_54_00/"+"LM6"+name+"SusyCAF_Tree_*.root"],
    CrossSection=0.3104, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM7=PSet(
    Name="LM7",
    File=[path+"2010_07_16_12_54_00/"+"LM7"+name+"SusyCAF_Tree_*.root"],
    CrossSection=1.209, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM8=PSet(
    Name="LM8",
    File=[path+"2010_07_16_12_54_00/"+"LM8"+name+"SusyCAF_Tree_*.root"],
    CrossSection=0.7300, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM9=PSet(
    Name="LM9",
    File=[path+"2010_07_12_17_52_54/"+"LM9"+name+"SusyCAF_Tree_*.root"],
    CrossSection=7.134, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM10=PSet(
    Name="LM10",
    File=[path+"2010_07_12_17_52_54/"+"LM10"+name+"SusyCAF_Tree_*.root"],
    CrossSection=0.04778, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM11=PSet(
    Name="LM11",
    File=[path+"2010_07_16_12_54_00/"+"LM11"+name+"SusyCAF_Tree_*.root"],
    CrossSection=0.8236, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM12=PSet(
    Name="LM12",
    File=[path+"2010_07_12_17_52_54/"+"LM12"+name+"SusyCAF_Tree_*.root"],
    CrossSection=4.414, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

LM13=PSet(
    Name="LM13",
    File=[path+"2010_07_16_12_54_00/"+"LM13"+name+"SusyCAF_Tree_*.root"],
    CrossSection=6.899, 
    Reweight=IntLumi,
    Format=("ICF",2),
)

# -----------------------------------------------------------------------------
# GGM

ggm10=PSet(
    Name="GGM_tan_beta_10",
    File="root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/GGM_tan_beta_10.root",
    CrossSection=17.29,
    Reweight=IntLumi,
    Format=("ICF",2),
)

ggm20=PSet(
    Name="GGM_tan_beta_20",
    File="root://xrootd.grid.hep.ph.ic.ac.uk//store/user/susy/MC/GGM_tan_beta_20.root",
    CrossSection=17.25,
    Reweight=IntLumi,
    Format=("ICF",2),
)

