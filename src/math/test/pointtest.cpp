#include <boost/test/unit_test.hpp>
#include "math/point.h"


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

BOOST_AUTO_TEST_SUITE_END()

} // namespace test
} // namespace math
} // namespace adapt

