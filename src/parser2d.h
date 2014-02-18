#ifndef _PARSER2D_H_
#define _PARSER2D_H_

#include <vector>
#include <istream>

namespace adapt {
namespace math {
class Point;
}

class Parser2d
{
public:
   Parser2d(std::istream& is);
   virtual ~Parser2d();

   std::vector<math::Point> parse();

private:
   std::istream& theStream;
};

} // namespace adapt

#endif /* _PARSER2D_H_ */
