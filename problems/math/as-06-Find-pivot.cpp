// Problem: Find the Pivot Integer

// Given a positive integer n, find the pivot integer x such that:
// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1.

// Example 1:
// Input: n = 8
// Output: 6
// Explanation:
// The sum of the integers from 1 to 6 is equal to the sum of the integers from 6 to 8:
// 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21. Thus, 6 is the pivot integer.

#include <iostream>
#include <cmath>
using namespace std;

int pivotInteger(int n)
{
    int total = n * (n + 1) / 2;
    int x = sqrt(total);
    return x * x == total ? x : -1;
}

int main()
{
    int n = 8;
    cout << pivotInteger(n) << endl; // Output: 6
    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(1)