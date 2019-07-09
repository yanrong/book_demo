#include <iostream>
#include <boost/accumulators/statistics/weighted_sum.hpp>
#include <boost/accumulators/statistics/sum.hpp>
#include <boost/accumulators/accumulators.hpp>

using namespace boost::accumulators;

int main()
{
	//accumulator_set<int, features<tag::weight_sum> , int> acc;
	accumulator_set<int, features<tag::sum> , int> acc;

	acc(1, weight = 2);acc(2, weight = 4);
	acc(3, weight = 4);acc(5, weight = 6);

	//std::cout<< weight_sum(acc) << std::endl;
	std::cout<< sum(acc) << std::endl;
}