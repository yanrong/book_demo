#include <stdio.h>

int stoi(char *s)
{
    int i,n=0;
    for(i=0;s[i] >= '0' && s[i]<= '9';++i)
        n=10*n + (s[i] - '0');
    return n;
}

char* lower(char *s)
{
    int i=0;
    while(s[i++] !='\0')
    {
        if(s[i] >= 'A'&& s[i] <='Z' )
            s[i]+= 'a'- 'A';
       // ++i;
    }
    return s;
}

/**change s lower case to upper case
 * this is to simple
 */

char* upper(char *s)
{
    int i=0;
    while(s[i++] !='\0')
    {
        if(s[i] >= 'a'&& s[i] <='z' )
            s[i] -= 'a'- 'A';
       // ++i;
    }
    return s;
}

int main()
{
    char* p="012";
    char ch[]="MY NAME IS DU";
    printf("char \"%s\" to int is%d\n",p,stoi(p));
    printf("orgin string: %s\n",ch);
    printf("lower case: %s\n",lower(ch));
    printf("upper case: %s",upper(ch));
    return 0;
}
