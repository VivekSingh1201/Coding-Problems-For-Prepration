// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
    
//     vector<int> arr = {100,1,200,3,2,3};
//     int n = arr.size();
    
//     if(n == 0) {
//         cout << 0;
//         return 0;
//     }
    
//     sort(arr.begin(), arr.end());
    
//     int count = 1;
//     int max_count = 1;
    
//     for(int i = 1; i < n; i++){
        
//         if(arr[i] == arr[i-1]) {
//             continue;   // skip duplicates
//         }
//         else if(arr[i] == arr[i-1] + 1){
//             count++;
//         }
//         else{
//             count = 1;
//         }
        
//         max_count = max(max_count, count);
//     }
    
//     cout << max_count << endl;
    
//     return 0;
// }

// time complexity : O(n log n) because we are sorting the array.
// space complexity : O(1) because we are using constant extra space.


// Using an unordered set to achieve O(n) time complexity.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    
    vector<int> arr = {100,1,200,3,2,3};
    
    // Create an unordered set from the array for O(1) lookups31
    unordered_set<int> s(arr.begin(), arr.end());
    
    int longest = 0;
    
    for(int num : s){
        
        // Only start counting if it's a sequence start
        if(s.find(num - 1) == s.end()){
            
            int current = num;
            int count = 1;
            
            while(s.find(current + 1) != s.end()){
                current++;
                count++;
            }
            
            longest = max(longest, count);
        }
    }
    
    cout << longest << endl;
    
    return 0;
}

// time complexity : O(n) because we are iterating through the array and set once.
// space complexity : O(n) because we are using an unordered set to store the elements of the array.