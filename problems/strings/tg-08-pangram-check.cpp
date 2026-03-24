// Check if strings are Panagram or not


// A pangram is a sentence that contains every letter of the alphabet at least once. We can use an unordered set to store the unique characters in the string and then check if the size of the set is equal to 26 (the number of letters in the English alphabet). If it is, then the string is a pangram; otherwise, it is not.

#include <iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int main() {
    
    string s1="The quick brown fox jumps over the lazy dog";
    
    unordered_set<char> st;
    
    for(char ele:s1){
        if(isalpha(ele)){
            st.insert(tolower(ele));
        }
    }
    
    if(st.size()==26){
        cout<<"String is Panagram"<<endl;
    }
    else{
        cout<<"String is not Panagram"<<endl;
    }
    
    
    
    return 0;
}

// Time complexity: O(n) where n is the length of the input string.
// Space complexity: O(1) since the size of the character set is fixed (e.g., 26 lowercase letters), the unordered set will have a constant number of entries.