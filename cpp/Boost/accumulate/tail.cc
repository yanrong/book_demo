#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/variates/covariate.hpp>
#include <boost/accumulators/statistics/tail.hpp>
#include <boost/accumulators/statistics/tail_variate.hpp>

using namespace boost::accumulators;

int main()
{
	//define a feature for tracking covariatel data
	typedef tag::tail_variate<int, tag::covariate1, left> my_tail_variate_tag;

	//this will calculate the left tail and my_tail_variate_tag for n == 2
	//using tag::tail<left::cache_size named paramter

	accumulator_set<double, features<my_tail_variate_tag> > acc(tag::tail<left>::cache_size = 2);
	acc(1.2, covariate1 = 12);
	acc(2.3, covariate1 = -23);
	acc(3.4, covariate1 = 34);
	acc(4.5, covariate1 = -45);

	extractor< my_tail_variate_tag > my_tail_variate;

	//write the tail statistic to std::cout , this will print 4.5 and 3.4
	std::ostream_iterator< double> dout (std::cout, ",");
	std::copy(tail(acc).begin(), tail(acc).end(), dout);
	std::cout<< std::endl;
	
	//write the tail_variate statistic to std::cout,this will print -45 and 34
	std::ostream_iterator<int> iout(std::cout, ",");
	std::copy(my_tail_variate(acc).begin(), my_tail_variate(acc).end(), iout);
	std::cout<< std::endl;

	return 0;
}