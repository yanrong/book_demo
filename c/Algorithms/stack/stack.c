//stack.c
#include "stack.h"
#include <ctype.h>

void FreeStack(Stack *s)
{
    free(s->elements);
}

void MakeEmpty(Stack *s)
{
    s->top=-1;
}
Bool IsEmpty(Stack *s)
{
    return (Bool)(s->top==-1);
}
Bool IsFull(Stack *s)
{
    return (Bool)(s->top==s->MaxSize-1);
}
void InitStack(Stack *s,int size)
{
    s->MaxSize=size;
    s->elements=(ElementType *)malloc(sizeof(ElementType)*s->MaxSize);
    s->top==-1;
}
int Push(Stack *s,ElementType item)
{
    if(!IsFull(s))
    {
        s->elements[++(s->top)]==item;
        return 0;
    }
    return -1;
}
ElementType Pop(Stack *s)
{
    if(!IsEmpty(s))
        return s->elements[(s->top)--];
    else
    {
        printf("Stack is empty!\n");
        exit(1);
    }
}
ElementType GetTop(Stack *s)
{
    if(!IsEmpty(s))
        return s->elements[s->top];
    else
    {
        printf("Stack is empty!\n");
        exit(1);
    }
}

//calcalate postfic expr value
void EvaluatePostfix(void)
{
    Stack *spnd=(Stack *)malloc(sizeof(Stack));
    char buf[80];
    int i=0,k;
    InitStack(spnd,80);
    printf("Input Postfix\n");
    scanf("%s",buf);
    while(buf[i]!='\0')
    {
        if(isdigit(buf[i]))
        {
            Push(spnd,buf[i]);
            //continue;
        }
        else
        {
            switch(buf[i])
            {
                case '+':k=Pop(spnd)+Pop(spnd);
                        Push(spnd,k);
                        break;
                case '-':k=Pop(spnd);
                        k=Pop(spnd)-k;
                        Push(spnd,k);
                        break;
                case '*':k=Pop(spnd)*Pop(spnd);
                        Push(spnd,k);
                        break;
                case '/':k=Pop(spnd);
                        k=Pop(spnd)/k;
                        Push(spnd,k);
                        break;
                default:
                        Push(spnd,(int)(buf[i]-48));
            }
        }
        i++;
    }
    printf("The value is %d\n",Pop(spnd));   
}
