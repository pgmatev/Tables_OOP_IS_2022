#include <cstring>
#include "String.hh"

String::String() : str(nullptr)
{
    str = new char[1];
    str[0] = '\0';
}

String::String(char* str)
{
    if (str == nullptr)
    {
        String();
    }
    else
    {
        this->str = new char[strlen(str)+1];
        strcpy(this->str, str);
        this->str[strlen(str)] = '\0';
    }
}

String::String(const String& other)
{
    this->str = new char[strlen(other.str)+1];
    strcpy(this->str, other.str);
    this->str[strlen(other.str)] = '\0';
}

String::~String()
{
    delete str;
}

void String::pop_back()
{
    int length = strlen(str);
    char* buff = new char[length];
    for (int i = 0; i < length - 1; i++)
    {
        buff[i] = str[i];
    }
    buff[length - 1] = '\0';
    *this = String(buff);
    delete [] buff;
}

void String::push_back(char* ch)
{
    int length = strlen(str);
    char* buff = new char[length + 2];
    for (int i = 0; i < length; i++)
    {
        buff[i] = str[i];
    }
    buff[length] = ch;
    buff[length + 1 ] = '\0';
    *this = String(buff);
    delete [] buff;
}

int String::length()
{
    return strlen(str);
}

String& String::operator=(const String& other)
{
    if(this!=&other)
    {
        this->str = new char[strlen(other.str)+1];
        strcpy(this->str, other.str);
    }
}
