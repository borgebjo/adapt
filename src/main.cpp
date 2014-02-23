#include "options.h"
#include "fitter.h"
#include "parser2d.h"
#include "parsererror.h"
#include "math/point.h"

#include <memory>
#include <iostream>

int main(int argc, char *argv[])
{
   adapt::Options options;

   std::unique_ptr<adapt::Fitter> fitter = options.parse(argc, argv);
   adapt::Parser2d parser(std::cin);
   try
   {
      auto points = parser.parse();

      std::cout << "Read the following points from stdin" << std::endl;
      for (auto point: points)
      {
	 std::cout << point << std::endl;
      }
   }
   catch (adapt::ParserError& e)
   {
      std::cout << "Error occured." << std::endl;
      std::cout << e.what() << std::endl;
      return 1;
   }
   return 0;
}
