#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
	int c,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	/*{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}*/
	c=s[i],s[i]=s[j],s[j]=c;
}
main()
{
	char c[]="you need to much work!";
	reverse(c);
	printf("%s\n",c);
}
