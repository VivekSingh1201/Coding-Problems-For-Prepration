// Leaders in an array are those elements which are greater than all the elements to their right side. The rightmost element is always a leader. For example, in the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.


#include<iostream>
using namespace std;

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders;
    int n = arr.size();
    int max = arr[n-1];
    // we will traverse the array from the right side and check for the maximum element and if we find any element which is greater than the maximum element then we will add it to the leaders vector and update the maximum element
    //we can do it in-place by upating the leaders at last of the original array and then we can print the leaders from the end of the array
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=max){
            leaders.push_back(arr[i]);
            max = arr[i];
        }
    }
    for(int i=leaders.size()-1;i>=0;i--){
        cout << leaders[i] << " ";
    }
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(n) because we are using an extra vector to store the leaders