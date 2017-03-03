#include <iostream>
#include <string>
#include <cstdlib>

#include "implement.hpp"

int main()
{
    try{
        Stack<int> intStack;
        Stack<float> floatStack;

        intStack.push(2);
        intStack.push(5);
        floatStack.push(9.90);
        floatStack=intStack;

        for(int i=0;i!=3;++i){
            std::cout << floatStack.top() << std::endl;
            floatStack.pop();
        }
    }
    catch(std::exception const& ex)
    {
        std::cerr<<"Excetption:"<<ex.what()<<std::endl;
        return EXIT_FAILURE;
    }
}
