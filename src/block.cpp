#include <list>
#include <string>

#include "affectation.hpp"
#include "block.hpp"


Block::Block(): _expressions()
{}

Block::Block(const std::list<Affectation *> expressions): _expressions(expressions)
{}

Block::Block(const Block & block): _expressions(block._expressions)
{}

Block::~Block()
{}

double Block::eval()
{
	Expression * tmp = _expressions.back();
	return tmp->eval();
}

void Block::add(Affectation * expression)
{
	_expressions.push_back(expression);
}

void Block::execute()
{
	std::list<Affectation *>::const_iterator it = _expressions.begin();
	while (it != _expressions.end())
	{
		Affectation * tmp = *it;
		new Affectation(*tmp);
		it++;
	}
}

void Block::rollback()
{
	std::list<Affectation *>::iterator it = _expressions.begin();
	while (it != _expressions.end())
	{
		Affectation * tmp = *it;
		tmp->rollback();
		it++;
	}
}

std::string Block::display() const
{
	std::list<Affectation *>::const_iterator it = _expressions.begin();
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

