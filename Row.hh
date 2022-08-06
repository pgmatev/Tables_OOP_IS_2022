#ifndef ROW_HH
#define ROW_HH

#include "Vector.hh"
#include "IntegerType.hh"
#include "FloatType.hh"
#include "StringType.hh"
#include "FloatType.hh"

class Row
{
private:
    Vector<Type*> cells;
public:
    Row();
    Row(Vector<Type*> cells);
    Vector<Type*> getCells();
};

#endif