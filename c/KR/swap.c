#include <stdio.h>

void swap(int *a,int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

main()
{
	int a=10,c=4,b=0x77;
	swap(&a,&c);
	printf("a=%d,c=%d\n",a,c);
}
