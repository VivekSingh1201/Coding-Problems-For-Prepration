// Coin Change

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;

    if (dp[amount] != -1)
        return dp[amount];

    int minCoins = INT_MAX;

    for (int coin : coins)
    {
        int res = solve(coins, amount - coin, dp);
        if (res != INT_MAX)
        {
            minCoins = min(minCoins, res + 1);
        }
    }
    return dp[amount] = minCoins;
}

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int res = solve(coins, amount, dp);
    return res == INT_MAX ? -1 : res;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount) << endl; // Output: 3
    return 0;
}


// Time Complexity: O(n * amount), where n is the number of coins and amount is the total amount of money.
// Space Complexity: O(amount) for the dp array.