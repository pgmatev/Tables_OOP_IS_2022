#ifndef INTEGER_TYPE_HH
#define INTEGER_TYPE_HH

#include "Type.hh"

class IntegerType : public Type
{
private:
    bool validate() override;

public:
    IntegerType();
    IntegerType(const String& value);
};

#endif