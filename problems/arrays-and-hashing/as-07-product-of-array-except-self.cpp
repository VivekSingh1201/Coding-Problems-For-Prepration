// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int left = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for(int i = nums.size() - 1; i >= 0; --i)
        {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {-1,1,0,-3,3};
    
    Solution sol;
    vector<int> res = sol.productExceptSelf(arr);
    
    for(int ele : res){
        cout<<ele<<" ";
    }
    
    return 0;
}

// time complexity : O(n) because we are traversing the array twice, once to calculate the total product of all the elements in the array and once to calculate the product of all the elements except the one at index i.
// space complexity : O(n) because we are using an extra array to store the result