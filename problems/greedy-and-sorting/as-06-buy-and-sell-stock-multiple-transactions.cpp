// Buy and Sell Stock with Multiple Transaction
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

#include <iostream>
#include<vector>
#include<string>
using namespace std;

// int main() {
//     vector<int> arr = {100,180,260,310,40,535,695};
//     int n = arr.size();
    
//     int max_profit=0, i=0;
//     int local_min,local_max;

//     // we are doing this in one pass, we are finding local minima and local maxima and adding the difference to max_profit
    
//     while(i<n-1){
//         //Local Minima
//         while(i<n-1 && arr[i]>=arr[i+1]){
//             i++;
//         }
//         local_min = arr[i];
        
//         //Local Maxima
//         while(i<n-1 && arr[i] <= arr[i+1]){
//             i++;
//         }
//         local_max = arr[i];
        
//         max_profit += local_max - local_min;
//     }
    
//     cout<<"Maximum Profit = "<<max_profit<<endl;

//     return 0;
// }



// But there is a another solution to this problem, we can simply add the difference of all the consecutive elements if the next element is greater than the current element, this will give us the maximum profit as well.

int main() {
    vector<int> arr = {100,180,260,310,40,535,695};
    int n = arr.size();
    int max_profit=0;
    for(int i=1; i<n; i++){
        if(arr[i]>arr[i-1]){
            max_profit += arr[i] - arr[i-1];
        }
    }
    cout<<"Maximum Profit = "<<max_profit<<endl;
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the result of the maximum profit.