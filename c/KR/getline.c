#include <stdio.h>
#define MAXLINE 1000

int Getline(char s[],int max)
{
	int c,i=0;
	while(--max > 0 && (c=getchar())!=EOF && c !='\n')
		s[i++]=c;
	if(c == '\n')
		s[i++]=c;
	s[i]='\0';
	return i;
}

int strindex(char s[],char t[])
{
	int i,j,k;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=i,k=0;t[k]!='\0'&& s[j]==t[k];j++,k++)
			;
		if(k>0 && t[k]=='\0')
			return i;
	}
	return -1;
}

int main()
{
	char line[MAXLINE];
	int found=0;
	char *pattern="ould";
	int i;
	while(Getline(line,MAXLINE)>0)
		if((i=strindex(line,pattern))>=0)
		{
			//printf("%s",line);
			printf("match position is %d\n",i+1);
			found++;
		}
	printf("%d string match pattern\n",found);
	return 0;
}
