#ifndef SEQ_STACK_H_INCLUDED
#define SEQ_STACK_H_INCLUDED

#include <iostream>
#include <new>
#include <cstdlib>

using std::cout;
using std::endl;


template <typename T>
class seq_stack
{
private:
    int top;
    int max_size;
    T *elems;

public:
    seq_stack(int sz):top(-1),max_size(sz){
        elems=new T[sz];
        if(!elems){
            cout<<"new memroy failed"<<endl;
            exit(1);
        }
    }
    ~seq_stack(){
        delete []elems;
    }

    void push(const T);
    T pop();
    T get_top();
    void stack_info();

    bool if_empty(){
        return top==-1;
    }

    void make_empty(){
        top=-1;
    }

    bool is_full(){
       return top==max_size-1;
    }

    int stack_size(){
        return top+1;
    }

    int stack_reserve(){
        return max_size;
    }

};

template <typename T>
void seq_stack<T>::push(const T item)
{
    if(is_full()){
     cout<<"fully stack:push(const T)"<<endl;
     return ;
    }
    elems[++top]=item;
}

template <typename T>
T seq_stack<T>::pop()
{
    if(if_empty()){
        cout<<"empty stack:pop()"<<endl;
        exit(1);
    }
    return elems[top--];
}

template <typename T>
T seq_stack<T>::get_top()
{
    if(if_empty()){
        cout<<"empty stack:get_top()"<<endl;
        exit(1);
    }
     return elems[top];
}

template <typename T>
void seq_stack<T>::stack_info()
{
    cout<<"stack size is:"<<stack_size()<<"\nstack reserve size:"<<stack_reserve()<<endl;
    cout<<"bottom:";
    for(int i=0;i<=top;i++){
        cout<<elems[i]<<" ";
    }
    cout<<":top"<<endl<<endl;
}

#endif // SEQ_STACK_H_INCLUDED
