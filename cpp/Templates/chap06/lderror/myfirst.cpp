#include <iostream>
#include <typeinfo>
#include "myfirst.hpp"

//export -----gcc do not support that
template <typename T>
void print_typeof(T const& x)
{
	std::cout<<typeid(x).name()<<std::endl;
}
