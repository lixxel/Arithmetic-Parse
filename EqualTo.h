/*
 * EqualTo.h
 *
 *  Created on: May 3, 2018
 *      Author: steph
 */

class EqualTo: public SubExpression
{
public:
    EqualTo(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return left->evaluate() == right->evaluate();
    }
};
