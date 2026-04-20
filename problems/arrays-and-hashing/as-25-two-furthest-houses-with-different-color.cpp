// Two Furthest Houses With Different Colors

// There are n houses evenly lined up on the street, and each house is beautifully painted. You are given a 0-indexed integer array colors of length n, where colors[i] represents the color of the ith house.
// Return the maximum distance between two houses with different colors.
// The distance between the ith and jth houses is abs(i - j), where abs(x) is the absolute value of x.

// Example 1:

// Input: colors = [1,1,1,6,1,1,1]
// Output: 3
// Explanation: In the above image, color 1 is blue, and color 6 is red.
// The furthest two houses with different colors are house 0 and house 3.
// House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
// Note that houses 3 and 6 can also produce the optimal answer.

#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<int> &A)
{
    int n = A.size();
    int left = 0, right = 0;

    for (int i = 0; i < n; i++)
        if (A[i] ^ A[n - 1])
        {
            left = i;
            break;
        }

    for (int i = n - 1; i >= 0; i--)
        if (A[i] ^ A[0])
        {
            right = i;
            break;
        }

    return max(n - 1 - left, right);
}


int main()
{
    vector<int> colors = {1, 1, 1, 6, 1, 1, 1};
    cout << "Maximum distance between two houses with different colors is: " << maxDistance(colors) << endl;
}


// Time Complexity: O(n) because we are iterating through the array twice to find the leftmost and rightmost houses with different colors.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the left and right pointers.