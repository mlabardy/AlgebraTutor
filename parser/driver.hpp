#ifndef DRIVER
#define DRIVER

#include <string>
#include <cstdint>
#include <functional>
#include <map>

#include "scanner.hpp"
#include "parser.h"
#include "../include/variable.hpp"
#include "../include/expression.hpp"
#include "../include/comparatorFactory.hpp"
#include "../include/block.hpp"
#include "../include/affectation.hpp"


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
	Variable * variable(const char *);
	Affectation * affectation(Expression *, const char *, const char *);
	Expression * unop(Expression *, const char *);
	Expression * binop(Expression *, Expression *, const char *);
	Expression * ternary(Expression *, Expression *, Expression *);
	ComparatorFactory * comp(Expression * x, Expression * y, const char * op);
	Block * block(Block *);
	void ifElse(Expression *, Block *, Block *);
	void forLoop(Affectation *, ComparatorFactory *, Affectation *, Block *);
	void deleteAll();

private:
	std::string _str;
	std::map<std::string, std::function<Expression *(Expression *)>> unops;
	std::map<std::string, std::function<Expression *(Expression *, Expression *)>> binops;
	std::map<std::string, std::function<ComparatorFactory *(Expression *, Expression *)>> comps;
	std::map<std::string, std::function<Affectation *(Variable *, Expression *)>> affect;
};

}

#endif
