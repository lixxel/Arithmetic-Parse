/*
 * GreaterThan.h
 *
 *  Created on: May 3, 2018
 *      Author: steph
 */

class GreaterThan: public SubExpression
{
public:
    GreaterThan(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return (left->evaluate() > right->evaluate());
    }
};
