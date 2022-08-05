#include "Row.hh"

Row::Row()
{
    this->cells = new Vector<Type*>();
}

Row::Row(Vector<Type*> cells)
{
    this->cells = cells;
}