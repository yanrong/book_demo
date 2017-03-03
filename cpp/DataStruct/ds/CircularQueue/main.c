#include "cir_queue.h"

int main()
{
    CirQueue *q;
    InitQueue(q);
    for(int i='a';i<='z';i++)
    {
        EnQueue(q,(DataType)i);
    }
    QueueInfo(q);

    for(int i=0;i<10;i++)
    {
        DeQueue(q);
    }
    printf("after 10 times dequeue:\n");
    QueueInfo(q);

    return 0;
}
