#include "circular_list.hpp"

int main()
{
    circular_list<float> float_list;
    int pos=8;

    for(int i=0;i!=10;++i){
        float_list.insert_node(i*2.2,i);
    }
    cout<<"list length:"<<float_list.length()<<endl;
    float_list.list_info();

    if(!float_list.if_empty()){
        for(int i=0;i!=5;i++)
            float_list.insert_node(0,2*i);
    }
    float_list.find_equal(0);

    cout<<"list's length:"<<float_list.length()<<endl;
    float_list.list_info();

    cout<<"find "<<pos<<"th node is:"<<float_list.find_node(pos)->get_data()<<endl;

    cout<<"remove node's data is:"<<float_list.remove_node(3)<<endl;
    cout<<"list's length:"<<float_list.length()<<endl;
    float_list.list_info();

    float_list.remove_all(0);
    cout<<"after remove all 0,list's length:"<<float_list.length()<<endl;
    float_list.list_info();

    float_list.make_empty();
    cout<<"make empty :list's length:"<<float_list.length()<<endl;
    float_list.list_info();

    return 0;
}
