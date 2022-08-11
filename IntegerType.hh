#ifndef INTEGER_TYPE_HH
#define INTEGER_TYPE_HH

#include "Type.hh"

class IntegerType : public Type
{
private:

public:
    IntegerType();
    IntegerType(const std::string& value);
    IntegerType(IntegerType& other);
    bool validate() override;
};

#endif