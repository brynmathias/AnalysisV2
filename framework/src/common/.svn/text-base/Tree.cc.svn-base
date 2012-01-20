/*! \file Tree.cc
 * \brief Source code for the Operation::Tree class
 */

#include "Tree.hh"
#include "Operation.hh"
#include "EventData.hh"
#include <stdexcept>
#include <iostream>

namespace Operation {

  //=====================================
  // Operation Chain class implementation
  //=====================================
  Tree::Tree(const std::string & name) :
    mName(name) {
    mFormat = "JSON";
  }

  Tree::~Tree() {}

  void Tree::Start(Event::Data & ev) {
    for ( std::vector<Operation::Tree::Data>::iterator i = mData.begin();
	  i != mData.end();
	  ++i ) {
      i->op->Start(ev);
      Tree::Start(ev, i->tBranch);
      Tree::Start(ev, i->fBranch);
    }
  }

  void Tree::End(Event::Data & ev) {
    for ( std::vector<Operation::Tree::Data>::iterator i = mData.begin();
	  i != mData.end();
	  ++i ) {
      i->op->End(ev);
      Tree::End(ev, i->tBranch);
      Tree::End(ev, i->fBranch);
    }
  }

  void Tree::Start(Event::Data & ev,
		   std::vector<Operation::Tree::Data> & tree) {
    for ( std::vector<Operation::Tree::Data>::iterator i = tree.begin();
	  i != tree.end();
	  ++i ) {
      i->op->Start(ev);
      Tree::Start(ev, i->tBranch);
      Tree::Start(ev, i->fBranch);
    }
  }
  
  void Tree::End(Event::Data & ev,
		 std::vector<Operation::Tree::Data> & tree) {
    for ( std::vector<Operation::Tree::Data>::iterator i = tree.begin();
	  i != tree.end();
	  ++i ) {
      i->op->End(ev);
      Tree::End(ev, i->tBranch);
      Tree::End(ev, i->fBranch);
    }
  }

  void Tree::SetFormat(std::string & format) {
    mFormat = format;
  }

  void Tree::Attach(Operation::_Base * op) {
    // Safety check so operations aren't used twice
    if ( GetOperation(mData,
		      op) != 0 ) {
      throw std::invalid_argument("Operation is already in use");
    }
    // Construct data structure
    Operation::Tree::Data tD;
    tD.tNG = 0.0;
    tD.tN = 0;
    tD.fNG = 0.0;
    tD.fN = 0;
    tD.op = op;
    // Push onto root
    mData.push_back(tD);
  }

  void Tree::TAttach(Operation::_Base * parent,
		     Operation::_Base * child) {
    // Safety check so operations aren't used twice
    if ( GetOperation(mData,
		      child) != 0 ) {
      throw std::invalid_argument("Child is already in use");
    }
    // Find the parent
    Operation::Tree::Data * parentData = GetOperation(mData,
						      parent);
    if ( parentData == 0 ) {
      throw std::invalid_argument("Parent isn't attached");
    }
    // Construct data structure
    Operation::Tree::Data tD;
    tD.tNG = 0.0;
    tD.tN = 0;
    tD.fNG = 0.0;
    tD.fN = 0;
    tD.op = child;
    // Push back onto tree
    parentData->tBranch.push_back(tD);
  }

  void Tree::FAttach(Operation::_Base * parent,
		     Operation::_Base * child) {
    // Safety check so operations aren't used twice
    if ( GetOperation(mData,
		      child) != 0 ) {
      throw std::invalid_argument("Child is already in use");
    }
    // Find the parent
    Operation::Tree::Data * parentData = GetOperation(mData,
						      parent);
    if ( parentData == 0 ) {
      throw std::invalid_argument("Parent isn't attached");
    }
    // Construct data structure
    Operation::Tree::Data tD;
    tD.tNG = 0.0;
    tD.tN = 0;
    tD.fNG = 0.0;
    tD.fN = 0;
    tD.op = child;
    // Push back onto tree
    parentData->fBranch.push_back(tD);
  }

