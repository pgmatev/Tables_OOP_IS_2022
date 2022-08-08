#ifndef STRING_TYPE_HH
#define STRING_TYPE_HH

#include "Type.hh"

class StringType : public Type
{
private:

public:
    StringType();
    StringType(const std::string& value);
    bool validate() override;

    void print();
};

#endif