#include <iostream>

template <typename T1,typename T2>
/*
*you should note that auto cannot be used as return type of a function
*,However,you can use auto in place of return type of function,in this 
*way,function must have a trailing return type by using decltype
*/
auto compose(T1 t1,T2 t2)->decltype(t1+t2)
{
	return (t1+t2);
}

int main()
{
	auto v = compose(2,3.14);
	std::cout<<"compose is:"<<v<<std::endl;
	return 0;
}
