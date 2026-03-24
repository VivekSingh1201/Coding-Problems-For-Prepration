// Missing and Repeating Number
// Given an unsorted array of n numbers between 1 and n, find the one that is missing and the one that is repeated.


#include<iostream>
using namespace std;    

int main(){
    vector<int> arr = {1,2,3,4,2};
    int n = arr.size();
    int missing, repeating;
    
    // whenever we have an array of n numbers between 1 and n then we can use the index of the array to mark the presence of the element in the array and we can also use the index to find the missing number by checking for the positive element in the array and the index of that element will be the missing number and if we find any element which is already negative then we will update the repeating variable with that element.
    
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1] > 0){
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; // mark the presence of the element in the array by making it negative
        }
        else{
            repeating = abs(arr[i]);
        }
    }

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            missing = i+1; // if the element is positive then it means that the element is missing and the index of that element will be the missing number
        }
    }
    cout << "Missing number: " << missing << endl;
    cout << "Repeating number: " << repeating << endl;
}

// time complexity : O(n) because we are traversing the array twice, once to mark the presence of the elements in the array and once to find the missing number.
// space complexity : O(1) because we are not using any extra space to store the result