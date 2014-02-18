#ifndef _FITTER_H_
#define _FITTER_H_
#include <vector>

namespace adapt {
namespace math {
class Point;
}

class Fitter
{
public:
   virtual ~Fitter() = 0;
   virtual void adapt(const std::vector<math::Point>&) = 0;
};
inline Fitter::~Fitter() {}
} // namespace adapt

#endif /* _FITTER_H_ */
