#ifndef UTILS_HH
#define UTILS_HH
#include <map>
#include <sstream>
#include <stdexcept>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

#ifndef _NO_BOOST_POOL_
#include <boost/pool/object_pool.hpp>
#endif

namespace Event{
class Data;
}

namespace Utils{

class Lumis {

  public:
    Lumis(){}
    ~Lumis(){}

    void Add(int RunNumber, int LumiSection) {
      std::reverse_iterator<std::vector<std::pair<int,std::vector<int> > >::iterator> it_end ( lumis_.begin() );
      std::reverse_iterator<std::vector<std::pair<int,std::vector<int> > >::iterator> it ( lumis_.end() );
      for (; it != it_end; it++) {
        if (it->first == RunNumber) {
          it->second.push_back(LumiSection);
          return;
        }
      }
      std::pair<int,std::vector<int> > newrun;
      newrun.first = RunNumber;
      newrun.second.push_back(LumiSection);
      lumis_.push_back(newrun);
    }

    std::string Print() {//operator<< ( std::ostream& os, const Utils::Lumis& input ) {
      std::stringstream ss;
      ss << "{";
      for (std::vector<std::pair<int,std::vector<int> > >::const_iterator it = lumis_.begin(); it != lumis_.end(); it++) {
        ss << "\"" << it->first << "\": [";
        int last_lumi = 0;
        int first_lumi = 0;
        for (std::vector<int>::const_iterator lumi = it->second.begin(); lumi != it->second.end(); lumi++) {
          if (last_lumi == 0) first_lumi = *lumi;
          if (*lumi != last_lumi && *lumi != last_lumi + 1 && last_lumi != 0) {
            ss << "[" << first_lumi << ", " << last_lumi << "], ";
            first_lumi = *lumi;
          }
          if (lumi == it->second.end()-1) ss << "[" << first_lumi << ", " << *lumi << "]";
          last_lumi = *lumi;
        }
        if (it == lumis_.end()-1) ss << "]";
        else ss << "], ";
      }
      ss << "}";
      return ss.str();
    }

    void Reset() {
      lumis_.clear();
    }

    void Sort() {
      for (std::vector<std::pair<int,std::vector<int> > >::iterator it = lumis_.begin(); it != lumis_.end(); it++) {
        sort(it->second.begin(), it->second.end());
      }
      sort(lumis_.begin(), lumis_.end());
    }

  private:
    std::vector<std::pair<int,std::vector<int> > > lumis_;
};

class ValMap{
 protected:
  struct ValueBase{
    virtual std::string ToString()=0;
    virtual std::string ToJSON()=0;
    virtual ~ValueBase(){};
  };

  template <typename T>
  class Value : public ValueBase{
   public:
    T val;
    Value(T init):val(init){}

    std::string ToJSON(){
      std::stringstream ss;
      std::string str;
      if (typeid(val) == typeid(str)) {
        ss << "\"" << val << "\"";
      } else {
        ss << val;
      }
      return ss.str();
    }
    std::string ToString(){
      std::stringstream ss;
      ss << val;
      return ss.str();
    }
  };
 public:

  template<typename ValType>
  const ValType& Get(std::string key) const{
    if(values.count(key)==0){
      std::string err;
      err= "Error fetching key: " + key + ". Key doesn't exist.";
      throw std::invalid_argument(err);
    }
    Value<ValType>* v=dynamic_cast<Value<ValType>*>(values.find(key)->second);
    if(v==0){
      std::string err="Error fetching key: " + key + ". Wrong type.";
      throw std::invalid_argument(err);
    }
    return v->val;
  }

  ValueBase& Get(std::string key){
    return *values[key];
  }

  std::string ToJSON() const{
    std::stringstream ss;
    std::map<std::string,ValueBase*>::const_iterator last = values.end();
    last--;
    for(std::map<std::string,ValueBase*>::const_iterator ii=values.begin();
        ii!=values.end();
        ++ii){
      if (ii == last) {
        ss << "    \"" << ii->first << "\" : " << ii->second->ToJSON() << std::endl;
      } else {
        ss << "    \"" << ii->first << "\" : " << ii->second->ToJSON() << "," << std::endl;
      }
    }
    return ss.str();
  }

