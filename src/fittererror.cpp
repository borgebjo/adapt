#include "fittererror.h"

namespace adapt {

FitterError::FitterError(const std::string& msg) :
   std::runtime_error(msg)
{
}

} // ns adapt
