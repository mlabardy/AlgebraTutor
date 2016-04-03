#include <iostream>

#include "debugger.hpp"


Debugger Debugger::d = Debugger();

Debugger::Debugger(): _activate(false)
{}

Debugger::~Debugger()
{}

Debugger & Debugger::instance()
{
	return Debugger::d;
}

void Debugger::set(bool boolean)
{
	_activate = boolean;
}

void Debugger::debug(std::ostream & os, const std::string & message)
{
	if (_activate == true)
	{
		os << message << std::endl;	
	}
}

void Debugger::debug(const std::string & message)
{
	if (_activate == true)
	{
		std::cerr << message << std::endl;
	}
}
