// Koko Eating Bananas

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFinish(vector<int> &piles, int h, int mid)
{
    long long hours = 0;
    for (int pile : piles)
    {
        hours += pile / mid;
        if (pile % mid != 0)
            hours++;
        if (hours > h)
            return false;
    }
    return hours <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = right;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, h, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << minEatingSpeed(piles, h) << endl; // Output: 4
    return 0;
}

// Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in a pile.
// Space Complexity: O(1)