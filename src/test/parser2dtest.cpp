#include <boost/test/unit_test.hpp>
#include "parser2d.h"
#include "parsererror.h"

#include "math/point.h"

#include <vector>
#include <sstream>
using namespace std;
namespace adapt {
namespace test {

BOOST_AUTO_TEST_SUITE(parser2d_test_suite)

BOOST_AUTO_TEST_CASE(test_input)
{
   std::stringstream ss;
   ss << "1.0 2.0" << endl;
   ss << "3.0 4.0";
   Parser2d parser(ss);

   std::vector<math::Point> expected{{1.0, 2.0}, {3.0, 4.0}};
   auto result = parser.parse();
   BOOST_CHECK_EQUAL_COLLECTIONS(begin(expected), end(expected),
   				 begin(result), end(result));
}

BOOST_AUTO_TEST_CASE(test_bad_input)
{
   std::stringstream ss;
   ss << "1.0 2.0" << endl;
   ss << "bad input";
   Parser2d parser(ss);

   BOOST_REQUIRE_THROW(parser.parse(), ParserError);
}

BOOST_AUTO_TEST_SUITE_END()

} // namespace test
} // namespace adapt

