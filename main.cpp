#include "Table.hh"

int main()
{
    String str = "-123"; 
    String str1 = "456";
    Type* it = new IntegerType(str);
    Type* it1 = new IntegerType(str1);
    Vector<Type*> v1;
    v1.push_back(it);
    v1.push_back(it1);
    Row r1(v1);
    Vector<Row> v2;
    v2.push_back(r1);
    Table t(v2);

    std::cout << it->getValue() << std::endl;
    // std::cout << t.getFields().getSize() << std::endl;
}