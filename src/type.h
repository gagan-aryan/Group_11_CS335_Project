#ifndef TYPE_H
#define TYPE_H

#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;

enum TypeClass {
  NULL_TYPE,
  DEFINED_TYPE,  // int, float, string are predefined types
  ARRAY_TYPE,
  STRUCT_TYPE,
  FUNCTION_TYPE,
  POINTER_TYPE
};

// All type classes inherit from this class
struct Type {
  virtual string getType();
  virtual Type* copy();
  virtual string getname();
  Type* next = NULL;	// type linked list
  bool cons = false;	//const or not		
  TypeClass typeClass = NULL_TYPE;
};

struct DefinedType : Type {
  string basename;
  string getType();
  DefinedType(string basename);
  Type* copy();
};

struct ArrayType : Type {
  int arrayLength;
  Type* elementType;

  string getType();
  ArrayType(int, Type*);
  Type* copy();
};

struct StructType : Type {
  string structName;
  umap<string, Type*> memberTypes;

  string getType();
  StructType(string, umap<string, Type*>);
  Type* copy();
};

struct FunctionType : Type {
  Type* returnType;
  Type* argTypeList
  /*
  vector<Type*> rettype;
  
  vector<Type*> argtype;  
  vector<int> argtype_num;
  */
  string argtype;
  string rettype
  
  string getType();
  FunctionType(Type*, Type*);
  FunctionType(string, string);
  int fcn_addtype(string);
  Type* copy();
};

struct PntrType : Type {
  Type* baseType;  // int* -> int
  string getType();
  PntrType(Type*);
  Type* copy();

};

#endif
