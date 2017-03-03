#include <stdio.h>
#include <stdlib.h>
#include "BinaryHeap.h"

#define MinBiHeapSize  (4)
#define MinBiHeapEleValue  (-2147483647)

struct BiHeapStruct
{
	int Capacity; 
	int Size;
	BiHeapEleType *Array;
};

BiHeap CreateBiHeap(int N)
{
	BiHeap H;
	if (N < MinBiHeapSize)
	{
		printf("Heap size is too small!\n");
		exit(1);
	}
	H = (BiHeap)malloc(sizeof(struct BiHeapStruct));
	H->Array = (BiHeapEleType *)malloc((N+1)*sizeof(BiHeapEleType));
	if (H->Array == NULL)
	{
		printf("Out of space!\n");
		exit(1);
	}
	H->Capacity = N;
	H->Size = 0;
	H->Array[0] = MinBiHeapEleValue;
	return H;
}

int IsBiHeapFull(BiHeap H)
{
	return H->Size == H->Capacity;
}

int IsBiHeapEmpty(BiHeap H)
{
	return H->Size == 0;
}

void InsertBiHeap(BiHeapEleType X, BiHeap H)
{
	int i;
	if (IsBiHeapFull(H))
	{
		printf("Binary Heap is full!\n");
		return;
	}
	for (i = ++H->Size; H->Array[i/2] > X; i /= 2)
	{
		H->Array[i] = H->Array[i/2];
	}
	H->Array[i] = X;
}

BiHeapEleType DeleteBiHeapMin(BiHeap H)
{
	int i, child;
	BiHeapEleType MinEle, LastEle;
	if (IsBiHeapEmpty(H))
	{
		printf("Binary heap is empty!\n");
		return MinBiHeapEleValue;
	}

	MinEle = H->Array[1];
	LastEle = H->Array[H->Size];
	for (i = 1; 2*i <= H->Size; i = child)
	{
		child = 2*i;
		if (child != H->Size && H->Array[child] > H->Array[child +1])
			child++;
		if (LastEle > H->Array[child])
			H->Array[i] = H->Array[child];
		else
			break;
	}
	H->Array[i] = LastEle;
	H->Size--;
	return MinEle;
}
BiHeapEleType FindBiHeapMin(BiHeap H)
{
	if (!IsBiHeapEmpty(H))
	{
		return H->Array[1];
	}
	printf("Binary Heap is empty!\n");
	return H->Array[0];
}

void MakeEmptyBiHeap(BiHeap H)
{
	H->Size = 0;
}
void DestroyBiHeap(BiHeap H)
{
	free(H->Array);
	free(H);
}

void BiHeapPercolateDown(int position, BiHeap H)
{
	int i, child;
	BiHeapEleType ElePerDown;
	ElePerDown = H->Array[position];
	for (i = position; 2*i <= H->Size; i = child)
	{
		child = 2*i;
		if (child != H->Size && H->Array[child+1] < H->Array[child])
		{
			child++;
		}
		if (H->Array[child] < ElePerDown)
		{
			H->Array[i] = H->Array[child];
		}
		else
		{
			break;
		}
	}
	H->Array[i] = ElePerDown;
}
void BuildBiHeap(BiHeap H, BiHeapEleType *arr, int n)
{
	int i;
	H->Size = n;
	for (i = 0; i < n; i++)
	{
		H->Array[i+1] = arr[i];
	}
	for (i = H->Size/2; i >0; i--)
	{
		BiHeapPercolateDown(i,H);
	}
}
void BinaryHeapTest(void)
{
	int i;
	BiHeapEleType x[15] = {10, 12, 1, 14, 6, 5, 8, 15, 3, 9, 7, 4, 11, 13, 2};
	BiHeap H1, H2;
	H1 = CreateBiHeap(128);
	H2 = CreateBiHeap(128);
	for (i = 0; i< 15; i++)
	{
		InsertBiHeap(x[i], H1);
	}
	BuildBiHeap(H2, x, 15);
	for (i = 1; i<= 15; i++)
	{
		printf("%d, ", H1->Array[i]);
	}
	printf("\n");
	for (i = 1; i<= 15; i++)
	{
		printf("%d, ", H2->Array[i]);
	}
	printf("\n");
}
/*
H1£º
				1
			   3 2
			6 7 5 4
15 14 12 9 10 11 13 8
H2£º
				1
			  3 2
		12 6 4 8
15 14 9 7 5 11 13 10
*/