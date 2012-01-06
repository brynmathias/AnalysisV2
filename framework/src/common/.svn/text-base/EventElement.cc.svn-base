#/*! \file EventElement.cc
 * \brief Wrapper for ROOT leaf access to make them safe
 */

#include "EventElement.hh"
#include "ICF_NtupleData.hh"
#include <stdexcept>
#include <sstream>
#include <TLeaf.h>
#include "Types.hh"

namespace Event {

  _Element::~_Element() {
    bool print_branches_to_keep = false;
    if ( print_branches_to_keep && !mName.empty() ) {
      std::cout << "\" keep " << mName << " \"," << std::endl;
    }
  }

  template<typename T, typename ND>
  Element<T, ND>::Element(TTree *source,
          std::string const & name,
          ND *ntupleData) :
      _Element(name),
      mNtupleData(ntupleData){
    mNtupleData->Register(this);
    // Map to the branch
    mBranch = source->GetBranch(name.c_str());
    if ( mBranch == 0 ) {
      std::string tStr;
      tStr = "Branch '" + name + "' does not exist. Disabling.";
      std::cerr << tStr <<std::endl;
      mEnabled=false;
      return;
    }
    // Do this the way it was meant to be done
    // First we get the leaf list and make sure
    // it's one leaf to the branch
    TObjArray *leaves = mBranch->GetListOfLeaves();
    if ( leaves->GetEntries() != 1 ) {
      std::string tStr;
      tStr = "More than one leaf in branch " + name;
      throw std::invalid_argument(tStr);
    } else if ( leaves->GetEntries() == 0 ) {
      std::string tStr;
      tStr = "No leaves in branch " + name;
      throw std::invalid_argument(tStr);
    }

    // We have one leaf, so now get the leaf reference
    TLeaf *leaf = reinterpret_cast<TLeaf *>(leaves->At(0));
    if ( leaf->GetLeafCount() != 0 ) {
      // Non-fixed leaf size
      std::string tStr;
      tStr = "Non-fixed leaf size for " + name;
      throw std::invalid_argument(tStr);
    }

    // Check the leaf size matches the size of the type

    // This doesn't work for pointer types
     /* if ( (leaf->GetLen() * leaf->GetLenType()) != sizeof(T)) {
      std::string tStr;
      std::stringstream a, b;
      a << std::dec << sizeof(T);
      b << std::dec << leaf->GetLen() * leaf->GetLenType();
      std::cout << leaf->GetLenType() << std::endl;
      std::cout << leaf->GetLen() << std::endl;
      tStr = "Leaf size for " + name + " is " + b.str();
      tStr += " while Element size is " + a.str();
      throw std::invalid_argument(tStr);
      }*/

    // Set the pointer reference
    mBranch->SetAddress(&mData);
    // Set cached index entry
    mCurrentEntry = (-1);
  }

  template<typename T, typename ND>
  Element<T, ND>::Element() :
      _Element(),
      mNtupleData(0)
  {;}

  template<typename T, typename ND>
  Element<T,ND>::Element( const Element<T,ND>& in ) {
    in.mNtupleData->Register(this);
    mNtupleData = in.mNtupleData;
    mBranch = in.mBranch;
    mCurrentEntry = in.mCurrentEntry;
    mData = in.mData;
    mEnabled = in.mEnabled;
    mName = in.mName;
    if(mEnabled) mBranch->SetAddress(&mData);
  }

  template<typename T, typename ND>
  Element<T,ND>& Element<T,ND>::operator= ( const Element<T,ND>& in ) {
    in.mNtupleData->Register(this);
    mNtupleData = in.mNtupleData;
    mBranch = in.mBranch;
    mCurrentEntry = in.mCurrentEntry;
    mData = in.mData;
    mEnabled = in.mEnabled;
    mName = in.mName;
    if(mEnabled) mBranch->SetAddress(&mData);
    return *this;
  }

  template<typename T, typename ND>
  const T & Element<T, ND>::operator() () const {
    if(!mEnabled){
      std::string e_str="Error accessing disabled branch: " + mName;
      throw std::invalid_argument(e_str);
    }
    if ( mNtupleData->GetCurrentEntry() != mCurrentEntry ) {
      mCurrentEntry = mNtupleData->GetCurrentEntry();
      // Force read of this entry
      Int_t ret = mBranch->GetEntry(mCurrentEntry, 1);
      if ( ret <= 0 ) {
  throw std::invalid_argument("Failed to get entry " + mName);
      }
    }
    // Return a const reference to the internal data member
    return mData;
  }

template<typename T, typename ND>
void Element<T,ND>::Reset() const{
  mBranch=mNtupleData->GetBranch(mName.c_str());
  mBranch->SetAddress(&mData);
  mCurrentEntry = (-1);
}


