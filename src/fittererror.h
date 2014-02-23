#ifndef _FITTERERROR_H_
#define _FITTERERROR_H_

#include <stdexcept>
#include <string>

namespace adapt {

class FitterError : public std::runtime_error
{
public:
   FitterError(const std::string& msg);
};

} // namespace adapt

#endif /* _FITTERERROR_H_ */
