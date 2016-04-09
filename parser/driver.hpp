#ifndef DRIVER
#define DRIVER

#include <string>
#include <cstdint>
#include <functional>
#include <vector>
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
	void block();
	Block * currentBlock();
	Block * previousBlock();
	void ifElse(Expression * cond, Block * x, Block * y);
	void deleteAll();

private:
	std::string _str;
	std::vector<Block *> _blocks;
	std::map<std::string, std::function<Expression *(Expression *)>> unops;
	std::map<std::string, std::function<Expression *(Expression *, Expression *)>> binops;
	std::map<std::string, std::function<ComparatorFactory *(Expression *, Expression *)>> comps;
	std::map<std::string, std::function<Affectation *(Variable *, Expression *)>> affect;
};

}

#endif
