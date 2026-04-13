// Capacity To Ship Packages Within D Days

// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// Example 1:

// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>   // for using accumulate function

using namespace std;

bool canShip(vector<int> &weights, int D, int capacity)
{
    int load = 0;
    int days = 1;

    for (int w : weights)
    {
        if (load + w > capacity)
        {
            days++;
            load = 0;
        }
        load += w;
    }

    return days <= D;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0); // give sum of all elements

    while (left < right)
    {
        int mid = left + (right - left) / 2; // It define Capacity of ship every time

        if (canShip(weights, days, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    cout << shipWithinDays(weights, days) << endl; // Output: 15
    return 0;
}

// Time Complexity: O(n log m), where n is the number of packages and m is the sum of weights.
// Space Complexity: O(1)