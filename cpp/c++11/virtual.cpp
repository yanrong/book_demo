#include <iostream>
/*
*if the paramters list signature is different in base and derive class,
*event use const for specify member function.the simple rule is all is same
*without any synatic compatbility in old c plus plus version.
*/
class A
{
public:/*
	virtual void f(short)
	{
		std::cout<<"A::f"<<std::endl;
	}*/
	virtual void f(int) const
	{
		std::cout<<"A::f"<<std::endl;
	}
};

class B : public A
{
public:
	virtual void f(int)
	{
		std::cout<<"B::F"<<std::endl;
	}
};

int main()
{
	A *a=new A;
	B *b=new B;
//	a=b;
	a->f(2);
	b->f(3);
	a=b;
	a->f(static_cast<int>(9.9));
	return 0;
}
