// Given a sorted array of integers in decreasing order, find the index of the first occurrence of a given target integer. If the target is not found in the array, return -1.


#include <iostream>
#include<vector>
#include <algorithm>
#include <utility>
using namespace std;

int find_target(vector<int> arr,int target){
    int n=arr.size();
    int low = 0;
    int high=n-1;
    
    int idx=-1;
    
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(arr[mid]==target){
            idx=mid;
            high=mid-1; // we are updating high to mid-1 because we want to find the first occurrence of the target element in the array and if we find the target element then we will update the index variable with the mid value and then we will update high to mid-1 to continue searching for the target element in the left half of the array.
        }
        else if(arr[mid]<target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    return idx;
}

int main() {
    vector<int> arr = {7,6,6,5,5,5,4,3,2,1};
    int target = 1;
    
    int result = find_target(arr,target);
    cout<<result<<endl;
    return 0;
}

//time complexity of this approach is O(log n) because we are using binary search to find the target element in the array. Space complexity is O(1) because we are using only a constant amount of space to store the low, high and mid variables.