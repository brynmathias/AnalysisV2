#ifndef SUSY_SIGNAL_SCAN_FILTERS_HH
#define SUSY_SIGNAL_SCAN_FILTERS_HH

namespace SUSYSignalScan{
class SignalScanLOCrossSectionWeighting : public Compute::ObjectFilter<double>{
 public:
  SignalScanLOCrossSectionWeighting(const Utils::ParameterSet & ps){
    mModifies = true;
    const std::vector<double> & m0 = ps.Get<std::vector<double> >("M0");
    const std::vector<double> & m12 = ps.Get<std::vector<double> >("M12");
    const std::vector<double> & loxs = ps.Get<std::vector<double> >("loxs");

    for(std::vector<double>::const_iterator m0_it = m0.begin();
        m0_it != m0.end(); m0_it++){
      xs_.insert(std::make_pair(std::make_pair((int)(*m0_it),
                                              (int)m12[m0_it - m0.begin()]),
                                loxs[m0_it - m0.begin()]*1E9));
    }
  }

  ~SignalScanLOCrossSectionWeighting(){}

  bool Apply(double * weight){
    if(!mEv->M0.enabled()) return false;
    int m0 = (int)mEv->M0();
    int m12 = (int)mEv->M12();
    std::pair<int, int> xy = make_pair(m0, m12);
    if(xs_.find(xy) == xs_.end()){
      std::stringstream ss;
      ss << "Point: (M0=" << m0 << ", M1/2=" << m12 << ") not found. Aborting.";
      throw std::invalid_argument(ss.str());
    }
    // The 100/10000 factor here is to get identical behaviour to the previous
    // iteration of the code (with the default settings). It should be changed
    // in future.
    *weight = xs_.find(xy)->second*100/10000;
  }

  std::ostream & Description(std::ostream & ostrm){
    return ostrm;
  }


 private:
  std::map<std::pair<int, int>, double> xs_;
};

}
#endif
