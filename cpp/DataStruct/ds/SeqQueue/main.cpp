#include "seq_queue.hpp"

int main()
{
    seq_queue<float> f_queue;///(100);
    for(int i=0;i!=10;i++){
        f_queue.en_queue(static_cast<float>(i*1.1));
    }
    f_queue.queue_info();

    for(int i=0;i!=5;++i){
        f_queue.de_queue();
    }
    cout<<"after 5 times de_queue:"<<endl;
    f_queue.queue_info();

    cout<<"make queue empty"<<'\n';
    f_queue.make_empty();
    f_queue.queue_info();
    return 0;
}
