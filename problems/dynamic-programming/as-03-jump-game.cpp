// Jump Game

// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps from index 1 to the last index.

#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;

        // Iterate through the array and keep track of the maximum reachable index at each step. 
        for(int i=0;i<n;i++){
            if(maxi<i) return false;
            maxi=max(maxi,nums[i]+i);
        }
        return true;
    }

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (canJump(nums)) {
        cout << "You can reach the last index." << endl;
    } else {
        cout << "You cannot reach the last index." << endl;
    }
    return 0;
}


// Time Complexity: O(n), where n is the number of elements in the input array.
// Space Complexity: O(1), as we are using only a constant amount of extra space.