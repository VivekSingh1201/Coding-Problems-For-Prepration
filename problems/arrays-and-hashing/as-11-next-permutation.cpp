// Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i = nums.size() - 2;
    // Find the rightmost pair of indices (i, i + 1) such that nums[i] < nums[i + 1]. If no such index exists, the permutation is the last permutation.
    while (i >= 0 && nums[i + 1] <= nums[i])
    {
        i--;
    }

    // If such an index exists, find the rightmost index j such that nums[i] < nums[j]. Swap the value of nums[i] with that of nums[j].
    if (i >= 0)
    {
        int j = nums.size() - 1;
        // Find the rightmost index j such that nums[i] < nums[j]. Since i + 1 is such an index, j is well defined, and there will always be a valid j.
        while (nums[j] <= nums[i])
        {
            j--;
        }
        swap(nums[i], nums[j]);
    }

    // Reverse the sub-array nums[i + 1...end]. This step is necessary because the sub-array nums[i + 1...end] is in descending order, 
    // and we need to make it the lowest possible order (i.e., ascending order) to get the next permutation.
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 3, 4, 2};

    nextPermutation(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl; // Output: 1 4 2 3

    return 0;
}

// Time Complexity: O(n), where n is the length of the input array nums. We traverse the array a few times, but each traversal is linear.
// Space Complexity: O(1), since we are modifying the input array in place and using only a constant amount of extra space for variables.