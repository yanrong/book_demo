//vector.h
 #ifndef _VECTOR_H
#define _VECTOR_H

#define ElementType int
typedef enum bool{false,true} Bool;
typedef struct vector_tag
{
    ElementType *elements;
    int ArraySize;
    int VectorLength;
}Vector;

void GetArray(Vector *);
void InitVector(Vector* ,int);
ElementType GetNode(Vector *,int);
void FreeVector(Vector *);
int Find(Vector *,ElementType);
Bool Remove(Vector *,int);
Bool Insert(Vector *,ElementType ,int );
void VectorInfo(Vector *v);

#endif
