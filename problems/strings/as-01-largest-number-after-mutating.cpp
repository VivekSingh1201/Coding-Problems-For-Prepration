// Largest Number After Mutating Substring

// You are given a string num, which represents a large integer. You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit. More formally, digit d maps to digit change[d].
// You may choose to mutate a single substring of num. To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).
// Return a string representing the largest possible integer after mutating (or choosing not to) a single substring of num.
// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: num = "132", change = [9,8,5,0,3,6,4,2,6,8]
// Output: "832"
// Explanation: Replace the substring "1":
// - 1 maps to change[1] = 8.
// Thus, "132" becomes "832".
// "832" is the largest number that can be created, so return it.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string maximumNumber(string num, vector<int> &change)
{
    int n = num.length();

    for (int i = 0; i < n; i++)
    {
        if (num[i] - '0' < change[num[i] - '0'])
        {
            while (i < n && num[i] - '0' <= change[num[i] - '0'])
            {
                num[i] = change[num[i] - '0'] + '0';
                i++;
            }
            break;
        }
    }
    return num;
}

int main()
{
    string num = "132";
    vector<int> change = {9, 8, 5, 0, 3, 6, 4, 2, 6, 8};

    string result = maximumNumber(num, change);
    cout << result << endl; // Output: "832"

    return 0;
}


// Time Complexity: O(n), where n is the length of the input string num. We iterate through the string at most once.
// Space Complexity: O(1), since we are modifying the input string in place and using only a constant amount of extra space for variables.