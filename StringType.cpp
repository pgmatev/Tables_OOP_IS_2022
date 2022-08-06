#include "StringType.hh"

bool StringType::validate() //do i need validation?
{
    return true;
}

StringType::StringType() : Type()
{}

StringType::StringType(const String& value) : Type(value)
{
    if (!validate())
    {
        throw std::invalid_argument("HA");
    }
}

void StringType::print()
{
    std::cout << "\"" << this->getValue() << "\"";
}