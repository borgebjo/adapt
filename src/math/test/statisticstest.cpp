#include <boost/test/unit_test.hpp>
#include "math/statistics.h"

#include <vector>
#include <stdexcept>

namespace adapt {
namespace math {
namespace test {

BOOST_AUTO_TEST_SUITE(statistics_test_suite)

BOOST_AUTO_TEST_CASE(test_mean_int)
{
   std::vector<int> values = {1,2,3,4,5};
   double expected = 3.0;
   BOOST_CHECK_CLOSE(expected, Mean(values), 0.01);
}

BOOST_AUTO_TEST_CASE(test_mean_double)
{
   std::vector<double> values = {1.1,2.2,3.3,4.4,5.5};
   double expected = 3.3;
   BOOST_CHECK_CLOSE(expected, Mean(values), 0.01);
}

BOOST_AUTO_TEST_CASE(test_mean_throws_invalid_argument)
{
   std::vector<double> values;
   BOOST_CHECK_THROW(Mean(values), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_variance_int_trivial)
{
   std::vector<int> values = {1,1};
   double expected = 0.0;
   BOOST_CHECK_CLOSE(expected, Variance(values), 0.01);
}

BOOST_AUTO_TEST_CASE(test_variance_int)
{
   std::vector<int> values = {1,2};
   double expected = 0.5;
   BOOST_CHECK_CLOSE(expected, Variance(values), 0.01);
}

BOOST_AUTO_TEST_CASE(test_variance_throws_invalid_argument)
{
   std::vector<double> no_values;
   BOOST_CHECK_THROW(Variance(no_values), std::invalid_argument);

   std::vector<double> one_value = {1.0};
   BOOST_CHECK_THROW(Variance(one_value), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace test
} // namespace math
} // namespace adapt

