#include <stdio.h>

int coins(int *v,int *min,int value)
{
	int i,j;

	//d(i)=min{ d(i-vj)+1 }，其中i-vj >=0，vj表示第j个硬币的面值
	//min[i] :initial value of conis value
	for(i = 0; i <= value;i++)
		min[i] = i;
	/*get mininal value
	fomr value 1 to "value",calculate each mininal conis
	*/
	for(i = 1;i <= value; i++)
	{
		//there have three kinds of value conis :1 ;3 ; 5
		for(j = 0;j < 3; j++)
		{
			if(v[j] <= i && ((min[i-v[j]] + 1) < min[i]))
				min[i] = min[i -v[j]] + 1;
		}
	}
	return min[value];
}

int main()
{
	int val[] = {1,3,5};
	int min[100];
	printf("%d\n",coins(val,min,19));
}