  void Tree::Reset() {
    // Invoke the helper function at root
    Tree::Reset(mData);
  }

  void Tree::Reset(std::vector<Operation::Tree::Data> & tree) {
    for ( std::vector<Operation::Tree::Data>::iterator i = tree.begin();
	  i != tree.end();
	  ++i ) {
      i->tNG = 0.0;
      i->tN = 0;
      i->fNG = 0.0;
      i->fN = 0;
      // Recursive calls
      Tree::Reset(i->tBranch);
      Tree::Reset(i->fBranch);
    }
  }

  Operation::Tree::Data * Tree::GetOperation(std::vector<Operation::Tree::Data> & tree,
					     Operation::_Base * op) const {
    Operation::Tree::Data * ptr = 0;
    for ( std::vector<Operation::Tree::Data>::iterator i = tree.begin();
	  i != tree.end();
	  ++i ) {
      if ( op == i->op ) return &*i;
      // Recursive calls
      ptr = GetOperation(i->tBranch,
			 op);
      if ( ptr != 0 ) return ptr;
      ptr = GetOperation(i->fBranch,
			 op);
      if ( ptr != 0 ) return ptr;
    }
    return ptr;
  }

  void Tree::Process(Event::Data & ev) {
    for ( std::vector<Operation::Tree::Data>::iterator i = mData.begin();
	  i != mData.end();
	  ++i ) {
      // Debug info for the moment
      //std::cout << std::hex << "Operation 0x" << i->op << std::endl;
      if ( i->op->Process(ev) ) {
	// Increment the event weight for this branch
	i->tNG += ev.GetEventWeight();
  i->tN += 1;
	// Begin the true branch calls
	Tree::Process(ev,
		      i->tBranch);
      } else {
	i->fNG += ev.GetEventWeight();
  i->fN += 1;
	// Begin the true branch calls
	Tree::Process(ev,
		      i->fBranch);
      }
    }
  }

  void Tree::Process(Event::Data & ev,
		     std::vector<Operation::Tree::Data> & tree) {
    for ( std::vector<Operation::Tree::Data>::iterator i = tree.begin();
	  i != tree.end();
	  ++i ) {
      // Debug info for the moment
      //std::cout << std::hex << "Operation 0x" << i->op << std::endl;
      if ( i->op->Process(ev) ) {
	// Increment the event weight for this branch
	i->tNG += ev.GetEventWeight();
  i->tN += 1;
	// Begin the true branch calls
	Tree::Process(ev,
		      i->tBranch);
      } else {
	i->fNG += ev.GetEventWeight();
  i->fN += 1;
	// Begin the true branch calls
	Tree::Process(ev,
		      i->fBranch);
      }
    }
  }

