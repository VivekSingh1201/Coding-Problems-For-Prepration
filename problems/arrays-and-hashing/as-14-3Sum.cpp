// 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k)
        {
            int total = nums[i] + nums[j] + nums[k];

            if (total > 0)
            {
                k--;
            }
            else if (total < 0)
            {
                j++;
            }
            else
            {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j - 1] && j < k)
                {
                    j++;
                }
            }
        }
    }
    return res;
}


int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);

    for (const auto &triplet : res)
    {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++)
        {
            cout << triplet[i];
            if (i < triplet.size() - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}


// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding the space for the output)