  std::string ToString() const{
    std::stringstream ss;
    for(std::map<std::string,ValueBase*>::const_iterator ii=values.begin();
        ii!=values.end();
        ++ii){
        ss << ii->first << " = " << ii->second->ToString() << std::endl;
    }
    return ss.str();
  }

  void Clear(){
    values.clear();
  }

  bool Contains(std::string key) const{
    return (values.count(key)>0);
  }

  template<typename ValType>
  void Set(std::string key,ValType val){
    Value<ValType> *v=new Value<ValType>(val);
    ValueBase* vb=dynamic_cast<ValueBase*>(v);
    vb=dynamic_cast<ValueBase*>(v);
    if(vb==0){
      std::string err="Error setting key: "+key+". Cast failed.";
      throw std::invalid_argument(err);
    }
    values[key]=vb;
  }

  void Remove(std::string key){
    values.erase(key);
  }

 protected:
std::map<std::string,ValueBase*> values;
};

class ParameterSet;
void LoadConfig(const ParameterSet & ps);

class ParameterSet : public ValMap{
  friend void LoadConfig(const ParameterSet & ps);
 public:
  void AddDouble(std::string key,double value){
    Set<double>(key,value);
  }

  void AddBool(std::string key,bool value){
    Set<bool>(key,value);
  }

  void AddString(std::string key,std::string value){
    Set<std::string>(key,value);
  }
  void AddInt(std::string key,int value){
    Set<int>(key,value);
  }

  void AddStringVector(std::string key,std::vector<std::string> value){
    Set<std::vector<std::string> >(key,value);
  }

  void AddDoubleVector(std::string key, std::vector<double> value){
    Set<std::vector<double> >(key,value);
  }

  void AddIntVector(std::string key, std::vector<int> value){
    Set<std::vector<int> >(key,value);
  }

 void AddUIntVector(std::string key, std::vector<unsigned int> value){
    Set<std::vector<unsigned int> >(key,value);
  }

  void AddLongIntVector(std::string key, std::vector<long> value){
    Set<std::vector<long> >(key, value);
  }

  void AddBoolVector(std::string key, std::vector<bool> value){
    Set<std::vector<bool> >(key,value);
  }

};

std::ostream & operator << (std::ostream & ostrm,
                            Utils::ParameterSet const & ps);

template<class T>
std::ostream & operator << (std::ostream & ostrm,
                            std::vector<T> const & vec){
  std::string str;
  ostrm << "[ ";
  for(typename std::vector<T>::const_iterator it=vec.begin();
      it!=vec.end(); ++it){
    if (typeid(*it) == typeid(str) && it == vec.begin()) ostrm << "\"";
    ostrm << *it;
    if (it!=vec.end()-1) ostrm << " , ";
    if (typeid(*it) == typeid(str) && it == vec.end()-1) ostrm << "\"";
  }
  ostrm << " ]";
  return ostrm;
}


class Config : public ValMap{
 public:
  static Config & Instance(){
    static Config myInstance;
    return myInstance;
  }

  friend void LoadConfig(const ParameterSet & ps);

 private:
  ValMap pset;
  Config(){};          // ctor is hidden
  Config(Config const&);      // copy ctor is hidden
  Config& operator=(Config const&);  // assign op is hidden
};

template<typename T>
T GetConfig(std::string name){
try{
  return Config::Instance().Get<T>(name);
}
catch(std::exception & e){
  std::string e_str="Error. Could not get configuration parameter: "
      +name+"\n ( "+e.what()+" ).";
  throw std::invalid_argument(e_str);
}
}
}

/* CloneVector class
 * =====================
 * This class attempts to implement a * wrapper around a vector class of const
 * pointers. If you wish to modify the pointer, then you can call the GetClone
 * method. If the const * has already been cloned this returns a non-const
 * pointer to it. If it hasnt, it calls ObjectType's copy constructor to create
 * one and returns a non const pointer to this.
 */

