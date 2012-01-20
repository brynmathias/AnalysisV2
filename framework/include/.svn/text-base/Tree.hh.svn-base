/*! \file Tree.hh
 * \brief Header file for the Operation::Tree class
 */

#ifndef Tree_hh
#define Tree_hh

#include <iostream>
#include <vector>

namespace Event {
  class Data;
}

/*! \brief Namespace for all Operation-related code.
 * 
 */
namespace Operation {

  // Forward declaration
  class _Base;

  /*! \brief Abstract definition of an operation chain.
   * \author CMS SUSY analysis team
   * \author John Jones
   * \date June 2009
   * \version 2
   * This tree structure is deliberately only
   * partially-recursive as processors don't handle
   * recursive behaviour very well because of the stack load.
   * Modern hyper-pipelined processors are much better
   * at handling iterative coding as it allows them
   * to look ahead...
   */
  class Tree {

  public:
    /**
     * \brief Operation::Tree class constructor.
     */
    Tree(const std::string & name);

    /**
     * \brief Operation::Tree class destructor.
     */
    ~Tree();

  private:
    // Name of tree
    const std::string mName;
    std::string mFormat;

    // Data storage for tree
    struct Data {
      std::vector<Operation::Tree::Data> tBranch;
      std::vector<Operation::Tree::Data> fBranch;
      Operation::_Base * op;
      double tNG; // weighted number of events
      int tN; // absolute number of events
      double fNG;
      int fN;
    };
    std::vector<Operation::Tree::Data> mData;

  public:
    /**
     * \brief True attachment function
     * This one attaches to the root of
     * the tree structure.
     */
    void Attach(Operation::_Base * op);

    /**
     * \brief True attachment function
     * This one attaches to the positive branch of
     * the operation parent, so if the parent passes
     * true this operation will be executed.
     */
    void TAttach(Operation::_Base * parent,
		 Operation::_Base * child);

    /**
     * \brief False attachment function
     * This one attaches to the negative branch of
     * the operation parent, so if the parent passes
     * false this operation will be executed.
     */
    void FAttach(Operation::_Base * parent,
		 Operation::_Base * child);

    /**
     * \brief Reset function
     * Use to reset counters, etc...
     * Does not clear tree structure
     */
    void Reset();

    /**
     * \brief Main processing function
     * Process the event with the operation...
     * Returns true on success (cut passed),
     * false on failure.
     */
    void Process(Event::Data & ev);

    /**
     * \brief Main start function
     * Passes the start command to all branches
     */
    void Start(Event::Data & ev);
    void End(Event::Data & ev);

    void SetFormat(std::string & format);
    std::string GetFormat() {return mFormat;}
  private:
    // Helper function to start
    void Start(Event::Data & ev,
	       std::vector<Operation::Tree::Data> & tree);

    // Helper function to end
    void End(Event::Data & ev,
	     std::vector<Operation::Tree::Data> & tree);

    // Helper function to clear weights
    void Reset(std::vector<Operation::Tree::Data> & tree);

    // Helper function for processing
    void Process(Event::Data & ev,
		 std::vector<Operation::Tree::Data> & tree);

    // Get a parent reference from it's unique operation pointer
    Operation::Tree::Data * GetOperation(std::vector<Operation::Tree::Data> & tree,
					 Operation::_Base * parent) const;

    // Status reporting helper function
    void Report(std::ostream & ostrm,
		Operation::Tree::Data const & tree,
		unsigned int level,
    bool isEnd,
    std::string format) const;

    // Declare streamer as friend
    friend std::ostream & Operation::operator << (std::ostream & ostrm,
						  Operation::Tree const & m);
    
  }; // ~Tree class

  // Status reporting for chain
  std::ostream & operator << (std::ostream & ostrm,
			      Operation::Tree const & m);

} // ~ namespace Operation

#endif //~Tree_hh
