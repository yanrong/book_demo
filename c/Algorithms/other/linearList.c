
#include <stdio.h>
#include <stdlib.h>
#define  Bool int
#define FALSE 0
#define TRUE 1

typedef int ElementType;
typedef struct linearList_tag{
    ElementType *data;//point to an alloced block memory
    int MaxSize;//setting the max size of linearlist
    int last;//indent to last element
}LinearList;

void InitList(LinearList *l,int sz)
{
    if(sz>0)
    {
        l->MaxSize=sz;//init the max size of liearlist
        l->last=0;//at beginning init last as 0,mean list is empty
        l->data=(ElementType *)malloc(sizeof(ElementType)*l->MaxSize);
    }
    return ;
}
void FreeList(LinearList *l)
{
    free(l->data);
}
Bool ListEmpty(LinearList *l)
{
    return (l->last<=0)?TRUE:FALSE;
}
Bool ListFull(LinearList *l)
{
    return (l->last>=l->MaxSize)?TRUE:FALSE;
}
int ListLength(LinearList *l)
{
    return l->last;//the last also store the length of list;
}
ElementType GetElem(LinearList *l,int i)
{
    return (i<0||i>=l->last) ? NULL:l->data[i];//get specificed position element
}
int LocateElem(LinearList *l,ElementType x)
{
    int i;
    for (i=0;i< l->last ;i++)//search whole liearlist to find match element X postion
    if(l->data[i]==x) return i+1;
    return -1;
}
Bool InsertElem(LinearList *l,ElementType x,int i)
{
    int j;
    //if pos i is illegal or linearlist is full;the return false
    if(i<0 || i>l->last || l->last==l->MaxSize)
        return FALSE;
    else
    {
        for(j=l->last-1;j>=i;j--)//find position i reverse form tail element
            l->data[j+1]=l->data[j];
        l->data[i]=x;
        l->last++;
        return TRUE;    
    }
}
Bool DeleteElem(LinearList *l,int i)
{
    int j;
    if(i<1 || i>l->last || l->MaxSize==0)
        return FALSE;
    else
    {
        for (j=i-1;j<l->last;j++)//j=i-1,make such trouble
            l->data[j]=l->data[j+1];
        l->last--;//make last plus 1
        return TRUE;
    }
}

void  ListInfo(LinearList *l)
{
	//print all element of list 
    int i;
    for(i=0;i<l->last;i++)
        printf("%d\t",l->data[i]);
    printf("\n");
}

int main(void)
{
    int i;
    LinearList *l=(LinearList *)malloc(sizeof(LinearList));
    InitList(l,10);
    
    for(i=0;i<9;i++)
        InsertElem(l,10+i,i);
    printf("Init linearlist is:\n");
    ListInfo(l);
    
    if(!InsertElem(l,16,0))
        printf("insert error!\n");
    else if(!ListFull(l))
        printf("list is full,failed to insert.\n");
    printf("after insert in head:\n\n");
    ListInfo(l);
    //testing position i
    i=1;
    printf("the location of element 13 is %d \n",LocateElem(l,13));
    printf("the %drd value is %d\n",i+1,GetElem(l,i));

    for(i=0;i<=2;i++)
        DeleteElem(l,1);
    printf("after %ds delete the list is:\n\n",i);
    ListInfo(l);

 	i=3;
    printf("the location of element 13 is %d \n",LocateElem(l,13));
    printf("the %drd value is %d\n",i+1,GetElem(l,i));
    FreeList(l);
    
    return 0;
}

