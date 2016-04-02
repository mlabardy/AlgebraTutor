#ifndef DRIVER
#define DRIVER

#include <string>
#include <cstdint>
#include <functional>
#include <tuple>
#include <map>

#include "scanner.hpp"
#include "parser.h"
#include "../include/variable.hpp"
#include "../include/expression.hpp"
#include "../include/comparatorFactory.hpp"


namespace Algebra
{

class Driver 
{
public:
	Driver();
	virtual ~Driver();

	void parse(const char *);

	Expression * constant(double);
	Variable * variable(double, const char *);
	Expression * unop(Expression *, const char *);
	Expression * binop(Expression *, Expression *, const char *);
	Expression * ternary(Expression *, Expression *, Expression *);
	ComparatorFactory * comp(Expression * x, Expression * y, const char * op);

	void deleteAll();

private:
	std::map<std::string, std::function<Expression *(Expression *)>> unops;
	std::map<std::string, std::function<Expression *(Expression *, Expression *)>> binops;
	std::map<std::string, std::function<ComparatorFactory *(Expression *, Expression *)>> comps;
};

}

#endif
