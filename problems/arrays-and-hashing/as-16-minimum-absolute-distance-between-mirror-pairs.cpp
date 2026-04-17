// Minimum Absolute Distance Between Mirror Pairs

// You are given an integer array nums.
// A mirror pair is a pair of indices (i, j) such that:
// 0 <= i < j < nums.length, and
// reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
// Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).
// If no mirror pair exists, return -1.

// Example 1:

// Input: nums = [12,21,45,33,54]

// Output: 1

// Explanation:
// The mirror pairs are:
// (0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
// (2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
// The minimum absolute distance among all pairs is 1.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int rev(int n)
{
    int rev = 0;
    while (n)
    {
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }
    return rev;
}

int minMirrorPairDistance(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int ans = n;

    for (int i = 0; i < n; i++)
    {
        int check = rev(nums[i]);

        if (mp.find(nums[i]) != mp.end())
        {
            ans = min(ans, abs(mp[nums[i]] - i));
        }

        mp[check] = i;
    }
    if (ans == n)
    {
        return -1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {12, 21, 45, 33, 54};
    cout << minMirrorPairDistance(nums) << endl; // Output: 1
    return 0;
}


// Time Complexity: O(n * log(m)), where n is the number of elements in the input array and m is the maximum value in the array. The log(m) factor arises from the reversal of the digits, which takes O(log(m)) time.
// Space Complexity: O(n), where n is the number of elements in the input array. In the worst case, all elements could be unique and stored in the unordered_map.
