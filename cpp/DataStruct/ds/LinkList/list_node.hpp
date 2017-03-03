#ifndef LIST_NODE_HPP_INCLUDED
#define LIST_NODE_HPP_INCLUDED

#define NULL 0

template <typename T> class circular_list;

template <typename T>
class list_node
{

private:
    T data;
    list_node *next_ptr;

    friend class circular_list<T>;
    list_node():next_ptr(NULL){}
    list_node(T const item,list_node<T> *ptr=NULL):data(item),next_ptr(ptr){}
    ~list_node(){ next_ptr=NULL;}

public:
    T get_data();
};

template <typename T>
T list_node<T>::get_data()
{
    return this->data;
}
#endif //list_node_HPP_INCLUDED
