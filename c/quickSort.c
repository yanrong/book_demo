#include <stdio.h>
//fuck pointer,
void swap(int *x,int *y)
{
	int temp = *x;
	*x=*y;
	*y=temp;
}

int partion(int *p,int l,int r)
{
	int x = p[r];
	int i = l - 1;
	int j = l;

	for(;j <= r-1;j++)
	{
		if(p[j] <= x){
			i++;
			swap(&p[i],&p[j]);
		}
	}
	swap(&p[i+1],&p[r]);
	return (i+1);
}

void quick_sort(int *p,int l, int r)
{
	int q;
	if(l < r)
	{
		q = partion(p,l,r);
		quick_sort(p,l,q-1);
		quick_sort(p,q+1,r);
	}
}

int main()
{
	int a[10]={0,-5,3,60,9,88,52,61,37,44};
	quick_sort(a,0,9);
	int i;
	for (i = 0; i < 10; ++i)
	{
		/* code */printf("%d ",a[i] );
	}
	
	return 0;
}