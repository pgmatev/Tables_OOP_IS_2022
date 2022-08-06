#ifndef CURRENCY_TYPE_HH
#define CURRENCY_TYPE_HH

#include "Type.hh"

enum Currenies
{
    USD,
    EUR,
    BGN
};

class CurrencyType : public Type
{
private:
    bool validate() override;
    Currencies currency;
public:
    CurrencyType();
    CurrencyType(const String& value);
};
#endif