  template<typename T, typename ND>
  Element<T, ND>::~Element() {
    if(mNtupleData) mNtupleData->Unregister(this);
  }

  template<typename T, typename ND>
  Element<T*, ND>::Element(TTree *source,
          std::string const & name,
          ND *ntupleData) :
      _Element(name),
      mNtupleData(ntupleData)
  {
    mNtupleData->Register(this);
    mData=new T();
    // Map to the branch
    mBranch = source->GetBranch(name.c_str());

    if ( mBranch == 0 ) {
      std::string tStr;
      tStr = "Branch '" + name + "' does not exist. Disabling.";
      std::cerr << tStr <<std::endl;
      mEnabled=false;
      return;
    }
    // Do this the way it was meant to be done
    // First we get the leaf list and make sure
    // it's one leaf to the branch
    TObjArray *leaves = mBranch->GetListOfLeaves();
    if ( leaves->GetEntries() != 1 ) {
      std::string tStr;
      tStr = "More than one leaf in branch " + name;
      throw std::invalid_argument(tStr);
    } else if ( leaves->GetEntries() == 0 ) {
      std::string tStr;
      tStr = "No leaves in branch " + name;
      throw std::invalid_argument(tStr);
    }

    // We have one leaf, so now get the leaf reference
    TLeaf *leaf = reinterpret_cast<TLeaf *>(leaves->At(0));
    if ( leaf->GetLeafCount() != 0 ) {
      // Non-fixed leaf size
      std::string tStr;
      tStr = "Non-fixed leaf size for " + name;
      throw std::invalid_argument(tStr);
    }

    // Check the leaf size matches the size of the type

/*        if ( (leaf->GetLen() * leaf->GetLenType()) != sizeof(T)
  && (sizeof(T)==4  || sizeof(T)==8) {
    std::cout << leaf->GetTypeName() << std::endl;
    std::string tStr;
      std::stringstream a, b;
      a << std::dec << sizeof(T);
      b << std::dec << leaf->GetLen() * leaf->GetLenType();
      std::cout << leaf->GetLenType() << std::endl;
      std::cout << leaf->GetLen() << std::endl;
      tStr = "Leaf size for " + name + " is " + b.str();
      tStr += " while Element size is " + a.str();
      throw std::invalid_argument(tStr);
      }
      AS: Removed since it doesnt seem to work for composite types */
    // Set the pointer reference
    mBranch->SetAddress(&mData);
    // Set cached index entry
    mCurrentEntry = (-1);
  }

  template<typename T, typename ND>
  Element<T*, ND>::Element() :
      _Element(),
    mNtupleData(0),
    mData()
  {;}

  template<typename T, typename ND>
  Element<T*,ND>::Element( const Element<T*,ND>& in ) {
    in.mNtupleData->Register(this);
    mNtupleData = in.mNtupleData;
    mBranch = in.mBranch;
    mLeaf = in.mLeaf;
    mCurrentEntry = in.mCurrentEntry;
    mData = in.mData;
    mEnabled = in.mEnabled;
    mName = in.mName;
    if(mEnabled) mBranch->SetAddress(&mData);
  }

  template<typename T, typename ND>
  Element<T*,ND>& Element<T*,ND>::operator= ( const Element<T*,ND>& in ) {
    in.mNtupleData->Register(this);
    mNtupleData = in.mNtupleData;
    mBranch = in.mBranch;
    mLeaf = in.mLeaf;
    mCurrentEntry = in.mCurrentEntry;
    mData = in.mData;
    mEnabled = in.mEnabled;
    mName = in.mName;
    if(mEnabled) mBranch->SetAddress(&mData);
    return *this;
  }

  template<typename T, typename ND>
  const T* Element<T*, ND>::operator() () const {
    if(!mEnabled){
      std::string e_str="Error accessing disabled branch: " + mName;
      throw std::invalid_argument(e_str);
    }
    if ( mNtupleData->GetCurrentEntry() != mCurrentEntry ) {
      mCurrentEntry = mNtupleData->GetCurrentEntry();
      // Force read of this entry
      Int_t ret = mBranch->GetEntry(mCurrentEntry, 1);
      if ( ret <= 0 ) {
        std::cout << "At entry:" << mCurrentEntry << std::endl;
  throw std::invalid_argument("Failed to get entry " + mName);
      }
    }
    // Return a const reference to the internal data member
    return mData;
  }

template<typename T, typename ND>
void Element<T*,ND>::Reset() const
{
  mBranch=mNtupleData->GetBranch(mName.c_str());
  mBranch->SetAddress(&mData);
  mCurrentEntry = (-1);
}

