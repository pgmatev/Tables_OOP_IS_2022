#ifndef FLOAT_TYPE_HH
#define FLOAT_TYPE_HH

#include "Type.hh"

class FloatType : public Type
{
private:
    bool validate() override;

public:
    FloatType();
    FloatType(const String& value);

};

#endif