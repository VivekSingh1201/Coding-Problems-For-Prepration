//
//  as-01-find-frequency-of-number.cpp
//  Coding-Problems
//
//  Created by Vivek Singh on 30/03/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> arr = {1,2,3,1,4};
    int xorr = 0;
    
    for(int i=0;i<arr.size();i++){
        xorr ^= arr[i];
    }
    
    for(int i=0;i<arr.size();i++){
        xorr ^= i;
    }
    
    cout<<"Repeating Number is:- " << xorr;
    
    return 0;
    
}


// time complexity: O(n)
// space complexity: O(1)