#include <stdio.h>
#define L 10
#define LeftChild(i) (2*(i)+1)//define leftchild
void Swap(int x,int y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}
void PercDown(int A[],int i,int N)
{
    int Child;
    int Tmp;
    for(Tmp=A[i];LeftChild(i)<N;i=Child)
    {
        Child=LeftChild(i);
        if(Child!=N-1 && A[Child+1]>A[Child])   
            Child++;
        if(Tmp<A[Child])   
            A[i]=A[Child];
        else  
            break;
    }
    A[i]=Tmp;
}
void HeapSort(int A[],int N)
{
    int i;
    for(i=N/2;i>=0;i--)
        PercDown(A,i,N);
    for(i=N-1;i>0;i--)
    {
        Swap(A[0],A[i]);
        PercDown(A,0,i);
    }
}
int main ()
{
  int i;
  int arr[L] = { 23, 45, 12, 90, 18, 675, 64, 543, 89, 94 };
  HeapSort (arr, L);
  printf ("after HeapSort ,the result following:\n");
  for (i = 0; i < L; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
  return  0;
}
