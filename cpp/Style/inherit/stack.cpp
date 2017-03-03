#include <assert.h>
#include <string.h>

class Stack
{
    int top;
    int _size;
protected:
    void **vec;

public:
    Stack(int sz);
    ~Stack();
    void *push();
    void *pop();
};

Stack::Stack(int sz)
{
    vec=new void*[_size=sz];
    top=0;
}

Stack::~Stack()
{
    delete [] vec;
}

void *Stack::push()
{
    assert(top>0);
    return vec[top++];
}

void *Stack::pop()
{
    assert(top>0);
    return vec[--top];
}

const int default_stack=128;
class char_stack:public Stack
{
    char *data;

public:
    char_stack();
    char_stack(int sz);
    char_stack(int sz,char *init);
    ~char_stack();
    void push(char);
    char pop();
};

char_stack::char_stack():Stack(default_stack)
{
    data=new char[default_stack];
    for(int i=0;i!=default_stack;++i)
        vec[i]=&data[i];
}

char_stack::char_stack(int sz):Stack(sz)
{
    data=new char[sz];
    for(int i=0;i!=sz;++i)
        vec[i]=&data[i];
}

char_stack::char_stack(int sz,char* init):Stack(sz)
{
    data=new char[sz];
    for(int i=0;i!=sz;++i)
        vec[i]=&data[i];
    for(int i=0;i<strlen(init);++i)
        *((char*)Stack::push())=init[i];
}

char_stack::~char_stack()
{
    delete []data;
}

void char_stack::push(char c)
{
    *((char*)Stack::push())=c;
}

char char_stack::pop()
{
    return *((char*)Stack::pop());
}

class int_stack:public Stack
{
    int *data;

public:
    int_stack();
    int_stack(int sz);
    ~int_stack();
    void push(int);
    int pop();

};

int_stack::int_stack():Stack(default_stack)
{
    data=new int[default_stack];
    for(int i=0;i!=default_stack;++i)
        vec[i]=&data[i];
}

int_stack::int_stack(int sz):Stack(sz)
{
    data=new int[sz];
    for(int i=0;i!=sz;++i)
        vec[i]=&data[i];
}

int_stack::~int_stack()
{
    delete []data;
}

void int_stack::push(int elem)
{
    *((char*)Stack::push())=elem;
}

int int_stack::pop()
{
    return *((char*)Stack::pop());
}
