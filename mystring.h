#ifndef MYSTRING_H
#define MYSTRING_H


#include <iostream>

class MyString {
    private:
    char* data;
    int len;

    public:
    MyString(char* str);
    ~MyString();

    std::string ToString();
    int length();
    MyString substr(int start, int n = -1);

    MyString operator+(MyString& other);
    friend std::ostream& operator<<(std::ostream& os, MyString& str);
    bool operator=(MyString& other);
    bool operator<(MyString& other);
    bool operator>(MyString& other);
    bool operator<=(MyString& other);
    bool operator>=(MyString& other);
    bool operator==(MyString& other);
    bool operator!=(MyString& other);
};

#endif