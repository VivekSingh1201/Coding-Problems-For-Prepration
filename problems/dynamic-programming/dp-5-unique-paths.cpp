// Unique Paths
// The problem is to find the number of unique paths from the top-left corner of a grid to the bottom-right corner,
// where you can only move either down or right at any point in time. The grid is represented as an m x n matrix, and you need to calculate the total number of unique paths that exist.
// The solution can be implemented using dynamic programming by creating a 2D dp array where dp[i][j] represents the number of unique paths to reach cell (i, j).
// The number of unique paths to reach a cell can be calculated as the sum of the unique paths to reach the cell directly above it and the cell directly to the left of it.
// The base cases are when you are in the first row or first column, where there is only one unique path to reach any cell in those rows or columns. Finally, the answer will be found in dp[m-1][n-1],
// which will give us the total number of unique paths from the top-left corner to the bottom-right corner of the grid.

#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main(){
    int m = 3, n = 7;
    cout << uniquePaths(m, n) << endl; // Output: 28
    return 0;
}

// Time Complexity: O(m*n) - We need to fill the dp array of size m x n, and each cell is computed once.
// Space Complexity: O(m*n) - The dp array of size m x n is used to store the number of unique paths to reach each cell. However, we can optimize this to O(n) by using a single array to store the number of unique paths for the current row, since we only need the values from the previous row to compute the current row.


// Dry Run:
// For m = 3 and n = 7, the dp array will be filled as follows:
// dp[0][j] = 1 for all j (first row)
// dp[i][0] = 1 for all i (first column)
// Then, we fill the rest of the dp array:
// dp[1][1] = dp[0][1] + dp[1][0] = 1 + 1 = 2
// dp[1][2] = dp[0][2] + dp[1][1] = 1 + 2 = 3
// dp[1][3] = dp[0][3] + dp[1][2] = 1 + 3 = 4
// dp[1][4] = dp[0][4] + dp[1][3] = 1 + 4 = 5
// dp[1][5] = dp[0][5] + dp[1][4] = 1 + 5 = 6
// dp[1][6] = dp[0][6] + dp[1][5] = 1 + 6 = 7
// dp[2][1] = dp[1][1] + dp[2][0] = 2 + 1 = 3 
// dp[2][2] = dp[1][2] + dp[2][1] = 3 + 3 = 6
// dp[2][3] = dp[1][3] + dp[2][2] = 4 + 6 = 10
// dp[2][4] = dp[1][4] + dp[2][3] = 5 + 10 = 15
// dp[2][5] = dp[1][5] + dp[2][4] = 6 + 15 = 21
// dp[2][6] = dp[1][6] + dp[2][5] = 7 + 21 = 28
// Finally, dp[2][6] will give us the total number of unique paths from the top-left corner to the bottom-right corner, which is 28.