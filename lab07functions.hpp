#ifndef DEFAULT_TEST
#define DEFAULT_TEST

#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::vector;
using std::string;

//Declaring function name split
vector<string> split(string const &, char sep = ' ');

//Print out values in vector<string>
void print_vector(ostream &, vector<string> const &);

#endif