// given an array reverse it in place

#include <iostream>
#include<vector>
using namespace std;    

int main() {
    
    vector<int> arr = {12,13,14,15,18,19,1,2};
    int n = arr.size();
    
    int left=0,right=n-1;
    
    while(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
    
    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the result of the reversed array. We are using only two variables to store the left and right indices in the array.