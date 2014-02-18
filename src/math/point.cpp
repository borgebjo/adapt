#include "math/point.h"

#include <ostream>

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
   ost << p.x() << " " << p.y();
   return ost;
}

}
} // namespace adapt
