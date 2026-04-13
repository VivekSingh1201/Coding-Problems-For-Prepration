// Single Element in a Sorted Array

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (mid % 2 == 1)
            mid--;

        if (nums[mid] == nums[mid + 1])
            left = mid + 2;
        else
            right = mid;
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << endl; // Output: 2
    return 0;
}

// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1)