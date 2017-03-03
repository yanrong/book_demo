#ifndef _BINARY_QUEUE_H
#define _BINARY_QUEUE_H

typedef int BiHeapEleType;
typedef struct BiHeapStruct *BiHeap;

BiHeap CreateBiHeap(int N);
int IsBiHeapFull(BiHeap H);
int IsBiHeapEmpty(BiHeap H);
void InsertBiHeap(BiHeapEleType X, BiHeap H);
BiHeapEleType DeleteBiHeapMin(BiHeap H);
void MakeEmptyBiHeap(BiHeap H);
void DestroyBiHeap(BiHeap H);
void BiHeapPercolateDown(int position, BiHeap H);
void BuildBiHeap(BiHeap H, BiHeapEleType *arr, int n);
void BinaryHeapTest(void);

#endif
