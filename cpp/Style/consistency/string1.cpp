#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;

class String{
    char *s;
    int len;

public:
    String(int n=80){s=new char[n];s[0]='\0';len=n;}
    String(char *p){len=strlen(p);s=new char[len+1];strcpy(s,p);}
    String(const String&);
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
    len=str.len;
    s=new char[len];
    strcpy(s,str.s);
}

void String::concat(String& a,String& b)
{
    len=a.len+b.len;
    delete []s;//error
    s=new char[len];
    strcpy(s,a.s);
    strcat(s,b.s);
}

int main(void)
{
    String s1("string1");
    //s1.print(); //undefine state
    String s2(20);
    String s3("hello world");
    s3.print();
    s2.Assign("string2");
    s2.print();
    s1.concat(s1,s2);
    s1.print();

    return 0;
}
