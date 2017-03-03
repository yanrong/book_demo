#include "double_list.h"

int main()
{
    double_list<int> int_list;
    for(int i=0;i!=15;i++){
        int_list.insert_node(2*i,i);
    }
    cout<<"length is:"<<int_list.length()<<endl;
    int_list.list_info();

    for(int i=0;i!=5;++i)
        int_list.insert_node(2,i*2);
    cout<<"length is:"<<int_list.length()<<endl;
    int_list.list_info();

    cout<<"the 20th node's element is:"<<int_list.find_elem(20)->get_data()<<endl;
    cout<<"remove 5 elems at list head:"<<endl;
    for(int i=0;i!=5;i++)
        int_list.remove_node(1);
    cout<<"length is:"<<int_list.length()<<endl;
    int_list.list_info();

    int_list.make_empty();
    cout<<"length is:"<<int_list.length()<<endl;
    int_list.list_info();
    return 0;
}
