// Find the missing ranges in a given range of numbers
// Given a sorted array of integers and a range [lower, upper], find the missing ranges in the array that fall within the given range. The missing ranges should be represented as a list of strings, where each string represents a range in the format "start->end" or "start" if the start and end are the same.


#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    
    vector<int> arr = {-48,-10,-6,-4,0,4,17};
    int n = arr.size();
    
    vector<int>range = {-54,17};
    vector<vector<int>> res;
    
    // we will check for the missing ranges by comparing the elements of the array with the given range and if we find any element which is less than the lower bound of the range then we will add that element to the result vector and if we find any element which is greater than the upper bound of the range then we will add that element to the result vector and if we find any element which is between the lower bound and upper bound of the range then we will check for the consecutive elements in the array and if we find any consecutive elements then we will add that range to the result vector.
    if(range[0]<arr[0]){
        res.push_back({range[0],arr[0]-1});
    }
    
    // we will check for the missing ranges by comparing the elements of the array with the given range and if we find any element which is less than the lower bound of the range then we will add that element to the result vector and if we find any element which is greater than the upper bound of the range then we will add that element to the result vector and if we find any element which is between the lower bound and upper bound of the range then we will check for the consecutive elements in the array and if we find any consecutive elements then we will add that range to the result vector.
    for(int i=0;i<n;i++){
        if(arr[i+1] - arr[i] > 1){
            res.push_back({(arr[i]+1),(arr[i+1]-1)});
        }
    }
    
    // we will check for the missing ranges by comparing the elements of the array with the given range and if we find any element which is less than the lower bound of the range then we will add that element to the result vector and if we find any element which is greater than the upper bound of the range then we will add that element to the result vector and if we find any element which is between the lower bound and upper bound of the range then we will check for the consecutive elements in the array and if we find any consecutive elements then we will add that range to the result vector.
    if(range[1]>arr[n-1]){
        res.push_back({arr[n-1]+1,range[1]});
    }
    
    // we will print the missing ranges by iterating through the result vector and if the start and end of the range are the same then we will print that element otherwise we will print the range in the format "start->end".
    for(auto ele : res){
        cout<<ele[0]<<" "<<ele[1]<<"\n";
    }
    
    return 0;
}

// time complexity : O(n) because we are traversing the array once to find the missing ranges.
// space complexity : O(n) because in the worst case, we can have all the elements in the array missing and we will be storing all the missing ranges in the result vector.