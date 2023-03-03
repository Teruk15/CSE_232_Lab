#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

using std::ostream;
using std::vector;
using std::string;
using std::istringstream;
using std::ostream_iterator;
using std::getline;
using std::cout;

#include "lab07functions.hpp"
// abc,abcc,adb
vector<string> split(string const &s, char sep){
    vector<string> outputs;
    istringstream iss(s);
    string word;
    while (getline(iss,word,sep)){//*(cin>>)
        outputs.push_back(word);
    }

    return outputs;
}

void print_vector(ostream &out, vector<string> const &v){
    // ostream_iterator<string> v (cout, " ");
    std::copy(v.begin(),v.end(),ostream_iterator<string>(out," "));
}