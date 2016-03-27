#ifndef DRIVER
#define DRIVER

#include <string>
#include <cstdint>
#include <functional>
#include <map>

#include "scanner.hpp"
#include "parser.h"
#include "../include/expression.hpp"


namespace Algebra
{

class Driver 
{
public:
	Driver();
	virtual ~Driver();

	void parse(const char *);

	Expression * constant(double);
	Expression * variable(double, const char *);
	Expression * unop(Expression *, const char *);
	Expression * binop(Expression *, Expression *, const char *);
	void deleteAll();

private:
	std::map<std::string, std::function<Expression *(Expression *)>> unops;
	std::map<std::string, std::function<Expression *(Expression *, Expression *)>> binops;
};

}

#endif
