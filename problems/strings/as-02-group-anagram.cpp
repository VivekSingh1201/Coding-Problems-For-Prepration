// Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> ans;

    for (string &s : strs)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        // build key like "1#0#0#1#..." with # separator
        string key = "";
        // We use the frequency of characters as the key to group anagrams together. Anagrams will have the same frequency of characters, thus the same key.
        for (int i = 0; i < 26; i++)
            key += to_string(freq[i]) + "#";   // using # as a separator to avoid ambiguity between counts

        // Insert the original string into the corresponding group in the map based on the generated key.
        ans[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto &entry : ans)
        res.push_back(entry.second);

    return res;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (const auto &group : res)
    {
        cout << "[";
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << "]";
    }
    return 0;
}

// Time Complexity: O(N * K) where N is the number of strings and K is the maximum length of a string in the input array. We iterate through each string and count the frequency of characters, which takes O(K) time. The rest of the operations (inserting into the map and building the result) take O(N) time.  
// Space Complexity: O(N * K) in the worst case, where all strings are different and have a length of K. The map will store N entries, and each entry can have a key of length O(K) and a value that is a vector of strings.