#include "Table.hh"

#include <iostream>

int main()
{
    // std::string str = "123"; 
    // std::string str1 = "456";
    // std::string str2 = "-0.456";
    // std::string str3 = "Hel\"lo";
    // std::string str4 = "$ 200.00";
    // Type* it = new IntegerType(str);
    // Type* it1 = new IntegerType(str1);
    // Type* it2 = new FloatType(str2);
    // Type* it3 = new StringType(str3);
    // Type* it4 = new CurrencyType(str4);
    // Row r1;
    // r1.getCells().push_back(it);
    // r1.getCells().push_back(it1);
    // r1.getCells().push_back(it2);
    // r1.getCells().push_back(it3);
    // r1.getCells().push_back(it4);
    // std::vector<Row> v2;
    // v2.push_back(r1);
    // Table t(v2);
    // std::cout << t.getRows()[0].getCells()[4]->getValue() << std::endl;
    std::ifstream file("Input1.txt");
    Table t1(file);
    t1.print();
    std::ofstream file1("Output.txt");
    t1.save(file1);
}