// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

//Example 1:

//Input: s = "anagram", t = "nagaram"

//Output: true


#include <iostream>
#include <string>
using namespace std;

int main() {
    
    string s="ADOBECODEBANC", t="ABC";
    int status[26]={0};
    
    for(char c : t){
        status[c-'A']++;
    }
    
    for(char c : s){
        status[c-'A']--;
    }
    
    for(int e : status){
        if(e>0){
            cout<<"String t not present in s"<<endl;
            return 0;
        }
    }
    
    cout<<"String t present in s"<<endl;
    return 1;
}