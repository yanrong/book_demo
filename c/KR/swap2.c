#include <stdio.h>

void swap(int *a,int *b)
{
	*a=*a + *b;
	*b=*a - *b;
	*a=*a - *b;
}

int main()
{
	int c=5,d=8;
	printf("c=%d,d=%d\n",c,d);
	swap(&c,&d);
	
	printf("c=%d,d=%d\n",c,d);
}
