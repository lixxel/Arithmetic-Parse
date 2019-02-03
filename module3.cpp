#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& fin);

int main()
{
    Expression* expression;
    char paren, comma;
    cout<< "Starting...\n";

    ifstream fin("inFile.txt");

        string line;

        while (getline(fin, line)){
        	symbolTable.clear();
        	stringstream iss(line);
        	cout << line << " ";
            try{
        	iss >> paren;
        	expression = SubExpression::parse(iss);
        	iss >> comma;
        	parseAssignments(iss);
        	cout << "Value = " << expression->evaluate() << endl;
            } catch(exception e){
            	cout << "error" << e.what();
            }
        }

    return 0;
}

void parseAssignments(stringstream& fin)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(fin);
        fin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
