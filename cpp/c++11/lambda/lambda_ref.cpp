#include <iostream>

int main()
{
	int int_var = 42;
	auto lambda_func = [&int_var]()
	{
		std::cout<<"This lambda captures int_var by reference:"<<int_var<<std::endl;
	};

	for(int i = 0; i < 3; i++)
	{
		int_var++;
		lambda_func();
	}
	std::cout<<"=================================="<<std::endl;
	auto lambda_mod_val = [&int_var]()
	{
		std::cout<<"This lambda captures int_var by reference and modify it's value :"<<int_var<<std::endl;
		int_var+=10;
		std::cout<<"after modify it's value is :"<<int_var<<std::endl;
	};
	lambda_mod_val();
	return 0;
}
