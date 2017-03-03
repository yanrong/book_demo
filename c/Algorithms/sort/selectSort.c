#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void SelectSort(int *,int );

int main(int argc, char **argv)
{
    int i,n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers generate:");
    scanf("%d",&n);
    if(n<0||n>MAX_SIZE)
    {
        fprintf(stderr,"Improper value !\n");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        /*random generate number*/
        list[i]=rand()%1000;
        printf("%d ",list[i]);
    }
    SelectSort(list,n);
    printf("\nSorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",list[i]);
    printf("\n");
    return 0;
}

void SelectSort(int *ptrl,int n)
{
    int i,j,min,tmp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(*(ptrl+j) < *(ptrl+min) )
                min = j;
        }
        if(min!=i)
        {
            SWAP(*(ptrl+i),*(ptrl+min),tmp);
        }
    }
}
