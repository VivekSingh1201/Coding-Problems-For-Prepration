// C++ program to reverse words in a given string with extra spaces  in start and end and multiple spaces between words


#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    string s = "  the   sky   is blue  ";
    int n = s.length();
    
    // -------- Step 1: Remove Extra Spaces --------
    int i = 0, j = 0;
    
    // Skip leading spaces
    while(j < n && s[j] == ' ') j++;
    
    while(j < n) {
        // Copy non-space characters
        if(s[j] != ' ') {
            s[i++] = s[j++];
        }
        else {
            // Copy only one space
            s[i++] = ' ';
            
            // Skip multiple spaces
            while(j < n && s[j] == ' ')
                j++;
        }
    }
    
    // Remove trailing space if exists
    if(i > 0 && s[i-1] == ' ')
        i--;
    
    s.resize(i);
    
    // -------- Step 2: Reverse Entire String --------
    reverse(s.begin(), s.end());
    
    // -------- Step 3: Reverse Each Word --------
    int start = 0;
    
    for(int k = 0; k <= s.length(); k++) {
        if(k == s.length() || s[k] == ' ') {
            reverse(s.begin() + start, s.begin() + k);
            start = k + 1;
        }
    }
    
    cout << s << endl;
    
    return 0;
}

// time complexity : O(n) because we are traversing the string multiple times (once for removing extra spaces, once for reversing the entire string, and once for reversing each word).
// space complexity : O(1) because we are using constant extra space.