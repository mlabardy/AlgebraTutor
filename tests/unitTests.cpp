#include <cstdlib>
#include <iostream>
#include <getopt.h> // for options

#include "../include/expressionFactory.hpp"
#include "../include/expression.hpp"
#include "../include/variable.hpp"
#include "../include/affectation.hpp"
#include "../include/debugger.hpp"

#define M_PI 3.14

using namespace std;
using namespace ExpressionFactory;


void unaryTests();
void binaryTests();
void variableTests();

int main(int argc, char * argv [])
{
	Debugger & d = Debugger::instance();

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

    } while (option != -1);

	
	
	unaryTests();
	// binaryTests();
	// variableTests();


	return 0;
}

void unaryTests()
{
	Expression * c = sum(constant(M_PI/3), constant(2.0));
	cerr << *c << " = " << c->eval() << endl;
	Expression::deleteAll();
}

void binaryTests()
{
	Expression * s = sum(constant(1.0), product(constant(2.0), sinus(constant(M_PI/6.0))));
	cerr << *s << " = " << s->eval() << endl;

	Expression * comp = greaterOrEqual(s, constant(1.8));
	cerr << *comp << " = " << comp->eval() << endl;

	Expression::deleteAll();
}

void variableTests()
{

	Variable * x = variable("x", 3.0);
	Variable * y = variable("y");

	cerr << *x << " = " << x->eval() << endl;
	cerr << *y << " = " << y->eval() << endl;

	Expression * exp = sum(constant(1.0), sum(constant(2.0), variable("x")));

	Expression * a = affectation(variable("y"), exp);

	cerr << *a << " = " << a->eval() << endl;
	cerr << *y << " = " << y->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();

	// plante ici -> c'est normal
	// cout << *y << " = " << y->eval() << endl;
}

