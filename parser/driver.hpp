#ifndef DRIVER
#define DRIVER

#include <string>
#include <cstdint>
#include "scanner.hpp"
#include "parser.h"

namespace Algebra {

class Driver 
{
public:
	Driver() = default;

	virtual ~Driver();

	void parse(const char *filename );

	void add_upper();
	void add_lower();
	void add_word(const std::string & word);
	void add_newline();
	void add_char();

	void operation(double x, double y, const char * op);
	void cos(double x);
	void get(double x);

   // std::ostream& print(std::ostream & stream);
private:
   int chars      = 0;
   int words      = 0;
   int lines      = 0;
   int uppercase  = 0;
   int lowercase  = 0;

   // Algebra::Parser  & parser;
   // Algebra::Scanner & scanner;
};

} /* end namespace MC */

#endif