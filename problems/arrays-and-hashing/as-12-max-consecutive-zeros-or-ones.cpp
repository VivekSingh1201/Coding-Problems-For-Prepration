// Given an array of 0's and 1's, find the maximum number of consecutive 1's or 0's in the array.


// #include <iostream>
// #include<vector>
// using namespace std;

// int main() {
//     vector<int> arr={1,0,1,0,1,0};
//     int n = arr.size();
    
//     int count=1;
//     int max_count=0;
    
    
//     for(int i=0;i<n;i++){
//         if(arr[i-1]==arr[i]){
//             count++;
//         }
//         else{
//             // cout<<"Count = "<<count<<endl;
//             max_count=max(max_count,count);
//             count=1;
//         }
//     }
    
//     cout<<"Max Count = "<<max(max_count,count)<<"\n"; // we will check for the maximum count by comparing the current count with the maximum count and if we find any element which is greater than the maximum count then we will update the maximum count with that element

//     return 0;
// }



// we can use XOR operator to find the maximum number of consecutive 1's or 0's in the array in O(n) time complexity and O(1) space complexity.

#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr={1,0,1,0,1,0,0,0,0,1,1,1,1};
    int n = arr.size();
    
    int count=1;
    int max_count=0;
    
    
    for(int i=0;i<n-1;i++){
        if((arr[i]^arr[i+1]) == 0){ // we will check for the consecutive 1's or 0's by using XOR operator and if we find any element which is equal to the next element then we will increment the count by 1
            count++;
        }
        else{
            // cout<<"Count = "<<count<<endl;
            max_count=max(max_count,count);
            count=1;
        }
    }
    
    cout<<"Max Count = "<<max(max_count,count)<<"\n"; // we will check for the maximum count by comparing the current count with the maximum count and if we find any element which is greater than the maximum count then we will update the maximum count with that element

    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the result of the maximum count of consecutive 1's or 0's in the array.