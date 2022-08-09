#include "FloatType.hh"

bool FloatType::validate()
{
    bool has_dot = false;
    if (this->getValue()[0] ==  '+' || this->getValue()[0] == '-' || (this->getValue()[0] > '0' && this->getValue()[0] <= '9'))
    {
        for (int i = 1; this->getValue()[i] != '\0'; i++)
        {
            if (this->getValue()[i] < '0' || this->getValue()[i] > '9')
            {
                if(this->getValue()[i] == '.' && this->getValue()[i+1] != '\0' && (this->getValue()[i-1] >= '0' && this->getValue()[i-1] <= '9') && !has_dot)
                {
                    has_dot = true;
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

FloatType::FloatType(const std::string& value) : Type(value)
{}