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

	string filename;

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
    	//driver.parse("exercices/test.txt");
	    if (optind < argc)
	    {
	    	filename = string(argv[optind++]);
	    }
    } while (option != -1);


    driver.parse(filename.c_str());

    return EXIT_SUCCESS;
}
