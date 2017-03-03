#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a[10],i,j,tmp,min;
	srand(time(NULL));
	for(i=0;i<10;i++)
		a[i]=rand()%100;
	for(i=0;i<10;i++)
		printf("%3d",a[i]);
	printf("\n");
	
	for(i=0;i<9;i++)
	{
		tmp=i;
		for(j=i+1;j<10;j++)
		{
			if(a[tmp]>a[j])
				tmp=j;
		}
		if(i!=tmp)
		{
			min=a[tmp];
			a[tmp]=a[i];
			a[i]=min;
		}
	}
	for(i=0;i<10;i++)
		printf("%3d",a[i]);
	printf("\n");
}
