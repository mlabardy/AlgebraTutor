#include <cstdlib>
#include <iostream>
#include <getopt.h> // for options

#include "../include/expressionFactory.hpp"
#include "../include/expression.hpp"
#include "../include/variable.hpp"
#include "../include/affectation.hpp"
#include "../include/block.hpp"
#include "../include/ifElse.hpp"
#include "../include/debugger.hpp"
#include "../include/for.hpp"

#define M_PI 3.14

using namespace std;
using namespace ExpressionFactory;


void unaryTests();
void binaryTests();
void variableTests();
void conditionalTests();
void affectationTests();
void blockTests();
void ifElse();
void forLoop();
void derivationTests();
void simplificationsTests();

int main(int argc, char **argv)
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


	// unaryTests();
	// binaryTests();
	// variableTests();
    // conditionalTests();
    // affectationTests();
    // blockTests();
    // ifElse();
    // forLoop();
    // derivationTests();
    simplificationsTests();


	return 0;
}


void unaryTests()
{
	// Expression * c = sum(constant(M_PI/3), constant(2.0));
	Expression * c = constant(2);
	cerr << *c << " = " << c->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();
}

void binaryTests()
{
	Expression * s = sum(constant(1.0), product(constant(2.0), sinus(constant(M_PI/6.0))));
	cerr << *s << " = " << s->eval() << endl;

	Expression * comp = greaterOrEqual(s, constant(1.8));
	cerr << *comp << " = " << comp->eval() << endl;

	Variable::deleteAll();
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

	// plante ici -> c'est normal
	// cout << *y << " = " << y->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();
}

void conditionalTests()
{
	Expression * test = ternary(greaterOrEqual(variable("x"), constant(0.0)),
										cosinus(variable("x")),
										cosinus(product(constant(2.0), variable("x"))));
	Expression * test1 = ternary(greaterThan(variable("x"), constant(0.0)),
										cosinus(variable("x")),
										cosinus(product(constant(2.0), variable("x"))));
	Expression * test2 = ternary(lessThan(variable("x"), constant(0.0)),
										cosinus(variable("x")),
										cosinus(product(constant(2.0), variable("x"))));
	Expression * test3 = ternary(equal(variable("x"), constant(0.0)),
										cosinus(variable("x")),
										cosinus(product(constant(2.0), variable("x"))));
	Expression * test4 = ternary(different(variable("x"), constant(0.0)),
										cosinus(variable("x")),
										cosinus(product(constant(2.0), variable("x"))));

	Variable * x = variable("x", M_PI/3.0);

	cerr << *x << " = " << x->eval() << endl;
	cerr << *test << " = " << test->eval() << endl;

	cerr << *test1 << " = " << test1->eval() << endl;

	cerr << *test2 << " = " << test2->eval() << endl;

	cerr << *test3 << " = " << test3->eval() << endl;

	cerr << *test4 << " = " << test4->eval() << endl;

	x->set( -M_PI/3.0);

	cerr << *x << " = " << x->eval() << endl;
	cerr << *test << " = " << test->eval() << endl;

	cerr << *test1 << " = " << test1->eval() << endl;

	cerr << *test2 << " = " << test2->eval() << endl;

	cerr << *test3 << " = " << test3->eval() << endl;

	cerr << *test4 << " = " << test4->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();

}

void affectationTests()
{
	Variable * x = variable("x", 10);
	Variable * y = variable("y", 5);

	cerr << *x << " = " << x->eval() << endl;
	cerr << *y << " = " << y->eval() << endl;

	Affectation * test = sumAffectation(x, y);
	cerr << *test << " = " << test->eval() << endl;
	x->set(10);
	y->set(5);

	Affectation * test1 = differenceAffectation(x, y);
	cerr << *test1 << " = " << test1->eval() << endl;
	x->set(10);
	y->set(5);

	Affectation * test2 = productAffectation(x, y);
	cerr << *test2 << " = " << test2->eval() << endl;
	x->set(10);
	y->set(5);

	Affectation * test3 = quotientAffectation(x, y);
	cerr << *test3 << " = " << test3->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();

}

void blockTests()
{
	Affectation * s = affectation(variable("x"), sum(constant(1.0), product(constant(2.0), sinus(constant(M_PI/6.0)))));
	Affectation * m = affectation(variable("y"), product(constant(1.0), product(constant(2.0), cosinus(constant(M_PI/6.0)))));
	Affectation * q = affectation(variable("z"), quotient(constant(1.0), product(constant(2.0), sinus(constant(M_PI/6.0)))));

	Block * b = block();
	b->add(s);
	b->add(m);
	b->add(q);

	cerr << *b << " = " << b->eval() << endl;
	cerr << *q << " = " << q->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();
}

