// Squares of a Sorted Array

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    int last = n - 1;
    int first = 0;
    int idx = n - 1;
    vector<int> res(n);

    while (first <= last)
    {
        if (abs(nums[first]) <= abs(nums[last]))
        {
            res[idx--] = nums[last] * nums[last];
            last--;
        }
        else
        {
            res[idx--] = nums[first] * nums[first];
            first++;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = sortedSquares(nums);
    for (int i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}

// time complexity: O(n)
// space complexity: O(n)