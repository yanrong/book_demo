#include <iostream>

using std::cout;
using std::endl;

int main()
{
	//you can call the lambda in same statement that creates it
	[](int i){cout<<":"<<i<<":"<<endl;}(42);

	//save the lambda in a variable like a function pointer
	//auto is not like as longer before
	auto func=[](int i){cout<<":"<<i<<":"<<endl;};
	func(42);
	return 0;
}
