/*
 * LessThan.h
 *
 *  Created on: May 3, 2018
 *      Author: steph
 */

class LessThan: public SubExpression
{
public:
    LessThan(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
    	return (left->evaluate() < right->evaluate());
    }
};
