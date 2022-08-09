#ifndef ROW_HH
#define ROW_HH

#include <vector>
#include <stdexcept>

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
    Type* validateCell(std::string& str, int row_count, int col_count);
};

#endif