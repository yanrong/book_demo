
#include <stdio.h>
#include <stdlib.h>
int N;
void insertSort(int *pa);
int main(void)
{
    printf("please input sort numbers count:(0-30)");
    scanf("%d",&N);
    for(;N<0||N>=30;)
    {
        printf("invalide input! try again!(0-30)");
        scanf("%d",&N);
    }
    int arr[N];
    int i;
    FILE *fp=fopen("arr.dat","r");
    if(!fp)
    {
        printf("falied to open arr.dat!\n");   
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        fscanf(fp,"%d",arr+i);
    }
    fclose(fp);
    insertSort(arr);
    printf("after sort :\n");
    for(i=0;i<N;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}

void insertSort(int *pa)
{
    int i,j;
    int tmp;
    for(i=1;i<N;i++)
    {
        tmp=pa[i];
        for(j=i;j>0&&pa[j-1]>tmp;j--)
            pa[j]=pa[j-1];
        pa[j]=tmp;
    }
   
}

