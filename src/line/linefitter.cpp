#include "line/linefitter.h"
#include "fittererror.h"
#include "math/point.h"
#include "math/statistics.h"

#include <ostream>

namespace adapt {
namespace line {
class Output;

LineFitter::LineFitter() :
   theA{0.0},
   theB{0.0}
{
}

LineFitter::~LineFitter()
{
}

void LineFitter::adapt(const std::vector<math::Point>& points)
{
   if (points.size() < 2)
      throw FitterError("LineFitter got less than two points.");

   std::vector<double> x_values;
   std::vector<double> y_values;
   for (auto point: points)
   {
      x_values.push_back(point.x());
      y_values.push_back(point.y());
   }

   theA = math::Covariance(x_values, y_values)/math::Variance(x_values);
   theB = math::Mean(y_values) - theA*math::Mean(x_values);
}

void LineFitter::publish(std::ostream& ost) const

{
   ost << theA << " " << theB;
   return;
}

} // namespace line
} // namespace adapt
