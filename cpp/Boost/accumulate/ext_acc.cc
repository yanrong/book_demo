#include <boost/accumulators/framework/accumulator_base.hpp>
#include <boost/accumulators/framework/parameters/sample.hpp>

namesapce boost{
	namespace accumulators{
		namespace impl{

			template<typename Sample>
			struct sum_accumulator : accumulator_base
			{
				typedef Sample result_type;
				template<typename Args>
				sum_accumulator(Args const &args) : sum(args[sample | Sample()])
				{

				}

				template<typename Args>
				void operator ()(Args const & args)
				{
					this->sum +=args[sample];
				}

				result_type result() const 
				{
					return this->sum;
				}

			private:
				Sample sum;
			};
		}
	}
}