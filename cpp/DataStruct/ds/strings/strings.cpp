#include <iostream>
#include <cstdlib>
using namespace std;

void strcpy(char *s,char *t)
{
    /**
    int i=0;
    while((s[i]=t[i])!='\0')
        i++;

    while((*s=*t)!='\0'){
        s++;
        t++;
    }
    while((*s++ =*t++)!='\0')
        ;
    */
    while(*s++=*t++)
        ;

}

int strlen(char *s)
{
    /**
    int n;
    for(n=0;*s!='\0';s++)
        n++;
    return n;
    */
    char *p=s;
    while(*s)
        s++;
    return s-p;
}

int strcmp(char *s,char *t)
{
    for(;*s==*t;s++,t++)
        if(*s=='\0' || *t=='\0')
            return 0;
    return *s - *t;
}

void strcat(char s[],char t[])
{
    /**
    int i,j;
    i=j=0;
    while(s[i]!='\0')
        i++;
    while((s[i++]=t[j++])!='\0')
        ;
    */
    while(*s) ///continue;
        s++;
    while(*s++=*t++);
}
int main()
{
    char *p= "Hello world!";
    char *d =new char [strlen(p)];
    char s[100]={"Hello test "};
    strcpy(d,p);
    cout<<strcmp(s,p)<<endl;
    cout << p << endl;
    cout << "p's length is:" << strlen(p)<<endl;
    cout << "d copied p :" << d <<endl;
    strcat(s,p);
    cout<<s<<endl;
    delete []d;
    d=0;
    return 0;
}
