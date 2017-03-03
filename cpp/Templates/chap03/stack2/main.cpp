#include "stack2.h"
#include <iostream>
#include <cstdlib>
#include <string>
int main()
{
    try{
        Stack<std::string> sstack;
        Stack<int> istack;

        istack.push(2);
        istack.push(7);
        std::cout<<istack.top()<<std::endl;

        std::string s1("you are my favorite");
        std::string s2(10,'Y');
        sstack.push(s1);
        sstack.push(s2);

        std::cout<<sstack.top()<<std::endl;

        for(int i=0;i!=3;++i)
        {
            istack.pop();
        }

    }catch (std::exception const& ex)
    {
        std::cerr<<"Exception"<<ex.what()<<std::endl;
        return  EXIT_FAILURE;
    }
}
