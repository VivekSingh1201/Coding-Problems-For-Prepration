// C++ program to find two numbers in an array that add up to a target sum

// For sorted array, we can use two pointers approach to achieve O(n) time complexity.
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main() {
    
//     vector<int> arr={2,3,4,5,6};
//     int n=arr.size();
//     int target=6;
    
//     int i=0, j=n-1;
    
//     while(i<j){
//         if(arr[i]+arr[j]==target){
//             cout<<i<<" "<<j<<endl;
//             return 0;
//         }
//         if(arr[i]+arr[j]<target){
//             i++;
//         }
//         else{
//             j--;
//         }
//     }
    

//     return 0;
// }

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are using constant extra space.




 

// For unsorted array, we can use an unordered map to achieve O(n) time complexity.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    
    vector<int> arr = {2,3,4,5,6};
    int target = 6;
    
    unordered_map<int,int> mp;
    
    for(int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        
        if(mp.find(complement) != mp.end()){
            cout << mp[complement] << " " << i << endl;
            return 0;
        }
        
        mp[arr[i]] = i;
    }
    
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(n) because we are using an unordered map to store the elements of the array.