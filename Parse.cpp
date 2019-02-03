#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "parse.h"

string parseName(stringstream& fin)
{
    char alnum;
    string name = "";

    fin >> ws;
    while (isalnum(fin.peek()))
    {
        fin >> alnum;
        name += alnum;
    }
    return name;
}

