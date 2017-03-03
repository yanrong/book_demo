#ifndef LINK_STACK_HPP_INCLUDED
#define LINK_STACK_HPP_INCLUDED

#include "stack_node.hpp"
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class link_stack
{
private:
    stack_node<T> *top;
    stack_node<T> * bottom;

public:
    link_stack():bottom(new stack_node<T>()){
        top=bottom;
    }
    bool if_empty(){
        return top==bottom;
    }

    void make_empty();
    void push(T const);
    T pop();
    T get_top();
    void stack_info();
};

template <typename T>
void link_stack<T>::push( T const item)
{
    stack_node<T> *tmp=new stack_node<T>(item);
    tmp->prev_ptr=top;
    top=tmp;
}

template <typename T>
T link_stack<T>::pop()
{
    if(if_empty()){
        cout<<"empty stack:pop()"<<endl;
        return T() ;
    }

    stack_node<T> *del_ptr=top;
    T tmp=del_ptr->data;
    top=top->prev_ptr;
    delete del_ptr;

    return tmp;
}

template <typename T>
void link_stack<T>::make_empty()
{
    stack_node<T> *del_ptr;
    while(if_empty()){
        del_ptr=top;
        top=top->prev_ptr;
        delete del_ptr;
    }
}

template <typename T>
T link_stack<T>::get_top()
{
    if(!if_empty())
        return top->data;
    return T();
}

template <typename T>
void link_stack<T>::stack_info()
{
    stack_node<T> *ptr=top;
    int _size=0;
    cout<<"top-->";
    while(ptr!=bottom){
        cout<<ptr->data<<" ";
        ptr=ptr->prev_ptr;
        _size++;
    }
    cout<<"-->bottom"<<endl;
    cout<<"stack size is:"<<_size<<endl<<endl;

}

#endif // LINK_STACK_HPP_INCLUDED
