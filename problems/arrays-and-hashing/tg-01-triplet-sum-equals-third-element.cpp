// find a triplet such that sum of two elemrnts is equal to the third element in the array


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    
    // sort the array

    sort(arr.begin(),arr.end());

    
    
    for(int i=2;i<n;i++){
        int left = 0, right = i-1;
        
        // two pointer approach to find the sum of two elements equal to the third element
        while(left<right){
            int sum = arr[left] + arr[right];
            
            if(sum == arr[i]){
                cout<<"True"<<endl;
                return 0;
            }
            else if(sum < arr[i]){
                left++;
            }
            else{
                right--;
            }
        }
    }
    

    return 0;
}

// Time complexity: O(n^2)
// Space complexity: O(1)