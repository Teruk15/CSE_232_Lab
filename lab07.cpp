#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "lab07functions.hpp"

int main(){
    string word;
    char spl;
    cout << "Give me a string to split: "<< endl;
    cin >> word;
    cout << "What character should I split on: " << endl;
    cin >> spl;
    print_vector(cout, split(word,spl));
}