#ifndef _POINT_H_
#define _POINT_H_

namespace adapt {
namespace math {

class Point
{
public:
   Point();
   Point(double x, double y);

   double x() const;
   double y() const;

private:
   double x_;
   double y_;
};

bool operator!=(const Point& lhs, const Point& rhs);
bool operator==(const Point& lhs, const Point& rhs);


}
} // namespace adapt

#endif /* _POINT_H_ */

