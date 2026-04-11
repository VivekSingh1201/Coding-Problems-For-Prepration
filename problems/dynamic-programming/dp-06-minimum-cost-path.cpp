// Minimum Cost Path in a Grid
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// Example:
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();    // rows
    int n = grid[0].size(); // cols

    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = grid[0][0];

    // first row — can only come from left
    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j]; // accumulate left to right

    // first col — can only come from top
    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0]; // accumulate top to bottom

    for (int i = 1; i < m; i++)
    { // i → rows
        for (int j = 1; j < n; j++)
        { // j → cols
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            //          cell cost    from top         from left
        }
    }
    return dp[m - 1][n - 1]; // bottom-right corner
}

int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    cout<< "Minimum Cost Path: " << minPathSum(grid) << endl; // Output: 7
    return 0;
}

// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid.
// Space Complexity: O(m*n) for the dp table. However, we can optimize it to O(n) by using a single array to store the current row's minimum path sums, since we only need the values from the previous row and the current row.