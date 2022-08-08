#include "IntegerType.hh"

bool IntegerType::validate()
{
    if (this->getValue()[0] ==  '+' || this->getValue()[0] == '-' || (this->getValue()[0] > '0' && this->getValue()[0] <= '9'))
    {
        for (int i = 1; this->getValue()[i] != '\0'; i++)
        {
            if (this->getValue()[i] < '0' || this->getValue()[i] > '9')
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

IntegerType::IntegerType() : Type()
{}

IntegerType::IntegerType(const std::string& value) : Type(value)
{
    // if (!validate())
    // {
    //     throw std::invalid_argument("The integer type only accepts a string of digits preceded by a '+' or '-' sign.");
    // }
}

IntegerType::IntegerType(IntegerType& other) : Type(other.getValue())
{
    // if (!validate())
    // {
    //     throw std::invalid_argument("The integer type only accepts a string of digits preceded by a '+' or '-' sign.");
    // }
}

// Type* IntegerType::clone()
// {
//     return new IntegerType(*this);
// }