#ifndef _LINEFITTER_H_
#define _LINEFITTER_H_

#include "fitter.h"

#include <vector>

namespace adapt {
namespace line {

class LineFitter : public adapt::Fitter
{
public:
   LineFitter() = default;
   virtual ~LineFitter();

   virtual void adapt(const std::vector<math::Point>&);
};


} // namespace line
} // namespace adapt

#endif /* _LINEFITTER_H_ */
