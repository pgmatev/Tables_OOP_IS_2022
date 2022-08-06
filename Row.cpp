#include "Row.hh"

Row::Row() : cells(Vector<Type*>())
{}

Row::Row(Vector<Type*> cells)
{
    this->cells = cells;
}

Vector<Type*> Row::getCells()
{
    return this->cells;
}