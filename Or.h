/*
 * Or.h
 *
 *  Created on: May 3, 2018
 *      Author: steph
 */

class Or: public SubExpression
{
public:
    Or(Expression* left, Expression* right):
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
       return (left->evaluate() || right->evaluate());
    }
};
