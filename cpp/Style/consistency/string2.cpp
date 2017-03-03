#include <stdio.h>
#include <iostream>
#include <string.h>
using std::cout;

class String{
    char *s;
    int len;//len==strlen(s)

public:
    String(int n=80){s=new char[n];s[0]='\0';len=0;}
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
    s=new char[len+1];
    strcpy(s,str.s);
}

void String::concat(String& a,String& b)
{
    len=a.len+b.len;
    /*
    delete []s; // that can't solve memory leak in x.concat(x,y)
     s=new char[len+1];
     */
    char *new_s= new char[len+1];
    strcpy(new_s,a.s);
    strcat(new_s,b.s);
    delete []s;
    s=new_s;
}

int main(void)
{
    String s1;
    String s2(20);
    String s3("hello world");
    s3.print();
    s2.Assign("string2");
    s2.print();
    s1.concat(s2,s3);
    s1.print();
    return 0;
}
