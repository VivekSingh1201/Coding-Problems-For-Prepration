// Palindrome Number
// Given an integer x, return true if x is a palindrome, and false otherwise.


// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

#include <iostream>

using namespace std;


bool isPalindrome(int x)
{
    if (x < 0)
        return 0;
    long rev = 0;
    long num = x;
    while (num)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev == x;
}

int main()
{
    int x = 121;
    cout << isPalindrome(x) << endl; // Output: true
    return 0;
}


// Time Complexity: O(log d)
// Space Complexity: O(1)