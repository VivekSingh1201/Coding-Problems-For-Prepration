// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.


// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// int main() {
    
//     string ch = "[{()}][]";
//     int n = ch.length();
    
//     stack<char> st;
    
//     for(int i = 0; i < n; i++){
        
//         if(ch[i]=='[' || ch[i]=='{' || ch[i]=='('){
//             st.push(ch[i]);
//         }
//         else{
            
//             if(st.empty()){
//                 cout<<"It is Invalid Parantheses!!!!";
//                 return 0;
//             }
            
//             if( (st.top()=='{' && ch[i]=='}') ||
//                 (st.top()=='[' && ch[i]==']') ||
//                 (st.top()=='(' && ch[i]==')') ){
                    
//                 st.pop();
//             }
//             else{
//                 cout<<"It is Invalid Parantheses!!!!";
//                 return 0;
//             }
//         }
//     }
    
//     if(!st.empty()){
//         cout<<"It is Invalid Parantheses!!!!";
//         return 0;
//     }
    
//     cout<<"It is Valid Parantheses!!!!";
    
//     return 0;
// }





// we can write it like 



#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    
    stack<char> st;
    
    unordered_map<char, char> match = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };
    
    for(char ch : s) {
        
        // If opening bracket → push
        if(ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            
            // If stack empty OR mismatch → invalid
            if(st.empty() || st.top() != match[ch]) {
                return false;
            }
            
            st.pop();
        }
    }
    
    return st.empty();
}

int main() {
    string ch = "[{()}]";
    
    if(isValid(ch))
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";
}

// time complexity : O(n) because we are traversing the string once.
// space complexity : O(n) because in the worst case, we can have all opening brackets in the string and we will be pushing all of them to the stack.