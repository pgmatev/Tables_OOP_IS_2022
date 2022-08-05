#include "Table.hh"

Table::Table(Vector<Row> rows)
{
    this->rows = rows;
}

Vector<Row> Table::getRows()
{
    return this->rows;
}