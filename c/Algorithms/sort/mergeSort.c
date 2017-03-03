#include <stdio.h>
#include <stdlib.h>
#define L 10
typedef int ElementType;
void Merge(ElementType A[],ElementType TmpArray[],int Lpos,int Rpos,int RightEnd)
{
    int i,LeftEnd,NumElements,TmpPos;
    LeftEnd=Rpos-1;
    TmpPos=Lpos;
    NumElements=RightEnd-Lpos+1;
    while(Lpos<=LeftEnd&&Rpos<RightEnd)
        if(A[Lpos]<=A[Rpos])
            TmpArray[TmpPos++]=A[Lpos++];
        else
            TmpArray[TmpPos++]=A[Rpos++];
    while(Lpos<=LeftEnd)
        TmpArray[TmpPos++]=A[Lpos++];
    while(Rpos<=RightEnd)
        TmpArray[TmpPos++]=A[Rpos++];
    for(i=0;i<NumElements;i++,RightEnd--)
        A[RightEnd]=TmpArray[RightEnd];
}
void MSort(ElementType A[], ElementType TmpArray[],int Left,int Right)
{
    int Center;
    if(Left<Right)
    {
        Center=(Left+Right)/2;
        MSort(A,TmpArray,Left,Center);
        MSort(A,TmpArray,Center+1,Right);
        Merge(A,TmpArray,Left,Center+1,Right);
    }
}

void MergeSort(ElementType A[],int N)
{
    ElementType *TmpArray;
    TmpArray=malloc(N*sizeof(ElementType));
    if(TmpArray!=NULL)
    {
        MSort(A,TmpArray,0,N-1);
        free(TmpArray);
    }
    else
    {
        printf("Fatal error in alloc memory!\n");
        exit(1);
    }
}

int main()
{
    int i;
    ElementType arr[L]={23,45,12,90,18,675,64,543,89,94};
    MergeSort(arr,L);
    printf("after sort ,the result following:\n");
    for(i=0; i<L; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
