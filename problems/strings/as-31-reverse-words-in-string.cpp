// C++ program to reverse words in a given string


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    string ch = "the sky is blue";
    int n=ch.length();
    
    int start=0;
    int i=0;
    
    reverse(ch.begin(),ch.end());
    
    while(ch[i]!='\0'){
        if(ch[i]!=' '){
            i++;
            continue;
        }
        else if(ch[i]==' '){
            reverse(ch.begin() + start, ch.begin() + i);
            start=++i;
        }
    }
    
    reverse(ch.begin() + start, ch.begin() + i);
    
    cout<<ch<<endl;

    return 0;
}

// time complexity : O(n) because we are traversing the string twice (once for reversing the entire string and once for reversing each word).
// space complexity : O(1) because we are using constant extra space.