// Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "".
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int n_s=strs.size();
        int n_c=strs[0].size();

        for(int i=0;i<n_c;i++){
            char key=strs[0][i];
            for(int j=1;j<n_s;j++){
                if(i==strs[j].size() || strs[j][i]!=key){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << "Longest common prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}

// Time Complexity: O(S) - Where S is the sum of all characters in all strings. In the worst case, we are comparing all characters of all strings.
// Space Complexity: O(1) - We are using only a constant amount of extra space for the variables. The space used for the output string does not count towards the space complexity as it is required to store the result.