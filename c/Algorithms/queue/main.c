//main.c
#include "queue.h"

int main(void)
{
    int i,k;
    Queue *q=(Queue *)malloc(sizeof(Queue));;
    InitQueue(q,10);
    for(i=0;i<10;i++)
        EnQueue(q,i);
    printf("after %d times EnQueue,queue's info is:\n",(q->rear-q->front));
    QueueInfo(q);
    printf("DeQueue elements is:\n");
    for(i=0;i<5;i++)
    {
       k=DeQueue(q);
       printf("%d ",k);
    }
    printf("\nnow queue's elements is:");
    QueueInfo(q);
    printf("now queue's head elements is:%d\n",GetFront(q));
    FreeQueue(q);
    free(q);
    return 0;
} 

