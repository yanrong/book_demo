#include <stdio.h>
#include <stdlib.h>

void cube_optimise(int* arr,int key)
{
	int mod;
	int factor = (key> 10)? 9 : 3;

	//printf("\nfactor = %d -- key = %d",factor,key);
	//int termin = key / 2;
	int i = 1,counts = 0;

	while(1)
	{
		if(!(key%factor))
		{
			arr[i++] = factor;
			//printf("\narr[i] = %d",factor);
			key = key/factor;
			//printf("\nkey = %d",key);
			counts++;
			//factor = 2;
			
			continue;
		}
		factor--;
		if(factor < 2)
		{
			arr[i] = key;
			counts++;
			break;
		}
	}
	//printf("\ntotal counts = %d\n",counts);
	arr[0]=counts;
}


int main(int argc,char* argv[])
{
	int num;
	int i,j;
	int result[6];
	int parr[5] = {9,10,26,27,100};
	/*
	scanf("%d",&num);
	int *parr = malloc(num * sizeof(int));

	for(i = 0; i < num; i++)
	{
		scanf("%d",parr + i);
	}
*/
	for(i = 0;i < 5;i++)
	{
		printf("\n===========================");
		cube_optimise(result,parr[i]);
		for(j = 1;j < result[0];j++)
			printf("\n%d ",result[j]);
		printf("\n===========================");
		//printf("\n");
	}

	//free(parr);
	return 0;
}