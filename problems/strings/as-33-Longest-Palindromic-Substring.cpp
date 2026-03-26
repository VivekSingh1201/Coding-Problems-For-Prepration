// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.
//example 1:
//Input: s = "babad"
//Output: "aba"
//Note: "aba" is also a valid answer.

#include <iostream>
#include <string>
using namespace std;


// Function to expand around the center and find the longest palindrome
string expand(int i, int j, string s){
        int left=i;
        int right=j;

        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

// Main function to find the longest palindromic substring
string longestPalindrome(string s) {
        string ans = "";

        for(int i=0;i<s.size();i++){ 
            string odd = expand(i,i,s);
            if(odd.size()>ans.size()){
                ans = odd;
            }
            string even = expand(i,i+1,s);
            if(even.size()>ans.size()){
                ans = even;
            }
        }
        return ans;
    }

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    cout << "Longest palindromic substring: " << longestPalindrome(s) << endl;
    return 0;
}

// Time Complexity: O(n^2) - The expand function can be called O(n) times, and each call can take O(n) time in the worst case.
// Space Complexity: O(1) - We are using only a constant amount of extra space for the variables. The space used for the output string does not count towards the space complexity as it is required to store the result.