#ifndef TABLE_HH
#define TABLE_HH

#include <fstream>

#include "Row.hh"


class Table
{
private:
    std::vector<Row> rows;
public:
    Table(std::vector<Row> rows);
    Table();
    Table(std::ifstream& file);
    std::vector<Row>& getRows();
    std::string& clean(std::string& str);
    void print();
};

#endif