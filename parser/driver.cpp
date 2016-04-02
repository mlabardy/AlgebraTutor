#include <cctype>
#include <fstream>
#include <cassert>
#include <map>
#include <functional>
#include <string>
#include <iostream>
#include <tuple>

#include "driver.hpp"
#include "scanner.hpp"
#include "parser.h"
#include "expressionFactory.hpp"
#include "comparatorFactory.hpp"
#include "expression.hpp"
#include "variable.hpp"


namespace Algebra {

Driver::Driver()
{
	unops["cos"] = [](Expression * expr) { return ExpressionFactory::cosinus(expr); };
	unops["sin"] = [](Expression * expr) { return ExpressionFactory::sinus(expr); };

	binops["+"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::sum(lexpr, rexpr); };
	binops["-"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::difference(lexpr, rexpr); };
	binops["*"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::product(lexpr, rexpr); };
	binops["/"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::quotient(lexpr, rexpr); };
	binops["^"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::exponantial(lexpr, rexpr); };

	comps["<="] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::lessOrEqual(lexpr, rexpr); };
	comps[">="] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::greaterOrEqual(lexpr, rexpr); };
}

Driver::~Driver() { }

void Driver::parse(const char * filename)
{
	assert(filename != nullptr);

	std::ifstream in_file(filename);

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
	Expression::deleteAll();
	Variable::deleteAll();
}

Expression * Driver::constant(double x)
{
	Expression * expr = ExpressionFactory::constant(x);
	//std::cout << expr->display() << std::endl;
	return expr;
}

Variable * Driver::variable(double x, const char * id)
{
	Variable * expr = ExpressionFactory::variable(std::string(id), x);
	//std::cout << *expr << " = " << expr->eval() << std::endl;
	return expr;
}

Expression * Driver::unop(Expression * x, const char * op)
{
	Expression * expr = unops.find(std::string(op))->second(x);
	//std::cout << *expr << std::endl;
	return expr;
}

Expression * Driver::binop(Expression * x, Expression * y, const char * op)
{
	Expression * expr = binops.find(std::string(op))->second(x, y);
	std::cout << *expr << " = " << expr->eval() << std::endl;
	//Expression::deleteAll();
	return expr;
}

ComparatorFactory * Driver::comp(Expression * x, Expression * y, const char * op)
{
	ComparatorFactory * expr = comps.find(std::string(op))->second(x, y);
	return expr;
}

Expression * Driver::ternary(Expression * cond, Expression * x, Expression * y)
{
	Expression * expr = ExpressionFactory::ternary(cond, x, y);
	std::cout << *expr << " = " << expr->eval() << std::endl;
	return expr;
}

void Driver::deleteAll()
{
	Expression::deleteAll();
	Variable::deleteAll();
}

}
