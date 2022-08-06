#include "FloatType.hh"

bool FloatType::validate()
{
    if (this->getValue()[0] ==  '+' || this->getValue()[0] == '-' || (this->getValue()[0] > '0' && this->getValue()[0] <= '9'))
    {
        for (int i = 1; this->getValue()[i] != '\0'; i++)
        {
            if (this->getValue()[i] < '0' || this->getValue()[i] > '9')
            {
                if(this->getValue()[i] == '.' && this->getValue()[i+1] != '\0' && (this->getValue()[i-1] >= '0' && this->getValue()[i-1] <= '9'))
                {
                    continue;
                }
                else 
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

FloatType::FloatType() : Type()
{}

FloatType::FloatType(const String& value) : Type(value)
{
    if (!validate())
    {
        throw std::invalid_argument("The float type only accepts a string of digits preceded by a '+' or '-' sign and a floating point in the middle.");
    }
}