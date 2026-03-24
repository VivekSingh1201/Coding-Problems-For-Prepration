// Given an array, rotate the array to the right by k steps, where k is non-negative.


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
    
//     vector<int> arr={1,2,3,4,5,6,7};
//     vector<int> res;
//     int n=arr.size();
//     int k=3;
//     int start=n-k;
//     int end=n;
    
//     for(int i=start;i<end;i++){
//         if(i==n-1){
//             i=0;
//             end=n-k;
//             res.push_back(arr[n-1]);
//         }
//         res.push_back(arr[i]);
//     }
    
//     for(int ele : res){
//         cout<<ele<<" ";
//     }

//     return 0;
// }


// time complexity : O(n) because we are iterating through the array once.
// space complexity : O(n) because we are using an additional array to store the rotated elements


// Using the modulo operator to find the new position of each element after rotation and placing it in a new array.

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
    
//     vector<int> arr = {1,2,3,4,5,6,7};
//     int n = arr.size();
//     int k = 3;
    
//     k = k % n;   // Handle k > n
    
//     vector<int> res(n);
    
//     for(int i = 0; i < n; i++){
//         res[(i + k) % n] = arr[i];
//     }
    
//     for(int ele : res){
//         cout << ele << " ";
//     }

//     return 0;
// }

// time complexity : O(n) because we are iterating through the array once.
// space complexity : O(n) because we are using an additional array to store the rotated elements



// Using the reverse method to rotate the array in place without using extra space.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    int k = 3;
    
    k = k % n;
    
    // Step 1: Reverse the entire array
    reverse(arr.begin(), arr.end());
    // eg: arr = {7,6,5,4,3,2,1}
    reverse(arr.begin(), arr.begin() + k);
    // eg: arr = {5,6,7,4,3,2,1}
    reverse(arr.begin() + k, arr.end());
    // eg: arr = {5,6,7,1,2,3,4}
    
    for(int ele : arr){
        cout << ele << " ";
    }

    return 0;
}

// time complexity : O(n) because we are iterating through the array a few times but it is still linear.
// space complexity : O(1) because we are rotating the array in place without using any