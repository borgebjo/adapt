#include "math/point.h"

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

}
} // namespace adapt
