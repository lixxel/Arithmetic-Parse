#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "or.h"
#include "and.h"
#include "equalto.h"
#include "not.h"
#include "conditional.h"


SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& fin)
{
    Expression* left;
    Expression* right;
    char operation, question, paren;

    left = Operand::parse(fin);
    fin >> operation;
    if (operation==':'){
    	right = Operand::parse(fin);
    	fin >> question;
    	Expression* conditional = Operand::parse(fin);
    	fin >> paren;
    	return new Conditional(left, right, conditional);
    }
    else if (operation=='!'){
    	fin >> paren;
    	return new Not(left, left);
    }
    else {
    	right = Operand::parse(fin);
    	fin >> paren;
    	switch (operation)
    	{
    	case '+':
    		return new Plus(left, right);
    	case '-':
    		return new Minus(left, right);
    	case '*':
    		return new Times(left, right);
    	case '/':
    		return new Divide(left, right);
    	case '>':
			return new GreaterThan(left, right);
    	case '<':
    		return new LessThan(left, right);
    	case '|':
    		return new Or(left, right);
    	case '&':
    		return new And(left, right);
    	case '=':
    		return new EqualTo(left, right);
    	}
    }
    return 0;
}
