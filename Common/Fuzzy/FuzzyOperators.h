#ifndef FUZZY_OPERATORS_H
#define FUZZY_OPERATORS_H
//-----------------------------------------------------------------------------
//
//  Name:   FuzzyOperators.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   classes to provide the fuzzy AND and OR operators to be used in
//          the creation of a fuzzy rule base
//-----------------------------------------------------------------------------
#include <vector>
#include <cassert>
#include "misc/utils.h"
#include "FuzzyTerm.h"

///////////////////////////////////////////////////////////////////////////////
//
//  a fuzzy AND operator class
//
///////////////////////////////////////////////////////////////////////////////
class FzAND : public FuzzyTerm
{
private:

  //an instance of this class may AND together up to 4 terms
  std::vector<FuzzyTerm*> m_Terms;

  //disallow assignment
  FzAND& operator=(const FzAND&) = delete;

public:

  ~FzAND();

  //copy ctor
  FzAND(const FzAND& fa);
   
  //ctors accepting fuzzy terms.
  FzAND(const FuzzyTerm& op1, const FuzzyTerm& op2);
  FzAND(const FuzzyTerm& op1, const FuzzyTerm& op2, const FuzzyTerm& op3);
  FzAND(const FuzzyTerm& op1, const FuzzyTerm& op2, const FuzzyTerm& op3, const FuzzyTerm& op4);

  //virtual ctor
  FuzzyTerm* Clone()const{return new FzAND(*this);}
  
  double GetDOM()const;
  void  ClearDOM();
  void  ORwithDOM(double val);
};


///////////////////////////////////////////////////////////////////////////////
//
//  a fuzzy OR operator class
//
///////////////////////////////////////////////////////////////////////////////
class FzOR : public FuzzyTerm
{
private:

  //an instance of this class may AND together up to 4 terms
  std::vector<FuzzyTerm*> m_Terms;

  //no assignment op necessary
  FzOR& operator=(const FzOR&);

public:

  ~FzOR();

  //copy ctor
  FzOR(const FzOR& fa);
   
  //ctors accepting fuzzy terms.
  FzOR(const FuzzyTerm& op1, const FuzzyTerm& op2);
  FzOR(const FuzzyTerm& op1, const FuzzyTerm& op2, const FuzzyTerm& op3);
  FzOR(const FuzzyTerm& op1, const FuzzyTerm& op2, const FuzzyTerm& op3, const FuzzyTerm& op4);

  //virtual ctor
  FuzzyTerm* Clone()const{return new FzOR(*this);}
  
  double GetDOM()const;

  //unused
  void ClearDOM(){assert(0 && "<FzOR::ClearDOM>: invalid context");}
  void ORwithDOM(double val){assert(0 && "<FzOR::ORwithDOM>: invalid context");}
};



#endif

