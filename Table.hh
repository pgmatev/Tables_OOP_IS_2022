#ifndef TABLE_HH
#define TABLE_HH

#include <fstream>

#include "Row.hh"


class Table
{
private:
    std::vector<Row> rows;
    void resize();
    std::string& clean(std::string& str);

public:
    Table(std::vector<Row> rows);
    Table();
    Table(std::ifstream& file);
    std::vector<Row>& getRows();
    void print();
    void save(std::ofstream& file);
    void edit(std::string& str, int row, int col);
    void remove(int row, int col);
    Table subTable(int beg_row, int beg_col, int end_row, int end_col);
    Table subTable(std::vector<int> columns);
    // Table subTable(int a, std::function<bool(bool, bool)> func);
};

#endif