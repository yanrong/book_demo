#include <string.h>
#include <iostream>
using std::cout;

class SimpleString
{
    char *_string;
    int _length;

public:
    SimpleString();
    SimpleString(const char*);
    SimpleString(SimpleString& s);
    ~SimpleString();

    const char *String() const;
    SimpleString& operator=(const char*);
    SimpleString& operator=(const SimpleString&);
};

char* Strdup(const char *s)
{
    char *s1=new char[strlen(s)+1];
    strcpy(s1,s);
    return s1;
}

SimpleString::SimpleString()
{
    _string=0;
    _length=0;
}

SimpleString::~SimpleString()
{
    delete []_string;
}

SimpleString::SimpleString(SimpleString& s)
{
    if(s._string){
        _string=Strdup(s._string);
        _length=s._length;
    }
    else{
        _string=0;
        _length=0;
    }
}

SimpleString::SimpleString(const char *s)
{
    _string=s?Strdup(s):0;
    _length=s?strlen(s):0;
}

const char* SimpleString::String() const
{
    return _string;
}

SimpleString& SimpleString::operator=(const char *s)
{
    delete[] _string;
    _string=s?Strdup(s):0;
    _length=s?strlen(s):0;
    return *this;
}

SimpleString& SimpleString::operator=(const SimpleString& s)
{
    delete []_string;
    _string=s._string?Strdup(s._string):0;
    _length=_string?s._length:0;
    return *this;
}

int main()
{
    char *str="hello ";
    char *str1="consistency!";
    SimpleString s1,s2(str),s4,s3;
    s1=s2;
    s3=str1;
    s4=s1;
    cout<<"s1:"<<s1.String()<<"\ns2:"<<s2.String()<<"\ns3:"<<s3.String()<<"\ns4:"<<s4.String()<<'\n';
    return 0;
}
