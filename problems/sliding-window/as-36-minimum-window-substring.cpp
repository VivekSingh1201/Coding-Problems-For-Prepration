// Minimum Window Substring

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    unordered_map<char, int> need, have;
    for (char c : t) need[c]++;

    int formed = 0, required = need.size();
    int left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        have[c]++;
        if (need.count(c) && have[c] == need[c])
            formed++;

        while (formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            char lc = s[left];
            have[lc]--;
            if (need.count(lc) && have[lc] < need[lc])
                formed--;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << "\n"; // "BANC"
    cout << minWindow("a", "a")              << "\n"; // "a"
    cout << minWindow("a", "aa")             << "\n"; // ""
}


// Time Complexity: O(|S| + |T|) where |S| and |T| are the lengths of the input strings. We traverse both strings at most once.
// Space Complexity: O(|S| + |T|) in the worst case, when all characters in S and T are unique. We use two hash maps to store the frequency of characters in T and the current window in S.