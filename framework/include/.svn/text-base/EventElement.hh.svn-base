/*! \file Element.hh
 * \brief Header file for the thread-safe ROOT data element template
 */

#ifndef ELEMENT_HH
#define ELEMENT_HH

#include <TTree.h>
#include <string>
#include <vector>

#include <Ntuple.hh>

#define USE_STL_VECTORS 1

/*! \brief Namespace for all event-related code.
 *
 */
namespace Event {

class _Element{
 public:
  _Element(const std::string & name):
      mEnabled(true),
      mName(name),
      mBranch(0),
      mLeaf(0),
      mCurrentEntry(-1)
  {}
  _Element():
      mEnabled(true),
      mName(),
      mBranch(0),
      mLeaf(0),
      mCurrentEntry(-1){}
  virtual ~_Element();
  virtual void Reset() const =0;
  bool enabled() const { return mEnabled; }
  const std::string & GetName() const{ return mName; }
 protected:
  bool mEnabled;
  std::string mName;
  mutable TBranch * mBranch;
  mutable TLeaf *mLeaf;
  mutable UInt_t mCurrentEntry;
};


  template<typename T, typename ND>
  class Element : public _Element{
  public:
    Element(TTree *source,
	    std::string const & name,
	    ND *ntupleData);
    Element();
    Element( const Element<T,ND>& );
    Element<T,ND>& operator= ( const Element<T,ND>& );
    ~Element();
    const T & operator() () const;
    virtual void Reset() const;
  private:
    ND* mNtupleData;
    mutable T mData;
  };

  // Specialise for dynamically-sized arrays
  template<typename T, typename ND>
  class Element<std::vector<T>, ND > : public _Element {
  public:
    Element(TTree *source,
	    std::string const & name,
	    ND *ntupleData);
    Element();
    Element( const Element<std::vector<T>,ND>& );
    Element<std::vector<T>,ND>& operator= ( const Element<std::vector<T>,ND>& );
    ~Element();
    const std::vector<T> & operator() () const;
    virtual void Reset() const;
  private:
    ND* mNtupleData;
    mutable std::vector<T> mData;
  };

  template<typename T, typename ND>
  class Element<T*, ND> : public _Element{
  public:
    Element(TTree *source,
	    std::string const & name,
	    ND *ntupleData);
    Element( const Element<T*,ND>& );
    Element<T*,ND>& operator= ( const Element<T*,ND>& );
    Element();
    ~Element();
    const T*  operator() () const;
    virtual void Reset() const;
  private:
    ND* mNtupleData;
    mutable T* mData;
  };

} // ~namespace Event

#endif //~ELEMENT_HH
