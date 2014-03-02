#include "line/linefitter.h"
#include "math/point.h"
#include "fittererror.h"

#include <boost/test/unit_test.hpp>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;
using namespace adapt::math;

namespace adapt {
namespace line {
namespace test {

BOOST_AUTO_TEST_SUITE(line_fitter_test_suite)

struct F // fixture
{
   F() {}
   ~F() {}

   LineFitter theFitter;
   std::stringstream output;
};

BOOST_FIXTURE_TEST_CASE(test_throws_on_too_few_poins, F)
{
   vector<Point> points{};
   BOOST_CHECK_THROW(theFitter.adapt(points), FitterError);
   points = {{1,2}};
   BOOST_CHECK_THROW(theFitter.adapt(points), FitterError);
}

BOOST_FIXTURE_TEST_CASE(test_fits_two_points, F)
{
   vector<Point> points{{0,1},{1,2}};
   theFitter.adapt(points);
   theFitter.publish(output);
   std::string expected{"1 1"};
   BOOST_CHECK_EQUAL(expected, output.str());
}

BOOST_FIXTURE_TEST_CASE(test_fits_set, F)
{
   std::vector<double> x_values{1, 2, 3, 4, 4, 5, 5, 6, 6, 7};
   std::vector<double> y_values{7, 8, 9, 8, 9, 11, 10, 13, 14, 13};
   vector<Point> points;
   assert(x_values.size() == y_values.size());
   for (unsigned int i = 0; i < x_values.size(); ++i)
      points.push_back({x_values[i], y_values[i]});

   theFitter.adapt(points);
   output << setprecision(5);
   theFitter.publish(output);
   std::string expected("1.1651 5.19");
   BOOST_CHECK_EQUAL(expected, output.str());
}
BOOST_AUTO_TEST_SUITE_END()

} // namespace test
} // namespace line
} // namespace adapt

