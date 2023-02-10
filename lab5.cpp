#include <iostream>
#include <math.h>
#include <algorithm>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: string;
using std::pow;
using std::sort;

std::int64_t LocToDec(std::string const & loc){
    int len = loc.length();
    int pwr;
    int total = 0;
    for (int i = 0; i < len; i++){
        pwr = loc[i] - 'a';
        total += pow(2,pwr);
    }
    return total;
}

std::string Abbreviate(std::string const & loc){
    int count;
    int diff;
    string true_loc = loc;
    int len = true_loc.length();
    string temp_loc = "";
    do
    {
        count = 0;
        for(int i = 0; i < len - 1; i++){
            sort(true_loc.begin(),true_loc.end());
            diff = true_loc[i] - true_loc[i+1];
            if(diff == 0){
                temp_loc += true_loc[i] + 1;
                i++;
                if(i == len - 2 ){
                    temp_loc += true_loc.back();
                }
                count++;
            }
            else if(i == len - 2 && true_loc[len-2] - true_loc[len-1] != 0){
                temp_loc += true_loc[len-2];
                temp_loc += true_loc[len-1];  
            }
            else{
                temp_loc += true_loc[i];
            }
        }
        if(count != 0){
            true_loc = temp_loc;
            temp_loc = "";
            len = true_loc.length();
        }
    } while (count != 0);
    
    return true_loc;
}

std::string DecToLoc(std::int64_t dec){
    string str = "";
    for(int i = 0; i < dec; i++){
        str += 'a';
    }
    return Abbreviate(str);
}

std::int64_t AddLoc(std::string const & loc1, std::string const & loc2){
    string str1,str2;
    int num1,num2;
    str1 = Abbreviate(loc1);
    str2 = Abbreviate(loc2);
    num1 = LocToDec(str1);
    num2 = LocToDec(str2);

    return num1 + num2;
}


int main() {
    string str,str1,str2;
    int num;
    cout << "Give me a location string:" << endl;
    cin >> str;
    cout << "Give me an integer:" << endl;
    cin >> num;
    cout << str << "to dec: " << LocToDec(str) << endl;
    cout << str << "abbreviated: " << Abbreviate(str) << endl;
    cout << num << " to loc: " << DecToLoc(num) << endl;
    cout << "Give me two more location strings:" << endl;
    cin >> str1;
    cin >> str2;
    cout << "Sum of " << str1 << " and " << str2 << " is: " << AddLoc(str1,str2) << endl;
}