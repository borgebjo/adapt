#include "parsererror.h"
#include <sstream>

namespace adapt {

ParserError::ParserError(int number) :
   theParserNumber{number}
{
   std::stringstream ss;
   ss << "Parsing error at item number " << number;
   theMessage = ss.str();
}

const char* ParserError::what() const noexcept(true)
{
   return theMessage.c_str();
}

} // namespace adapt
