#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;

class String{
    char *s;
    int len;

public:
    String(){s=new char[80];len=80;}
    String(int n){s=new char[n];len=n;}
    String(char *p){len=strlen(p);s=new char[len+1];strcpy(s,p);}
    String(const String& );
    ~String(){delete [] s;}

    void Assign(char *str){
        strcpy(s,str);
        len=strlen(str);
    }
    void print(){cout<<s<<"\n";}
    void concat(String& a,String &b);
};

String::String(const String& str)
{
    len=strlen(str.s);
    s=new char[len];
    strcpy(s,str.s);
}

void String::concat(String& a,String& b)
{
    len=strlen(a.s)+strlen(b.s);
    s=new char[len];
    strcpy(s,a.s);
    strcat(s,b.s);
}

int main(void)
{
    String s1;
    //s1.print(); //undefine state
    String s2(20);
    String s3("hello world");
    s3.print();
    s2.Assign("string2");
    s2.print();
    s1.concat(s2,s3);
    s1.print();
    return 0;
}
