#include <iostream>
#include <memory>

void foo(int *p)
{
	/*if(p == nullptr){
		std::cout<<"error--->pointer is null,that mean do not reference any object"<<std::endl;
	}*/
	std::cout<<*p<<std::endl;
}

int main()
{
	std::unique_ptr<int> p1(new int(42));
	std::unique_ptr<int> p2 = std::move(p1);

	if(p1 && p1.get() == nullptr){
		//foo(p1.get());
		std::cout<<"error--->pointer is null,that mean do not reference any object"<<std::endl;
	}

	++*p2;
	if(p2){
		foo(p2.get());
	}

	return 0;
}

