#include "Table.hh"

int main()
{
    String str = "123"; 
    String str1 = "456";
    String str2 = "-0.456";
    String str3 = "Hel\"lo";
    Type* it = new IntegerType(str);
    Type* it1 = new IntegerType(str1);
    Type* it2 = new FloatType(str2);
    Type* it3 = new StringType(str3);
    // Vector<Type*> v1;
    // v1.push_back(it);
    // v1.push_back(it1);
    // Row r1(v1);
    // Vector<Row> v2;
    // v2.push_back(r1);
    // Table t(v2);
    it2->print();
    dynamic_cast<StringType*>(it3)->print();
    // std::cout << t.getRows().get(0).getCells().getSize() << std::endl;
}