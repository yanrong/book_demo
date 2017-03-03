#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "stack6assign.cpp"

int main()
{
    try{
        Stack<int> intStack;
        Stack<float> floatStack;
        Stack<int,std::vector<int> > vStack;


        vStack.push(33);
        vStack.push(40);

        intStack.push(7);
        intStack.push(4);

        floatStack.push(60.00);
        while(!vStack.empty()){
            std::cout<<vStack.top()<<" ";
            vStack.pop();
        }

        floatStack=intStack;

        for(int i=0;i!=3;++i)
        {
            std::cout<<floatStack.top()<<std::endl;
            floatStack.pop();
        }
    }catch(std::exception const& ex){
        std::cerr<<"Exception:"<<ex.what()<<std::endl;
    }
}
