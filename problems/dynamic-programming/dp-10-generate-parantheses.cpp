// Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

#include <iostream>
#include <vector>
using namespace std;

void dfs(int open, int close, string s, int n, vector<string> &res)
{
    if (open == close && open + close == n * 2)
    {
        res.push_back(s);
        return;
    }
    if (open < n)
    {
        dfs(open + 1, close, s + "(", n, res);
    }
    if (close < open)
    {
        dfs(open, close + 1, s + ")", n, res);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    dfs(0, 0, "", n, res);
    return res;
}

int main()
{
    int n = 3;
    vector<string> result = generateParenthesis(n);
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl; // Output: ((())) (()()) (())() ()(()) ()()()
    return 0;
}

// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(4^n / sqrt(n)) (number of valid combinations)