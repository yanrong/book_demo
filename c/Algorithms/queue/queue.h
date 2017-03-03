//queue.h
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef enum boolean{false,true} Bool;
typedef struct queue
{
    int rear,front;
    ElementType *elements;
    int MaxSize;
}Queue;

void InitQueue(Queue *,int);
void FreeQueue(Queue *);
void MakeEmpty(Queue *);
Bool IsEmpty(Queue *);
Bool IsFull(Queue *);
int Length(Queue *);
int EnQueue(Queue *,ElementType);
ElementType DeQueue(Queue *);
ElementType GetFront(Queue *);

//////////////////////////////
void QueueInfo(Queue *);
#endif
