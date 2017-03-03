#include "stack7.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

int main()
{
    try{
        Stack<int> intStack;
        Stack<float> floatStack;

        intStack.push(22);
        intSatck.push(111);

        floatStack.push(11.11);
        //floatStack=intStack;
        while(1){
            std::cout<<floatStack.top()<< " ";
            floatStack.pop();
        }
        std::cout<<std::endl;
    }
    catch(std::exception const& ex){
        std::cerr<<"Excetpion:"<<ex.what()<<std::endl;
    }

    Stack<int,std::vector> vStack;

    vStack.push(12);
    vStack.push(11);
     while(vStack.empty()){
            std::cout<<vStack.top()<< " ";
            vStack.pop();
        }
    std::cout<<std::endl;
    return 0;
}
