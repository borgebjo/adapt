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
   if (!fitter)
      return 1;
   adapt::Parser2d parser(std::cin);
   try
   {
      auto points = parser.parse();
      fitter->adapt(points);
      fitter->publish(std::cout);
      std::cout << std::endl;
   }
   catch (adapt::ParserError& e)
   {
      std::cout << "Error occured." << std::endl;
      std::cout << e.what() << std::endl;
      return 1;
   }
   catch (std::exception& e)
   {
      std::cerr << e.what() << std::endl;
   }
   return 0;
}
