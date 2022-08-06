#ifndef STRING_TYPE_HH
#define STRING_TYPE_HH

#include "Type.hh"

class StringType : public Type
{
private:
    bool validate() override;
public:
    StringType();
    StringType(const String& value);
    void print();
};

#endif