  template<typename T, typename ND>
  Element<T*, ND>::~Element() {
    if(mNtupleData) mNtupleData->Unregister(this);
  }

  template<typename T, typename ND>
  Element<std::vector<T>, ND >::Element(TTree *source,
            std::string const & name,
            ND *ntupleData) :
      _Element(name),
      mNtupleData(ntupleData){
    mNtupleData->Register(this);
    // Map to the branch
    mBranch = source->GetBranch(name.c_str());
    if ( mBranch == 0 ) {
      std::string tStr;
      tStr = "Branch '" + name + "' does not exist";
      throw std::invalid_argument(tStr);
    }

    // Do this the way it was meant to be done
    // First we get the leaf list and make sure
    // it's one leaf to the branch
    TObjArray *leaves = mBranch->GetListOfLeaves();
    if ( leaves->GetEntries() != 1 ) {
      std::string tStr;
      tStr = "More than one leaf in branch " + name;
      throw std::invalid_argument(tStr);
    } else if ( leaves->GetEntries() == 0 ) {
      std::string tStr;
      tStr = "No leaves in branch " + name;
      throw std::invalid_argument(tStr);
    }
    // We have one leaf, so now get the leaf reference
    mLeaf = reinterpret_cast<TLeaf *>(leaves->At(0));
    if ( mLeaf->GetLeafCount() == 0 ) {
      // Fixed leaf size
      std::string tStr;
      tStr = "Fixed leaf size for " + name;
      throw std::invalid_argument(tStr);
    }

    // Get the size of the leaf array base type
    if ( mLeaf->GetLenType() != sizeof(T) ) {
      std::string tStr;
      std::stringstream a, b;
      a << std::dec << sizeof(T);
      b << std::dec << mLeaf->GetLenType();
      tStr = "Leaf basic type size for " + name + " is " + b.str();
      tStr += " while Element basic type size is " + a.str();
      throw std::invalid_argument(tStr);
    }

    std::cout << "Maximum array size for "
        << name
        << " is "
        << std::dec
        << mLeaf->GetLeafCount()->GetMaximum()
        << "("
        << sizeof(T)
        << ")"
        << std::endl;
    // Dimension the vector to be big enough
    // for the maximum size of the array
    mData.reserve(mLeaf->GetLeafCount()->GetMaximum());

    // Set the pointer reference
    // This is a little dodgy technically as there
    // isn't an absolute guarantee that STL in the future
    // won't fragment the vector memory into pieces
    // but by then this code will probably be forgotten :).
    mBranch->SetAddress(reinterpret_cast<char *>(&mData[0]));
    // Set cached index entry
    mCurrentEntry = (-1);
  }

  template<typename T, typename ND>
  Element<std::vector<T>, ND>::Element() :
      _Element(),
    mNtupleData(0)
  {;}

  template<typename T, typename ND>
  Element<std::vector<T>,ND>::Element( const Element<std::vector<T>,ND>& in ) {
    in.mNtupleData->Register(this);
    mNtupleData = in.mNtupleData;
    mBranch = in.mBranch;
    mLeaf = in.mLeaf;
    mCurrentEntry = in.mCurrentEntry;
    mData = in.mData;
    mEnabled = in.mEnabled;
    mName = in.mName;
    if(mEnabled) mBranch->SetAddress(&mData);
  }

  template<typename T, typename ND>
  Element<std::vector<T>,ND>& Element<std::vector<T>,ND>::operator= ( const Element<std::vector<T>,ND>& in ) {
    in.mNtupleData->Register(this);
    mNtupleData = in.mNtupleData;
    mBranch = in.mBranch;
    mLeaf = in.mLeaf;
    mCurrentEntry = in.mCurrentEntry;
    mData = in.mData;
    mEnabled = in.mEnabled;
    mName = in.mName;
    if(mEnabled) mBranch->SetAddress(&mData);
    return *this;
  }

