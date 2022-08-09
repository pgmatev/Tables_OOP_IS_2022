#include "CurrencyType.hh"

bool CurrencyType::validate()
{
    if (getValue()[0] == '$')
    {
        currency = USD;
        if (getValue()[1] != ' ')
        {
            return false;
        }
        for (int i = 2; getValue()[i] != '\0'; i++)
        {
            if((getValue()[i] < '0' || getValue()[i] > '9') && getValue()[i] != '.')
            {
                return false;
            }
            if(getValue()[i] == '.')
            {
                if ((getValue()[i+1] < '0' || getValue()[i+1] > '9') || (getValue()[i+2] < '0' || getValue()[i+2] > '9') || (getValue()[i+3] != '\0'))
                {
                    return false;
                }
            }
        }
        return true;
    }
    if (getValue().find("€") != std::string::npos)
    {
        currency = EUR;
        if(getValue()[3] != ' ')
        {
            return false;
        }
        for (int i = 4; getValue()[i] != '\0'; i++)
        {
            if((getValue()[i] < '0' || getValue()[i] > '9' ) && getValue()[i] != '.')
            {
                return false;
            }
            if(getValue()[i] == '.')
            {
                if ((getValue()[i+1] < '0' || getValue()[i+1] > '9') || (getValue()[i+2] < '0' || getValue()[i+2] > '9') || (getValue()[i+3] != '\0'))
                {
                    return false;
                }
            }
        }
        return true;
    }
    if (getValue().find("лв.") != std::string::npos)
    {
        currency = BGN;
        for (int i = 0; i < getValue().find("лв.") - 1; i++)
        {
            if((getValue()[i] < '0' || getValue()[i] > '9') && getValue()[i] != '.')
            {
                return false;
            }
            if(getValue()[i] == '.')
            {
                if ((getValue()[i+1] < '0' || getValue()[i+1] > '9') || (getValue()[i+2] < '0' || getValue()[i+2] > '9') || (i + 3) != getValue().find("лв.")-1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

CurrencyType::CurrencyType() : Type()
{
    validate();
}

CurrencyType::CurrencyType(const std::string& value) : Type(value)
{
    validate();
}

Currencies CurrencyType::getCurrency()
{
    return currency;
}