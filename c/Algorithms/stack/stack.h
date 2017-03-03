//stack.h
//stack header file
#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef  int ElementType;
typedef enum boolean{false,true} Bool;
typedef struct stack_tag
{
    int top;
    ElementType *elements;
    int MaxSize;
}Stack;

void InitStack(Stack *,int);
void FreeStack(Stack*);
int Push(Stack *,ElementType);
ElementType Pop(Stack *);
ElementType GetTop(Stack *);
void MakeEmpty(Stack *);
Bool IsEmpty(Stack *);
Bool IsFull(Stack *);
void EvaluatePostfix(void);

#endif 
