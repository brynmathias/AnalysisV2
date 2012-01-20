#!/usr/bin/env python

import setupSUSY
from libFrameworkSUSY import *
from libHadronic import *
from icf.core import PSet,Analysis

from hadronic.batchGolden import *
def addCutFlowData(a) :
  a.AddJetFilter("PreCC",JetCorrections)
  a+=cutTreeData

# AK5 Calo

conf_ak5_caloData = deepcopy(defaultConfig)
conf_ak5_caloData.Ntuple = deepcopy(ak5_calo)
conf_ak5_caloData.XCleaning = deepcopy(default_cc)
conf_ak5_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak5_caloData=Analysis("AK5Calo")
addCutFlowData(anal_ak5_caloData)

# AK5 PF

conf_ak5_pfData = deepcopy(defaultConfig)
conf_ak5_pfData.Ntuple = deepcopy(ak5_pf)
conf_ak5_pfData.XCleaning = deepcopy(default_cc)
conf_ak5_pfData.Common = deepcopy(default_common)
anal_ak5_pfData=Analysis("AK5PF")
addCutFlowData(anal_ak5_pfData)

# AK5 JPT

conf_ak5_jptData = deepcopy(defaultConfig)
conf_ak5_jptData.Ntuple = deepcopy(ak5_jpt)
conf_ak5_jptData.XCleaning = deepcopy(default_cc)
conf_ak5_jptData.Common = deepcopy(default_common)
# conf_ak5_jDatapt.Common.print_out()
anal_ak5_jptData=Analysis("AK5JPT")
addCutFlowData(anal_ak5_jptData)

# AK7 Calo

conf_ak7_caloData = deepcopy(defaultConfig)
conf_ak7_caloData.Ntuple = deepcopy(ak7_calo)
conf_ak7_caloData.XCleaning = deepcopy(default_cc)
conf_ak7_caloData.Common = deepcopy(default_common)
# conf_ak5_calo.Common.print_out()
anal_ak7_caloData=Analysis("AK7Calo")
addCutFlowData(anal_ak7_caloData)
test = PSet(
Name = "test",
Format = ("ICF",3),
Weight = 1.0,
File = "../../Ntuples/375_newFormat.root")

anal_ak5_caloData.Run("../results/",conf_ak5_caloData,[test])
# anal_ak5_caloData.Run("../results/",conf_ak5_caloData,[bryn1])
#anal_ak5_caloData.Run("../results/",conf_ak5_caloData,[bryn2])
#anal_ak5_caloData.Run("../results/",conf_ak5_caloData,data38)
# anal_ak5_caloData.Run("../results/",conf_ak5_caloData,[LatestSkim101010])


#

# anal_ak5_pfData.Run("../results/",conf_ak5_pfData,data)
# anal_ak5_jptData.Run("../results/",conf_ak5_jptData,data)
# anal_ak7_caloData.Run("../results/",conf_ak7_caloData,data)
