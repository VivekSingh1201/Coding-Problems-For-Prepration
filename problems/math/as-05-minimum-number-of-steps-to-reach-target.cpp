// Minimum Number of Steps to Reach Target

// You are given a positive integer target.

// In one step you can either add 1, add 2, or add 3 to your current number. Return the minimum number of steps required to reach the target starting from 0.


#include <iostream>
#include <cmath>

using namespace std;

int minimumSteps(int target)
{
    int steps = 0, sum = 0;
    while (sum < target || (sum - target) % 2 != 0)
    {
        steps++;
        sum += steps;
    }
    return steps;
}

int main()
{
    int target;
    cin >> target;
    cout << minimumSteps(target) << endl;
    return 0;
}

// time complexity: O(sqrt(target)) because in the worst case, we will need to keep adding steps until the sum exceeds the target. The sum of the first n natural numbers is given by the formula n(n + 1) / 2, which grows quadratically. Therefore, we can estimate that n will be approximately sqrt(2 * target) in the worst case.
// space complexity: O(1) since we are using only a constant amount of extra space


// Dry Run:

// Example: target = 10

// Step 1: steps = 0, sum = 0
// Step 2: steps = 1, sum = 1 (sum < target, continue)
// Step 3: steps = 2, sum = 3 (sum < target, continue)
// Step 4: steps = 3, sum = 6 (sum < target, continue)
// Step 5: steps = 4, sum = 10 (sum >= target, check if (sum - target) % 2 == 0, which is true, so we can stop here)