#include <stdio.h>
#define N 27
main()
{
	char s[100];
	int i=0,c;
	scanf("%s",s);
	long ch[N]={0};
	while((c=s[i++]) != '\0')
	{
		if(c >= 'a' && c <= 'z')
			++ch[c-'a'];
		else ++ch[N-1];
	}
	printf("first appeared char is:\n");
	for(i=0;i < N; ++i)
		if(ch[i]==1)
			printf("%c\t",i+'a');
	printf("\nother char appears %ld \n",ch[N-1]);
}