namespace Compute{
template<class ObjectType>
class CloneVector{
 public:
  /* These methods emulate an stl vector interface for boost python
     integration.
  */
  typedef int size_type;
  typedef int difference_type;
  typedef const ObjectType* value_type;
  typedef typename std::vector<const ObjectType*>::iterator iterator;

  int size(){ return objects.size();}

  value_type& operator[](int i){ return objects[i];}

  iterator erase(iterator ii){
    dealloc(clone_objects_ptr[ii-objects.begin()]);
    clone_objects_ptr.erase(clone_objects_ptr.begin()+(ii-objects.begin()));
    return objects.erase(ii);
  }

  iterator erase(iterator i_start,iterator i_end){
    iterator i_last;
    for(iterator ii=i_start;ii!=i_end;++ii){
      i_last=erase(ii);
    }
    return i_last;
  }

  iterator insert(iterator pos,const ObjectType* item){
    int p=pos-objects.begin();
    typename std::vector<ObjectType*>::iterator cp=clone_objects_ptr.begin()+p;
    clone_objects_ptr.insert(cp,0);
    return objects.insert(pos,item);
  }

  template <class InputIterator>
  void insert(iterator pos,InputIterator first,InputIterator last){
    iterator p=pos;
    for(InputIterator it=first;it!=last;++it){
      insert(pos++,*it);
    }
  }

  void push_back(const value_type& ob){
    objects.push_back(ob);
    clone_objects_ptr.push_back(0);
  }

  CloneVector(iterator i1,iterator i2):
      objects(i1,i2){
    for(iterator ii=i1;ii!=i2;++ii){
      clone_objects_ptr.push_back(0);
    }
  }

  /* Provide a non-iterator based Clone for testing purposes */
  ObjectType & CloneI(int idx){
    if(idx>=objects.size()) throw std::invalid_argument("Index to clone out of range");
    else{
      return *Clone(objects.begin()+idx);
    }
  }

 private:
#ifndef _NO_BOOST_POOL_
  boost::object_pool<ObjectType> pool;
#endif
 public:
  CloneVector(){}

  ObjectType* alloc(const ObjectType& ob){
#ifdef _NO_BOOST_POOL_
    return new ObjectType(ob);
#else
    return pool.construct(ob);
#endif
  }

  void dealloc(ObjectType* ob){
#ifdef _NO_BOOST_POOL_
    delete ob;
#else
    pool.free(ob);
#endif
  }

  ObjectType* Clone(typename std::vector<const ObjectType*>::const_iterator ii){
    int pos=ii-objects.begin();
    ObjectType** ob=&clone_objects_ptr[pos];
    if(*ob) return *ob;
    else{
      *ob=alloc(**ii);
      objects[pos]=*ob;
      return *ob;
    }
  }

  typename std::vector<const ObjectType*>::iterator
  AddClone(const ObjectType *ob,ObjectType** obd){
    ObjectType* obc=alloc(*ob);
    clone_objects_ptr.push_back(obc);
    objects.push_back(obc);
    *obd=obc;
    return (objects.end()-1);
  }

  void Add(const ObjectType* ob){
    objects.push_back(ob);
    clone_objects_ptr.push_back(0);
  }

  void Clear(){
    objects.clear();
    for(typename std::vector<ObjectType*>::iterator ii=clone_objects_ptr.begin();
        ii!=clone_objects_ptr.end();++ii){
      if(!*ii) continue;
#ifdef _NO_BOOST_POOL_
      delete *ii;
#else
      pool.free(*ii);
#endif
    }
    clone_objects_ptr.clear();
  }

  //  void Remove(typename std::vector<const ObjectType*>::iterator ii){
  //    int pos=ii-objects.begin();
  //   objects.erase(ii);
  //   clone_objects_ptr.erase(clone_objects_ptr.begin()+pos);
  // }

