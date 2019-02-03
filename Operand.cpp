#include <cctype>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream& fin)
{
    char paren;
    double value;

    fin >> ws;
    if (isdigit(fin.peek()))
    {
        fin >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (fin.peek() == '(')
    {
        fin >> paren;
        return SubExpression::parse(fin);
    }
    else
        return new Variable(parseName(fin));
    return 0;
}
