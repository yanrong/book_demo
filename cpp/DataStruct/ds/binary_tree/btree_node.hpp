#ifndef BTREE_NODE_HPP_INCLUDED
#define BTREE_NODE_HPP_INCLUDED

#include <iostream>

#define PREORDER 0
#define INORDER 1
#define POSTORDER 2
#define LEVEL 3

typedef int MODE;

using std::cout;
using std::endl;

template <typename T>
struct tree_node
{
    T data;
    tree_node<T> *left,*right;
};

template <typename T>
class bin_tree
{
    public:
        tree_node<T> *root;

        bin_tree(){root=NULL;}
        ~bin_tree(){destory(root);}

        void create_tree(T);

        void pre_order(tree_node<T> *);
        void in_order(tree_node<T> *);
        void post_order(tree_node<T> *);
        void display_mode(MODE);
        void lev_order(tree_node<T> *);
        void destory(tree_node<T> *);
};

template <typename T>
void bin_tree<T>::create_tree(T item)
{
    tree_node<T> *node=new tree_node<T>();
    if(!node)
    {
        cout<<"error to new a node!"<<endl;
        return ;
    }
    node->data=item;
    node->left=node->right=NULL;
    if(!root){
        root=node;
    }else{
        tree_node<T> *back,*cur=root;
        while(cur)
        {
            back=cur;
            if(cur->data > item)
                cur=cur->left;
            else
                cur=cur->right;
        }

        if(back->data > item)
            back->left=node;
        else
            back->right=node;
    }
}

template <typename T>
void bin_tree<T>::pre_order(tree_node<T> *r)
{
    if(r)
    {
        cout<<r->data<<" ";
        pre_order(r->left);
        pre_order(r->right);
    }

}

template <typename T>
void bin_tree<T>::in_order(tree_node<T> *r)
{
    if(r)
    {
        in_order(r->left);
        cout<<r->data<<" ";
        in_order(r->right);
    }
}

template <typename T>
void bin_tree<T>::post_order(tree_node<T> *r)
{
    if(r)
    {
        post_order(r->left);
        post_order(r->right);
        cout<<r->data<<" ";
    }
}

template <typename T>
void bin_tree<T>::display_mode(MODE mode)
{
    switch (mode)
    {
        case PREORDER:pre_order(root);break;
        case INORDER:in_order(root);break;
        case POSTORDER:post_order(root);break;
        case LEVEL:lev_order(root);break;
        default:break;
    }
    cout<<endl;
}

template <typename T>
void bin_tree<T>::destory(tree_node<T> *r)
{
    if(r)
    {
        destory(r->left);
        destory(r->right);
        delete r;
    }
}

template <typename T>
void bin_tree<T>::lev_order(tree_node<T> *root)
{
    const int len=100;
    int front=0,rear=0;
    tree_node<T> *_queue[len];
    tree_node<T> * tmp;
    if(!root)
        return ;
    else
    {
        _queue[rear++]=root;
        while(front!=rear)
        {
            tmp=_queue[front++];
            cout<<tmp->data<<" ";
            if(tmp->left) _queue[rear++]=tmp->left;
            if(tmp->right) _queue[rear++]=tmp->right;
        }
    }
}

#endif // BTREE_NODE_HPP_INCLUDED
