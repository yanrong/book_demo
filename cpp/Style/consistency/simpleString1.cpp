#include <string.h>
#include <iostream>
using std::cout;

class SimpleString
{
    char *_string;
    void duplicate(const char *);

public:
    SimpleString();
    SimpleString(const char*);
    SimpleString(SimpleString& s);
    ~SimpleString();

    const char *String() const;
    SimpleString& operator=(const char*);
    SimpleString& operator=(const SimpleString&);
};

void SimpleString::duplicate(const char *s)
{
    if(s){
        _string=new char[strlen(s)+1];
        strcpy(_string,s);
    }
    else _string=0;
}

SimpleString::SimpleString()
{
    _string=0;
}

SimpleString::~SimpleString()
{
    delete []_string;
}

SimpleString::SimpleString(SimpleString& s)
{
    duplicate(s._string);
}

SimpleString::SimpleString(const char *s)
{
    duplicate(s);
}

const char* SimpleString::String() const
{
    return _string;
}

SimpleString& SimpleString::operator=(const char *s)
{
    char *prev_string = _string;
    duplicate(s);
    delete []prev_string;
    return *this;
}

SimpleString& SimpleString::operator=(const SimpleString& s)
{
    if(this == &s)
        return *this;
    return operator=(s._string);
}

int main()
{
    char *str="memory leak";
    char *str1="consistency!";
    SimpleString s1,s2(str),s4,s3;
    s1=s2;
    s3=str1;
    s4=s1;
    cout<<"s1:"<<s1.String()<<"\ns2:"<<s2.String()<<"\ns3:"<<s3.String()<<"\ns4:"<<s4.String()<<'\n';
    return 0;
}
