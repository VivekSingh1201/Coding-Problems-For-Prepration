// find the peak element in a bitonic array
// Bitonic array is an array which is first increasing and then decreasing. We have to find the index of the peak element in the bitonic array. The peak element is the element which is greater than its neighbors. If there are multiple peak elements then we have to return the index of the first peak element. If there is no peak element then we have to return -1.


#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,4,6,8,9,10,37,5,3,};
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] > arr[mid + 1])
            high = mid;      // peak is left side (including mid)
        else
            low = mid + 1;   // peak is right side
    }

    cout << arr[low]<<endl;   // or arr[high]
    return 0;
}

// time complexity : O(log n) because we are using binary search to find the peak element in the bitonic array.
// space complexity : O(1) because we are not using any extra space to store the result of the peak element.