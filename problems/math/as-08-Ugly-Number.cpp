// Problem: Ugly Number
// An ugly number is a positive integer that is divisible by a prime factor of 2, 3, or 5.
// Given an integer n, return true if n is an ugly number, or false otherwise.

// Example 1:
// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3, where 2 and 3 are prime factors of 6.

#include <iostream>
using namespace std;

bool isUgly(int n)
{
    if (n <= 0)
        return false;

    for (int p : {2, 3, 5})
        while (n % p == 0)
            n /= p;

    return n == 1;
}

int main()
{
    int n = 6;
    cout << isUgly(n) << endl; // Output: true
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)