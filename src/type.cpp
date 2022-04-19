#include "type.h"
using namespace std;

string Type::getType() {
  cout << "VIRTUAL FUNCTION OF TYPE NOT OVERLOADED!!" << endl;
  exit(1);
  return "";
}

Type* Type::copy() {
  cout << "VIRTUAL FUNCTION OF TYPE NOT OVERLOADED!!" << endl;
  exit(1);
  return NULL;
}

DefinedType::DefinedType(string _basename) {
  this->basename = _basename;
  this->typeClass = DEFINED_TYPE;
}

string DefinedType::getType() {
  return basename;  // int, float , ...
}

Type* DefinedType::copy() { return (new DefinedType(*this)); }

ArrayType::ArrayType(int _arrayLength, Type* _elementType) {
  this->arrayLength = _arrayLength;
  this->elementType = _elementType;
  this->typeClass = ARRAY_TYPE;
}

string ArrayType::getType() {
  // "[" ArrayLength "]" ElementType
  // e.g. [10]int, [10][11]int
  return "[" + to_string(arrayLength) + "]" + elementType->getType();
}

Type* ArrayType::copy() { return (new ArrayType(*this)); }

StructType::StructType(string _name, umap<string, Type*> _typeList) {
  this->structName = _name;
  this->memberTypes = _typeList;
  this->typeClass = STRUCT_TYPE;
}

string StructType::getType() {
  // structName { name1 : type, name2 : type, ...}
  // e.g. Type { getType: string(), copy: Type*(), .. }
  string structTypeName;
  structTypeName += structName;
  structTypeName += "{";
  for (auto& [name, type] : memberTypes) {
    structTypeName += name;
    structTypeName += ":";
    structTypeName += type->getType();
    structTypeName += ",";  // weird comma at the end, Sorry!
  }
  structTypeName += "}";
  return structTypeName;
}

Type* StructType::copy() { return (new StructType(*this)); }

FunctionType::FunctionType(Type* _returnType, Type* _argTypeList) {
  this->returnType = _returnType;
  this->argTypeList = _argTypeList;
  this->typeClass = FUNCTION_TYPE;
}

string FunctionType::getType() {
  // returnType( argType1, argType2, ....)
  string funcTypeName;
  funcTypeName += returnType->getType();
  funcTypeName += "(";
  Type* temp = argTypeList;
  while (temp != NULL) {
    funcTypeName += temp->getType();
    temp = temp->next;
  }
  funcTypeName += ")";

  return funcTypeName;
}

Type* FunctionType::copy() { return (new FunctionType(*this)); }

PntrType::PntrType(Type* _baseType) {
  this->baseType = _baseType;
  this->typeClass = POINTER_TYPE;
}

string PntrType::getType() {
  // baseType*
  return baseType->getType() + "*";
}

Type* PntrType::copy() { return (new PntrType(*this)); }