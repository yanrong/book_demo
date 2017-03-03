#include <iostream>
/*
*use specifier override and final to solve the confuse override and over-
*write problem,function in base and derive class has same params list
*/
class A
{
public:
	virtual void f(int)
	{
		std::cout<<"A::f"<<std::endl;
	}
};

class B : public A
{
public:
	virtual void f(int) override final
	{
		std::cout<<"B::F"<<std::endl;
	}
};

class C : public B
{
public:
	virtual void f(int) //override
	{
//		std::cout<<"C::f,is error that override base class's final member"<<std::endl;
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
