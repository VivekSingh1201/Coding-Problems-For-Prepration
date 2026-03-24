// Buy and Sell Stock with one transaction only

// Given an array of stock prices, find the maximum profit that can be made by buying and selling the stock only once.

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {7,5,3,1};
    int n = arr.size();
    
    int max_profit=0;
    int max_val=arr[n-1];
    // we will traverse the array from the right side and check for the maximum value and if we find any element which is greater than the maximum value then we will update the maximum value with that element and we will also check for the maximum profit by subtracting the current element from the maximum value and if we find any element which is greater than the maximum profit then we will update the maximum profit with that element
    for(int i=n-2;i>=0;i--){
        max_profit=max(max_profit, max_val - arr[i]); // we will check for the maximum profit by subtracting the current element from the maximum value and if we find any element which is greater than the maximum value then we will update the maximum value with that element
        if(arr[i]>max_val){
            max_val=arr[i];
        }
    }
    
    cout<<"Maximum profit: "<<max_profit<<endl;

    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the result of the maximum profit. We are using only two variables to store the maximum profit and the maximum value in the array.