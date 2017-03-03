#ifndef LINK_QUEUE_HPP_INCLUDED
#define LINK_QUEUE_HPP_INCLUDED

#include <iostream>
#include "queue_node.hpp"

using std::cout;
using std::endl;

template <typename T>
class link_queue
{
    private:
        queue_node<T> *front,*rear;

    public:
        link_queue():front(NULL),rear(NULL){}
        ~link_queue(){ make_empty(); }

        void en_queue(T const );
        T de_queue();
        T get_front();
        void make_empty();
        void queue_info();

        bool is_empty()
        {
            return front==NULL;
        }
};

template <typename T>
void link_queue<T>::en_queue( T const item)
{
    if(is_empty())
    {
        front=rear=new
 queue_node<T>(item);
    }
    else
    {
        rear=rear->next_ptr=new queue_node<T>(item);
    }

}

template <typename T>
T link_queue<T>::de_queue()
{
    if(is_empty())
    {
        cout<<"empty queue:error de_queue()"<<endl;
        return T();
    }

    queue_node<T> *del_ptr=front;
    T tmp=del_ptr->data;
    front=front->next_ptr;
    delete del_ptr;

    return tmp;
}

template <typename T>
T link_queue<T>::get_front()
{
    if(is_empty())
    {
        cout<<"empty queue:get_front()"<<endl;
        return T();
    }
    return front->data;
}

template <typename T>
void link_queue<T>::make_empty()
{
    queue_node<T> *del_ptr;
    while(front)
    {
        del_ptr=front;
        front=front->next_ptr;
        delete del_ptr;
    }
}

template <typename T>
void link_queue<T>::queue_info()
{
    cout<<"queue's info is:"<<endl;
    if(is_empty())
    {
        cout<<"empty queue:queue_info()"<<endl;
        return ;
    }

    queue_node<T> *ptr=front;
    cout<<"front:";

    while(ptr)
    {
       cout<<ptr->data<<"  " ;
       ptr=ptr->next_ptr;
    }
    cout<<":rear"<<endl<<endl;
}

#endif // LINK_QUEUE_HPP_INCLUDED
