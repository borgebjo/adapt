#include <boost/test/unit_test.hpp>
#include "math/point.h"
#include <sstream>

namespace adapt {
namespace math {
namespace test {

BOOST_AUTO_TEST_SUITE(point_test_suite)

BOOST_AUTO_TEST_CASE(test_constructor_sets_x_and_y)
{
   const double expected_x = 12.01;
   const double expected_y = 14.49;
   Point point{expected_x, expected_y};

   BOOST_CHECK_CLOSE(expected_x, point.x(), 0.01);
   BOOST_CHECK_CLOSE(expected_y, point.y(), 0.01);
}

BOOST_AUTO_TEST_CASE(test_default_constructor_sets_zero)
{
   Point point{};

   BOOST_CHECK_CLOSE(0.0, point.x(), 0.01);
   BOOST_CHECK_CLOSE(0.0, point.y(), 0.01);
}

BOOST_AUTO_TEST_CASE(test_operator_equal)
{
   Point lhs{123.2, 2.1332};
   Point rhs{123.2, 2.1332};
   BOOST_CHECK(lhs == rhs);
}

BOOST_AUTO_TEST_CASE(test_operator_not_equal)
{
   Point lhs{0,1};
   Point rhs{2,2};
   BOOST_CHECK(lhs != rhs);

   lhs = Point{1,0};
   BOOST_CHECK(lhs != rhs);
}

BOOST_AUTO_TEST_CASE(test_output_streaming_operator)
{
   Point p{1.2, 3.4};
   std::stringstream ss;
   ss << p;
   BOOST_CHECK_EQUAL("1.2 3.4",ss.str());
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace test
} // namespace math
} // namespace adapt

