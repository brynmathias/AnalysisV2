MyCustomJets::MyCustomJets():
    Compute::User<std::vector<Event::Jet>,MyCustomJets>()
{}

void MyCustomJets::_Update() const {
  mData.clear();
  for (std::vector<Event::Jet>::const_iterator iJ = mEv->JD_Jets().begin();
       iJ != mEv->JD_Jets().end();++iJ) {
    if(fabs(iJ->Eta())< 0.5) mData.push_back(*iJ);
  }
}
