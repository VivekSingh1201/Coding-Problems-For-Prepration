// Find the maximum subarray sum in an array

// Given an array of integers, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.


#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits> // Required header for INT_MIN
using namespace std;

int main() {
    
    vector<int> arr = {-2,-4};
    int n = arr.size();
    
    int sum=0, t_sum=INT_MIN;
    
    for(int i=0;i<n;i++){ //it is also called as Kadane's algorithm which is an efficient algorithm to find the maximum subarray sum in O(n) time complexity and O(1) space complexity. The idea is to keep track of the current sum and the maximum sum at each step and if the current sum becomes negative then we will reset it to 0 because a negative sum will not contribute to the maximum sum in the future. We will also update the maximum sum at each step by comparing it with the current sum.
        sum+=arr[i];
        t_sum=max(t_sum,sum);
        if(sum>0){
            continue;
        }
        sum=0;
    }
    
    cout<<t_sum<<endl;
    
    return 0;
}

//time complexity of this approach is O(n) because we are iterating through the array once to find the maximum subarray sum. Space complexity is O(1) because we are using only a constant amount of space to store the sum and t_sum variables.