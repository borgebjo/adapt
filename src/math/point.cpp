#include "math/point.h"

#include <ostream>
#include <istream>

namespace adapt {
namespace math {

Point::Point() :
   Point(0.0, 0.0)
{
}

Point::Point(double x, double y) :
   x_(x),
   y_(y)
{
}

double Point::x() const
{
   return x_;
}

double Point::y() const
{
   return y_;
}

bool operator!=(const Point& lhs, const Point& rhs)
{
   return !(lhs == rhs);
}


bool operator==(const Point& lhs, const Point& rhs)
{
   return (lhs.x() == rhs.x()) && (lhs.y() == rhs.y());
}

std::ostream& operator<<(std::ostream& ost, const Point& p)
{
   ost << p.x() << " " << p.y() << " ";
   return ost;
}

std::istream& operator>>(std::istream& is, Point& p)
{
   double x,y;
   is >> x;
   if (is.fail())
      return is;
   is >> y;
   if (is.fail())
      return is;
   p = Point{x,y};
   return is;
}

}
} // namespace adapt