  typename std::vector<const ObjectType*>::const_iterator begin()const{ return objects.begin(); }
  typename std::vector<const ObjectType*>::const_iterator end()const{ return objects.end(); }

  typename std::vector<const ObjectType*>::iterator begin(){ return objects.begin(); }
  typename std::vector<const ObjectType*>::iterator end(){ return objects.end(); }

 private:
  std::vector<const ObjectType*> objects;
  std::vector<ObjectType*> clone_objects_ptr;
};

template<class ObjType>
class ObjectFilter{
 protected:
  bool mModifies;
  Event::Data *mEv;
 public:
  ObjectFilter(){}
  virtual ~ObjectFilter(){}
  void Init(Event::Data & ev){ mEv=&ev; }
  virtual bool Apply(ObjType* ob){
    std::string e_str="Error: Invalid ObjectFilter.\n";
    e_str+="Probably you have not correctly set mModifies.";
    throw std::invalid_argument(e_str);
  }

  virtual bool Apply(const ObjType* ob){
    std::string e_str="Error: Invalid ObjectFilter.\n";
    e_str+="Probably you have not correctly set mModifies.";
    throw std::invalid_argument(e_str);
  }
  virtual std::ostream& Description(std::ostream & ostrm) =0;
  bool Modifies(){
    return mModifies;
  }

};

template<class ObjType>
std::ostream& operator << (std::ostream& ostrm, ObjectFilter<ObjType>& m) {
  return m.Description(ostrm);
}

template <class ObjectType>
class ObjectProcessor{
 public:
  ObjectProcessor(): mModifies(false),mEnabled(false){};
  void AddFilters(const std::vector<std::pair<std::string,
                  Compute::ObjectFilter<ObjectType>*> > & filters,
                  const std::string & name){
    for(typename std::vector<std::pair<std::string,
            Compute::ObjectFilter<ObjectType>* > >::const_iterator it
            = filters.begin();
        it!= filters.end();
        ++it){
      if(it->first == name) Add(it->second);
    }
  }

  ~ObjectProcessor(){}

  void Add(ObjectFilter<ObjectType> *filter);
  void Init();
  bool Modifies(){
    if(!mEnabled){
      Init();
      mEnabled=true;
    }
    return mModifies;
  }
  bool Apply(const ObjectType* ob);
  bool Apply(ObjectType* ob);
  bool Enabled(){return (mFilters.size()>0);}
 private:
  std::vector<ObjectFilter<ObjectType>*> mFilters;
  bool mModifies;
  bool mEnabled;
};

template<class ObjectType>
inline void ObjectProcessor<ObjectType>::Add(ObjectFilter<ObjectType> *filter){
  mFilters.push_back(filter);
}

template<class ObjectType>
inline void ObjectProcessor<ObjectType>::Init(){
  for(typename std::vector< ObjectFilter < ObjectType > * > ::iterator ii=mFilters.begin();
      ii!=mFilters.end();
      ++ii){
    if((*ii)->Modifies()){
      mModifies=true;
      break;
    }
  }
  mEnabled=(mFilters.size()>0);
}

template<class ObjectType>
inline bool ObjectProcessor<ObjectType>::Apply(ObjectType* ob){
  for(typename std::vector<ObjectFilter<ObjectType>*>::iterator ii=mFilters.begin();
      ii!=mFilters.end();
      ++ii){
    if(!(*ii)->Modifies()){
      // We need to cast to const to make sure the right overloaded virtual is called
      if(!(*ii)->Apply((const ObjectType*)ob)) return false;
    }
    else{
      if(!(*ii)->Apply(ob)) return false;
    }
  }
  return true;
}

template<class ObjectType>
inline bool ObjectProcessor<ObjectType>::Apply(const ObjectType* ob){
  for(typename std::vector<ObjectFilter<ObjectType>*>::iterator ii=mFilters.begin();
      ii!=mFilters.end();
      ++ii){
    if(!(*ii)->Apply(ob)) return false;
  }
  return true;
}


}
#endif
