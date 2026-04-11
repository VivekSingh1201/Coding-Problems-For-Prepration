// Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
        if(n==0 || n==1){
            return 1;
        }
        
        vector<int> dp(n+1);
        dp[0]=1,dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
    return dp[n];
    }

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}

// Time Complexity: O(n) - We are filling the dp array of size n+1.
// Space Complexity: O(n) - We are using a dp array of size n+1