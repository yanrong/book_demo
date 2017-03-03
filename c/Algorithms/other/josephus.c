
#include "vector.h"
/*
* para: p --the vector that hold data to operate
*       n --the number of sequeue
8       s --start number
        m --restart number
*/
void Josephus(Vector *p, int n,int s,int m)
{
    int k=1,s1=s;
    int i,j,w;
    for(i=0;i<n;i++)
    {
        Insert(p,k,i);//insert number into vector
        k++;
    }
    for(j=n;j>=1;j--)//using n times to finish whole.
    {
        s1=(s1+m-1)%j;//get next start number
        if(s1==0)//maybe s+m-1 divide exacly j;
        	s1=j;//then next start number is j;
        w=GetNode(p,s1-1);//vector's first elements is 0
        Remove(p,s1-1);
        Insert(p,w,n-1);//insert at tail
    }
}
int main(void)
{
    Vector *p=(Vector *)malloc(sizeof(Vector));
    InitVector(p,16);
    Josephus(p,16,1,3);
    VectorInfo(p);
    return 0;
}

