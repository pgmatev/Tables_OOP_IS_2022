#include "Row.hh"

Row::Row()
{}

Row::Row(std::vector<Type*> cells) : cells(cells)
{}

std::vector<Type*>& Row::getCells()
{
    return this->cells;
}

Type* Row::validateCell(std::string& str)
{
    if (str.empty())
    {
        return nullptr;
    }
    Type* it = new IntegerType(str);
    if (it->validate())
    {
        return it;
    }
    Type* ft = new FloatType(str);
    if (ft->validate())
    {
        return ft;
    }
    Type *ct = new CurrencyType(str);
    if (ct->validate())
    {
        return ct;
    }
    Type* st = new StringType(str);
    if (st->validate())
    {
        return st;
    }
    return nullptr;
}