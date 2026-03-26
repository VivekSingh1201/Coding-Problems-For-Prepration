// Given a string s, find the length of the longest substring without repeating characters.
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.


#include <iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main() {
    
    string s = "abcabcbb";
    
    int left=0;
    int max_l=0;
    unordered_set<char> charSet;
    

    // Use a sliding window approach to find the longest substring without repeating characters
    for(int right=0;right<s.length();right++){
        while(charSet.find(s[right]) != charSet.end()){
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        max_l=max(max_l,right-left+1);
    }
    
    cout<<max_l;

    return 0;
}



// Time Complexity: O(n) - Each character is visited at most twice (once by the right pointer and once by the left pointer).
// Space Complexity: O(min(m, n)) - The space complexity is determined by the size of the set, which can grow up to the size of the longest substring without repeating characters. In the worst case, this can be O(n) if all characters are unique, but it is limited by the size of the character set (m) if the input string contains a limited number of unique characters.