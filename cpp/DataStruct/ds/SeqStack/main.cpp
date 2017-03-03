#include "seq_stack.h"
/**

*/

int main()
{
    seq_stack<char> ch_stack(100);
    int times=6;
    for(int i=65;i!=91;i++)
    {
        char tmp=static_cast<char>(i);
        ch_stack.push(tmp);
    }
    ch_stack.stack_info();
    cout<<"pop elements is:";
    for(int i=0;i!=times;i++){
        cout<<ch_stack.pop()<<" ";
    }
    cout<<endl;
    cout<<"now top elements is:"<<ch_stack.get_top()<<endl<<endl;

    ch_stack.stack_info();
    return 0;
}
