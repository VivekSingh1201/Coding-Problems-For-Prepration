// Integer Break

// Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

// Return the maximum product you can get.

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.

#include <iostream>
#include <vector>
using namespace std;

int func(int i, vector<int> dp)
{
    if (i <= 3)
        return i;
    if (dp[i] != -1)
        return dp[i];
    int ans = 0;
    for (int j = 1; j < i; j++)
    {
        ans = max(ans, j * func(i - j, dp));
    }
    return dp[i] = ans;
}

int integerBreak(int n)
{
    if (n < 4)
        return n - 1;

    vector<int> dp(n + 1, -1);
    return func(n, dp);
}

int main()
{
    int n = 10;
    cout << "Maximum product for integer break of " << n << " is: " << integerBreak(n) << endl;
}


// Time Complexity: O(n^2) because for each integer from 1 to n, we are iterating through all integers less than it to calculate the maximum product.
// Space Complexity: O(n) due to the dp array used for memoization.