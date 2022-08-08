#ifndef FLOAT_TYPE_HH
#define FLOAT_TYPE_HH

#include "Type.hh"

class FloatType : public Type
{
private:

public:
    FloatType();
    FloatType(const std::string& value);
    bool validate() override;

};

#endif