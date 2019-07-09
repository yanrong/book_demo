#include <iostream>
#include <boost/accumulators/statistics/count.hpp>
#include <boost/accumulators/accumulators.hpp>

int main()
{
	using namespace boost::accumulators;
	accumulator_set<int, features<tag::count> > acc;
	acc(0);
	acc(0);
	acc(0);
	acc(0);
	assert( 4 == count(acc));
	std::cout <<" count:" << count(acc) << '\n';
	return 0;
}
