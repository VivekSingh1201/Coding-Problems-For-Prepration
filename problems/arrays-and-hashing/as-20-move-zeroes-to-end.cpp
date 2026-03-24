// Move all the 0's to the end of the array while maintaining the relative order of the non-zero elements

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    
    vector<int> arr = {0,0,0,0,0,1};
    int n = arr.size();
    int ele = 0; 
    
    int new_idx=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]!=ele){   // we are checking for the non-zero element in the array and if we find any non-zero element then we will move that element to the left side of the array and we are also updating the new_idx variable to point to the next index where we want to move the next non-zero element.
            if(new_idx!=i){
                swap(arr[new_idx],arr[i]);
            }
            new_idx++;
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the