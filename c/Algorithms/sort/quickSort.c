#include <stdio.h>
#define N 10

int Part(int *arr,int left,int right)
{
    int key=arr[left];
    while(left<right)
    {
        while(arr[right]>key && left<right) right--;
        if(left<right)  arr[left++]=arr[right];
        while(arr[left]<key && left<right)  left++;
        if(left<right) arr[right--]=arr[left];
    }
    arr[left]=key;
    return left;
}
void QSort(int *arr,int low,int high)
{
    int pivot;
    if(low<high)
    {
        pivot=Part(arr,low,high);
        QSort(arr,low,pivot-1);
        QSort(arr,pivot+1,high);
    }
}
void QuickSort(int *arr,int arr_size)
{
    QSort(arr,0,arr_size-1);
}
int main()
{
    int i;
    int arr[N]={54,43,02,18,73,29,23,92,19,85};
    QuickSort(arr,N);
    printf("after sort arrar is:\n");
    for(i=0;i<N;i++)
        printf("%d ",arr[i] );
    return 0;
}
