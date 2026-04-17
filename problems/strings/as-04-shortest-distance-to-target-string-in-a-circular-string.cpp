// Shortest Distance to Target String in a Circular String

// You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

// Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
// Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

// Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.

// Example 1:

// Input: words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
// Output: 1
// Explanation: We start from index 1 and can reach "hello" by
// - moving 3 units to the right to reach index 4.
// - moving 2 units to the left to reach index 4.
// - moving 4 units to the right to reach index 0.
// - moving 1 unit to the left to reach index 0.
// The shortest distance to reach "hello" is 1.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int closestTarget(vector<string> &words, string target, int startIndex)
{
    int n = words.size();
    int ans = INT_MAX;

    // Check startIndex itself
    if (words[startIndex] == target)
        return 0;

    // Search right (clockwise)
    for (int i = 1; i <= n; i++)
    {
        int idx = (startIndex + i) % n;
        if (words[idx] == target)
        {
            ans = min(ans, i);
            break;
        }
    }

    // Search left (counter-clockwise)
    for (int i = 1; i <= n; i++)
    {
        int idx = (startIndex - i + n) % n;
        if (words[idx] == target)
        {
            ans = min(ans, i);
            break;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}


int main()
{
    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    string target = "hello";
    int startIndex = 1;

    cout << closestTarget(words, target, startIndex) << endl; // Output: 1

    return 0;
}


// Time Complexity: O(n) where n is the length of the words array, as we may need to check each word at most once in both directions.
// Space Complexity: O(1) as we are using only a constant amount of extra space.