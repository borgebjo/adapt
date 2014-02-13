#include "options.h"

#include <iostream>
#include <sstream>

#include <boost/program_options.hpp>
namespace po = boost::program_options;
using namespace std;

namespace adapt {

void Options::parse(int argc, char *argv[])
{
   stringstream description;
   description << "adapt is about fitting shapes to a set of points." << endl
	       << endl
	       << "Points are given on the following format" << endl
	       << endl
	       << "x0 y0 x1 y1 ... xn yn." << endl
	       << endl
	       << "It is possible to give the points as standard input." << endl
	       << endl
	       << "Options";

   po::options_description desc(description.str());
   desc.add_options()
      ("help,h", "print this")
      ("circle", "fit a circle to the given points");

   po::variables_map vm;
   po::store(po::parse_command_line(argc, argv, desc), vm);
   po::notify(vm);

   if (vm.count("help"))
   {
      cout << desc << endl;
      return;
   }

   if (vm.count("circle")) {
      cout << "Fit a circle" << endl;
      double a;
   } else {
      cout << "Nothing to do." << endl;
   }
}

} // namespace adapt
