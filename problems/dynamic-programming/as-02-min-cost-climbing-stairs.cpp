// Min Cost Climbing Stairs


//dp memoization approach

// The problem is to find the minimum cost to reach the top of a staircase, where each step has a cost associated with it. You can either climb one or two steps at a time. The cost of climbing a step is given in an array, and you can start from either the first or second step.

/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<int> &cost, int i, vector<int> &dp) {
    if (i < 0) return 0; // Base case: no cost for negative steps
    if (dp[i] != -1) return dp[i]; // Return already computed cost

    // Calculate the cost of climbing one step and two steps
    int costOneStep = minCost(cost, i - 1, dp) + cost[i];
    int costTwoSteps = minCost(cost, i - 2, dp) + cost[i];

    // Store the minimum cost in the dp array
    dp[i] = min(costOneStep, costTwoSteps);
    return dp[i];
}

int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n, -1); // Initialize dp array with -1
    return min(minCost(cost, n - 1, dp), minCost(cost, n - 2, dp)); // Start from the last two steps
}

*/


// Time Complexity: O(n) - Each step is computed once and stored in the dp array.
// Space Complexity: O(n) - The dp array is used to store the minimum cost for each step, which takes O(n) space. Additionally, the recursive call stack can go up to O(n) in the worst case, but since we are using memoization, it will not exceed O(n).





// Space Optimization Approach

// We can optimize the space complexity to O(1) by using two variables to keep track of the minimum cost for the last two steps instead of using a dp array.


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        int prev1=0,prev2=0;

        for(int i=2;i<=n;i++){
            int curr = min(prev1+cost[i-1],prev2+cost[i-2]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    vector<int> cost(n);
    cout << "Enter the cost of each step: ";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << "Minimum cost to reach the top: " << minCostClimbingStairs(cost) << endl;
    return 0;
}

// Time Complexity: O(n) - We are iterating through the cost array once.
// Space Complexity: O(1) - We are using only a constant amount of extra space for the variables prev1 and prev2. The space used for the input array does not count towards the space complexity as it is required to store the input.
