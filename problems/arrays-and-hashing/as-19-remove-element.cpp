// Remove all occurrences of an element from an array and return the new length of the array after removal

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    
    vector<int> arr = {0,1,3,0,2,2,4,2};
    int n = arr.size();
    int ele = 2;
    
    int new_idx=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]!=ele){
            if(new_idx!=i){
                swap(arr[new_idx],arr[i]); // we are swapping the elements at new_idx and i because we want to move the non-ele element to the left side of the array and we are also updating the new_idx variable to point to the next index where we want to move the next non-ele element.
            }
            new_idx++;  // we are updating the new_idx variable to point to the next index where we want to move the next non-ele element.
        }
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<"\n"<<"Remaining Element = "<<new_idx<<endl;
    
    

    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the non-ele elements.