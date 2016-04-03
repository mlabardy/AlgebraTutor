#include <list>
#include <string>

#include "block.hpp"


Block::Block()
{}

Block::~Block()
{}

double Block::eval()
{
	Expression * tmp = _expressions.back();
	return tmp->eval();
}

void Block::add(Expression * expression)
{
	_expressions.push_back(expression);
}

std::string Block::display() const
{
	std::list<Expression *>::const_iterator it = _expressions.begin();
	std::string str("{\n");
	while (it != _expressions.end())
	{
		Expression * tmp = *it;
		str.append("\t");
		str.append(tmp->display());
		str.append("\n");
		it++;
	}
	str.append("}");
	return str;
}

std::ostream & operator << (std::ostream & os, const Block & block)
{
	os << block.display();
	return os;
}

