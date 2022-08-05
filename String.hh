#ifndef STRING_HH
#define STRING_HH

#include <iostream>

class String
{
private:
    char* str;

public:
    String();
    String(char* str);
    String(const String& other);
    ~String();

    void pop_back();
    void push_back(char ch);
    int length();
    // void copy(char s[], int len, int pos);
    String& operator=(const String& other);
    char& operator[](int i);
    friend std::istream& operator>>(std::istream& is, String& obj);    
    friend std::ostream& operator<<(std::ostream& os, const String& obj);
};

#endif