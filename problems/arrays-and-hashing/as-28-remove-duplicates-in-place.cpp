// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.


#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<int> arr = {1,1,2,2,2,3,3,3,4,4,4,4,5};
    int n = arr.size();
    
    if(n == 0) return 0;
    
    int idx = 1;   // Position to place next unique element
    
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[i - 1]) {
            arr[idx++] = arr[i];
        }
    }
    
    // Print unique elements
    for(int i = 0; i < idx; i++){
        cout << arr[i] << " ";
    }
    
    cout << "\nNew length: " << idx<<endl;
    
    return 0;
}

// Time complexity: O(n) where n is the size of the array
// Space complexity: O(1) since we are modifying the array in place and not using any extra space.