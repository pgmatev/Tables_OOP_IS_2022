#ifndef TYPE_HH
#define TYPE_HH

#include <stdexcept>
#include <cstring>
#include <string>
#include <iostream>


class Type
{
private:
    std::string value;

public:
    Type();
    Type(const std::string& value);
    virtual bool validate() = 0;
    std::string& getValue();
    void print();
};

#endif