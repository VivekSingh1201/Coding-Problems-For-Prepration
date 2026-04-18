// Longest Valid Parentheses

// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".



#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}

int main()
{
    string s = "(()";
    cout << longestValidParentheses(s) << endl; // Output: 2
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) (in the worst case when all characters are '(')