#include "CurrencyType.hh"

bool CurrencyType::validate()
{
    if (getValue()[0] == '$')
    {
        currency = USD;
        if (getValue()[1] != ' ')
        {
            std::cout << "false on space";
            return false;
        }
        for (int i = 2; getValue()[i] != '\0'; i++)
        {
            if((getValue()[i] < '0' || getValue()[i] > '9') && getValue()[i] != '.')
            {
                std::cout << "false on 0-9 or .";
                return false;
            }
            if(getValue()[i] == '.')
            {
                if ((getValue()[i+1] < '0' || getValue()[i+1] > '9') || (getValue()[i+2] < '0' || getValue()[i+2] > '9') || (getValue()[i+3] != '\0'))
                {
                    std::cout << "false on 2 spaces after dot";
                    return false;
                }
            }
        }
        return true;
    }
    if (getValue()[0] == '€')
    {
        currency = EUR;
        if(getValue()[1] != ' ')
        {
            return false;
        }
        for (int i = 2; getValue()[i] != '\0'; i++)
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
    if (getValue()[getValue().length()-1] == '.' && getValue()[getValue().length()-2] == 'в' && getValue()[getValue().length()-3] == 'л')
    {
        currency = BGN;
        for (int i = 0; i < getValue().length()-2; i++)
        {
            if((getValue()[i] < '0' || getValue()[i] > '9') && getValue()[i] != '.')
            {
                return false;
            }
            if(getValue()[i] == '.')
            {
                if ((getValue()[i+1] < '0' || getValue()[i+1] > '9') || (getValue()[i+2] < '0' || getValue()[i+2] > '9') || (i + 3) != getValue().length()-2)
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
{}

CurrencyType::CurrencyType(const std::string& value) : Type(value)
{}