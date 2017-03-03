#ifndef CIRCULAR_QUEUE_H_INCLUDED
#define CIRCULAR_QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int  QueueSize=100;
typedef char DataType;

typedef struct
{
    int front;
    int rear;
    DataType *data;
}CirQueue;

void InitQueue(CirQueue *Q)
{
    Q->data=(DataType *)malloc(sizeof(DataType)*QueueSize);
    if(!Q->data)
    {
        printf("malloc error!\n");
        return ;
    }
    Q->front=Q->rear=0;
}

bool QueueFull(CirQueue *Q)
{
    return  (Q->rear+1)%QueueSize==Q->front;
}

bool QueueEmpty(CirQueue *Q)
{
    return Q->front==Q->rear;
}

int QueueLength(CirQueue *Q)
{
    return (Q->rear-Q->front+QueueSize)%QueueSize;
}

void EnQueue(CirQueue *Q,DataType x)
{
    if(QueueFull(Q))
    {
        printf("queue is full:EnQueue overflow!\n");
        exit(1);
    }
    Q->data[Q->rear]=x;
    Q->rear=(Q->rear+1)%QueueSize;
}

DataType DeQueue(CirQueue *Q)
{
    if(QueueEmpty(Q))
    {
        printf("empty queue:DeQueue!\n");
        exit(1);
    }
    DataType tmp=Q->data[Q->front];
    Q->front=(Q->front+1)%QueueSize;
    return tmp;
}

DataType QueueFront(CirQueue *Q)
{
    if(QueueEmpty(Q))
    {
        printf("empty queue:DeQueue!\n");
        exit(1);
    }
    return Q->data[Q->front];
}

void QueueInfo(CirQueue *Q)
{
    if(QueueEmpty(Q))
    {
        printf("empty queue:QueueInfo\n");
        return ;
    }
    printf("Queue info is:\nreserve size is:%d\tlength is:%d\n",QueueSize,QueueLength(Q));

    printf("head:");
    for(int i=0;i<QueueLength(Q);i++)
    {
        printf("%c ",Q->data[(Q->front+i+QueueSize)%QueueSize]);
    }
    printf(":rear\n\n");
}

#endif /// CIRCULAR_QUEUE_H_INCLUDED
