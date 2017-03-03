#include <stdio.h>
#define MAXLINE 1000

int Getline(char line[],int maxline);
void copy(char to[],char from[]);

int main()
{
	int len,max;
	char line[MAXLINE],longest[MAXLINE];
	max=0;
	while((len=Getline(line,MAXLINE))>0)
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
		if(max>0)
			printf("%s",longest);
	return 0;
}

int Getline(char *line,int max)
{
	int c,i;
	for(i=0;i<max-1 && (c=getchar())!=EOF && c!='\n';i++)
		line[i]=c;
	if(c=='\n')
	{
		line[i]=c;
		++i;
	}
	line[i]='\0';
	return i;
}

void copy(char* to,char* from)
{
	while((*to++ = *from++)!='\0')
		;
	return ;
}
