// Check if two strings are rotations of each other

// For example, "abcd" and "cdab" are rotations of each other, but "abcd" and "acbd" are not.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    
    string s1="abcd", s2="cdab";
    string ans="No";
    
    int n=s1.length();
    
    for(int i=0;i<n;i++){
        if(s1==s2){
            ans="Yes";
            break;
        }
        
        // Rotate the string by one position to the rightxs
        char last = s1.back();
        s1.pop_back();
        s1=last+s1;
    }
    
    cout<<ans<<endl;

    return 0;
}

// Time Complexity: O(n^2) in the worst case, where n is the length of the strings. This is because we are rotating the string n times and each rotation takes O(n) time.
// Space Complexity: O(1) as we are using only a constant amount of extra space.