#include<iostream>
#include<string.h>
using namespace std;
class String{
private:
    char* c_str;
    int len;
public:
    /***********6 kinds of contructors***************/
    String(); // empty constructor
    String(const String &str2); // copy constructor
    String(const String &str2, int begin, int len); // substring constructor
    // from c-string, Copies the null-terminated character sequence (C-string) pointed by s.
    String(const char* const str);
    // from buffer, Copies the first n characters from the array of characters pointed by s.
    String(const char* const str, int len); 
    //fill constructor, Fills the string with n consecutive copies of character c.
    String(int len, char c);
    /******member functions********/
    const int size() const; // get the length of String
    const int length() const; // get the length of String
    char * get_c_str() const; // get the char pointer of the 
    
    /******overload operators******/
    String & operator=(const String &other) {
        this->len = other.len;
        this->c_str = new char[this->len + 1];
        memcpy(this->c_str, other.c_str, this->len);
        this->c_str[this->len] = '\0';
        return *this;
    }

    String & operator=(const char* const str) {
        this->len = strlen(str);
        this->c_str = new char[this->len + 1];
        memcpy(this->c_str, str, this->len);
        this->c_str[this->len] = '\0';
        return *this;
    }

    const String operator + (const String &str2){
        int total = this->len + str2.len;
        char * const new_str = new char[total + 1];
        memcpy(new_str, this->c_str, this->len);
        memcpy(new_str + this->len, str2.c_str, str2.len);
        new_str[total] = '\0';
        const String temp(new_str);
        return temp;
    }
    void operator += (const String &str2) {
        int total = this->len + str2.len;
        char * const new_str = new char[total + 1];
        memcpy(new_str, this->c_str, this->len);
        memcpy(new_str + this->len, str2.c_str, str2.len);
        new_str[total] = '\0';
        delete this->c_str;
        this->c_str = new_str;
        this->len = total;
    }
    friend ostream &operator<<(ostream &out, const String & str);
};
