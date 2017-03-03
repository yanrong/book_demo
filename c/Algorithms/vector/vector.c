//vector.c
  #include <stdio.h>
 #include <stdlib.h>
 #include "vector.h"
 
 void GetArray(Vector *v)
 {
    v->elements=(ElementType *)malloc(sizeof(ElementType)*(v->ArraySize));
    if(v->elements==NULL)
        printf("Memory Allocation Error!\n");
 }
 void InitVector(Vector *v,int size)
 {
    if(size<=0)
        printf("Invalid array size!\n");
    else 
    {
        v->ArraySize=size;
        v->VectorLength=0;
        GetArray(v);
    }
 }
 ElementType GetNode(Vector *v,int i)
 {
    return (i<0||i>=v->VectorLength)?(int)NULL:v->elements[i];
 }
 void FreeVector(Vector *v)
 {
    free (v->elements);
 }
 int Find(Vector *v, ElementType x)
 {
    int i;
    for(i=0;i<=v->VectorLength;i++)
        if(v->elements[i]==x)
            return i;
    return -1;
 }
 Bool Insert(Vector *v,ElementType x,int i)
 {
    int j;
    if(v->VectorLength==v->ArraySize)
    {
        printf("overflow!\n");
        return false;
    }
    else if(i<0||i>v->VectorLength)
    {
        printf("position error\n");
        return false;
    }
    else
    {
        for(j=v->VectorLength-1;j>=i;j--)
            v->elements[j+1]=v->elements[j];
        v->elements[i]=x;
        v->VectorLength++;
        return true;
    }
 }
 Bool Remove(Vector *v,int i)
 {
    int j;
    if(v->VectorLength==0)
    {
        printf("vector is empty!\n");
        return false;
    }
    else if(i<0||i>v->VectorLength)
    {
        printf("position error\n");
        return false;
    }
    else
        for(j=i;j<v->VectorLength;j++)
            v->elements[j]=v->elements[j+1];
        v->VectorLength--;
        return true;
 }
 void VectorInfo(Vector *v)
 {
    int i;
    for(i=0;i<v->VectorLength;i++)
        printf("%d ",v->elements[i]);
    printf("\n");
 }
