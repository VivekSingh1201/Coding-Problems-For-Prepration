// Given an array of positive integers nums and a positive integer target, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than target.

// approach : sliding window

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    vector<int> nums={1,2,3,4};
    int target = 2;
    
    int n=nums.size();
    int max_sub=0;
    int left=0;
    int prod=1;
    int count=0;
    
    for(int right=0;right<n;right++){
        prod *= nums[right];
        
        // shrink the window until the product is less than the target
        while(prod >= target){
            prod /= nums[left++];
        }
        
        count += right - left + 1;
    }
    
    
    cout << count<<endl;
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are using only a constant amount of extra space



//  Dry Run


//   nums = [10, 5, 2, 6], k = 100

//   right=0: product=10  → window [10]          → count += 1  (total=1)
//   right=1: product=50  → window [10,5]        → count += 2  (total=3)
//   right=2: product=100 ≥ 100 → shrink
//          product=10  → window [2]           → count += 1  (total=4) ❌ wait
//          product=100/10=10 → left=1
//          window [5,2] → count += 2          (total=5) ✔
//   right=3: product=60  → window [5,2,6]       → count += 3  (total=8)

//   Answer: 8
//   Valid subarrays: [10],[5],[2],[6],[10,5],[5,2],[2,6],[5,2,6]
// 

// 

// ## Why `right - left + 1`?

// When window is `[left .. right]`, the new subarrays introduced by including `right` are exactly:
// ```
// [right]
// [left+1 .. right]
// [left+2 .. right]
// ...
// [left   .. right]