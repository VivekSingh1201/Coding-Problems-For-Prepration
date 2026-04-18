// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

#include <iostream>
#include <string>
using namespace std;

string expand(int i, int j, string s)
{
    int left = i;  // going left from ith position
    int right = j; // going right from ith position

    while (left >= 0 && right < s.length() && s[right] == s[left])
    {
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        string odd = expand(i, i, s);
        if (odd.length() > ans.length())
        {
            ans = odd;
        }
        string even = expand(i, i + 1, s);
        if (even.length() > ans.length())
        {
            ans = even;
        }
    }
    return ans;
}


int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl; // Output: "bab" or "aba"
    return 0;
}


// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding the space for the output string)