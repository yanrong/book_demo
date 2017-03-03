#ifndef QUEUE_NODE_HPP_INCLUDED
#define QUEUE_NODE_HPP_INCLUDED

///#define NULL 0

template <typename T> class link_queue;

template <typename T>
class queue_node
{
    private:
        T data;
        queue_node<T> *next_ptr;

        friend class link_queue<T>;
        queue_node(const T item,queue_node<T> *next=NULL):data(item),next_ptr(next){}
        queue_node(){}
};

#endif // QUEUE_NODE_HPP_INCLUDED
