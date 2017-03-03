#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
FILE *fp;
char cbuffer;
char *key[8]={"if","else","for","while","do","return","main","continue"};
int atype,id=4;
int search(char searchchar[ ],int wordtype)  /*判断单词是保留字还是标识符*/
{
     int i=0;
     int p;
     switch (wordtype)
     {
       case 1:for (i=0;i<=7;i++)
  {
    if (strcmp(key[i],searchchar)==0)
        { p=i+1; break; }    /*是保留字则p为非0且不重复的整数*/
    else p=0;             /*不是保留字则用于返回的p=0*/
  }
  return(p);
      }
  return 0;
}
char  alphaprocess(char buffer)
{
 int   atype;   /*保留字数组中的位置*/
    int   i=-1;
    char  alphatp[20];
    while ((isalpha(buffer))||(isdigit(buffer))||buffer=='_')
    {
           alphatp[++i]=buffer;
           buffer=fgetc(fp);
     }  /*读一个完整的单词放入alphatp数组中*/
     alphatp[i+1]='\0';
     atype=search(alphatp,1);/*对此单词调用search函数判断类型*/
     if(atype!=0)
         {   printf("%s, (1,%d)\n",alphatp,atype-1); id=1;  }
     else
         { printf("(%s ,2)\n",alphatp); id=2; }
return buffer;
}
 
 
char digitprocess(char buffer)
     {
 int i=-1;
 char digittp[20];
 while ((isdigit(buffer))||buffer=='.')
 {
     digittp[++i]=buffer;
     buffer=fgetc(fp);
   }
 
 digittp[i+1]='\0';
 printf("(%s ,3)\n",digittp);
 id=3;
 return(buffer);
     }
char otherprocess(char buffer)
{
      char ch[20];
      ch[0]=buffer;
       ch[1]='\0';
       //ch[2]='\0';
      if(ch[0]==','||ch[0]==';'||ch[0]=='{'||ch[0]=='}'||ch[0]=='('||ch[0]==')')
        { printf("(%s ,5)\n",ch); 
              buffer=fgetc(fp);
              id=4;
              return(buffer);}
      if(ch[0]=='*'||ch[0]=='/')
         {  printf("(%s ,4)\n",ch);
             buffer=fgetc(fp); 
                 id=4; 
                 return(buffer);
             }
      if ((ch[0]=='+'&&ch[1]=='+')||(ch[0]=='-'&&ch[1]=='-'))
           {
                 printf("(%s ,4)\n",ch);
              buffer=fgetc(fp); 
                 id=4; 
                 return(buffer);
   }
     if(ch[0]=='='||ch[0]=='!'||ch[0]=='<'||ch[0]=='>')
   { buffer=fgetc(fp);
     if(buffer=='=')
          {  ch[1]=buffer;
             ch[2]='\0';
             printf("(%s ,4)\n",ch);
           }
        else
              { printf("(%s ,4)\n",ch);
                 id=4;
                 return(buffer); 
              }
      buffer=fgetc(fp);
          id=4;
      return(buffer);
     }
if((ch[0]=='>'&&ch[1]=='=')|| (ch[0]=='<'&&ch[1]=='=')|| (ch[0]=='!'&&ch[1]=='='))
{     buffer=fgetc(fp);
      printf("(%s ,4)\n",ch);
      id=4;
      return(buffer);
     }

if(ch[0]=='+'||ch[0]=='-')
  { if(id==4)  /*在当前符号以前是运算符，则此时为正负号*/
       {  buffer=fgetc(fp);
          ch[1]=buffer; 
               ch[2]='\0';
          printf("(%s ,3)\n",ch); 
               id=3;
               buffer=fgetc(fp);
         return(buffer);
        }
    ch[1]='\0';
       printf("(%s ,4)\n",ch);
    buffer=fgetc(fp);
        id=4;
    return(buffer);
  }
}
int   main()
{
      if ((fp=fopen("example.c","r"))==NULL)   /*只读方式打开一个文件*/
             printf("error");
     else
       {
         cbuffer = fgetc(fp);  /*fgetc( )函数：从磁盘文件读取一个字符*/
         while (cbuffer!=EOF)
             {
                if(cbuffer==' '||cbuffer=='\n')   /*掠过空格和回车符*/
                     cbuffer=fgetc(fp);
                else
                if(isalpha(cbuffer))
                   cbuffer=alphaprocess(cbuffer);
               else
                   if (isdigit(cbuffer))
                        cbuffer=digitprocess(cbuffer);
                   else cbuffer=otherprocess(cbuffer);
               }
        }
  system("pause");
  return 0;
}
