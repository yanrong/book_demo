#include <stdexcept>
#include <deque>
#include "stack6.h"

template <typename T, typename CONT>
void Stack<T,CONT>::push(T const& elem)
{
    elems.push_back(elem);
}

template <typename T, typename CONT>
void Stack<T,CONT>::pop()
{
    if(elems.empty()){
        throw std::out_of_range("empty stack, error Stack<T<CONT>::pop()");
    }
    elems.pop_back();
}

template <typename T, typename CONT>
T Stack<T,CONT>::top() const
{
    if(elems.empty()){
        throw std::out_of_range("empty stack,error Stack<T,CONT>::top()");
    }
    return elems.back();
}

//a special template member of class definition
template <typename T, typename CONT>
template <typename T2, typename CONT2>
Stack<T,CONT>& Stack<T,CONT>::operator=(Stack<T2,CONT2> const& op2)
{
    if((void *)this==(void*)&op2){
        return *this;
    }

    Stack<T2,CONT2> tmp(op2);//error of "template error2.png"

    elems.clear();
    while(!tmp.empty()){
        elems.push_front(tmp.top());
        tmp.pop();
    }
    return *this;
}
