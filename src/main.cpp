#include "options.h"
#include "fitter.h"
#include <memory>
#include <iostream>

int main(int argc, char *argv[])
{
   adapt::Options options;

   std::unique_ptr<adapt::Fitter> fitter = options.parse(argc, argv);
   return 0;
}
