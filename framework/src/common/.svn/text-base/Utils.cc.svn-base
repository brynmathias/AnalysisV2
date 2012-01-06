#include "Utils.hh"
namespace Utils{
std::ostream & operator << (std::ostream & ostrm,
			        Utils::ParameterSet const & ps) { 
    ostrm << ps.ToJSON();
  return ostrm;
}

void LoadConfig(const ParameterSet & ps){
  Config::Instance().values=std::map<std::string,ValMap::ValueBase*>(ps.values);
}
}
