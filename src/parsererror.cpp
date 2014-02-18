#include "parsererror.h"

namespace adapt {

ParserError::ParserError(int number) :
   theParserNumber{number}
{
}

const char* ParserError::what() const noexcept(true)
{
}

} // namespace adapt
