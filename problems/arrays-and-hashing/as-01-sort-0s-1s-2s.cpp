//Given an array arr[] consisting of only 0s, 1s, and 2s. The objective is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last.

//This problem is the same as the famous "Dutch National Flag problem". The problem was proposed by Edsger Dijkstra. The problem is as follows:

//Given n balls of colour red, white or blue arranged in a line in random order. You have to arrange all the balls such that the balls with the same colours are adjacent with the order of the balls, with the order of the colours being red, white and blue (i.e., all red coloured balls come first then the white coloured balls and then the blue coloured balls). 

#include <iostream>
using namespace std;

int main(){
    int arr[5] = {1, 0, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, mid = 0, high = n - 1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are not using any extra space to store the result of the sorted array. We are using only three variables to store the low, mid and high indices in the array.