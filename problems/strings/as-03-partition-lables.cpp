// Partition Labels

// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(string s)
{
    int n = s.length();

    unordered_map<char, int> lastIndex;

    for (int i = 0; i < n; i++)
    {
        lastIndex[s[i]] = i;
    }

    vector<int> res;
    int start = 0, end = 0;

    for (int i = 0; i < n; i++)
    {
        end = max(end, lastIndex[s[i]]);

        if (i == end)
        {
            res.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return res;
}


int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = partitionLabels(s);
    for (int size : res)
    {
        cout << size << " ";
    }
    cout << endl; // Output: 9 7 8
    return 0;
}


// Time Complexity: O(n), where n is the length of the string s.
// Space Complexity: O(1), since the size of the hashmap will be at most 26 (number of lowercase letters).  