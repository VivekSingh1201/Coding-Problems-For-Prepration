// Reverse each word in a string

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
    
    string str = "Hello World";
    int n = str.length();
    stack<char> st;
    string res;
    
    for(int i = 0; i < n; i++){
        if(str[i] != ' '){
            st.push(str[i]);
        }
        else{
            // reverse word
            while(!st.empty()){
                res += st.top();
                st.pop();
            }
            res += ' ';
        }
    }

    // last word (VERY IMPORTANT)
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    
    cout << res << endl;
    
    return 0;
}

// time complexity : O(n) because we are traversing the string once.
// space complexity : O(n) because in worst case, we may need to store all characters in the stack.