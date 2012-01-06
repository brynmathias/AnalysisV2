import setupSUSY
import libFrameworkSUSY as fwk
import libWPol as wpol
from icf.core import PSet
class eWPol:
    def __init__(self,
                 data,
                 loose_id,
                 tight_id,
                 trigger_bits = (
                     "HLT_Ele10_LW_L1R", # run < 140041
                     "HLT_Ele15_SW_L1R", # run <= 143962
                     "HLT_Ele15_SW_CaloEleId_L1R", # run <= 146427
                     "HLT_Ele17_SW_CaloEleId_L1R", # run <= 147116
                     "HLT_Ele17_SW_TightEleId_L1R", # run <= 148818
                     "HLT_Ele22_SW_TighterEleId_L1R_v2", # run <= 149180
                     "HLT_Ele22_SW_TighterEleId_L1R_v3" # run >= 149181
                     ),
                 pf_mht = True,
                 mht_cuts = [50, 75, 100 ],
                 met_cuts = [10, 20, 30, 40],
                 mt_cuts = [30, 50, 70],
                 lepton_type = "Electron",
                 ele_jet_dr = 0.3,
                 lep_ptcut = 25.,
                 name = "eWPol",
		 ignore_gen = False,
                 event_no_dump = True
                 ):
        self.name = name
        self.jet_dr = wpol.EleJetDRFilter(ele_jet_dr)
        self.loose_ele_id = wpol.CustomEleId(loose_id.ps())
        self.tight_ele_id = wpol.CustomEleId(tight_id.ps())
        self.lep_pt_cut = lep_ptcut
        self.pol_plots_cfg = PSet(
            DoGen = not (data or ignore_gen),
            LeptonType = lepton_type,
            METThreshold = 40.,
            NLeptons = 1
            )
        self.ops = []
        # Basic event selection
        triggers = PSet(Triggers=trigger_bits)
        self.ops.append(("basic_plots_pretrig",
                         wpol.eWPolBasicPlots("eWPolBasicPlots_PreTrigger",
                                              self.pol_plots_cfg.ps())))
        self.ops.append(("trigger", fwk.OP_MultiTrigger(
            triggers.ps()
            )))
        self.ops.append(("basic_plots_posttrig",
                         wpol.eWPolBasicPlots("eWPolBasicPlots_PostTrigger",
                                              self.pol_plots_cfg.ps())))
        self.ops.append(("good_events", fwk.OP_GoodEventSelection()))
        # Basic object cuts
        self.ops.append(("datamc_one_ele", wpol.DataMCPlots("RECO_DataMCPlots_OneEle")))
        self.ops.append(("one_ele", fwk.OP_NumComElectrons("==", 1)))
        self.ops.append(("basic_plots_gteqoneele",
                         wpol.eWPolBasicPlots("eWPolBasicPlots_GTEQOneEle",
                                              self.pol_plots_cfg.ps())))
        self.ops.append(("good_ele", wpol.ApplyLeptonCut(lepton_type,
                                            lep_ptcut,
                                            self.tight_ele_id,
                                            1,
                                            True)))
        self.ops.append(("datamc_one_wp70_ele", wpol.DataMCPlots("RECO_DataMCPlots_OneWP70Ele")))
        self.ops.append(("three_charge", wpol.ChargeAgreement()))
        self.ops.append(("basic_plots_oneele",
                         wpol.eWPolBasicPlots("eWPolBasicPlots_OneEle",
                                              self.pol_plots_cfg.ps())))
        # self.ops.append(("z_mass", wpol.MassWindowCut(lepton_type,
        #                                     PSet( MassLower = 76.,
        #                                           MassUpper = 106.,
        #                                           MatchCharge = True,
        #                                           NetCharge = 0).ps() )))
        self.ops.append(("zero_mu", fwk.OP_NumComMuons("==", 0)))
        self.ops.append(("lt4_jets", fwk.OP_NumComJets("<", 4)))
        self.ops.append(("pol_plots_premht", wpol.RECO_ElPolPlots(
            "RECO_ElPolPlots_PreMHT",
            self.pol_plots_cfg.ps())))

