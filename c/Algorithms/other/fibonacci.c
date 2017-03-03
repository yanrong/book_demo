#include <stdio.h>
int fibonacci(int n)
{
	int i,last,NextToLast,Answer;
	if(n<=1) return 1;
	last=NextToLast=1;
	for(i=2;i<=n;i++)
	{
		Answer=last+NextToLast;
		NextToLast=last;
		last=Answer;
	}
	return Answer;
}
main()
{
	int n;
	scanf("%d",&n);
	printf("fibonacci(%d) is:%d\n\n",n,fibonacci(n));
}
