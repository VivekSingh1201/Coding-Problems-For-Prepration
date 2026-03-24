// Given an array of integers, find the maximum product of any three numbers in the array.

// We can solve this problem by sorting the array and then finding the maximum product of any three numbers in the array. The maximum product can be obtained by either multiplying the three largest numbers in the array or by multiplying the two smallest numbers in the array with the largest number in the array.


#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr={-10,-3,-5,-6,20};
    int n = arr.size();
    
    sort(arr.begin(),arr.end());
    
    int max1 = arr[n-1],max2=arr[n-2],max3=arr[n-3];
    int min1=arr[0], min2=arr[1];
    
    int prod = max((min1*min2*max1),(max1*max2*max3));
    
    cout << prod;
    
    return 0;
}

// time complexity : O(n log n) because we are sorting the array.
// space complexity : O(1) because we are not using any extra space to store the result of the maximum product of any three numbers in the array.