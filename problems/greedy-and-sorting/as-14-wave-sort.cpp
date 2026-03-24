//Given an array of unsorted integers sort the array in a waveform

//for example, if the input array is [10, 5, 6, 3, 2, 20, 100, 80], the output should be [10, 5, 6, 3, 2, 20, 100, 80] or [10, 6, 5, 3, 20, 2, 100, 80] or any other arrangement where the elements are in a waveform pattern.

//large -> small -> large -> small -> large -> small and so on


#include <iostream>
#include<vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    vector<int> arr = {10,5,6,3,2,20,1};
    int n = arr.size();

    for(int i = 0; i < n; i += 2) {
        
        // Check left neighbor
        if(i > 0 && arr[i] < arr[i-1]) // we will check for the left neighbor and if we find any element which is less than the left neighbor then we will swap the current element with the left neighbor
            swap(arr[i], arr[i-1]);

        // Check right neighbor
        if(i < n-1 && arr[i] < arr[i+1]) // we will check for the right neighbor and if we find any element which is less than the right neighbor then we will swap the current element with the right neighbor
            swap(arr[i], arr[i+1]);
    }

    for(int x : arr)
        cout << x << " ";
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the result of the waveform array.