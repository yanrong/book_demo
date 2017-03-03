#include <stdio.h>
#include <stdlib.h>

void strcpy(char *s,char *t)
{
     /*
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
    int n;
    for(n=0;*s!='\0';s++)
        n++;
    return n;
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
    int i,j;
    i=j=0;
    while(s[i]!='\0')
        i++;
    while((s[i++]=t[j++])!='\0')
        ;
}
int main()
{
    char *p= "Hello world!";
    char *d=(char *)malloc(sizeof(p)/sizeof(char));
    char s[100]={"Hello test "};
    strcpy(d,p);
    printf("%d\n",strcmp(s,p));
    printf("%s\n",p);
    printf("p's length is:%d\n", strlen(p));
    printf("d copied p :%s\n",d);
    strcat(s,p);
    printf("%s\n",s);
    return 0;
}

