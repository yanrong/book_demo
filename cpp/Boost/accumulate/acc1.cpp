#include <iostream>
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/moment.hpp>

/***********extract **********/
#include <boost/accumulators/statistics/min.hpp>
#include <boost/accumulators/statistics/max.hpp>

using namespace boost::accumulators;

int main()
{
	///
	accumulator_set<double, stats<tag::mean, tag::moment<2> > > acc;

	//push in some data

	acc(1.2);
	acc(2.3);acc(3.4);
	acc(4.5);acc(5.6);

	std::cout << "Mean: " << mean(acc) << std::endl;
	//we do need't accumulator field descriptor for ----accumulators::moment or
	/// boost namespace 
	std::cout << "Moment: " << moment<2>(acc) << std::endl;

	/*********extract************/
	accumulator_set<int, features<tag::min, tag::max> > iacc;
	iacc(2);iacc(-1);iacc(1);
	std::cout << "min: " << min(iacc) << ", max: " << max(iacc) << std::endl;

	//extract_result be more convenient
	std::cout << "extract result min: " << extract_result<tag::min>(iacc) \
	<< ", extract result max: " << extract_result<tag::max>(iacc) << std::endl;


	//more interesting that we can define extractor

	extractor<tag::min> _min;
	extractor<tag::max> _max;
	//now call defined 
	std::cout << "defined. min: " << _min(iacc) << ", max: " << _max(iacc) << std::endl;

	return 0;
}
