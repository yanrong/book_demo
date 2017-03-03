#ifndef CIRCULARLIST_HPP_INCLUDED
#define CIRCULARLIST_HPP_INCLUDED

#include "list_node.hpp"

#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cerr;
using std::vector;

template <typename T>
class circular_list
{
private:
    list_node<T> *head;

public:
    circular_list():head(new list_node<T>()){
        head->next_ptr=head;
    }
    ~circular_list(){
        make_empty();
        delete head;
    }

    bool if_empty();
    void make_empty();
    int length();
    list_node<T>* find_node(int);
    void find_equal(T);
    bool insert_node(T ,int=0);
    T remove_node(int=0);
    bool remove_all(T);
    T get_node(int);
    void list_info();
};

template <typename T>
bool circular_list<T>::if_empty()
{
    return head->next_ptr==head;
}

template <typename T>
void circular_list<T>::make_empty()
{
    list_node<T> *del_ptr;
    while(!if_empty()){
        del_ptr=head->next_ptr;
        head->next_ptr=del_ptr->next_ptr;
        delete del_ptr;
    }
}

template <typename T>
int circular_list<T>::length()
{
    list_node<T> *ptr=head;
    int counter=0;

    while(ptr->next_ptr!=head){
        ptr=ptr->next_ptr;
        counter++;
    }
    return counter;
}

template <typename T>
list_node<T>* circular_list<T>::find_node(int pos)
{
    if(pos<0){
        cout<<"errror position:circular_list<T>::find_node(T ,int)"<<endl;
        return NULL;
    }

    list_node<T> *ptr=head->next_ptr;
    for(int i=1;i!=pos;++i){
        ptr=ptr->next_ptr;
        if(ptr==head){
            cout<<"position is illegal:circular_list<T>::find_node(T ,int)"<<endl;
            return NULL;
        }
    }
    return ptr;
}

template <typename T>
void circular_list<T>::find_equal(T item)
{
    list_node<T> *ptr=head->next_ptr;
    int counter=0;
    vector<T> nodes;

    while(ptr!=head){
        if(ptr->data==item){
            counter++;
            nodes.push_back(ptr->data);
        }
        ptr=ptr->next_ptr;
    }
    if(!nodes.empty()){
        typename vector<T>::iterator pos=nodes.begin();
        cout<<counter<<" node equal to item:"<<endl;
        for(;pos!=nodes.end();++pos){
            cout<<*pos<<' ';
        }
        cout<<endl;
    }
}

template <typename T>
bool circular_list<T>::insert_node(T item,int pos)
{
    if(pos<0){
        cout<<"invalid position:circular_list<T>::insert_node(T ,int)"<<endl;
        return false;
    }
    list_node<T> *ptr=head;
    list_node<T> *node_ptr=new list_node<T>(item);
    if(!node_ptr){
        cout<<"new node error:circular_list<T>::insert_node(T ,int)"<<endl;
        return false;
    }
    for(int i=0;i!=pos;i++){
        ptr=ptr->next_ptr;
        if(ptr==head){
            cout<<"invalid error:circular_list<T>::insert_node(T ,int)"<<endl;
            return false;
        }
    }

    node_ptr->next_ptr=ptr->next_ptr;
    ptr->next_ptr=node_ptr;
    return true;
}

template <typename T>
bool circular_list<T>::remove_all(T item)
{
    list_node<T> *head_ptr=head;
    list_node<T> *del_ptr=head->next_ptr;
    while(del_ptr!=head){
        if(del_ptr->data==item){
            head_ptr->next_ptr=del_ptr->next_ptr;
            delete del_ptr;
            del_ptr=head_ptr->next_ptr;
            continue;
        }
        head_ptr=head_ptr->next_ptr;
        del_ptr=del_ptr->next_ptr;
    }

    return true;
}

template <typename T>
T circular_list<T>::remove_node(int pos)
{
    if(pos<0){
        cout<<"invalid pos:T circular_list<T>::remove_node(int)"<<endl;
        exit(1);
    }
    list_node<T> *head_ptr=head->next_ptr,*del_ptr;
    for(int i=0;i!=pos&&head_ptr!=head;++i){
        head_ptr=head_ptr->next_ptr;
    }
    if(head_ptr==head){
        cout<<"head_ptr==head:T circular_list<T>::remove_node(int)"<<endl;
        exit(1);
    }
    del_ptr=head_ptr->next_ptr;
    head_ptr->next_ptr=del_ptr->next_ptr;
    T tmp=del_ptr->data;
    delete del_ptr;

    return tmp;
}

template <typename T>
T circular_list<T>::get_node(int pos)
{
    if(pos<1){
        cout<<"invalid pos:T circular_list<T>::get_node(int)"<<endl;
        exit(1);
    }
    list_node<T> *head_ptr=head;
    for(int i=1;i!=pos;++i){
        head_ptr=head_ptr->next_ptr;
        if(head_ptr==head){
            cout<<"out boundary pos:T circular_list<T>::get_node(int)"<<endl;
            exit(1);
        }
    }
    return head_ptr->data;
}

template<typename T>
void circular_list<T>::list_info()
{
    list_node<T> *head_ptr=head->next_ptr;
    if(if_empty()){
        cout<<"empty list:void circular_list<T>::list_info()"<<endl;
        return ;
    }
    cout<<"list is:"<<'\n'<<"head";
    while(head_ptr!=head){
        cout<<"-->"<<head_ptr->data;
        head_ptr=head_ptr->next_ptr;
    }
    cout<<"-->head"<<endl<<endl;
}

#endif // CIRCULARLIST_HPP_INCLUDED
