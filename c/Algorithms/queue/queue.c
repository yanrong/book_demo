//queue.c
#include "queue.h"

void InitQueue(Queue *q,int size)
{
    q->MaxSize=size;
    q->elements=(ElementType *)malloc(sizeof(ElementType)*q->MaxSize);
    q->front=q->rear=0;
}

void FreeQueue(Queue *q)
{
    free(q->elements);
}

void MakeEmpty(Queue *q)
{
    q->front=q->rear=0;
}

Bool IsEmpty(Queue *q)
{
    return (Bool)(q->front==q->rear);
}

Bool IsFull(Queue *q)
{
    return (Bool)(q->front==(q->rear+1)%(q->MaxSize));
}

int Length(Queue *q)
{
    return (q->rear-q->front+q->MaxSize)%(q->MaxSize);
}

int EnQueue(Queue *q,ElementType item)
{
    if(!IsFull(q))
    {
        q->elements[q->rear]=item;
        q->rear=(q->rear+1)%(q->MaxSize);
        return 0;
    }
    else return -1;
}

ElementType DeQueue(Queue *q)
{
    ElementType item;
    if(!IsEmpty(q))
    {
        item=q->elements[q->front];
        q->front=(q->front+1)%(q->MaxSize);
        return item;
    }
    else
    {
        printf("error!\n");
        exit(1);
    }
}

ElementType GetFront(Queue *q)
{
    if(!IsEmpty(q))
    {
        return q->elements[q->front];
    }
    else
    {
        printf("error!\n");
        exit(1);
    }
}

void QueueInfo(Queue *q)
{
    int i=q->front;
    while (i!=q->rear)
    {
        printf("%d ",q->elements[i++]);
    }
    printf("\n");
} 