  // Status report helper function
  void Tree::Report(std::ostream & ostrm,
		    Operation::Tree::Data const & tree,
		    unsigned int level,
        bool isEnd,
        std::string format) const {
    if (format == "text") {
      // Do indentation
      for ( unsigned int i = 0 ;
            i != level ;
            i++ ) {
        ostrm << " ";
      }
      // Operation
      ostrm << *(tree.op)
            << "[T="
            << tree.tNG
            << ", F="
            << tree.fNG
            << "]"
            << std::endl;
      if ( tree.tBranch.size() != 0 ) {
        for ( unsigned int i = 0 ;
              i != level ;
              i++ ) {
          ostrm << " ";
        }
        ostrm << "T:" << endl;
      }
      // Loop over true branches
      for ( std::vector<Operation::Tree::Data>::const_iterator i = tree.tBranch.begin();
            i != tree.tBranch.end();
            ++i ) {
        Tree::Report(ostrm,
                     *i,
                     level+1,
                     true,
                     format);
      }
      if ( tree.fBranch.size() != 0 ) {
        for ( unsigned int i = 0 ;
              i != level ;
              i++ ) {
          ostrm << " ";
        }
        ostrm << "F:" << endl;
      }
      // Loop over false branches
      for ( std::vector<Operation::Tree::Data>::const_iterator i = tree.fBranch.begin();
            i != tree.fBranch.end();
            ++i ) {
        Tree::Report(ostrm,
                     *i,
                     level+1,
                     true,
                     format);
      }
    } else {
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      // Operation
      ostrm << "\"" << *(tree.op) << "\" : " << std::endl; 
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      ostrm << "{" << std::endl;
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      double efficiency = (tree.tNG + tree.fNG) > 0 ? tree.tNG/(tree.tNG + tree.fNG) : 0; 
      ostrm << "  \"efficiency\" : " << efficiency << "," << std::endl;
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      ostrm << "  \"T\" : " << tree.tNG << "," << std::endl;
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      double eT = tree.tN > 0 ? tree.tNG/sqrt(1.*tree.tN) : 0;
      ostrm << "  \"eT\" : " << eT << "," << std::endl;
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      ostrm << "  \"F\" : " << tree.fNG << "," << std::endl;
      for ( unsigned int j = 0 ;
      j != level+2 ;
      j++ ) {
        ostrm << "  ";
      }
      double eF;
      eF = tree.fN > 0 ? tree.fNG/sqrt(1.*tree.fN) : 0;
      ostrm << "  \"eF\" : " << eF;// << "," << std::endl;
      if (isEnd) {
        ostrm << "," << std::endl;
      } else {
        ostrm << std::endl;
      }
      // Loop over true branches
      std::vector<Operation::Tree::Data>::const_iterator last;
      std::vector<Operation::Tree::Data>::const_iterator lastf;
      last = tree.tBranch.end();
      last--;
      for ( std::vector<Operation::Tree::Data>::const_iterator i = tree.tBranch.begin();
      i != tree.tBranch.end();
      ++i ) {
        Tree::Report(ostrm,
         *i,
         level+1,
         (*i).tBranch.size() > 0,
         format);
        for ( unsigned int j = 0 ;
        j != level+3 ;
        j++ ) {
          ostrm << "  ";
        }
        if (i != last || tree.fBranch.size() > 0) {
          ostrm << "}," << std::endl;
        } else {
          ostrm << "}" << std::endl; 
        }
      }
      // Loop over false branches
      lastf = tree.fBranch.end();
      lastf--;
      for ( std::vector<Operation::Tree::Data>::const_iterator i = tree.fBranch.begin();
      i != tree.fBranch.end();
      ++i ) {
        Tree::Report(ostrm,
         *i,
         level+1,
         (*i).fBranch.size() > 0,
         format);
        for ( unsigned int j = 0 ;
        j != level+3 ;
        j++ ) {
          ostrm << "  ";
        }
        if (i != lastf) {
          ostrm << "}," << std::endl;
        } else {
          ostrm << "}" << std::endl;
        }
      }
    }
  }

  // Status output
  std::ostream & operator << (std::ostream & ostrm,
			      Operation::Tree const & m) {
    if (m.mFormat == "text") {
      ostrm << "Tree name: "
        << m.mName
        << std::endl;
    } else {
      ostrm << "  \"Cut Flow\" : " << std::endl;
      ostrm << "  {" << std::endl;
      ostrm << "    \"Tree Name\" : \"" << m.mName << "\"," << std::endl;
    }
    // Loop over the root branches and report
    for ( std::vector<Operation::Tree::Data>::const_iterator i = m.mData.begin();
	  i != m.mData.end();
	  ++i ) {
      m.Report(ostrm,
	       *i,
	       0,
         true,
         m.mFormat);
    }
    
    if (m.mFormat != "text") {
      ostrm << "    }" << std::endl;
      ostrm << "  }" << std::endl;
    }

    return ostrm;
  }

} // ~namespace Operation
