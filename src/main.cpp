#include <cstdlib>
#include <iostream>
#include <getopt.h> // for options

#include "expressionFactory.hpp"
#include "expression.hpp"
#include "variable.hpp"
#include "debugger.hpp"
#include "driver.hpp"

using namespace std;
using namespace ExpressionFactory;
using namespace Algebra;


int main(int argc, char *argv[])
{

	Debugger & d = Debugger::instance();

	Driver driver;  

	int option;
    const char* const short_options = "dh";
    const struct option long_options[] = {
        { "debug", 		    		0,  NULL,  'd' },
        { "help", 		    		0,  NULL,  'h' },
        { NULL,         			0,  NULL,   0  }
    };

    // options management
    do
    {
    	option = getopt_long (argc, argv, short_options, long_options, NULL);

    	switch (option)
    	{
    		case 'd':
    			d.set(true);
    			d.debug("\n----------------------- DEBUG MODE ----------------------");
    		break;
    		
    		case 'h':
    			d.set(true);
    			d.debug("\n------------------------- OPTIONS -----------------------");
    			d.debug(".-------------------------------------------------------.");
    			d.debug("| '-d' or '--debug'\t: activate the debug mode\t|");
    			d.debug("| '-h' or '--help'\t: display all options\t\t|");
    			d.debug(".-------------------------------------------------------.");
    		return 0;
    	}
    	driver.parse("exercices/exercices.txt");
	    /*if (optind < argc)
	    {

	    	//driver.parse(argv[optind]);
	    }*/

    } while (option != -1);




	// std::cout << "Les tests se font dans le dossier ./tests/" << std::endl;
	
	// auto callbacks = make_tuple(
	//     [] (int x) { std::cout << x << std::endl; },
	//     [&] () { std::cout << y << std::endl; }, // y is captured by reference
	//     [=] (int x) { std::cout << x + y << std::endl; } // y is captured by value
	//     // other lambdas here, if you want...
 	//    );

    // callbacks(2);


	return EXIT_SUCCESS;
}
