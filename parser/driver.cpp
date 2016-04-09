#include <cctype>
#include <fstream>
#include <cassert>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "driver.hpp"
#include "scanner.hpp"
#include "parser.h"
#include "expressionFactory.hpp"
#include "comparatorFactory.hpp"
#include "expression.hpp"
#include "variable.hpp"
#include "affectation.hpp"
#include "block.hpp"
#include "debugger.hpp"


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
	comps["<"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::lessThan(lexpr, rexpr); };
	comps[">"] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::greaterThan(lexpr, rexpr); };
	comps["=="] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::equal(lexpr, rexpr); };
	comps["!="] = [](Expression * lexpr, Expression * rexpr) { return ExpressionFactory::different(lexpr, rexpr); };

	affect["="] = [](Variable * variable, Expression * expr) { return ExpressionFactory::affectation(variable, expr); };
	affect["+="] = [](Variable * variable, Expression * expr) { return ExpressionFactory::sumAffectation(variable, expr); };
	affect["-="] = [](Variable * variable, Expression * expr) { return ExpressionFactory::differenceAffectation(variable, expr); };
	affect["*="] = [](Variable * variable, Expression * expr) { return ExpressionFactory::productAffectation(variable, expr); };
	affect["/="] = [](Variable * variable, Expression * expr) { return ExpressionFactory::quotientAffectation(variable, expr); };
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
    
    _str = std::string("");
    block();

    if(parser.parse() != 0)
	{
		std::cerr << "Parse failed!!\n";
	}

    Debugger::instance().debug(_str);

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

	/*std::ostringstream stringOfValue;
	stringOfValue << expr->eval();

	str.append(expr->display());
	str.append(" = ");
	str.append(stringOfValue.str());
	str.append("\n");*/

	//Debugger::instance().debug(str);
	//std::cout << *expr << " = " << expr->eval() << std::endl;
	return expr;
}

Variable * Driver::variable(const char * id)
{
	Variable * expr = ExpressionFactory::variable(std::string(id));
	return expr;
}

Affectation * Driver::affectation(Expression * expression, const char * variable, const char * op)
{
	Variable * var = ExpressionFactory::variable(std::string(variable));
	Affectation * expr = affect.find(std::string(op))->second(var, expression);

	std::ostringstream stringOfValue;
	stringOfValue << expr->eval();

	_str.append(expr->display());
	_str.append(" = ");
	_str.append(stringOfValue.str());
	_str.append("\n");
	_str.append(var->display());
	_str.append(" = ");
	_str.append(stringOfValue.str());
	_str.append("\n\n");

	//Debugger::instance().debug(str);

	return expr;
}

Expression * Driver::unop(Expression * x, const char * op)
{
	Expression * expr = unops.find(std::string(op))->second(x);

	std::ostringstream stringOfValue;
	stringOfValue << expr->eval();

	_str.append("r:");
	_str.append(expr->display());
	_str.append(" = ");
	_str.append(stringOfValue.str());
	_str.append("\n");

	//Debugger::instance().debug(str);

	return expr;
}

Expression * Driver::binop(Expression * x, Expression * y, const char * op)
{
	Expression * expr = binops.find(std::string(op))->second(x, y);

	std::ostringstream stringOfValue;
	stringOfValue << expr->eval();

	_str.append("r:");
	_str.append(expr->display());
	_str.append(" = ");
	_str.append(stringOfValue.str());
	_str.append("\n");

	//Debugger::instance().debug(str);

	return expr;
}

ComparatorFactory * Driver::comp(Expression * x, Expression * y, const char * op)
{
	ComparatorFactory * expr = comps.find(std::string(op))->second(x, y);

	_str.append(expr->display());
	_str.append(" = ");

	_str.append((expr->eval() == 1) ? "true" : "false");
	_str.append("\n");
	//Debugger::instance().debug(str);

	return expr;
}

Expression * Driver::ternary(Expression * cond, Expression * x, Expression * y)
{
	Expression * expr = ExpressionFactory::ternary(cond, x, y);

	/*std::string str(expr->display());
	str.append(" = ");

	str.append((expr->eval() == 1) ? x->display() : y->display());

	Debugger::instance().debug(str);*/

	return expr;
}

void Driver::block()
{
	Block * currentBlock = ExpressionFactory::block();
	_blocks.push_back(currentBlock);
}

Block * Driver::currentBlock()
{
	return _blocks[_blocks.size()-1];
}

Block * Driver::previousBlock()
{
	return _blocks[_blocks.size()-2];
}

void Driver::ifElse(Expression * cond, Block * x, Block * y)
{
	IfElse * ie = ExpressionFactory::ifThenElse(cond, x, y);

	_str.append(ie->display());
	_str.append("\n");
}

void Driver::deleteAll()
{
	Expression::deleteAll();
	Variable::deleteAll();
}

}
