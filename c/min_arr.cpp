#include <iostream>

using namespace std;

int list(int *arr,int n)
{
	int *p = new int[n*sizeof(int)];
	int len = 1;
	int i,j;
	//d(i) = max{1, d(j)+1},其中j<i,A[j]<=A[i]
	for(i = 0; i < n; i++)
	{
		p[i] = 1; // least lenght of max sub array is 1, only has an elements
		for(j = 0; j < i; j++)
		{
			if(arr[j] <= arr[i] && p[j]+1 > p[i])
				p[i] = p[j] + 1;
		}
		if(p[i] > len) len = p[i]; 
	}

	delete []p;
	return len;
}

int main()
{
	int a[] = {3,4,5,9,3,5,6,1};
	cout<<list(a,8)<<endl;
	return 0;
}