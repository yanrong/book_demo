#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

#include <iostream>
using std::ostream;//namespace std;

template <typename T>class single_list;

template <typename T>class list_node;
template <typename T>ostream& operator<<(ostream& os,list_node<T>& node);

template <typename T>
class list_node
{
    public:
        friend ostream& operator<< <T>(ostream& os ,list_node<T>& node);

    private:
        friend typename ::single_list<T> ;
        list_node():next(NULL){}
        list_node(const T item, list_node<T> *n=NULL):data(item),next(n){}
        ~list_node(){ next=NULL;}

        T data;
        list_node *next;
};

template <typename T>
ostream& operator<<(ostream& os,list_node<T>& node)
{
    os<<node.data;
    return os;
}

#endif // SINGLE_NODE_H
