#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <boost/accumulators/statistics/sum.hpp>


using namespace boost::accumulators;
int main()
{
	//accumulator_set<int, features<tag::weight_sum> , int> acc;
	accumulator_set<double, features<tag::count, droppable<tag::sum> > >acc;

	acc(3.0);
	acc(2.0);
	acc.drop<tag::sum>();
	acc(1.0);

	//sum will drop acc, now acc is 3.0+2.0
	std::cout<< count(acc) <<' '<< sum(acc) << std::endl;
}