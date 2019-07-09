#include <utility>
#include <tuple>
#include <iostream>

int main()
{
	std::pair<int, std::string> p1;
	p1 = std::make_pair(121, std::string("make change"));
	std::cout << "pair :" << p1.first << ", "<< p1.second << "\n";

	auto p2 = std::make_pair(3.1415926, "crazy world\n");
	std::cout << "pair :" << p2.first << ", "<< p2.second << '\n';

	auto tp1 = std::make_tuple(666, 'k', "you do it\n" );
	std::tuple<int, std::string, double> tp2;
	tp2 = std::make_tuple(1, std::string("bye !!!"), 0.0001);

	std::cout << "tp1 :" << std::get<0>(tp1) << "," << std::get<1>(tp1) << "," << std::get<2>(tp1) << '\n';
	std::cout << "tp2 :" << std::get<0>(tp2) << "," << std::get<1>(tp2) << "," << std::get<2>(tp2) << '\n';

	return 0;
}