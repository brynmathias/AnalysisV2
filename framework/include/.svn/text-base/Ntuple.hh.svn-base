#ifndef NTUPLE_HH
#define NTUPLE_HH

#if defined(_NT7_)
#error "NT7 is long dead. You need to come to terms with that."
#endif

#if !defined(_ICF2_) && !defined(_ICF_)
#error "Freaking out. Ntuple format not defined. Add NTUPLE_TYPE = _ICF_ (for ICF > 2011) or NTUPLE_TYPE = _ICF2_ (for ICF < 2011) to beginning of your config.inc file."
#endif



#if defined(_ICF2_) && defined(_ICF_)
#error "More than one ntuple type defined. Please fix."
#endif

// Use these for ICF Ntuples
namespace ICF{
class NtupleData;
}

#if defined(_ICF2_)
#warning "Compiling for ICFv2 format ntuples."
typedef ICF::NtupleData ND_CLASS;
#define NT_DIRNAME "susyTree"
#define NT_TREENAME "tree"
#define NT_FORMAT "ICF"
#define NT_VERSION 2
#endif

#if defined(_ICF_)
typedef ICF::NtupleData ND_CLASS;
#define NT_DIRNAME "susyTree"
#define NT_TREENAME "tree"
#define NT_FORMAT "ICF"
#define NT_VERSION 3
#endif

#endif
