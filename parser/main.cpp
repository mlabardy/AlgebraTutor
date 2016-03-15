#include <iostream>
#include <cstdlib>

#include "driver.hpp"

using namespace Algebra;

int main(void)
{

   Driver driver;
   
   driver.parse("exercices.txt");
   
   // std::cout << "Results\n";
   
   // driver.print(std::cout) << "\n";

   return EXIT_SUCCESS;
}
