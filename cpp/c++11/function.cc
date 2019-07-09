#include <functional>
#include <iostream>

struct Foo{
	Foo(int num):num_(num){}
	void print_add(int i) const {std::cout << num_ + i << '\n';}
	int num_;
};

void print_num(int i)
{
	std::cout<< i << '\n';
}

struct printNum{
	void operator()(int i) const
	{
		std::cout << i << '\n';
	}
};

int main()
{
	//store a free function
	std::function<void(int)> f1 = print_num;
	f1(-9);

	//store a lambda
	std::function<void()> f2 = [](){print_num(42);};
	f2();

	//store the result of a call to std::bind
	std::function<void()> f3 = std::bind(print_num, 3133);
	f3();

	//store a call to a member function
	std::function<void(const Foo&, int)> f4 = &Foo::print_add;
	const Foo foo(123456);
	f4(foo, 1);
	f4(123, 1);
	//call to a data member accesspr
	std::function<int(Foo const&)> f5 = &Foo::num_;
	std::cout <<"num_ :" << f5(foo) << '\n';
 	//call to a member function and object
	using std::placeholders::_1;
	std::function<void(int)> f6 = std::bind(&Foo::print_add, foo, _1);
	f6(2);
	//call to a member function and object ptr
	std::function<void(int)> f7 = std::bind(&Foo::print_add, &foo, _1);
	f7(2);

	//store a call to a function object
	std::function<void(int)> f8 = printNum();
	f8(18);

	return 0;
}