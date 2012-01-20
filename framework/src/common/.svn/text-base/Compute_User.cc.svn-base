#include "Compute_User.hh"
#include "EventData.hh"
namespace Compute{

void UserBase::Init(Event::Data &ev){
  mEv=&ev;
}

UserBase::UserBase(){
  mEv=0;
}

UserBase::~UserBase(){
}


std::ostream & UserBase::Description(std::ostream & ostrm){
  return ostrm;
}

std::ostream & operator << (std::ostream& ostrm,UserBase & m)
 {
  return m.Description(ostrm);
}
}
