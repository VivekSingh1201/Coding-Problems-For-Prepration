//Convert a string to an integer
// We can use the built-in function stoi in C++ to convert a string to an integer. The function takes a string as input and returns the corresponding integer value. If the string cannot be converted to an integer, it throws an exception. We can also handle the exception to avoid program crashes
//But here we will implement our own function to convert a string to an integer without using the built-in function.

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string s = "12345";
    int res = 0;
    
    for(char c : s){
        if(c < '0' || c > '9'){
            cout << "Invalid input" << endl;
            return 0;
        }
        res = res * 10 + (c - '0');
    }
    
    cout << res << endl;
    return 0;
}

// time complexity : O(n) because we are traversing the string once.
// space complexity : O(1) because we are using only a constant amount of extra space