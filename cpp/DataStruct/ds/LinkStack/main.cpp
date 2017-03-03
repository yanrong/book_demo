#include "link_stack.hpp"

int main()
{
    link_stack<int> int_stack;
    for(int i=0;i!=10;++i)
        int_stack.push(i);
    int_stack.stack_info();

    for(int i=0;i!=5;i++)
        int_stack.pop();
    cout<<"after 5 times pop(),now stack info:"<<endl;
    int_stack.stack_info();

    cout<<"now top element is:"<<int_stack.get_top()<<endl;
    return 0;
}
