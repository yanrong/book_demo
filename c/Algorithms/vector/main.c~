#include "vector.h"

Vector *Union(Vector *va,Vector *vb)
{
    int m,n,i,j=0,k;
    ElementType x;
    Vector *vc=(Vector *)malloc(sizeof(Vector));//malloc vecotr c to hold union elements
    
    n=va->VectorLength;//get vector a's length
    m=vb->VectorLength;
    InitVector(vc,m+n);//initilize vector c
    
    for(i=0;i<n;i++)//add the vector a's elements to c
    {
        x=GetNode(va,i);
        Insert(vc,x,j);
        j++;
    }
    for(i=0;i<m;i++)//Finding there is a same elements in vector b,if not add it to vector c directly
    {
        x=GetNode(vb,i);
        k=Find(va,x);
        if(k==-1)
        {
            Insert(vc,x,j);
            j++;
        }
    }
    return vc;
}
Vector *Intersection(Vector *va,Vector *vb)
{
    int m,n,k;
    int i=0,j=0;
    ElementType x;
    Vector *vc=(Vector *)malloc(sizeof(Vector));//malloc vecotr c to hold union elements
    
    n=va->VectorLength;//get vector a's length
    m=vb->VectorLength;
    InitVector(vc,(m>n)?n:m);//initilize vector c
    
    while(i<m)
    {
        x=GetNode(vb,i);
        k=Find(va,x);
        if(k!=-1)
        {
            Insert(vc,x,j);
            j++;
        }
        i++;
        
    }   
    return vc;
}
int main(void)
{
    int i;
    Vector *a=(Vector *)malloc(sizeof(Vector));
    Vector *b=(Vector *)malloc(sizeof(Vector));
    Vector *c;
     
    InitVector(a,5);
    InitVector(b,5);
 
    for(i=0;i<5;i++)
    {
        Insert(a,i,i);
        Insert(b,i+2,i);
    }
    c=Union(a,b);
    VectorInfo(c);
    
    c=Intersection(a,b);
    VectorInfo(c);
    return 0;
} 


