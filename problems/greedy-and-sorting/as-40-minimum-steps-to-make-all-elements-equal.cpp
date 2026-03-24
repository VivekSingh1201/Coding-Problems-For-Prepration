// Minimum Steps to Make All Elements Equal
// Given an array of integers, you can perform the following operation any number of times: choose an element and increment it by 1. Return the minimum number of operations required to make all elements in the array equal.


// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include<queue>
// using namespace std;

// int main() {
    
//     vector<int> arr={4,3,4};
//     int n=arr.size();
//     int steps=0;
    
//     sort(arr.begin(),arr.end());
    
//     while(arr[0]!=arr[n-1]){
//         steps++;
//         for(int i=0;i<n-1;i++){
//             arr[i]++;
//         }
//         sort(arr.begin(),arr.end());
//     }
    
//     for(int e : arr){
//         cout<<e<<' ';
//     }
//     cout<<endl<<steps<<endl;
    
//     return 0;
// }


// time complexity : O(n^2 log n) because we are sorting the array in each iteration.
// space complexity : O(1) because we are using only a constant amount of extra space


// Optimal approach : 
// By decrementing the largest element instead of incrementing the smaller elements, we can reduce the number of operations. We can use a max heap to keep track of the largest element and decrement it until all elements are equal.
// This is math based approach

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include <climits> // For using INT_MAX
using namespace std;

int main() {
    
    vector<int> arr={4,3,4};
    int n=arr.size();
    int min_e=INT_MAX;
    int steps=0;
    int sum=0;
    
    for(int e : arr){
        min_e=min(e,min_e);
        sum+=e;
    }
    
    // The total number of steps required to make all elements equal to the minimum element is the sum of the differences between each element and the minimum element.
    steps = sum - min_e * n;
    
    cout<<steps<<endl;
    
    return 0;
}


// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are using only a constant amount of extra space