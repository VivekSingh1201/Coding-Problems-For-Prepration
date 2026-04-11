// Transform Array by Parity

// You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

// Replace each even number with 0.
// Replace each odd numbers with 1.
// Sort the modified array in non-decreasing order.
// Return the resulting array after performing these operations.

// Example 1:
// Input: nums = [3,1,2,4]
// Output: [0,0,1,1]
// Explanation: After replacing the even numbers with 0 and the odd numbers with 1, the array becomes [1,1,0,0]. After sorting in non-decreasing order, the array becomes [0,0,1,1].

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();

        int even = 0;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
            }
        }

        for(int i=0;i<n;i++){
            if(even!=0){
                nums[i]=0;
                even--;
            }
            else{
                nums[i]=1;
            }
        }
        return nums;
    }

int main(){
    vector<int> nums = {3,1,2,4,5,4,2,1};
    vector<int> result = transformArray(nums);
    cout<<"Transformed array is:- ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

// time complexity: O(n)
// space complexity: O(1)