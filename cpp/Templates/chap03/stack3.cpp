#include <iostream>
#include <deque>
#include <cstdlib>

#include "stack3.hpp"

int main()
{
    try
    {
        //int stack
        Stack<int> intStack;

        //double stack
        Stack<double ,std::deque<double> > dbStack;

        intStack.push(7);
        intStack.push(10);
        std::cout<<"intStack's top "<<intStack.top()<<std::endl;

        dbStack.push(10.05);
        std::cout<<"dbStack's top "<< dbStack.top()<<std::endl;
        std::cout<<dbStack.pop()<<std::endl;
        dbStack.pop();
    }
    catch(std::exception const& ex)
    {
        std::cerr<<"Execption: "<<ex.what()<<std::endl;
        return EXIT_FAILURE;
    }
}
