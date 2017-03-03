#include <stdio.h>
#include <time.h>

unsigned long int next=1;
int rand(void)
{
	next=next*1103515245+12345;
	return (unsigned int)(next/65536)%32768;
}

void srand(unsigned int seed)
{
	next=seed;
}

int main()
{
	int i;
	srand(time(NULL));
	for(i=0;i<100;++i)
		printf("%2d%c",rand()%100,(i%10==9) ? '\n':' ');
	return 0;
}
