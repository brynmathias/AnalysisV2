import setupSUSY
from libFrameworkSUSY import *
from libbryn import *
from icf.core import PSet,Analysis


from montecarlo.LMx import *
from montecarlo.w_jets_mg_edwardSkim import *
from montecarlo.TTBarTauola_NNLO import *
from montecarlo.z_jets_mg_edwardSkim import *
from montecarlo.z_inv_mg_edwardSkim import *
from montecarlo.QCD_Pythia6_allBins import *
from montecarlo.QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1 import *
from montecarlo.QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2 import *
from montecarlo.QCD_Madgraph_50_100 import *
from montecarlo.QCD_Madgraph_100_250 import *
from montecarlo.QCD_Madgraph_250_500 import *
from montecarlo.QCD_Madgraph_500_1000 import *
from montecarlo.QCD_Madgraph_1000_inf import *

AllData38WithTP = PSet(
Name="AllRunsWithTP_Jet",
Weight=1.,
Format=("ICF",2),
File=[
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_0_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_10_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_11_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_12_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_13_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_14_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_15_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_16_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_17_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_18_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_19_skim.root"          ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_1_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_2_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_3_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_4_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_5_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_6_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_7_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_8_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_9_skim.root"           ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_0_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_10_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_11_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_12_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_13_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_14_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_15_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_16_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_17_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_18_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_19_skim.root"            ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_1_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_2_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_3_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_4_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_5_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_6_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_7_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_8_skim.root"             ,
"/vols/cms02/elaird1/14_skims/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt/MultiJet.Run2010B-PromptReco-v2.RECO.RAW.Burt_9_skim.root"             ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_0_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_10_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_11_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_12_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_13_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_14_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_15_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_16_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_17_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_18_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_19_skim.root"                    ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_1_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_2_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_3_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_4_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_5_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_6_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_7_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_8_skim.root"                     ,
"/vols/cms02/elaird1/14_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt2_9_skim.root"                     ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_0_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_10_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_11_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_12_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_13_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_14_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_15_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_16_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_17_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_18_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_19_skim.root"                      ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_1_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_2_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_3_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_4_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_5_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_6_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_7_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_8_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt/Jet.Run2010B-PromptReco-v2.RECO.RAW.Burt_9_skim.root"                       ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_0_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_10_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_11_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_12_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_13_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_14_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_15_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_16_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_17_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_18_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_19_skim.root"              ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_1_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_2_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_3_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_4_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_5_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_6_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_7_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_8_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt/JetMET.Run2010A-Sep17ReReco_v2.RECO.RAW.Burt_9_skim.root"               ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_0_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_10_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_11_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_12_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_13_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_14_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_15_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_16_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_17_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_18_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_19_skim.root"  ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_1_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_2_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_3_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_4_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_5_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_6_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_7_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_8_skim.root"   ,
"/vols/cms02/elaird1/12_skims/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning/JetMETTau.Run2010A-Sep17ReReco_v2.RECO.RAW.Henning_9_skim.root"   ,
]
)



from data.Jet_MultiJet_JetMet_38_JSonUpTo151010 import *
from data.edward_data_skim_36 import *
from data.edward_data_skim_allJetTo_Json151010 import *
#data38=[AllData38WithTP]
data38=[AllData38WithTP]
#data38=[Jet_MultiJet_JetMet_38_JSonUpTo151010]



MC=[LM0,LM1,QCD_Madgraph_1000_inf,QCD_Madgraph_500_1000,QCD_Madgraph_250_500,QCD_Madgraph_100_250,QCD_Madgraph_50_100,wjets_madgraph_edwardSkim,zjets_madgraph_edwardSkim,Zinvisible_jets_edwardSkim,ttbarTauola,QCD_Pt_0to15_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_15to20_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_20to30_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_30to50_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_50to80_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_80to120_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_120to170_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_170to230_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_230to300_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_300to380_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_380to470_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_470to600_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_600to800_7TeV_pythia8_Summer10_START36_V10_S09_v1,QCD_Pt_800to1000_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1000to1400_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1400to1800_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_1800to2200_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_2200to2600_7TeV_pythia8_Summer10_START36_V10_S09_v2,QCD_Pt_3000to3500_7TeV_pythia8_Summer10_START36_V10_S09_v2]
