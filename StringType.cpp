#include "StringType.hh"

bool StringType::validate() //do i need validation?
{
    return true;
}

StringType::StringType() : Type()
{}

StringType::StringType(const std::string& value) : Type(value)
{}

void StringType::print()
{
    std::cout <<  this->getValue();
}