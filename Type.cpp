#include "Type.hh"

Type::Type(const String& value) : value(String(value))
{}

Type::Type() : value(String())
{}

String& Type::getValue()
{
    return value;
}

void Type::print()
{
    std::cout << value;
}