# Pre MHT Cut

        self.ops.append(("basic_plots_premht",
                         wpol.eWPolBasicPlots("eWPolBasicPlots_PreMHT",
                                              self.pol_plots_cfg.ps())))

        # self.ops.append(("datamc_plots_premht", wpol.DataMCPlots(
        #     "RECO_DataMCPlots_PreMHT2")))

        # MHT Cuts and plots
        self.mht_cuts = {}
        self.pol_plots = {}
        self.datamc_plots = {}
        for mht in mht_cuts:
            if pf_mht:
                self.mht_cuts[mht] = wpol.OP_PFMHTCut(mht)
            else:
                self.mht_cuts[mht] = fwk.RECO_CommonMHTCut(mht)
            self.pol_plots["mht%d" % mht] = wpol.RECO_ElPolPlots(
                "RECO_ElPolPlots_PostMHT%d" % mht,
                self.pol_plots_cfg.ps())
            self.datamc_plots["mht%d" % mht] = wpol.DataMCPlots(
                "RECO_DataMCPlots_PostMHT%d" % mht)

        # MET Cuts and plots

        self.met_cuts = {}
        for mht in mht_cuts:
            for met in met_cuts:
                self.met_cuts[(mht, met)] = fwk.OP_PFMETCut(met)
                self.pol_plots["mht%d_met%d" % (mht, met)] = wpol.RECO_ElPolPlots(
                    "RECO_ElPolPlots_PostMHT%dMET%d" % (mht, met),
                    self.pol_plots_cfg.ps())

        # MT Cuts and plots
        self.mt_cuts = {}
        for mht in mht_cuts:
            for mt in mt_cuts:
                self.mt_cuts[(mht, mt)] = wpol.ePFMTCut(lepton_type, mt)
                self.pol_plots["mht%d_mt%d" % (mht, mt)] = wpol.RECO_ElPolPlots(
                    "RECO_ElPolPlots_PostMHT%dMT%d" % (mht, mt),
                    self.pol_plots_cfg.ps())
		self.datamc_plots["mht%d_mt%d" % (mht, mt)] = wpol.DataMCPlots(
		    "RECO_DataMCPlots_PostMHT%dMT%d" % (mht, mt))
        self.cuts = {}
        self.tree = fwk.Tree(self.name)
        if event_no_dump:
            self.event_no_dump = wpol.EventNoDump("EventNoDump_MT50", "event_no")

    def buildTree(self,
                  basic_plots=True,
                  pol_plots=True,
                  vetos = [],
                  tree = None,
                  root_op = None):
        if tree is None:
            tree = self.tree

        veto_list = vetos
        if not basic_plots:
            veto_list.append("basic_plots")
        if not pol_plots:
            veto_list.append("pol_plots")
        ops_ = []
        for name, op in self.ops:
            veto = False
            print name
            for v in vetos:
                if name.startswith(v):
                    print "Removing operation '%s' from tree" % name
                    veto = True
            if not veto:
                ops_.append((name, op))
        if root_op is None:
            tree.Attach(ops_[0][1])
        else:
            tree.TAttach(root_op, ops_[0][1])

        idx = 1
        for name, op in ops_[1:]:
            tree.TAttach(ops_[idx-1][1], op)
            idx += 1
        for mht, mht_op in self.mht_cuts.iteritems():
             tree.TAttach(ops_[idx-1][1], mht_op)
             if pol_plots:
                 tree.TAttach(mht_op, self.pol_plots["mht%d" % mht])
                 tree.TAttach(mht_op, self.datamc_plots["mht%d" % mht])
        for (mht, met), met_op in self.met_cuts.iteritems():
             tree.TAttach(self.mht_cuts[mht], met_op)
             if pol_plots:
                 tree.TAttach(met_op, self.pol_plots["mht%d_met%d" % (mht, met)])
        for(mht, mt), mt_op in self.mt_cuts.iteritems():
             tree.TAttach(self.mht_cuts[mht], mt_op)
             if pol_plots:
                 tree.TAttach(mt_op, self.pol_plots["mht%d_mt%d" % (mht, mt)])
                 tree.TAttach(mt_op, self.datamc_plots["mht%d_mt%d" % (mht, mt)])
	     # Fringe hack
             if mht == 50 and self.event_no_dump is not None:
	         tree.TAttach(mt_op, self.event_no_dump)

    def installFilters(self, a):
        a.AddElectronFilter("PostCC", self.loose_ele_id)
        a.AddJetFilter("PostCC", self.jet_dr)

    def GetOp(self, name):
        for n, o in self.ops:
            if n == name:
                return o
        return None

