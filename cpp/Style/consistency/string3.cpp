#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class String{

    struct srep{
        char *s;    //point to data
        int n;      //reference counter
        srep(){ n=1;}
    };
    srep *p;

public:
    String(const char *);
    String();
    String(const String&);
    String& operator=(const char *);
    String& operator=(const String&);
    ~String();
    char& operator[](int);

    friend ostream& operator<<(ostream& ,const String&);
    friend istream& operator>>(istream& ,const String&);

    friend int operator==(const String &x,const char *s){
        return strcmp(x.p->s,s)==0;
    }

    friend int operator==(const String &x,const String &y){
        return strcmp(x.p->s,y.p->s)==0;
    }

    friend int operator!=(const String &x,const char *s){
        return strcmp(x.p->s,s)!=0;
    }

    friend int operator!=(const String &x,const String &y){
        return strcmp(x.p->s,y.p->s)!=0;
    }
};

String::String()
{
    p=new srep;
    p->s=0;
}

String::String(const String& x)
{
    x.p->n++;
    p=x.p;
}

String::String(const char *s)
{
    p=new srep;
    p->s=new char[strlen(s)+1];
    strcpy(p->s,s);
}

String::~String()
{
    if(--p->n==0){
        delete []p->s;
        delete p;
    }
}

String& String::operator=(const char *s)
{
    if(p->n >1){    //disconnect self
        p->n--;
        p=new srep;
    }
    else    //free old sting
        delete []p->s;
    p->s=new char [strlen(s)+1];
    strcpy(p->s,s);
    return *this;
}

String& String::operator=(const String& x)
{
    x.p->n++;
    if(--p->n==0){  //protect against 'st=st'
      delete []p->s;
      delete p;
    }
    p=x.p;
    return *this;
}

ostream& operator<<(ostream& os,const String& x)
{
    return os<<x.p->s<<"\n";
}

istream& operator>>(istream& is,String& x)
{
    char buf[256];
    is>>buf;     //unsafe ,might overflow
    x=buf;
    return is;
}

char& String::operator[](int i)
{
    if(i<0 || strlen(p->s)<i)
        abort();
    return p->s[i];
}

//simple driver:
int main()
{
    String x[100];
    int n;

    for(n=0;cin>>x[n];n++){
        if(n==100)
            abort();
        String y;
        cout<<(y=x[n]);
        if(y=="done") break;
    }
    cout<<"here wo go back again\n";
    for(int i=n-1;i>=0;i--)
        cout<<x[i];
    return 0;
}
