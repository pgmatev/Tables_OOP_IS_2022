#ifndef CURRENCY_TYPE_HH
#define CURRENCY_TYPE_HH

#include "Type.hh"

enum Currencies
{
    USD,
    EUR,
    BGN
};

class CurrencyType : public Type
{
private:
    Currencies currency;
public:
    CurrencyType();
    CurrencyType(const std::string& value);
    bool validate() override;
    Currencies getCurrency();
};
#endif