  template<typename T, typename ND>
  const std::vector<T> & Element<std::vector<T>, ND >::operator() () const {
    if ( mNtupleData->GetCurrentEntry() != mCurrentEntry ) {
      mCurrentEntry = mNtupleData->GetCurrentEntry();
      // Force read of this entry
      Int_t ret = mBranch->GetEntry(mCurrentEntry, 1);
      if ( ret <= 0 ) {
  throw std::invalid_argument("Failed to get entry " + mName);
      }
      // Now we update the vector size
      // NB - not done yet, just let people iterate the old way
      //mData.resize(mLeaf->GetLen());
      //std::cout << "New size is " << std::dec << mLeaf->GetLen() << std::endl;
    }

    // Return a const reference to the internal data member
    return mData;
  }

template<typename T,typename ND>
void Element<std::vector<T>,ND>::Reset() const{
  mBranch=mNtupleData->GetBranch(mName.c_str());
  TObjArray *leaves = mBranch->GetListOfLeaves();
  mLeaf = reinterpret_cast<TLeaf *>(leaves->At(0));
  mData.reserve(mLeaf->GetLeafCount()->GetMaximum());
  mBranch->SetAddress(reinterpret_cast<char *>(&mData[0]));
  mCurrentEntry = (-1);
}

template<typename T, typename ND>
Element<std::vector<T>, ND >::~Element() {
  if(mNtupleData) mNtupleData->Unregister(this);
}

  //Need to explicitly instantiate every template class for both ntuple structures
  template class Element<unsigned int, ICF::NtupleData>;
  template class Element<signed int, ICF::NtupleData>;
  template class Element<double, ICF::NtupleData>;
  template class Element<float, ICF::NtupleData>;
  template class Element<bool, ICF::NtupleData>;
  template class Element<signed char, ICF::NtupleData>;
  template class Element<unsigned char, ICF::NtupleData>;
  template class Element<signed short, ICF::NtupleData>;
  template class Element<unsigned short, ICF::NtupleData>;

  template class Element<std::vector<double> , ICF::NtupleData>;
  template class Element<std::vector<unsigned int> , ICF::NtupleData>;
  template class Element<std::vector<signed int> , ICF::NtupleData>;
  template class Element<std::vector<float> , ICF::NtupleData>;
  template class Element<std::vector<signed char> , ICF::NtupleData>;
  template class Element<std::vector<unsigned char> , ICF::NtupleData>;
  template class Element<std::vector<signed short> , ICF::NtupleData>;
  template class Element<std::vector<unsigned short> , ICF::NtupleData>;
  template class Element<std::vector<TLorentzVector>* , ICF::NtupleData>;
  template class Element<std::vector<TLorentzVector> , ICF::NtupleData>;
  template class Element<TLorentzVector, ICF::NtupleData> ;
  template class Element<std::vector<bool>*, ICF::NtupleData>;
  template class Element<std::vector<unsigned>* , ICF::NtupleData>;
  template class Element<std::vector<double>*, ICF::NtupleData>;
  template class Element<std::vector<float>*, ICF::NtupleData>;
  template class Element<std::vector<int>*, ICF::NtupleData>;
  template class Event::Element<ICF_LorentzVs*, ICF::NtupleData>;
  template class Event::Element<ICF_LorentzV*, ICF::NtupleData>;
  template class Element<std::map<std::string,bool>*,ICF::NtupleData>;
  template class Element<std::map<std::string,int>*,ICF::NtupleData>;
  template class Element<ICF_XYZPoints*, ICF::NtupleData>;
  template class Element<ICF_XYZPoint*, ICF::NtupleData>;

// #ifdef _ICF2_
// In _ICF_ these clases are synonymous with the LorentzV equivalents
  template class Element<PolarLorentzV,ICF::NtupleData>;
  template class Element<PolarLorentzV*,ICF::NtupleData>;
  template class Element<std::vector<PolarLorentzV>,ICF::NtupleData>;
  template class Element<std::vector<PolarLorentzV>*,ICF::NtupleData>;
// #endif

  /*
  template class Element<double[3]>;
  template class Element<double[5]>;
  template class Element<bool[10]>;
  template class Element<double[10]>;
  template class Element<bool[13]>;
  template class Element<double[13]>;
  template class Element<float[13]>;
  template class Element<unsigned int[13]>;
  template class Element<bool[18]>;
  template class Element<double[18]>;
  template class Element<bool[50]>;
  template class Element<double[50]>;
  template class Element<signed int[159]>;
  template class Element<unsigned int[170]>;
  template class Element<signed int[170]>;
  template class Element<float[170]>;
  */

} // ~namespace Event
