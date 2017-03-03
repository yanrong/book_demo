#include <iostream>

int main()
{
	int sum = 0;
	for(int i = 0; i <= 100; i++)
		[&](int x){sum += x;}(i);

	std::cout<<"sum is:"<<sum<<std::endl;
}
