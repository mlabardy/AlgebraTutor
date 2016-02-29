#include <iostream>

#include "operator.hpp"


namespace Operator 
{
	const std::string name(Binary binaryOperator) 
	{
		switch(binaryOperator) {
			case ADD:
			return "+";
			case SUB:
			return "-";
			case DIV:
			return "/";
			case MUL:
			return "*";
			case LOE:
			return "<=";
			case GOE:
			return ">=";
			case LT:
			return "<";
			case GT:
			return ">";
			case EQ:
			return "==";
			case DIF:
			return "!=";
		}
		return "";
	}

	const std::string name(Unary unaryOperator) 
	{
		switch(unaryOperator) {
			case COS:
			return "cos";
			case SIN:
			return "sin";
			case EXP:
			return "^";
			case TAN:
			return "tan";
			case ATAN:
			return "atan";
			case ACOS:
			return "acos";
			case ASIN:
			return "asin";
		}
		return "";
	}
}
