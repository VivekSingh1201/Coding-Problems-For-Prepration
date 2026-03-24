// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
// For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    vector<int> arr = {10,3,0,6,0};
    vector<int>res;
    int n = arr.size();
    
    int total=1;
    
    for(int ele : arr){
        if(ele==0){
            continue;
        }
        total *= ele;
    }
    
    for(int ele : arr){
        if(ele==0){
            ele=1;
        }
        res.push_back(total/ele);
    }
    
    for(int ele : res){
        cout<<ele<<" ";
    }
    
    return 0;
}

// time complexity : O(n) because we are traversing the array twice, once to calculate the total product of all the elements in the array and once to calculate the product of all the elements except the one at index i.
// space complexity : O(n) because we are using an extra array to store the result