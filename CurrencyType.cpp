#include "CurrencyType.hh"

bool CurrencyType::validate()
{
}

CurrencyType::CurrencyType() : Type()
{}

CurrencyType::CurrencyType(const String& value) : Type(value)
{
    if (!validate())
    {
        throw std::invalid_argument("");
    }
}