void ifElse()
{
	Expression * x = variable("x", 3);
	Expression * s = sum(constant(1.0), product(constant(2.0), sinus(constant(M_PI/6.0))));
	Expression * m = product(constant(1.0), product(constant(2.0), cosinus(constant(M_PI/6.0))));
	Expression * q = quotient(constant(1.0), product(constant(2.0), sinus(constant(M_PI/6.0))));

	cerr << *x << " = " << x->eval() << endl;
	cerr << *s << " = " << s->eval() << endl;
	cerr << *q << " = " << q->eval() << endl;

	Expression * test = greaterThan(variable("x"), constant(0.0));

	Affectation * af = affectation(variable("y"), s);
	Affectation * of = affectation(variable("y"), q);

	Block * i = block();
	i->add(af);

	Block * e = block();
	e->add(of);

	Expression * ite = ifThenElse(test, i, e);
	cerr << *test << " = " << test->eval() << endl;
	cerr << *ite << " = " << ite->eval() << endl;

	ite->eval(); // obligatoire

	Variable * var = variable("y");
	cerr << *var << " = " << var->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();
}

void forLoop()
{
	Affectation * start = affectation(variable("x"), constant(1));
	ComparatorFactory * condition = lessOrEqual(variable("x"), constant(5));
	Affectation * end = sumAffectation(variable("x"), constant(1));

	Block * expressions = block();

	Variable * t = variable("t", 1);
	double value = t->eval();
	Affectation * a = sumAffectation(t, variable("x"));

	expressions->add(a);

	For * f = forLoop(start, condition, end, expressions);
	cerr << *f << endl;

	f->eval(); // obligatoire

	cerr << *t << " = " << t->eval() << endl;
	cerr << *variable("x") << " = " << variable("x")->eval() << endl;

	Variable::deleteAll();
	Expression::deleteAll();
}

void derivationTests()
{
	Expression * monome1 = product(constant(-4), exponantial(variable("x"), constant(3)));
	Expression * monome2 = product(constant(2), exponantial(variable("x"), constant(2)));
	Expression * monome3 = product(constant(-3), exponantial(variable("x"), constant(1)));
	Expression * monome4 = cosinus(exponantial(variable("x"), constant(5)));

	Expression * e = quotient(constant(1), variable("x")); // 1/x

	Expression * c = cosinus(exponantial(variable("x"), constant(3))); // cos(x^3)

	Expression * s = sum(monome1, sum(monome2, sum(monome3, monome4))); // −4x^3 +2x^2 −3x +1

	Expression * si = sinus(product(constant(5), exponantial(variable("x"), constant(2)))); // sin(5x^2)

	cerr << *s << endl;
	cerr << *(s->derivation()) << endl;

	cerr << *e << endl;
	cerr << *(e->derivation()) << endl;

	cerr << *c << endl;
	cerr << *(c->derivation()) << endl;

	cerr << *si << endl;
	cerr << *(si->derivation()) << endl;

	Variable::deleteAll();
	Expression::deleteAll();
}

void simplificationsTests()
{
	Expression * monome1 = product(constant(-4), exponantial(variable("x"), constant(3)));
	Expression * monome2 = product(constant(2), exponantial(variable("x"), constant(2)));
	Expression * monome3 = product(constant(-3), exponantial(variable("x"), constant(1)));
	Expression * monome4 = cosinus(exponantial(variable("x"), constant(5)));

	Expression * e = quotient(constant(1), variable("x")); // 1/x

	Expression * c = cosinus(exponantial(variable("x"), constant(3))); // cos(x^3)

	Expression * s = sum(monome1, sum(monome2, sum(monome3, monome4))); // −4x^3 +2x^2 −3x +1

	Expression * si = sinus(product(constant(5), exponantial(variable("x"), constant(2)))); // sin(5x^2)

	Expression * l = product(constant(2), product(constant(5), variable("x")));

	Expression * l2 = product(product(constant(3), variable("y")), product(constant(5), variable("x")));

	//Expression * l3 = product(l, l2);

	cerr << *l << endl;
	cerr << *(l->simplification()) << endl;

	cerr << *l2 << endl;
	cerr << *(l2->simplification()) << endl;

	/*cerr << *s << endl;
	cerr << *(s->derivation()) << endl;

	cerr << *e << endl;
	cerr << *(e->derivation()) << endl;

	cerr << *c << endl;
	cerr << *(c->derivation()) << endl;

	cerr << *si << endl;
	cerr << *(si->derivation()) << endl;*/

	Variable::deleteAll();
	Expression::deleteAll();
}
