hadd data_Run2011A_May10ReReco.root  Electrons_ElectronHad_Run2011A_May10ReReco*.root
hadd data_Run2011A_PromptRecoV4.root Electrons_ElectronHad_Run2011A_PromptReco_v4*.root
hadd data_Run2011A_Aug05ReReco.root  Electrons_ElectronHad_Run2011A_05Aug2011*.root
hadd data_Run2011A_PromptRecoV6.root Electrons_ElectronHad_Run2011A_PromptReco_v6*.root

hadd data_Run2011B_PromptRecoV1.root Electrons_ElectronHad_Run2011B_PromptReco_v1*.root

hadd data_PAS.root data_Run2011A_May10ReReco.root data_Run2011A_PromptRecoV4.root
hadd data_Run2011A.root data_Run2011A_May10ReReco.root data_Run2011A_PromptRecoV4.root data_Run2011A_Aug05ReReco.root data_Run2011A_PromptRecoV6.root
cp data_Run2011B_PromptRecoV1.root data_Run2011B.root 

hadd data.root data_Run2011A.root data_Run2011B.root

hadd qcd.root Electrons_QCD*.root
hadd w.root   Electrons_W*.root
hadd tt.root  Electrons_TT*.root
hadd z.root   Electrons_DY*.root
hadd lm1.root Electrons_LM1*.root
hadd lm3.root Electrons_LM3*.root
hadd lm6.root Electrons_LM6*.root
hadd lm9.root Electrons_LM9*.root

hadd ewk.root z.root w.root tt.root

hadd sm.root ewk.root qcd.root


