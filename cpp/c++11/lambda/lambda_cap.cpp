#include <iostream>

int main()
{
	int int_var = 12;
	double db_var = 3.14;	
	[int_var,db_var] ()
	{
		int i=7;
		std::cout<<int_var<<' '<<db_var<<' '<<i<<std::endl;
	}();

	auto lambda_func = [int_var]()
	{
		std::cout<<"This lambda has a copy of int_var when created:"<<int_var<<std::endl;
	};

	lambda_func();
	for(int i = 0;i < 3; i++)
	{
		int_var++;
		lambda_func();
	}
	return 0;
}
