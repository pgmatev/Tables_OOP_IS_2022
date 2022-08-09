#include "StringType.hh"

bool StringType::validate() //do i need validation?
{
    if (getValue()[0] != '\"' || getValue()[getValue().size() - 1] != '\"')
    {
        return false;
    }
    return true;
}

StringType::StringType() : Type()
{}

StringType::StringType(const std::string& value) : Type(value)
{}

std::string StringType::trim()
{
    std::string str = getValue();
    str.erase(0, 1);
    str.erase(str.size()-1, 1);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '\\')
        {
            if (str[i+1] == '\"')
            {
                str.erase(i, 1);
            }
            if (str[i+1] == '\\')
            {
                str.erase(i, 1);
            }
        }
    }
    return str;
}

void StringType::print()
{
    std::cout << this->trim();
}