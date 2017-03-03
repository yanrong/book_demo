#include <iostream>
#include <string>
#include <cstdlib>
#include "stack1.h"
using std::string;
using std::cout;
using std::endl;
using std::cerr;
int main()
{
	try{
		Stack<int> intStack;
		Stack<string> stringStack;
		
		intStack.push(7);
		cout<<intStack.top()<<endl;
		
		stringStack.push("hello");
		cout<<stringStack.top()<<endl;
		
		stringStack.pop();
		stringStack.pop();
	}
	catch(std::exception const& ex)
	{
		cerr<<"Exception:"<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
}
