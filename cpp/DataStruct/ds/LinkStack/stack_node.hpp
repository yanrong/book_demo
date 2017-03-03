#ifndef STACK_NODE_HPP_INCLUDED
#define STACK_NODE_HPP_INCLUDED

#define NULL 0

template <typename T> class link_stack;

template <typename T>
class stack_node
{
private:
    T data;
    stack_node<T> *prev_ptr;

    friend class link_stack<T>;
    stack_node(){}
    stack_node(T d,stack_node<T> *prev=NULL):data(d),prev_ptr(prev){}
};

#endif // STACK_NODE_HPP_INCLUDED
