// Palindrome partitioning

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include <iostream>
#include <vector>
using namespace std;

bool isPalin(string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void backtrack(string &s, int ind, vector<string> &cur, vector<vector<string>> &ans)
{
    int n = s.length();
    if (ind >= n)
    {
        ans.push_back(cur);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (isPalin(s, ind, i))
        {
            cur.push_back(s.substr(ind, i - ind + 1));
            backtrack(s, i + 1, cur, ans);
            cur.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> cur;
    backtrack(s, 0, cur, ans);
    return ans;
}


int main()
{
    string s = "aab";
    vector<vector<string>> ans = partition(s);
    for (const auto &partition : ans)
    {
        for (const auto &str : partition)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}



// Time Complexity: O(n * 2^n) in the worst case, where n is the length of the string. This is because we are generating all possible partitions and checking if each partition is a palindrome.
// Space Complexity: O(n) for the recursion stack and O(n) for storing the current partition, resulting in O(n) overall. Additionally, the space required to store the final answer can be O(n * 2^n) in the worst case, as there can be a large number of partitions.

