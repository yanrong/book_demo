#include <stdio.h>
#include <stdlib.h>

void inputPasswd(char passwd[], int min, int max)  
{  
    char s[20];  
    char temp[2];  
    int n;  
    strcpy(s," ");  
    while(1)  
    {  
        while(1)  
        {  
            n=getchar();   
            printf("*");  
            memset(temp,0,sizeof(temp));  
            sprintf(temp,"%c",n);  
            strcat(s,temp);  
        }  
        if(strlen(s) > max+1)  
        {  
            memset(s, 0, sizeof(s));  
            printf("\n密码过长，请重新输入:");  
            strcpy(s," ");  
            continue;  
        }  
        if(strlen(s) < min+1)  
        {  
            memset(s, 0, sizeof(s));  
            printf("\n密码过短，请重新输入:");  
            strcpy(s," ");  
            continue;  
        }  
        break;  
    }  
    printf("\n");  
    strcpy(passwd, s+1);  
}  

int main()  
{  
    char passwd[10];  
    printf("请输入密码:");  
    inputPasswd(passwd, 6, 9);  
    printf("Password:%s\n", passwd);  
    return 0;  
}  