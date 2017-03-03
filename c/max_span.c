#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000

int get_result(int* p ,int len)
{
	int i=1;

	int min = p[0];
	int max = p[0];
	for(;i < len;i++)
	{
		if(p[i] > max)
			max = p[i];
		if(p[i] < min)
			min = p[i];
	}
	return max- min;
}
int main(int argc,char* argv[])
{
	int length;
	int i;
	char cnt;
	scanf("%d",&length);

	int *array = malloc(length*sizeof(int));
	for(i = 0;i < length;i++)
	{
		scanf("%d",array + i);
		if((cnt= getchar())== '\n') break;
	}

	int res = get_result(array,length);
	printf("%d", res);

	free(array);
	return 0;
}