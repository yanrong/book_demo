#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include "single_node.h"
#include <stdlib.h>

using std::cout;
using std::cerr;
using std::endl;

template <typename T>
class single_list
{
    public:
        single_list():head(new list_node<T>()){}
        ~single_list(){
            make_empty();
            delete head;
        }
        void make_empty();
        int length();
        list_node<T> *find_value(T ,int );
        list_node<T> *find_value(int );
        bool insert_value(T ,int );
        T remove_value(int=0);
        bool remove_all(T );
        T get(int);
        void print();

    private:
        list_node<T> *head;
};

template <typename T>
void single_list<T>::make_empty()//delete elements at list's head
{
    list_node<T> *p;
    while(head->next!=NULL){
        p=head->next;
        head->next=p->next;
        delete p;
    }
}

template <typename T>
int single_list<T>::length()
{
    list_node<T> * p=head->next;
    int counter=0;
    for(; p ;counter++)
        p=p->next;
    return counter;
}

template <typename T>
list_node<T>* single_list<T>::find_value(T value,int pos)
{
    //get last node's data is equal to value
    if(pos<1){
        cerr<<"Illegal position"<<endl;
        return NULL;
    }

    list_node<T> *p=head;
    int counter=0;

    while(counter!=pos && p){
        p=p->next;
        if(p->data==value)
            counter++;
    }
    if(!p && !counter){
        cerr<<"cant find the element"<<endl;
        return NULL;
    }
    return p;
}

template <typename T>
list_node<T>* single_list<T>::find_value(int pos)
{
    if(pos<1){
        cerr<<"Illegal boundary"<<endl;
        return NULL;
    }

    list_node<T> *p=head->next;
    for(int i=0;i<pos&&p;i++)
        p=p->next;
    if(!p){
        cerr<<"the pos is out of boundary"<<endl;
        return NULL;
    }
    return p;
}

template <typename T>
bool single_list<T>::insert_value(T item,int pos)
{
    if(pos<0){
        cerr<<"the position is illegal"<<endl;
        return false;
    }

    list_node<T> *phead=head;
    /*single_list is a friend function of
    list_node,access member function  as normal function call*/
    list_node<T> *node=new list_node<T>(item);

    if(!node){
        cerr<<"allocate memory error!"<<endl;
        return false;
    }
    for(int i=0;i<pos&&phead;i++){
        phead=phead->next;
    }
    if(!phead){
        cerr<<"out of boundary"<<endl;
        return false;
    }

    node->next=phead->next;
    phead->next=node;
    return true;
}

template <typename T>
T single_list<T>::remove_value(int pos)
{
    if(pos<0){
        cerr<<"illegal position"<<endl;
        exit(1);
    }

    list_node<T> *phead=head,*pdel=0;
    for(int i=0;i<pos&&phead->next;i++)
        phead=phead->next;
    if(!phead->next){
        cerr<<"can't find element"<<endl;
        exit(1);
    }

    pdel=phead->next;
    phead->next=pdel->next;
    T tmp=pdel->data;
    delete pdel;
    return tmp;
}

template <typename T>
bool single_list<T>::remove_all(T item)
{
    list_node<T> *phead=head;
    list_node<T> *pdel=head->next;
    bool counter=0;

    while(pdel){
        if(pdel->data==item){
            phead->next=pdel->next;
            delete pdel;
            pdel=phead->next;
            counter++;
            continue;
        }
        phead=phead->next;
        pdel=pdel->next;
    }
    if(counter)
        return true;
    else
        return false;
}

template<typename T>
T single_list<T>::get(int pos)
{
    if(pos<0){
        cerr<<"illegal position"<<endl;
        exit(1);
    }

    list_node<T> *phead=head->next;
    for(int i=0;i<pos-1;i++){
        phead=phead->next;
        if(!phead){
            cerr<<"the pos is out of boundary"<<endl;
            exit(1);
        }
    }
    return phead->data;
}

template <typename T>
void single_list<T>::print()
{
    list_node<T> *phead=head->next;
    cout<<"the list info is:"<<endl;
    while(phead){
        cout<<phead->data<<"->";
        phead=phead->next;
    }
    cout<<"NULL\n-----------------------------> finished"<<endl;
}

#endif //SINGLE_LIST_H
