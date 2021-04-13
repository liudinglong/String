#include<cstring>
#include"String.h"

const int String::size() const {
    return this->len;
}
const int String::length() const{
    return this->len;
}
char * String::get_c_str() const{
    return this->c_str;
}
/******************6 types of constructors***************************/
// empty string constructor
String::String() {
    this->c_str = new char[1];
    this->c_str[0] = '\0';
    this->len = 0;
}
// copy constructor
String::String(const String &str2) {
    this->c_str = new char[str2.size() + 1];
    memcpy(this->c_str, str2.get_c_str(), str2.size());
    this->len = str2.size();
    this->c_str[this->len] = '\0';
}
// substring constructor
String::String(const String &str2, int begin, int len) {
    this->c_str = new char [len + 1];
    memcpy(this->c_str, str2.get_c_str() + begin, len);
    this->c_str[len] = '\0';
    this->len = len;
}
// from c-string, Copies the null-terminated character sequence (C-string) pointed by str
String::String(const char* const str) {
    int str_len = strlen(str);
    this->c_str = new char[str_len + 1];
    this->len = str_len;
    memcpy(this->c_str, str, str_len);
    this->c_str[str_len] = '\0';
}
// from buffer, Copies the first n characters from the array of characters pointed by s.
String::String(const char* const str, int len) {
    this->c_str = new char[len + 1];
    memcpy(this->c_str, str, len);
    this->c_str[len] = '\0';
}
//fill constructor, Fills the string with n consecutive copies of character c.
String::String(int len, char c) {
    this->c_str = new char[len + 1];
    for(unsigned int i = 0; i < len; ++i) {
        this->c_str[i] = c;
    }
    this->c_str[len] = '\0';
    this->len = len;
}

/******overload operators******/
ostream & operator<<(ostream & os, const String & str) {
    os << str.get_c_str() << endl;
    return os;
}
// String operator += (String &str1, String &str2) {
//     int total = str1.size() + str2.size();
//     char * new_str = new char[total + 1];
//     memcpy(new_str, str1.get_c_str(), str1.size());
//     memcpy(new_str + str1.size(), str2.get_c_str(), str2.size());
//     new_str[total] = '\0';
//     delete str1.get_c_str();
//     str1.get_c_str() = new_str;
//     str1.len = total;
//     return str1;
// }
// String operator + (const String &str1, const String &str2) {
//     int total = str1.len + str2.len;
//     char * new_str = new char[total + 1];
//     memcpy(new_str, str1.c_str, str1.len);
//     memcpy(new_str + str1.len, str2.c_str, str2.len);
//     new_str[total] = '\0';
//     return new_str;
// }
