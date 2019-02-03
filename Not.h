/*
 * Not.h
 *
 *  Created on: May 3, 2018
 *      Author: steph
 */

class Not: public SubExpression
{
public:
    Not(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return !(left->evaluate());
    }
};
