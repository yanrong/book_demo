#ifndef SEQ_QUEUE_HPP_INCLUDED
#define SEQ_QUEUE_HPP_INCLUDED

#include <iostream>
#include <stdlib.h>

using std::endl;
using std::cout;

template <typename T>
class seq_queue
{
    private:
        int rear;
        int front;
        int max_size;
        int counter;
        T *elems;

    public:
        seq_queue(int size=50):rear(0),front(0),max_size(size),counter(0)
        {
            elems=new T[size];
            if(!elems)
            {
                cout<<"new memory failed"<<endl;
                exit(1);
            }
        }
        ~seq_queue()
        {
            delete []elems;
        }

        void make_empty();
        bool if_empty();
        bool is_full();
        bool en_queue(T); /**add an element to queue's front*/
        T de_queue();   /**delete an element at queue's rear**/
        void queue_info();

};

template <typename T>
void seq_queue<T>::make_empty()
{
    counter=0;
    rear=front=0;
}

template <typename T>
bool seq_queue<T>::if_empty()
{
    return this->rear==this->front;
}

template <typename T>
bool seq_queue<T>::is_full()
{
    ///return (this->rear-this->front)==this->max_size;
    return counter==max_size;
}

template <typename T>
bool seq_queue<T>::en_queue(T item)
{
    if(is_full())
    {
        cout<<"full queue:bool en_queue(T)"<<endl;
        return false;
    }
    elems[rear]=item;
    rear=(rear+1)%max_size;
    counter++;

    return true;
}
template <typename T>
T seq_queue<T>::de_queue()
{
    if(if_empty()){
        cout<<"empty queue:T seq_queue<T>::de_queue()"<<endl;
        return T();
    }
    T tmp=elems[front];
    front=(front+1)%max_size;
    counter--;

    return tmp;
}

template <typename T>
void seq_queue<T>::queue_info()
{
    cout<<"Queue info is:\nreserve capacity:"<<max_size<<"\tqueueu size is:"<<counter<<endl;
   /** for(int i=front;i!=rear;++i){
        cout<<elems[i]<<" ";
    }*/
    if(if_empty()){
        cout<<"empty queue!"<<endl;
        return ;
    }
    cout<<"front:";
    for(int i=0;i!=counter;++i){
        cout<<elems[(front+i+max_size)%max_size]<<"--";
    }
    cout<<":rear"<<endl<<endl;
}

#endif // SEQ_QUEUE_HPP_INCLUDED
