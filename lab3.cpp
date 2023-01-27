#include <iostream>

using std:: cin;
using std:: cout;
using std:: endl;

int input;
int last_digit;
int rest_num;
int count = 0;
int total = 0;

int main() {
// WRITE YOUR CODE HERE

while (cin >> input){
    if (input < 0){
        break;
    }

    while (input >= 10){
        last_digit = input % 10;
        rest_num = input / 10;

        total += last_digit;

        input = rest_num;

        if (input < 10) {
            total += rest_num;
            count ++;
            
            input = total;
            total = 0;
        }
    }

    cout << count << ' ' << input << endl;
    count = 0;
}




  
  return 0;
}