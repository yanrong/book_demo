#include <stdio.h>
#define N 10
void BubbleSort(int a[],int n)
{
    int i,j,temp;
 
     for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
              temp=a[j+1];
              a[j+1]=a[j];
              a[j]=temp;
             }
        }
    }
}
int main()
{
    //const int N=10 : error: variable-sized object may not be initialized
    int arr[N]={10,23,84,80,588,30,23,40,237,42};
    int i;
    printf("disordered arrary numbers is:\n");
    for(i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");
    BubbleSort(arr,N);
    printf("sorted arrary numbers is:\n");
    for(i=0;i<N;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
