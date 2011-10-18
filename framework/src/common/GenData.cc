#include "GenData.hh"
#include "EventData.hh"

namespace Compute{
namespace Gen{

GenMatrix::GenMatrix(const Event::Data & ev):
    Compute::Variable<GenMatrixData, GenMatrix>(ev){}


void GenMatrix::_Update() const{
  mData.clear();
  mData.fillFrom(mEv.GenParticles());
}

}
}
