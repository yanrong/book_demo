#include <iostream>
#include <string>
#include "max.h"

int main()
{
	int i=4;
	std::cout<<"max(7,i):"<<::max(7,i)<<std::endl;
	
	double f1=3.4;
	double f2=-6.7;
	std::cout<<"max(f1,i):"<<::max<double>(f1,i)<<std::endl;
	
	std::string s1="mathematics";
	std::string s2="math";
	
	std::cout<<"max(s1,s2):"<<::max(s1,s2)<<std::endl;
	return 0;
}
