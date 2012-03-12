from HaronicExample import *
import setupSUSY
from libFrameworkSUSY import *
def switches() :
  d = {}
  d["model"] = ["tanB3", "tanB10", "tanB40", "tanB50", "T1", "T2","T2bb","T2tt"][6]
  d["selection"] = ["had", "muon"][0]
  d["thresholds"] = [(36.7, 73.7), (43.3, 86.7), (50.0, 100.0)][0]
  d["jes"] = ["", "+ve", "-ve"][0]
  checkSwitches(d)
  return d


cutTreeMC = Tree("MC")
stuff = cutFlow(cutTreeMC, model = switches()["model"])
anal_ak5_caloMC =Analysis("AK5Calo")
addCutFlowMC(anal_ak5_caloMC,cutTreeMC)



anal_ak5_caloMC.Run(outputDir(), conf_ak5_calo_msugra,[sample()])
