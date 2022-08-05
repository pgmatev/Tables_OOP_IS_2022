#ifndef TYPE_HH
#define TYPE_HH

#include "String.hh"

class Type
{
private:
    String value;

    virtual bool validate() = 0;

public:
    Type();
    Type(const String& value);

    String& getValue();
};

#endif