#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

main()
{
	srand(time(NULL));
	int i,a[N];
	for(i=0;i<N;++i)
		a[i]=rand()%100;
	for(i=0;i<N;i++)
		printf("%3d%c",a[i], (i%10==9 ||i==N-1) ? '\n' : ' ');
	return 0;
}
