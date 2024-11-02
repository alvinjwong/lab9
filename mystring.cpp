#include "mystring.h"
#include <cstring>


MyString::MyString(const char* str) {
    len = strlen(str);
    data = new char[len+1];
    strncpy(data, str, len);
}

    MyString::~MyString() {
        delete[] data;
    }

    std::string MyString::ToString() {
        return std::string(data);
    }

    int MyString::length() {
        return len;
    }

    MyString MyString::substr(int start, int n) {
        if (start >= len || start < 0) {
            return MyString("");
        }
        int aLen;
        if (n < 0 || start + n > len) {
            aLen = len - start;
        } else {
            aLen = n;
        }

        char* subdata= new char[aLen + 1];
        strncpy(subdata, data + start, aLen);
        subdata[aLen] = '\0';
        MyString sub_str(subdata);
        delete[] subdata;
        return sub_str;
    }

    MyString MyString::operator+(MyString& other) {
        char* concatdata = new char[len + other.len + 1];
        strncpy(concatdata, data, len);
        strncpy(concatdata + len, other.data, other.len);
        concatdata[len + other.len] = '\0';
        MyString result(concatdata);
        delete[] concatdata;
        return result;
    }

    std::ostream& operator<<(std::ostream& os, MyString& str) {
        os << str.data;
        return os;
    }

    bool MyString::operator==(MyString& other) {
        return strcmp(data, other.data) == 0;
    }

    bool MyString::operator>=(MyString& other) {
        return strcmp(data, other.data) >= 0;
    }

    bool MyString::operator<=(MyString& other) {
        return strcmp(data, other.data) <= 0;
    }

    bool MyString::operator!=(MyString& other) {
        return strcmp(data, other.data) != 0;
    }

    bool MyString::operator>(MyString& other) {
        return strcmp(data, other.data) > 0;
    }

    bool MyString::operator<(MyString& other) {
        return strcmp(data, other.data) < 0;
    }


