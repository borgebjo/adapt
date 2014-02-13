#include "options.h"

int main(int argc, char *argv[])
{
   adapt::Options options;

   options.parse(argc, argv);
   return 0;
}
