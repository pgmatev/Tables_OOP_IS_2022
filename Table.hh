#ifndef TABLE_HH
#define TABLE_HH

#include "Row.hh"


class Table
{
private:
    Vector<Row> rows;
public:
    Table(Vector<Row> rows);

    Vector<Row> getRows();
};

#endif