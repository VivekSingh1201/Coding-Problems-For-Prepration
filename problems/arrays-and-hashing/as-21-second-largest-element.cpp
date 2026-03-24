// Find the second largest element in an array there can be duplicate elements also

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    
    vector<int> arr = {1,2,3,4,5,1,5,2,3,4};
    int n = arr.size();
    
    int first=arr[0],second=-1;
    
    for(int i=1;i<n;i++){
        if(arr[i]>first){
            second=first;
            first=arr[i];
        }
    }
    
    cout<<second<<endl;
    
    return 0;
}

// time complexity : O(n) because we are traversing the array once.
// space complexity : O(1) because we are using only two variables to store the first and second largest elements.