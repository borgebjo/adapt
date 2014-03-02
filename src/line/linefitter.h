#ifndef _LINEFITTER_H_
#define _LINEFITTER_H_

#include "fitter.h"

#include <vector>
#include <iosfwd>

namespace adapt {
namespace math { class Point; }
namespace line {

class LineFitter : public adapt::Fitter
{
public:
   LineFitter();
   virtual ~LineFitter();

   virtual void adapt(const std::vector<math::Point>&);
   virtual void publish(std::ostream& ost) const;

private:
   double theA;
   double theB;
};


} // namespace line
} // namespace adapt

#endif /* _LINEFITTER_H_ */
