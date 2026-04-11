// Nth Fibonacci Number
// The Fibonacci numbers are the numbers in the following integer sequence.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
// The first two Fibonacci numbers are 0 and 1. Every other number in the sequence is the sum of the two preceding ones.
// Given n, calculate the nth Fibonacci number.

#include <iostream>
using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;
    int prev1 = 0, prev2 = 1;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        res = prev1 + prev2;
        prev1 = prev2;
        prev2 = res;
    }
    return res;
}

int main()
{
    int n = 10;
    cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl; // Output: 55
    return 0;
}

// Time Complexity: O(n) where n is the input number for which we want to calculate the Fibonacci number. We compute each Fibonacci number from 2 up to n exactly once.
// Space Complexity: O(1) since we are using only a constant amount of space to store the last two Fibonacci numbers and the current result. We are not using any additional space that grows with n.