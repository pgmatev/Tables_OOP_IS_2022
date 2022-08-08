#include "Type.hh"

Type::Type(const std::string& value) : value(value)
{}

Type::Type() : value(nullptr)
{}

std::string& Type::getValue()
{
    return value;
}

void Type::print()
{
    std::cout << value;
}