def setup_antiselection(
    baton,
    data,
    loose_id,
    tight_id,
    dont_use_gen,
    trigger_info,
    main,
    control_tree,
    ewpol_conf):
    from alexPy.sweet_control import sweet_control_ps
    print "Creating BG analysis"
    e_bg = eWPol(data,
                 loose_id,
                 tight_id,
                 mht_cuts = [],
                 met_cuts = [],
                 mt_cuts = [],
                 name = "BG",
                 ignore_gen = dont_use_gen
                 )
    e_bg.buildTree(basic_plots = False, pol_plots = False,
                   vetos = ["trigger",
                            "good_events",
                            "three_charge",
                            "one_ele",
                            "good_ele",
                            "z_mass",
                            "datamc"],
                   tree = main.tree,
                   root_op = main.ops[1][1])

    lt4j = e_bg.GetOp("lt4_jets")
    sweet = sweet_control_ps(data, ewpol_conf)
    control_tree_ps = sweet.eff80_HoEIso_AntiDeltaEtaDeltaPhi.copy()
    control_tree_ps._quiet_set("TriggerInfo", trigger_info)
    control_tree_ps._quiet_set("PtCut", main.lep_pt_cut)
    control_tree_ps._quiet_set("EtaCut", ewpol_conf.Common.Electrons.EtaCut)
    if control_tree:
        import libAlex as alex
        baton.control_tree_op = alex.ControlTree("control_tree_eff80_HoEIso_AntiDeltaEtaDeltaPhi",
						   control_tree_ps.ps())
        main.tree.TAttach(lt4j, baton.control_tree_op)
    control_plots_ps = control_tree_ps.copy()
    control_plots_ps._quiet_set("WPtCut", 50.)
    control_plots_ps._quiet_set("MTCut", 50.)
    baton.control_plots_op = wpol.ControlPlots("ControlPlots_PostMHT50MT50", control_plots_ps.ps())
    main.tree.TAttach(lt4j, baton.control_plots_op)
    control_plots_ps._quiet_set("MTCut", 0.)
    baton.control_plots_op2 = wpol.ControlPlots("ControlPlots_PostMHT50", control_plots_ps.ps())
    main.tree.TAttach(lt4j, baton.control_plots_op2)
    control_plots_ps._quiet_set("WPtCut", 0.)
    baton.control_plots_op3 = wpol.ControlPlots("ControlPlots_PreMHT", control_plots_ps.ps())
    main.tree.TAttach(lt4j, baton.control_plots_op3)
    baton.e_bg = e_bg
    return baton

def setup_light_tree(baton, main, data, dont_use_gen, trigger_info):
    import wpol.electron_id as electron_id
    import libAlex as alex
    tree_cfg = PSet(
		DoGen = not (data or dont_use_gen),
		TriggerInfo = trigger_info,
		ElectronCuts80 = electron_id.eff_80,
		ElectronCuts70 = electron_id.eff_70,
		ElectronCuts60 = electron_id.eff_60,
		Isolation = True,
		HoverE = True,
		DeltaEtaAtVtx = True,
		DeltaPhiAtVtx = True,
		SigmaIEtaIEta = True,
		Conversions = True,
		ConversionsExtra = True,
		SupressErrors = True
		)
    baton.tree2 = alex.AlexTree("light_tree_lt4jets", tree_cfg.ps())
    main.tree.TAttach(main.GetOp("lt4_jets"), baton.tree2)
    return baton

def setup_skim(baton, main):
    import libFrameworkSUSY as fwk
    baton.skimo = fwk.SkimOp(skim_cf.ps())
    print "Adding skim"
    main.tree.TAttach(main.mht_cuts[50], baton.skimo)
    return baton

