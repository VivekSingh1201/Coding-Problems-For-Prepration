// House Robber Problem
// Given an array of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police (i.e., without robbing two adjacent houses).

// Example 1:
// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

/*

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int loot(int i, vector<int> &nums, vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i] + loot(i+2,nums,dp);
        int skip = loot(i+1,nums,dp);
        return dp[i]=max(pick,skip);
    }

int main(){
    vector<int> nums = {2,10,5,3,15};
    vector<int> dp(nums.size(), -1);
    cout<<"Maximum amount that can be robbed is:- " << loot(0,nums,dp)<<endl;
    return 0;
    
 }
    
*/

// time complexity: O(n)
// space complexity: O(n)






// Note: The above solution can be optimized to O(1) space complexity by using two variables to keep track of the maximum amount robbed so far instead of using a dp array.

// Optimized Solution

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums = {1,2,10,1,1,5};
    int prev1 = 0; // max amount robbed till the previous house
    int prev2 = 0; // max amount robbed till the house before the previous house
    for(int i=0;i<nums.size();i++){
        int pick = nums[i] + prev2; // if we rob the current house, we add its amount to the max amount robbed till the house before the previous house
        int skip = prev1; // if we skip the current house, we take the max amount robbed till the previous house
        int curr = max(pick, skip); // current max amount is the maximum of picking or skipping the current house
        prev2 = prev1; // update prev2 to be the previous max amount
        prev1 = curr; // update prev1 to be the current max amount
    }
    cout<<"Maximum amount that can be robbed is:- " << prev1<<endl;
    return 0;
    
}


// time complexity: O(n)
// space complexity: O(1)