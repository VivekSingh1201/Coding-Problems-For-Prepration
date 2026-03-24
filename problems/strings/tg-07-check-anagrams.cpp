// Check if two strings are anagrams of each other
// Two strings are anagrams if they contain the same characters in the same frequency. We can use an unordered map to count the frequency of each character in the first string and then decrement the frequency for each character in the second string. If the frequency of any character becomes negative, then the strings are not anagrams; otherwise, they are anagrams.

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    
    string s1 = "listen";
    string s2 = "silent";
    
    if(s1.length() != s2.length()){
        cout << "Not anagrams" << endl;
        return 0;
    }
    
    unordered_map<char,int> freq;
    
    for(char c : s1){
        freq[c]++;
    }
    
    for(char c : s2){
        freq[c]--;
        if(freq[c] < 0){
            cout << "Not anagrams" << endl;
            return 0;
        }
    }
    
    cout << "Anagrams" << endl;
    return 0;
}

// Time complexity: O(n) where n is the length of the strings (assuming both strings have the same length).
// Space complexity: O(1) since the size of the character set is fixed (e.g., 26 lowercase letters), the unordered map will have a constant number of entries.