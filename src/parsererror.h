#ifndef _PARSERERROR_H_
#define _PARSERERROR_H_

#include <stdexcept>
#include <string>

namespace adapt {

class ParserError : public std::exception
{
public:
   ParserError(int number);

   virtual const char* what() const noexcept(true);

private:
   int theParserNumber;
   std::string theMessage;
};

} // namespace adapt

#endif /* _PARSERERROR_H_ */
