#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "stack8.hpp"

int main()
{
    try{
        Stack<int> intStack;
        Stack<float> floatStack;

        intStack.push(11);
        intStack.push(111);

        floatStack.push(11.11);

        floatStack=intStack;

        while(1){
            std::cout<<floatStack.top()<<std::endl;
            floatStack.pop();
        }
        std::cout<<std::endl;
    }
    catch(std::exception const& ex){
        std::cerr<<"Exception:"<<ex.what()<<std::endl;
    }

    Stack<int,std::vector> vStack;

    vStack.push(2013);
    vStack.push(20);
    while(!vStack.empty()){
        std::cout<<vStack.top()<<std::endl;
        vStack.pop();
    }
    return 0;
}
