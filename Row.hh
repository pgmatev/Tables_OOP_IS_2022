#ifndef ROW_HH
#define ROW_HH

#include <vector>

#include "IntegerType.hh"
#include "FloatType.hh"
#include "StringType.hh"
#include "CurrencyType.hh"

class Row
{
private:
    std::vector<Type*> cells;
public:
    Row();
    Row(std::vector<Type*> cells);
    std::vector<Type*>& getCells();
    Type* validateCell(std::string& str);
};

#endif