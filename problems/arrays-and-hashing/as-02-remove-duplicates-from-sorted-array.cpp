// Revmove the duplicates from sorted array and print the unique elements

#include<iostream>
using namespace std;

int main(){
    int arr[13] = {1,1,3,3,4,5,5,5,6,7,7,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 1;

    for(int i = 1; i < n; i++){
        if(arr[i]!=arr[i-1]){      // check for the last element and if it is not equal to the current element then we will add it to the unique array
            arr[k]=arr[i];
            k++;
        }
    }

    for(int i = 0; i < k; i++){
        cout << arr[i] << " ";
    }
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the unique elements