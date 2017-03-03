#ifndef STACK_H
#define STACK_H

#include <deque>
#include <stdexcept>
#include "stack5.hpp"
//#include "assign.h"

template <typename T>
void Stack<T>::push(T const & elem)
{
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop()
{
    if(elems.empty()){
        throw std::out_of_range("Stack<T>::pop():empty stack");
    }
    elems.pop_back();
}

template <typename T>
T Stack<T>::top() const
{
    if(elems.empty()){
        throw std::out_of_range("Stack<T>::top():empty stack");
    }
    return elems.back();
}

//assign.h head file
template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2)
{
    if((void*)this == (void*)&op2){
        return *this;
    }

    Stack<T2> tmp(op2);
    elems.clear();
    while(!tmp.empty()){
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return *this;
}

#endif // STACK_H
