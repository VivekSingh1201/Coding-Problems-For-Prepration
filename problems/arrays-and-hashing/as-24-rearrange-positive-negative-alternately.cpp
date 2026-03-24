// Given an array of integers, rearrange the array such that positive and negative numbers are placed alternatively. The order of appearance should be maintained. 
//If there are more positive numbers than negative numbers, then the extra positive numbers should be placed at the end of the array. If there are more negative numbers than positive numbers, then the extra negative numbers should be placed at the end of the array.


#include <iostream>
#include<vector>
using namespace std;

int main() {
    
    vector<int> arr = {12,13,-14,-15,18,19,1,-2};
    int n = arr.size();
    vector<int> pos,neg;
    
    
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    
    int pos_idx=0,neg_idx=0;
    int n_pos=pos.size();
    int n_neg=neg.size();
    
    arr.erase(arr.begin(),arr.end());
    
    while(pos_idx<n_pos && neg_idx<n_neg){
        arr.push_back(pos[pos_idx++]);
        arr.push_back(neg[neg_idx++]);
    }
    
    while(pos_idx<n_pos){
        arr.push_back(pos[pos_idx++]);
    }
    
    while(neg_idx<n_neg){
        arr.push_back(neg[neg_idx++]);
    }

    for(int ele : arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    
    return 0;
}

// time complexity : O(n) because we are traversing the array twice, once to separate the positive and negative numbers and once to rearrange the array.
// space complexity : O(n) because we are using two extra vectors to store the positive and