#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"
#include "scanner.hpp"
#include "parser.h"

namespace Algebra {

Driver::~Driver()
{
   // delete scanner;
   // scanner = nullptr;
   // delete parser;
   // parser = nullptr;
}

void 
Driver::parse( const char * const filename )
{
	assert( filename != nullptr );

	std::ifstream in_file( filename );

	if(!in_file.good()) 
	{
		exit( EXIT_FAILURE );
	}

    Algebra::Scanner scanner(&in_file);

    Algebra::Parser parser(scanner, *this);
    
    if(parser.parse() != 0)
	{
		std::cerr << "Parse failed!!\n";
	}

	// Algebra::Parser  & parser;
	// Algebra::Scanner & scanner;

	// assert( filename != nullptr );
	// std::ifstream in_file( filename );

	// if( ! in_file.good() ) exit( EXIT_FAILURE );

	// // delete(scanner);
	// try
	// {
	// 	scanner = Algebra::Scanner( &in_file );
	// }
	// catch( std::bad_alloc &ba )
	// {
	// 	std::cerr << "Failed to allocate scanner: (" <<
	//      ba.what() << "), exiting!!\n";
	// 	exit( EXIT_FAILURE );
	// }

	// // delete(parser); 
	// try
	// {
	// 	parser( (scanner) /* scanner */, 
	//                               (*this) /* driver */ );
	// }
	// catch( std::bad_alloc &ba )
	// {
	// 	std::cerr << "Failed to allocate parser: (" << 
	//      ba.what() << "), exiting!!\n";
	//   exit( EXIT_FAILURE );
	// }
	// const int accept( 0 );
	// if( parser.parse() != accept )
	// {
	// 	std::cerr << "Parse failed!!\n";
	// }
}

void 
Driver::add_upper()
{ 
   uppercase++; 
   chars++; 
   words++; 
}

void 
Driver::add_lower()
{ 
   lowercase++; 
   chars++; 
   words++; 
}

void 
Driver::add_word( const std::string &word )
{
   words++; 
   chars += word.length();
   for(const char &c : word ){
      if( islower( c ) )
      { 
         lowercase++; 
      }
      else if ( isupper( c ) ) 
      { 
         uppercase++; 
      }
   }
}

void 
Driver::add_newline()
{ 
   lines++; 
   chars++; 
}

void 
Driver::add_char()
{ 
   chars++; 
}

void Driver::operation(double x, double y, const char * op)
{
	printf("%f %s %f\n", x, op, y);
}

void Driver::cos(double x)
{
	printf("cos(%f)\n", x);
}

void Driver::get(double x)
{
	printf("%f\n", x);
}

// std::ostream& 
// Driver::print( std::ostream &stream )
// {
//    stream << "Uppercase: " << uppercase << "\n";
//    stream << "Lowercase: " << lowercase << "\n";
//    stream << "Lines: " << lines << "\n";
//    stream << "Words: " << words << "\n";
//    stream << "Characters: " << chars << "\n";
//    return(stream);
// }
}
