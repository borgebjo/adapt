#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include <memory>

namespace adapt {
class Fitter;

class Options
{
public:
   std::unique_ptr<Fitter> parse(int argc, char* argv[]);
};

} // namespace adapt

#endif /* _OPTIONS_H_ */
