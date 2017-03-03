#include <stdio.h>
#define N 27
main()
{
	char s;
	int i;
	long ch[N]={0};
	while((s=getchar())!='\n')
	{
		if(s >= 'a' && s <= 'z')
			++ch[s-'a'];
		else ++ch[N-1];
	}
	for(i=0;i < N;++i)
		if(ch[i]==1)
			printf("%c is first appear!\n",i+'a');
	printf("other char appears %ld \n",ch[N-1]);
}
