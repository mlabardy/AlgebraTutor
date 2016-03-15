#include <iostream>
#include <cstdlib>

#include "driver.hpp"

using namespace Algebra;


int main(void)
{

   Driver driver;
   
   driver.parse("exercices.txt");

   return EXIT_SUCCESS;
}
