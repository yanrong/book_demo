#ifndef MYFIRST_HPP
#define MYFIRST_HPP

#include <iostream>
#include <typeinfo>

template <typename T>
void print_typeof(T const&);//template error4.png,ommit a semicolon


template <typename T>
void print_typeof(T const& x)
{
	std::cout<<typeid(x).name()<<std::endl;
}

#endif	//myfirst
