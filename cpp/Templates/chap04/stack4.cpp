#include <iostream>
#include <string>
#include <cstdlib>
#include "stack4.hpp"

int main()
{
    try
    {
        Stack<int,20> int20Stack;
        Stack<int,40> int40Stack;
        Stack<std::string,40> stringStack;

        int20Stack.push(7);
        int40Stack.push(70);
        std::cout<<int20Stack.top()<<std::endl;

        stringStack.push("hello world");
        std::cout<<stringStack.top()<<std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch(std::exception const& ex)
    {
        std::cerr<<"Exception:"<<ex.what()<<std::endl;
        return EXIT_FAILURE;
    }
}
