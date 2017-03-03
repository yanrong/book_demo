#include "single_list.h"

int main()
{
    single_list<int> my_list;
    for(int i=0;i!=20;++i){
        my_list.insert_value(i*3,i);
    }
    my_list.print();
    for(int i=0;i!=5;++i){
        my_list.insert_value(3,i*3);
    }
    cout<<"the length of my_list is:"<<my_list.length()<<endl;
    my_list.print();

    my_list.remove_value(5);
    cout<<"the length of my_list is:"<<my_list.length()<<endl;
    my_list.print();

    my_list.remove_all(3);
    cout<<"the length of my_list is:"<<my_list.length()<<endl;
    my_list.print();

    cout<<"thr fifth elements is:"<<my_list.get(5)<<endl;
    cout<<*my_list.find_value(18,1)<<endl;

    my_list.find_value(100);
    my_list.make_empty();
    cout<<"the length of my_list is:"<<my_list.length()<<endl;

    return 0;
}
