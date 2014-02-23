#include "parser2d.h"
#include "parsererror.h"

#include "math/point.h"

namespace adapt {

Parser2d::Parser2d(std::istream& is) :
theStream(is)
{
}

Parser2d::~Parser2d()
{
}

// Reads points from the input stream.
std::vector<math::Point> Parser2d::parse()
{
   std::vector<math::Point> points{};
   while (theStream)
   {
      math::Point p;
      theStream >> p;
      if (!theStream.eof() && theStream.fail())
      {
	 int currentParseNumber = points.size() + 1;
	 throw ParserError(currentParseNumber);
      }
      else if (!theStream.fail())
      {
	 points.push_back(p);
      }
   }

   return points;
}

} // namespace adapt
