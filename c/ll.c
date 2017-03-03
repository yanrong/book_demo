#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDOM(i) (rand()%i)
#define N   15
 
//划分函数
int partion(int a[],int p,int r){
    int x = 0;
    int j;
    int i;
    int temp;
    i = p-1;
    x = a[r];
    for ( j = p; j <=r-1; j++)
    {
        if (a[j] <=  x)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
 
        }
    }
    temp = a[i+1];
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
 
void quik_sort(int a[], int p,int r){
    int q;
    if (p < r)
    {
        q=partion(a,p,r);
        quik_sort(a,p,q-1);
        quik_sort(a,q+1,r);
    }
     
}
 
void main(){
 
    int rand_no = 0;
    int i = 0;
    int a[N];               //n表示数组长度
    //srand((int)time(0));      //设置随机数种子
    printf("==============================排序前=========================================");
    printf("\n");
    for(rand_no = 0;rand_no < N;rand_no++)
    {
 
        a[rand_no]=RANDOM(100);
        printf("%5d",a[rand_no]);
         
    }
    printf("\n");
    printf("==============================排序后=========================================\n");
    quik_sort(a,0,N-1);
    for (int j = 0; j < N; j++)
    {
        printf("%5d",a[j]);
    }
    printf("\n");   
 
 
}