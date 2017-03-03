#ifndef DOUBLE_NODE_H
#define DOUBLE_NODE_H

template <typename T> class double_list;

template <typename T>
class double_node
{
    private:
        double_node *prev_ptr;
        double_node *next_ptr;
        T data;

    private:
        friend class double_list<T>;
        double_node():prev_ptr(0),next_ptr(0){}
        double_node(const T item, double_node<T> *prev=0, double_node<T> *next=0):
            data(item),prev_ptr(prev),next_ptr(next){}
        ~double_node(){
            prev_ptr=0;
            next_ptr=0;
        }
    public:
        T get_data();

};

template <typename T>
T double_node<T>::get_data()
{
    return this->data;
}
#endif // DOUBLE_NODE_H
